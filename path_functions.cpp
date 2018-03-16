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

#include "aoapplication.h"
#include "courtroom.h"
#include "file_functions.h"
#include <QDir>
#include <QDebug>
#include <QStandardPaths>

QString base_path = "";

QString AOApplication::get_base_path()
{
	return QDir::currentPath() + "/base/";
}

QString AOApplication::get_theme_path()
{
	return get_base_path() + "themes/" + current_theme.toLower() + "/";
}

QString AOApplication::get_default_theme_path()
{
	return get_base_path() + "themes/default/";
}

QString AOApplication::get_character_path(QString p_character)
{
	return get_base_path() + "characters/" + p_character.toLower() + "/";
}

QString AOApplication::get_demothings_path()
{
	QString default_path = "misc/demothings/";
	QString alt_path = "misc/RosterImages";
	if (dir_exists(default_path))
		return get_base_path() + default_path;
	else if (dir_exists(alt_path))
		return get_base_path() + alt_path;
	else
		return get_base_path() + default_path;
}
QString AOApplication::get_sounds_path()
{
	return get_base_path() + "sounds/general/";
}
QString AOApplication::get_music_path(QString p_song)
{
	return get_base_path() + "sounds/music/" + p_song.toLower();
}

QString AOApplication::get_background_path()
{
	if (courtroom_constructed)
		return w_courtroom->get_background_path();
	//this function being called when the courtroom isn't constructed makes no sense
	return "";
}

QString AOApplication::get_default_background_path()
{
	return get_base_path() + "background/gs4/";
}

QString AOApplication::get_evidence_path()
{
		QString default_path = "evidence/";
		QString alt_path = "items/";
		if (dir_exists(default_path))
			return get_base_path() + default_path;
		else if (dir_exists(alt_path))
			return get_base_path() + alt_path;
		else
			return get_base_path() + default_path;
}

QString Courtroom::get_background_path()
{
	return ao_app->get_base_path() + "background/" + current_background.toLower() + "/";
}

QString Courtroom::get_default_background_path()
{
	return ao_app->get_base_path() + "background/gs4/";
}
