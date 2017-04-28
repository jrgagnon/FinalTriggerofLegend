#include "ftol_SDL.h"

class ftol_sprite
{
public:
      ftol_sprite(SDL_Renderer* passed_renderer, std::string FilePath, int x, int y, int w, int h, int b);
      ~ftol_sprite(void);
      void Draw();  //Draws the image to the screen
      void SetX(int X);
      void SetY(int Y);
      void setPosition(int X, int Y);
      int GetX(void);
      int GetY(void);

private:
      int backround;  //Denotes whether this sprite will be a backround or not
      SDL_Texture* loadTexture(std::string path);
      SDL_Rect rect;
      SDL_Renderer* renderer;
      SDL_Texture* texture;
};
