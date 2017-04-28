#include "ftol_sprite.h"
#include "ftol_SDL.h"

ftol_sprite::ftol_sprite(SDL_Renderer* passed_renderer, std::string FilePath, int x, int y, int w, int h, int b)
{
  renderer = passed_renderer;
  backround = b;

  texture = loadTexture(FilePath.c_str());
	if(texture == NULL)
	{
		printf("Failed to load image!\n");
	}

  //Initialize the rectangle to passed size
  rect.x = x;
  rect.y = y;
  rect.w = w;
  rect.h = h;
}

SDL_Texture* ftol_sprite::loadTexture(std::string path)
{
  //The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if(loadedSurface == NULL)
	{
		printf( "Unable to load image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
	}
	else
	{
    //Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
		if( newTexture == NULL )
		{
			printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	return newTexture;
}

ftol_sprite::~ftol_sprite(void)
{
  SDL_DestroyTexture(texture);
}

void ftol_sprite::Draw()
{
  if(backround == 0) //Sprite is not a backround
  {
    SDL_RenderCopy(renderer, texture, NULL, &rect);
  } else //Sprite is backround
  {
    SDL_RenderCopy(renderer, texture, NULL, NULL);
  }
}

void ftol_sprite::SetX(int X)
{
  rect.x = X;
}

void ftol_sprite::SetY(int Y)
{
  rect.y = Y;
}

void ftol_sprite::setPosition(int X, int Y)
{
  rect.x = X;
  rect.y = Y;
}

int ftol_sprite::GetX(void)
{
  return rect.x;
}

int ftol_sprite::GetY(void)
{
  return rect.y;
}
