#include <stdio.h>
#include <stdlib.h>
#include "time_val_.h"
#include <string.h>
#include <sys/time.h>
#include <fcntl.h>

unsigned long tvUL(struct timeval A);

int main(int argc, char *argv[])
{
    printName();
    int maxRuns = 1;
    int VERBOSE = 0;
    int WAIT = 0;
    for (int i = 1; i < argc; i++)
    {
        if (strcmp(argv[i], "-w") == 0)
            WAIT = 1;
        if (strcmp(argv[i], "-v") == 0)
            VERBOSE = 1;
        if (atoi(argv[1]) != 0)
            maxRuns = atoi(argv[1]);
    }

    char *buffer = (char *)malloc(255);
    buffer[0] = '\0';
    int validCommand = 0;
    int run = 0;
    unsigned long begin = 0;
    unsigned long end = 0;
    unsigned long delta = 0;
    unsigned long deltas = 0;
    char *command;
    struct timeval start, stop;
    int remProgress = 0;
    int prevProgress = 0;

    printf("Welcome to the code timer!\n");

    printf("\nPlease enter your program command and press enter: \n");
    while ((validCommand == 0) || (run < maxRuns))
    {
        if (validCommand == 0)
        {
            fgets(buffer, 255, stdin);
            buffer[strcspn(buffer, "\n")] = '\0';
            command = (char *)malloc(strlen(buffer) + 1);
            strcpy(command, buffer);
            free(buffer);
            buffer = (char *)malloc(255);
            buffer[0] = '\0';
        }
        gettimeofday(&start, NULL);
        if (system(command)) // cmd produced an error
        {
            printf("\nAn error occurred with your command.\n");
            printf("Please try to enter your command again: \n");
        }
        else // cmd executed successfully
        {
            gettimeofday(&stop, NULL);
            if (validCommand == 0)
                printf("Your program is running...\n");
            validCommand = 1;
            run += 1;
            begin = tvUL(start);
            end = tvUL(stop);

            delta = end - begin;
            deltas += delta;
            if (VERBOSE == 1)
                printf("run(%d/%d) took %lu\n", run, maxRuns, delta);
            else
            {

                remProgress = ((run*10)/maxRuns)*10;
                if (remProgress != prevProgress)
                {
                    prevProgress = remProgress;
                    printf("%d%% ", remProgress);
                }
            }


        }

    }
    free(command);
    printf("\nThe average execution time was %lu us\n", deltas/maxRuns);
    if (WAIT == 1)
    {
        printf("\n(press enter to exit)");
        fgets(buffer, sizeof(buffer), stdin);
    }
    return 0;
}

unsigned long tvUL(struct timeval A)
{
    long long UL = A.tv_sec*1000000+A.tv_usec;
    return UL;
}
