#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, const char * argv[]) {

    FILE *file = fopen(argv[1], "r");
    char line[1024];
    char cur_char;
    bool should_cap;
    // NOTE: true  = CAPITALIZED
    //       false = lowercased

    while ( fgets(line, 1024, file) )
    {
        should_cap = true; // Start capitalized
        for ( int idx=0 ; (idx < strlen(line)); idx++)
        {
            cur_char = line[idx];
            if ( (cur_char >= 'a') && (cur_char <= 'z') && should_cap )
            {
                cur_char -= 32;
                should_cap = !should_cap;
            }
            else if ( (cur_char >= 'A') && (cur_char <= 'Z') && !should_cap )
            {
                cur_char += 32;
                should_cap = !should_cap;
            }
            else if ( ((cur_char >= 'a') && (cur_char <= 'z')) ||
                      ((cur_char >= 'A') && (cur_char <= 'Z')) )
            { should_cap = !should_cap; }

            /* Output line -> stdout */
            printf("%c", cur_char);
        }
    }
    return 0;
}
