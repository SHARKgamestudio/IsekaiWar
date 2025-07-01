#include "MenuScene.h"

#include "../UI/UIComponent.h"

MenuScene::~MenuScene() {
	for (auto element : elements) {
		delete element;
	}
	elements.clear();

	delete cursor;
}

void MenuScene::Load(){
	cursor = nullptr;
}

void MenuScene::UpdateLogic(float dt) { 
	for (UIComponent* element : elements) {
		element->UpdateLogic(dt);
	}
}

void MenuScene::Draw(sf::RenderWindow& window) {
	for (UIComponent* element : elements) {
		element->UpdateCursor(window, cursor->getGlobalBounds());
		window.draw(*element);
	}
	
	window.draw(*cursor);
}