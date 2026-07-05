/*
  shDOS - Command interpreter
  Original file name: generic.c
  Copyright (C) 2026 Juan Manuel Mar Hdz.
  Licensed under GPL-3.0, see the license file on the root project structure for more information.
*/

/* Purpose: Show shdos version
	 Created date: 19/06/2026
   Created by username: Juan Manuel Mar Hdz.
   Last modified date: 02/07/2026
   Last modified username: Juan Manuel Mar Hdz.
	 Thanks to chatgpt
*/
void ver(unsigned short attr)
{

  int bits = getOSBits();
	
  clearcmdbuffer();
	snprintf(mediumbuffer, sizeof(mediumbuffer), "\n%s %s, %i bits edition\n(c) %s %s\n\n", PROJECT_NAME, PROJECT_VERSION, bits, PROJECT_YEAR, TEAM_NAME);
	print_colored_text(mediumbuffer, attr);
	fflush(stdout);
	
}
