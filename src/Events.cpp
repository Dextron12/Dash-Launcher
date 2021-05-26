#include "Events.hpp"

Events::Events(){
}

Events& Events::Get_Instance(){
  static Events instance;
  return instance;
}

void Events::Event_Loop(){
  if (Get_Instance().eventLoopCounter == 0){
    Get_Instance().eventLoopCounter += 1;
    while (SDL_PollEvent(&Get_Instance().event) != 0){
      if(Get_Instance().event.type == SDL_QUIT){
          Get_Instance().m_quit = true;
        break;
      }
      if (Get_Instance().event.type == SDL_WINDOWEVENT){
        if(Get_Instance().event.window.event == SDL_WINDOWEVENT_RESIZED){
          Get_Instance().m_Display_Changed_Size = true;
        }
      }

      //Mouse
      if (Get_Instance().event.type == SDL_MOUSEMOTION){
        Get_Instance().m_Mouse_Pos = {Get_Instance().event.motion.x, Get_Instance().event.motion.y};
      }

      if (Get_Instance().event.type == SDL_MOUSEWHEEL){
        if (Get_Instance().event.wheel.y > 0){
          Get_Instance().m_Scrolled_Up = true;
        }
        if (Get_Instance().event.wheel.y < 0){
          Get_Instance().m_Scrolled_Down = true;
        }
      }

      if (Get_Instance().event.type == SDL_MOUSEBUTTONDOWN){
        if (Get_Instance().event.button.button == 1){
          Get_Instance().m_Left_Click = true;
          Get_Instance().m_Left_ClickHold = true;
        }
      }

      if (Get_Instance().event.type == SDL_MOUSEBUTTONUP){
        if (Get_Instance().event.button.button == 1){
          if (Get_Instance().m_Left_ClickHold == true){
            Get_Instance().m_Left_ClickHold = false;
          }
        }
      }

      //Keyboard
      if (Get_Instance().event.type == SDL_TEXTINPUT){
        Get_Instance().m_Text_Input = Get_Instance().event.text.text;
        break; //Break here for multiple key presses to be identified
      }
      if (Get_Instance().event.type == SDL_KEYDOWN){

        if( Get_Instance().event.key.keysym.sym == SDLK_c && SDL_GetModState() & KMOD_CTRL ){
          Get_Instance().m_Copied_Text = true;
        } 
        if( Get_Instance().event.key.keysym.sym == SDLK_v && SDL_GetModState() & KMOD_CTRL ){
          Get_Instance().m_Pasted_Text = true;
        }

        if (Get_Instance().event.key.keysym.sym == SDLK_BACKSPACE){
          Get_Instance().m_Backspace = true;
        }

        if (Get_Instance().event.key.keysym.sym == SDLK_RETURN){
          Get_Instance().m_Return = true;
        }
      }
    }
  }
  else {
    std::cout << "Called Events::Event_Loop(); more then once\n";
  }
}

void Events::Reset_Events(){
  Get_Instance().eventLoopCounter = 0;
  Get_Instance().m_quit = false;
  Get_Instance().m_Display_Changed_Size = false;
  //Mouse
  Get_Instance().m_Scrolled_Down = false;
  Get_Instance().m_Scrolled_Up = false;
  Get_Instance().m_Left_Click = false;
  //KeyBoard
  Get_Instance().m_Text_Input = "";
  Get_Instance().m_Pasted_Text = false;
  Get_Instance().m_Copied_Text = false;
  Get_Instance().m_Backspace = false;
  Get_Instance().m_Return = false;
}

const bool& Events::Quit_Application(){
  return Get_Instance().m_quit;
}
const bool& Events::Display_Changed_Size(){
  return Get_Instance().m_Display_Changed_Size;
}
const SDL_Point& Events::Mouse_Pos(){
  return Get_Instance().m_Mouse_Pos;
}
const bool& Events::Scrolled_Down(){
  return Get_Instance().m_Scrolled_Down;
}
const bool& Events::Scrolled_Up(){
  return Get_Instance().m_Scrolled_Up;
}
const bool& Events::Left_Click(){
  return Get_Instance().m_Left_Click;
}
const bool& Events::Left_ClickHold(){
  return Get_Instance().m_Left_ClickHold;
}
const std::string& Events::Get_Text_Input(){
  return Get_Instance().m_Text_Input;
}
const bool& Events::Pasted_Text(){
  return Get_Instance().m_Pasted_Text;
}
const bool& Events::Copied_Text(){
  return Get_Instance().m_Copied_Text;
}
const bool& Events::Backspace(){
  return Get_Instance().m_Backspace;
}

const bool& Events::Return(){
  return Get_Instance().m_Return;
}