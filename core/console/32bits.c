/*
  shDOS - Command interpreter
  Original file name: 32bits.c
  Copyright (C) 2026 Juan Manuel Mar Hdz.
  Licensed under GPL-3.0, see the license file on the root project structure for more information.
*/

#include <windows.h>

/* Purpose: Return command columns number
	 Created date: 10/06/2026
   Created by username: Juan Manuel Mar Hdz.
   Last modified date: 01/07/2026
   Last modified username: Juan Manuel Mar Hdz.
	 Thanks to chatgpt
*/
int getWidth()
{
	
	CONSOLE_SCREEN_BUFFER_INFO csbi;

  if(GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
	  return csbi.dwSize.X;
  else
    return 80;

}

/* Purpose: Return command rows number
	 Created date: 08/07/2026
   Created by username: Juan Manuel Mar Hdz.
   Last modified date: 08/07/2026
   Last modified username: Juan Manuel Mar Hdz.
	 Thanks to chatgpt
*/
int getHeight()
{
	
	CONSOLE_SCREEN_BUFFER_INFO csbi;

  if(GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
    return csbi.dwSize.Y;
  else
    return 25;

}

/* Purpose: Return initial console text color
	 Created date: 14/06/2026
   Created by username: Juan Manuel Mar Hdz.
   Last modified date: 08/07/2026
   Last modified username: Juan Manuel Mar Hdz.
	 Thanks to chatgpt
*/
int getOriginalConsole()
{
	
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
  return csbi.wAttributes;
	
}

/* Purpose: Restore console text color
	 Created date: 14/06/2026
   Created by username: Juan Manuel Mar Hdz.
   Last modified date: 08/07/2026
   Last modified username: Juan Manuel Mar Hdz.
	 Thanks to chatgpt
*/
void restoreConsole(WORD original_attr)
{
	
	HANDLE hConsole;
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  DWORD written, cells;
  COORD origin = {0,0};
		
  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  GetConsoleScreenBufferInfo(hConsole, &csbi);
	cells = csbi.dwSize.X * csbi.dwSize.Y;

  FillConsoleOutputAttribute(hConsole, original_attr, cells, origin, &written);
	SetConsoleTextAttribute(hConsole, original_attr);
  SetConsoleCursorPosition(hConsole, origin);

}

/* Purpose: Set cursor text position
	 Created date: 13/06/2026
   Created by username: Juan Manuel Mar Hdz.
   Last modified date: 13/06/2026
   Last modified username: Juan Manuel Mar Hdz.
	 Thanks to chatgpt
*/
void setCursorPosition(int x, int y)
{
	
	COORD pos;

  pos.X = x - 1;
  pos.Y = y - 1;

  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	
}

/* Purpose: Set background line color
	 Created date: 14/06/2026
   Created by username: Juan Manuel Mar Hdz.
   Last modified date: 01/07/2026
   Last modified username: Juan Manuel Mar Hdz.
	 Thanks to chatgpt
*/
void fill_line(int y, int attr)
{
	
	HANDLE hConsole;
  DWORD written;
  int width, i;

  COORD pos;
  WORD attributes[LARGE_BUFFER];
  char spaces[LARGE_BUFFER];

  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  width = getWidth();

  for(i = 0; i < width; i++)
  {
		
		attributes[i] = (WORD)attr;
    spaces[i] = ' ';
    
	}

  pos.X = 0;
  pos.Y = y;

  WriteConsoleOutputCharacter(hConsole, spaces, width, pos, &written);
	WriteConsoleOutputAttribute(hConsole, attributes, width, pos, &written);
	
}

/* Purpose: Set color to string
	 Created date: 14/06/2026
   Created by username: Juan Manuel Mar Hdz.
   Last modified date: 14/06/2026
   Last modified username: Juan Manuel Mar Hdz.
	 Thanks to chatgpt and gemini
*/
void print_colored_text(const char *s, int color)
{
	
	HANDLE hConsole;
  DWORD written;

  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole, (WORD)color);
  WriteConsole(hConsole, s, strlen(s), &written, NULL);
	
}

/* Purpose: Set color to string
	 Created date: 14/06/2026
   Created by username: Juan Manuel Mar Hdz.
   Last modified date: 22/06/2026
   Last modified username: Juan Manuel Mar Hdz.
	 Thanks to chatgpt and gemini
*/
void print_colored_text_xy(int x, int y, const char *text, int attr)
{
	
	COORD pos;
	HANDLE hConsole;
  DWORD written;
  WORD attributes[LARGE_BUFFER];
  int len, i;

  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	len = strlen(text);

  for(i = 0; i < len; i++)
    attributes[i] = (WORD)attr;

  pos.X = x;
  pos.Y = y;

  WriteConsoleOutputCharacter(hConsole, text, len, pos, &written);
	WriteConsoleOutputAttribute(hConsole, attributes, len, pos, &written);
	
}


/* Purpose: Set background console color
	 Created date: 07/07/2026
   Created by username: Juan Manuel Mar Hdz.
   Last modified date: 08/07/2026
   Last modified username: Juan Manuel Mar Hdz.
	 Thanks to chatgpt
*/
void setConsoleColor(int attr)
{
	
	HANDLE hConsole;
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  DWORD written;
  COORD origin = {0, 0};
	
	console_attr = attr;

  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsole, &csbi);
	FillConsoleOutputAttribute(hConsole, (WORD)attr, csbi.dwSize.X * csbi.dwSize.Y, origin, &written);
  SetConsoleTextAttribute(hConsole, (WORD)attr);

}
