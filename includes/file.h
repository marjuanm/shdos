/*
  shDOS - Command interpreter
  Original file name: file.h
  Copyright (C) 2026 Juan Manuel Mar Hdz.
  Licensed under GPL-3.0, see the license file on the root project structure for more information.
*/ 

#ifndef FILE_H
#define FILE_H

void getExePath(char *, char *);
int isExecutable(char command[MEDIUM_BUFFER]);

#endif
