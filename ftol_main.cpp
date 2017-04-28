#include "ftol_SDL.h"
#include "ftol_main.h"

//ftol_main constructor
ftol_main::ftol_main(int width, int height)
{
  quit = false;
  ScreenWidth = width;
  ScreenHeight = height;

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
  grass = new ftol_sprite(renderer, "Data/grass.bmp", 0, 0, ScreenWidth, ScreenHeight, 1);

  player = NULL;
  player = new ftol_sprite(renderer, "Data/celes.png", 250, 250, 48, 72, 0);
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
          player->SetY(player->GetY() - STRIDE_LENGTH);
          break;

        case SDLK_s:
          player->SetY(player->GetY() + STRIDE_LENGTH);
          break;

        case SDLK_a:
          player->SetX(player->GetX() - STRIDE_LENGTH);
          break;

        case SDLK_d:
          player->SetX(player->GetX() + STRIDE_LENGTH);
          break;

        default:
          break;
      }
      break;
    default:
      break;
  }
}

//GameLoop runs the game
void ftol_main::GameLoop(void)
{
  while(!quit && mainEvent->type != SDL_QUIT)
  {
    SDL_PollEvent(mainEvent);
    SDL_RenderClear(renderer);

    grass->Draw();
    player->Draw();

    keyPress();

    SDL_RenderPresent(renderer);
  }
}
