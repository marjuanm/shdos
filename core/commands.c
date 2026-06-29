/*
  shDOS - Command interpreter
  Original file name: commands.c
  Copyright (C) 2026 Juan Manuel Mar Hdz.
  Licensed under GPL-3.0, see the license file on the root project structure for more information.
*/

/* Purpose: Show shdos version
	 Created date: 19/06/2026
   Created by username: Juan Manuel Mar Hdz.
   Last modified date: 29/06/2026
   Last modified username: Juan Manuel Mar Hdz.
	 Thanks to chatgpt
*/
void ver(unsigned short attr)
{

  int bits = getOSBits();
	
  clearcmdbuffer();
	snprintf(mediumbuffer, sizeof(mediumbuffer), "\n%s %s, %i bits edition\n\n", PROJECT_NAME, PROJECT_VERSION, bits);
	print_colored_text(mediumbuffer, attr);
	fflush(stdout);
	
}

/* Purpose: Execute command with parameters from os terminal
	 Created date: 25/06/2026
   Created by username: Juan Manuel Mar Hdz.
   Last modified date: 29/06/2026
   Last modified username: Juan Manuel Mar Hdz.
	 Thanks to chatgpt
*/
void executeCommand(char *command, char *args, unsigned short attr)
{
	
	FILE *fp;
	int ok =  FALSE, isCOM = FALSE;
	char *dot, exe[LARGE_BUFFER];
  
	memset(exe, 0, LARGE_BUFFER);
	strncpy(exe, currentpath, LARGE_BUFFER - 1);
	strcat(exe, command);
	
	if(isExecutable(exe) == TRUE)
	{
		
		dot = strrchr(exe, '.');
		
		if(dot && stricmp(dot, ".com") == 0)
		{

			if(getOSBits() == 32)
			  ok = FALSE;
			else
				ok = TRUE;
			
		}
		else
			ok = TRUE;

		if(ok == FALSE)
		  unsupportedComFile(attr);
		else
		{
			
			if(access(exe, 0) != 0)
				commandNotFound(attr);
			else
			{
				
				clearcmdbuffer();
				snprintf(mediumbuffer, sizeof(mediumbuffer), "\nEjecutable existe\n");
				print_colored_text(mediumbuffer, attr);
				fflush(stdout);

			}
			
		}
		
	}	
	else
	{
		
		dot = strrchr(exe, '.');
		
		if(!dot)
		{
		
			//check is .com file
			memset(exe, 0, LARGE_BUFFER);
			strncpy(exe, currentpath, LARGE_BUFFER - 1);
			strcat(exe, command);
			strcat(exe, ".com");
			
			if(access(exe, 0) == 0)
			{
				
				if(getOSBits() == 16)
					ok = TRUE;
				else
				{
					
					isCOM = TRUE;
					ok = FALSE;

				}
				
		  }
			else
			{
			
				//check is .exe file
				memset(exe, 0, LARGE_BUFFER);
				strncpy(exe, currentpath, LARGE_BUFFER - 1);
				strcat(exe, command);
			  strcat(exe, ".exe");
				
				if(access(exe, 0) != 0)
				{
					
					//check is .bat file
					memset(exe, 0, LARGE_BUFFER);
					strncpy(exe, currentpath, LARGE_BUFFER - 1);
					strcat(exe, command);
					strcat(exe, ".bat");
			
					if(access(exe, 0) == 0)
						ok = TRUE;
					else
						ok = FALSE;
					
				}
				else
					ok = TRUE;
				
			}
			
		}
		else
			ok = TRUE;
		
		if(ok == FALSE)
		{
			
			if(isCOM == TRUE)
				unsupportedComFile(attr);
			else
				invalidExecutable(attr);
			
		}
		else
		{
			
			if(access(exe, 0) != 0)
			{
				
CHECK_COM_16_BITS:
				
				dot = strrchr(exe, '.');
		
				if(dot && stricmp(dot, ".com") == 0)
				{

					if(getOSBits() == 16)
					{
						
						fp = fopen(exe, "rb");
						
						if(fp)
						{
							
							ok = TRUE;
							fclose(fp);
							
						}
						else
							ok = FALSE;
						
					}
					else
						ok = FALSE;
					
					if(ok == TRUE)
					{
						
						clearcmdbuffer();
						snprintf(mediumbuffer, sizeof(mediumbuffer), "\nEjecutable existe\n");
						print_colored_text(mediumbuffer, attr);
						fflush(stdout);

					}
					else
					  commandNotFound(attr);
					
				}
				else
					commandNotFound(attr);
				
			}
			else
			{
					
				dot = strrchr(exe, '.');
				
				if(dot && (stricmp(dot, ".com") == 0 && getOSBits() == 16))
					goto CHECK_COM_16_BITS;
				else
				{
					
					if(dot && 
				  (stricmp(dot, ".exe") == 0 || 
					stricmp(dot, ".bat") == 0))
					{
						
						clearcmdbuffer();
						snprintf(mediumbuffer, sizeof(mediumbuffer), "\nEjecutable existe\n");
						print_colored_text(mediumbuffer, attr);
						fflush(stdout);

					}
				  else
					  commandNotFound(attr);
				
				}
				
			}
			
		}
		
	}
	
}

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

/* Purpose: Show command not found message
	 Created date: 25/06/2026
   Created by username: Juan Manuel Mar Hdz.
   Last modified date: 29/06/2026
   Last modified username: Juan Manuel Mar Hdz.
	 Thanks to chatgpt
*/
void commandNotFound(unsigned short attr)
{
	
	clearcmdbuffer();
	
	if(separator == '\\')
  {
    
    if(getOSBits() == 16)
      snprintf(mediumbuffer, sizeof(mediumbuffer), "\nBad command or file name\n\n");
    else
      snprintf(mediumbuffer, sizeof(mediumbuffer), "\nEl comando enviado no se reconoce como un comando valido, programa o archivo por lotes ejecutable.\n\n");
    
  }
	else
    snprintf(mediumbuffer, sizeof(mediumbuffer), "\nCommand not found\n\n");

	print_colored_text(mediumbuffer, attr);
  fflush(stdout);

}

/* Purpose: Show invalid executable format file message
	 Created date: 25/06/2026
   Created by username: Juan Manuel Mar Hdz.
   Last modified date: 29/06/2026
   Last modified username: Juan Manuel Mar Hdz.
	 Thanks to chatgpt
*/
void invalidExecutable(unsigned short attr)
{
	
	clearcmdbuffer();
	snprintf(mediumbuffer, sizeof(mediumbuffer), "\nEl comando ejecutable debe de tener extension .com (16 bits), .exe o .bat\n\n");
	print_colored_text(mediumbuffer, attr);
  fflush(stdout);

}

/* Purpose: Show unsupported executable format message (.com files)
	 Created date: 25/06/2026
   Created by username: Juan Manuel Mar Hdz.
   Last modified date: 29/06/2026
   Last modified username: Juan Manuel Mar Hdz.
	 Thanks to chatgpt
*/
void unsupportedComFile(unsigned short attr)
{
	
	clearcmdbuffer();
	snprintf(mediumbuffer, sizeof(mediumbuffer), "\nLos ejecutables .COM no son compatibles con equipos de 64 bits.\n\n");
	print_colored_text(mediumbuffer, attr);
  fflush(stdout);

}
