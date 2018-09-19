#include "Game.h"

Game::Game() {
	m_window.create(sf::VideoMode(1280, 720, 32), "Arcanoid.exe");
	m_window.setVerticalSyncEnabled(1);

	m_should_pop = 0;
	
	pushState<StatePlaying>(*this);
}

Game::~Game() {

}

void Game::run() {
	m_clock.restart();
	while (m_window.isOpen() && !m_states.empty()) {
		m_elapsed_time = m_clock.getElapsedTime().asSeconds();
		m_d_time = m_elapsed_time - m_last_time;
		m_last_time = m_elapsed_time;

		StateBase& current_state = getState();
		current_state.handleInput();
		current_state.update(m_d_time);
		


		m_window.clear();
		current_state.render();
		m_window.display();

		handleEvent();
		tryPop();
	}

}

void Game::pop() {
	m_should_pop = 1;
}

sf::RenderWindow& Game::getWindow() {
	return m_window;
}

StateBase& Game::getState() {
	return *m_states.back();
}

void Game::tryPop() {
	if (m_should_pop) {
		m_states.pop_back();
		m_should_pop = 0;
	}
}

void Game::handleEvent() {
	sf::Event event;
	while (m_window.pollEvent(event)) {
		getState().handleEvent(event);

		switch(event.type) {
			case sf::Event::Closed:
				m_window.close(); 
				break;
			default: 
				break;
		}
	}
}

