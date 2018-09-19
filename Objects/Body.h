#pragma once

#include <string>

#include "Shape.h"

#include "SFML/Graphics.hpp"

class Body : public sf::Drawable {
public:
	Body();
	Body(Shape& sh);
	~Body();
	
	void setBorderBox(sf::VertexArray& va);
	
	void setTexture(sf::Texture& tx);
	void setTextureBox(sf::VertexArray& va);
	
	void update(float d_time);
	
	//const sf::Vector2f& getPosition() const;
	//const sf::VertexArray& getVertexPosition() const;
	
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	
private:
	sf::Vector2f m_vel, m_acc;
	Shape m_shape;
	
	sf::Font font;
	sf::Text text;
};