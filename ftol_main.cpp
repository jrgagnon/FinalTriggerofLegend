#include "ftol_main.h"

//ftol_main constructor
ftol_main::ftol_main(int width, int height)
{
  quit = false;
  ScreenWidth = width;
  ScreenHeight = height;

  MoveUp = false;
  MoveDown = false;
  MoveLeft = false;
  MoveRight = false;

  timeCheck = SDL_GetTicks();

  //Initialize and create the game window
  window = NULL;
  window = SDL_CreateWindow("Final Trigger of Legend", 100, 100, ScreenWidth, ScreenHeight, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

  if(window == NULL)
  {
    std::cout << "Window could not be created" << std::endl;
    quit = true;
  } else {
    surface = SDL_GetWindowSurface(window);

    //Create renderer for window
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if(renderer == NULL)
    {
      printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
      quit = true;
    }
    else
    {
      //Initialize renderer color
      SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    }
  }

  grass = NULL;
  grass = new ftol_sprite(renderer, "Data/checker.png", 0, 0, 1024, 1024, 1);

  townTiles = NULL;
  townTiles = new ftol_tileset(4, 3);

  //townMap = NULL;
  //townMap = new ftol_map(16, 12, 192, "Data/lazy.map", renderer, "Data/tiles.png");

  player = NULL;
  player = new ftol_sprite(renderer, "Data/celes.png", 5, 5, 36, 54, 0);

  camera.x = 0;
  camera.y = 0;
  camera.w = ScreenWidth;
  camera.h = ScreenHeight;
  //Initialize the event trigger used to see various actions of the window
  //Like close
  mainEvent = new SDL_Event();
}

//ftol_main destructor
ftol_main::~ftol_main(void)
{
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  delete grass;
  delete player;
  delete mainEvent;
}

void ftol_main::keyPress(void)
{
  int newValue = 0;
  switch(mainEvent->type)
  {
    case SDL_KEYDOWN:

      switch(mainEvent->key.keysym.sym)
      {
        case SDLK_w:
          MoveUp = true;
          break;

        case SDLK_s:
          MoveDown = true;
          break;

        case SDLK_a:
          MoveLeft = true;
          break;

        case SDLK_d:
          MoveRight = true;
          break;

        default:
          break;
      }
      break;

    case SDL_KEYUP:

      switch(mainEvent->key.keysym.sym)
      {
        case SDLK_w:
          MoveUp = false;
          break;

        case SDLK_s:
          MoveDown = false;
          break;

        case SDLK_a:
          MoveLeft = false;
          break;

        case SDLK_d:
          MoveRight = false;
          break;

        default:
          break;
        }
          break;
    default:
      break;
  }

  if (timeCheck+10 < SDL_GetTicks())
  {
    int tempY = 0;
    int tempX = 0;

    if (MoveUp)
    {
      tempY = player->GetY() - STRIDE_LENGTH;

      if(tempY < 0)
      {
        tempY = 0;
      }

      player->SetY(tempY);
    }

    if (MoveDown)
    {
      tempY = player->GetY() + STRIDE_LENGTH;

      if(tempY > LEVEL_HEIGHT - player->GetH())
      {
        tempY = LEVEL_HEIGHT - player->GetH();
      }

      player->SetY(tempY);
    }

    if (MoveLeft)
    {
      tempX = player->GetX() - STRIDE_LENGTH;

      if(tempX < 0)
      {
        tempX = 0;
      }

      player->SetX(tempX);
    }
    
    if (MoveRight)
    {
      tempX = player->GetX() + STRIDE_LENGTH;

      if(tempX > LEVEL_WIDTH - player->GetW())
      {
        tempX = LEVEL_WIDTH - player->GetW();
      }

      player->SetX(tempX);
    }

    timeCheck = SDL_GetTicks();
  }
}

void ftol_main::updateCamera(void)
{
  //Center the camera over the player
  camera.x = player->GetX() - ScreenWidth / 2;
  camera.y = player->GetY() - ScreenHeight / 2;

  //Keep the camera in bounds
  if( camera.x < 0 )
  {
    camera.x = 0;
  }
  if( camera.y < 0 )
  {
    camera.y = 0;
  }
  if( camera.x > LEVEL_WIDTH - camera.w )
  {
    camera.x = LEVEL_WIDTH - camera.w;
  }
  if( camera.y > LEVEL_HEIGHT - camera.h )
  {
    camera.y = LEVEL_HEIGHT - camera.h;
  }
}

//GameLoop runs the game
void ftol_main::GameLoop(void)
{
  while(!quit && mainEvent->type != SDL_QUIT)
  {
    SDL_PollEvent(mainEvent);
    SDL_RenderClear(renderer);

    //townMap->DrawMap(camera);
    grass->Draw(camera);
    player->Draw(camera);

    keyPress();
    updateCamera();

    SDL_RenderPresent(renderer);
  }
}
