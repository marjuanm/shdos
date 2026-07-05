/*
  shDOS - Command interpreter
  Original file name: core.h
  Copyright (C) 2026 Juan Manuel Mar Hdz.
  Licensed under GPL-3.0, see the license file on the root project structure for more information.
*/ 

#ifndef CORE_H
#define CORE_H

char smallbuffer[SMALL_BUFFER];
char mediumbuffer[MEDIUM_BUFFER];
char largebuffer[LARGE_BUFFER];

char confpath[LARGE_BUFFER];
char shellpath[LARGE_BUFFER];
char currentpath[LARGE_BUFFER];

char prompt[LARGE_BUFFER];
unsigned short original_attr, global_attr;

void trim(char *);
void cmd(char *[]);
void showWelcome();
void clearcmdbuffer();
void getExePath(char *, char *);
void getValueFromKey(char *, char *);
void getCorrectValueToLoad(char *stream, char *value);
struct CONFIGURATION getDefaultConfiguration();

#endif
