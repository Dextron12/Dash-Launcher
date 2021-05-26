#include "Widgets.hpp"

#include <iostream>

accountWidget::accountWidget(SDL_Renderer* render, SDL_Rect pos){
    Form userForm(SDL_Rect{pos.x+10, pos.y+50, pos.w-20, 50}, "Username");
    Form passForm(SDL_Rect{pos.x+10,pos.y+110,pos.w-20,50}, "Password");

    render = render;
    pos = pos;
    std::cout << "Reached app constructor.\n";
}

void accountWidget::failedAttempt(){
    if (logAttempt < 3){
        logAttempt += 1;
    } else {
        logAttempt = -1;
    }
}

void accountWidget::login(){
    //Draws a white widget background
    basicShapes.rectangle(*render, pos, {0,0,0,255});
    std::cout << "Running login script...\n";


}
