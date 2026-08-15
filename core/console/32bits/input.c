/*
  shDOS - Command interpreter
  Original file name: input.c
  Copyright (C) 2026 Juan Manuel Mar Hdz.
  Licensed under GPL-3.0, see the license file on the root project structure for more information.
*/

HANDLE hOut;

/* Purpose: Clear current line
	 Created date: 04/08/2026
   Created by username: Juan Manuel Mar Hdz.
   Last modified date: 04/08/2026
   Last modified username: Juan Manuel Mar Hdz.
	 Thanks to chatgpt
*/
void clear_line(int y)
{
	
	COORD pos;
  DWORD written;

  pos.X = 0;
  pos.Y = y;

  FillConsoleOutputCharacter(hOut, ' ', getWidth(), pos, &written);
	
}

/* Purpose: Print on screen typing chars
	 Created date: 04/08/2026
   Created by username: Juan Manuel Mar Hdz.
   Last modified date: 05/08/2026
   Last modified username: Juan Manuel Mar Hdz.
	 Thanks to chatgpt
*/
void redrawCommand()
{
	
	DWORD written;
  int total, attr;
	int x, y, width;

  hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	width = getWidth();

  clear_line(startY);
  setCursorPosition(0, startY);
	
	attr = (conf.consolebgcolor << 4) | conf.prompttextcolor;
  print_colored_text(prompt, attr);
	
	attr = (conf.consolebgcolor << 4) | conf.consoletextcolor;
  SetConsoleTextAttribute(hOut, attr);
  WriteConsole(hOut, command, latestpos, &written, NULL);

  total = strlen(prompt) + currpos;

  x = total % width;
  y = startY + (total / width);

  setCursorPosition(x, y);

}

/* Purpose: Return key pressed (code)
	 	 Created date: 04/08/2026
   Created by username: Juan Manuel Mar Hdz.
   Last modified date: 14/08/2026
   Last modified username: Juan Manuel Mar Hdz.
	 Thanks to chatgpt
*/
int readKey()
{
	
	HANDLE h;
  DWORD read;
  INPUT_RECORD rec;

  h = GetStdHandle(STD_INPUT_HANDLE);

  while(TRUE)
  {

		ReadConsoleInput(h, &rec, 1, &read); 
		
		if(rec.EventType != KEY_EVENT) continue;
		if(!rec.Event.KeyEvent.bKeyDown) continue;
		
		// Normal ASCII character
		
		if(rec.Event.KeyEvent.uChar.AsciiChar) 
			return rec.Event.KeyEvent.uChar.AsciiChar;

    // detect special keys

		switch(rec.Event.KeyEvent.wVirtualKeyCode)
    {

			case VK_LEFT:
        return KEY_LEFT;

      case VK_RIGHT:
        return KEY_RIGHT;

      case VK_UP:
        return KEY_UP;

      case VK_DOWN:
        return KEY_DOWN;

      case VK_HOME:
        return KEY_HOME;

      case VK_END:
        return KEY_END;
        
		}
    
	}

}
