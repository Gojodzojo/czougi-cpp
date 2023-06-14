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
    std::pair<bool, Scene*> processEvent(sf::RenderWindow& window, sf::Event& event);
};

