#include "AppLayout.h"

/**
 * Constructor of the class AppLayout.
 * The constructor initialize the layouts, the console, the shaders editor
 * and the OpenGL context of the application that will be set in this layout.
 * for the shaders.
 * @param QWidget* parent The parent widget
 * @author Matrax
 * @version 1.0
 */
AppLayout::AppLayout(QWidget * parent) :
    QVBoxLayout(parent),
    m_horizontalLayout(parent),
    m_console(parent),
    m_editor(parent),
    m_context(parent)
{
    //Configure the layout
    this->setSpacing(10);
    this->setContentsMargins(20, 20, 20, 20);
    this->addWidget(&(this->m_context));
    this->m_horizontalLayout.addWidget(&(this->m_console));
    this->m_horizontalLayout.addLayout(&(this->m_editor));
    this->addLayout(&(this->m_horizontalLayout));

    AppConsole::info("Main application layout builded !");
}

/**
 * Destructor of the AppLayout class.
 * This destructor do nothing.
 * @author Matrax
 * @version 1.0
 */
AppLayout::~AppLayout() {}

/**
 * This method return the console of the application
 * @return AppConsole& The console of the application
 * @author Matrax
 * @version 1.0
 */
AppConsole & AppLayout::getConsole()
{
    return this->m_console;
}

/**
 * This method return the editor of the application
 * @return AppEditor& The editor of the application
 * @author Matrax
 * @version 1.0
 */
AppEditor & AppLayout::getEditor()
{
    return this->m_editor;
}

/**
 * This method return the OpenGL context of the application
 * @return AppContext& The OpenGL context of the application
 * @author Matrax
 * @version 1.0
 */
AppContext & AppLayout::getContext()
{
    return this->m_context;
}
