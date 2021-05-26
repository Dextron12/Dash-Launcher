SRC = $(wildcard src/*.cpp)
INC = -IC:\Programming\C++\Dash\include -IC:\Programming\C++\Dash\Libs\SDL2\include -LC:\Programming\C++\Dash\Libs\SDL2\lib
ARG = -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf
OUT = dash

$(OUT).exe: $(SRC)
	g++ $(SRC) $(INC) $(ARG) $(LIB)  -o $(OUT)
	dash.exe