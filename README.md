<p align="center">
    <img src="https://www.busquedaweb.com/openprojects/shdos/pet.png?v=2" width="auto" height="331" alt="ShellDOS's pet"><br>
    <a href="https://github.com/marjuanm/shdos/blob/main/history.txt"><img src="https://www.busquedaweb.com/openprojects/shdos/release.png?v=2" height="20" alt="Release version"></a>
    <a href="https://github.com/marjuanm/shdos/archive/refs/heads/main.zip"><img src="https://www.busquedaweb.com/openprojects/shdos/download.png" height="20" alt="Download current version"></a>
    <a href="https://github.com/marjuanm/shdos/blob/main/LICENSE"><img src="https://www.busquedaweb.com/openprojects/shdos/license.png" height="20" alt="Project's license"></a>
</p>

# Whats is ShellDOS?
ShellDOS (or simply ShDOS) is a retro-style DOS command interpreter designed to bring modern features to classic environments. The project aims to provide a command-line experience inspired by MS-DOS and FreeDOS while incorporating functionality commonly found in Linux and other modern operating systems.

The project is currently in its early stages and can execute the shell while displaying user input. Future versions will interpret and execute commands, support colorized output, and include selected Linux-inspired commands. ShDOS is intended to run on both 16-bit DOS systems (MS-DOS and FreeDOS) and 32-bit environments (currently tested on Windows 11), combining retro compatibility with modern usability.

# Updates for the latest version (0.2.0):

The system was prone to overflow errors when closing the program after receiving very large commands. Now, the system truncates commands if they exceed the buffer size and uses safe functions to display text on the screen, preventing this overflow error.

I've begun partially implementing the "commands" module, which will contain the implementations of the internal commands, of course, it has a very limited number of commands: ver, cls, and exit.

# License:

ShellDOS is released under GPL-3 license, but is provided "as is". Use at your own risk, the author is not responsible for loss of data, file corruption, hardware damage, lost profits, or any other consequences resulting from the use of this software.

The software will be regularly updated to correct any bugs that may appear during development. We recommend downloading the latest version to minimize the risk of data loss. Always keep backups of important data.

# Building:

ShDOS is written in C language using the OpenWatcom compiler, allowing it to generate both 16 / 32-bit executables. Before building the project, download and install <a href="https://openwatcom.org/ftp/install/" target="_blank">OpenWatcom</a>, preferably in a directory without spaces (for example, C:\OpenWatcom), and run BINNT\IDE.EXE.

To compile ShDOS, open the shdos.wpj project file located in either the 16 or 32-bit folder and click Make Target. The 32-bit version can be executed directly on modern Windows systems, while the 16-bit version should be tested in DOSBox, MS-DOS, or FreeDOS. As the project is still in its early stages, new features and improvements will be added gradually over time.

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
