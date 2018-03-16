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

#ifndef AOSCENE_H
#define AOSCENE_H

#include <QLabel>

class Courtroom;
class AOApplication;

class AOScene : public QLabel
{
	Q_OBJECT
public:
	explicit AOScene(QWidget *parent, AOApplication *p_ao_app);

	void set_image(QString p_image);
	void set_legacy_desk(QString p_image);

private:
	QWidget *m_parent;
	AOApplication *ao_app;

};

#endif // AOSCENE_H
