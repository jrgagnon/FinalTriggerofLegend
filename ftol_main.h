#include "ftol_sprite.h"

#define STRIDE_LENGTH 3

class ftol_main
{
  public:
    ftol_main(int width, int height);
    ~ftol_main(void);

    void GameLoop(void);

  private:
    SDL_Surface* loadSurface(std::string path);
    void keyPress(void);

    bool quit;

    int ScreenWidth;          // The Desired width of the screen
    int ScreenHeight;         // The Desired height of the screen

    SDL_Window* window;       // Main Window of the game
    SDL_Surface* surface;     // surface contained by the window
    SDL_Event* mainEvent;     // Event logger?
    SDL_Renderer* renderer;   // Renderer for textures

    ftol_sprite* grass;
    ftol_sprite* player;
};
