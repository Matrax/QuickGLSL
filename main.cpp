//Qt includes
#include <QApplication>
#include <QSurfaceFormat>

//QuickGLSL includes
#include "AppWindow.h"

/**
 * This function configure the default OpenGL surface
 * for the OpenGL context of QuickGLSL.
 * The surface is configured to have vertical synchronalization,
 * 32 bits RGBA color buffer using OpenGL 4.6 core profile.
 * @author Matrax
 * @version 1.0
 */
void setDefaultOpenGLSurface()
{
    QSurfaceFormat format;
    format.setAlphaBufferSize(8);
    format.setRedBufferSize(8);
    format.setGreenBufferSize(8);
    format.setBlueBufferSize(8);
    format.setDepthBufferSize(24);
    format.setStencilBufferSize(8);
    format.setSwapInterval(1);
    format.setVersion(4, 6);
    format.setProfile(QSurfaceFormat::CoreProfile);
    format.setRenderableType(QSurfaceFormat::RenderableType::OpenGL);
    QSurfaceFormat::setDefaultFormat(format);
}

/**
 * Main functions of the application.
 * @param int argc The number of arguments
 * @param int argv The array of arguments
 * @return int The error code
 */
int main(int argc, char *argv[])
{
    setDefaultOpenGLSurface();

    QApplication application(argc, argv);
    AppWindow window(nullptr);

    return application.exec();
}
