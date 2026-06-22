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
   Last modified date: 10/06/2026
   Last modified username: Juan Manuel Mar Hdz.
	 Thanks to chatgpt
*/
int getCmdWidth()
{
	
	CONSOLE_SCREEN_BUFFER_INFO csbi;

  if(GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
	  return csbi.dwSize.X;
  else
    return 80;

}

/* Purpose: Clear console window
	 Created date: 13/06/2026
   Created by username: Juan Manuel Mar Hdz.
   Last modified date: 19/06/2026
   Last modified username: Juan Manuel Mar Hdz.
	 Thanks to chatgpt
*/
void cls()
{
	
  clearcmdbuffer();
	fflush(stdout);		  
	system("cls");
	
}

/* Purpose: Return initial console text color
	 Created date: 14/06/2026
   Created by username: Juan Manuel Mar Hdz.
   Last modified date: 14/06/2026
   Last modified username: Juan Manuel Mar Hdz.
	 Thanks to chatgpt
*/
int getOriginalCmdTextColor()
{
	
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
  return csbi.wAttributes;
	
}

/* Purpose: Restore console text color
	 Created date: 14/06/2026
   Created by username: Juan Manuel Mar Hdz.
   Last modified date: 14/06/2026
   Last modified username: Juan Manuel Mar Hdz.
	 Thanks to chatgpt
*/
void restoreCmdTextColor(WORD original_attr)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), original_attr);
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
   Last modified date: 19/06/2026
   Last modified username: Juan Manuel Mar Hdz.
	 Thanks to chatgpt
*/
void fill_line(int y, int attr)
{
	
	HANDLE hConsole;
  DWORD written;
  int width, i;

  COORD pos;
  WORD attributes[MAX_BUFFER];
  char spaces[MAX_BUFFER];

  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  width = getCmdWidth();

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
   Last modified date: 19/06/2026
   Last modified username: Juan Manuel Mar Hdz.
	 Thanks to chatgpt and gemini
*/
void print_colored_text_xy(int x, int y, const char *text, int attr)
{
	
	COORD pos;
	HANDLE hConsole;
  DWORD written;
  WORD attributes[MAX_BUFFER];
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

/* Purpose: Return default console configuration
	 Created date: 20/06/2026
   Created by username: Juan Manuel Mar Hdz.
   Last modified date: 21/06/2026
   Last modified username: Juan Manuel Mar Hdz.
	 Thanks to chatgpt and gemini
*/
struct CONFIGURATION getDefaultCmdConfiguration()
{
	
	struct CONFIGURATION conf;
    
  conf.showheader = 1;                    // 1 = yes, 0 = false
  conf.headertype = 1;                    // 1 = full (version + help and copyright in new row), 2 = version + copyright in 2 rows
  conf.headerbgcolor = BLUE;              // default value    
  conf.headertextcolor = WHITE;           // default value
  conf.consolebgcolor = BLACK;            // default value
  conf.consoletextcolor = WHITE;          // default value
  conf.prompttextcolor = GREEN;           // default value
	conf.usecmdthemes = 1;									//1 = yes, 0 = false
    
  memset(conf.promptlabel, 0, MAX_BUFFER);
  strncpy(conf.promptlabel, "$p$g", sizeof(conf.promptlabel) - 1); // prompt like C:\>
	conf.promptlabel[sizeof(conf.promptlabel) - 1] = '\0';
  
	return conf;

}

