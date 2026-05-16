#pragma once

#include <SDL3/SDL.h>

struct MainMenuButton
{
    float x, y;
    float width, height;
    int row;
};

void renderMainMenuButton(SDL_Renderer* renderer, SDL_Texture* texture,
                          const MainMenuButton& button);

bool isMainMenuButtonHovered(const MainMenuButton& button, float mouseX,
                             float mouseY);
