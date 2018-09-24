#pragma once

#include "SFML/Graphics.hpp"

#include "Body.h"


class Player : public sf::Drawable {
public:
	Player();
	~Player();

	void handleInput();
	void update(float d_time);
	void handleEvent(sf::Event& event);
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	Rectangle m_body;
};