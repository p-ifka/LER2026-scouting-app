#include "ui.h"
#include "raymob.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void init_ui(ui_ctx *ctx)
{
    ui_style style;

    style.bg = (Color){255, 0, 255, 255};
    style.fg = (Color){255, 255, 255, 255};

    ctx->style = style;
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

void start_draw(ui_ctx *ctx)
{
    BeginDrawing();
    ClearBackground(ctx->style.bg);
}

void end_draw()
{
    EndDrawing();
}



void outline_rect(ui_ctx *ctx, ui_rect *rect)
{
    DrawRectangle(rect->x, rect->y, rect->w, rect->h, ctx->style.fg);
}

ui_layout new_layout(const int slices[], int slices_len, enum ui_plane plane,  ui_rect *parent)
{
    ui_layout ret = {0};
    ui_rect *children;
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
	parent_width = parent->w;
	parent_height = parent->h;
	parent_x = parent->x;
	parent_y = parent->y;
    }

    children = malloc(slices_len * sizeof(ui_rect));
    assert(children && "[error] failed to allocate memory");

    tmp_offset = 0;
    if(plane == X) {
	for(int i=0; i<slices_len; i++) {
	    tmp_size = parent_width * (slices[i] * 0.01f);
	    children[i] = (ui_rect){tmp_offset, parent_y, tmp_size, parent_height};
	    tmp_offset += tmp_size;

	}
    } else {
	for(int i=0; i<slices_len; i++) {
	    tmp_size = parent_height * (slices[i] * 0.1f);
	    children[i] = (ui_rect){parent_x, tmp_offset, parent_width, tmp_size};
	    tmp_offset += tmp_size;
	}
    }


    ret = (ui_layout){children, slices_len};
    return ret;
}


