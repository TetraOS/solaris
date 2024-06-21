#include <X11/Xlib.h>
#include "include/event.h"
#include "include/window.h"

void event_loop(Display *display, Window root) {
    XEvent event;
    while (1) {
        XNextEvent(display, &event);
        switch (event.type) {
            case CreateNotify:
                handle_create_event(display, &event.xcreatewindow);
                break;
            case DestroyNotify:
                handle_destroy_event(display, &event.xdestroywindow);
                break;
            // Add more event handlers as needed
        }
    }
}
