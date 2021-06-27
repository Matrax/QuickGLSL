#ifndef APPWINDOW_H
#define APPWINDOW_H

//Qt includes
#include <QMainWindow>
#include <QString>
#include <QKeyEvent>

//QuickGLSL includes
#include "AppConsole.h"
#include "AppLayout.h"
#include "AppMenuBar.h"

/**
 * This class create and manage the window of the application.
 * The window contains all the widget of the application redesigned with a Qt stylesheet
 * in the stylesheets folder.
 * @brief This class create and manage the window of the application.
 * @author Matrax
 * @version 1.0
 */
class AppWindow : public QMainWindow
{
    Q_OBJECT

    private:

        //Attributes
        QWidget m_centralWidget;
        AppMenuBar m_menu;
        AppLayout m_layout;

    public:

        //Constructors and destructor
        AppWindow(QWidget *parent = nullptr);
        AppWindow(const AppWindow &) = delete;
        ~AppWindow();

        //Methods
        void loadStyle();
        AppMenuBar & getMenuBar();
        AppLayout & getLayout();

    public slots:

        //Slots
        void quit();
        void about();
        void save();
        void recompile();
        void saveAndRecompile();

};

#endif
