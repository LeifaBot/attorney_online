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

#ifndef AOTEXTEDIT_H
#define AOTEXTEDIT_H

#include <QPlainTextEdit>

class AOTextEdit : public QPlainTextEdit
{
	Q_OBJECT
public:
	AOTextEdit(QWidget *parent);

protected:
	void mouseDoubleClickEvent(QMouseEvent *e);

signals:
	void double_clicked();

private slots:
	void on_enter_pressed();

};

#endif // AOTEXTEDIT_H
