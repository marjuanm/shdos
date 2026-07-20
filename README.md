<p align="center">
    <a href="https://software.webxpress.top/projects/shdos" target="_blank"><img src="https://www.busquedaweb.com/openprojects/shdos/pet.png?v=2" width="auto" height="331" alt="ShellDOS's pet"></a><br>
    <a href="https://github.com/marjuanm/shdos/blob/main/CHANGELOG"><img src="https://www.busquedaweb.com/openprojects/shdos/release.png?v=9" height="20" alt="Release version"></a>
    <a href="https://github.com/marjuanm/shdos/archive/refs/heads/main.zip"><img src="https://www.busquedaweb.com/openprojects/shdos/latest.png?v=2" height="20" alt="Download current version"></a>
    <a href="https://software.webxpress.top/projects/shdos/repositories/" target="_blank"><img src="https://www.busquedaweb.com/openprojects/shdos/download.png?v=3" height="20" alt="Repositories"></a>
    <a href="https://github.com/marjuanm/shdos/blob/main/LICENSE"><img src="https://www.busquedaweb.com/openprojects/shdos/license.png" height="20" alt="Project's license"></a>
    <a href="https://software.webxpress.top/projects/shdos/wiki/getting-started/" target="_blank"><img src="https://www.busquedaweb.com/openprojects/shdos/wiki.png" height="20" alt="Wiki documentation"></a>
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

# 🚀 Updates for the latest version (0.2.7):

Implementation of various functions to detect the operating system and its version (in a general sense); these enable ShellDOS to generate a configuration file with console colors customized for the specific operating system.

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

Of course, anyone who don't wish to purchase the download can obtain the source code, install OpenWatcom, and compile the project themselves. The process is simple and is part of shDOS's open philosophy.

Furthermore, as mentioned, the commercial versions will be updated more frequently, and the public repository may remain a few months behind the officially distributed version. If, however, you do not wish to purchase a commercial license but would like to support this project, you can make a donation using one of the methods described in the next section.

Thank you for supporting the development of shDOS.

----------------------------------

When available, users will be able to purchase a copy for approximately $6 USD. The download will include:

* Complete project source code.
* Ready-to-use 16-bit executables.
* Ready-to-use 32-bit executables.
* Files and resources needed to compile the project.

# ❤️ Donations

If you don't wish to purchase a commercial license but would like to support this project, thank you very much in advance. You may donate any amount you wish—any contribution is greatly appreciated; please select one of the following methods.

- ⭐ <a href="https://github.com/sponsors/marjuanm?frequency=recurring" target="_blank">GitHub Sponsors</a>
- ☕ <a href="https://ko-fi.com/msproys" target="_blank">Ko-fi</a>
- 💳 <a href="https://www.paypal.com/donate/?business=73JT73SJF2HXY&no_recurring=0&item_name=Thank+you+for+donating+and+supporting+my+projects.+If+you+don%27t+need+a+commercial+license%2C+any+donation+helps.+Many+thanks%21&currency_code=MXN" target="_blank">PayPal</a>

# 🤝 Community Support

- ShellDOS is a project maintained in my spare time.
- Bug reports and feature suggestions are always welcome and will be reviewed as soon as possible.
- There is no Service Level Agreement (SLA) or guaranteed support for users who are not project sponsors.
- Sponsors help fund the ongoing development of ShellDOS. As a token of appreciation, their bug reports, feature requests, and support inquiries may be given higher priority (once binary distribution is active, I will post the link for reporting bugs as a sponsor).
- Pull requests are always welcome. Well-documented, tested, and high-quality contributions are more likely to be accepted.

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
