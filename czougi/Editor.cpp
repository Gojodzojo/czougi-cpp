﻿#include "Editor.h"

using namespace sf;
using namespace std;

const int TOOLBAR_WIDTH = VIEW_WIDTH - VIEW_HEIGHT;
const int LINE_THICKNESS = 2;

const Vector2f FILE_OPERATION_ICON_SIZE(40, 40);
const float FILE_OPERATION_ICON_MARGIN = (TOOLBAR_WIDTH - FILE_OPERATION_ICON_SIZE.x * 3) / 4 ;
const float FILE_OPERATION_ICON_POSITION_Y = VIEW_HEIGHT - 90;

const float TOOL_ICON_SIZE = BLOCK_SIZE * 2;
const float TOOL_ICON_MARGIN = (TOOLBAR_WIDTH - TOOL_ICON_SIZE * 3) / 4;

const float LEFT_TOOL_ICON_X = VIEW_HEIGHT + TOOL_ICON_MARGIN;
const float FIRST_ROW_TOOL_ICON_Y = 180;

Editor::Editor(Level level) : 
	level(level),
	toolbarBackground(Vector2f(TOOLBAR_WIDTH, VIEW_HEIGHT)),
	playIcon(FILE_OPERATION_ICON_SIZE),
	saveIcon(FILE_OPERATION_ICON_SIZE),
	deleteIcon(FILE_OPERATION_ICON_SIZE),
	horizontalLine(Vector2f(VIEW_HEIGHT, LINE_THICKNESS)),
	verticalLine(Vector2f(LINE_THICKNESS, VIEW_HEIGHT)),
	tools {
		make_unique<BrickWallTool>(),
		make_unique<ConcreteWallTool>(),
		make_unique<WaterTool>(),
		make_unique<LeavesTool>(),
		make_unique<TankTool>(yellowTankTexture, PlayerColor::Yellow),
		make_unique<TankTool>(blueTankTexture, PlayerColor::Blue),
		make_unique<TankTool>(greenTankTexture, PlayerColor::Green),
		make_unique<TankTool>(redTankTexture, PlayerColor::Red),
		make_unique<EagleTool>(yellowEagleTexture, PlayerColor::Yellow),
		make_unique<EagleTool>(blueEagleTexture, PlayerColor::Blue),
		make_unique<EagleTool>(greenEagleTexture, PlayerColor::Green),
		make_unique<EagleTool>(redEagleTexture, PlayerColor::Red),
		make_unique<EraserTool>()
	},
	activeToolIndex(0)
{
	for (int i = 0; i < sizeof(tools) / sizeof(unique_ptr<Tool>); i++)
	{
		tools[i]->setPosition(VIEW_HEIGHT + TOOL_ICON_MARGIN + (i % 3) * (TOOL_ICON_MARGIN + TOOL_ICON_SIZE), FIRST_ROW_TOOL_ICON_Y + (i / 3) * (TOOL_ICON_SIZE + TOOL_ICON_MARGIN));
	}

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

	horizontalLine.setOrigin(Vector2f(0, LINE_THICKNESS / 2));
	verticalLine.setOrigin(Vector2f(LINE_THICKNESS / 2, 0));
}

Scene* Editor::processEvent(sf::RenderWindow& window, sf::Event& event)
{
	if (event.type == Event::MouseMoved)
	{
		mousePosition = window.mapPixelToCoords(Vector2i(event.mouseMove.x, event.mouseMove.y));
	}
	if (event.type == Event::MouseButtonReleased && event.mouseButton.button == Mouse::Left)
	{
		Vector2f mousePosition = window.mapPixelToCoords(Vector2i(event.mouseButton.x, event.mouseButton.y));

		for (int i = 0; i < sizeof(tools) / sizeof(unique_ptr<Tool>); i++)
		{
			if (tools[i]->isHovered(mousePosition))
			{
				activeToolIndex = i;
			}
		}
	}

	return nullptr;
}

Scene* Editor::doCalculations(sf::RenderWindow& window, float deltaTime)
{
	return nullptr;
}

void Editor::draw(sf::RenderWindow& window)
{
	window.draw(toolbarBackground);
	window.draw(levelName);

	for (int i = 0; i < sizeof(tools) / sizeof(unique_ptr<Tool>); i++)
	{
		tools[i]->drawOnToolbar(window);
	}

	window.draw(playIcon);
	window.draw(saveIcon);
	window.draw(deleteIcon);

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

	if (mousePosition.x > 0 && mousePosition.x < VIEW_HEIGHT && mousePosition.y > 0 && mousePosition.y < VIEW_HEIGHT)
	{
		window.setMouseCursorVisible(false);
		Vector2f cursorPosition(((int)mousePosition.x / LEVEL_SIZE) * BLOCK_SIZE, ((int)mousePosition.y / LEVEL_SIZE) * BLOCK_SIZE);
		tools[activeToolIndex]->drawAsCursor(window, cursorPosition);
	}
	else
	{
		window.setMouseCursorVisible(true);
	}
}