#include "ftol_SDL.h"
#include "ftol_sprite.h"
#include "ftol_tileset.h"
//#include "ftol_map.h"

#define LEVEL_WIDTH 1024
#define LEVEL_HEIGHT 1024

#pragma once

class ftol_main
{
  public:
    ftol_main(int width, int height);
    ~ftol_main(void);

    void GameLoop(void);

  private:
    SDL_Surface* loadSurface(std::string path);
    void keyPress(void);
    void updateCamera(void);

    bool quit;

    int ScreenWidth;          // The Desired width of the screen
    int ScreenHeight;         // The Desired height of the screen

    bool MoveUp;              // Used to determine what buttons are pressed
    bool MoveDown;
    bool MoveLeft;
    bool MoveRight;

    int timeCheck;            // Used in calculation for player movement speed

    SDL_Window* window;       // Main Window of the game
    SDL_Surface* surface;     // surface contained by the window
    SDL_Event* mainEvent;     // Event logger?
    SDL_Renderer* renderer;   // Renderer for textures

    SDL_Rect camera;         // Rect for the camera to determine what is shown

    ftol_tileset* townTiles;  // Stores the tileset info for the town

    //ftol_map* townMap;
    ftol_sprite* player;
    ftol_sprite* grass;
};
