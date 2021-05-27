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