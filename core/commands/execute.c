/*
  shDOS - Command interpreter
  Original file name: commands.c
  New file name: execute.c
  Copyright (C) 2026 Juan Manuel Mar Hdz.
  Licensed under GPL-3.0, see the license file on the root project structure for more information.
*/

/* Purpose: Execute command with parameters from os terminal
	 Created date: 25/06/2026
   Created by username: Juan Manuel Mar Hdz.
   Last modified date: 18/08/2026
   Last modified username: Juan Manuel Mar Hdz.
	 Thanks to chatgpt
*/
int executeCommand(char *command, char *args, unsigned short attr)
{
	
	FILE *fp;
	char *dot;
	int ok =  FALSE, isCOM = FALSE;
  
	exe[0] = '\0';
	strncpy(exe, currentpath, LARGE_BUFFER - 1);
	strcat(exe, command);
	
	// prepare parameters to run with exe
			
	if(stricmp(command, "dir") == 0)
	{
    
		if(args != NULL && *args != '\0')
		{
        
			if(strlen(args) == 2 && args[1] == ':')
        snprintf(syscommand, sizeof(syscommand), "%s \"%s\\\"", command, args);
			else
        snprintf(syscommand, sizeof(syscommand), "%s \"%s\"", command, args);
    
		}
		else
			snprintf(syscommand, sizeof(syscommand), "%s \"%s\"", command, currentpath);
			
	}
	else 
	{ 
		
		if(args != NULL && *args != '\0') 
			snprintf(syscommand, sizeof(syscommand), "%s %s", command, args); 
		else 
		{ 
			
			strncpy(syscommand, command, sizeof(syscommand) - 1); 
			syscommand[sizeof(syscommand) - 1] = '\0'; 
					
		} 
				
	}
			
	// prepare parameters to run with exe
					
	// check if is a internal command and execute from system function
	if(stricmp(command, "dir") == 0 || 
		stricmp(command, "md") == 0 || 
		stricmp(command, "mkdir") == 0 || 
		stricmp(command, "copy") == 0 || 
		stricmp(command, "del") == 0 || 
		stricmp(command, "erase") == 0 || 
		stricmp(command, "ren") == 0 || 
		stricmp(command, "rename") == 0 || 
		stricmp(command, "type") == 0 || 
		stricmp(command, "attrib") == 0 || 
		stricmp(command, "xcopy") == 0 || 
		stricmp(command, "date") == 0 || 
		stricmp(command, "time") == 0 || 
		stricmp(command, "ver") == 0 || 
		stricmp(command, "exit") == 0 || 
		stricmp(command, "cls") == 0 || 
		stricmp(command, "path") == 0 || 
		stricmp(command, "set") == 0 || 
		stricmp(command, "help") == 0 || 
		stricmp(command, "chkdsk") == 0 || 
		stricmp(command, "format") == 0 || 
		stricmp(command, "tree") == 0 || 
		stricmp(command, "fc") == 0 || 
		stricmp(command, "mode") == 0 || 
		stricmp(command, "choice") == 0 || 
		stricmp(command, "doskey") == 0 || 
		stricmp(command, "rem") == 0 || 
		stricmp(command, "echo") == 0 || 
		stricmp(command, "for") == 0 || 
		stricmp(command, "if") == 0 || 
		stricmp(command, "goto") == 0 || 
		stricmp(command, "call") == 0 || 
		stricmp(command, "pause") == 0
  )
	{
		
		if(stricmp(command, "exit") == 0) // exit command
			return 0;
		else if(stricmp(command, "cls") == 0) // cls command
		{
			
			cls();
			return 1; 
		
		}
		else if(stricmp(command, "ver") == 0) // ver command
		{
			
			ver(attr);
			return 1; 
		
		}
		else
		{
			
			//printf("comando=%s", syscommand);getchar();fflush(stdout);
			
			printf("\n");
			fflush(stdout);
			
			system(syscommand); // execute command
			fflush(stdout); // force to print command output
			
			printf("\n");
			clearcmdbuffer();
			
			return 1;
			
		}
					
	}
	else
	{
		
		// check external command type
		
		if(isExecutable(exe) == TRUE)
		{
		
			dot = strrchr(exe, '.');
		
		  // if file is a .com, 16 bits os then is valid, 32 bits is invalid format
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
			
			  // check if file exists, then run
				if(file_exists(exe) == FALSE)
					commandNotFound(attr);
				else
				{
				
					clearcmdbuffer();
					snprintf(mediumbuffer, sizeof(mediumbuffer), "\nComando externo existe\n");
					print_colored_text(mediumbuffer, attr);
					fflush(stdout);

				}
			
			}
		
		}	
		else
		{
		
			dot = strrchr(exe, '.');
		
			if(!dot) // the file not contain extension
			{
		
				//check is a .com file without extension
				exe[0] = '\0';
				strncpy(exe, currentpath, LARGE_BUFFER - 1);
				strcat(exe, command);
				strcat(exe, ".com");
			
				if(file_exists(exe) == TRUE)
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
			
					//check is .exe file without extension
					exe[0] = '\0';
					strncpy(exe, currentpath, LARGE_BUFFER - 1);
					strcat(exe, command);
					strcat(exe, ".exe");
				
					if(file_exists(exe) == FALSE)
					{
					
						//check is .bat file without extension
						exe[0] = '\0';
						strncpy(exe, currentpath, LARGE_BUFFER - 1);
						strcat(exe, command);
						strcat(exe, ".bat");
			
						if(file_exists(exe) == TRUE)
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
		
			if(ok == FALSE) // invalid file, but the .com files are valid on 16 bits system
			{
			
			  // file is not valid on the system (.com on 32 bits or invalid executable)
				if(isCOM == TRUE)
					unsupportedComFile(attr);
				else
					invalidExecutable(attr);
			
			}
			else
			{
			
				if(file_exists(exe) == FALSE)
				{
				
				  // check file type but without extension
					
CHECK_COM_16_BITS:
				
					dot = strrchr(exe, '.');
		
		      // .com files are valid on 16 bits os
					
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
							snprintf(mediumbuffer, sizeof(mediumbuffer), "\nEjecutable existe\n\n");
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
				
				  // only execute .com files on 16 bits system, then run
					
					if(dot && (stricmp(dot, ".com") == 0 && getOSBits() == 16))
						goto CHECK_COM_16_BITS;
					else
					{
					
						if(dot && 
							(stricmp(dot, ".exe") == 0 || 
							stricmp(dot, ".bat") == 0)
						)
						{
						
							clearcmdbuffer();
							snprintf(mediumbuffer, sizeof(mediumbuffer), "\nEjecutable existe\n\n");
							print_colored_text(mediumbuffer, attr);
							fflush(stdout);

						}
						else
							commandNotFound(attr);
				
					}
				
				}
			
			}
		
		}
		
		return 1;
		
	}
	
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
