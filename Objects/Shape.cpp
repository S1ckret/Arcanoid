#include "Shape.h"

void Shape::setColor(sf::Color cl) {
	for (ui i = 0; i < world.size(); i++) {
		world[i].color = cl;
	}
}