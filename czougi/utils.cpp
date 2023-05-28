#include "utils.h"

using namespace sf;

void centerTextOrigin(Text& text)
{
	FloatRect textBounds = text.getGlobalBounds();
	text.setOrigin(textBounds.width / 2, textBounds.height / 2);
}

bool isHovered(const FloatRect& bounds, const Vector2f& mousePosition)
{
	return mousePosition.x >= bounds.left &&
		mousePosition.x <= bounds.left + bounds.width &&
		mousePosition.y >= bounds.top &&
		mousePosition.y <= bounds.top + bounds.height;
}