// Copyright none
#include "mainwindow.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <QtWidgets>


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
  //
  // construct image_widget

  image_widget_ = new QLabel;
  image_widget_->setBackgroundRole(QPalette::Base);
  image_widget_->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
  image_widget_->setScaledContents(true);
  image_widget_->setMinimumSize(600, 600);

  create_actions();
  create_menus();

  setCentralWidget(image_widget_);
  resize(QGuiApplication::primaryScreen()->availableSize() * 2 / 5);
}


void MainWindow::create_actions() {
  //
  action_checker_board_image_ = new QAction(tr("Checker Board Image"), this);
  connect(action_checker_board_image_, SIGNAL(triggered()),
          this, SLOT(slot_load_checker_board_image()));

  action_exit_ = new QAction(tr("E&xit"), this);
  action_exit_->setShortcut(tr("Ctrl+Q"));
  connect(action_exit_, SIGNAL(triggered()), this, SLOT(slot_exit()));

  action_about_ = new QAction(tr("&About"), this);
  connect(action_about_, SIGNAL(triggered()), this, SLOT(slot_about()));
}

void MainWindow::slot_exit() {
  close();
}

void MainWindow::slot_about() {
    QMessageBox::about(this, tr("About Image Viewer"),
    tr("<p>The user can select several images to be displayed on the screen</p>"));
}


void MainWindow::create_menus() {
  menu_open_ = new QMenu(tr("&Open"), this);

  menu_open_->addAction(action_checker_board_image_);
  menu_open_->addAction(action_exit_);


  menu_help_ = new QMenu(tr("&Help"), this);
  menu_help_->addAction(action_about_);

  menuBar()->addMenu(menu_open_);
  menuBar()->addMenu(menu_help_);
}



//
// Checker Board Triangle
//
const int checker_board_width = 600;
const int checker_board_height = 600;

void MainWindow::slot_load_checker_board_image() {
  // The ~10 lines of code below must be changed with your code
  // Create a QImage of required size
  // Draw a simple black/white checker board

  QImage checker_board_image(checker_board_width,
                             checker_board_height,
                             QImage::Format_RGB32);
  QPainter painter(&checker_board_image);
  painter.fillRect(checker_board_image.rect(), Qt::black);

  QPen pen(qRgb(51, 204, 102));
  pen.setDashPattern({5, 5});
//  pen.setStyle( Qt::CustomDashLine );
  painter.setPen(pen);
  QVector<QPoint> linePoints;

  const int step_width = checker_board_width/10;
  const int step_height = checker_board_height/10;
  for (int y = step_height; y < checker_board_height; y+=step_height)
      // linePoints << QPoint(0,y) << QPoint(checker_board_width,y);
      painter.drawLine(0, y, checker_board_width, y);
  for (int x = step_width; x < checker_board_width; x+=step_width)
      // linePoints << QPoint(x,0) << QPoint(x,checker_board_height);
      painter.drawLine(x, 0, x, checker_board_height);

  // painter.drawLines(linePoints);

  painter.setPen(Qt::black);
  const double xr = 0.64*checker_board_width;
  const double yr = (1-0.33)*checker_board_height;
  const double xv = 0.3*checker_board_width;
  const double yv = (1-0.6)*checker_board_height;
  const double xb = 0.15*checker_board_width;
  const double yb = (1-0.06)*checker_board_height;
  const QVector<QPoint> points({
    QPoint(xr, yr),
    QPoint(xv, yv),
    QPoint(xb, yb)
  });
  QPolygon triangle(points);
  for (int y = std::min(std::min(yr, yv), yb); y < checker_board_height; ++y)
    for (int x = std::min(std::min(xr, xv), xb); x < checker_board_width; ++x)
        if (triangle.containsPoint(QPoint(x, y), Qt::OddEvenFill)) {
            const double r = (((yv-yb)*(x-xb)+(xb-xv)*(y-yb))/((yv-yb)*(xr-xb)+(xb-xv)*(yr-yb)));
            const double v = (((yb-yr)*(x-xb)+(xr-xb)*(y-yb))/((yv-yb)*(xr-xb)+(xb-xv)*(yr-yb)));
            const double b = (1-r-v);

//            const double nr=r/(r+v+b);
//            const double nv=v/(r+v+b);
//            const double nb=b/(r+v+b);
            checker_board_image.setPixel(x, y, qRgb(r*255, v*255, b*255));
        }

  //
  // You probably don't want to change these lines
  //

  image_widget_->setPixmap(QPixmap::fromImage(checker_board_image));
  image_widget_->setFixedSize(checker_board_width, checker_board_height);
  adjustSize();
}
