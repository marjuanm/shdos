/*
  shDOS - Command interpreter
  Original file name: console.h
  Copyright (C) 2026 Juan Manuel Mar Hdz.
  Licensed under GPL-3.0, see the license file on the root project structure for more information.
 */ 

#ifndef CONSOLE_H
#define CONSOLE_H

unsigned short original_attr, global_attr;
unsigned short console_attr, prompt_attr;
unsigned short original_text_attr, original_bg_attr;

int getX();
int getY();
int getWidth();
int getHeight();
int getOriginalConsole();

void fill_line(int, int);
void setCursorPosition(int, int);
void print_colored_char(char, int);
void print_colored_text(const char *, int);
void print_colored_text_xy(int, int, const char *, int);

#endif
