#pragma once
#include <iostream>
#include <vector>
#include "Player.h"
#include "Block.h"
#include <shlobj.h>
#include <fstream>
#include <vector>
#include <Windows.h>
#include <filesystem>

const int LEVEL_SIZE = 30;

bool isLevelNameAvaliable(const std::string&);
std::string getLevelPath(const std::string&);
std::string getGameConfigPath();
std::string getGameSavesPath();
std::vector<std::string> getLevelNames();


class Level
{
public:
	std::string name;
	std::vector<Player> players;
	std::vector<BrickWall> brickWalls;
	std::vector<ConcreteWall> concreteWalls;
	std::vector<Water> waters;
	std::vector<Leaves> leaves;

	Level();
	Level(const std::string&);
	bool isTileAvaliable(float, float);
	bool canBeSaved();
	void save();
	void rename(const std::string&);
	void deleteLevel();
};