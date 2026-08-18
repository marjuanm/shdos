/*
  shDOS - Command interpreter
  Original file name: configuration.c
  New file name: file.c
  Copyright (C) 2026 Juan Manuel Mar Hdz.
  Licensed under GPL-3.0, see the license file on the root project structure for more information.

  This file contains portions derived from and reimplemented based on
  Scryvano project https://github.com/marjuanm/scryvano/blob/main/core/fs-operations/file.c
 
  The original source is licensed under the General Public License version 3 (GPL-3). 
	Portions derived from the original work have been modified and incorporated into ShellDOS project.
 
  Copyright notices and attribution for the original work are retained where applicable.
  Thanks to the Scryvano project and its contributors for their work and reference implementation.
  https://github.com/marjuanm/scryvano
*/

/* Purpose: Check if file is executable
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
  Last modified date: 15/08/2026
  Last modified username: Juan Manuel Mar Hdz.
*/
void getExePath(char *fullpath, char *path)
{
	
	char *p;

  path[0] = '\0';
	strncpy(path, fullpath, LARGE_BUFFER - 1);
	path[LARGE_BUFFER - 1] = '\0';

  p = strrchr(path, '\\');

  if(p != NULL)
    *(p + 1) = '\0';
  else
    path[0] = '\0';

}

/* 
  Purpose: Return flag file exists
  Created date: 13/08/2026
  Created by username: Juan Manuel Mar Hdz.
  Last modified date: 13/08/2026
  Last modified username: Juan Manuel Mar Hdz.
*/
int file_exists(char *fullpath) 
{

	if(access(fullpath, F_OK) == 0)
    return TRUE;
	else
	  return FALSE;

}
