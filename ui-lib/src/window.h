#pragma once

#include <QtGui>
#include "ui_window.h"

class Window : public QMainWindow
{
  Q_OBJECT

  public:
    Window(QMainWindow* parent = 0);

  private:
    Ui::Window ui;
};
