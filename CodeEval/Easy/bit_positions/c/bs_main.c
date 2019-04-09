#include <stdio.h>

int main(int argc, const char * argv[]) {

    FILE *file = fopen(argv[1], "r");
    char line[1024];
    long num, bit1, bit2; // input vars
    long bs1, bs2, n_bs1, n_bs2; // temp vars

    while (fgets(line, 1024, file)) {
        // Parse the input into 3 integers
        if ( sscanf(line, "%li,%li,%li", &num, &bit1, &bit2) != 3 ) {
            printf("Failed scan values");
        } else {
            // Do a little math as the bit1 and bit2 are read in 1-based offset
            bit1--; bit2--;
            // Create the bit-shifted "Masks"
            bs1 = 1 << bit1;
            bs2 = 1 << bit2;
            // bitwise AND the two numbers,
            n_bs1 = num & bs1;
            n_bs2 = num & bs2;
            // Shift the bits back...
            n_bs1 = n_bs1 >> bit1;
            n_bs2 = n_bs2 >> bit2;
            // and compare...
            if ( !(n_bs1 ^ n_bs2) ) { // if the bits are not the same
                printf("%s\n", "true");
            } else {
                printf("%s\n", "false");
            }
        }
    }
    return 0;
}
