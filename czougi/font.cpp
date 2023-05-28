#include "font.h"

using namespace sf;
using namespace std;

Font robotoRegular;

void loadFonts()
{
	if (!robotoRegular.loadFromFile("fonts/Roboto-Regular.ttf"))
	{
		throw runtime_error("Could not load Roboto-Regular.ttf");
	}
}