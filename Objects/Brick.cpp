#include "Brick.h"

Brick::Brick() {}

Brick::Brick(float h_w, float h_h, sf::Vector2f pos, int lifes) {
	setPosition(pos.x, pos.y);
	setSize(h_w, h_h);
	m_life = lifes;
}

Brick::~Brick() {
}

void Brick::setSize(float h_w, float h_h) {
	m_rect.setSize(h_w, h_h);
}

void Brick::setPosition(float x, float y) {
	m_rect.setPosition(x, y);
}

const Rectangle& Brick::getRectangle() {
	return m_rect;
}

void Brick::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(m_rect);
}

