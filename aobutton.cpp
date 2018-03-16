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

#include "aobutton.h"

#include "debug_functions.h"
#include "file_functions.h"

#include <QDebug>

AOButton::AOButton(QWidget *parent, AOApplication *p_ao_app) : QPushButton(parent)
{
	ao_app = p_ao_app;
}

AOButton::~AOButton()
{

}

void AOButton::set_image(QString p_image)
{
	QString image_path = ao_app->get_theme_path() + p_image;
	QString default_image_path = ao_app->get_default_theme_path() + p_image;

	if (file_exists(image_path))
		this->setStyleSheet("border-image:url(\"" + image_path + "\")");
	else
		this->setStyleSheet("border-image:url(\"" + default_image_path + "\")");
}

