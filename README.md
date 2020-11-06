# hatlog
Small C logger used for testing, exercises and training examples.

Uses Linux system calls only, so not very portable.

Copy the header and source into your project so you always compile with the same version.

# Instructions

1. Include:
```
#include "hatlog.h"
```
2. Initialise with:
```
hatlog_initialise("<name_of_program>");
```
If you do not call initialise, debug statements have no affect and no debug file is created

3. Output line to log file - similar to printf():
```
hatlog("<message>", vargs);
```
4. Stop with:
```
hatlog_stop();
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
