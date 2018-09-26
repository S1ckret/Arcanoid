#pragma once 

#include "Body.h"
#include "Shape.h"
#include "Player.h"

#include "SFML/Graphics.hpp"

#include <string>

class Ball : public sf::Drawable {
public:
	Ball();
	~Ball();
	
	void setView(sf::View* view);
	void setPlayer(Player* pl);
	
	void handleInput();
	void update(float d_time);
	bool testCollision(const Shape& sh);
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	
	void m_screenCollision();
private:
	sf::View* m_view;
	Body m_body;
	const sf::Vector2f half_ball = sf::Vector2f(7.5f, 7.5f);
	bool m_tied;
	Player* m_player;
};