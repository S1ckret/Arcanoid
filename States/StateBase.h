#pragma once

#include "SFML/Graphics.hpp"

class Game;

class StateBase {
public:
	StateBase(Game &game) : m_game(&game)
	{	}
	virtual ~StateBase() = default;

	virtual void handleInput() = 0;
	virtual void update		(float d_time) = 0;
	virtual void render		() = 0;
	virtual void debugRender() = 0;
	virtual void handleEvent(sf::Event& event) = 0;

protected:
	Game* m_game;

};
