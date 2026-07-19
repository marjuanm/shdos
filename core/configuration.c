/*
  shDOS - Command interpreter
  Original file name: configuration.c
  Copyright (C) 2026 Juan Manuel Mar Hdz.
  Licensed under GPL-3.0, see the license file on the root project structure for more information.
*/

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
  Last modified date: 17/07/2026
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
	
	if(osbits == 16)
	{
		
		conf.consoletextcolor = LIGHTGRAY;      // default value
		conf.prompttextcolor = GREEN;						// default value
		
	}
	else
	{
		
		if(getOSMajorVersion() < 10)
		{
		
			conf.consoletextcolor = LIGHTGRAY;      // default value
			conf.prompttextcolor = GREEN;						// default value
		
		}
		else
		{
			
			conf.consoletextcolor = LIGHTGREEN;      // default value
			conf.prompttextcolor = LIGHTMAGENTA;		 // default value
			
		}
		
	}
	
	conf.usecmdthemes = 1;									// 1 = yes, 0 = false
	  
  memset(conf.promptlabel, 0, SMALL_BUFFER);
  strncpy(conf.promptlabel, "$p$g", sizeof(conf.promptlabel) - 1); // prompt like C:\>
	conf.promptlabel[sizeof(conf.promptlabel) - 1] = '\0';
  
	return conf;

}

/* 
  Purpose: Load shellDOS configuration from file
  Created date: 07/07/2026
  Created by username: Juan Manuel Mar Hdz.
  Last modified date: 08/07/2026
  Last modified username: Juan Manuel Mar Hdz.
*/
void loadConfiguration()
{
	
	int exists, itmp;
	FILE *fp = fopen(confpath, "r");
	
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
					itmp = (int)strtol(stmp, NULL, 16);
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
	//conf.consolebgcolor=4;conf.headerhighttextcolor=4;
	//patch if two colors in association are equals
	
	if(conf.headerbgcolor == conf.headertextcolor)
	{
		
		if(conf.headerbgcolor < 0 || conf.headerbgcolor > 15) conf.headerbgcolor = 0;
		conf.headertextcolor = getContrastColor(conf.headerbgcolor);
	
	}
	
	if(conf.consolebgcolor == conf.headerhighttextcolor)
	{
		
		if(conf.consolebgcolor < 0 || conf.consolebgcolor > 15) conf.consolebgcolor = 0;
		conf.headerhighttextcolor = getContrastColor(conf.consolebgcolor);
	
	}

}
