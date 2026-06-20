/*
  shDOS - Command interpreter
  Original file name: core.c
  Copyright (C) 2026 Juan Manuel Mar Hdz.
  Licensed under GPL-3.0, see the license file on the root project structure for more information.
*/

int pos = 0;
int firsttime = TRUE;
unsigned short original_attr, attr;
char command[MAX_BUFFER];

/* Purpose: Main cmd function
	 Created date: 08/06/2026
   Created by username: Juan Manuel Mar Hdz.
   Last modified date: 19/06/2026
   Last modified username: Juan Manuel Mar Hdz.
*/
void cmd()
{

  int ext;
	char c, buffer[MAX_BUFFER], tmp[2];

  original_attr = getOriginalCmdTextColor();
	attr = (BLACK << 4) | LIGHTGRAY;
	
	while(TRUE)
	{
		
		if(firsttime == TRUE)
		{
			
			memset(command, 0, MAX_BUFFER);  //clear command array
			firsttime = FALSE;
			showWelcome();

		}
    
		c = getch(); //capture user entry, char by char and autocomplete in next steps

    if(c == 9) // TAB
    {
        // autocompletar
    }
    else if(c == 13) // ENTER
    {
      
			//execute command
			
			if(stricmp(command, "exit") == 0)
			{
				
				cls();
				break;
				
			}
			else if(stricmp(command, "ver") == 0)
			  ver(attr);
			else if(stricmp(command, "cls") == 0)
			{
				
				clearcmdbuffer();
				fflush(stdout);
				cls();
				
			}
			else
			{
				
				snprintf(buffer, sizeof(buffer), "\nEl comando ingresado es: %s\nPresione cualquier tecla para continuar...\n", command);
				print_colored_text(buffer, attr);
				clearcmdbuffer();
				
				//ignore special keys
				/*while(TRUE)
				{
					
					if(c == 0 || c == 224)
					  ext = getch(); // consume second byte
					else
						break;
					
				}*/
				
				/* 
				  EXTRA PROTECTION HERE!
					If the user continues typing but the command is already full,
					we trap the remaining characters in a loop so they don't echo
					or wait on the keyboard, UNTIL ENTER is pressed (13).
				*/
				if(c != 13) 
				{
        
					while((ext = getch()) != 13) 
					{
            
						// If a special key (2 bytes) is pressed within the excess,
						// we also consume its second byte so as not to break the cycle.
            if(ext == 0 || ext == 224) 
							getch(); 
            
					}
					
					// We simulate that the current character 'c' is now ENTER (13)
					// so that the main loop knows that the user has finished.
					c = 13; 
    
				}
				
			}
			
    }
    else
    {
			
			//ignore special keys
			if(c == 0 || c == 224)
			{
		
				ext = getch();
				continue;
    
			}
			
			// add chars to command array, but prevent overflow
			if(pos < MAX_BUFFER - 1)
			{
        
				command[pos] = c;
        pos++;
				command[pos] = '\0';
				
				//colored putch(c);
			  tmp[0] = c;
			  tmp[1] = '\0';
			  print_colored_text(tmp, attr);
			
			}
			
		}
		
	}
	
	//restoreCmdTextColor(original_attr);

}

/* 
  Purpose: Show the welcome message
  Created date: 10/06/2026
  Created by username: Juan Manuel Mar Hdz.
  Last modified date: 19/06/2026
  Last modified username: Juan Manuel Mar Hdz.
	Thanks to chatgpt and gemini
*/
void showWelcome()
{
	
	char buffer[MAX_BUFFER];
	int attr = (BLUE << 4) | WHITE;
	int pos, columns = getCmdWidth();
	
	cls();
	
	fill_line(0, attr);
	snprintf(buffer, sizeof(buffer), "%s %s", PROJECT_NAME, PROJECT_VERSION);
	print_colored_text_xy(0, 0, buffer, attr);
	fflush(stdout);

	pos = columns - strlen("Type HELP = Help");
	print_colored_text_xy(pos, 0, "Type HELP = Help", attr);
  fflush(stdout);
	
	setCursorPosition(1, 2);
	snprintf(buffer, sizeof(buffer), "(C) %s %s", PROJECT_YEAR, TEAM_NAME);
	print_colored_text(buffer, (BLACK << 4) | WHITE);
	fflush(stdout);
	
	setCursorPosition(1, 4);
	
}

/* 
  Purpose: Clear command buffer
  Created date: 08/06/2026
  Created by username: Juan Manuel Mar Hdz.
  Last modified date: 10/06/2026
  Last modified username: Juan Manuel Mar Hdz.
*/
void clearcmdbuffer()
{
	
	pos = 0;
	memset(command, 0, MAX_BUFFER);
	
}

