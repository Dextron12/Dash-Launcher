#pragma once
#ifndef GUI_H
#define GUI_H

#include <SDL2\SDL.h>
#include <SDL2\SDL_ttf.h>
#include <vector>
#include <string>

class Primitives{
    public:
        void rectangle(SDL_Renderer &render, SDL_Rect rect, std::vector<int> colour);
};

class Text{
    TTF_Font* font;

    //Surfaces for texture rendering
    SDL_Surface* textLayer;
    SDL_Texture* text;

    TTF_Font* loadFont(std::string fontPath, int ptSize);
    public:
        Text(std::string fontPath, int fontSize);
        void draw(SDL_Renderer &render, std::string msg, SDL_Rect position, SDL_Color colour);
};

class imageBtn{
    SDL_Texture* texture;
    public:
        imageBtn(SDL_Renderer &render, std::string filePath);
        void draw(SDL_Renderer &render, SDL_Rect rect);

        bool pressed = false;
};

class Form{

    
    std::string inActive;
    SDL_Rect pos;
    
    public:
        std::string input; // active text shown during typing
        bool state = false;

        Form(SDL_Rect position, std::string inActiveMsg);
        void draw(SDL_Renderer &render, Primitives shapes, Text fontObject);
};

class MessageRenderer{

    public:
        bool state = true;
        void draw(SDL_Renderer* render, SDL_Rect pos, std::string msg, std::string title, Text fontObject, Primitives drawObject);

};

#endif