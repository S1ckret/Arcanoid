#include "Brick.h"

Brick::Brick() {
	m_alive = true;
}

Brick::Brick(float h_w, float h_h, sf::Vector2f pos, int lifes) {
	setPosition(pos.x, pos.y);
	setSize(h_w, h_h);
	m_alive = true;
	m_life = lifes;
	updateColor();
}

Brick::~Brick() {
}

void Brick::setSize(float h_w, float h_h) {
	m_rect.setSize(h_w, h_h);
}

void Brick::setPosition(float x, float y) {
	m_rect.setPosition(x, y);
}

void Brick::minusLife() {
	m_life--;
	if (m_life < 1) {
		m_alive = false;
	}
	updateColor();
}

const Rectangle& Brick::getRectangle() const {
	return m_rect;
}

bool Brick::isAlive() {
	return m_alive;
}

void Brick::updateColor() {
	switch (m_life) {
		case 0: m_rect.setPosition(-1000.f, -1000.f);
			break;
		case 1: m_rect.setColor(sf::Color(255, 0, 0));
			break;
		case 2: m_rect.setColor(sf::Color(255, 165, 0));
			break;
		case 3: m_rect.setColor(sf::Color(255, 255, 0));
			break;
		case 4: m_rect.setColor(sf::Color(144, 238, 144));
			break;
		case 5: m_rect.setColor(sf::Color(0, 128, 0));
			break;
		case 6: m_rect.setColor(sf::Color(0, 90, 0));
			break;
		case 7: m_rect.setColor(sf::Color(0, 0, 255));
			break;
		case 8: m_rect.setColor(sf::Color(0, 0, 140));
			break;
		default: m_rect.setColor(sf::Color(128, 128, 128));
			break;
			
	}
}

void Brick::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(m_rect);
}

