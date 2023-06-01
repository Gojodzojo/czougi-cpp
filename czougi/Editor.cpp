#include "Editor.h"

using namespace sf;
using namespace std;

const int TOOLBAR_WIDTH = VIEW_WIDTH - VIEW_HEIGHT;
const int LINE_THICKNESS = 1;

const Vector2f FILE_OPERATION_ICON_SIZE(40, 40);
const float FILE_OPERATION_ICON_MARGIN = (TOOLBAR_WIDTH - FILE_OPERATION_ICON_SIZE.x * 3) / 4 ;
const float FILE_OPERATION_ICON_POSITION_Y = VIEW_HEIGHT - 90;

const float TOOL_ICON_SIZE = BLOCK_SIZE * 2;
const float TOOL_ICON_MARGIN = (TOOLBAR_WIDTH - TOOL_ICON_SIZE * 3) / 4;

const float LEFT_TOOL_ICON_X = VIEW_HEIGHT + TOOL_ICON_MARGIN;
const float MIDDLE_TOOL_ICON_X = VIEW_HEIGHT + TOOL_ICON_MARGIN * 2 + TOOL_ICON_SIZE;
const float RIGHT_TOOL_ICON_X = VIEW_HEIGHT + TOOL_ICON_MARGIN * 3 + TOOL_ICON_SIZE * 2;

const float FIRST_ROW_TOOL_ICON_Y = 180;
const float SECOND_ROW_TOOL_ICON_Y = FIRST_ROW_TOOL_ICON_Y + TOOL_ICON_SIZE + TOOL_ICON_MARGIN;
const float THIRD_ROW_TOOL_ICON_Y = SECOND_ROW_TOOL_ICON_Y + TOOL_ICON_SIZE + TOOL_ICON_MARGIN;
const float FOURTH_ROW_TOOL_ICON_Y = THIRD_ROW_TOOL_ICON_Y + TOOL_ICON_SIZE + TOOL_ICON_MARGIN;
const float FIFTH_ROW_TOOL_ICON_Y = FOURTH_ROW_TOOL_ICON_Y + TOOL_ICON_SIZE + TOOL_ICON_MARGIN;

Editor::Editor(Level level) : 
	level(level),
	toolbarBackground(Vector2f(TOOLBAR_WIDTH, VIEW_HEIGHT)),
	playIcon(FILE_OPERATION_ICON_SIZE),
	saveIcon(FILE_OPERATION_ICON_SIZE),
	deleteIcon(FILE_OPERATION_ICON_SIZE),
	horizontalLine(Vector2f(VIEW_HEIGHT, LINE_THICKNESS)),
	verticalLine(Vector2f(LINE_THICKNESS, VIEW_HEIGHT)),
	brickWallSprite(*brickWallTexture),
	concreteWallSprite(*concreteWallTexture),
	waterSprite(*waterTexture),
	leavesSprite(*leavesTexture),
	yellowTankSprite(*yellowTankTexture),
	blueTankSprite(*blueTankTexture),
	greenTankSprite(*greenTankTexture),
	redTankSprite(*redTankTexture),
	yellowEagleSprite(*yellowEagleTexture),
	blueEagleSprite(*blueEagleTexture),
	greenEagleSprite(*greenEagleTexture),
	redEagleSprite(*redEagleTexture),
	eraserIcon(*eraserTexture)
{
	brickWallSprite.setScale(TEXTURE_SCALE);
	concreteWallSprite.setScale(TEXTURE_SCALE);
	waterSprite.setScale(TEXTURE_SCALE);
	leavesSprite.setScale(TEXTURE_SCALE);
	yellowTankSprite.setScale(TEXTURE_SCALE);
	blueTankSprite.setScale(TEXTURE_SCALE);
	greenTankSprite.setScale(TEXTURE_SCALE);
	redTankSprite.setScale(TEXTURE_SCALE);
	yellowEagleSprite.setScale(TEXTURE_SCALE);
	blueEagleSprite.setScale(TEXTURE_SCALE);
	greenEagleSprite.setScale(TEXTURE_SCALE);
	redEagleSprite.setScale(TEXTURE_SCALE);
	eraserIcon.setScale(TEXTURE_SCALE);

	toolbarBackground.setOutlineColor(Color::White);
	toolbarBackground.setPosition(VIEW_HEIGHT, 0);

	levelName.setFont(robotoRegular);
	levelName.setCharacterSize(30);
	levelName.setString(level.name);
	centerTextOrigin(levelName);
	levelName.setPosition(VIEW_HEIGHT + TOOLBAR_WIDTH / 2, 80);
	levelName.setFillColor(Color::Black);

	playIcon.setFillColor(Color::Green);
	saveIcon.setFillColor(Color::Blue);
	deleteIcon.setFillColor(Color::Black);

	playIcon.setPosition(VIEW_HEIGHT + FILE_OPERATION_ICON_MARGIN, FILE_OPERATION_ICON_POSITION_Y);
	saveIcon.setPosition(VIEW_HEIGHT + FILE_OPERATION_ICON_MARGIN * 2 + FILE_OPERATION_ICON_SIZE.x, FILE_OPERATION_ICON_POSITION_Y);
	deleteIcon.setPosition(VIEW_HEIGHT + FILE_OPERATION_ICON_MARGIN * 3 + FILE_OPERATION_ICON_SIZE.x * 2, FILE_OPERATION_ICON_POSITION_Y);

	yellowEagleSprite.setPosition(MIDDLE_TOOL_ICON_X, SECOND_ROW_TOOL_ICON_Y);
	blueEagleSprite.setPosition(RIGHT_TOOL_ICON_X, SECOND_ROW_TOOL_ICON_Y);
	greenEagleSprite.setPosition(LEFT_TOOL_ICON_X, THIRD_ROW_TOOL_ICON_Y);
	redEagleSprite.setPosition(MIDDLE_TOOL_ICON_X, THIRD_ROW_TOOL_ICON_Y);

	yellowTankSprite.setPosition(RIGHT_TOOL_ICON_X, THIRD_ROW_TOOL_ICON_Y);
	blueTankSprite.setPosition(LEFT_TOOL_ICON_X, FOURTH_ROW_TOOL_ICON_Y);
	greenTankSprite.setPosition(MIDDLE_TOOL_ICON_X, FOURTH_ROW_TOOL_ICON_Y);
	redTankSprite.setPosition(RIGHT_TOOL_ICON_X, FOURTH_ROW_TOOL_ICON_Y);

	eraserIcon.setPosition(MIDDLE_TOOL_ICON_X, FIFTH_ROW_TOOL_ICON_Y);
}

Scene* Editor::processEvent(sf::RenderWindow& window, sf::Event& event)
{
	return nullptr;
}

Scene* Editor::doCalculations(sf::RenderWindow& window, float deltaTime)
{
	return nullptr;
}

template<typename T>
void drawToolIcon(float x, float y, T& graphics, RenderWindow& window)
{
	graphics.setPosition(Vector2f(x, y));
	window.draw(graphics);
	graphics.setPosition(Vector2f(x + BLOCK_SIZE, y));
	window.draw(graphics);
	graphics.setPosition(Vector2f(x, y + BLOCK_SIZE));
	window.draw(graphics);
	graphics.setPosition(Vector2f(x + BLOCK_SIZE, y + BLOCK_SIZE));
	window.draw(graphics);
}

void Editor::draw(sf::RenderWindow& window)
{
	window.draw(toolbarBackground);
	window.draw(levelName);

	drawToolIcon(LEFT_TOOL_ICON_X, FIRST_ROW_TOOL_ICON_Y, brickWallSprite, window);
	drawToolIcon(MIDDLE_TOOL_ICON_X, FIRST_ROW_TOOL_ICON_Y, concreteWallSprite, window);
	drawToolIcon(RIGHT_TOOL_ICON_X, FIRST_ROW_TOOL_ICON_Y, waterSprite, window);
	drawToolIcon(LEFT_TOOL_ICON_X, SECOND_ROW_TOOL_ICON_Y, leavesSprite, window);

	for (int i = 0; i < LEVEL_SIZE - 1; i++)
	{
		horizontalLine.setPosition(0, BLOCK_SIZE + i * BLOCK_SIZE);
		window.draw(horizontalLine);
	}

	for (int i = 0; i < LEVEL_SIZE - 1; i++)
	{
		verticalLine.setPosition(BLOCK_SIZE + i * BLOCK_SIZE, 0);
		window.draw(verticalLine);
	}

	window.draw(yellowEagleSprite);
	window.draw(blueEagleSprite);
	window.draw(greenEagleSprite);
	window.draw(redEagleSprite);
	window.draw(yellowTankSprite);
	window.draw(blueTankSprite);
	window.draw(greenTankSprite);
	window.draw(redTankSprite);
	window.draw(eraserIcon);
	window.draw(playIcon);
	window.draw(saveIcon);
	window.draw(deleteIcon);
}