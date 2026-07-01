/*
  shDOS - Command interpreter
  Original file name: commands.h
  Copyright (C) 2026 Juan Manuel Mar Hdz.
  Licensed under GPL-3.0, see the license file on the root project structure for more information.
*/ 

#ifndef COMMANDS_H
#define COMMANDS_H

void ver(unsigned short);
void cls();

void executeCommand(char *, char *, unsigned short);
int isExecutable(char command[MEDIUM_BUFFER]);
void commandNotFound(unsigned short);
void invalidExecutable(unsigned short);
void unsupportedComFile(unsigned short);

#endif
