// Copyright none
#include <QtWidgets>
#include <iostream>
#include <chrono>
#include <string>
#include <algorithm>
#include <memory>
#include "./mainwindow.h"
#include "./util.h"
#include "./fractal.h"

namespace global {
    // variables to manipulate the fractal inside the events
    static bool fract_julia = false;  // choose wich fractal to display
    static std::unique_ptr<FractalImage> current_fract;
    static double xc = -0.5;  // initial values
    static double yc = 0;
    static double d = 1;
}

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
  action_mandelbrot_image_ = new QAction(tr("Mandelbrot Fractal Image"), this);
  connect(action_mandelbrot_image_, SIGNAL(triggered()),
          this, SLOT(slot_mandelbrot_image()));

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

  menu_open_->addAction(action_mandelbrot_image_);
  menu_open_->addAction(action_exit_);


  menu_help_ = new QMenu(tr("&Help"), this);
  menu_help_->addAction(action_about_);

  menuBar()->addMenu(menu_open_);
  menuBar()->addMenu(menu_help_);
}




// fractal subwindow
const int fractal_width = 600;
const int fractal_height = 400;
void MainWindow::slot_mandelbrot_image() {
  //
  if (global::fract_julia)
    global::current_fract = std::make_unique<JuliaImage>
            (global::xc, global::yc, global::d, fractal_width, fractal_height);
  else
    global::current_fract = std::make_unique<MandelbrotImage>
            (global::xc, global::yc, global::d, fractal_width, fractal_height);
  // measuring construct time
  auto start = std::chrono::high_resolution_clock::now();
  global::current_fract->make_fractal();
  auto end = std::chrono::high_resolution_clock::now();
  auto elapsed_time = end - start;
  std::cout << "Info: image calculated in "
            << Commify(elapsed_time.count()) << " ns, or "
            << elapsed_time.count()/1000000000.0 << " s" << std::endl;

  image_widget_->setPixmap(QPixmap::fromImage(*global::current_fract.get()));
  image_widget_->setFixedSize(fractal_width, fractal_height);
  adjustSize();
}

// event for fractal navigation
void MainWindow::keyPressEvent(QKeyEvent *event) {

  bool pressed = false;

  switch (event->key()) {
  case Qt::Key_T:   // toggle
      global::fract_julia = !global::fract_julia;
      pressed = true;
      break;
  case Qt::Key_Left:    // go left
          global::xc -= 0.1*global::d;
          pressed = true;
      break;
  case Qt::Key_Right:   // go right
          global::xc += 0.1*global::d;
          pressed = true;
      break;
  case Qt::Key_Up:  // go up
          global::yc += 0.1*global::d;
          pressed = true;
      break;
  case Qt::Key_Down:    // go down
          global::yc -= 0.1*global::d;
          pressed = true;
      break;
  case Qt::Key_Plus:    // zoom in
          global::d = global::d/1.5;
          pressed = true;
      break;
  case Qt::Key_Minus:   // zoom out
          global::d = global::d*1.5;
          pressed = true;
      break;

  default:
      QMainWindow::keyPressEvent(event);
    }

    if (pressed) {  // if change detected, we update the screen
      slot_mandelbrot_image();
    }
}


