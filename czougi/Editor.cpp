#include "Editor.h"

using namespace sf;
using namespace std;

Editor::Editor(Level level): level(level)
{
	title.setFont(robotoRegular);
	title.setCharacterSize(50);
	title.setString("To jest Editor");
}

Scene* Editor::processEvent(sf::RenderWindow& window, sf::Event& event)
{
	return nullptr;
}

Scene* Editor::doCalculations(sf::RenderWindow& window, float deltaTime)
{
	return nullptr;
}

void Editor::draw(sf::RenderWindow& window)
{
	window.draw(title);
}