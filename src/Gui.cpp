#include "Gui.hpp"
#include "Events.hpp"


#include <SDL2\SDL_image.h>
#include <SDL2\SDL_ttf.h>
#include <iostream>

//Define Primitives functions here


void Primitives::rectangle(SDL_Renderer &render, SDL_Rect rect, std::vector<int> colour){
    SDL_SetRenderDrawColor(&render, colour[0], colour[1], colour[2], colour[3]);
    SDL_RenderFillRect(&render, &rect);
}

TTF_Font* Text::loadFont(std::string fontPath, int ptSize){
    TTF_Font* lFont = TTF_OpenFont(fontPath.c_str(), ptSize);
    if (lFont == nullptr){
        std::cout << "Failed to load font: " << TTF_GetError() << "\n";
    }
    return lFont;
}

Text::Text(std::string fontPath, int fontSize){
    font = loadFont(fontPath, fontSize);
}

void Text::draw(SDL_Renderer &render, std::string msg, SDL_Rect position, SDL_Color colour){
    textLayer = TTF_RenderText_Blended(font, msg.c_str(), colour);
    position.w = textLayer->w; position.h = textLayer->h;
    text = SDL_CreateTextureFromSurface(&render, textLayer);
    SDL_RenderCopy(&render, text, NULL, &position);
    //Clear mem resources
    SDL_DestroyTexture(text);
    SDL_FreeSurface(textLayer);
}


//Define classes and other functions here

imageBtn::imageBtn(SDL_Renderer &render, std::string filePath){
    SDL_Surface* surface = IMG_Load(filePath.c_str());
    if (surface == NULL){
        std::cout << "Error Initiating Image Button: " << SDL_GetError() << "\n";
    }
    texture = SDL_CreateTextureFromSurface(&render, surface);
    SDL_FreeSurface(surface);
}

void imageBtn::draw(SDL_Renderer &render, SDL_Rect rect){
    

    if (Events::Left_Click()){
        if ( (rect.x+rect.w > Events::Mouse_Pos().x && Events::Mouse_Pos().x > rect.x) && (rect.y+rect.h > Events::Mouse_Pos().y && Events::Mouse_Pos().y > rect.y) ){
            pressed = true;
        }
    }
    SDL_RenderCopy(&render, texture, NULL, &rect);
}

Form::Form(SDL_Rect position, std::string inActiveMsg){
    state = false;
    inActive = inActiveMsg;
    pos = position;
    std::string input = "";
}

void Form::draw(SDL_Renderer &render, Primitives shapes, Text fontObject){
    shapes.rectangle(render, pos, {49, 79, 79, 255});
    if (state == false){
        if (input.size() == 0){
            fontObject.draw(render, inActive, SDL_Rect{pos.x+10, pos.y+2}, {255, 255, 255, 255});
        } else {
            fontObject.draw(render, input, SDL_Rect{pos.x+10, pos.y+2}, {255, 255, 255, 255});
        }
        
    } else{
        if (input.size() != 0){
            fontObject.draw(render, input, SDL_Rect{pos.x+10, pos.y+2}, {255, 255, 255, 255});
        }
    }

    if ( (pos.x+pos.w > Events::Mouse_Pos().x && Events::Mouse_Pos().x > pos.x) && (pos.y+pos.h > Events::Mouse_Pos().y && Events::Mouse_Pos().y > pos.y) ) {
        if (Events::Left_Click() == true){
            state = true;
        }
    } else {
        if (state == true){
            if (Events::Left_Click() == true){
                state = false;
            }
        }
    }

    if (state == true){
        if (Events::Get_Text_Input() != ""){
            input += Events::Get_Text_Input();
        }

        if (Events::Backspace() == true){
            if (!input.empty()){
                input.pop_back();
            }
        }

        if (Events::Return() == true){
            state = false;
        }
    }
}

void MessageRenderer::draw(SDL_Renderer* render, SDL_Rect pos, std::string msg, std::string title, Text fontObject, Primitives drawObject){
    if (state == true){
        drawObject.rectangle(*render, pos, {240, 240, 240, 255}); // bg
        drawObject.rectangle(*render, SDL_Rect{pos.x, pos.y, pos.w, 25}, {49, 49, 49, 255}); // title bar

        drawObject.rectangle(*render, SDL_Rect{pos.x+(pos.w/2)-30, pos.y+(pos.h-35), 100, 25}, {49, 79, 79, 255}); // ok btn

        fontObject.draw(*render, title, SDL_Rect{pos.x+10,pos.y+4}, SDL_Color{240, 240, 240, 255}); // title
        fontObject.draw(*render, "Ok", SDL_Rect{pos.x+(pos.w/2)+11, pos.y+(pos.h-30)}, SDL_Color{240, 240, 240, 255}); // ok btn

        //Begin logic here
        auto keyPressed = SDL_GetKeyboardState(NULL);
        if (keyPressed[SDL_SCANCODE_RETURN] || keyPressed[SDL_SCANCODE_ESCAPE]){
            state = false;
        }
    }
}
