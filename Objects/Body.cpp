#include "Body.h"



Body::Body() {
}

Body::Body(Shape& sh) {
	m_shape = sh;
	m_shape.world = m_shape.local;
	for (ui i = 0; i < m_shape.local.size(); i++) {
		m_shape.world[i] = sf::Vertex(m_shape.local[i].position + m_shape.position); // + position
	}
	
}


Body::~Body() {
}

void Body::setBorderBox(sf::VertexArray& va) {
	for (ui i = 0; i < va.getVertexCount(); i++) {
		m_shape.local.push_back(va[i]);
		m_shape.world.push_back(sf::Vertex(va[i].position + m_shape.position)); // + position
	}
}

void Body::setPosition(sf::Vector2f pos) {
	m_shape.position = pos;
}


void Body::setPosition(float x, float y) {
	m_shape.position = sf::Vector2f(x, y);
}

void Body::setColor(sf::Color cl) {
	m_shape.setColor(cl);
}

void Body::setAcceleration(sf::Vector2f acc) {
	m_acc = acc;
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

void Body::applyForce(sf::Vector2f force) {
	m_force += force;
}

void Body::update(float d_time) {
	m_d_time = d_time;
	//f = ma // a = f/m (m = 1) => a = f;
	m_acc += m_force;
	m_force = sf::Vector2f(0.f, 0.f);
	m_vel += m_acc * d_time;
	m_shape.position += m_vel * d_time;
	if (!m_shape.local.empty()) {
		for (ui i = 0; i < m_shape.local.size(); i++) {
				m_shape.world[i].position = m_shape.local[i].position + m_shape.position;
		}
	}
}

void Body::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(&m_shape.world[0], m_shape.world.size(), sf::Quads);
}

sf::Vector2f Body::getVelocity() {
	return m_vel * m_d_time;
}

const Shape& Body::getShape() const {
	return m_shape;
}









