#include <QApplication>
#include <window.h>

int main(int argc, char **argv)
{
 QApplication app (argc, argv);

 Window window; // my custom widget
 window.show();
 window.reset();

 return app.exec();
}
