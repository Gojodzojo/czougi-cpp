#pragma once
#include <vector>
#include "Keybindings.h"
#include "Block.h"
class Eagles : public Block
{
public:
	int _playerNumber;
	Eagles(int playerNumber);
	sf::RectangleShape graphics;
	/*std::vector<Eagle> eagles;*/
	void draw(sf::RenderWindow&);
};
