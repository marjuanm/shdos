/*
  shDOS - Command interpreter
  Original file name: generic.c
  Copyright (C) 2026 Juan Manuel Mar Hdz.
  Licensed under GPL-3.0, see the license file on the root project structure for more information.
*/

/* 
  Purpose: Prepare prompt buffer
  Created date: 24/06/2026
  Created by username: Juan Manuel Mar Hdz.
  Last modified date: 24/06/2026
  Last modified username: Juan Manuel Mar Hdz.
	Thanks to chatgpt
*/
void setPromptBuffer()
{
	
	// path
	memset(prompt, 0, LARGE_BUFFER);
  strncpy(prompt, currentpath, sizeof(prompt) - 1);
	
	// >
	if(strlen(prompt) > 0 && prompt[strlen(prompt) - 1] == '\\')
		prompt[strlen(prompt) - 1] = '\0';

	strcat(prompt, ">");
	
}

/* 
  Purpose: Print prompt buffer on the screen
  Created date: 24/06/2026
  Created by username: Juan Manuel Mar Hdz.
  Last modified date: 08/07/2026
  Last modified username: Juan Manuel Mar Hdz.
*/
void drawPrompt()
{

	snprintf(largebuffer, sizeof(largebuffer), prompt);
	print_colored_text(largebuffer, prompt_attr);
	fflush(stdout);
	
}

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
