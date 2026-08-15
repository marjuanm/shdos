/*
  shDOS - Command interpreter
  Original file name: console.h
  New file name: input.h
  Copyright (C) 2026 Juan Manuel Mar Hdz.
  Licensed under GPL-3.0, see the license file on the root project structure for more information.
 */ 

#ifndef INPUT_H
#define INPUT_H

int startX, startY;
int currpos = 0, latestpos = 0;

int readKey();
int getCommandRows();
void clear_line(int);
void redrawCommand();
void insertCommandChar(char);
void deleteCommandChar();
void updateCommandCursor();

#endif
