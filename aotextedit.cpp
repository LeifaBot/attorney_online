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

#include "aotextedit.h"

AOTextEdit::AOTextEdit(QWidget *parent) : QPlainTextEdit(parent)
{
	this->setReadOnly(true);

	//connect(this, SIGNAL(returnPressed()), this, SLOT(on_enter_pressed()));
}

void AOTextEdit::mouseDoubleClickEvent(QMouseEvent *e)
{
	QPlainTextEdit::mouseDoubleClickEvent(e);

	this->setReadOnly(false);
}

void AOTextEdit::on_enter_pressed()
{
	this->setReadOnly(true);
}

