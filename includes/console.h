/*
  shDOS - Command interpreter
  Original file name: console.h
  Copyright (C) 2026 Juan Manuel Mar Hdz.
  Licensed under GPL-3.0, see the license file on the root project structure for more information.
 */ 
 
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef CONSOLE_H
#define CONSOLE_H

unsigned short original_attr, global_attr;
unsigned short console_attr, prompt_attr;
unsigned short original_text_attr, original_bg_attr;

int getWidth();
int getHeight();

void setCursorPosition(int, int);
void fill_line(int, int);
void print_colored_char(char, int);
void print_colored_text(const char *, int);
void setCconsoleColor(int);

void drawPrompt();
void setPromptBuffer();

int getTextColor(unsigned char);
int getBackgroundColor(unsigned char);

#endif
