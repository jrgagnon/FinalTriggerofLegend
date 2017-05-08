#include "ftol_SDL.h"

#pragma once

class ftol_tileset
{
  public:
    ftol_tileset(int xTiles, int yTiles);
		SDL_Rect* getTileSections();  //Returns the entire set of tile sections
    SDL_Rect getTileSection(int x);  //Returns the section associated with the passed number

  private:
    void sectionTiles();
		SDL_Rect* tileSections; //The boxes that determine what sections to load
    int X;  //The number of tiles in the X plane
    int Y;  //The number of tiles in the Y plane
    int totalTiles; //The total number of tiles in this tile set
};
