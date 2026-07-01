/*
  shDOS - Command interpreter
  Original file name: 32bits.c
  Copyright (C) 2026 Juan Manuel Mar Hdz.
  Licensed under GPL-3.0, see the license file on the root project structure for more information.
*/

#include <dos.h>

int cursor_x = 0, cursor_y = 0;
static unsigned short far *video = (unsigned short far *)MK_FP(0xB800, 0);

/* Purpose: Return command columns number
	 Created date: 10/06/2026
   Created by username: Juan Manuel Mar Hdz.
   Last modified date: 01/07/2026
   Last modified username: Juan Manuel Mar Hdz.
	 Thanks to chatgpt
*/
int getWidth()
{
  
	unsigned short far *cols;
	cols = (unsigned short far *)MK_FP(0x40, 0x4A);
	return *cols;
		
}

/* Purpose: Return initial console text color
	 Created date: 14/06/2026
   Created by username: Juan Manuel Mar Hdz.
   Last modified date: 15/06/2026
   Last modified username: Juan Manuel Mar Hdz.
	 Thanks to chatgpt
*/
int getOriginalCmdTextColor()
{
	return (BLACK << 4) | LIGHTGRAY;
}

/* Purpose: Restore console text color
	 Created date: 14/06/2026
   Created by username: Juan Manuel Mar Hdz.
   Last modified date: 22/06/2026
   Last modified username: Juan Manuel Mar Hdz.
*/
void restoreCmdTextColor(unsigned short original_attr)
{
	
	snprintf(largebuffer, sizeof(largebuffer), "");
	print_colored_text(largebuffer, original_attr);
	
}

/* Purpose: Set cursor text position
	 Created date: 13/06/2026
   Created by username: Juan Manuel Mar Hdz.
   Last modified date: 14/06/2026
   Last modified username: Juan Manuel Mar Hdz.
	 Thanks to chatgpt
*/
void setCursorPosition(int x, int y)
{
	
	union REGS r;

  r.h.ah = 0x02;
  r.h.bh = 0;
  r.h.dh = y - 1;
  r.h.dl = x - 1;

  int86(0x10, &r, &r);
	
	cursor_x = x - 1;
  cursor_y = y - 1;

}

/* Purpose: Set background line color
	 Created date: 10/06/2026
   Created by username: Juan Manuel Mar Hdz.
   Last modified date: 01/07/2026
   Last modified username: Juan Manuel Mar Hdz.
	 Thanks to chatgpt
*/
void fill_line(int y, int attr)
{
	
	int x;

  for(x = 0; x < getWidth(); x++)
    video[y * 80 + x] = ((unsigned short)attr << 8) | ' ';
    
}

/* Purpose: Set color to char
	 Created date: 10/06/2026
   Created by username: Juan Manuel Mar Hdz.
   Last modified date: 15/06/2026
   Last modified username: Juan Manuel Mar Hdz.
	 Thanks to chatgpt and gemini
*/
void print_colored_char(char c, int color)
{
	
	if(c == '\n')
  {
		
		cursor_x = 0;
    cursor_y++;
    setCursorPosition(cursor_x + 1, cursor_y + 1);
    
    return;
    
	}

  if(c == '\r')
    return;
			
	video[cursor_y * 80 + cursor_x] = ((unsigned short)color << 8) | c;
	cursor_x++;

  if(cursor_x >= 80)
  {
    
    cursor_x = 0;
    cursor_y++;
    
	}
	
	setCursorPosition(cursor_x + 1, cursor_y + 1);

}

/* Purpose: Set color to string
	 Created date: 10/06/2026
   Created by username: Juan Manuel Mar Hdz.
   Last modified date: 10/06/2026
   Last modified username: Juan Manuel Mar Hdz.
	 Thanks to chatgpt and gemini
*/
void print_colored_text(const char *s, int color)
{
	
	while(*s)
  {
    
    print_colored_char(*s, color);
    s++;
    
	}

}

/* Purpose: Set color to string using x, y position
	 Created date: 10/06/2026
   Created by username: Juan Manuel Mar Hdz.
   Last modified date: 10/06/2026
   Last modified username: Juan Manuel Mar Hdz.
	 Thanks to chatgpt and gemini
*/
void print_colored_text_xy(int x, int y, const char *s, int attr)
{
	
	while(*s)
  {
    
    video[y * 80 + x] = ((unsigned short)attr << 8) | *s;
		x++;
    s++;
    
	}
	
}
