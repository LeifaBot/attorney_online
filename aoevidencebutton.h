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

#ifndef AOEVIDENCEBUTTON_H
#define AOEVIDENCEBUTTON_H

#include "aoapplication.h"
#include "aoimage.h"

#include <QPushButton>
#include <QString>

class AOEvidenceButton : public QPushButton
{
	Q_OBJECT

public:
	AOEvidenceButton(QWidget *p_parent, AOApplication *p_ao_app, int p_x, int p_y);

	void reset();
	void set_image(QString p_image);
	void set_theme_image(QString p_image);
	void set_id(int p_id) {m_id = p_id;}

	void set_selected(bool p_selected);

private:
	AOApplication *ao_app;
	QWidget *m_parent;

	AOImage *ui_selected;
	AOImage *ui_selector;

	int m_id = 0;

protected:
	void enterEvent(QEvent *e);
	void leaveEvent(QEvent *e);
	void mouseDoubleClickEvent(QMouseEvent *e);

signals:
	void evidence_clicked(int p_id);
	void evidence_double_clicked(int p_id);
	void on_hover(int p_id, bool p_state);

private slots:
	void on_clicked();
};

#endif // AOEVIDENCEBUTTON_H
