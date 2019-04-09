#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[1024];
    while (fgets(line, 1024, file)) {
        /* parse the input */
        /* NOTE: the input strings look like:
         *  "A B C D E F G H I"
         *  which gives us 2*n-1 "valid" characters.
         */
        int num_chars = (strlen(line) + 1) / 2;
        /* The matrix will be defined in a "linearized" matrix
         * array this mean that any location will be defined as
         * the ( row offset + column offset ).
         */
        char* in_mat = calloc(num_chars, sizeof(char));
        int N = (int)sqrt(num_chars); // to get the matrix size...

        for ( int idx=0; idx < num_chars; idx++ )
        {
            in_mat[idx] = line[idx*2];
        }

        /* rotation */
        int row, col, idx=0;
        char* out_mat = calloc(num_chars, sizeof(char));
        for ( col = 0; (col < N); col++)
        {
            for ( row = N*N-N; row >= 0; row = row - N)
            {
                out_mat[idx] = in_mat[col+row];
                idx++;
            }
        }

        /* Output */
        for ( int idx = 0; idx < (N*N); idx++ )
        {
            printf("%c ", out_mat[idx] );
        }
        printf("\n");
    }
    return 0;
}
