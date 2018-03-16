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

#ifndef AOCHARMOVIE_H
#define AOCHARMOVIE_H

#include <QMovie>
#include <QLabel>
#include <QTimer>

class AOApplication;

class AOCharMovie : public QLabel
{
	Q_OBJECT

public:
	AOCharMovie(QWidget *p_parent, AOApplication *p_ao_app);

	void play(QString p_char, QString p_emote, QString emote_prefix);
	void play_pre(QString p_char, QString p_emote, int duration);
	void play_talking(QString p_char, QString p_emote);
	void play_idle(QString p_char, QString p_emote);

	void set_flipped(bool p_flipped) {m_flipped = p_flipped;}

	void stop();

	void combo_resize(int w, int h);

private:
	AOApplication *ao_app;

	QMovie *m_movie;
	QVector<QImage> movie_frames;
	QTimer *preanim_timer;

	const int time_mod = 62;

	bool m_flipped = false;

	bool play_once = true;

signals:
	void done();

private slots:
	void frame_change(int n_frame);
	void timer_done();
};

#endif // AOCHARMOVIE_H
