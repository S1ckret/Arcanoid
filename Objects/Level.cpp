#include "Level.h"

Level::Level() {
	m_win = 0;
	m_font.loadFromFile("res/BKANT.TTF");
	m_win_text.setFont(m_font);
}

Level::Level(std::string filename, sf::View* view) {
	Level();
	load(filename);
	m_view = view;
	m_ball.setView(m_view);
	m_ball.setPlayer(&m_player);
	m_player.setView(m_view);
	m_win_text.setCharacterSize(26);
	m_win_text.setPosition(m_view->getSize() / 2.f);
	m_win_text.setString("You Won !");
}

Level::~Level() {
	
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

void Level::setView(sf::View* view) {
	m_view = view;
	m_ball.setView(m_view);
	m_player.setView(m_view);
}
	
void Level::handleInput() {
	m_ball.handleInput();
	m_player.handleInput();
}

void Level::update(float d_time) {
	if (!m_bricks.empty()) {
		m_ball.testCollision(m_player.getShape());
		for (auto it = m_bricks.begin(); it != m_bricks.end(); ) {
			if (m_ball.testCollision((*it)->getRectangle().getShape())) {
				(*it)->minusLife();
				if (!(*it)->isAlive()) {
					m_bricks.erase(it);
				} else {
					it++;
				}
			} else {
				it++;
			}
		}
		m_player.update(d_time);
		m_ball.update(d_time);
	}
	else {
		m_win = 1;
	}
}

void Level::handleEvent(sf::Event event) {
	
}

void Level::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	if (!m_win) {
	for (int i = 0; i < m_bricks.size(); i++) {
		target.draw(*m_bricks[i]);
	}
	target.draw(m_ball);
	target.draw(m_player);
	}
	else {
		target.draw(m_win_text);
	}
}