##################################################
#
#  This work is licensed under the MIT license.
#
#  You are free to copy, modify and distribute
#  this work freely given that proper attribution
#  is supplied and the author is not held liable.
#  See LICENSE for details.
#
#  Copyright (c) 2016-2018 David "OmniTroid" Skoland
#
##################################################

QT       += core gui multimedia network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

RC_ICONS = logo.ico

TARGET = attorney_online
TEMPLATE = app

VERSION = 2.4.3.0

SOURCES += \
	main.cpp\
	lobby.cpp \
	text_file_functions.cpp \
	path_functions.cpp \
	aoimage.cpp \
	file_functions.cpp \
	aobutton.cpp \
	networkmanager.cpp \
	aoapplication.cpp \
	aopacket.cpp \
	packet_distribution.cpp \
	hex_functions.cpp \
	encryption_functions.cpp \
	courtroom.cpp \
	aocharbutton.cpp \
	hardware_functions.cpp \
	aoscene.cpp \
	aomovie.cpp \
	misc_functions.cpp \
	aocharmovie.cpp \
	aoemotebutton.cpp \
	emotes.cpp \
	aosfxplayer.cpp \
	aomusicplayer.cpp \
	aoblipplayer.cpp \
	evidence.cpp \
	aoevidencebutton.cpp \
	charselect.cpp \
	aotextarea.cpp \
	aolineedit.cpp \
	aotextedit.cpp \
	aoevidencedisplay.cpp

HEADERS += \
	lobby.h \
	aoimage.h \
	file_functions.h \
	aobutton.h \
	networkmanager.h \
	aoapplication.h \
	datatypes.h \
	aopacket.h \
	hex_functions.h \
	encryption_functions.h \
	courtroom.h \
	aocharbutton.h \
	hardware_functions.h \
	aoscene.h \
	aomovie.h \
	misc_functions.h \
	aocharmovie.h \
	aoemotebutton.h \
	bass.h \
	aosfxplayer.h \
	aomusicplayer.h \
	aoblipplayer.h \
	aoevidencebutton.h \
	aotextarea.h \
	aolineedit.h \
	aotextedit.h \
	aoevidencedisplay.h

unix:LIBS += -L$$PWD -lbass
win32:LIBS += "$$PWD/bass.dll"
