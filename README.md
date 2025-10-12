# xoe-core
WIP - A core library for development of games and tools.

# Development Environment

## Development Environment - Linux

### Development Environment - Linux - Install a Compiler

Install `libc-dev`, `gcc`, `g++`, `make` and `dpkg-dev`. Usually this can be
done with one installation command from most package managers like so:

*Pacman (Arch based distros):*
```sh
# pacman -S base-devel
```

*Apt (Debian based distros):*
```sh
# apt install build-essential
```

These meta packages aren't exactly equivalent but both will get you what you
need.

### Development Environment - Linux - Install Meson

Install [Meson](https://mesonbuild.com/Quick-guide.html)

Once you've installed meson and have a compiler you can setup your build
directory. From the project root in a terminal run:

```sh
$ meson setup build
```

This will create your build directory. All other commands will be run from
there. Example:

```sh
$ cd build
$ meson compile
$ meson test
```

## Development Environment - Linux - Install a Debugger

Install GDB:

*Pacman (Arch based distros):*
```sh
# pacman -S gdb
```

*Apt (Debian based distros):*
```sh
# apt install gdb
```

# Typical Workflow

## Typical Workflow - Compile and Test

Assuming you've setup your build directory (see: the Installing Meson section)
You can run meson build and test commands from the build directory.

```sh
$ meson compile
$ meson test
```

## Typical Workflow - Debugging

There is a Sublime Text project file in the workspace root with debug commands.

This requires the
[Sublime Debugger](https://packagecontrol.io/packages/Debugger) package to be
installed and configured.