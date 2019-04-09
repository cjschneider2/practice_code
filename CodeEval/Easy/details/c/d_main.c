#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[]) {

    FILE *file = fopen(argv[1], "r");
    char line[1024];

    while (fgets(line, 1024, file)) {

        int mat_min = 8, // the max matrix size is 10 - 2 for the
                         // 'X' and 'Y' end blocks...
            spaces = 0;
        char prev_char = 'X'; // It'll always start with an 'X'
        int _ignore_row = 0;

        for ( int idx = 0; (idx < strlen(line)); idx++)
        {
            char cur_char = line[idx];

            if ( cur_char == ',')
            {
                if ( spaces < mat_min ) { mat_min = spaces; }
                spaces = 0;
            }
            if ( cur_char == '.' && !_ignore_row) { spaces++; }
            // Checking for already adj. "XY..Y" blocks
            if ( (prev_char == 'X') && (cur_char == 'Y') )
            {
                spaces = 0;
                _ignore_row = 1;
            }
            prev_char = cur_char;
        }
        // only to make sure the last is counted ...
        if ( spaces < mat_min ) { mat_min = spaces; }
        printf("%d\n", mat_min);
    }
    return 0;
}
