# Raylib SML Bindings

[Raylib](https://www.raylib.com/) Bindings for [SML](made://en.wikipedia.org/wiki/Standard_ML). 

## Current Limitations

The bindings are created specifically for [Moscow ML](https://mosml.org/). We are currently researchng if these bindings are applicable to other implementations of SML. 

Currently supported version of Raylib is 5.5. 

Only Linux is supported right now.

The bindings are neither complete nor stable. Anything can change at any moment. Feel free to fork this project and adapt it to your specific needs.

## Quick Start

Make sure you have [mosml](https://mosml.org) installed on your system and `$MOSMLHOME` envar pointing at the root of the instalation where folders like `bin/` and `include/` reside.

```console
$ $MOSMLHOME/bin/mosml build.sml
$ ./example
```
