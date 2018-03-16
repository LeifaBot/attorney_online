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

#ifndef ENCRYPTION_FUNCTIONS_H
#define ENCRYPTION_FUNCTIONS_H

#include <QString>

QString fanta_encrypt(QString p_input, unsigned int key);
QString fanta_decrypt(QString p_input, unsigned int key);

#endif // ENCRYPTION_FUNCTIONS_H
