#include "AppEditor.h"

/**
 * Constructor of the class AppEditor.
 * The constructor initialize the QComboBox and the two QTextEdit
 * for the shaders.
 * @param QWidget* parent The parent widget
 * @author Matrax
 * @version 1.0
 */
AppEditor::AppEditor(QWidget * parent) :
    QVBoxLayout(parent)
{
    //File selector
    this->m_fileSelector.setMaximumHeight(20);
    this->m_fileSelector.addItem(tr("Triangle - Vertex Shader"));
    this->m_fileSelector.addItem(tr("Triangle - Fragment Shader"));
    this->addWidget(&(this->m_fileSelector));

    //Widgets stack
    this->m_stack.setMaximumHeight(200);
    this->m_stack.addWidget(&(this->m_vertexEditor));
    this->m_stack.addWidget(&(this->m_fragmentEditor));
    this->addWidget(&(this->m_stack));

    //Vertex shader editor
    this->m_vertexEditor.setTabStopDistance(20);
    this->m_vertexEditor.setAcceptRichText(false);
    this->m_vertexEditor.setAcceptDrops(false);
    this->m_vertexEditor.setTextInteractionFlags(Qt::TextSelectableByMouse | Qt::TextSelectableByKeyboard | Qt::TextEditable);
    this->m_vertexEditor.setPlaceholderText("Write the vertex shader here...");
    this->loadFileFromEditor(this->m_vertexEditor, "shaders/triangle.vertex");

    //Fragment shader editor
    this->m_fragmentEditor.setTabStopDistance(20);
    this->m_fragmentEditor.setAcceptRichText(false);
    this->m_fragmentEditor.setAcceptDrops(false);
    this->m_fragmentEditor.setTextInteractionFlags(Qt::TextSelectableByMouse | Qt::TextSelectableByKeyboard | Qt::TextEditable);
    this->m_fragmentEditor.setPlaceholderText("Write the fragment shader here...");
    this->loadFileFromEditor(this->m_fragmentEditor, "shaders/triangle.fragment");

    //Connect interactions
    connect(&(this->m_fileSelector), &QComboBox::activated, &(this->m_stack), &QStackedWidget::setCurrentIndex);

    AppConsole::info("Main shader editor builded !");
}

/**
 * Destructor of the AppEditor class.
 * This destructor do nothing.
 * @author Matrax
 * @version 1.0
 */
AppEditor::~AppEditor() {}

/**
 * This method load from a file the text to set in a QTextEdit.
 * @param editor The QTextEdit to set the text
 * @param path The file path
 * @author Matrax
 * @version 1.0
 */
void AppEditor::loadFileFromEditor(QTextEdit & editor, QString path)
{
    QFile file(path);
    file.open(QIODevice::ReadOnly | QIODevice::Text);

    if(file.isOpen() == true)
    {
        QString data = file.readAll();
        editor.setText(data);
        file.close();
    } else {
        QString error("Error on load the file ");
        error.append(path);
        AppConsole::error(error);
    }
}

/**
 * This method save in a file the text from a QTextEdit.
 * @param editor The QTextEdit to set the text
 * @param path The file path
 * @author Matrax
 * @version 1.0
 */
void AppEditor::saveFileFromEditor(QTextEdit & editor, QString path)
{
    QFile file(path);
    file.open(QIODevice::WriteOnly | QIODevice::Text);

    if(file.isOpen() == true)
    {
        QString data = editor.toPlainText();
        file.write(data.toLocal8Bit());
        QString message("File ");
        message.append(path);
        message.append(" saved !");
        file.close();
        AppConsole::info(message);
    } else {
        QString error("Error on save the file ");
        error.append(path);
        AppConsole::error(error);
    }
}

/**
 * This method return the vertex editor of the application
 * @return QTextEdit& The vertex editor of the application
 * @author Matrax
 * @version 1.0
 */
QTextEdit & AppEditor::getVertexEditor()
{
    return this->m_vertexEditor;
}

/**
 * This method return the fragment editor of the application
 * @return QTextEdit& The fragment editor of the application
 * @author Matrax
 * @version 1.0
 */
QTextEdit & AppEditor::getFragmentEditor()
{
    return this->m_fragmentEditor;
}
