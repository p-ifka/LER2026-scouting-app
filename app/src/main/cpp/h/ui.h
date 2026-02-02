#ifndef UI_HEADER_H
#define UI_HEADER_H

#include "raymob.h"

// const Color ui_colors[] = {
//     (Color){0, 0, 0, 255},	// 0:BACKGROUND
//     (Color){255, 0, 0, 255},	// 1:RED
//     (Color){0, 255, 0, 255},	// 2:GREEN
//     (Color){255, 255, 0, 255}, 	// 3:YELLOW
//     (Color){0, 0, 255, 255},	// 4:BLUE
//     (Color){255, 0, 255, 255},	// 5:MAGENTA
//     (Color){0, 255, 255, 255},	// 6:AQUA
//     (Color){255, 255, 255, 255}	// 7:WHITE
// };


enum ui_plane {
    X, Y
};

typedef struct {
    Rectangle *children;
    int child_count;
} ui_layout;


void init_ui();		// initialize ui
int should_close();		// return 1 if app should close, 0 otherwise
void close();			// close app
void start_draw();
void end_draw();
void outline_rect(Rectangle *);

ui_layout new_layout(const int [], int, enum ui_plane, Rectangle *);		// create new layout from parameters

#endif
