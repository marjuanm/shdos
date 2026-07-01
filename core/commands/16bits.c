/*
  shDOS - Command interpreter
  Original file name: 16bits.c
  Copyright (C) 2026 Juan Manuel Mar Hdz.
  Licensed under GPL-3.0, see the license file on the root project structure for more information.
 */ 

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

	cursor_x = 0;
	cursor_y = 0;
	setCursorPosition(cursor_x + 1, cursor_y + 1);

}
