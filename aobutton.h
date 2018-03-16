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

#ifndef AOBUTTON_H
#define AOBUTTON_H

#include "aoapplication.h"

#include <QPushButton>

class AOButton : public QPushButton
{
	Q_OBJECT

public:
	AOButton(QWidget *parent, AOApplication *p_ao_app);
	~AOButton();

	AOApplication *ao_app;

	void set_image(QString p_image);
};

#endif // AOBUTTON_H
