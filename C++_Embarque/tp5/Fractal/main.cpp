/**
*   Description: create a grphic application with a menu
*                you can choose to display 3 differents windows
*                -  TriangleImage
*                -  SplineImage
*                -  FractalImage
*   Authors: Romain Cocogne and Bernard
*   Version: 1.0
*/
#include <QApplication>
#include "./mainwindow.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);

  a.setApplicationName("QT Images");

  MainWindow w;
  w.show();

  return a.exec();
}
