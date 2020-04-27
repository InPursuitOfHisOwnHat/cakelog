# cakelog
Small C logger used for testing, exercises and training examples.

Uses system calls only.

# Instructions

1. Include:
```
#include "cakelog.c"
```
2. Initialise with:
```
cakelog_initialise("<name_of_program>");
```
 3. Output line to log file - similar to printf():
```
cakelog("<message>", vargs);
```
4. Stop with:
```
cakelog_stop();
```

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
