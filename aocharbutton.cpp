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

#include "aocharbutton.h"

#include "file_functions.h"

#include <QFile>

AOCharButton::AOCharButton(QWidget *parent, AOApplication *p_ao_app, int x_pos, int y_pos) : QPushButton(parent)
{
	m_parent = parent;

	ao_app = p_ao_app;

	this->resize(60, 60);
	this->move(x_pos, y_pos);

	ui_taken = new AOImage(this, ao_app);
	ui_taken->resize(60, 60);
	ui_taken->set_image("char_taken.png");
	ui_taken->setAttribute(Qt::WA_TransparentForMouseEvents);
	ui_taken->hide();

	ui_passworded = new AOImage(this, ao_app);
	ui_passworded->resize(60, 60);
	ui_passworded->set_image("char_passworded");
	ui_passworded->setAttribute(Qt::WA_TransparentForMouseEvents);
	ui_passworded->hide();

	ui_selector = new AOImage(parent, ao_app);
	ui_selector->resize(62, 62);
	ui_selector->move(x_pos - 1, y_pos - 1);
	ui_selector->set_image("char_selector.png");
	ui_selector->setAttribute(Qt::WA_TransparentForMouseEvents);
	ui_selector->hide();
}

void AOCharButton::reset()
{
	ui_taken->hide();
	ui_passworded->hide();
	ui_selector->hide();
}

void AOCharButton::set_taken()
{
	ui_taken->show();
}

void AOCharButton::set_passworded()
{
	ui_passworded->show();
}

void AOCharButton::set_image(QString p_character)
{
	QString image_path = ao_app->get_character_path(p_character) + "char_icon.png";
	QString legacy_path = ao_app->get_demothings_path() + p_character.toLower() + "_char_icon.png";
	QString alt_path = ao_app->get_demothings_path() + p_character.toLower() + "_off.png";

	this->setText("");

	if (file_exists(image_path))
		this->setStyleSheet("border-image:url(\"" + image_path + "\")");
	else if (file_exists(legacy_path))
	{
		this->setStyleSheet("border-image:url(\"" + legacy_path + "\")");
		//ninja optimization
		QFile::copy(legacy_path, image_path);
	}
	else
	{
		this->setStyleSheet("border-image:url()");
		this->setText(p_character);
	}
}

void AOCharButton::enterEvent(QEvent * e)
{
	ui_selector->raise();
	ui_selector->show();

	setFlat(false);
	QPushButton::enterEvent(e);
}

void AOCharButton::leaveEvent(QEvent * e)
{
	ui_selector->hide();
	QPushButton::leaveEvent(e);
}


