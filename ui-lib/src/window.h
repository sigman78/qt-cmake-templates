#pragma once

#include <QtGui>
#include "window.h"

class Window : public QMainWindow
{
  Q_OBJECT

  public:
    Window(QMainWindow* parent = 0);

  private:
    Ui::Window ui;
};

#endif
