#include "ftol_SDL.h"
#include "ftol_main.h"

int main(int argc, char *argv[])
{
  ftol_main* main = new ftol_main(600, 400);

  main->GameLoop();

  return 0;
}
