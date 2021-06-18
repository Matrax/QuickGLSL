#ifndef APPEDITOR_H
#define APPEDITOR_H

//Qt includes
#include <QWidget>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QComboBox>
#include <QStackedWidget>
#include <QFile>

//QuickGLSL includes
#include "AppConsole.h"

/**
 * This class create and manage the vertex and fragment shader text editor.
 * A QStackedWidget manage the visibility of the two editors.
 * The AppEditor load the content of the vertex and fragment shader from the shaders folder
 * and the user can save the content with the menu bar of the application.
 * @brief This class create and manage the vertex and fragment shader text editor.
 * @author Matrax
 * @version 1.0
 */
class AppEditor : public QVBoxLayout
{
    Q_OBJECT

    private:

        //Attributes
        QStackedWidget m_stack;
        QComboBox m_fileSelector;
        QTextEdit m_vertexEditor;
        QTextEdit m_fragmentEditor;

    public:

        //Constructors and destructor
        AppEditor(QWidget * parent = nullptr);
        AppEditor(const AppEditor &) = delete;
        virtual ~AppEditor();

        //Methods
        void loadFileFromEditor(QTextEdit & editor, QString path);
        void saveFileFromEditor(QTextEdit & editor, QString path);
        QTextEdit & getVertexEditor();
        QTextEdit & getFragmentEditor();
};

#endif
