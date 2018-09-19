#pragma once

#include "Shape.h"
#include "SFML/Graphics.hpp"

class Rectangle : public sf::Drawable {
public:
	Rectangle();
	Rectangle(float h_w, float h_h, sf::Vector2f pos);
	
	void setPosition(float x, float y);
	void setRect(float h_w, float h_h);
	void setColor(sf::Color cl);
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	
private:
	Shape m_shape;
	
};