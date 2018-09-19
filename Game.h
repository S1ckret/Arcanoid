#pragma once

#include <vector>
#include <memory>

#include "SFML/Graphics.hpp"

#include "States/StateBase.h"
#include "States/StatePlaying.h"


class Game {
public:
	Game();
	~Game();

	void run();
	void pop();
	sf::RenderWindow& getWindow();

private:
	StateBase& getState();

	void tryPop();
	void handleEvent();

	std::vector<std::unique_ptr<StateBase>> m_states;

	template <typename T, typename ...Args>
	void pushState(Args&& ...args);

private:
	sf::RenderWindow m_window;
	bool m_should_pop;

	float m_d_time;
	float m_elapsed_time;
	float m_last_time;
	sf::Clock m_clock;




};

template <typename T, typename ...Args>
void Game::pushState(Args&& ...args) {
	m_states.push_back(std::make_unique<T>(std::forward<Args>(args)...));
}