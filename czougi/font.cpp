#include "font.h"

using namespace sf;
using namespace std;

Font robotoRegular;
Font sansExtraBold;

void loadFonts()
{
	if (!robotoRegular.loadFromFile("fonts/Roboto-Regular.ttf"))
	{
		throw runtime_error("Could not load Roboto-Regular.ttf");
	}

	if (!sansExtraBold.loadFromFile("fonts/OpenSans-ExtraBold.ttf"))
	{
		throw runtime_error("Could not load OpenSans-ExtraBold.ttf");
	}
}