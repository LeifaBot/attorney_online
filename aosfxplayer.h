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

#ifndef AOSFXPLAYER_H
#define AOSFXPLAYER_H

#include "bass.h"
#include "aoapplication.h"

#include <QWidget>

class AOSfxPlayer
{
public:
	AOSfxPlayer(QWidget *parent, AOApplication *p_ao_app);

	void play(QString p_sfx, QString p_char = "");
	void stop();
	void set_volume(int p_volume);

private:
	QWidget *m_parent;
	AOApplication *ao_app;

	int m_volume = 0;
	HSTREAM m_stream;
};

#endif // AOSFXPLAYER_H
