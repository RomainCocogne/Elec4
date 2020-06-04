//
// header-start
//////////////////////////////////////////////////////////////////////////////////
//
// \file      mainwindow.h
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
#pragma once


#include <QMainWindow>
#include <vector>

QT_BEGIN_NAMESPACE
class QAction;
class QLabel;
class QMenu;
class QScrollArea;
class QScrollBar;
QT_END_NAMESPACE


class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  static const int MAX_RECENT_FILES_;
  explicit MainWindow(QWidget *parent = nullptr);
  ~MainWindow() = default;

  QLabel *image_widget_;
  QScrollArea *scroll_area_;

private slots:
  void slot_exit();
  void slot_about();
  void slot_open_file();
  void slot_open_recent_file();

private:
  QString base_dir_;
  void update_recent_file_actions();
  void create_actions();
  void create_menus();
  void process_file(const QString &);

  void set_current_file(const QString &);
  QString stripped_name(const QString &);

  std::vector<QAction *> action_open_recent_files_;
  QAction *action_open_;
  QAction *action_exit_;
  QAction *action_about_;
  QAction *action_menu_open_recent_title_;

  QMenu *menu_file_;
  QMenu *menu_open_recent_;
  QMenu *menu_help_;
};
