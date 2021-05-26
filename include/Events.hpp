#pragma once
#ifndef EVENTS_H
#define EVENTS_h

#include <iostream>
#include <SDL2\SDL.h>
#include <string>

class Events    ///Singleton
{
public:
    Events(const Events&) = delete;
    Events(Events&&) = delete;
    Events& operator=(const Events&) = delete;
    Events& operator=(Events&&) = delete;

    static const bool& Display_Changed_Size();

    //Mouse
    static const SDL_Point& Mouse_Pos();

    static const bool& Scrolled_Down();
    static const bool& Scrolled_Up();

    static const bool& Left_Click();
    static const bool& Left_ClickHold(); // waits for the mouseup event to deactivate

    //Keyboard
    static const std::string& Get_Text_Input();
    static const bool& Pasted_Text();
    static const bool& Copied_Text();

    static const bool& Backspace();
    static const bool& Return();

    static Events& Get_Instance();
private:
    Events();

    //Allow main to access private members
    friend class Apps;

    //handles events
    static void Event_Loop();

    // reset events
    static void Reset_Events();

    //For quiting, used main only
    static const bool& Quit_Application();

    //for event loop
    int eventLoopCounter = 0; // to ensure Event_Loop() isnt repeated twice in same frame
    SDL_Event event;

    bool m_quit = false;

    bool m_Display_Changed_Size = false;

    //Mouse
    SDL_Point m_Mouse_Pos = {0,0};
    bool m_Scrolled_Up = false;
    bool m_Scrolled_Down = false;

    bool m_Left_Click = false;
    bool m_Left_ClickHold = false;

    //Keyboard
    std::string m_Text_Input = "";
    bool m_Copied_Text = false;
    bool m_Pasted_Text = false;
    bool m_Backspace = false;
    bool m_Return = false;
};

#endif