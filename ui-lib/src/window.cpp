#include "window.h"
#include "moc_window.cpp"

Window::Window(QMainWindow* parent)
  : QMainWindow(parent)
{
  this->ui.setupUi(this);
}
