#pragma once 

#include <vector>

#include "SFML/Graphics.hpp"

typedef unsigned int ui;

struct Shape {
public:
	
	sf::Vector2f position;
	
	std::vector<sf::Vertex> local;
	std::vector<sf::Vertex> world;
	
};