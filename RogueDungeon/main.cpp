#include <SDL2/SDL_error.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_video.h>
#include <iostream>
#include <SDL2/SDL.h>

// Screen Dimmensions COnstants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char* args[]){
  
  // This is the window that will be rendered to
  SDL_Window* window = NULL;

  // The surface contained by the window
  SDL_Surface* screenSurface = NULL;

  // Initializing SDL
  if( SDL_Init(SDL_INIT_VIDEO) < 0){
    printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
  }
  else {
  // Creating the window
    window = SDL_CreateWindow("Rogue Dungeon", SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,SCREEN_WIDTH,SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if(window == NULL){
      printf("Window could not be created! SDL_Error: %s\n",SDL_GetError());
    }
    else{
      // Getting the Window surface
      screenSurface = SDL_GetWindowSurface(window);

      // Filling the surface with a color
      SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0,0,0));

      // Updating the surface
      SDL_UpdateWindowSurface(window);

      // "Hack" to get window to stay up
      SDL_Event e; bool quit = false; while(quit == false){while(SDL_PollEvent(&e)){if(e.type ==SDL_QUIT) quit = true;}} 

    }
  }
}
