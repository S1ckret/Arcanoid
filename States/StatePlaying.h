#pragma once

#include "StateBase.h"

#include "../Objects/Body.h"
#include "../Objects/Rectangle.h"
#include "../Objects/Level.h"

class StatePlaying 
	: public StateBase {
public:
	StatePlaying(Game& game);
	~StatePlaying();

	void handleInput();
	void update(float d_time);
	void render();
	void debugRender();
	void handleEvent(sf::Event& event);

private:
	sf::RenderWindow* m_window;
	sf::View m_view;
	
	Level lvl;
};
