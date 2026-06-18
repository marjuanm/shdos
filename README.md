<p align="center">
    <img src="https://www.busquedaweb.com/openprojects/shdos/pet.png?v=2" width="auto" height="331" alt="ShellDOS's pet"><br>
    <a href="https://github.com/marjuanm/shdos/blob/main/history.txt"><img src="https://www.busquedaweb.com/openprojects/shdos/release.png?v=1" height="20" alt="Release version"></a>
    <a href="https://github.com/marjuanm/shdos/archive/refs/heads/main.zip"><img src="https://www.busquedaweb.com/openprojects/shdos/download.png" height="20" alt="Download current version"></a>
    <a href="https://github.com/marjuanm/shdos/blob/main/LICENSE"><img src="https://www.busquedaweb.com/openprojects/shdos/license.png" height="20" alt="Project's license"></a>
</p>

# Whats is ShellDOS?
ShellDOS (or simply shDOS) will be a retro-style DOS command interpreter with modern features similar to those found in Linux and other operating systems.

The project is still in its early stages, currently limited to simply running the executable and displaying the user's input on the screen. The goal, of course, is to interpret this input as a command to be executed by the console.

The aim is to create a retro console capable of running on 16-bit (MS-DOS and FreeDOS) and 32-bit DOS (tested on Windows 11 only), adding some Linux features such as the execution of Linux commands and color-coded output (although it does not yet support running Linux applications).

# Updates for the latest version (0.1.2):

The console now displays a title bar with the version and copyright information in blue with white text (the copyright is on a separate line), along with the prompt "Type HELP = Help," recreating the look of older consoles.

It's fully functional on 16-bit platforms such as <a href="https://www.freedos.org/" target="_blank">FreeDOS</a>, MS-DOS, <a href="https://reactos.org/" target="_blank">Reactos</a> (it's 32-bit but allows running 16-bit applications) and Windows 95.

It can also run in 32-bit mode (tested so far only on Windows 11), but I've encountered the problem that the command console uses color templates that don't always match the colors specified for the program being developed.

It has a very limited number of commands: ver, cls, and exit.

# Building:

ShellDOS or shDOS is programmed in C using the OpenWatcom compiler to create 16-bit and 32-bit executables. Therefore, you need to download and install this IDE beforehand, which you can find at this URL: https://openwatcom.org/ftp/install/

I first encountered OpenWatcom about 15 years ago when I was still using Windows XP. I honestly don't remember which installer I used (I no longer have that file), but I assume it must have been "open-watcom-c-win32-1.9.exe". Just download it and proceed with the installation.

For some reason, back then I had to install everything in a folder without spaces because it kept failing. So, I recommend installing it in c:\openwatcom or something similar. Look for the BINNT\IDE.EXE file and run it. Then, simply locate the project file to begin compiling.

We'll open the shdos.wpj file from the 16-bit or 32-bit folder, click the "Make target" icon to generate the executable, and if we're using the 32-bit version, we can run it directly in Windows. Otherwise, we'll need to run our .exe in DOSBox, MS-DOS, or FreeDOS from a virtual machine.

As I mentioned at the beginning, this project is in its early stages; we'll be making contributions gradually.

# Binaries:

shDOS is a free software project distributed under the GPL-3.0 license. The source code will be publicly available for anyone who wants to study, modify, or compile the project.

However, the repository will not include official binaries. The 16-bit and 32-bit executables will be offered as a paid download for approximately $6 USD.

The idea is to help fund the project's development without limiting the freedoms granted by the GPL license. Those who purchase the download will receive a ZIP file with the ready-to-use executables and a more recent version of the source code (the version on GitHub will be synchronized a few months later).

Of course, anyone who does not wish to purchase the download can obtain the source code, install OpenWatcom, and compile the project themselves. The process is simple and is part of shDOS's open philosophy.

Furthermore, as mentioned, the commercial versions will be updated more frequently, and the public repository may remain a few months behind the officially distributed version.

Thank you for supporting the development of shDOS.

----------------------------------

When available, users will be able to purchase a copy for approximately $6 USD. The download will include:

* Complete project source code.
* Ready-to-use 16-bit executables.
* Ready-to-use 32-bit executables.
* Files and resources needed to compile the project.

# Useful resources:

DOSBox:
<ul>
<li><a href="https://portableapps.com/apps/games/dosbox_portable" target="_blank">Portable edition</a> (only to Windows)</li>
<li><a href="https://www.dosbox.com/download.php?main=1" target="_blank">Regular version</a></li>
</ul>

FreeDOS (run in VirtualBox or another virtual machine)
<br>
<a href="https://www.freedos.org/download/" target="_blank">Descargar</a>

VirtualBox (available for Windows and other operating systems)
<br>
<a href="https://www.virtualbox.org/wiki/Downloads" target="_blank">Descargar</a>
