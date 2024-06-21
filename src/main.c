/*
 * Copyright (C) 2023 Carson Schildt
 * Author: John Doe <tetraos.team@gmail.com>
 * Date: 21-06-2024
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include <stdio.h> 
#include <X11/Xlib.h>
#include "include/event.h"
#include "include/window.h"

int main() {
    Display *display;
    Window root;

    // Open connection to X server
    display = XOpenDisplay(NULL);
    if (display == NULL) {
        fprintf(stderr, "Unable to open X display\n");
        return 1;
    }

    // Get the root window
    root = DefaultRootWindow(display);

    // Set up event masks
    XSelectInput(display, root, SubstructureRedirectMask | SubstructureNotifyMask);

    // Enter the event loop
    event_loop(display, root);

    // Close the display
    XCloseDisplay(display);
    return 0;
}