#pragma once

#include "SFML/Graphics.hpp"

#include "Body.h"
#include <string>

class Player : public sf::Drawable {
public:
	Player();
	~Player();

	void setView(sf::View* view);
	
	void handleInput();
	void update(float d_time);
	void handleEvent(sf::Event& event);
	
	const Shape& getShape() const;
	sf::Vector2f getHalfSize();
	sf::Vector2f getVelocity();
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void m_screenTestCollision();
private:
	Body m_body;
	bool m_moving_left, m_moving_right;
	const float m_max_vel = 600.f;
	const float m_half_w = 100.f;
	const float m_half_h = 10.f;
	sf::View* m_view;
	
	

};