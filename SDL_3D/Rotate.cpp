#include "Rotate.h"

#include "Model.h"
#include <gtc/matrix_transform.hpp>

Rotate::Rotate(glm::vec3 axis, float speed) :
	mAxis{ axis },
	mSpeed{ speed }
{
}

void Rotate::Init()
{
	mTarget = GetSiblingComponent<Model>();
	SDL_assert(mTarget);
}

void Rotate::Update(float dt)
{
	mTarget->SetRotation(glm::rotate(mTarget->Rotation(), dt * mSpeed, mAxis));
}
