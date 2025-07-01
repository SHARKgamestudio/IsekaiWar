#include "Animator.h"

#pragma region Local Dependencies

#include "Spritesheet.h"
#include "Animation.h"

#pragma endregion

Animator::Animator(Spritesheet* spritesheet, std::vector<Animation*> animations) {
	this->current = nullptr; this->last = nullptr;

	this->blendtree = false;
	this->frameAsTime = 0;

	this->currentAnimation = 0; this->currentBlendTree = 0;

	this->animations = animations;
	this->spritesheet = spritesheet;
}

Animator::~Animator() {
	for (int i = 0; i < animations.size(); i++) {
		free(animations[i]);
	}
}

void Animator::UpdateLogic(float deltaTime) {

	Animation* animatedValue = animations[currentAnimation];

	if (animatedValue != nullptr) {
		if (last != animatedValue) {
			frameAsTime = float(animatedValue->start);
			last = animatedValue;
		}

		if (spritesheet->current <= animatedValue->end) {
			frameAsTime += (deltaTime * 8) * animatedValue->speed;
		}
		else {
			if (!blendtree) { blendtree = true; }
			spritesheet->current = animatedValue->start;
			frameAsTime = float(animatedValue->start);
		}
	}

	spritesheet->current = int(frameAsTime);

	spritesheet->UpdateViewport();
}

void Animator::AddAnimation(Animation* animatedValue) {
	animations.push_back(animatedValue);
}

void Animator::AddBlendTree(BlendTree* blendtree) {
	blendtrees.push_back(blendtree);
}

Animation* Animator::Find(std::string name) {
	Animation* result = nullptr;
	for (int i = 0; i < animations.size(); i++) {
		if (animations[i]->name == name) {
			return animations[i];
			break;
		}
	}

	return result;
}

void Animator::Play(std::string name)
{
	for (int i = 0; i < animations.size(); i++) {
		if (animations[i]->name == name) {
			currentAnimation = i;
			blendtree = false;
			if (frameAsTime < animations[i]->start || frameAsTime > animations[i]->end) {
				frameAsTime = float(animations[i]->start);
			}
			return;
		}
	}
}

void Animator::PlayBlendTree(std::string name) {
	for (int i = 0; i < blendtrees.size(); i++) {
		if (blendtrees[i]->name == name) {
			currentBlendTree = i;
			blendtree = true;
			return;
		}
	}
}