#include "ftol_tile.h"

ftol_tile::ftol_tile(int x, int y, int tileType, SDL_Rect tileBox)
{
  myType = tileType;

  boundingBox.x = x;
  boundingBox.y = y;
  boundingBox.w = TILE_WIDTH;
  boundingBox.h = TILE_HEIGHT;

  myTileBox = tileBox;
}

void ftol_tile::render(SDL_Rect camera, SDL_Renderer* passed_renderer, SDL_Texture* texture)
{
  if(checkCollision(boundingBox, camera))
  {
    SDL_RenderCopy(passed_renderer, texture, &myTileBox, &boundingBox);
  }
}

bool ftol_tile::checkCollision(SDL_Rect a, SDL_Rect b)
{
  //The sides of the rectangles
  int leftA, leftB;
  int rightA, rightB;
  int topA, topB;
  int bottomA, bottomB;

  //Calculate the sides of rect A
  leftA = a.x;
  rightA = a.x + a.w;
  topA = a.y;
  bottomA = a.y + a.h;

  //Calculate the sides of rect B
  leftB = b.x;
  rightB = b.x + b.w;
  topB = b.y;
  bottomB = b.y + b.h;

  //If any of the sides from A are outside of B
  if( bottomA <= topB )
  {
    return false;
  }

  if( topA >= bottomB )
  {
    return false;
  }

  if( rightA <= leftB )
  {
    return false;
  }

  if( leftA >= rightB )
  {
    return false;
  }

  //If none of the sides from A are outside B
  return true;
}

int ftol_tile::getType()
{
  return myType;
}
