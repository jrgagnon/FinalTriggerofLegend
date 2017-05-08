#include "ftol_tileset.h"

ftol_tileset::ftol_tileset(int xTiles, int yTiles)
{
  X = xTiles;
  Y = yTiles;
  totalTiles = X * Y;

  tileSections = NULL;

  sectionTiles();
}

SDL_Rect* ftol_tileset::getTileSections()
{
  return tileSections;
}

SDL_Rect ftol_tileset::getTileSection(int x)
{
  return tileSections[x];
}

void ftol_tileset::sectionTiles()
{
  tileSections = new SDL_Rect[totalTiles];
  int count = 0;
  for(int i = 0; i < X; i++)
  {
    for(int j = 0; j < Y; j++)
    {
      tileSections[count].x = i * TILE_WIDTH;
      tileSections[count].y = j * TILE_HEIGHT;
      tileSections[count].w = TILE_WIDTH;
      tileSections[count].h = TILE_HEIGHT;
      count++;
    }
  }

}
