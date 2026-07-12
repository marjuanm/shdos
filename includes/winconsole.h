/*
  shDOS - Command interpreter
  Original file name: winconsole.h
  Copyright (C) 2026 Juan Manuel Mar Hdz.
  Licensed under GPL-3.0, see the license file on the root project structure for more information.
 */ 

#ifndef WINCONSOLE_H
#define WINCONSOLE_H

#include <windows.h>

int getOriginalConcole();
void restoreConsole(WORD);

int getTextColor(WORD);
int getBackgroundColor(WORD);

#endif
