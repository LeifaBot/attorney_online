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

#include "aolineedit.h"

AOLineEdit::AOLineEdit(QWidget *parent) : QLineEdit(parent)
{
  this->setReadOnly(true);
  this->setFrame(false);

  connect(this, SIGNAL(returnPressed()), this, SLOT(on_enter_pressed()));
}

void AOLineEdit::mouseDoubleClickEvent(QMouseEvent *e)
{
  QLineEdit::mouseDoubleClickEvent(e);

  this->setReadOnly(false);
}

void AOLineEdit::on_enter_pressed()
{
  this->setReadOnly(true);
}
