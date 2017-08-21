#include "Model.h"

#include <gtx/transform.hpp>

Model::Model(Mesh* shape, glm::vec3 translation, glm::vec3 scale, glm::mat4 rotation) :
	mShape{ shape },
	mTranslation{ glm::translate(translation) },
	mScale{ glm::scale(scale) },
	mRotation{ rotation }
{
	calcModel();
}

void Model::SetScale(glm::vec3 scale)
{
	mScale = glm::scale(scale);
	calcModel();
}

void Model::SetRotation(glm::mat4 rotation)
{
	mRotation = rotation;
	calcModel();
}

void Model::SetTranslation(glm::vec3 translation)
{
	mTranslation = glm::translate(translation);
	calcModel();
}

void Model::calcModel()
{
	mTransform = mTranslation * (mRotation * mScale);
}
