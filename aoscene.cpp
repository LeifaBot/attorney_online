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

#include "aoscene.h"

#include "courtroom.h"

#include "file_functions.h"

#include <QDebug>

AOScene::AOScene(QWidget *parent, AOApplication *p_ao_app) : QLabel(parent)
{
	m_parent = parent;
	ao_app = p_ao_app;
}

void AOScene::set_image(QString p_image)
{
	QString background_path = ao_app->get_background_path() + p_image + ".png";
	QString animated_background_path = ao_app->get_background_path() + p_image + ".gif";
	QString default_path = ao_app->get_default_background_path() + p_image;

	QPixmap background(background_path);
	QPixmap animated_background(animated_background_path);
	QPixmap default_bg(default_path);

	int w = this->width();
	int h = this->height();

	if (file_exists(animated_background_path))
		this->setPixmap(animated_background.scaled(w, h));
	else if (file_exists(background_path))
		this->setPixmap(background.scaled(w, h));
	else
		this->setPixmap(default_bg.scaled(w, h));
}

void AOScene::set_legacy_desk(QString p_image)
{
	//vanilla desks vary in both width and height. in order to make that work with viewport rescaling,
	//some INTENSE math is needed.

	QString desk_path = ao_app->get_background_path() + p_image;
	QString default_path = ao_app->get_default_background_path() + p_image;

	QPixmap f_desk;

	if (file_exists(desk_path))
		f_desk.load(desk_path);
	else
		f_desk.load(default_path);

	int vp_width = m_parent->width();
	int vp_height = m_parent->height();

	//double y_modifier = 147 / 192;
	//double w_modifier = vp_width / 256;
	double h_modifier = vp_height / 192;

	//int final_y = y_modifier * vp_height;
	//int final_w = w_modifier * f_desk.width();
	int final_h = h_modifier * f_desk.height();

	//this->resize(final_w, final_h);
	//this->setPixmap(f_desk.scaled(final_w, final_h));
	this->resize(vp_width, final_h);
	this->setPixmap(f_desk.scaled(vp_width, final_h));
}
