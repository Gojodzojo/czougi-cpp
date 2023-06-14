#include "InvalidLevelPrompt.h"

using namespace sf;
using namespace std;

InvalidLevelPrompt::InvalidLevelPrompt() : background(Vector2f(BACKGROUND_WIDTH, BACKGROUND_HEIGHT))
{
    title.setFont(robotoRegular);
    title.setCharacterSize(50);

    okButtonText = title;

    title.setString("Poziom musi miec co\nnajmniej dwa czolgi, a kazdy\nz czolgow musi miec\nustawionego swojego orzelka");
    okButtonText.setString("Ok");

    centerTextOrigin(title);
    centerTextOrigin(okButtonText);

    title.setPosition(VIEW_CENTER_X, VIEW_CENTER_Y - 60);
    okButtonText.setPosition(VIEW_CENTER_X, VIEW_CENTER_Y + 130);

    title.setFillColor(Color::Black);
    okButtonText.setFillColor(Color::Green);

    background.setOrigin(BACKGROUND_WIDTH / 2, BACKGROUND_HEIGHT / 2);
    background.setPosition(VIEW_CENTER_X, VIEW_CENTER_Y);
    background.setFillColor(Color::White);
    background.setOutlineColor(Color::Cyan);
    background.setOutlineThickness(5);
}

void InvalidLevelPrompt::draw(sf::RenderWindow& window)
{
    window.draw(background);
    window.draw(title);
    window.draw(okButtonText);
}

pair<bool, Scene*> InvalidLevelPrompt::processEvent(sf::RenderWindow& window, sf::Event& event)
{
    if (event.type == Event::MouseButtonReleased && event.mouseButton.button == Mouse::Left)
    {
        Vector2f mousePosition = window.mapPixelToCoords(Vector2i(event.mouseButton.x, event.mouseButton.y));

        if (isHovered(okButtonText.getGlobalBounds(), mousePosition))
        {
            return make_pair(false, nullptr);
        }
    }

    return make_pair(true, nullptr);
}
