#pragma once
#include <iostream>
#include <vector>
#include "Player.h"
#include "Block.h"

const int LEVEL_SIZE = 30;

class Level
{
public:
	std::string name = "Nowy poziom";
	std::vector<Player> players;
	std::vector<BrickWall> brickWalls;
	std::vector<ConcreteWall> concreteWalls;
	std::vector<Water> waters;
	std::vector<Leaves> leaves;

	bool isTileAvaliable(float, float);
};

