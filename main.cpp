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

#include "datatypes.h"
#include "networkmanager.h"
#include "lobby.h"
#include "courtroom.h"

#include <QDebug>

int main(int argc, char *argv[])
{
		AOApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
		AOApplication main_app(argc, argv);
		main_app.construct_lobby();
		main_app.net_manager->connect_to_master();
		AOPacket *f_packet = new AOPacket("ALL#%");
		main_app.send_ms_packet(f_packet);
		main_app.w_lobby->show();

		return main_app.exec();
}
