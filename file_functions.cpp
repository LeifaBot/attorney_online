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

#include <QFileInfo>
#include <QDir>

#include "file_functions.h"

bool file_exists(QString file_path)
{
	QFileInfo check_file(file_path);

	return check_file.exists() && check_file.isFile();
}

bool dir_exists(QString dir_path)
{
	QDir check_dir(dir_path);

	return check_dir.exists();
}
