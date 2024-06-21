#ifndef WINDOW_H
#define WINDOW_H

#include <X11/Xlib.h>

void handle_create_event(Display *display, XCreateWindowEvent *event);
void handle_destroy_event(Display *display, XDestroyWindowEvent *event);

#endif // WINDOW_H
