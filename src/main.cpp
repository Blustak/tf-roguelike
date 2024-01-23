#include <SDL2/SDL.h>
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_video.h>
#include <stdio.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char *argv[]) {
  // The windo to render to
  SDL_Window *window = NULL;

  // The surface contained by the window
  SDL_Surface *surface = NULL;

  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    printf("SDL Could not initialise! SD_Error: %s\n", SDL_GetError());
  } else {
    window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
                              SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == NULL) {
      printf("Window could not be created! SDL_Error:%s\n", SDL_GetError());
    } else {
      surface = SDL_GetWindowSurface(window);

      SDL_FillRect(surface, NULL,
                   SDL_MapRGB(surface->format, 0xFF, 0xFF, 0xFF));

      SDL_Rect *test_rect;
      test_rect->x = 10;
      test_rect->y = 10;
      test_rect->w = 50;
      test_rect->h = 50;

      SDL_FillRect(surface, test_rect,
                   SDL_MapRGB(surface->format, 0xFF, 0x00, 0x00));

      SDL_UpdateWindowSurface(window);

      // bootstrapping to have teh window stay open
      SDL_Event e;
      bool quit = false;
      while (quit == false) {
        while (SDL_PollEvent(&e)) {
          if (e.type == SDL_QUIT)
            quit = true;
        }
      }
    }
  }

  SDL_DestroyWindow(window);

  SDL_Quit();

  return 0;
}
