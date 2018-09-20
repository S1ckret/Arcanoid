#include "Level.h"

Level::Level() {
	
}

Level::~Level() {
	
}

Level::Level(std::string filename) {
	load(filename);
}

void Level::load(std::string filename) {
	std::ifstream in;
	in.open(filename);
	if (!in.is_open()) {
		std::ofstream out;
		out.open("lvl/error.txt");
		out << "Cannot open file";
		out.close();
		return;
	}
	
	float h_w, h_h, x, y;
	int life;
	std::ofstream out;
	out.open("lvl/log.txt");
	
	while (in >> h_w >> h_h >> x >> y >> life)
	{
		out << h_w << " " << h_h << " "  << x << " "  << y << " "  << life << "\n";
		m_bricks.push_back(new Brick(h_w, h_h, sf::Vector2f(x, y), life));
	}
	in.close();
	out.close();
}

void Level::setWindow(sf::RenderWindow* win) {
	m_win = win;
	m_ball.setWindow(m_win);
}
	
void Level::handleInput() {
	
}

void Level::update(float d_time) {
	for (int i = 0; i < m_bricks.size(); i++) {
		m_ball.testCollision(m_bricks[i]->getRectangle().getShape());
	}
	m_ball.update(d_time);
//	m_ball.testCollision(m_bricks[0]->getRectangle().getShape());
	
}

void Level::handleEvent(sf::Event event) {
	
}

void Level::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	for (int i = 0; i < m_bricks.size(); i++) {
		target.draw(*m_bricks[i]);
	}
	target.draw(m_ball);
}