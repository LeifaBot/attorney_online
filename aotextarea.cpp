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

#include "aotextarea.h"

#include <QScrollBar>
#include <QTextCursor>
#include <QRegExp>
#include <QDebug>

AOTextArea::AOTextArea(QWidget *p_parent) : QTextBrowser(p_parent)
{

}

void AOTextArea::append_chatmessage(QString p_name, QString p_message)
{
	const QTextCursor old_cursor = this->textCursor();
	const int old_scrollbar_value = this->verticalScrollBar()->value();
	const bool is_scrolled_down = old_scrollbar_value == this->verticalScrollBar()->maximum();

	this->moveCursor(QTextCursor::End);

	this->append("");
	this->insertHtml("<b>" + p_name.toHtmlEscaped() + "</b>:&nbsp;");

	QRegExp url_regex("\\b(https?://\\S+\\.\\S+)\\b");

	//this is to make sure the message matches the regex even if it's the first word in the sentence
	p_message += " ";

	QString result = p_message.toHtmlEscaped().replace("\n", "<br>").replace(url_regex, "<a href='\\1'>\\1</a>" );

	this->insertHtml(result);

	if (old_cursor.hasSelection() || !is_scrolled_down)
	{
			// The user has selected text or scrolled away from the bottom: maintain position.
			this->setTextCursor(old_cursor);
			this->verticalScrollBar()->setValue(old_scrollbar_value);
	}
	else
	{
			// The user hasn't selected any text and the scrollbar is at the bottom: scroll to the bottom.
			this->moveCursor(QTextCursor::End);
			this->verticalScrollBar()->setValue(this->verticalScrollBar()->maximum());
	}
}
