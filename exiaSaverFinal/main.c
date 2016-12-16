#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
    if (argc <= 1) {
        initialiserProgramme();
    }
    else {
        if (argv[1] = "-stat") {
            initialiserStats();
        }
    }
    return EXIT_SUCCESS;
}
