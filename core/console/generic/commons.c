/*
  shDOS - Command interpreter
  Original file name: generic.c
	New file name: commons.c
  New name: commons.h
  Copyright (C) 2026 Juan Manuel Mar Hdz.
  Licensed under GPL-3.0, see the license file on the root project structure for more information.
*/

/* Purpose: Get text color from attr
   Created date: 08/07/2026
   Created by username: Juan Manuel Mar Hdz.
   Last modified date: 08/07/2026
   Last modified username: Juan Manuel Mar Hdz.
*/
int getTextColor(unsigned char attr)
{
   return attr & 0x0F;
}

/* Purpose: Get background color from attr
   Created date: 08/07/2026
   Created by username: Juan Manuel Mar Hdz.
   Last modified date: 08/07/2026
   Last modified username: Juan Manuel Mar Hdz.
*/
int getBackgroundColor(unsigned char attr)
{
   return (attr >> 4) & 0x07;
}

/* 
  Purpose: Prepare prompt buffer
  Created date: 24/06/2026
  Created by username: Juan Manuel Mar Hdz.
  Last modified date: 06/08/2026
  Last modified username: Juan Manuel Mar Hdz.
	Thanks to chatgpt
*/
void showPrompt()
{
	
	// path
	memset(prompt, 0, LARGE_BUFFER);
  strncpy(prompt, currentpath, sizeof(prompt) - 1);
	
	// >
	if(strlen(prompt) > 0 && prompt[strlen(prompt) - 1] == '\\')
		prompt[strlen(prompt) - 1] = '\0';

	strcat(prompt, ">");
	
	command[0] = '\0';
  currpos = 0;
  latestpos = 0;
  startY = getY();
	redrawCommand();

}

