#include "ShaderSys.h"
#include "Assert.h"
#include "FileUtils.h"
#include <iostream>

ShaderSys::ShaderSys()
{
}

ShaderSys::~ShaderSys()
{
}

bool ShaderSys::Init()
{
	if (!mProgramCreated) {
		mProgramID = glCreateProgram();
		printf("Shader Program Initialized\n");
	}
	return false;
}

bool ShaderSys::Shutdown()
{
	DeleteShaders();
	DeleteProgram();
	printf("Successful Shutdown\n");
	return false;
}

bool ShaderSys::AddVertexShader(const char * const filename)
{
	AddShader(filename, GL_VERTEX_SHADER);
	return false;
}

bool ShaderSys::AddFragmentShader(const char * const filename)
{
	AddShader(filename, GL_FRAGMENT_SHADER);
	return false;
}

bool ShaderSys::AddShader(const char* const filename, GLenum shaderType)
{
	GLuint shaderID = glCreateShader(shaderType);
	GLchar* shaderSource = FileUtils::ReadFileIntoString(filename);
	glShaderSource(shaderID, 1, &shaderSource, NULL);
	glCompileShader(shaderID);
	SaveShaderInfo(filename, shaderType, shaderID);
	mNumShaders++;
	glAttachShader(mProgramID, shaderID);
	return true;
}

bool ShaderSys::CheckShaderCompileStatus(GLuint shaderID)
{
	GLint status;
	glGetShaderiv(shaderID, GL_COMPILE_STATUS, &status);
	GLint len;
	glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &len);
	GLchar* buffer = new GLchar[len];
	ShowShaderLogInfo(shaderID, buffer, len);
	delete buffer;
	return false;
}

bool ShaderSys::CheckProgramStatus(GLenum pname)
{
	GLint programiv;
	glGetProgramiv(mProgramID, pname, &programiv);
	return true;
}

bool ShaderSys::CheckProgramStatus()
{
	if (CheckProgramStatus(GL_LINK_STATUS)) {
		printf("Successful GL_LINK_STATUS\n");
	}
	glValidateProgram(mProgramID);
	if (CheckProgramStatus(GL_VALIDATE_STATUS)) {
		printf("Successful GL_VALIDATE_STATUS\n");
	}
	return false;
}

bool ShaderSys::LinkAndUseProgram()
{
	glLinkProgram(mProgramID);
	glUseProgram(mProgramID);
	return false;
}

GLint ShaderSys::GetUniformLocation(const GLchar* name)
{
	GLint result;
	result = glGetUniformLocation(mProgramID, name);
	return result;
}

GLint ShaderSys::GetAttribLocation(const GLchar* name)
{
	GLint result;
	result = glGetAttribLocation(mProgramID, name);
	return result;
}

void ShaderSys::ShowShaderLogInfo(GLuint shaderID, char* infoBuffer, GLint bufferLen)
{
	GLsizei len;
	glGetShaderInfoLog(shaderID, bufferLen, &len, infoBuffer);
	// TODO: Test and format output
	for (int i = 0; i < bufferLen; i++) {
		std::cout << infoBuffer[i];
	}
	std::cout << "\n";
}

void ShaderSys::ShowProgramLogInfo(char* infoBuffer, GLint bufferLen, GLenum pname)
{
	for (int i = 0; i < bufferLen; i++) {
		std::cout << infoBuffer[i];
	}
	std::cout << "\n";
}

bool ShaderSys::SaveShaderInfo(const char* const filename, GLenum shaderType, GLuint shaderId)
{
	printf("Saving shader with ID %d\n", shaderId);
	char name[maxShaderNameLen];
	for (int i = 0; i < maxShaderNameLen; i++) {
		name[i] = filename[i];
	}
	mShaders[mNumShaders].id = shaderId;
	mShaders[mNumShaders].type = shaderType;
	return false;
}

void ShaderSys::DeleteShaders()
{
	for (GLuint iShader = 0; iShader < mNumShaders; iShader++) {
		glDeleteShader(mShaders[iShader].id);
	}
	mNumShaders = 0;
}

void ShaderSys::DeleteProgram()
{
	if (mProgramCreated) {
		glDeleteProgram(mProgramID);
	}
}