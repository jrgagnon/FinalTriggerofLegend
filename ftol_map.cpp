#include "ftol_map.h"

ftol_map::ftol_map(int l, int h, int total, std::string MapPath, SDL_Renderer* passed_renderer, std::string TexturePath)
{
  myMap = NULL;
  mapLength = l;
  mapHeight = h;
  totalMapTiles = total;
  renderer = passed_renderer;
  texture = loadTexture(TexturePath.c_str());
  createMap(MapPath.c_str());
}

ftol_map::~ftol_map(void)
{
  SDL_DestroyTexture(texture);
  SDL_DestroyRenderer(renderer);
  delete myMap;
  delete myTileSet;
}

void ftol_map::setMapTile(int x, int y, ftol_tile* newTile)
{
  myMap[x][y] = newTile;
}

ftol_tile ftol_map::getTile(int x, int y)
{
  return myMap[x][y];
}

bool ftol_map::createMap(std::string FilePath)
{
  //Success flag
  bool tilesLoaded = true;

  //The tile offsets
  int x = 0;
  int y = 0;

  //Open the map
  std::ifstream map(FilePath.c_str());

  //If the map couldn't be loaded
  if( map == NULL )
  {
    printf( "Unable to load map file!\n" );
	  tilesLoaded = false;
  }
	else
	{
    myMap = ftol_tile[totalMapTiles];
    //Initialize the tiles
	  for( int i = 0; i < totalMapTiles; ++i )
    {
      //Determines what kind of tile will be made
      int tileType = -1;

      //Read tile from map file
      map >> tileType;

      //If the was a problem in reading the map
      if( map.fail() )
      {
        //Stop loading map
        printf( "Error loading map: Unexpected end of file!\n" );
        tilesLoaded = false;
        break;
      }

      //If the number is a valid tile number
      if( ( tileType >= 0 ) && ( tileType < totalMapTiles ) )
      {
        myMap[i] = new ftol_tile(x, y, tileType, myTileSet->getTileSection(tileType));
      }
			//If we don't recognize the tile type
			else
			{
        //Stop loading map
				printf( "Error loading map: Invalid tile type at %d!\n", i );
				tilesLoaded = false;
				break;
			}

			//Move to next tile spot
			x += TILE_WIDTH;

			//If we've gone too far
			if( x >= mapLength )
			{
				//Move back
				x = 0;

				//Move to the next row
				y += TILE_HEIGHT;
			}
		}
  }
}

SDL_Texture* ftol_map::loadTexture(std::string path)
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

void ftol_map::DrawMap(SDL_Rect camera)
{
  for(int i = 0; i < totalMapTiles; i++)
  {
    myMap[i].render(camera, renderer, texture);
  }
}
