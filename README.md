# QuickGLSL

QuickGLSL is an application using Qt/C++17 to do some test with vertex and fragment shaders.

You can edit vertex and fragment shaders and have a direct result
with a triangle in a OpenGL scene.
QuickGLSL use the last version of OpenGL to do the rendering (OpenGL 4.6), so you can
use all the last functions implemented in GLSL.

![alt QuickGLSL](https://github.com/Matrax/QuickGLSL/blob/main/images/application.png "GLSLViewer")

# Installation

## Windows:
The "window" folder contains an already compiled version for Window 10 of QuickGLSL. (Compiled with MinGW).

## Others
- Generate the makefile using qmake or cmake with Qt.
- Compile the program with make.

# Deployment

## Windows
windeployqt . --release --no-translations --no-system-d3d-compiler --no-compiler-runtime --no-quick-import