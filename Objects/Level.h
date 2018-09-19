#pragma once 

#include <string>
#include <fstream>
#include <vector>

#include "SFML/Graphics.hpp"

#include "Brick.h"

class Level : public sf::Drawable{
public:
	Level();
	Level(std::string filename);
	~Level();
	
	void load(std::string filename);
	
	void handleInput();
	void update(float d_time);
	void handleEvent(sf::Event event);
	
private:
	// loadPlayerCfg();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
private:
	std::vector<Brick* > m_bricks;
	// Player
	// Ball
};