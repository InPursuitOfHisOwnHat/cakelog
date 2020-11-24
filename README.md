# cakelog
Small C logger used for testing, exercises and training examples.

Uses Linux system calls only, so not very portable.

Copy the header and source into your project so you always compile with the same version.

# Instructions

1. Include:
```
#include "cakelog.h"
```
2. Initialise with:
```
cakelog_initialise("<name_of_program>");
```
If you do not call initialise, debug statements have no affect and no debug file is created

3. Output line to log file - similar to printf():
```
cakelog("<message>", vargs);
```
4. Stop with:
```
cakelog_stop();
```

## Compiler Options

`-DCAKELOG_OUTPUT_STR_MAX_BUF_SIZE [n]` set the maximum length of logging string in chars (default is 256)

# Example Output:

```
[2020-04-27 16:40:20]	===================================================
[2020-04-27 16:40:20]	Succesfully Initialised Log with File Descriptor 3
[2020-04-27 16:40:20]	===================================================
[2020-04-27 16:40:20]	This is a test log message.
[2020-04-27 16:40:20]	This is another one.
[2020-04-27 16:40:20]	============
[2020-04-27 16:40:20]	Stopping log
[2020-04-27 16:40:20]	============
```
