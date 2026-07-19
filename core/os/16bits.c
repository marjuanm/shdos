/*
  shDOS - Command interpreter
  Original file name: 16bits.c
  Copyright (C) 2026 Juan Manuel Mar Hdz.
  Licensed under GPL-3.0, see the license file on the root project structure for more information.
*/

/* Purpose: Return OS bit number
	 Created date: 25/06/2026
   Created by username: Juan Manuel Mar Hdz.
   Last modified date: 25/06/2026
   Last modified username: Juan Manuel Mar Hdz.
*/
int getOSBits()
{
	return 16;
}

/* Purpose: Return OS flavor
	 Created date: 15/07/2026
   Created by username: Juan Manuel Mar Hdz.
   Last modified date: 15/07/2026
   Last modified username: Juan Manuel Mar Hdz.
	 Thanks to chatgpt
*/
void getOSFlavor(char *flavor)
{
  
  union REGS r;

  memset(flavor, 0, MEDIUM_BUFFER);

  r.x.ax = 0x1600;
  int86(0x2F, &r, &r);

  if((r.h.al != 0) && (r.h.al != 0x80))
    strncpy(flavor, "WINDOWS", MEDIUM_BUFFER - 1);
  else
    strncpy(flavor, "DOS", MEDIUM_BUFFER - 1);
  
	flavor[MEDIUM_BUFFER - 1] = '\0';

}

/* Purpose: Return OS major version
	 Created date: 15/07/2026
   Created by username: Juan Manuel Mar Hdz.
   Last modified date: 17/07/2026
   Last modified username: Juan Manuel Mar Hdz.
	 Thanks to chatgpt
*/
int getOSMajorVersion()
{
	
	union REGS r;
	char osflavor[MEDIUM_BUFFER];
	
	if(osflavor[0] == '\0')
		getOSFlavor(osflavor);
	
	if(stricmp(osflavor, "WINDOWS") != 0 && stricmp(osflavor, "LINUX") != 0)
		return 0;
	else
	{
		
		r.x.ax = 0x1600;
    int86(0x2F, &r, &r);

    switch(r.h.al)
    {
			
			case 0x00:

				return 0; // unknown or DOS
				break;
				
			case 0x80:
			
				return 0; // DOS
				break;
				
			case 0x01:
        
				return 2; // Windows 2.x
				break;
				
			case 0x02:
			
				return 3; // Windows 3.x
				break;
				
			case 0x03:
        
				return 3; // Windows 3.x
				break;
				
			case 0x04:
        
				return 4; // Windows 9.x
				break;
				
			default:
			
				return 0; // unknown or DOS
				break;
				
    }
		
	}
	
}

/* Purpose: Return OS minor version
	 Created date: 15/07/2026
   Created by username: Juan Manuel Mar Hdz.
   Last modified date: 17/07/2026
   Last modified username: Juan Manuel Mar Hdz.
	 Thanks to chatgpt
*/
int getOSMinorVersion()
{
	
	union REGS r;
	char osflavor[MEDIUM_BUFFER];
	
	if(osflavor[0] == '\0')
		getOSFlavor(osflavor);
	
	if(stricmp(osflavor, "WINDOWS") != 0 && stricmp(osflavor, "LINUX") != 0)
		return 0;
	else
	{
		
		r.x.ax = 0x160A;
    int86(0x2F, &r, &r);
		
		return r.h.bl;
		
  }
	
}
