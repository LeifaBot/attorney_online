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

#include "hardware_functions.h"

#include <QDebug>

#if (defined (_WIN32) || defined (_WIN64))
#include <windows.h>

DWORD dwVolSerial;
BOOL bIsRetrieved;

QString get_hdid()
{
	bIsRetrieved = GetVolumeInformation(TEXT("C:\\"), NULL, NULL, &dwVolSerial, NULL, NULL, NULL, NULL);

	if (bIsRetrieved)
		return QString::number(dwVolSerial, 16);
	else
		//a totally random string
		//what could possibly go wrong
		return "gxsps32sa9fnwic92mfbs0";

}

#elif (defined (LINUX) || defined (__linux__))

#include <QFile>
#include <QTextStream>

QString get_hdid()
{
	QFile fstab_file("/etc/fstab");
	if (!fstab_file.open(QIODevice::ReadOnly))
		return "gxcps32sa9fnwic92mfbs0";

	QTextStream in(&fstab_file);

	while(!in.atEnd())
	{
		QString line = in.readLine();

		if (line.startsWith("UUID"))
		{
			QStringList line_elements = line.split("=");

			if (line_elements.size() > 1)
				return line_elements.at(1).left(23).trimmed();
		}
	}

	return "gxcpz32sa9fnwic92mfbs0";
}

#else

#error This operating system is unsupported for hardware functions.

#endif
