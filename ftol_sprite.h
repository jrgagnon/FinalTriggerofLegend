#include "ftol_SDL.h"

#pragma once

class ftol_sprite
{
public:
      ftol_sprite(SDL_Renderer* passed_renderer, std::string FilePath, int x, int y, int w, int h, int b);
      ~ftol_sprite(void);
      void Draw(SDL_Rect camera);  //Draws the image to the screen
      void SetX(int X);
      void SetY(int Y);
      void setPosition(int X, int Y);
      int GetX(void);
      int GetY(void);
      int GetW(void);
      int GetH(void);

private:
      int backround;  //Denotes whether this sprite will be a backround or not
      SDL_Texture* loadTexture(std::string path);
      SDL_Rect rect;
      SDL_Rect drawRect;
      SDL_Renderer* renderer;
      SDL_Texture* texture;
};
