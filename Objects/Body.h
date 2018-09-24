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
	void setPosition(float x, float y);
	
	
	void setColor(sf::Color cl);
	
	void setTexture(sf::Texture& tx);
	void setTextureBox(sf::VertexArray& va);
	
	void update(float d_time);
	
	sf::Vector2f getVelocity();
	
	const Shape& getShape() const;
	//const sf::Vector2f& getPosition() const;
	//const sf::VertexArray& getVertexPosition() const;
	
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	
private:
	friend class Ball;
	sf::Vector2f m_vel, m_acc;
	float m_d_time;
	Shape m_shape;
};