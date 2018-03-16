//////////////////////////////////////////////////
//
//  This work is licensed under the MIT license.
//  
//  You are free to copy, modify and distribute
//  this work freely given that proper attribution
//  is supplied and the author is not held liable.
//  See LICENSE for details.
//  
//  Copyright (c) 2016-2018 David "OmniTroid" Skoland
//
//////////////////////////////////////////////////

#ifndef AOLINEEDIT_H
#define AOLINEEDIT_H

#include <QLineEdit>
#include <QMouseEvent>

class AOLineEdit : public QLineEdit
{
  Q_OBJECT

public:
  AOLineEdit(QWidget *parent);

protected:
  void mouseDoubleClickEvent(QMouseEvent *e);

signals:
  void double_clicked();

private slots:
  void on_enter_pressed();


};

#endif // AOLINEEDIT_H
