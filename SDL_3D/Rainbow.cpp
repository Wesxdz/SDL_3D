#include "Rainbow.h"

Rainbow::Rainbow(float speed) :
	mPhase{ speed }
{
}

void Rainbow::Update(float dt)
{
	mStage += dt;
	while (mStage >= mPhase) {
		mStage -= mPhase;
	}
	float percent = mStage / mPhase;
	mColor->r = percent; // Peak at 0
	mColor->g = percent + percent / 3.0f;
	if (mColor->g > 1.0f) mColor->g = 1.0f - mColor->g; // Peak at 1/3
	mColor->b = percent + percent / 1.5f;
	if (mColor->b > 1.0f) mColor->b = 1.0f - mColor->b; // Peak at 2/3
}

void Rainbow::Init()
{
	mColor = GetSiblingComponent<Color>();
	SDL_assert(mColor);
}
