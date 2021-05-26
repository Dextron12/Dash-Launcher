//Dash Launcher 2021, Created and Maintained by Dextron12
//Dash launcher is an online client side launcher that handles all Dextron12 games, applications and services
//Requries Internet to login/create account, Store and account pages require Internet. All applications are downlaoded locally if owned by the user

//All headers are property of Dextron12
//No liability for application or service failure is accepted

#include "commons.hpp" //Includes all libraries and global variables
#include "Events.hpp" //Includes events application
#include "Widgets.hpp" //Includes all widgets, needed to create account widgets and menus whcih depends on gui

class Apps{
    Primitives basicShapes;
    

    public:


        void Login(){
            accountWidget accountApp(render, SDL_Rect{20,80,80,60});
            while(appRunning){
                Events::Event_Loop();
                SDL_SetRenderDrawColor(render, 175, 175, 175, 255);
                SDL_RenderClear(render);
                //Check events here
                if (Events::Quit_Application()){
                    appRunning = false;
                }
                if (Events::Display_Changed_Size()){
                    width = SDL_GetWindowSurface(window)->w;
                    height = SDL_GetWindowSurface(window)->h;
                }
                //Draw Here
                basicShapes.rectangle(*render, SDL_Rect{0,height-30,width,30}, {70, 130, 180, 0});
                accountApp.login();


                //Logic Here

                SDL_RenderPresent(render);
                Events::Reset_Events();

            }
        }

        void init(){
            if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
                std::cout << "Failed to initailize SDL2.\n";
                errorCode = -1;
            }
            window = SDL_CreateWindow("Dash", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_RESIZABLE);
            render = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
            Login();
        }
    
};

int main(int argc, char* argv[]){
    Apps app;
    app.init();

    return errorCode;
}


