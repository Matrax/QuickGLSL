#ifndef APPMENUBAR_H
#define APPMENUBAR_H

//Qt includes
#include <QMenu>
#include <QMenuBar>
#include <QApplication>

/**
 * This class create and manage the main menu bar of the application.
 * This menu bar contains action that can save the shaders wrote in the shaders editor,
 * recompile the shader program, see informations about Qt, and quit the application.
 * @brief This class create and manage the main menu bar of the application.
 * @author Matrax
 * @version 1.0
 */
class AppMenuBar : public QMenuBar
{

    private:

        //Attributes
        QMenu * m_fileMenu;
        QMenu * m_helpMenu;
        QAction * m_saveAction;
        QAction * m_recompileAction;
        QAction * m_saveAndRecompileAction;
        QAction * m_quitAction;
        QAction * m_aboutAction;

    public:

        //Constructors and destructor
        AppMenuBar(QWidget * parent = nullptr);
        AppMenuBar(const AppMenuBar &) = delete;
        ~AppMenuBar();

        //Methods
        QMenu * getFileMenu();
        QMenu * getHelpMenu();
        QAction * getSaveAction();
        QAction * getRecompileAction();
        QAction * getSaveAndRecompileAction();
        QAction * getQuitAction();
        QAction * getAboutAction();

};

#endif
