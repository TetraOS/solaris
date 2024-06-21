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