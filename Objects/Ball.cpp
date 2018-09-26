#include "Ball.h"

Ball::Ball() {
	m_tied = true;
	
	sf::VertexArray box(sf::Quads, 4);
	box[0].position = sf::Vector2f(-half_ball.x, -half_ball.y);
	box[1].position = sf::Vector2f(half_ball.x, -half_ball.y);
	box[2].position = sf::Vector2f(half_ball.x, half_ball.y);
	box[3].position = sf::Vector2f(-half_ball.x, half_ball.y);
	m_body.setBorderBox(box);
	
	m_body.m_vel = sf::Vector2f(0.f, 0.f);
	m_body.m_acc = sf::Vector2f(0.f, 0.f);
	
}

Ball::~Ball() {
	
}

void Ball::setView(sf::View* view) {
	m_view = view;
}

void Ball::setPlayer(Player* pl) {
	m_player = pl;
}

void Ball::handleInput() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		if (m_tied) {
			if (m_player->getVelocity().x > 0.f) {
				m_body.m_vel = sf::Vector2f(300.f, -300.f);
			}
			else {
				m_body.m_vel = sf::Vector2f(-300.f, -300.f);
			}
			m_tied = 0;
		}
	}
}

void Ball::update(float d_time) {
	m_screenCollision();
	
	m_body.update(d_time);
	if (m_tied) {
		m_body.setPosition(m_player->getShape().position - sf::Vector2f(0.f, m_player->getHalfSize().y) - sf::Vector2f(0.f, half_ball.y));
	}
}

bool Ball::testCollision(const Shape& sh) {
	
	Shape ball = m_body.getShape();
	ball.position += m_body.getVelocity();
	for (int i = 0; i < ball.world.size(); i++) {
		ball.world[i].position += m_body.getVelocity();
	}
	
	const sf::Vector2f half_sh = (sh.world[2].position - sh.world[0].position) * 0.5f;
	const sf::Vector2f half_ball = (ball.world[2].position - ball.world[0].position) * 0.5f;
	
	const float dx = sh.position.x - ball.position.x;
	const float px = (half_ball.x + half_sh.x) - abs(dx);
	if (px <= 0.f) {
		return false;
	}
	
	const float dy = sh.position.y - ball.position.y;
	const float py = (half_ball.y + half_sh.y) - abs(dy);
	if (py <= 0.f) {
		return false;
	}
	
	
	if (px < py) {
		m_body.m_vel = sf::Vector2f(-m_body.m_vel.x, m_body.m_vel.y);
		
	}
	else {
		m_body.m_vel = sf::Vector2f(m_body.m_vel.x, -m_body.m_vel.y);
	}	
	return true;
}

void Ball::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(m_body);
}

void Ball::m_screenCollision() {
	const Shape& ball = m_body.getShape();
	
	if (ball.position.x + half_ball.x > m_view->getSize().x) {
		m_body.m_vel.x = -m_body.m_vel.x;
		m_body.m_shape.position.x = m_view->getSize().x - half_ball.x;
	}
	else if (ball.position.x - half_ball.x < 0.f) {
		m_body.m_vel.x = -m_body.m_vel.x;
		m_body.m_shape.position.x = half_ball.x;
	}
	if (ball.position.y + half_ball.y > m_view->getSize().y) {
		m_tied = 1;
		m_body.m_vel = sf::Vector2f(0.f, 0.f);
	}
	else if (ball.position.y - half_ball.y < 0.f) {
		m_body.m_vel.y = -m_body.m_vel.y;
		m_body.m_shape.position.y = half_ball.y;
	}
}