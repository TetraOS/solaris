/*
 * Copyright (c) 2024 The Tetra Foundation
 * Author: Carson Schildt
 *
 * # window.h
 * 
 * `window.h` declares the Window class, facilitating X11 window management in a graphical application by providing methods for creating, manipulating, and handling window    
 * events. It serves as the interface for utilizing window functionalities and defines the contract for interacting with X11 windows within the program.
 */

#ifndef WINDOW_H
#define WINDOW_H

#include <X11/Xlib.h> // Include X11 library for window management
#include <string>     // Include string library for window title

// Forward declaration of ResizeListener class
class ResizeListener;

// Window class declaration
class Window {
public:
    // Constructor: Initializes a window with the given display connection and window ID
    Window(Display* display, WindowID windowId);

    // Destructor: Cleans up resources associated with the window
    ~Window();

    // Method to retrieve the window title
    std::string GetWindowTitle() const;

    // Method to set the window title
    void SetWindowTitle(const std::string& title);

    // Method to retrieve the window size
    void GetWindowSize(int& width, int& height) const;

    // Method to set the window size
    void SetWindowSize(int width, int height);

    // Method to handle window events
    void HandleEvents();

    // Method to add a resize listener
    void AddResizeListener(ResizeListener* listener);

    // Method to remove a resize listener
    void RemoveResizeListener(ResizeListener* listener);

    // Method to run the window event loop
    void Run();

private:
    // Display connection associated with the window
    Display* display;

    // ID of the window
    WindowID windowId;

    // Width and height of the window
    int width;
    int height;

    // Title of the window
    std::string title;

    // List of resize listeners
    std::list<ResizeListener*> resizeListeners;

    // Private method to handle window resize events
    void HandleResizeEvent(int width, int height);

    // Private method to notify resize listeners
    void NotifyResizeListeners(int width, int height);
};

#endif /* WINDOW_H */
