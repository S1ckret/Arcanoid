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
	void setPosition(sf::Vector2f pos);
	void setColor(sf::Color cl);
	void setAcceleration(sf::Vector2f acc);
	
	void setTexture(sf::Texture& tx);
	void setTextureBox(sf::VertexArray& va);
	void applyForce(sf::Vector2f force);
	
	void update(float d_time);
	
	sf::Vector2f getVelocity();
	
	const Shape& getShape() const;
	//const sf::Vector2f& getPosition() const;
	//const sf::VertexArray& getVertexPosition() const;
	
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	
private:
	friend class Ball;
	friend class Player;
	sf::Vector2f m_vel, m_acc;
	sf::Vector2f m_force;
	float m_d_time;
	Shape m_shape;
};