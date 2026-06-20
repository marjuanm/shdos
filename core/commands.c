/*
  shDOS - Command interpreter
  Original file name: commands.c
  Copyright (C) 2026 Juan Manuel Mar Hdz.
  Licensed under GPL-3.0, see the license file on the root project structure for more information.
*/

/* Purpose: Show shdos version
	 Created date: 19/06/2026
   Created by username: Juan Manuel Mar Hdz.
   Last modified date: 19/06/2026
   Last modified username: Juan Manuel Mar Hdz.
	 Thanks to chatgpt
*/
void ver(unsigned short attr)
{

	char buffer[MAX_BUFFER];
	
  clearcmdbuffer();
	snprintf(buffer, sizeof(buffer), "\n%s %s\n", PROJECT_NAME, PROJECT_VERSION);
	print_colored_text(buffer, attr);
	fflush(stdout);
	
}
