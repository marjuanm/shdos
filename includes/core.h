/*
  shDOS - Command interpreter
  Original file name: core.h
  Copyright (C) 2026 Juan Manuel Mar Hdz.
  Licensed under GPL-3.0, see the license file on the root project structure for more information.
*/ 

#ifndef CORE_H
#define CORE_H

void cmd(char *[]);
void showWelcome();
void clearcmdbuffer();
void getExePath(char *, char *);
void getValueFromKey(char *, char *);
void getCorrectValueToLoad(char *stream, char *value);

#endif
