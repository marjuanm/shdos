/*
  shDOS - Command interpreter
  Original file name: colors.c
  Copyright (C) 2026 Juan Manuel Mar Hdz.
  Licensed under GPL-3.0, see the license file on the root project structure for more information.
*/

/* 
  Purpose: Get contrast color
  Created date: 07/07/2026
  Created by username: Juan Manuel Mar Hdz.
  Last modified date: 07/07/2026
  Last modified username: Juan Manuel Mar Hdz.
	Thanks to gemini
*/
int getContrastColor(int color)
{
	
	int ccolor = 0;
	
	switch(color)
	{
			
		case BLACK:
				
			ccolor = WHITE;
			break;
				
		case BLUE:
				
			ccolor = WHITE;
			break;
				
		case GREEN:
				
			ccolor = WHITE;
			break;
			
		case CYAN:
				
			ccolor = BLACK;
			break;
				
		case RED:
				
			ccolor = WHITE;
			break;	
				
		case MAGENTA:
				
			ccolor = WHITE;
			break;	
				
		case BROWN:
				
			ccolor = WHITE;
			break;	
				
		case LIGHTGRAY:
				
			ccolor = BLACK;
			break;	
				
		case DARKGRAY:
				
			ccolor = WHITE;
			break;

		case LIGHTBLUE:
				
			ccolor = WHITE;
			break;
				
    case LIGHTGREEN:
				
			ccolor = BLACK;
			break;  
				
		case LIGHTCYAN:
				
			ccolor = BLACK;
			break;	
				
		case LIGHTRED:
				
			ccolor = WHITE;
			break;	
				
		case LIGHTMAGENTA:
				
			ccolor = WHITE;
			break;	
				
		case YELLOW:
				
			ccolor = BLACK;
			break;	
				
		case WHITE:
				
			ccolor = BLACK;
			break;
				
		default:
				
			ccolor = BLACK;
			break;	
	
	}
	printf("color=%i, ccolor=%i", color, ccolor);getchar();
	return ccolor;
	
}
