#include "AppConsole.h"

std::unique_ptr<AppConsole> AppConsole::instance = std::unique_ptr<AppConsole>(nullptr);

/**
 * Constructor of the class AppConsole.
 * The constructor initialize the QScrollArea of the console and the QLabel.
 * It also set the instance of the singleton the first time the object is created.
 * @param QWidget* parent The parent widget
 * @author Matrax
 * @version 1.0
 */
AppConsole::AppConsole(QWidget * parent) :
    QScrollArea(parent),
    m_label("", parent),
    m_output("")
{
    if(AppConsole::instance == nullptr)
    {
        //Configure the console
        this->setMaximumWidth(600);
        this->setMaximumHeight(220);
        this->setWidgetResizable(true);

        //Configure the text
        QFont font("Arial", 10, QFont::DemiBold);
        this->m_label.setMargin(5);
        this->m_label.setFont(font);
        this->m_label.setMaximumHeight(300);
        this->m_label.setTextFormat(Qt::PlainText);
        this->m_label.setAlignment(Qt::AlignLeft);
        this->m_label.setTextInteractionFlags(Qt::TextSelectableByMouse);
        this->setWidget(&(this->m_label));

        AppConsole::instance.reset(this);
        AppConsole::info("Main console builded");
    } else {
        AppConsole::error("You can't have multiple instance of the MainConsole");
    }
}

/**
 * Destructor of the AppConsole class.
 * This destructor do nothing.
 * @author Matrax
 * @version 1.0
 */
AppConsole::~AppConsole() {}

/**
 * This method is called when Qt resize the console
 * @author Matrax
 * @version 1.0
 */
void AppConsole::resizeEvent(QResizeEvent *)
{
    this->m_label.setMaximumWidth(this->width());
}

/**
 * This static function send a message to the console application.
 * @param QString output The message to send
 * @author Matrax
 * @version 1.0
 */
void AppConsole::message(QString output)
{
    QString message;
    message.append(output);
    message.append("\n");
    AppConsole::instance->append(message);
}

/**
 * This static function send an info message to the console application.
 * @param QString output The message to send
 * @author Matrax
 * @version 1.0
 */
void AppConsole::info(QString output)
{
    QString message;
    message.append("[Info] ");
    message.append(output);
    message.append("\n");
    AppConsole::instance->append(message);
}

/**
 * This static function send a warning message to the console application.
 * @param QString output The message to send
 * @author Matrax
 * @version 1.0
 */
void AppConsole::warning(QString output)
{
    QString message;
    message.append("[Warning] ");
    message.append(output);
    message.append("\n");
    AppConsole::instance->append(message);
}

/**
 * This static function send an error message to the console application.
 * @param QString output The message to send
 * @author Matrax
 * @version 1.0
 */
void AppConsole::error(QString output)
{
    QString message;
    message.append("[Error] ");
    message.append(output);
    message.append("\n");
    AppConsole::instance->append(message);
}

/**
 * This method append a text to the QLabel of the console.
 * @param message
 * @author Matrax
 * @version 1.0
 */
void AppConsole::append(QString message)
{
    this->m_output.append(message);
    this->m_label.setText(this->m_output);
}
