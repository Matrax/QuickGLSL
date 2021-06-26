#include "AppContext.h"

/**
 * Constructor of the class AppContext.
 * The constructor initialize the QOpenGLWidget and the noise.
 * @param QWidget* parent The parent widget
 * @author Matrax
 * @version 1.0
 */
AppContext::AppContext(QWidget * parent) :
      QOpenGLWidget(parent),
      m_functions(nullptr),
      m_vertexShader(nullptr),
      m_fragmentShader(nullptr),
      m_programShader(nullptr),
      m_vao(nullptr),
      m_vbo(nullptr),
      m_randomGenerator(50)
{
    //Configure the OpenGL context
    this->setMinimumHeight(400);
    this->setCursor(Qt::CrossCursor);

    AppConsole::info("Main OpenGL panel builded !");
}

/**
 * Destructor of the AppContext class.
 * This destructor destroy the triangle VAO and the triangle VBO.
 * It also destroy the current OpenGL context.
 * @author Matrax
 * @version 1.0
 */
AppContext::~AppContext()
{
    this->m_vao->destroy();
    this->m_vbo->destroy();
    this->doneCurrent();
}

/**
 * This method check the OpenGL version used by the graphics
 * card, and if it's not the version 4.6, the application show a
 * message box and exit.
 * @author Matrax
 * @version 1.0
 */
void AppContext::checkOpenGLVersion()
{
    int majorVersion = 0;
    int minorVersion = 0;

    this->m_functions->glGetIntegerv(GL_MAJOR_VERSION, &majorVersion);
    this->m_functions->glGetIntegerv(GL_MINOR_VERSION, &minorVersion);

    if(majorVersion == 4 && minorVersion == 6)
    {
        QString output;
        output.append("OpenGL Version: ");
        output.append((const char *) this->m_functions->glGetString(GL_VERSION));
        AppConsole::info(output);
    } else {
        QMessageBox box;
        box.setText("Your graphics card doesn't support OpenGL 4.6");
        QString message("Your graphics card only support OpenGL ");
        message.append(QChar(majorVersion));
        message.append(".");
        message.append(QChar(minorVersion));
        message.append(".\nYou can update your graphic card driver or change your graphics card");
        box.setInformativeText(message);
        box.exec();
        std::exit(1);
    }
}

/**
 * This method is called when Qt initialize the OpenGL context.
 * @author Matrax
 * @version 1.0
 */
void AppContext::initializeGL()
{
    //Load OpenGL functions
    this->m_functions = std::unique_ptr<QOpenGLFunctions>(this->context()->functions());
    this->m_functions->initializeOpenGLFunctions();
    this->checkOpenGLVersion();

    //Clear buffers values
    this->m_functions->glClearColor(0, 0, 0, 1);
    this->m_functions->glClearDepthf(1.0f);
    this->m_functions->glClearStencil(0);

    //Load shaders and triangle
    this->loadTriangleBuffers();
    this->loadTriangleShaders("shaders/triangle.vertex", "shaders/triangle.fragment");

    //Set timer event
    this->startTimer(16, Qt::CoarseTimer);
}

/**
 * This method is called when Qt resize the OpenGL context.
 * @param int width The width of the new size
 * @param int height The height of the new size
 * @author Matrax
 * @version 1.0
 */
void AppContext::resizeGL(int width, int height)
{
    this->m_functions->glViewport(0, 0, width, height);
}

/**
 * This method is called when Qt repaint the OpenGL context.
 * @author Matrax
 * @version 1.0
 */
void AppContext::paintGL()
{
    this->m_programShader->bind();
    this->m_vao->bind();
    this->m_programShader->setUniformValue(this->m_uniforms["random"], static_cast<float>(std::rand()) / static_cast<float>(RAND_MAX));
    this->m_programShader->setUniformValue(this->m_uniforms["smooth_random"], this->m_randomGenerator.random());
    this->m_functions->glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
    this->m_functions->glDrawArrays(GL_TRIANGLES, 0, 3);
    this->m_vao->release();
    this->m_programShader->release();
}

/**
 * This method is called by Qt every 16 milliseconds.
 * @author Matrax
 * @version 1.0
 */
void AppContext::timerEvent(QTimerEvent *)
{
    this->repaint();
}

/**
 * This method read all the data from a file.
 * @param path The path of the file
 * @return The data readed from the file.
 * @author Matrax
 * @version 1.0
 */
QString AppContext::readAllDataFromFile(QString path)
{
    QFile file(path);
    QString source;
    file.open(QIODevice::ReadOnly | QIODevice::Text);

    if(file.isOpen() == true)
    {
        source = file.readAll();
        file.close();
    } else {
        QString message("Error on opening the file ");
        message.append(path);
        AppConsole::error(message);
    }

    return source;
}

/**
 * This method load the vertex and the fragment shaders
 * of the triangle.
 * @brief AppContext::loadTriangleShaders
 * @param vertex_path
 * @param fragment_path
 */
void AppContext::loadTriangleShaders(QString vertex_path, QString fragment_path)
{
    //Create vertex, fragment and program shader
    this->m_vertexShader = std::make_unique<QOpenGLShader>(QOpenGLShader::Vertex);
    this->m_fragmentShader = std::make_unique<QOpenGLShader>(QOpenGLShader::Fragment);
    this->m_programShader = std::make_unique<QOpenGLShaderProgram>();

    //Compile vertex shader
    QString vertex_source = this->readAllDataFromFile(vertex_path);
    this->m_vertexShader->compileSourceCode(vertex_source);

    if(this->m_vertexShader->isCompiled() == true)
    {
        AppConsole::info("Vertex shader compiled !");
    } else {
        AppConsole::error("Error on compiling the vertex shader");
        AppConsole::message("==============Vertex===============\n");
        AppConsole::message(this->m_vertexShader->log());
        AppConsole::message("===================================");
    }

    //Compile fragment shader
    QString fragment_source = this->readAllDataFromFile(fragment_path);
    this->m_fragmentShader->compileSourceCode(fragment_source);

    if(this->m_fragmentShader->isCompiled() == true)
    {
        AppConsole::info("Fragment shader compiled !");
    } else {
        AppConsole::error("Error on compiling the fragment shader");
        AppConsole::message("===============Fragment==============\n");
        AppConsole::message(this->m_fragmentShader->log());
        AppConsole::message("=====================================");
    }

    //Linking vertex and fragment shader
    this->m_programShader->create();
    this->m_programShader->addShader(this->m_vertexShader.get());
    this->m_programShader->addShader(this->m_fragmentShader.get());
    this->m_programShader->link();

    if(this->m_programShader->isLinked() == true)
    {
        this->m_uniforms["random"] = this->m_programShader->uniformLocation("random");
        this->m_uniforms["smooth_random"] = this->m_programShader->uniformLocation("smooth_random");
        AppConsole::info("Program shader linked !");
    } else {
        AppConsole::error("Error on linking the shader program");
        AppConsole::message("===============Program===============\n");
        AppConsole::message(this->m_programShader->log());
        AppConsole::message("=====================================");
    }

}

/**
 * This method unload the vertex and the fragment shaders
 * of the triangle.
 * @author Matrax
 * @version 1.0
 */
void AppContext::unloadTriangleShaders()
{
    if(this->m_programShader.get() != nullptr)
    {
        this->m_vertexShader.release();
        this->m_fragmentShader.release();
        this->m_programShader.release();
        AppConsole::info("Actual shader program destroyed");
    }
}

/**
 * This method load the VAO and the VBO of the triangle.
 * @author Matrax
 * @version 1.0
 */
void AppContext::loadTriangleBuffers()
{
    //Create VAO and VBO
    this->m_vao = std::make_unique<QOpenGLVertexArrayObject>();
    this->m_vao->create();

    if(this->m_vao->isCreated() == true)
    {
        this->m_vbo = std::make_unique<QOpenGLBuffer>(QOpenGLBuffer::VertexBuffer);
        this->m_vbo->create();

        if(this->m_vbo->isCreated() == true)
        {
            //Allocate VBO
            float data[] = { 0.5, -0.5, 0,
                             0, 0.5, 0,
                             -0.5, -0.5, 0
                           };
            this->m_vao->bind();
            this->m_vbo->bind();
            this->m_vbo->allocate(&data, 3 * 3 * sizeof(float));
            this->m_functions->glEnableVertexAttribArray(0);
            this->m_functions->glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
            this->m_vao->release();
        } else {
            AppConsole::error("Error on the creation of the triangle VBO");
        }

    } else {
        AppConsole::error("Error on the creation of the triangle VAO");
    }
}
