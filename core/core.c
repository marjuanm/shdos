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
   Last modified date: 15/06/2026
   Last modified username: Juan Manuel Mar Hdz.
*/
void cmd()
{

  int ext;
	char c, buffer[128], tmp[2];

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
				
				clearcmdbuffer();
				fflush(stdout);
				clrsrc();
				
				break;
				
			}
			else if(stricmp(command, "ver") == 0)
			{
				
				clearcmdbuffer();
				sprintf(buffer, "\n%s %s\n", PROJECT_NAME, PROJECT_VERSION);
				print_colored_text(buffer, attr);
				fflush(stdout);
				
			}
			else if(stricmp(command, "cls") == 0)
			{
				
				clearcmdbuffer();
				fflush(stdout);
				clrsrc();
				
			}
			else
			{
				
				sprintf(buffer, "\nEl comando ingresado es: %s\nPresione cualquier tecla para continuar...\n", command);
				print_colored_text(buffer, attr);
				clearcmdbuffer();
				
				//ignore special keys
				while(TRUE)
				{
					
					if(c == 0 || c == 224)
					  ext = getch(); // consume second byte
					else
						break;
					
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
			
			// add chars to command array
			command[pos] = c;
			pos++;
			command[pos] = '\0';

			//colored putch(c);
			tmp[0] = c;
			tmp[1] = '\0';
			print_colored_text(tmp, attr);
			
		}
		
	}
	
	restoreCmdTextColor(original_attr);

}

/* 
  Purpose: Show the welcome message
  Created date: 10/06/2026
  Created by username: Juan Manuel Mar Hdz.
  Last modified date: 14/06/2026
  Last modified username: Juan Manuel Mar Hdz.
*/
void showWelcome()
{
	
	char buffer[128];
	int attr = (BLUE << 4) | WHITE;
	int pos, columns = getCmdWidth();
	
	clrsrc();
	
	fill_line(0, attr);
	sprintf(buffer, "%s %s", PROJECT_NAME, PROJECT_VERSION);
	print_colored_text_xy(0, 0, buffer, attr);
	fflush(stdout);

	pos = columns - strlen("Type HELP = Help");
	print_colored_text_xy(pos, 0, "Type HELP = Help", attr);
  fflush(stdout);
	
	setCursorPosition(1, 2);
	sprintf(buffer, "(C) %s %s", PROJECT_YEAR, TEAM_NAME);
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

