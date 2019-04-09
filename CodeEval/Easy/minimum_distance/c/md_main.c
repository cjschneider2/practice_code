#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(int argc, const char * argv[]) {

    if ( argc < 2 ) { printf("Not enough arguments, Exiting...\n"); return 0;}
    FILE *file = fopen(argv[1], "r");

    const int MAX_CHAR = 1000000;
    char line[MAX_CHAR]; // ^--: <100 friends with addresses in the range of
                         // 0<A<10000 + a little extra...

    while (fgets(line, MAX_CHAR, file)) {

        /* Input parsing */
        char* token = strdup(line);
        int no_friends = 0;
        int* addr = NULL;

        // Read in how many entries we have
        if ( (token = strtok(token, " ")) ) {
            sscanf(token, "%d", &no_friends);
            addr = calloc(no_friends, sizeof(int));
        } else { printf("Number of friends input parsing failed\n"); return 0;}
        token = NULL;

        // put the address numbers into the array
        int idx = 0;
        while ( (token = strtok(token, " \n")) != NULL )
        {
            sscanf(token, "%d", (addr + idx) );
            token = NULL;
            ++idx;
        }

        /* calculation */
        // Although confusingly written, if we take the floor of the arithmetic
        // mean to find the "center" of the distribution, we can then find a sum
        // of the distances between this center point and the other houses and
        // sum these value up to get the answer.

        // this should calculate the mean position for the "optimal" position of
        // the house
        int sum_house = 0;
        for ( int i = 0; i < no_friends; ++i) {
            sum_house += addr[i];
        }
        // should be the arithmetic mean rounded to the nearest integer...
        int center =  (int) round( (double)sum_house / (double)no_friends);

        // this should calculate the sum of the differences 
        int sum_diff = 0;
        for ( int i = 0; i < no_friends; ++i) {
            sum_diff += abs(addr[i] - center);
        }

        /* DEBUG */
        printf("Number of friends: %d\n", no_friends);
        printf("    Optimal: %f\n", (double)sum_house / (double)no_friends );
        printf("    Real: %d\n", center);
        printf("    Sum_Diff: %d\n", sum_diff);
        /*
        printf("    Addresses: ");
        for ( int i = 0; i < no_friends; ++i) {
            printf("%d ", addr[i]);
        }
        printf("\n");
        */
        //printf("%d\n", sum);
    }
    return 0;
}
