#include <QApplication>
#include <QLabel>
#include <QWidget>
 
int main(int argc, char *argv[ ])
{
 
QApplication app(argc, argv);
QLabel hola("<center>Hello, world</center>");
hola.setWindowTitle("First program");
hola.resize(600, 400);
hola.show();
return app.exec();
 
}
