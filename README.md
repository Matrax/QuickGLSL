# QuickGLSL

## Description
QuickGLSL is an application developed with the open source version of Qt and using C++17, that can be used to do some test with vertex and fragment shaders.
You can edit vertex and fragment shaders and have a direct result with a triangle in a OpenGL scene.
QuickGLSL use the last version of OpenGL to do the rendering (OpenGL 4.6 core profile), so you can use all the last functions implemented in GLSL.

## Example
![alt QuickGLSL](https://github.com/Matrax/QuickGLSL/blob/main/images/application.png "GLSLViewer")

# Installation

## Windows:
- The "window" folder contains an already compiled version for Window 10 of QuickGLSL. (Compiled with MinGW). So you can directly go to the deployment section.

## Other OS
- You need to have qmake installed with Qt.
- Generate the makefile using qmake with Qt
- Compile the program with make.

# Deployment

## Windows
windeployqt . --release --no-translations --no-system-d3d-compiler --no-compiler-runtime --no-quick-import

# Shaders

## Predefined uniforms variables

- uniform float random (send to the shader every frame a random number between 0 and 1)
- uniform float smooth_random (send to the shader every frame a smooth random number using interpolation between 0 and 1)
