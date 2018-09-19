#include "Body.h"



Body::Body() {
	font.loadFromFile("res/BKANT.TTF");
	text.setFont(font);
}

Body::Body(Shape& sh) {
	m_shape = sh;
	m_shape.world = m_shape.local;
	for (ui i = 0; i < m_shape.local.size(); i++) {
		m_shape.world[i] = sf::Vertex(m_shape.local[i].position + m_shape.position); // + position
	}
	
	font.loadFromFile("res/BKANT.TTF");
	text.setFont(font);
	text.setPosition(100.f, 100.f);
	text.setCharacterSize(24);
	text.setString(std::to_string(m_shape.local.size()) + "   " + std::to_string(m_shape.world.size()));
}


Body::~Body() {
}

void Body::setBorderBox(sf::VertexArray& va) {
	for (ui i = 0; i < va.getVertexCount(); i++) {
		m_shape.local.push_back(va[i]);
		m_shape.world.push_back(sf::Vertex(va[i].position + m_shape.position)); // + position
	}
}

void Body::setTexture(sf::Texture& tx) {
	
}

void Body::setTextureBox(sf::VertexArray& va) {
	if (!m_shape.local.empty()) {
		for (ui i = 0; i < m_shape.local.size(); i++) {
			m_shape.local[i].texCoords = sf::Vector2f(va[i].position.x, va[i].position.y);
		}
	}
}

void Body::update(float d_time) {
	m_vel += m_acc;
	
	m_shape.position += m_vel;
	if (!m_shape.local.empty()) {
		for (ui i = 0; i < m_shape.local.size(); i++) {
				m_shape.world[i].position = m_shape.local[i].position + m_shape.position;
		}
	}
}

void Body::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(&m_shape.world[0], m_shape.world.size(), sf::LineStrip);
	target.draw(text);
}











