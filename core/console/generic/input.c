/*
  shDOS - Command interpreter
  Original file name: input.c
  Copyright (C) 2026 Juan Manuel Mar Hdz.
  Licensed under GPL-3.0, see the license file on the root project structure for more information.
*/

/* Purpose: Insert chars on the string between the text
	 Created date: 04/08/2026
   Created by username: Juan Manuel Mar Hdz.
   Last modified date: 04/08/2026
   Last modified username: Juan Manuel Mar Hdz.
	 Thanks to chatgpt
*/
void insertCommandChar(char c)
{
	
	if(latestpos >= MEDIUM_BUFFER-1) return;
	
	memmove(&command[currpos + 1], &command[currpos], latestpos - currpos + 1);
	command[currpos] = c;
  
	latestpos++;
  currpos++;

}

/* Purpose: Delete character before cursor
   Created date: 04/08/2026
   Created by username: Juan Manuel Mar Hdz.
   Last modified date: 15/08/2026
   Last modified username: Juan Manuel Mar Hdz.
	 Thanks to chatgpt and gemini
*/
void deleteCommandChar()
{
	
	int total, endX, endY;
  int width = getWidth();

  if(currpos <= 0)
    return;

  memmove(&command[currpos - 1], &command[currpos], latestpos - currpos + 1);
  currpos--;
  latestpos--;

  redrawCommand();

  total = strlen(prompt) + latestpos;
  endX = total % width;
  endY = startY + (total / width);

  setCursorPosition(endX, endY);
  print_colored_char(' ', console_attr);
	updateCommandCursor();

}

/* Purpose: Calculate command length in rows
   Created date: 04/08/2026
   Created by username: Juan Manuel Mar Hdz.
   Last modified date: 04/08/2026
   Last modified username: Juan Manuel Mar Hdz.
	 Thanks to chatgpt
*/
int getCommandRows()
{
	
	int total;

  total = strlen(prompt) + latestpos;
  if(total == 0) return 0;
	
  return (total - 1) / getWidth();

}

/* Purpose: Update command cursor position
   Created date: 14/08/2026
   Created by username: Juan Manuel Mar Hdz.
	 Last modified date: 14/08/2026
   Last modified username: Juan Manuel Mar Hdz.
   Thanks to chatgpt
*/
void updateCommandCursor()
{
	
	int total;
  int x;
  int y;
  int width;

  width = getWidth();

  total = strlen(prompt) + currpos;

  x = total % width;
  y = startY + (total / width);

  setCursorPosition(x, y);

}
