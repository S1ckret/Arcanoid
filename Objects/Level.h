#pragma once 

#include <string>
#include <fstream>
#include <vector>

#include "SFML/Graphics.hpp"

#include "Brick.h"
#include "Ball.h"
#include "Player.h"

class Level : public sf::Drawable{
public:
	Level();
	Level(std::string filename, sf::View* view);
	~Level();
	
	void load(std::string filename);
	void setView(sf::View* view);
	
	void handleInput();
	void update(float d_time);
	void handleEvent(sf::Event event);
	
private:
	// loadPlayerCfg();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
private:
	sf::View* m_view;

	std::vector<Brick* > m_bricks;
	Ball m_ball;
	Player m_player;
};