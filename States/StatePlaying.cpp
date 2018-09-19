#include "StatePlaying.h"

#include "../Game.h"

StatePlaying::StatePlaying(Game& game) : StateBase(game) {
	m_window = &game.getWindow();
	m_view.reset(sf::FloatRect(0, 0, 1920, 1080));
	Shape shape;
	shape.position = sf::Vector2f(1000.f, 300.f);
	shape.local.push_back(sf::Vertex(sf::Vector2f(-20.f, -30.f)));
	shape.local.push_back(sf::Vertex(sf::Vector2f(20.f, 0.f)));
	shape.local.push_back(sf::Vertex(sf::Vector2f(100.f, 0.f)));
	shape.local.push_back(sf::Vertex(sf::Vector2f(100.f, 60.f)));
	shape.local.push_back(sf::Vertex(sf::Vector2f(-20.f, 60.f)));
	
	body = new Body(shape);
	
	rect.setRect(50.f, 50.f);
	rect.setPosition(200.f, 200.f);
}

StatePlaying::~StatePlaying() {
	delete body;
}

void StatePlaying::handleInput() {

}

void StatePlaying::update(float d_time) {
	body->update(d_time);
}

void StatePlaying::render() {
	m_window->setView(m_view);
	m_window->draw(*body);
	m_window->draw(rect);
}

void StatePlaying::debugRender() {

}

void StatePlaying::handleEvent(sf::Event& event) {

}