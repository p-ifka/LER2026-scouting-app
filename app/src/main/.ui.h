#ifndef UI_HEADER_H
#define UI_HEADER_H

#include "raymob.h"

enum ui_plane {
    X, Y
};

typedef struct {
    Color bg;
    Color fg;
} ui_style;

typedef struct {
    int x,y,w,h;
} ui_rect;

typedef struct {
    ui_rect *children;
    int child_count;
} ui_layout;

typedef struct {
    ui_style style;
} ui_ctx;



void init_ui(ui_ctx *);		// initialize ui
int should_close();		// return 1 if app should close, 0 otherwise
void close();			// close app
void start_draw(ui_ctx *);
void end_draw();
void outline_rect(ui_ctx *, ui_rect *);

ui_layout new_layout(const int [], int, enum ui_plane, ui_rect *);		// create new layout from parameters

#endif
