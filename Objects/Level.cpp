#include "Level.h"

Level::Level() {
	m_win = 0;
	m_font.loadFromFile("res/BKANT.TTF");
	m_win_text.setFont(m_font);
}

Level::Level(std::string filename, sf::View* view) {
	m_win = 0;
	m_font.loadFromFile("res/BKANT.TTF");
	m_win_text.setFont(m_font);
	
	load(filename);
	m_view = view;
	
	m_ball.setView(m_view);
	m_ball.setPlayer(&m_player);
	m_player.setView(m_view);
	
	m_win_text.setString("You Won !");
	m_win_text.setCharacterSize(72);
	m_win_text.setOrigin(m_win_text.getLocalBounds().left + m_win_text.getLocalBounds().width / 2.f, 
		m_win_text.getLocalBounds().top + m_win_text.getLocalBounds().height / 2.f);
	m_win_text.setPosition(m_view->getSize() / 2.f);
	
}

Level::~Level() {
	auto it = m_particles.begin();
	while (it != m_particles.end()) {
		m_particles.erase(it);
	}
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
	m_ball.testCollision(m_player.getShape());
	if (!m_win) {
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
	}
	else {
		if (m_particles.empty()) {
		sf::VertexArray box(sf::Quads, 4);
		box[0].position = sf::Vector2f(-10.f, -10.f);
		box[1].position = sf::Vector2f(10.f, -10.f);
		box[2].position = sf::Vector2f(10.f, 10.f);
		box[3].position = sf::Vector2f(-10.f, 10.f);
		for (int i = 0; i < 100; i++) {
			m_particles.push_back(new Body());
			m_particles[i]->setBorderBox(box);
			m_particles[i]->setColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
			m_particles[i]->setPosition(m_view->getSize()/ 2.f + sf::Vector2f(rand() % 200 - 100, rand() % 200 - 100));
			m_particles[i]->setAcceleration(sf::Vector2f(0.f, 250.1f));
			m_particles[i]->setVelocity(sf::Vector2f(rand() %  300 - 150.f, -230.f));
		}
	} else {
		for (auto it = m_particles.begin(); it != m_particles.end(); it++) {
			(*it)->update(d_time);	
		}
	}
	}
	
	m_player.update(d_time);
	m_ball.update(d_time);
	
	if (m_bricks.empty()) {
		m_win = 1;
	}
}

void Level::handleEvent(sf::Event event) {
	
}

void Level::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	for (int i = 0; i < m_bricks.size(); i++) {
		target.draw(*m_bricks[i]);
	}
	target.draw(m_ball);
	target.draw(m_player);
	
	if (m_win) {
		target.draw(m_win_text);
		for (auto it = m_particles.begin(); it != m_particles.end(); it++) {
			target.draw(*(*it));
		}
		
	}
}