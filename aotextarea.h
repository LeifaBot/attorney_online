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

#ifndef AOTEXTAREA_H
#define AOTEXTAREA_H

#include <QTextBrowser>

class AOTextArea : public QTextBrowser
{
public:
	AOTextArea(QWidget *p_parent = nullptr);

	void append_chatmessage(QString p_name, QString p_message);
};

#endif // AOTEXTAREA_H
