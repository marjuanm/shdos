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

#ifndef COLORS_H
#define COLORS_H

#define BLACK           0x0
#define BLUE            0x1
#define GREEN           0x2
#define CYAN            0x3
#define RED             0x4
#define MAGENTA         0x5
#define BROWN           0x6
#define LIGHTGRAY       0x7
#define DARKGRAY        0x8
#define LIGHTBLUE       0x9
#define LIGHTGREEN      0xA
#define LIGHTCYAN       0xB
#define LIGHTRED        0xC
#define LIGHTMAGENTA    0xD
#define YELLOW          0xE
#define WHITE           0xF

int getContrastColor(int);

#endif
