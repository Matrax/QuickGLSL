#include "AppWindow.h"

/**
 * Constructor of the class AppWindow.
 * The constructor initialize the window of the application.
 * It create the menu and the main layout in the window.
 * This constructor also connect all the actions in the main menu bar
 * with lot of actions.
 * @param QWidget* parent The parent widget
 * @author Matrax
 * @version 1.0
 */
AppWindow::AppWindow(QWidget * parent) :
    QMainWindow(parent),
    m_menu(parent),
    m_layout(parent)
{
    //Configure the window
    this->loadStyle();
    this->resize(900, 600);
    this->setMinimumSize(900, 600);
    this->setWindowTitle("QuickQLSL");
    this->setMenuBar(&(this->m_menu));
    this->setCentralWidget(&this->m_centralWidget);
    this->m_centralWidget.setLayout(&this->m_layout);

    //Connect interactions
    connect(this->m_menu.getSaveAction(), &QAction::triggered, this, &AppWindow::save);
    connect(this->m_menu.getRecompileAction(), &QAction::triggered, this, &AppWindow::recompile);
    connect(this->m_menu.getSaveAndRecompileAction(), &QAction::triggered, this, &AppWindow::saveAndRecompile);
    connect(this->m_menu.getQuitAction(), &QAction::triggered, this, &AppWindow::quit);
    connect(this->m_menu.getAboutAction(), &QAction::triggered, this, &AppWindow::about);

    //Show the window
    this->show();

    AppConsole::info("Main window builded");
}

/**
 * Destructor of the AppWindow class.
 * @author Matrax
 * @version 1.0
 */
AppWindow::~AppWindow()
{
    disconnect(this->m_menu.getSaveAction(), &QAction::triggered, this, &AppWindow::save);
    disconnect(this->m_menu.getRecompileAction(), &QAction::triggered, this, &AppWindow::recompile);
    disconnect(this->m_menu.getSaveAndRecompileAction(), &QAction::triggered, this, &AppWindow::saveAndRecompile);
    disconnect(this->m_menu.getQuitAction(), &QAction::triggered, this, &AppWindow::quit);
    disconnect(this->m_menu.getAboutAction(), &QAction::triggered, this, &AppWindow::about);
    this->hide();
}

/**
 * This method load the stylesheet of the application
 * with the file at stylesheets/Main.qss.
 * @author Matrax
 * @version 1.0
 */
void AppWindow::loadStyle()
{
    QFile stylesheet("stylesheets/Main.qss");
    stylesheet.open(QIODevice::ReadOnly | QIODevice::Text);

    if(stylesheet.isOpen() == true)
    {
        QString data = stylesheet.readAll();
        this->setStyleSheet(data);
        AppConsole::info("Stylesheet of the application loaded");
    } else {
        AppConsole::warning("Impossible to open the main stylesheet of the application");
    }

    stylesheet.close();
}

/**
 * This method exit the application.
 * @author Matrax
 * @version 1.0
 */
void AppWindow::quit()
{
    QApplication::quit();
}

/**
 * This method show a window with informations about Qt.
 * @author Matrax
 * @version 1.0
 */
void AppWindow::about()
{
    QApplication::aboutQt();
}

/**
 * This method recompile the vertex and fragment shaders using the files
 * in the shaders folder.
 * @author Matrax
 * @version 1.0
 */
void AppWindow::recompile()
{
    this->m_layout.getContext().unloadTriangleShaders();
    this->m_layout.getContext().loadTriangleShaders("shaders/triangle.vertex", "shaders/triangle.fragment");
}

/**
 * This method save the vertex and fragment shaders in the shaders folder
 * @author Matrax
 * @version 1.0
 */
void AppWindow::save()
{
    this->m_layout.getEditor().saveFileFromEditor(this->m_layout.getEditor().getVertexEditor(), "shaders/triangle.vertex");
    this->m_layout.getEditor().saveFileFromEditor(this->m_layout.getEditor().getFragmentEditor(), "shaders/triangle.fragment");
}

/**
 * This method save and recompile the vertex and fragment shaders
 * @author Matrax
 * @version 1.0
 */
void AppWindow::saveAndRecompile()
{
    this->save();
    this->recompile();
}

/**
 * This method return the main menu bar of the application
 * @return AppMenuBar& The main menu bar of the application
 * @author Matrax
 * @version 1.0
 */
AppMenuBar & AppWindow::getMenuBar()
{
    return this->m_menu;
}

/**
 * This method return the main layout of the application
 * @return AppLayout& The main layout of the application
 * @author Matrax
 * @version 1.0
 */
AppLayout & AppWindow::getLayout()
{
    return this->m_layout;
}
