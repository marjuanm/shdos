/*
  shDOS - Command interpreter
  Original file name: core.c
  Copyright (C) 2026 Juan Manuel Mar Hdz.
  Licensed under GPL-3.0, see the license file on the root project structure for more information.
*/

int pos = 0;
int firsttime = TRUE;
struct CONFIGURATION conf;
char command[MEDIUM_BUFFER];
char line[SMALL_BUFFER], tmp[2];
char value[SMALL_BUFFER], stmp[SMALL_BUFFER];

/* Purpose: Main cmd function
	 Created date: 08/06/2026
   Created by username: Juan Manuel Mar Hdz.
   Last modified date: 05/07/2026
   Last modified username: Juan Manuel Mar Hdz.
*/
void cmd(char *argv[])
{

  FILE *fp;
	char c, *args;
	int ext, exists, itmp;
	
	// read shdos.cfg, if not exists then create by default

  getExePath(argv[0], currentpath);
	
	strcat(shellpath, currentpath);
	strcat(confpath, currentpath);
	strcat(confpath, "shdos.cfg");
	
	if(strcasecmp(shellpath, "/")	== 0)
		separator = '/';
	else
		separator = '\\';
	
	fp = fopen(confpath, "r");
	conf = getDefaultConfiguration();
	
	if(fp != NULL)
  {
		
		//load configuration from shdos.cfg, every line start with key=value
		while(fgets(line, SMALL_BUFFER, fp) != NULL)
	  {
			
			line[strcspn(line, "\r\n")] = '\0';
		  
			if(strncasecmp(line, "showheader=", strlen("showheader=")) == 0) 
			{
				
				getValueFromKey(line, value);
				
				if(value != NULL) 
				{
					
					getCorrectValueToLoad(value, stmp);
					
					if(strcasecmp(stmp, "1")	== 0 || strcasecmp(stmp, "0") == 0) 
						conf.showheader = atoi(stmp);
					
				}
				
			}
			
			if(strncasecmp(line, "headertype=", strlen("headertype=")) == 0) 
			{
				
				getValueFromKey(line, value);
				
				if(value != NULL) 
				{

					if(strcasecmp(value, "1")	== 0 || strcasecmp(value, "2") == 0) 
						conf.headertype = atoi(value);
					
				}
				
			}
			
			if(strncasecmp(line, "headerbgcolor=", strlen("headerbgcolor=")) == 0) 
			{
				
				getValueFromKey(line, value);
				
				if(value != NULL) 
				{
					
					getCorrectValueToLoad(value, stmp);
					itmp = (int)strtol(stmp, NULL, 16);
					if(itmp >= BLACK && itmp <= WHITE) conf.headerbgcolor = itmp;
					
				}
				
			}
			
			if(strncasecmp(line, "headertextcolor=", strlen("headertextcolor=")) == 0) 
			{
				
				getValueFromKey(line, value);
				
				if(value != NULL) 
				{
					
					getCorrectValueToLoad(value, stmp);
					itmp = (int)strtol(stmp, NULL, 16);
					if(itmp >= BLACK && itmp <= WHITE) conf.headertextcolor = itmp;
					
				}
				
			}
			
			if(strncasecmp(line, "headerhighttextcolor=", strlen("headerhighttextcolor=")) == 0) 
			{
				
				getValueFromKey(line, value);
				
				if(value != NULL) 
				{
					
					getCorrectValueToLoad(value, stmp);
					itmp = (int)strtol(stmp, NULL, 16);
					if(itmp >= BLACK && itmp <= WHITE) conf.headerhighttextcolor = itmp;
					
				}
				
			}
			
			if(strncasecmp(line, "consolebgcolor=", strlen("consolebgcolor=")) == 0) 
			{
				
				getValueFromKey(line, value);
				
				if(value != NULL) 
				{
					
					getCorrectValueToLoad(value, stmp);
					itmp = (int)strtol(stmp, NULL, 16);
					if(itmp >= BLACK && itmp <= WHITE) conf.consolebgcolor = itmp;
					
				}
				
			}
			
			if(strncasecmp(line, "consoletextcolor=", strlen("consoletextcolor=")) == 0) 
			{
				
				getValueFromKey(line, value);
				
				if(value != NULL) 
				{
					
					getCorrectValueToLoad(value, stmp);
					itmp = (int)strtol(stmp, NULL, 16);
					if(itmp >= BLACK && itmp <= WHITE) conf.consoletextcolor = itmp;
					
				}
				
			}
			
			if(strncasecmp(line, "prompttextcolor=", strlen("prompttextcolor=")) == 0) 
			{
				
				getValueFromKey(line, value);
				
				if(value != NULL) 
				{
					
					getCorrectValueToLoad(value, stmp);
					if(itmp >= BLACK && itmp <= WHITE) conf.prompttextcolor = itmp;
					
				}
				
			}
			
			if(strncasecmp(line, "promptlabel=", strlen("promptlabel=")) == 0) 
			{
				
				getValueFromKey(line, value);
				
				if(value != NULL) 
				{
					
					getCorrectValueToLoad(value, stmp);
					
					memset(conf.promptlabel, 0, SMALL_BUFFER);
					strncpy(conf.promptlabel, stmp, sizeof(conf.promptlabel) - 1);
					conf.promptlabel[sizeof(conf.promptlabel) - 1] = '\0';
					
				}
				
			}
				
		}

		fclose(fp);
    exists = TRUE;

	}
	else
	  exists = FALSE;

	//create configuration file
	if(exists == FALSE)
	{
		
		//printf("Archivo no encontrado, ha sido creado con valores predeterminados...");
		//fflush(stdout);
		
		fp = fopen(confpath, "w");
	
    //if not fail then write on the created file (fail to write on cdrom by example)	
		if(fp != NULL)
		{
			
			if(conf.showheader == 1)
				fprintf(fp, "showheader=yes\n");
			else
				fprintf(fp, "showheader=no\n");
		
			fprintf(fp, "headertype=%d\n", conf.headertype);
			fprintf(fp, "headerbgcolor=%X\n", conf.headerbgcolor);
			fprintf(fp, "headertextcolor=%X\n", conf.headertextcolor);
			fprintf(fp, "headerhighttextcolor=%X\n", conf.headerhighttextcolor);
			fprintf(fp, "consolebgcolor=%X\n", conf.consolebgcolor);
			fprintf(fp, "consoletextcolor=%X\n", conf.consoletextcolor);
			fprintf(fp, "prompttextcolor=%X\n", conf.prompttextcolor);
		
			if(conf.usecmdthemes == 1)
				fprintf(fp, "usecmdthemes=yes ;work only with Windows 10 or superior\n");
			else
				fprintf(fp, "usecmdthemes=no ;work only with Windows 10 or superior\n");
		
			fprintf(fp, "promptlabel=%s\n", conf.promptlabel);

		  fclose(fp);
			
		}
		
		cls();
		
	}
	
	// read shdos.cfg, if not exists then create by default

	setPromptBuffer();
	
	// process commands area
	
	original_attr = getOriginalCmdTextColor();
	global_attr = (BLACK << 4) | LIGHTGRAY;
	
	while(TRUE)
	{
		
		if(firsttime == TRUE)
		{
			
			memset(command, 0, MEDIUM_BUFFER);  //clear command array
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
			
			trim(command);
			args = strchr(command, ' ');
			
			if(args)
			{
    
				*args = '\0';  // split command and args
				args++;        // args
				
			}
			
			if(stricmp(command, "exit") == 0)
			{
				
				cls();
				break;
				
			}
			else if(stricmp(command, "ver") == 0)
			{
				
				ver(global_attr);
				drawPrompt();
				
			}
			else if(stricmp(command, "cls") == 0)
			{
				
				cls();
				drawPrompt();
				
			}
			else if(stricmp(command, "cd") == 0 || stricmp(command, "chdir") == 0)
			{
				
				executeCommand(command, NULL, global_attr);
				drawPrompt();
				
			}
			else if(stricmp(command, "dir") == 0)
			{
				
				executeCommand(command, NULL, global_attr);
				drawPrompt();
				
			}
			else if(stricmp(command, "md") == 0 || stricmp(command, "mkdir") == 0)
			{
				
				executeCommand(command, NULL, global_attr);
				drawPrompt();
				
			}
			else if(stricmp(command, "rd") == 0 || stricmp(command, "rmdir") == 0)
			{
				
				executeCommand(command, NULL, global_attr);
				drawPrompt();
				
			}
			else if(stricmp(command, "copy") == 0)
			{
				
				executeCommand(command, NULL, global_attr);
				drawPrompt();
				
			}
			else if(stricmp(command, "del") == 0 || stricmp(command, "erase") == 0)
			{
				
				executeCommand(command, NULL, global_attr);
				drawPrompt();
				
			}
			else if(stricmp(command, "ren") == 0 || stricmp(command, "rename") == 0)
			{
				
				executeCommand(command, NULL, global_attr);
				drawPrompt();
				
			}
			else if(stricmp(command, "type") == 0)
			{
				
				executeCommand(command, NULL, global_attr);
				drawPrompt();
				
			}
			else if(stricmp(command, "date") == 0)
			{
				
				executeCommand(command, NULL, global_attr);
				drawPrompt();
				
			}
			else if(stricmp(command, "time") == 0)
			{
				
				executeCommand(command, NULL, global_attr);
				drawPrompt();
				
			}
			else if(stricmp(command, "prompt") == 0)
			{
				
				executeCommand(command, NULL, global_attr);
				drawPrompt();
				
			}
			else if(stricmp(command, "vol") == 0)
			{
				
				executeCommand(command, NULL, global_attr);
				drawPrompt();
				
			}
			else if(stricmp(command, "truename") == 0)
			{
				
				executeCommand(command, NULL, global_attr);
				drawPrompt();
				
			}
			else
			{
				
				//process external commands
				if(args == NULL || *args == '\0')
					executeCommand(command, NULL, global_attr);
				else
					executeCommand(command, args, global_attr);
				
				drawPrompt();
				
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
							ext = getch(); 
            
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
			if(pos < MEDIUM_BUFFER - 2)
			{
        
				command[pos] = c;
        pos++;
				command[pos] = '\0';
				
				//colored putch(c);
			  tmp[0] = c;
			  tmp[1] = '\0';
			  print_colored_text(tmp, global_attr);
			
			}
			
		}
		
	}
	
	// process commands area
	
	restoreCmdTextColor(original_attr);

}

/* 
  Purpose: Trim string
  Created date: 10/06/2026
  Created by username: Juan Manuel Mar Hdz.
  Last modified date: 24/06/2026
  Last modified username: Juan Manuel Mar Hdz.
	Thanks to chatgpt
*/
void trim(char *str)
{
	
	char *start = str;
  char *end;

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
  Last modified date: 05/07/2026
  Last modified username: Juan Manuel Mar Hdz.
	Thanks to chatgpt and gemini
*/
void showWelcome()
{
	
	int attr = (conf.headerbgcolor << 4) | conf.headertextcolor;
	int pos, columns = getWidth();
	char helpstr[SMALL_BUFFER];
	
	memset(helpstr, 0, SMALL_BUFFER);
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
		  setCursorPosition(1, 2);
		  snprintf(largebuffer, sizeof(largebuffer), "(c) %s %s", PROJECT_YEAR, TEAM_NAME);
		  print_colored_text(largebuffer, (BLACK << 4) | conf.headerhighttextcolor);
		  fflush(stdout);
	
	    //write on fourth row
	    setCursorPosition(1, 4);
	
		}
		else
		{
			
			//write on first row
		  setCursorPosition(1, 1);
		  snprintf(largebuffer, sizeof(largebuffer), "%s %s", PROJECT_NAME, PROJECT_VERSION);
		  print_colored_text(largebuffer, (BLACK << 4) | LIGHTGRAY);
		  fflush(stdout);

		  //write on second row
		  setCursorPosition(1, 2);
		  snprintf(largebuffer, sizeof(largebuffer), "(c) %s %s", PROJECT_YEAR, TEAM_NAME);
		  print_colored_text(largebuffer, (BLACK << 4) | LIGHTGRAY);
		  fflush(stdout);
	
	    //write on fourth row
	    setCursorPosition(1, 4);
	
		}	
		
	}
	
	drawPrompt();

}

/* 
  Purpose: Clear command buffer
  Created date: 08/06/2026
  Created by username: Juan Manuel Mar Hdz.
  Last modified date: 22/06/2026
  Last modified username: Juan Manuel Mar Hdz.
*/
void clearcmdbuffer()
{
	
	pos = 0;
	memset(command, 0, MEDIUM_BUFFER);
	
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

/* 
  Purpose: Return value from string in key=value format
  Created date: 21/06/2026
  Created by username: Juan Manuel Mar Hdz.
  Last modified date: 22/06/2026
  Last modified username: Juan Manuel Mar Hdz.
*/
void getValueFromKey(char *stream, char *val)
{
	
	char *p;

  //ignore full comments
	if(stream[0] == ';' || stream[0] == '#')
  {
		
		val[0] = '\0';
    return;
    
	}
	
	//ignore comments section on the line, the line is truncate at found ; or #
	p = strpbrk(stream, ";#");
  if(p != NULL) *p = '\0';
	
	//extract value at found '=' on the line
	
	p = strchr(stream, '=');
  
	//no value found to line
	if(p == NULL)
  {
		
		val[0] = '\0';
    return;
    
	}
	
	//copy the value section
	p++;
	while(*p == ' ' || *p == '\t') p++;

	memset(val, 0, SMALL_BUFFER);
  strncpy(val, p, SMALL_BUFFER - 1);
  val[SMALL_BUFFER - 1] = '\0';

}

/* 
  Purpose: Return value from string in correct format (convert yes and on to 1, no, off to 0)
  Created date: 21/06/2026
  Created by username: Juan Manuel Mar Hdz.
  Last modified date: 05/07/2026
  Last modified username: Juan Manuel Mar Hdz.
*/
void getCorrectValueToLoad(char *stream, char *val)
{

	if(strcasecmp(stream, "1") == 0 ||
    strcasecmp(stream, "yes") == 0 ||
    strcasecmp(stream, "on") == 0)
		{
			
			strcpy(val, "1");
			val[SMALL_BUFFER - 1] = '\0';
			
		}
	else if (strcasecmp(stream, "0") == 0 ||
    strcasecmp(stream, "no") == 0 ||
    strcasecmp(stream, "off") == 0)
		{
			
			strcpy(val, "0");
			val[SMALL_BUFFER - 1] = '\0';
			
		}
	else
	{
    
		strncpy(val, stream, SMALL_BUFFER - 1);
    val[SMALL_BUFFER - 1] = '\0';

	}
	
}

/* 
  Purpose: Return default shellDOS configuration
  Created date: 08/06/2026
  Created by username: Juan Manuel Mar Hdz.
  Last modified date: 05/07/2026
  Last modified username: Juan Manuel Mar Hdz.
*/
struct CONFIGURATION getDefaultConfiguration()
{
	
	struct CONFIGURATION conf;
    
  conf.showheader = 1;                    // 1 = yes, 0 = false
  conf.headertype = 1;                    // 1 = full (version + help and copyright in new row), 2 = version + copyright in 2 rows
  conf.headerbgcolor = BLUE;              // default value    
  conf.headertextcolor = WHITE;           // default value
  conf.headerhighttextcolor = WHITE;			// default value
	conf.consolebgcolor = BLACK;            // default value
  conf.consoletextcolor = WHITE;          // default value
  conf.prompttextcolor = GREEN;           // default value
	conf.usecmdthemes = 1;									//1 = yes, 0 = false
    
  memset(conf.promptlabel, 0, SMALL_BUFFER);
  strncpy(conf.promptlabel, "$p$g", sizeof(conf.promptlabel) - 1); // prompt like C:\>
	conf.promptlabel[sizeof(conf.promptlabel) - 1] = '\0';
  
	return conf;

}

