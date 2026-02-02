#include "ui.h"
#include "raymob.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void init_ui()
{
    InitWindow(0, 0, "scout26");
    SetTargetFPS(30);
}

int should_close()
{
    return WindowShouldClose();
}

void close()
{
    CloseWindow();
}

void start_draw()
{
    BeginDrawing();
    ClearBackground((Color){0, 0, 0, 255});
}

void end_draw()
{
    EndDrawing();
}



void outline_rect(Rectangle *rect)
{
    DrawRectangleLines(rect->x, rect->y, rect->width, rect->height, (Color){255, 255, 255, 255});
}

ui_layout new_layout(const int slices[], int slices_len, enum ui_plane plane, Rectangle *parent)
{
    ui_layout ret = {0};
    Rectangle *children;
    int sum;
    int parent_width;
    int parent_height;
    int parent_x;
    int parent_y;
    int tmp_offset, tmp_size;

    sum = 0;
    for(int i=0; i<slices_len; i++) {
	sum += slices[i];
    }
    assert(sum == 100 && "[error] invalid slices: sum must = 100");

    if(parent == NULL) {
	parent_width = GetScreenWidth();
	parent_height = GetScreenHeight();
	parent_x = 0;
	parent_y = 0;
    } else {
	parent_width = parent->width;
	parent_height = parent->height;
	parent_x = parent->x;
	parent_y = parent->y;
    }

    children = malloc(slices_len * sizeof(Rectangle));
    assert(children && "[error] failed to allocate memory");

    tmp_offset = 0;
    if(plane == X) {
	for(int i=0; i<slices_len; i++) {
	    tmp_size = parent_width * (slices[i] * 0.01f);
	    children[i] = (Rectangle){tmp_offset, parent_y, tmp_size, parent_height};
	    tmp_offset += tmp_size;

	}
    } else {
	for(int i=0; i<slices_len; i++) {
	    tmp_size = parent_height * (slices[i] * 0.1f);
	    children[i] = (Rectangle){parent_x, tmp_offset, parent_width, tmp_size};
	    tmp_offset += tmp_size;
	}
    }


    ret = (ui_layout){children, slices_len};
    return ret;
}


