/*
  shDOS - Command interpreter
  Original file name: input.h
  Copyright (C) 2026 Juan Manuel Mar Hdz.
  Licensed under GPL-3.0, see the license file on the root project structure for more information.
 */ 

#ifndef INPUT_H
#define INPUT_H

int startX, startY;
int currpos = 0, latestpos = 0;

int getCommandRows();
void deleteCommandChar();
void updateCommandCursor();
void insertCommandChar(char);

#endif
