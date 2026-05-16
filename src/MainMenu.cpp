#include "MainMenu.h"

void renderMainMenuButton(SDL_Renderer* renderer, SDL_Texture* texture,
                          const MainMenuButton& button)
{
    SDL_FRect buttonDestRect = {button.x, button.y, button.width,
                                button.height};
    SDL_FRect buttonSrcRect = {0, (float)button.row * 100, 500, 100};
    SDL_RenderTexture(renderer, texture, &buttonSrcRect, &buttonDestRect);
}

bool isMainMenuButtonHovered(const MainMenuButton& button, float mouseX,
                             float mouseY)
{
    if (mouseX >= button.x && mouseX <= button.x + button.width &&
        mouseY >= button.y && mouseY <= button.y + button.height)
    {
        return true;
    }
    else
    {
        return false;
    }
}
