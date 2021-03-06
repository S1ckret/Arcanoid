#pragma once 

#include "Rectangle.h"

#include "SFML/Graphics.hpp"

class Brick : public sf::Drawable {
public:
	Brick();
	Brick(float h_w, float h_h, sf::Vector2f pos, int lifes);
	~Brick();
	
	void setSize(float h_w, float h_h);
	void setPosition(float x, float y);
	
	void minusLife();
	
	const Rectangle& getRectangle() const;
	bool isAlive();
	
private:
	void updateColor();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	
private:
	Rectangle m_rect;
	int m_life;
	bool m_alive;
	
};