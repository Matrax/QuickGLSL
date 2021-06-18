#ifndef APPCONTEXT_H
#define APPCONTEXT_H

//Qt includes
#include <QApplication>
#include <QMessageBox>
#include <QWidget>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLBuffer>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLShader>
#include <QOpenGLShaderProgram>
#include <QString>
#include <QTimerEvent>
#include <QFile>

//Std includes
#include <map>
#include <memory>

//QuickGLSL includes
#include "AppConsole.h"

/**
 * This class create and manage the main OpenGL context of the application.
 * This context create default shader to render a scene with black background
 * and one triangle which the user can modify with the default vertex and fragment
 * shader.
 * @brief This class create and manage the main OpenGL context of the application.
 * @author Matrax
 * @version 1.0
 */
class AppContext : public QOpenGLWidget
{

    private:

        //Attributes
        std::map<QString, int> m_uniforms;
        std::unique_ptr<QOpenGLFunctions> m_functions;
        std::unique_ptr<QOpenGLShader> m_vertexShader;
        std::unique_ptr<QOpenGLShader> m_fragmentShader;
        std::unique_ptr<QOpenGLShaderProgram> m_programShader;
        std::unique_ptr<QOpenGLVertexArrayObject> m_vao;
        std::unique_ptr<QOpenGLBuffer> m_vbo;

    protected:

        //Virtual methods overrided
        void initializeGL() override;
        void resizeGL(int width, int height) override;
        void paintGL() override;
        void timerEvent(QTimerEvent * event) override;

    public:

        //Constructors and destructor
        AppContext(QWidget * parent = nullptr);
        AppContext(const AppContext &) = delete;
        virtual ~AppContext();

        //Methods
        void checkOpenGLVersion();
        void loadTriangleBuffers();
        void unloadTriangleShaders();
        void loadTriangleShaders(QString vertex_path, QString fragment_path);
        QString readAllDataFromFile(QString path);
};

#endif
