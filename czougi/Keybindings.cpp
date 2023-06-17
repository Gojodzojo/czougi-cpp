#include "Keybindings.h"

using namespace std;
using namespace sf;

Keybindings playersKeybindings[4] = {
	Keybindings(sf::Keyboard::W, sf::Keyboard::S, sf::Keyboard::A, sf::Keyboard::D, sf::Keyboard::E),
	Keybindings(sf::Keyboard::Up, sf::Keyboard::Down, sf::Keyboard::Left, sf::Keyboard::Right, sf::Keyboard::RShift),
	Keybindings(sf::Keyboard::U, sf::Keyboard::J, sf::Keyboard::H, sf::Keyboard::K, sf::Keyboard::I),
	Keybindings(sf::Keyboard::Num8, sf::Keyboard::Num5, sf::Keyboard::Num4, sf::Keyboard::Num6, sf::Keyboard::Num9),
};

Keybindings::Keybindings(sf::Keyboard::Key up, sf::Keyboard::Key down, sf::Keyboard::Key left, sf::Keyboard::Key right, sf::Keyboard::Key shot)
	: up(up), down(down), left(left), right(right), shot(shot)
{
}

string getGameConfigPath();

void saveKeybindings()
{
	string keybindingsPath = getGameConfigPath() + "\\keybindings.txt";

	ofstream file(keybindingsPath);

	for (int i = 0; i < 4; i++)
	{
		file << playersKeybindings[i].up << ' ';
		file << playersKeybindings[i].down << ' ';
		file << playersKeybindings[i].left << ' ';
		file << playersKeybindings[i].right << ' ';
		file << playersKeybindings[i].shot << endl;
	}
}

void loadKeybindings()
{
	string keybindingsPath = getGameConfigPath() + "\\keybindings.txt";

	ifstream file(keybindingsPath);

	if (file)
	{
		for (int i = 0; i < 4; i++)
		{
			int t;
			file >> t;
			playersKeybindings[i].up = (Keyboard::Key)t;
			file >> t;
			playersKeybindings[i].down = (Keyboard::Key)t;
			file >> t;
			playersKeybindings[i].left = (Keyboard::Key)t;
			file >> t;
			playersKeybindings[i].right = (Keyboard::Key)t;
			file >> t;
			playersKeybindings[i].shot = (Keyboard::Key)t;
		}
	}
}
