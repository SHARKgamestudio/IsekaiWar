#pragma once

#pragma region Local Dependencies

#include "Animation.h"
#include "BlendTree.h"

#include <vector>
#include <string>

#pragma endregion

class Spritesheet;

class Animator {
private:
	Spritesheet* spritesheet;

	std::vector<Animation*> animations;
	int currentAnimation = 0;

	std::vector<BlendTree*> blendtrees;
	int currentBlendTree = 0;

	Animation* current, * last;

	bool blendtree; float frameAsTime;
public:
	Animator(Spritesheet* spritesheet, std::vector<Animation*> animations = {});
	~Animator();

	void UpdateLogic(float deltaTime);

	Animation* Find(std::string name);

	void AddAnimation(Animation* animatedValue);
	void AddBlendTree(BlendTree* blendtree);

	void Play(std::string name);
	void PlayBlendTree(std::string name);
};