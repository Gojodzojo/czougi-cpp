#pragma once
#include "Prompt.h"
#include "window.h"
#include "font.h"
#include "utils.h"

class InvalidLevelPrompt :
    public Prompt
{
    sf::Text title;
    sf::Text okButtonText;
    sf::RectangleShape background;

public:
    InvalidLevelPrompt();
    void draw(sf::RenderWindow&);
    bool processEvent(sf::RenderWindow& window, sf::Event& event);
};

