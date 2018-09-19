#include "Rectangle.h"

Rectangle::Rectangle() {
	for (ui i = 0; i < 4; i++) {
		m_shape.local.push_back(sf::Vertex(sf::Vector2f(0.f, 0.f)));
	}
	m_shape.world = m_shape.local;
}

Rectangle::Rectangle(float h_w, float h_h, sf::Vector2f pos) {
	m_shape.position = pos;
	setRect(h_w, h_h);
}

void Rectangle::setPosition(float x, float y) {
	m_shape.position = sf::Vector2f(x, y);
	if (!m_shape.world.empty()) {
		for (ui i = 0; i < 4; i++) {
			m_shape.world[i] = sf::Vertex(m_shape.local[i].position + m_shape.position);
		}
	}
}

void Rectangle::setRect(float h_w, float h_h) {
	std::vector<sf::Vertex>().swap(m_shape.local);
	std::vector<sf::Vertex>().swap(m_shape.world);
	
	m_shape.local.push_back(sf::Vertex(sf::Vector2f(-h_w, -h_h)));
	m_shape.local.push_back(sf::Vertex(sf::Vector2f(h_w, -h_h)));
	m_shape.local.push_back(sf::Vertex(sf::Vector2f(h_w, h_h)));
	m_shape.local.push_back(sf::Vertex(sf::Vector2f(-h_w, h_h)));
	
	for (ui i = 0; i < 4; i++) {
		m_shape.world.push_back(sf::Vertex(m_shape.local[i].position + m_shape.position));
	}
}

void Rectangle::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(&m_shape.world[0], m_shape.world.size(), sf::Quads);
}