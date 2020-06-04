//
// header-start
//////////////////////////////////////////////////////////////////////////////////
//
// \file      mainwindow.cpp
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
#include "mainwindow.h"
#include "yuvimage.h"
#include <QtWidgets>


//
//! \brief Initialization of the static member
//!        common to all objects of the class
//!

const int MainWindow::MAX_RECENT_FILES_ = 10;

//
//! \brief MainWindow constructor
//!

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
  //
  // construct image_widget and scroll area
  //
  image_widget_ = new QLabel;
  image_widget_->setBackgroundRole(QPalette::Base);
  image_widget_->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
  image_widget_->setScaledContents(true);

  scroll_area_ = new QScrollArea;
  scroll_area_->setBackgroundRole(QPalette::Dark);
  scroll_area_->setWidget(image_widget_);

  create_actions();
  create_menus();
  update_recent_file_actions();

  setCentralWidget(scroll_area_);
  resize(QGuiApplication::primaryScreen()->availableSize() * 2 / 5);

  base_dir_ = QDir::homePath();
}


void MainWindow::create_actions() {
  action_open_ = new QAction(tr("&Open..."), this);
  action_open_->setShortcut(tr("Ctrl+O"));
  connect(action_open_, SIGNAL(triggered()), this, SLOT(slot_open_file()));

  action_menu_open_recent_title_ = new QAction(tr("Recently Opened Files"), this);

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
    QMessageBox::about(this, tr("About YUV Viewer"),
            tr("<p><b>yuv-viewer</b> display on the screen an YUV 4:2:0 image "
               "read from a given file.</p>"));
}


void MainWindow::create_menus() {
  menu_file_ = new QMenu(tr("&File"), this);

  menu_open_recent_ = new QMenu(menu_file_);
  menu_open_recent_->setTitle(tr("Open Recent"));
  menu_open_recent_->addAction(action_menu_open_recent_title_);
  menu_open_recent_->addSeparator();

  menu_file_->addAction(action_open_);
  menu_file_->addAction(menu_open_recent_->menuAction());
  menu_open_recent_->addSeparator();
  menu_file_->addAction(action_exit_);


  menu_help_ = new QMenu(tr("&Help"), this);
  menu_help_->addAction(action_about_);

  for (int i = 0; i < MAX_RECENT_FILES_; ++i) {
    auto qaction = new QAction(this);
    action_open_recent_files_.push_back(qaction);

    qaction->setVisible(false);
    menu_open_recent_->addAction(qaction);

    connect(qaction, SIGNAL(triggered()), this, SLOT(slot_open_recent_file()));
  }

  menuBar()->addMenu(menu_file_);
  menuBar()->addMenu(menu_help_);
}




void MainWindow::slot_open_recent_file() {
  QAction *action = qobject_cast<QAction *>(sender());
  if (action) {
    QString file_name = action->data().toString();

    process_file(file_name);
  }
}


void MainWindow::slot_open_file() {
  QString file_name =
      QFileDialog::getOpenFileName(this,
                                   tr("Open Raw File"),
                                   base_dir_,
                                   tr("Images (*.yuv);;Any files (*)"));

  if (file_name.isEmpty()) {
    // may be the result of a "cancel" action in the fileDialog
    return;
  }
  // update the base_dir so that we open from the last location
  // next time
  base_dir_ = QFileInfo(file_name).canonicalPath();

  set_current_file(file_name);
  process_file(file_name);
}


//
//! \brief Entry point to process a yuv file
//!        call the YuvImage constructor
//!        update the window title with the file name
//!        copy the image to the image_widget for display

void MainWindow::process_file(const QString &file_name) {
  //
  YuvImage image(file_name.toStdString());
  QString window_title = QString("%1 %2x%3").arg(file_name).arg(image.width()).arg(image.height());
  setWindowFilePath(window_title);
  image_widget_->setPixmap(QPixmap::fromImage(image));
  image_widget_->adjustSize();
}


//
//! \brief The methods below manage the recent file list
//!        history.
//!        set_current_file()

void MainWindow::set_current_file(const QString &file_name) {
  QString key("recentFileList");

  // query file list from key "recentFileList"
  // move fileName to top of the list
  // and remove other instance of fileName

  QSettings settings;
  QStringList files = settings.value(key).toStringList();
  files.removeAll(file_name);
  files.prepend(file_name);
  while (files.size() > MAX_RECENT_FILES_) {
    files.removeLast();
  }
  settings.setValue(key, files);

  foreach (QWidget *widget, QApplication::topLevelWidgets()) {
    MainWindow *main_window = qobject_cast<MainWindow *>(widget);
    if (main_window) {
      main_window->update_recent_file_actions();
    }
  }
}

void MainWindow::update_recent_file_actions() {
  QSettings settings;
  QString key("recentFileList");

  QStringList files = settings.value(key).toStringList();

  int numRecentFiles = qMin(files.size(), MAX_RECENT_FILES_);

  for (int i = 0; i < numRecentFiles; ++i) {
    QString text = tr("%1").arg(stripped_name(files[i]));
    action_open_recent_files_[i]->setText(text);
    action_open_recent_files_[i]->setData(files[i]);
    action_open_recent_files_[i]->setVisible(true);
  }
  for (int i = numRecentFiles; i < MAX_RECENT_FILES_; ++i) {
    action_open_recent_files_[i]->setVisible(false);
  }
}

QString MainWindow::stripped_name(const QString &full_file_name) {
  // ensure that we keep at most 50 characters
  //
  QString file_name("/" + QFileInfo(full_file_name).fileName());
  QString path_name(QFileInfo(full_file_name).canonicalPath());

  if (path_name.length() > 6) {
    int  l_path_name = path_name.length();
    int  l_file_name = file_name.length();

    if (l_path_name + l_file_name > 50) {
      int l_left = 50 - (l_file_name + 3);
      l_left = (l_left < 3)  ? 3 : l_left;
      // remove from l_path_name
      path_name = path_name.left(l_left).append("...");
    }
  }
  return path_name + file_name;
}
