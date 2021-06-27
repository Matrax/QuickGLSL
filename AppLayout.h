#ifndef APPLAYOUT_H
#define APPLAYOUT_H

//Qt includes
#include <QWidget>
#include <QHBoxLayout>
#include <QGridLayout>

//QuickGLSL includes
#include "AppEditor.h"
#include "AppContext.h"
#include "AppConsole.h"

/**
 * This class create and manage the main application layout.
 * This layout contains all the element of the application like
 * the console, the shaders editor and the OpenGL context.
 * @brief This class create and manage the main application layout.
 * @author Matrax
 * @version 1.0
 */
class AppLayout : public QVBoxLayout
{

    private:

        //Attributes
        QHBoxLayout m_horizontalLayout;
        AppConsole m_console;
        AppEditor m_editor;
        AppContext m_context;

    public:

        //Constructors and destructor
        AppLayout(QWidget * parent = nullptr);
        AppLayout(const AppLayout &) = delete;
        ~AppLayout();

        //Methods
        AppConsole & getConsole();
        AppEditor & getEditor();
        AppContext & getContext();

};

#endif
