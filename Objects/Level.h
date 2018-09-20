#pragma once 

#include <string>
#include <fstream>
#include <vector>

#include "SFML/Graphics.hpp"

#include "Brick.h"
#include "Ball.h"

class Level : public sf::Drawable{
public:
	Level();
	Level(std::string filename);
	~Level();
	
	void load(std::string filename);
	void setWindow(sf::RenderWindow* win);
	
	void handleInput();
	void update(float d_time);
	void handleEvent(sf::Event event);
	
private:
	// loadPlayerCfg();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
private:
	sf::RenderWindow* m_win;

	std::vector<Brick* > m_bricks;
	Ball m_ball;
	// Player
	// Ball
};