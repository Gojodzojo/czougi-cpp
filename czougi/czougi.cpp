#include <SFML/Graphics.hpp>
#include <iostream>
#include "window.h"
#include "Scene.h"
#include "Menu.h"
#include "font.h"
#include "textures.h"
#include "Settings.h"

using namespace std;
using namespace sf;

int main()
{
    RenderWindow window(VideoMode(VIEW_WIDTH, VIEW_HEIGHT), WINDOW_TITLE);
    window.setFramerateLimit(FRAMERATE_LIMIT);

    RectangleShape background(Vector2f(VIEW_WIDTH, VIEW_HEIGHT));
    background.setPosition(0, 0);
    background.setFillColor(Color::Black);

    try
    {
        loadFonts();
        loadTextures();
        loadSettings();
    }
    catch (const exception& e)
    {
        cout << "Failed to load resources: " << e.what();
        return 1;
    }

    Scene* scene = new Menu;
    Clock clock;

    while (window.isOpen())
    {
        float deltaTime = clock.getElapsedTime().asSeconds();
        clock.restart();

        Event event;
        while (window.pollEvent(event))
        {
            Scene* newScene = scene->processEvent(window, event);
            if (newScene != nullptr)
            {
                delete scene;
                scene = newScene;
            }

            if (event.type == Event::Closed)
                window.close();

            // Aktualizowanie wielkości wyświetlanego obszaru po zmienieniu wielkości okna
            else if (event.type == Event::Resized)
                handleResize(window, event);
        }
       
        Scene* newScene = scene->doCalculations(window, deltaTime);
        if (newScene != nullptr)
        {
            delete scene;
            scene = newScene;
        }

        // Rysowanie obiektów
        window.clear(Color::Blue);
        window.draw(background);
        scene->draw(window);
        window.display();
    }

    return 0;
}