# ShellDOS (shDOS)
ShellDOS (or simply shDOS) will be a retro-style DOS command interpreter with modern features similar to those found in Linux and other operating systems.

The project is still in its early stages, currently limited to simply running the executable and displaying the user's input on the screen. The goal, of course, is to interpret this input as a command to be executed by the console.

The aim is to create a retro console capable of running on 16-bit MS-DOS and FreeDOS (currently only tested in DOSBox) and 32-bit DOS (tested on Windows 11), adding some Linux features such as the execution of Linux commands and color-coded output (although it does not yet support running Linux applications).

-------------------------------------

shDOS is programmed in C using the OpenWatcom compiler to create 16-bit and 32-bit executables. Therefore, you need to download and install this IDE beforehand, which you can find at this URL: https://openwatcom.org/ftp/install/

I first encountered OpenWatcom about 15 years ago when I was still using Windows XP. I honestly don't remember which installer I used (I no longer have that file), but I assume it must have been "open-watcom-c-win32-1.9.exe". Just download it and proceed with the installation.

For some reason, back then I had to install everything in a folder without spaces because it kept failing. So, I recommend installing it in c:\openwatcom or something similar. Look for the BINNT\IDE.EXE file and run it. Then, simply locate the project file to begin compiling.

We'll open the shdos.wpj file from the 16-bit or 32-bit folder, click the "Make target" icon to generate the executable, and if we're using the 32-bit version, we can run it directly in Windows. Otherwise, we'll need to run our .exe in DOSBox, MS-DOS, or FreeDOS from a virtual machine.

As I mentioned at the beginning, this project is in its early stages; we'll be making contributions gradually.
