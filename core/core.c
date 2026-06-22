/*
  shDOS - Command interpreter
  Original file name: core.c
  Copyright (C) 2026 Juan Manuel Mar Hdz.
  Licensed under GPL-3.0, see the license file on the root project structure for more information.
*/

int pos = 0;
int firsttime = TRUE;
struct CONFIGURATION conf;
unsigned short original_attr, attr;
char value[MAX_BUFFER], stmp[MAX_BUFFER];
char command[MAX_BUFFER], currentpath[MAX_BUFFER];
char buffer[MAX_BUFFER], line[MAX_BUFFER], tmp[2];
	
/* Purpose: Main cmd function
	 Created date: 08/06/2026
   Created by username: Juan Manuel Mar Hdz.
   Last modified date: 21/06/2026
   Last modified username: Juan Manuel Mar Hdz.
*/
void cmd(char *argv[])
{

  FILE *fp;
	char c;
	int ext, exists, itmp;
	
	// read shdos.cfg, if not exists then create by default

  getExePath(argv[0], currentpath);
	strcat(currentpath, "shdos.cfg");
	fp = fopen("shdos.cfg", "r");
	conf = getDefaultCmdConfiguration();
	
	if(fp != NULL)
  {
		
		//load configuration from shdos.cfg, every line start with key=value
		while(fgets(line, MAX_BUFFER, fp) != NULL)
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
					
					getCorrectValueToLoad(value, stmp);
					
					if(strcasecmp(stmp, "1")	== 0 || strcasecmp(stmp, "2") == 0) 
						conf.headertype = itmp;
					
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
					itmp = (int)strtol(value, NULL, 16);
					if(itmp >= BLACK && itmp <= WHITE) conf.headertextcolor = itmp;
					
				}
				
			}
			
			if(strncasecmp(line, "consolebgcolor=", strlen("consolebgcolor=")) == 0) 
			{
				
				getValueFromKey(line, value);
				
				if(value != NULL) 
				{
					
					getCorrectValueToLoad(value, stmp);
					itmp = (int)strtol(value, NULL, 16);
					if(itmp >= BLACK && itmp <= WHITE) conf.consolebgcolor = itmp;
					
				}
				
			}
			
			if(strncasecmp(line, "consoletextcolor=", strlen("consoletextcolor=")) == 0) 
			{
				
				getValueFromKey(line, value);
				
				if(value != NULL) 
				{
					
					getCorrectValueToLoad(value, stmp);
					itmp = (int)strtol(value, NULL, 16);
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
					
					memset(conf.promptlabel, 0, MAX_BUFFER);
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
		
		printf("Archivo no encontrado, ha sido creado con valores predeterminados...");
		fflush(stdout);
		
		fp = fopen("shdos.cfg", "w");
		
		if(conf.showheader == 1)
			fprintf(fp, "showheader=yes\n");
		else
			fprintf(fp, "showheader=no\n");
		
    fprintf(fp, "headertype=%d\n", conf.headertype);
    fprintf(fp, "headerbgcolor=%X\n", conf.headerbgcolor);
    fprintf(fp, "headertextcolor=%X\n", conf.headertextcolor);
    fprintf(fp, "consolebgcolor=%X\n", conf.consolebgcolor);
    fprintf(fp, "consoletextcolor=%X\n", conf.consoletextcolor);
    fprintf(fp, "prompttextcolor=%X\n", conf.prompttextcolor);
		
		if(conf.usecmdthemes == 1)
			fprintf(fp, "usecmdthemes=yes ;work only with Windows 10 or superior\n");
		else
			fprintf(fp, "usecmdthemes=no ;work only with Windows 10 or superior\n");
		
		fprintf(fp, "promptlabel=%s\n", conf.promptlabel);

    fclose(fp);
		cls();
		
	}
	
	// read shdos.cfg, if not exists then create by default
	
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
	
	restoreCmdTextColor(original_attr);

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

/* 
  Purpose: Return folder from path
  Created date: 21/06/2026
  Created by username: Juan Manuel Mar Hdz.
  Last modified date: 21/06/2026
  Last modified username: Juan Manuel Mar Hdz.
*/
void getExePath(char *fullpath, char *path)
{
	
	char *p;

  memset(path, 0, MAX_BUFFER);
	strncpy(path, fullpath, MAX_BUFFER - 1);
	path[MAX_BUFFER - 1] = '\0';

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
  Last modified date: 21/06/2026
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

	memset(val, 0, MAX_BUFFER);
  strncpy(val, p, MAX_BUFFER - 1);
  val[MAX_BUFFER - 1] = '\0';

}

/* 
  Purpose: Return value from string in correct format (convert yes and on to 1, no, off to 0)
  Created date: 21/06/2026
  Created by username: Juan Manuel Mar Hdz.
  Last modified date: 21/06/2026
  Last modified username: Juan Manuel Mar Hdz.
*/
void getCorrectValueToLoad(char *stream, char *value)
{
	
	memset(value, 0, MAX_BUFFER);
	
	if(value != NULL) 
	{
		
	  if(
			strcasecmp(value, "1") == 0 ||
			strcasecmp(value, "yes") == 0 ||
			strcasecmp(value, "on") == 0
		)
    {
		
			strncpy(value, "1", MAX_BUFFER - 1);
			value[MAX_BUFFER - 1] = '\0';

		}
		else
		{
			
			if(
				strcasecmp(value, "0") == 0 ||
				strcasecmp(value, "no") == 0 ||
				strcasecmp(value, "off") == 0
			)
			{
		
				strncpy(value, "0", MAX_BUFFER - 1);
				value[MAX_BUFFER - 1] = '\0';

			}
			else
			{
		
				strncpy(value, stream, MAX_BUFFER - 1);
				value[MAX_BUFFER - 1] = '\0';

			}
			
		}
		
	}
	else
		value[0] = '\0';
	
}
