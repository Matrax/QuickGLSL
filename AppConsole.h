#ifndef APPCONSOLE_H
#define APPCONSOLE_H

//Qt includes
#include <QScrollArea>
#include <QScrollBar>
#include <QWidget>
#include <QLabel>

//Std includes
#include <memory>

/**
 * This class create and manage the console of the application.
 * This class is also a singleton, so you can't have multiple instance of a AppConsole
 * in the application at the same time.
 * You can't get the instance if the AppConsole because the singleton is only used in private
 * to send messages to the console with public static functions like info(), warning() or error().
 * These static functions can show message in the console of ShaderViewer.
 * @brief This class create and manage the console of the application
 * @author Matrax
 * @version 1.0
 */
class AppConsole : public QScrollArea
{

    private:

        //Static
        static std::unique_ptr<AppConsole> instance;

        //Attributes
        QLabel m_label;
        QString m_output;

    protected:

        //Events
        void resizeEvent(QResizeEvent * event) override;

    public:

        //Constructors and destructor
        AppConsole(QWidget * parent = nullptr);
        AppConsole(const AppConsole &) = delete;
        ~AppConsole();

        //Static functions
        static void message(QString output);
        static void info(QString output);
        static void warning(QString output);
        static void error(QString output);

        //Methods
        void append(QString message);

};

#endif
