#pragma once

#include <GL\glew.h>

const int maxShaderNameLen = 256;  // relative path to shader
const int maxShaders       = 2;    // only need vertex and frag shaders for now

struct ShaderInfo
    {
    char name[maxShaderNameLen] { 0 }; // name[0] == '\0' if this shader info is empty
    GLuint id   { 0 };
    GLenum type { 0 };      // shader type, eg, GL_VERTEX_SHADER
    };

class ShaderProgram
    {
    public:
        ShaderProgram( );
        ~ShaderProgram( );

    public:
		bool Init();
        bool Shutdown( );

        // Shader methods
        bool AddVertexShader  (const char* const filename);
        bool AddFragmentShader(const char* const filename);
        bool AddShader(const char* const filename, GLenum shaderType); // prefer adding specific shaders
        bool CheckShaderCompileStatus (GLuint shaderID);

        // Program methods
        bool CheckProgramStatus (GLenum pname);
        bool CheckProgramStatus ();
        bool LinkAndUseProgram  ();

        GLint GetUniformLocation (const GLchar* name);
        GLint GetAttribLocation  (const GLchar* name);

        GLint GetProgramId( ) const { return mProgramID; }

    private:
        void ShowShaderLogInfo (GLuint shaderID, char* infoBuffer, GLint bufferLen);
        void ShowProgramLogInfo(char* infoBuffer, GLint bufferLen, GLenum pname);
        bool SaveShaderInfo(const char* const filename, GLenum shaderType, GLuint shaderId);

		void DeleteShaders();
		void DeleteProgram();

    public:
        GLuint mProgramID;
        ShaderInfo mShaders[maxShaders];
		GLuint mNumShaders{ 0 };
		bool mProgramCreated{ false };
    };
