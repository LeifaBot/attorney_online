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

//This class represents a static theme-dependent image

#ifndef AOIMAGE_H
#define AOIMAGE_H

#include "aoapplication.h"

#include <QLabel>

class AOImage : public QLabel
{
public:
  AOImage(QWidget *parent, AOApplication *p_ao_app);
  ~AOImage();

  QWidget *m_parent;
  AOApplication *ao_app;

  void set_image(QString p_image);
  void set_image_from_path(QString p_path);
  void set_size_and_pos(QString identifier);
};

#endif // AOIMAGE_H
