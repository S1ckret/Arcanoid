#pragma once 

#include "Body.h"
#include "Shape.h"

#include "SFML/Graphics.hpp"

#include <string>

class Ball : public sf::Drawable {
public:
	Ball();
	~Ball();
	
	void setWindow(sf::RenderWindow* win);
//	void tieToPlayer(Player& pl);
	
	void update(float d_time);
	bool testCollision(const Shape& sh);
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	
	void m_screenCollision();
private:
	sf::RenderWindow* m_win;
	Body m_body;
	
	sf::Font font;
	sf::Text text;
};