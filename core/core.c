/*
  shDOS - Command interpreter
  Original file name: core.c
  Copyright (C) 2026 Juan Manuel Mar Hdz.
  Licensed under GPL-3.0, see the license file on the root project structure for more information.
 */

int pos = 0;
int firsttime = TRUE;
char command[MAX_BUFFER];

/* Purpose: Main cmd function
	 Created date: 08/06/2026
   Created by username: Juan Manuel Mar Hdz.
   Last modified date: 08/06/2026
   Last modified username: Juan Manuel Mar Hdz.
*/
void cmd()
{

  int ext;
	char c;

	while(TRUE)
	{
		
		if(firsttime == TRUE)
		{
			
			memset(command, 0, MAX_BUFFER);  //clear command array
			firsttime = FALSE;
			
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
				printf("Ingresado exit");
				break;
				
			}
			else
			{
				
				printf("\nEl comando ingresado es: %s\nPresione cualquier tecla para continuar...\n", command);
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

			putch(c);
			
		}
		
	}

}

/* 
  Purpose: Clear command buffer
  Created date: 08/06/2026
  Created by username: Juan Manuel Mar Hdz.
  Last modified date: 08/06/2026
  Last modified username: Juan Manuel Mar Hdz.
*/
void clearcmdbuffer()
{
	
	pos = 0;
	firsttime = TRUE;
	memset(command, 0, MAX_BUFFER);
	
}
