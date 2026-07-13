<p align="center">
    <a href="https://software.webxpress.top/projects/shdos" target="_blank"><img src="https://www.busquedaweb.com/openprojects/shdos/pet.png?v=2" width="auto" height="331" alt="ShellDOS's pet"></a><br>
    <a href="https://github.com/marjuanm/shdos/blob/main/CHANGELOG"><img src="https://www.busquedaweb.com/openprojects/shdos/release.png?v=8" height="20" alt="Release version"></a>
    <a href="https://github.com/marjuanm/shdos/archive/refs/heads/main.zip"><img src="https://www.busquedaweb.com/openprojects/shdos/download.png" height="20" alt="Download current version"></a>
    <a href="https://github.com/marjuanm/shdos/blob/main/LICENSE"><img src="https://www.busquedaweb.com/openprojects/shdos/license.png" height="20" alt="Project's license"></a>
</p>

# What is ShellDOS?
**ShellDOS** (or **shDOS**) is a retro-styled DOS command interpreter that combines the classic MS-DOS/FreeDOS experience with selected modern features inspired by Linux. It's designed to run in both 16-bit and 32-bit environments.

The project is currently in an early stage, providing a functional shell interface. Future releases will add command execution, color support and additional Linux-inspired commands. It has been successfully tested on DOSBOX, FreeDOS and other compatible environments (see the <a href="https://software.webxpress.top/projects/shdos/wiki/installation/#running" target="_blank">project's Wiki</a> for details).

### 🗺️ Development Roadmap

- [/] 🐻 Visual identity and core system concept
- [/] ⚙️ Main command interpreter architecture
- [/] 🛠️ Basic command support *(In progress)*
- [ ] 💾 Implementation of all native MS-DOS commands
- [ ] 🐧 Support and translation for essential Linux commands
- [ ] 🎨 Text coloring system for console command output

# 🚀 Updates for the latest version (0.2.5):

ShellDOS is now also on <b><a href="https://gitlab.com/marjuanm/shdos">GitLab!</b></b> However, the main repository will remain on GitHub and will be synchronized every few weeks.

# 📋 License:

ShellDOS is released under GPL-3 license, but is provided "as is". Use at your own risk, the author is not responsible for loss of data, file corruption, hardware damage, lost profits, or any other consequences resulting from the use of this software.

The software will be regularly updated to correct any bugs that may appear during development. We recommend downloading the latest version to minimize the risk of data loss. Always keep backups of important data.

# 💻 Installation:

To install ShellDOS on your computer, simply download and unzip the project file; if you are using 32-bit or 64-bit Windows, run the `shdos.exe` file corresponding to your version.

If you wish to run the 16-bit version, you must do so via DOSBox or a virtual machine with a 16-bit operating system installed. ShellDOS has very low system requirements; however, please check <a href="https://software.webxpress.top/projects/shdos/wiki/prerequisites/" target="_blank">the prerequisites</a> to ensure you meet them and can run our application without issues.

# 🛠️ Compiling from source code:

ShellDOS is written in C and compiled with the OpenWatcom compiler, allowing it to generate both 16-bit and 32-bit executables. Download and extract the project source code, configure OpenWatcom and run the compile command to build shdos.exe. 

For detailed installation, configuration, and build instructions, please refer to <a href="https://software.webxpress.top/projects/shdos/wiki/installation/#building" target="_blank">the project's Wiki</a>.

# ⚙️ Implemented Commands:

The list of implemented commands is still quite short, but we are continuing to work on it.

* `ver`: displays the current version of shDOS.
* `cls`: clears the screen.
* `exit`: exits the shDOS console and returns to the system that launched it.

# 📦 Binaries:

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

# 🔗 Useful resources:

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
