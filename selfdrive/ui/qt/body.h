#pragma once

#include <QMovie>
#include <QLabel>
#include <QPushButton>

#include "selfdrive/common/util.h"
#include "selfdrive/ui/ui.h"

class RecordButton : public QPushButton {
  Q_OBJECT

public:
  RecordButton(QWidget* parent = 0);

private:
  void paintEvent(QPaintEvent*) override;
};

class BodyWindow : public QLabel {
  Q_OBJECT

public:
  BodyWindow(QWidget* parent = 0);

private:
  bool charging = false;
  FirstOrderFilter fuel_filter;
  QMovie *awake, *sleep;
  RecordButton *btn;
  void paintEvent(QPaintEvent*) override;

private slots:
  void updateState(const UIState &s);
};
