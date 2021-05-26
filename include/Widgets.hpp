#include "gui.hpp"

#include <SDL2\SDL.h>

class accountWidget{
    /*accountLogon(SDL_Renderer* render, SDL_Rect pos)  // Creates a login apllication. Username and password can be retreived by calling getLogon();
    {
        Primitives primitives;
        std::string _username; std::string _password;
        int logAttempt;
        int state = 0; //0: Logon, 1: Register Account, 2: Reset account, 3: service unavailable
        Form userForm(SDL_Rect{pos.x+10, pos.y+50, pos.w-20, 50}, "Username");
        Form passForm(SDL_Rect{pos.x+10, pos.y+110, pos.w-20, 50}, "Password");
    }*/
    Primitives basicShapes;
    SDL_Renderer* render;
    std::string _username; std::string _password;
    int logAttempt = 0; int state = 0;
    SDL_Rect pos;


    public:
        //Initialize app with constructor
        accountWidget(SDL_Renderer* render, SDL_Rect pos);
        //void functions to access private vars
        //Private vars are private as they proctect the logon details from applications injecting and ejecting data into program
        void failedAttempt(); // Increases failed attempt. If reached three check if suer account exists, if so ask user to reset password
        void resetWidget(); // Resets all forms, logon attempts and stored user data
        void resetAccount(); // Resets a users account | state 2
        void registerAccount(); // Creates register pane | state 1
        void login(); // creates login pane | state 0 ~ default state
        void serviceFailure(); // Draws fail pane, Occurs if login services arent available if server is being used


    
};

class dropdownMenu{};