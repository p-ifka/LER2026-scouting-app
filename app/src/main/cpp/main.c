#include "raymob.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

#include <stdbool.h>

int main(void)
{
    int screen_w;
    int screen_h;
    bool running;
    

    InitWindow(0, 0, "scout26");
    SetTargetFPS(15);

    screen_w = GetScreenWidth();
    screen_h = GetScreenHeight();

    running = true;
    while(running) {
	BeginDrawing();

	ClearBackground((Color){0, 0, 0, 255});

	
	EndDrawing();
	
	if(WindowShouldClose()) {
	    running = false;
	}
    }
    

    
    return 0;
}
