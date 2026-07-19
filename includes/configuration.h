/*
  shDOS - Command interpreter
  Original file name: configuration.h
  Copyright (C) 2026 Juan Manuel Mar Hdz.
  Licensed under GPL-3.0, see the license file on the root project structure for more information.
*/ 

#ifndef CONFIGURATION_H
#define CONFIGURATION_H

struct CONFIGURATION conf;
char line[SMALL_BUFFER], tmp[2];
char value[SMALL_BUFFER], stmp[SMALL_BUFFER];

void getValueFromKey(char *, char *);
void getCorrectValueToLoad(char *stream, char *value);
struct CONFIGURATION getDefaultConfiguration();
void loadConfiguration();

#endif
