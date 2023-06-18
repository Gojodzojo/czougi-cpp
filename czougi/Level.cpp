#include "Level.h"

using namespace sf;
using namespace std;

string getGameConfigPath()
{
	PWSTR path;
	SHGetKnownFolderPath(FOLDERID_Documents, KF_FLAG_DEFAULT, NULL, &path);
	wstring wstrpath(path);
	int size_needed = WideCharToMultiByte(CP_UTF8, 0, &wstrpath[0], (int)wstrpath.size(), NULL, 0, NULL, NULL);
	std::string strTo(size_needed, 0);
	WideCharToMultiByte(CP_UTF8, 0, &wstrpath[0], (int)wstrpath.size(), &strTo[0], size_needed, NULL, NULL);
	CoTaskMemFree(path);

	return strTo + "\\Czougi";
}

string getGameSavesPath()
{
	return getGameConfigPath() + "\\saves";
}

vector<string> getLevelNames()
{
	string gameConfigPath = getGameConfigPath();
	string gameSavesPath = gameConfigPath + "\\saves";
	filesystem::create_directory(gameConfigPath);
	filesystem::create_directory(gameSavesPath);

	vector<string> levelNames;

	for (const auto& file : filesystem::directory_iterator(gameSavesPath))
	{
		string fileName = file.path().filename().string();
		levelNames.push_back(fileName.substr(0, fileName.length() - 4));
	}

	return levelNames;
}

string getLevelPath(const string& name)
{
	return getGameSavesPath() + "\\" + name + ".txt";
}

bool isLevelNameAvaliable(const string& name)
{
	fstream file(getLevelPath(name));
	return !file.good();
}

Level::Level(): name("Nowy Poziom")
{
	if (!isLevelNameAvaliable(name))
	{
		for (int i = 1; true; i++)
		{
			if (isLevelNameAvaliable(name + " " + to_string(i)))
			{
				name += " " + to_string(i);
				break;
			}
		}
	}

	filesystem::create_directory(getGameSavesPath());
	save();
}

void Level::rename(const string& newName)
{
	filesystem::rename(getLevelPath(name), getLevelPath(newName));
	name = newName;
}

void Level::deleteLevel()
{
	filesystem::remove(getLevelPath(name));
}

bool Level::canBeSaved()
{
	if (players.size() < 2)
	{
		return false;
	}

	for (Player& player : players)
	{
		if (!player.eagle.isAlive)
		{
			return false;
		}
	}

	return true;
}

Level::Level(const string& levelName) : name(levelName)
{
	ifstream file(getLevelPath(levelName));

	int elementsNumber;
	file >> elementsNumber;
	players.reserve(elementsNumber);

	for (int i = 0; i < elementsNumber; i++)
	{
		int playerColor;
		file >> playerColor;
		Player player((PlayerColor)playerColor);
		
		Vector2f playerPosition;
		file >> playerPosition.x >> playerPosition.y;

		Vector2f eaglePosition;
		file >> eaglePosition.x >> eaglePosition.y;

		playerPosition.x *= BLOCK_SIZE;
		playerPosition.y *= BLOCK_SIZE;
		eaglePosition.x *= BLOCK_SIZE;
		eaglePosition.y *= BLOCK_SIZE;

		player.graphics.setPosition(playerPosition);
		player.eagle.graphics.setPosition(eaglePosition);
		player.eagle.isAlive = true;
		players.push_back(player);
	}

	file >> elementsNumber;
	brickWalls.reserve(elementsNumber);

	for (int i = 0; i < elementsNumber; i++)
	{
		Vector2f blockPosition;
		file >> blockPosition.x >> blockPosition.y;

		blockPosition.x *= BLOCK_SIZE;
		blockPosition.y *= BLOCK_SIZE;

		BrickWall block;
		block.graphics.setPosition(blockPosition);
		brickWalls.push_back(block);
	}

	file >> elementsNumber;
	concreteWalls.reserve(elementsNumber);

	for (int i = 0; i < elementsNumber; i++)
	{
		Vector2f blockPosition;
		file >> blockPosition.x >> blockPosition.y;

		blockPosition.x *= BLOCK_SIZE;
		blockPosition.y *= BLOCK_SIZE;

		ConcreteWall block;
		block.graphics.setPosition(blockPosition);
		concreteWalls.push_back(block);
	}

	file >> elementsNumber;
	waters.reserve(elementsNumber);

	for (int i = 0; i < elementsNumber; i++)
	{
		Vector2f blockPosition;
		file >> blockPosition.x >> blockPosition.y;

		blockPosition.x *= BLOCK_SIZE;
		blockPosition.y *= BLOCK_SIZE;

		Water block;
		block.graphics.setPosition(blockPosition);
		waters.push_back(block);
	}

	file >> elementsNumber;
	leaves.reserve(elementsNumber);

	for (int i = 0; i < elementsNumber; i++)
	{
		Vector2f blockPosition;
		file >> blockPosition.x >> blockPosition.y;

		blockPosition.x *= BLOCK_SIZE;
		blockPosition.y *= BLOCK_SIZE;

		Leaves block;
		block.graphics.setPosition(blockPosition);
		leaves.push_back(block);
	}
}

void Level::save()
{
	ofstream file(getLevelPath(name));
	
	file << players.size() << endl;

	for (Player& player : players)
	{
		Vector2f playerPosition = player.graphics.getPosition();
		Vector2f eaglePosition = player.eagle.graphics.getPosition();

		file << player.playerColor << ' ' << playerPosition.x / BLOCK_SIZE << ' ' << playerPosition.y / BLOCK_SIZE << ' ';
		file << eaglePosition.x / BLOCK_SIZE << ' ' << eaglePosition.y / BLOCK_SIZE << endl;
	}

	file << brickWalls.size() << endl;

	for (BrickWall& block : brickWalls)
	{
		Vector2f blockPosition = block.graphics.getPosition();
		file << blockPosition.x / BLOCK_SIZE << ' ' << blockPosition.y / BLOCK_SIZE << endl;
	}

	file << concreteWalls.size() << endl;

	for (ConcreteWall& block : concreteWalls)
	{
		Vector2f blockPosition = block.graphics.getPosition();
		file << blockPosition.x / BLOCK_SIZE << ' ' << blockPosition.y / BLOCK_SIZE << endl;
	}

	file << waters.size() << endl;

	for (Water& block : waters)
	{
		Vector2f blockPosition = block.graphics.getPosition();
		file << blockPosition.x / BLOCK_SIZE << ' ' << blockPosition.y / BLOCK_SIZE << endl;
	}

	file << leaves.size() << endl;

	for (Leaves& block : leaves)
	{
		Vector2f blockPosition = block.graphics.getPosition();
		file << blockPosition.x / BLOCK_SIZE << ' ' << blockPosition.y / BLOCK_SIZE << endl;
	}
}

bool Level::isTileAvaliable(float x, float y)
{
	for (auto& block : brickWalls)
	{
		Vector2f blockPosition = block.graphics.getPosition();
		if (blockPosition.x == x && blockPosition.y == y)
			return false;
	}

	for (auto& block : concreteWalls)
	{
		Vector2f blockPosition = block.graphics.getPosition();
		if (blockPosition.x == x && blockPosition.y == y)
			return false;
	}

	for (auto& block : waters)
	{
		Vector2f blockPosition = block.graphics.getPosition();
		if (blockPosition.x == x && blockPosition.y == y)
			return false;
	}

	for (auto& block : leaves)
	{
		Vector2f blockPosition = block.graphics.getPosition();
		if (blockPosition.x == x && blockPosition.y == y)
			return false;
	}

	for (auto& player : players)
	{
		Vector2f playerPosition = player.graphics.getPosition();
		if (x == playerPosition.x && y == playerPosition.y ||
			x == playerPosition.x + BLOCK_SIZE && y == playerPosition.y ||
			x == playerPosition.x && y == playerPosition.y + BLOCK_SIZE ||
			x == playerPosition.x + BLOCK_SIZE && y == playerPosition.y + BLOCK_SIZE)
			return false;

		Vector2f eaglePosition = player.eagle.graphics.getPosition();
		if (player.eagle.isAlive && (x == eaglePosition.x && y == eaglePosition.y ||
			x == eaglePosition.x + BLOCK_SIZE && y == eaglePosition.y ||
			x == eaglePosition.x && y == eaglePosition.y + BLOCK_SIZE ||
			x == eaglePosition.x + BLOCK_SIZE && y == eaglePosition.y + BLOCK_SIZE))
			return false;
	}

    return true;
}
