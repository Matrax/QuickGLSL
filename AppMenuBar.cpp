#include "AppMenuBar.h"

/**
 * Constructor of the class AppMenuBar.
 * The constructor initialize the main menu of the application
 * with the file and help menu and all their "actions".
 * @param QWidget* parent The parent widget
 * @author Matrax
 * @version 1.0
 */
AppMenuBar::AppMenuBar(QWidget * parent) :
    QMenuBar(parent),
    m_fileMenu(nullptr),
    m_helpMenu(nullptr),
    m_saveAction(nullptr),
    m_recompileAction(nullptr),
    m_saveAndRecompileAction(nullptr),
    m_quitAction(nullptr),
    m_aboutAction(nullptr)
{
    //File menu
    this->m_fileMenu = this->addMenu(tr("&File"));
    this->m_saveAction = this->m_fileMenu->addAction(tr("&Save"));
    this->m_recompileAction = this->m_fileMenu->addAction(tr("&Recompile"));
    this->m_saveAndRecompileAction = this->m_fileMenu->addAction(tr("&Save and recompile"));
    this->m_quitAction = this->m_fileMenu->addAction(tr("&Quit"));

    //Help menu
    this->m_helpMenu = this->addMenu(tr("&Help"));
    this->m_aboutAction = this->m_helpMenu->addAction(tr("&About Qt"));
}

/**
 * Destructor of the AppMenuBar class.
 * This destructor do nothing.
 * @author Matrax
 * @version 1.0
 */
AppMenuBar::~AppMenuBar() {}

/**
 * This method return the pointer to the file menu.
 * @return QMenu* the pointer to the file menu.
 * @author Matrax
 * @version 1.0
 */
QMenu * AppMenuBar::getFileMenu()
{
    return this->m_fileMenu;
}

/**
 * This method return the pointer to the help menu.
 * @return QMenu* the pointer to the help menu.
 * @author Matrax
 * @version 1.0
 */
QMenu * AppMenuBar::getHelpMenu()
{
    return this->m_helpMenu;
}

/**
 * This method return the pointer to the "save" action.
 * @return QAction* the pointer to the "save" action.
 * @author Matrax
 * @version 1.0
 */
QAction * AppMenuBar::getSaveAction()
{
    return this->m_saveAction;
}

/**
 * This method return the pointer to the "recompile" action.
 * @return QAction* the pointer to the "recompile" action.
 * @author Matrax
 * @version 1.0
 */
QAction * AppMenuBar::getRecompileAction()
{
    return this->m_recompileAction;
}

/**
 * This method return the pointer to the "save and recompile" action.
 * @return QAction* the pointer to the "save and recompile" action.
 * @author Matrax
 * @version 1.0
 */
QAction * AppMenuBar::getSaveAndRecompileAction()
{
    return this->m_saveAndRecompileAction;
}

/**
 * This method return the pointer to the "quit" action.
 * @return QAction* the pointer to the "quit" action.
 * @author Matrax
 * @version 1.0
 */
QAction * AppMenuBar::getQuitAction()
{
    return this->m_quitAction;
}

/**
 * This method return the pointer to the "about" action.
 * @return QAction* the pointer to the "about" action.
 * @author Matrax
 * @version 1.0
 */
QAction * AppMenuBar::getAboutAction()
{
    return this->m_aboutAction;
}
