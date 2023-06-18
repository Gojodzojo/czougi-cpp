#include "Editor.h"

using namespace sf;
using namespace std;

const int TOOLBAR_WIDTH = VIEW_WIDTH - VIEW_HEIGHT;
const int LINE_THICKNESS = 2;

const Vector2f FILE_OPERATION_ICON_SIZE(45, 45);
const float FILE_OPERATION_ICON_MARGIN = (TOOLBAR_WIDTH - FILE_OPERATION_ICON_SIZE.x * 3) / 4 ;
const float FILE_OPERATION_ICON_POSITION_Y = VIEW_HEIGHT - 90;

const float TOOL_ICON_SIZE = BLOCK_SIZE * 2;
const float TOOL_ICON_MARGIN = (TOOLBAR_WIDTH - TOOL_ICON_SIZE * 3) / 4;

const float LEFT_TOOL_ICON_X = VIEW_HEIGHT + TOOL_ICON_MARGIN;
const float FIRST_ROW_TOOL_ICON_Y = 180;

Editor::Editor(Level level) : 
	level(level),
	prompt(nullptr),
	toolbarBackground(Vector2f(TOOLBAR_WIDTH, VIEW_HEIGHT)),
	playIcon(*playIconTexture),
	saveIcon(*saveIconTexture),
	deleteIcon(*deleteIconTexture),
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
	activeToolIndex(0),
	isSelecting(false)
{
	playIcon.setScale(TEXTURE_SCALE);
	saveIcon.setScale(TEXTURE_SCALE);
	deleteIcon.setScale(TEXTURE_SCALE);

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

	playIcon.setPosition(VIEW_HEIGHT + FILE_OPERATION_ICON_MARGIN, FILE_OPERATION_ICON_POSITION_Y);
	saveIcon.setPosition(VIEW_HEIGHT + FILE_OPERATION_ICON_MARGIN * 2 + FILE_OPERATION_ICON_SIZE.x, FILE_OPERATION_ICON_POSITION_Y);
	deleteIcon.setPosition(VIEW_HEIGHT + FILE_OPERATION_ICON_MARGIN * 3 + FILE_OPERATION_ICON_SIZE.x * 2, FILE_OPERATION_ICON_POSITION_Y);

	horizontalLine.setOrigin(Vector2f(0, LINE_THICKNESS / 2));
	verticalLine.setOrigin(Vector2f(LINE_THICKNESS / 2, 0));
}

Scene* Editor::processEvent(sf::RenderWindow& window, sf::Event& event)
{
	if (prompt != nullptr)
	{
		auto result = prompt->processEvent(window, event);

		// Zmień scenę
		if (result.second != nullptr)
		{
			return result.second;
		}

		// Zamknij okno
		if (!result.first)
		{
			levelName.setString(level.name);
			centerTextOrigin(levelName);
			prompt.reset();
		}
	}
	else
	{
		if (event.type == Event::MouseMoved)
		{
			mousePosition = window.mapPixelToCoords(Vector2i(event.mouseMove.x, event.mouseMove.y));

			if (isSelecting)
			{
				if (mousePosition.x > VIEW_HEIGHT && mousePosition.x < 0 && mousePosition.y > VIEW_HEIGHT && mousePosition.y < 0)
				{
					isSelecting = false;
				}
				else
				{
					Vector2f cursorPosition(((int)mousePosition.x / LEVEL_SIZE) * BLOCK_SIZE, ((int)mousePosition.y / LEVEL_SIZE) * BLOCK_SIZE);
					Vector2f selectionRectanglePosition = selectionRectangle.getPosition();
					Vector2f selectionRectangleSize = cursorPosition - selectionRectanglePosition;
					Vector2f selectionRectangleOrigin(0, 0);

					if (selectionRectangleSize.x >= 0)
					{
						selectionRectangleSize.x += BLOCK_SIZE;
					}
					else
					{
						selectionRectangleSize.x -= BLOCK_SIZE;
						selectionRectangleOrigin.x -= BLOCK_SIZE;
					}

					if (selectionRectangleSize.y >= 0)
					{
						selectionRectangleSize.y += BLOCK_SIZE;
					}
					else
					{
						selectionRectangleSize.y -= BLOCK_SIZE;
						selectionRectangleOrigin.y -= BLOCK_SIZE;
					}

					selectionRectangle.setOrigin(selectionRectangleOrigin);
					selectionRectangle.setSize(selectionRectangleSize);
				}
			}
		}
		else if (event.type == Event::MouseButtonReleased && event.mouseButton.button == Mouse::Left)
		{
			Vector2f mousePosition = window.mapPixelToCoords(Vector2i(event.mouseButton.x, event.mouseButton.y));

			if (mousePosition.x > 0 && mousePosition.x < VIEW_HEIGHT && mousePosition.y > 0 && mousePosition.y < VIEW_HEIGHT && (isSelecting == tools[activeToolIndex]->isSelectable))
			{
				Vector2f cursorPosition(((int)mousePosition.x / LEVEL_SIZE) * BLOCK_SIZE, ((int)mousePosition.y / LEVEL_SIZE) * BLOCK_SIZE);
				Vector2f selectionRectanglePosition = selectionRectangle.getPosition();
				tools[activeToolIndex]->performAction(cursorPosition, selectionRectanglePosition, level);
			}
			else
			{
				if (isHovered(saveIcon.getGlobalBounds(), mousePosition))
				{
					if(level.canBeSaved())
					{
						level.save();
						return new Menu(4);
					}
					else
					{
						prompt = make_unique<InvalidLevelPrompt>();
					}
				}
				else if (isHovered(playIcon.getGlobalBounds(), mousePosition))
				{
					if (level.canBeSaved())
					{
						level.save();
						return new Arena(level);
					}
					else
					{
						prompt = make_unique<InvalidLevelPrompt>();
					}
				}
				else if (isHovered(deleteIcon.getGlobalBounds(), mousePosition))
				{
					prompt = make_unique<DeleteLevelPrompt>(level);
				}
				else if (isHovered(levelName.getGlobalBounds(), mousePosition))
				{
					prompt = make_unique<RenamePrompt>(level);
				}

				for (int i = 0; i < sizeof(tools) / sizeof(unique_ptr<Tool>); i++)
				{
					if (tools[i]->isHovered(mousePosition))
					{
						activeToolIndex = i;
					}
				}
			}

			isSelecting = false;
		}
		else if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left && tools[activeToolIndex]->isSelectable &&
			mousePosition.x > 0 && mousePosition.x < VIEW_HEIGHT && mousePosition.y > 0 && mousePosition.y < VIEW_HEIGHT)
		{
			Vector2f mousePosition = window.mapPixelToCoords(Vector2i(event.mouseButton.x, event.mouseButton.y));

			Vector2f cursorPosition(((int)mousePosition.x / LEVEL_SIZE) * BLOCK_SIZE, ((int)mousePosition.y / LEVEL_SIZE) * BLOCK_SIZE);
			selectionRectangle.setPosition(cursorPosition);
			selectionRectangle.setSize(Vector2f(BLOCK_SIZE, BLOCK_SIZE));
			selectionRectangle.setOrigin(0, 0);
			selectionRectangle.setFillColor(tools[activeToolIndex]->selectionColor);
			isSelecting = true;
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

	for (auto& block : level.brickWalls)
	{
		block.draw(window);
	}

	for (auto& block : level.concreteWalls)
	{
		block.draw(window);
	}

	for (auto& block : level.waters)
	{
		block.draw(window);
	}

	for (auto& block : level.leaves)
	{
		block.draw(window);
	}

	for (auto& player : level.players)
	{
		player.draw(window);

		if (player.eagle._isAlive)
		{
			player.eagle.draw(window);
		}
	}

	if (prompt != nullptr)
	{
		window.setMouseCursorVisible(true);
		prompt->draw(window);
	}
	else
	{
		if (mousePosition.x > 0 && mousePosition.x < VIEW_HEIGHT && mousePosition.y > 0 && mousePosition.y < VIEW_HEIGHT)
		{
			window.setMouseCursorVisible(false);

			if (isSelecting)
			{
				window.draw(selectionRectangle);
			}
			else
			{
				Vector2f cursorPosition(((int)mousePosition.x / LEVEL_SIZE) * BLOCK_SIZE, ((int)mousePosition.y / LEVEL_SIZE) * BLOCK_SIZE);
				tools[activeToolIndex]->drawAsCursor(window, cursorPosition);
			}
		}
		else
		{
			window.setMouseCursorVisible(true);
		}
	}
}