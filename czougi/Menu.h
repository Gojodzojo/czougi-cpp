#pragma once
#include <iostream>
#include "Scene.h"
#include "font.h"
#include "window.h"
#include "utils.h"
#include "Keybindings.h"
#include "Creators.h"
#include "textures.h"
#include "Level.h"
#include "Arena.h"
#include "Editor.h"

class Menu :
    public Scene
{
private:
	// char sterowanie[20];
	int z2;
	sf::Sprite Tlo1;
	sf::Sprite Tytol1;
	sf::Text tekst;
	sf::Text tekst2;
	sf::ConvexShape convex;
	sf::Text tekst3;
	sf::ConvexShape convex3;
	sf::Text tekst5;
	sf::ConvexShape convex4;
	sf::Text tekst6;
	sf::ConvexShape convex5;
	sf::Text tekst7;
	sf::Text tekst8;
	sf::Text tekst9;
	sf::Text tekst10;
	sf::ConvexShape convex6;
	sf::Text tekst11;
	sf::Text tekst12;
	sf::RectangleShape rectangle1;
	sf::Text litera1;
	sf::Text tekst13;
	sf::RectangleShape rectangle2;
	sf::Text litera2;
	sf::Text tekst14;
	sf::RectangleShape rectangle3;
	sf::Text litera3;
	sf::Text tekst15;
	sf::RectangleShape rectangle4;
	sf::Text litera4;
	sf::Text tekst31;
	sf::RectangleShape rectangle17;
	sf::Text litera17;
	sf::Text tekst16;
	sf::Text tekst17;
	sf::RectangleShape rectangle5;
	sf::Text litera5;
	sf::Text tekst18;
	sf::RectangleShape rectangle6;
	sf::Text litera6;
	sf::Text tekst19;
	sf::RectangleShape rectangle7;
	sf::Text litera7;
	sf::Text tekst20;
	sf::RectangleShape rectangle8;
	sf::Text litera8;
	sf::Text tekst32;
	sf::RectangleShape rectangle18;
	sf::Text litera18;
	sf::Text tekst21;
	sf::Text tekst22;
	sf::RectangleShape rectangle9;
	sf::Text litera9;
	sf::Text tekst23;
	sf::RectangleShape rectangle10;
	sf::Text litera10;
	sf::Text tekst24;
	sf::RectangleShape rectangle11;
	sf::Text litera11;
	sf::Text tekst25;
	sf::RectangleShape rectangle12;
	sf::Text litera12;
	sf::Text tekst33;
	sf::RectangleShape rectangle19;
	sf::Text litera19;
	sf::Text tekst26;
	sf::Text tekst27;
	sf::RectangleShape rectangle13;
	sf::Text litera13;
	sf::Text tekst28;
	sf::RectangleShape rectangle14;
	sf::Text litera14;
	sf::Text tekst29;
	sf::RectangleShape rectangle15;
	sf::Text litera15;
	sf::Text tekst30;
	sf::RectangleShape rectangle16;
	sf::Text litera16;
	sf::Text tekst34;
	sf::RectangleShape rectangle20;
	sf::Text litera20;
	sf::Text tekst35;
	std::vector<sf::Text> levelNames;
	std::vector<sf::RectangleShape>box;
	std::vector<sf::Sprite>cog;
	std::vector<sf::Sprite>play;
	sf::Text tekst36;
	sf::Text tekst37;
	sf::Text tekst38;
	sf::Text tekst39;
	sf::Text tekst40;
	sf::CircleShape shape1;
	sf::Sprite X1;
	sf::CircleShape shape;
	sf::Event event;//wychwyca interakcje z uzytkownikiem
	int okno;
	float m;
	float m2;
	int start;
	int start2;
public:
	Menu(int okno = 0);
	Scene* processEvent(sf::RenderWindow& window, sf::Event& event);
	Scene* doCalculations(sf::RenderWindow& window, float deltaTime);
	void draw(sf::RenderWindow& window);
};

