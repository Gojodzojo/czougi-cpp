#pragma once
#include <iostream>
#include <vector>
#include "Player.h"
#include "Block.h"

class Level
{
public:
	std::string name;
	std::vector<Player> players;
	std::vector<BrickWall> brickWalls;
	std::vector<ConcreteWall> concreteWalls;
	std::vector<Water> Waters;
	std::vector<Leaves> leaves;
};
