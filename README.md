# Cakelog

---

- [Introduction](#introduction)
- [Build Instructions](#build-instructions)
  - [Compiler Options](#compiler-options)
- [API](#api)
  - [`int cakelog_initialise(const char *executable_name, bool force_flush)`](#int-cakelog_initialiseconst-char-executable_name-bool-force_flush)
  - [`ssize_t cakelog(const char* msg_str, ...)`](#ssize_t-cakelogconst-char-msg_str-)
  - [`int cakelog_stop()`](#int-cakelog_stop)

---

## Introduction

Cakelog is a simple light-weight logging module that can be used to generate simple timestamped log files for C/C++ programs.

An example of its output is below:

```
[2021-05-27 20:59:10.083]	---------------------------------------------------------
[2021-05-27 20:59:10.084]	| Succesfully Initialised CakeLog with File Descriptor 3 |
[2021-05-27 20:59:10.084]	---------------------------------------------------------
[2021-05-27 20:59:10.084]	O, what men dare do! What men may do! What men daily do, not knowing what they do!
[2021-05-27 20:59:10.084]	(sleeping for 2 seconds)
[2021-05-27 20:59:12.084]	There are very few moments in a man's existence when he experiences so much ludicrous distress, or meets with so little charitable commiseration, as when he is in pursuit of his own hat.
[2021-05-27 20:59:12.084]	--------------------
[2021-05-27 20:59:12.084]	| Stopping CakeLog |
[2021-05-27 20:59:12.084]	--------------------

```
The source which generated the above output is below - it is provided in this repo as `cakelog-test.c`.

```
#include "cakelog.h"
#include <unistd.h>
#include <stdio.h>

int main(int argc, char** argv) {

    cakelog_initialise(argv[0], false);

    cakelog("O, what men dare do! What men may do! What men daily do, not knowing what they do!");
    cakelog("(sleeping for 2 seconds)");
    sleep(2);
    cakelog("There are very few moments in a man's existence when he experiences so much ludicrous distress, or meets with so little charitable commiseration, as when he is in pursuit of his own hat.");

    cakelog_stop();

}
```

Log files are created in the same directory as the executable and named with the pattern:

    [NAME]_YYMMDD_HHMMSS.log

Where `[NAME]` is a `char*` passed to the `cakelog_initialise()` function.

## Build Instructions

To use Cakelog in a program, simply add an include directive for its header file (`cakelog.h`) and ensure the `cakelog.c` module is compiled along with your program.

e.g.

    gcc myprogram.c cakelog.c

### Compiler Options

The default maximum length of a debug string is 1024-bytes (1kb). Lines longer than this will be truncated.

The value can be changed at compile time, but, as mentioned before, the log lines are allocated on the stack, so you may run into problems if you put too large a value.

This is set in the macro:

    #define CAKELOG_OUTPUT_STR_MAX_BUF_SIZE 1024

This macro value can be adjusted at compile time using the -D switch.

    gcc -o myprogram myprogram.c cakelog.c -DCAKELOG_OUTPUT_STR_MAX_BUF_SIZE=500



## API

### `int cakelog_initialise(const char *executable_name, bool force_flush)`

Must be called first or any calls to the `cakelog()` function will have no effect (allows you to conditionally decide whether a program should log or not which will slightly improve performance). 

The `force_flush` option will decide whether log lines are flushed to the log file as soon as they're written.

Creates the log file in the current directory (the same one as the executable). The log file is given a name of the format:

        [NAME]_YYMMDD_HHMMSS.log

Returns 0 on success and any other number on failure.

### `ssize_t cakelog(const char* msg_str, ...)`

Writes a line to the log file.

`msg_str` is the message to be written. It can contain standard `C` format specifiers.

The message is automatically prefixed with a timestamp followed by a tab (`\t`). The timestamp takes the format:

    [YYYY-MM-DD HH:MM:SS.MSS]

The return value is the number of bytes written.

Note that before being written to the log file, logging strings are allocated on the stack in this function, not on the heap.

### `int cakelog_stop()`

Uninitialise Cakelog and close the log file descriptor.

Returns 0 on success and any other number on failure.


