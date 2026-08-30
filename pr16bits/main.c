/*
  shDOS - Command interpreter
  Original file name: main.c
  Copyright (C) 2026 Juan Manuel Mar Hdz.
  Licensed under GPL-3.0, see the license file on the root project structure for more information.
*/

#include <io.h>
#include <dos.h>
#include <math.h>
#include <conio.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#include "../includes/constants.h"
#include "../includes/structures.h"
#include "../includes/os.h"
#include "../includes/core.h"
#include "../includes/colors.h"
#include "../includes/commons.h"
#include "../includes/commands.h"
#include "../includes/console/input.h"
#include "../includes/console/console.h"
#include "../includes/console/16bits/console.h"
#include "../includes/configuration.h"
#include "../includes/fs-operations/file.h"

#include "../core/console/16bits/input.c"
#include "../core/console/16bits/console.c"
#include "../core/console/generic/input.c"
#include "../core/console/generic/colors.c"
#include "../core/console/generic/commons.c"
#include "../core/os/16bits.c"
#include "../core/configuration.c"
#include "../core/fs-operations/file.c"
#include "../core/commands/execute.c"
#include "../core/commands/16bits.c"
#include "../core/commands/generic.c"
#include "../core/core.c"

/* 
  Purpose: Create the main laucher of the console
  Created date: 08/06/2026
  Created by username: Juan Manuel Mar Hdz.
  Last modified date: 21/06/2026
  Last modified username: Juan Manuel Mar Hdz. 
  Thanks to chatGPT
*/
int main(int argc, char *argv[])
{
	
	cmd(argv);
	return 0;
	
}
