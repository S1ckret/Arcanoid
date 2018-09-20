#include "Ball.h"

Ball::Ball() {
	m_body.setPosition(550.f, 600.f);
	
	sf::VertexArray box(sf::Quads, 4);
	box[0].position = sf::Vector2f(-10.f, -10.f);
	box[1].position = sf::Vector2f(10.f, -10.f);
	box[2].position = sf::Vector2f(10.f, 10.f);
	box[3].position = sf::Vector2f(-10.f, 10.f);
	m_body.setBorderBox(box);
	
	m_body.m_vel = sf::Vector2f(150.f, -150.f);
	m_body.m_acc = sf::Vector2f(0.f, 0.f);
	
	font.loadFromFile("res/BKANT.TTF");
	text.setFont(font);
	text.setPosition(100.f, 700.f);
}

Ball::~Ball() {
	
}

void Ball::setWindow(sf::RenderWindow* win) {
	m_win = win;
}

void Ball::update(float d_time) {
//	m_screenCollision();
	m_body.update(d_time);
}

void Ball::testCollision(const Shape& sh) {
	const Shape& ball = m_body.getShape();
	
	const sf::Vector2f half_sh = (sh.world[2].position - sh.world[0].position) * 0.5f;
	const sf::Vector2f half_ball = (ball.world[2].position - ball.world[0].position) * 0.5f;
	
	const float dx = sh.position.x - ball.position.x;
	const float px = (half_ball.x + half_sh.x) - abs(dx);
	if (px <= 0.f) {
		return;
	}
	
	const float dy = sh.position.y - ball.position.y;
	const float py = (half_ball.y + half_sh.y) - abs(dy);
	if (py <= 0.f) {
		return;
	}
	
	text.setString("Half shape: " + std::to_string(half_ball.x) + " " + std::to_string(half_ball.y) + "\n"
		+ "dx: " + std::to_string(dx) + " dy: " + std::to_string(dy) + "\n"
		+ "px: " + std::to_string(px) + " py: " + std::to_string(py));
	
	
	if (px < py) {
		m_body.m_vel = sf::Vector2f(-m_body.m_vel.x, m_body.m_vel.y);
	}
	else {
		m_body.m_vel = sf::Vector2f(m_body.m_vel.x, -m_body.m_vel.y);
	}
	
	
	
	
}

void Ball::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(m_body);
	target.draw(text);
}

void Ball::m_screenCollision() {
	const Shape& ball = m_body.getShape();
	const sf::Vector2f half_ball = (ball.world[1].position - ball.world[0].position) * 0.5f;
	
	if (ball.position.x + half_ball.x > m_win->getSize().x) {
		m_body.m_vel = sf::Vector2f(-m_body.m_vel.x, m_body.m_vel.y);
	}
	else if (ball.position.x - half_ball.x < 0.f) {
		m_body.m_vel = sf::Vector2f(-m_body.m_vel.x, m_body.m_vel.y);
	}
}