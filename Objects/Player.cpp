#include "Player.h"

Player::Player() {
	m_moving_left = 0;
	m_moving_right = 0;
	
	sf::VertexArray rect(sf::Quads, 4);
	rect[0].position = sf::Vector2f(-m_half_w, -m_half_h);
	rect[1].position = sf::Vector2f(m_half_w, -m_half_h);
	rect[2].position = sf::Vector2f(m_half_w, m_half_h);
	rect[3].position = sf::Vector2f(-m_half_w, m_half_h);
	
	m_body.setBorderBox(rect);
	m_body.setColor(sf::Color::Magenta);
	m_body.setPosition(500.f, 950.f);
	
	font.loadFromFile("res/BKANT.TTF");
	text.setFont(font);
	text.setPosition(100.f, 500.f);

}

Player::~Player() {
	
}

void Player::setView(sf::View* view) {
	m_view = view;
}

void Player::handleInput() {
	m_moving_left = 0;
	m_moving_right = 0;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		m_moving_left = 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		m_moving_right = 1;
	}
}

void Player::update(float d_time) {
	m_screenTestCollision();
	
	m_body.m_acc *= 0.09998f;
	m_body.m_vel *= 0.9888f;
	if (abs(m_body.m_vel.x) < 0.001f) {
		m_body.m_vel.x = 0.f;
	}
	
	if (m_moving_left) {
		m_body.applyForce(sf::Vector2f(-700.f, 0.f));
	}
	if (m_moving_right) {
		m_body.applyForce(sf::Vector2f(700.f, 0.f));
	}
	
	m_body.update(d_time);
	
	if (m_body.m_vel.x > m_max_vel) {
		m_body.m_vel.x = m_max_vel;
	} else if (m_body.m_vel.x < -m_max_vel) {
		m_body.m_vel.x = -m_max_vel;
	}
	
	text.setString( "Velocity: " + std::to_string(m_body.m_vel.x) + "\n"
		+ "Acceleration: " + std::to_string(m_body.m_acc.x) + "\n");
	

}

void Player::handleEvent(sf::Event& event) {
	
}

const Shape& Player::getShape() const {
	return m_body.getShape();;
}

sf::Vector2f Player::getHalfSize() {
	return sf::Vector2f(m_half_w, m_half_h);
}

sf::Vector2f Player::getVelocity() {
	return m_body.m_vel;
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(m_body);
	target.draw(text);

}

void Player::m_screenTestCollision() {
	if (m_body.m_shape.position.x + m_half_w > m_view->getSize().x) {
		m_body.m_vel.x = -m_body.m_vel.x;
		m_body.m_shape.position.x = m_view->getSize().x - m_half_w;
	}
	else if (m_body.m_shape.position.x - m_half_w < 0.f) {
		m_body.m_vel.x = -m_body.m_vel.x;
		m_body.m_shape.position.x = m_half_w;
	}
}