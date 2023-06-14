#include "window.h"

using namespace sf;

void handleResize(RenderWindow& window, Event& event)
{
    float viewportWidth = 1;
    float viewportHeight = 1;
    float viewportX = 0;
    float viewportY = 0;

    float windowAspectRatio = (float)event.size.height / (float)event.size.width;
    float targetAspectRatio = (float)VIEW_HEIGHT / (float)VIEW_WIDTH;

    if (windowAspectRatio > targetAspectRatio)
    {
        viewportHeight = targetAspectRatio / windowAspectRatio;

        viewportY = (1 - viewportHeight) / 2;
    }
    else
    {
        viewportWidth = windowAspectRatio / targetAspectRatio;
        viewportX = (1 - viewportWidth) / 2;
    }

    View visibleArea = window.getDefaultView();
    visibleArea.setViewport(FloatRect(viewportX, viewportY, viewportWidth, viewportHeight));
    window.setView(visibleArea);
}