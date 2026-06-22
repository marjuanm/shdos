/*
  shDOS - Command interpreter
  Original file name: structures.h
  Copyright (C) 2026 Juan Manuel Mar Hdz.
  Licensed under GPL-3.0, see the license file on the root project structure for more information.
*/

#include "constants.h"

#ifndef STRUCTURES_H
#define STRUCTURES_H

struct CONFIGURATION
{
	
	int showheader;
	int headertype;
	int headerbgcolor;
	int headertextcolor;
	int consolebgcolor;
	int consoletextcolor;
	int prompttextcolor;
	int usecmdthemes;
	char promptlabel[MAX_BUFFER];
	
};

#endif
