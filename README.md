<p align="center">
    <img src="https://www.busquedaweb.com/openprojects/shdos/pet.png?v=2" width="auto" height="331" alt="ShellDOS's pet"><br>
    <a href="https://github.com/marjuanm/shdos/blob/main/history.txt"><img src="https://www.busquedaweb.com/openprojects/shdos/release.png?v=3" height="20" alt="Release version"></a>
    <a href="https://github.com/marjuanm/shdos/archive/refs/heads/main.zip"><img src="https://www.busquedaweb.com/openprojects/shdos/download.png" height="20" alt="Download current version"></a>
    <a href="https://github.com/marjuanm/shdos/blob/main/LICENSE"><img src="https://www.busquedaweb.com/openprojects/shdos/license.png" height="20" alt="Project's license"></a>
</p>

# Whats is ShellDOS?
ShellDOS (or simply shDOS) is a retro-style DOS command interpreter designed to bring modern features to classic environments. The project aims to provide a command-line experience inspired by MS-DOS and FreeDOS while incorporating functionality commonly found in Linux and other modern operating systems.

The project is currently in its early stages and can execute the shell while displaying user input. Future versions will interpret and execute commands, support colorized output, and include selected Linux-inspired commands. ShellDOS is intended to run on both 16-bit DOS systems (tested on DOSBox / MS-DOS / FreeDOS /  Windows 95 and Reactos) and 32-bit environments (tested on Windows 95 / 7, 11 and Reactos), combining retro compatibility with modern usability.

# Updates for the latest version (0.2.1):

ShellDOS can read the shdos.cfg configuration file and load the data (without applying it yet), or create the file if it's not available and preload a configuration to be applied on the next boot.

The 16-bit and 32-bit executables have been successfully tested on DOSBox, FreeDOS, MS-DOS, Windows 95/7/11 and ReactOS. However, if run from a CD-ROM, it fails silently because it doesn't validate that the path is read-only. Therefore, it's necessary to copy and paste the shdos.exe file to a folder that allows both reading and writing.

# License:

ShellDOS is released under GPL-3 license, but is provided "as is". Use at your own risk, the author is not responsible for loss of data, file corruption, hardware damage, lost profits, or any other consequences resulting from the use of this software.

The software will be regularly updated to correct any bugs that may appear during development. We recommend downloading the latest version to minimize the risk of data loss. Always keep backups of important data.

# Building and how to use:

ShellDOS is written in C language using the OpenWatcom compiler, allowing it to generate both 16 / 32-bit executables. Before building the project, download and install <a href="https://openwatcom.org/ftp/install/" target="_blank">OpenWatcom</a>, preferably in a directory without spaces (for example, C:\OpenWatcom), and run BINNT\IDE.EXE.

To compile ShellDOS, open the shdos.wpj project file located in either the 16 or 32-bit folder and click Make Target. The 32-bit version can be executed directly on modern Windows systems, while the 16-bit version should be tested in DOSBox, MS-DOS, or FreeDOS. As the project is still in its early stages, new features and improvements will be added gradually over time.

<b>How to run:</b>

For Windows platforms, you can run the executable from the command prompt. Simply open it, navigate to the folder containing the shdos.exe file and run the program.

Alternatively, you can simply double-click the shdos.exe file and wait for the command prompt window to open. If you are using DOSBox or FreeDOS/MS-DOS you must navigate to the folder containing the shdos.exe file and launch the program.

From the ShellDOS console, execute the implemented commands to begin managing your files, programs, etc., <b>just like in the old days!</b>

<b>Implemented Commands:</b>

* ver: displays the current version of shDOS.
* cls: clears the screen.
* exit: exits the shDOS console and returns to the system that launched it.

# Binaries:

ShellDOS is a free software project distributed under the GPL-3.0 license. The source code will be publicly available for anyone who wants to study, modify, or compile the project.

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
* <a href="https://portableapps.com/apps/games/dosbox_portable" target="_blank">Portable edition</a> (only to Windows)
* <a href="https://www.dosbox.com/download.php?main=1" target="_blank">Regular version</a>

FreeDOS (run in VirtualBox or another virtual machine)
<br>
<a href="https://www.freedos.org/download/" target="_blank">Descargar</a>

Reactos (run in VirtualBox or another virtual machine)
<br>
<a href="https://reactos.org/" target="_blank">Descargar</a>

VirtualBox (available for Windows and other operating systems)
<br>
<a href="https://www.virtualbox.org/wiki/Downloads" target="_blank">Descargar</a>
