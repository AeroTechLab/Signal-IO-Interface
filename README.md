# Signal I/O Interface
Physical/virtual signal aquisition and generation interface to be implemented by hardware specific [plugins](https://en.wikipedia.org/wiki/Plug-in_(computing))

## Overview

Computer I/O boards commonly offer many digital or analog ports/channels for reading/writing electrical signals. The independent management of those channels is taken into account for creating a generic interface for any such device. In a software using **Signal I/O Interface** one would be able to switch between different device libraries (implemented in plug-ins) without rewriting the main application code.

## Usage

On a terminal, get the [GitHub code repository](https://github.com/LabDin/Signal-IO-Interface) with:

    $ git clone https://github.com/LabDin/Signal-IO-Interface [<my_project_folder>]

This code is dependent on macros from [Plug-in Loader](https://github.com/LabDin/Plugin-Loader) project, that is automatically linked as a [git submodule](https://chrisjean.com/git-submodules-adding-using-removing-and-updating/).

To add that repository to your sources, navigate to the root project folder and clone them with:

    $ cd <my_project_folder>
    $ git submodule update --init

**Signal I/O Interface** itself consists of a single header file of common variables and function declarations. Simply include it in both plug-in and host projects

## Documentation

Doxygen-generated detailed methods documentation is available on a [GitHub Page](https://labdin.github.io/Signal-IO-Interface/classSIGNAL__IO__INTERFACE.html)
