/*
  shDOS - Command interpreter
  Original file name: console.h
  New file name: commons.h
  Copyright (C) 2026 Juan Manuel Mar Hdz.
  Licensed under GPL-3.0, see the license file on the root project structure for more information.
 */ 

#ifndef COMMONS_H
#define COMMONS_H

unsigned short original_attr, global_attr;
unsigned short console_attr, prompt_attr;
unsigned short original_text_attr, original_bg_attr;

int getX();
int getY();
int getWidth();
int getHeight();

void setCursorPosition(int, int);
void fill_line(int, int);
void print_colored_char(char, int);
void print_colored_text(const char *, int);

int getTextColor(unsigned char);
int getBackgroundColor(unsigned char);

#endif
