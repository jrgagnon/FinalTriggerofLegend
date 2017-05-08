#include "ftol_SDL.h"
#include "ftol_tileset.h"

#pragma once

class ftol_tile
{
  public:
    ftol_tile(int x, int y, int tileType, SDL_Rect tileBox);
		void render(SDL_Rect camera, SDL_Renderer* passed_renderer, SDL_Texture* texture);
    int getType();  //Returns the tile number it is
    SDL_Rect getBox(); //Get the collision box

  private:
    bool checkCollision(SDL_Rect a, SDL_Rect b);  //Checks collision between the 2 passed boxes
		SDL_Rect boundingBox; //The attributes of the tile
    SDL_Rect myTileBox; //The location of my tile on the tile sheet
		int myType; //The tile type
};
