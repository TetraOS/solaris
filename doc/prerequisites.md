# Solaris Project Prerequisites

The Solaris project, the window manager shipped with the Cosmos Desktop Environment, requires the following prerequisites:

## Prerequisites Overview

- **GTK (GTKmm)**: C++ interface for GTK used in the Solaris project
- **Xlib**: Library for communication with the X server

## Installation Guides

### GTK (GTKmm)

**Linux:**
- Ubuntu/Debian: `sudo apt-get install libgtkmm-3.0-dev`
- Fedora: `sudo dnf install gtkmm30-devel`
- Arch Linux: `sudo pacman -S gtkmm`

**macOS:**
- Install GTKmm using Homebrew: `brew install gtkmm3`

**Windows:**
- Follow the instructions on the GTKmm website for Windows installation.

### Xlib

**Linux:**
- Ubuntu/Debian: `sudo apt-get install libx11-dev`
- Fedora: `sudo dnf install libX11-devel`
- Arch Linux: `sudo pacman -S libx11`
