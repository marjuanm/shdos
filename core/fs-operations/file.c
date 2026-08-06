/*
  shDOS - Command interpreter
  Original file name: configuration.c
  Copyright (C) 2026 Juan Manuel Mar Hdz.
  Licensed under GPL-3.0, see the license file on the root project structure for more information.
*/

/* Purpose: Check if executable file exists
	 Created date: 25/06/2026
   Created by username: Juan Manuel Mar Hdz.
   Last modified date: 25/06/2026
   Last modified username: Juan Manuel Mar Hdz.
	 Thanks to chatgpt
*/
int isExecutable(char command[MEDIUM_BUFFER])
{
	
	char *dot;
	
	//get command extension
	dot = strrchr(command, '.');

	if(dot &&
    (stricmp(dot, ".com") == 0 ||
    stricmp(dot, ".exe") == 0 ||
    stricmp(dot, ".bat") == 0))
      return TRUE;
	else
	  return FALSE;
	
}


/* 
  Purpose: Return folder from path
  Created date: 21/06/2026
  Created by username: Juan Manuel Mar Hdz.
  Last modified date: 22/06/2026
  Last modified username: Juan Manuel Mar Hdz.
*/
void getExePath(char *fullpath, char *path)
{
	
	char *p;

  memset(path, 0, LARGE_BUFFER);
	strncpy(path, fullpath, LARGE_BUFFER - 1);
	path[LARGE_BUFFER - 1] = '\0';

  p = strrchr(path, '\\');

  if(p != NULL)
    *(p + 1) = '\0';
  else
    path[0] = '\0';

}
