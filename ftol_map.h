#include "ftol_SDL.h"
#include "ftol_tile.h"

#pragma once

class ftol_map
{
  public:
    ftol_map(int l, int h, int total, std::string MapPath, SDL_Renderer* passed_renderer, std::string TexturePath);
    ~ftol_map(void);
		void setMapTile(int x, int y, ftol_tile* newTile);  //Returns the entire set of tile sections
    ftol_tile getTile(int x, int y);  //Returns the tile associated with the passed location
    void DrawMap(SDL_Rect camera);

  private:
    bool createMap(std::string FilePath); //Creates this map
    SDL_Texture* loadTexture(std::string path);

    ftol_tile *myMap; //The map associated with this object
    ftol_tileset *myTileSet; //The tile set to be used with this map
    SDL_Renderer* renderer;
    SDL_Texture* texture;

    int mapLength;
    int mapHeight;
    int totalMapTiles;
};
