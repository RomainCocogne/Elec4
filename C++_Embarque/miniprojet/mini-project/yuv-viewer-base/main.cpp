//
// header-start
//////////////////////////////////////////////////////////////////////////////////
//
// \file      main.cpp
//
// \brief     This file belongs to the C++ tutorial project
//
// \author    Bernard
//
// \copyright Copyright 2020
//
//////////////////////////////////////////////////////////////////////////////////
// header-end
//
#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);

  a.setOrganizationName("Polytech");
  a.setOrganizationDomain("polytech.unice.fr");
  a.setApplicationName("yuv-viewer");

  MainWindow w;
  w.show();

  return a.exec();
}
