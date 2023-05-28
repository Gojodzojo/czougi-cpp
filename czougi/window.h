#pragma once
#include <SFML/Graphics.hpp>

static const char* WINDOW_TITLE = "Czougi";
const int VIEW_WIDTH = 1250;
const int VIEW_HEIGHT = 900;
const unsigned int FRAMERATE_LIMIT = 60;


void handleResize(sf::RenderWindow&, sf::Event&);