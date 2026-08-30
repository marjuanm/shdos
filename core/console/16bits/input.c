/*
  shDOS - Command interpreter
  Original file name: input.c
  Copyright (C) 2026 Juan Manuel Mar Hdz.
  Licensed under GPL-3.0, see the license file on the root project structure for more information.
*/

/* Purpose: Clear current line
   Created date: 14/08/2026
   Created by username: Juan Manuel Mar Hdz.
   Last modified date: 14/08/2026
   Last modified username: Juan Manuel Mar Hdz.
	 Thanks to chatgpt
*/
void clear_line(int y)
{
	
	int i, width;

  width = getWidth();
  setCursorPosition(0, y);
  for(i=0; i<width; i++) putchar(' ');
}

/* Purpose: Print on screen typing chars
   Created date: 14/08/2026
   Created by username: Juan Manuel Mar Hdz.
   Last modified date: 15/08/2026
   Last modified username: Juan Manuel Mar Hdz.
	 Thanks to chatgpt
*/
void redrawCommand()
{
	
	int x, y;
	int total, attr;
  int width = getWidth();
	
	setCursorPosition(0, startY);

  attr = (conf.consolebgcolor << 4) | conf.prompttextcolor;
  print_colored_text(prompt, attr);
	attr = (conf.consolebgcolor << 4) | conf.consoletextcolor;
  print_colored_text(command, attr);

  total = strlen(prompt) + currpos;
  x = total % width;
  y = startY + (total / width);

  setCursorPosition(x, y);

}

/* Purpose: Return key pressed
   Created date: 14/08/2026
   Created by username: Juan Manuel Mar Hdz.
   Last modified date: 14/08/2026
   Last modified username: Juan Manuel Mar Hdz.
	 Thanks to chatgpt
*/
int readKey()
{
	
	int c, ext;
	
	c = getch();

  if(c == 0 || c == 224)
  {
		
		ext = getch();
    return 1000 + ext;
    
  }
	else
		return c;

}
