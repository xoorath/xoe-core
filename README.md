# xoe-core

WIP - A core library for development of games and tools.

# Development Environment

## Development Environment - Linux

### Development Environment - Linux - Install a Compiler

*Pacman (Arch based distros):*

```sh
# pacman -Sy clang
```

*Apt (Debian based distros):*

```sh
# apt update 
# apt install clang
```

### Development Environment - Linux - Install Meson

Install [Meson](https://mesonbuild.com/Quick-guide.html)

Note: Meson doesn't (yet?) allow you to specify a compiler but it will utilize the environment
variables CC and CXX to determine the c and cpp compiler to use. Only clang is supported at the time of writing.

Once you've installed meson and have a compiler you can setup your build
directory. From the project root in a terminal run:

```sh
$ meson setup buildDir
```

This will create your build directory. All other commands will be run from
there. Example:

```sh
$ cd build
$ meson compile
$ meson test
```

## Development Environment - Linux - IDE Selection

### Recommended Options

* Use [CLion](https://www.jetbrains.com/clion/)
* Use [Sublime Debugger](https://packagecontrol.io/packages/Debugger).

## Development Environment - Build configs

The supported build configs are: `[debug, debugoptimized, release]`

```sh
$ meson setup meson-build-debug --buildtype=debug
$ cd meson-build-debug
$ meson compile
$ meson test
```

```sh
$ meson setup meson-build-debugoptimized --buildtype=debugoptimized
$ cd meson-build-debugoptimized
$ meson compile
$ meson test
```

```sh
$ meson setup meson-build-release --buildtype=release
$ cd meson-build-release
$ meson compile
$ meson test
```