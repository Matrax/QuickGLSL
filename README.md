# QuickGLSL

## Description
QuickGLSL is an application developed with the open source version of Qt and using C++17, that can be used to do some test with vertex and fragment shaders.
You can edit vertex and fragment shaders and have a direct result with a triangle in a OpenGL scene.
QuickGLSL use the last version of OpenGL to do the rendering (OpenGL 4.6 core profile), so you can use all the last functions implemented in GLSL.

## Example
![alt QuickGLSL](https://github.com/Matrax/QuickGLSL/blob/main/images/application.png "GLSLViewer")

## Installation
- The "window" folder contains an already compiled version for Window 10 of QuickGLSL (compiled with MinGW). You can directly go to the deployment section.
- If you have another OS, compile QuickGLSL with QMake. 

## Deployment
OS | Commands
------------ | -------------
Windows | windeployqt . --release --no-translations --no-system-d3d-compiler --no-compiler-runtime --no-quick-import
Debian | (Not tested yet)

## Predefined uniforms variables
Variables | Uses
------------ | -------------
uniform float random | Send every frame to the shaders a random number between 0 and 1.
uniform float smooth_random | Send every frame to the shaders a smooth random number using interpolation between 0 and 1.