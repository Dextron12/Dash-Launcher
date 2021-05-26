//Include general headers here:
#include <iostream>
#include <string>

//Include SDL libs here:
#include <SDL2/SDL.h>


//Define global variabels here
int errorCode = 0; //Change to -1 to abort program

int width = 1024; int height = 480;
SDL_Window* window; // The global window that gets initialized
SDL_Renderer* render; // The global render

bool appRunning = true; //Flag for window oeprations
