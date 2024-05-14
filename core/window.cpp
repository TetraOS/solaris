/*
 * Copyright (c) 2024 The Tetra Foundation
 * Author: Carson Schildt
 *
 * #window.cpp
 *
 * window.cpp implements the Window class, providing functionalities for managing X11 windows in a graphical application, including window creation, event handling, and error 
 * checking. It facilitates window management tasks and allows for easy integration of X11 windows into applications while ensuring robustness through error handling
 *
 */

#include "window.h"

// Constructor
Window::Window(Display* display, WindowID windowId) : display(display), windowId(windowId) {
    // Ensure display and window ID are valid
    if (!display || windowId == 0) {
        // Print error message to stderr
        std::cerr << "Error: Invalid display or window ID!" << std::endl;
        // Exit with failure status
        exit(EXIT_FAILURE);
    }
    
    // Initialize window attributes
    XWindowAttributes windowAttributes;
    // Retrieve window attributes from X11 server
    Status status = XGetWindowAttributes(display, windowId, &windowAttributes);
    if (status == 0) {
        // Print error message to stderr
        std::cerr << "Error: Failed to retrieve window attributes!" << std::endl;
        // Exit with failure status
        exit(EXIT_FAILURE);
    }
    // Extract window width and height
    this->width = windowAttributes.width;
    this->height = windowAttributes.height;
    // Extract window title
    this->title = GetWindowTitle();
}

// Destructor
Window::~Window() {
    // No cleanup needed
}

// Method to retrieve window title
std::string Window::GetWindowTitle() const {
    // Retrieve window title from X11 server
    char* windowTitle = nullptr;
    // Fetch window title
    XFetchName(display, windowId, &windowTitle);
    // Convert C-style string to C++ string
    std::string title = (windowTitle != nullptr) ? std::string(windowTitle) : "";
    // Free allocated memory for window title
    XFree(windowTitle);
    // Return window title
    return title;
}

// Method to set window title
void Window::SetWindowTitle(const std::string& title) {
    // Set window title using X11 functions
    XStoreName(display, windowId, title.c_str());
}

// Method to retrieve window size
void Window::GetWindowSize(int& width, int& height) const {
    // Return window size
    width = this->width;
    height = this->height;
}

// Method to set window size
void Window::SetWindowSize(int width, int height) {
    // Resize window using X11 functions
    XResizeWindow(display, windowId, width, height);
}

// Method to handle window events
void Window::HandleEvents() {
    XEvent event;

    // Poll for events
    while (XCheckWindowEvent(display, windowId, ~0, &event)) {
        switch (event.type) {
            case ConfigureNotify:
                // Handle window resize event
                HandleResizeEvent(event.xconfigure.width, event.xconfigure.height);
                break;
            // Add cases to handle other window events as needed
            default:
                // Ignore unsupported event types
                break;
        }
    }
}

// Method to handle window resize events
void Window::HandleResizeEvent(int width, int height) {
    // Update window size
    this->width = width;
    this->height = height;

    // Notify resize listeners about the resize event
    NotifyResizeListeners(width, height);
}

// Method to add a resize listener
void Window::AddResizeListener(ResizeListener* listener) {
    // Add resize listener to the list
    resizeListeners.push_back(listener);
}

// Method to remove a resize listener
void Window::RemoveResizeListener(ResizeListener* listener) {
    // Remove resize listener from the list
    resizeListeners.remove(listener);
}

// Method to notify resize listeners
void Window::NotifyResizeListeners(int width, int height) {
    // Iterate through all resize listeners
    for (auto listener : resizeListeners) {
        // Notify each listener about the resize event
        listener->OnResize(width, height);
    }
}

// Method to run the window event loop
void Window::Run() {
    // Main event loop
    while (true) {
        // Handle window events
        HandleEvents();

        // Other processing can be done here
    }
}
