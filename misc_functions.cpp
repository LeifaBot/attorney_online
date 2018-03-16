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

#include "misc_functions.h"

#include <QTime>
#include <QCoreApplication>
#include <QMessageBox>

void delay(int p_milliseconds)
{
	QTime dieTime = QTime::currentTime().addMSecs(p_milliseconds);

	while(QTime::currentTime() < dieTime)
		QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

void call_notice(QString p_message)
{
	QMessageBox *msgBox = new QMessageBox;

	msgBox->setText(p_message);
	msgBox->setWindowTitle("Notice");

	msgBox->exec();
}
