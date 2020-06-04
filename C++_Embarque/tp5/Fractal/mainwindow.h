
#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include <vector>
#include <memory>
#include "./fractal.h"

QT_BEGIN_NAMESPACE
class QAction;
class QLabel;
class QMenu;
QT_END_NAMESPACE


class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow() = default;

  QLabel *image_widget_;

 private slots:
  void slot_exit();
  void slot_about();
  void slot_mandelbrot_image();

 private:
  void create_menus();
  void create_actions();
  void keyPressEvent(QKeyEvent *event) override;
//  void resizeEvent(QResizeEvent* event) override;

  QAction *action_mandelbrot_image_;
  QAction *action_about_;
  QAction *action_exit_;

  QMenu *menu_open_;
  QMenu *menu_help_;

};

#endif  // MAINWINDOW_H
