/*
  shDOS - Command interpreter
  Original file name: 32bits.c
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
	return 32;
}

/* Purpose: Return OS flavor
	 Created date: 15/07/2026
   Created by username: Juan Manuel Mar Hdz.
   Last modified date: 15/07/2026
   Last modified username: Juan Manuel Mar Hdz.
*/
void getOSFlavor(char *flavor)
{
	
	memset(flavor, 0, MEDIUM_BUFFER);

	if(separator == '\\')
		strncpy(flavor, "WINDOWS", MEDIUM_BUFFER - 1);
	else
		strncpy(flavor, "LINUX", MEDIUM_BUFFER - 1);
	
	flavor[MEDIUM_BUFFER - 1] = '\0';
	
}

/* Purpose: Return OS major version
	 Created date: 15/07/2026
   Created by username: Juan Manuel Mar Hdz.
   Last modified date: 17/07/2026
   Last modified username: Juan Manuel Mar Hdz.
	 Thanks to chatgpt and gemini
*/
int getOSMajorVersion()
{
	
	HKEY hKey;
	int version;
  LONG lResult;
	OSVERSIONINFO osvi;
	DWORD dwType, dwSize, dwMajorVersion;
	char szCurrentBuild[SMALL_BUFFER] = {0};
	char szCurrentVersion[SMALL_BUFFER] = {0};
	
  memset(&osvi, 0, sizeof(osvi));
  osvi.dwOSVersionInfoSize = sizeof(osvi);

  if(GetVersionEx(&osvi))
	{
		
		if((int)osvi.dwMajorVersion < 6)
		  return (int)osvi.dwMajorVersion; //work in Windows xp or minus
    else
		{
			
			lResult = RegOpenKeyExA(HKEY_LOCAL_MACHINE, "SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion", 0, KEY_READ, &hKey);

			if(lResult == ERROR_SUCCESS) 
			{
				
				dwType = REG_SZ;
				dwSize = sizeof(szCurrentVersion);
				lResult = RegQueryValueExA(hKey, "CurrentVersion", NULL, &dwType, (LPBYTE)szCurrentVersion, &dwSize);
    
				if(lResult == ERROR_SUCCESS)
				{
				
					if(strcmp(szCurrentVersion, "6.3") == 0) //Windows 8.1/10/11 
					{
				
						dwType = REG_DWORD;
            dwSize = sizeof(dwMajorVersion);
            lResult = RegQueryValueExA(hKey, "CurrentMajorVersionNumber", NULL, &dwType, (LPBYTE)&dwMajorVersion, &dwSize);
            
            if(lResult == ERROR_SUCCESS)
						{
							
							if(dwMajorVersion >= 10)
							{
								
								dwType = REG_SZ;
                dwSize = sizeof(szCurrentBuild);
                lResult = RegQueryValueExA(hKey, "CurrentBuildNumber", NULL, &dwType, (LPBYTE)szCurrentBuild, &dwSize);
                
                if(lResult == ERROR_SUCCESS) 
								{
									
									int buildNumber = atoi(szCurrentBuild);

									if(buildNumber >= 22000)
										version = 11; // Windows 11
									else
										version = 10; // Windows 10
                
								}
								else
									version = 6;
								
							}
							else
								version = 6;
							
						}
						else
							version = 6;
						
					}
					else
						version = 6;
				}
				else
				  version = 6;
			}
			else
				version = 6;
				
			RegCloseKey(hKey);
			return version;
			
		}
		
	}
  else
    return 0;

  return 0;
	
}

/* Purpose: Return OS minor version
	 Created date: 15/07/2026
   Created by username: Juan Manuel Mar Hdz.
   Last modified date: 17/07/2026
   Last modified username: Juan Manuel Mar Hdz.
	 Thanks to chatgpt and gemini
*/
int getOSMinorVersion()
{
	
	HKEY hKey;
  LONG lResult;
	int version;
  OSVERSIONINFO osvi;
  DWORD dwType, dwSize;
  char szCurrentVersion[SMALL_BUFFER] = {0};

  memset(&osvi, 0, sizeof(osvi));
  osvi.dwOSVersionInfoSize = sizeof(osvi);

  if(GetVersionEx(&osvi))
  {
		
		if((int)osvi.dwMajorVersion < 6)
		  return (int)osvi.dwMinorVersion; //work on Windows xp or minus
    else
    {
			
			lResult = RegOpenKeyExA(HKEY_LOCAL_MACHINE, "SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion", 0, KEY_READ, &hKey);
      
      if(lResult == ERROR_SUCCESS)
      {
				
				dwType = REG_SZ;
        dwSize = sizeof(szCurrentVersion);
        
				lResult = RegQueryValueExA(hKey, "CurrentVersion", NULL, &dwType, (LPBYTE)szCurrentVersion, &dwSize);
        
        if(lResult == ERROR_SUCCESS)
        {
					
					if(strcmp(szCurrentVersion, "6.3") == 0) 
            version = 0; //Windows 10/11
					else if(strcmp(szCurrentVersion, "6.2") == 0)
            version = 2; // Windows 8
					else if(strcmp(szCurrentVersion, "6.1") == 0)
            version = 1; // Windows 7
          else
            version = 0; // Windows Vista (6.0)
					
				}
				else
          version = (int)osvi.dwMinorVersion;
                
      }
			else
        version = (int)osvi.dwMinorVersion;
      
			RegCloseKey(hKey);
			return version;
			
    }
    
	}
	else
		return 0;
	
	return 0;
	
}

