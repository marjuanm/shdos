/*
  shDOS - Command interpreter
  Original file name: core.c
  Copyright (C) 2026 Juan Manuel Mar Hdz.
  Licensed under GPL-3.0, see the license file on the root project structure for more information.
*/

int firsttime = TRUE;
int currwidth, currheight;
int prevwidth, prevheight;


/* Purpose: Main cmd function
	 Created date: 08/06/2026
   Created by username: Juan Manuel Mar Hdz.
   Last modified date: 19/08/2026
   Last modified username: Juan Manuel Mar Hdz.
*/
void cmd(char *argv[])
{

  char *args;
  int c, running = TRUE;
  
	// set console start path
	
	getExePath(argv[0], currentpath);
	strcat(shellpath, currentpath);
	strcat(confpath, currentpath);
	strcat(confpath, "shdos.cfg");
	
	if(strcasecmp(shellpath, "/")	== 0)
		separator = '/';
	else
		separator = '\\';
	
	osbits = getOSBits();
	getOSFlavor(osflavor);
	
	// load configuration
	
	conf = getDefaultConfiguration();
	loadConfiguration();
	cls();
	
	//conf.consolebgcolor=RED;
	original_attr = getOriginalConsole();
	original_text_attr = getTextColor(original_attr);
	original_bg_attr = getBackgroundColor(original_attr);
	
	console_attr = (conf.consolebgcolor << 4) | conf.consoletextcolor;
	prompt_attr = (conf.consolebgcolor << 4) | conf.prompttextcolor;
	setConsoleColor((conf.consolebgcolor << 4) | conf.consoletextcolor);
	
	// load configuration	

  clearcmdbuffer();
	
	// process commands area

	while(running)
	{
		
		// welcome message to start
		if(firsttime == TRUE)
		{
			
			firsttime = FALSE;
			showWelcome();

		}

    c = readKey();

    switch(c)
    {

      case 13: // ENTER

        command[latestpos] = '\0';
				setCursorPosition(0, startY + getCommandRows());
				
				trim(command);
				args = strchr(command, ' '); // get command paramenters
				
				if(args != NULL)
				{
    
		      // prepare parameters to send
					*args = '\0';
					args++;
					trim(args);

				}
				
				if(strlen(command) > 0) running = executeCommand(command, args, console_attr);
				showPrompt();

        break;

      case 8: // BACKSPACE

        deleteCommandChar();
				updateCommandCursor();
				
				break;

      case KEY_LEFT:

        if(currpos > 0) currpos--;
				updateCommandCursor();
				
				break;

      case KEY_RIGHT:

        if(currpos<latestpos) currpos++;
				updateCommandCursor();
				
				break;

        case KEY_HOME:

        currpos = 0;
				updateCommandCursor();
				
				break;

      case KEY_END:

        currpos = latestpos;
				updateCommandCursor();
				
				break;

      default:

				if(c >= 32 && c < 127)
        {

          insertCommandChar((char)c);
					redrawCommand();

        }

				break;

		}
		
	}
	
	// process commands area
	
	cls();
	restoreConsole(original_attr);

}

/* 
  Purpose: Trim string
  Created date: 10/06/2026
  Created by username: Juan Manuel Mar Hdz.
  Last modified date: 17/08/2026
  Last modified username: Juan Manuel Mar Hdz.
	Thanks to chatgpt
*/
void trim(char *str)
{
	
	char *end;
	char *start = str;
  
	if(str == NULL || *str == '\0')
    return;

  start = str;

  while(*start && isspace((unsigned char)*start))
		start++;

  if(start != str)
    memmove(str, start, strlen(start) + 1);

  /* if empty string? */
  if(*str == '\0')
    return;

  end = str + strlen(str) - 1;

  /* remove spaces chars */
  while(end >= str && isspace((unsigned char)*end))
  {
    
    *end = '\0';
    end--;
    
	}
	
}

/* 
  Purpose: Show the welcome message
  Created date: 10/06/2026
  Created by username: Juan Manuel Mar Hdz.
  Last modified date: 17/08/2026
  Last modified username: Juan Manuel Mar Hdz.
	Thanks to chatgpt and gemini
*/
void showWelcome()
{
	
	int attr = (conf.headerbgcolor << 4) | conf.headertextcolor;
	int pos, columns = getWidth();
	char helpstr[SMALL_BUFFER];
	
	helpstr[0] = '\0';
  strncpy(helpstr, "Type HELP or press F1 = Help", SMALL_BUFFER - 1);
  helpstr[SMALL_BUFFER - 1] = '\0';
	
	cls();
	
	if(conf.showheader == 1)
	{
		
		if(conf.headertype == 1)
		{
			
			//write on first row
		  fill_line(0, attr);
		  snprintf(largebuffer, sizeof(largebuffer), "%s %s", PROJECT_NAME, PROJECT_VERSION);
		  print_colored_text_xy(0, 0, largebuffer, attr);
		  fflush(stdout);

		  pos = columns - strlen(helpstr);
		  print_colored_text_xy(pos, 0, helpstr, attr);
		  fflush(stdout);
		
	    //write on second row
		  setCursorPosition(0, 1);
		  snprintf(largebuffer, sizeof(largebuffer), "(c) %s %s", PROJECT_YEAR, TEAM_NAME);
		  print_colored_text(largebuffer, (conf.consolebgcolor << 4) | conf.headerhighttextcolor);
		  fflush(stdout);
	
	    //write on fourth row
	    setCursorPosition(0, 3);
	
		}
		else
		{
			
			//write on first row
		  setCursorPosition(0, 0);
		  snprintf(largebuffer, sizeof(largebuffer), "%s %s", PROJECT_NAME, PROJECT_VERSION);
		  print_colored_text(largebuffer, (conf.consolebgcolor << 4) | conf.consoletextcolor);
		  fflush(stdout);

		  //write on second row
		  setCursorPosition(0, 1);
		  snprintf(largebuffer, sizeof(largebuffer), "(c) %s %s", PROJECT_YEAR, TEAM_NAME);
		  print_colored_text(largebuffer, (conf.consolebgcolor << 4) | conf.consoletextcolor);
		  fflush(stdout);
	
	    //write on fourth row
	    setCursorPosition(0, 3);
			
		}	
		
	}
	else
	{
		
		//write on first row
		setCursorPosition(0, 0);
		
	}
	
	showPrompt();
	
}

/* 
  Purpose: Clear command buffer
  Created date: 08/06/2026
  Created by username: Juan Manuel Mar Hdz.
  Last modified date: 17/08/2026
  Last modified username: Juan Manuel Mar Hdz.
*/
void clearcmdbuffer()
{
	
	currpos = 0;
	latestpos = currpos;
	command[0] = '\0';
	
}
