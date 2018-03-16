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

#ifndef AOPACKET_H
#define AOPACKET_H

#include <QString>
#include <QStringList>

class AOPacket
{
public:
	AOPacket(QString p_packet_string);
	AOPacket(QString header, QStringList &p_contents);
	~AOPacket();

	QString get_header() {return m_header;}
	QStringList &get_contents() {return m_contents;}
	QString to_string();

	void encrypt_header(unsigned int p_key);
	void decrypt_header(unsigned int p_key);

	void net_encode();
	void net_decode();

private:
	bool encrypted = false;

	QString m_header;
	QStringList m_contents;
};

#endif // AOPACKET_H
