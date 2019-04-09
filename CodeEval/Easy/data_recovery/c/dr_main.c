#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void parse ( char* line, char*** word_list, char*** loc_list, int* word_cnt) {
    /* Splits the line at the ';' by creating two indexing pointers and
     * replacing the ';' with a null char '\0' to "end" the string there
     * for the first string. The 2nd string pointer will be at the address
     * directly behind where the ';' was to index into the 2nd part of
     * the string. (this also calculates the word count)
     */
    char* tmp_1st = line;
    char* tmp_2nd = line; // for now...
    int count = 0;

    while (*tmp_2nd) {
        if ( *tmp_2nd == ' ' ) {
            count++;
        }
        if ( *tmp_2nd == ';' ) {
            count++;
            *tmp_2nd = '\0'; // end the string there
            tmp_2nd++; // increment the pointer
            break; // and exit the loop
        }
        tmp_2nd++;
    }

    /* allocate the memory for the *_list arrays */
    char** tmp_word_list = malloc(sizeof(char*) * count);
    char** tmp_loc_list = malloc(sizeof(char*) * count);

    /* parse the 1st string using spaces as a delimiter and put
     * the address of the token into the word list
     * NOTE: we don't really have to worry about messing up the
     *       tmp_* strings when using strtok() as they are
     *       discarded later.
     */
    size_t idx=0;
    // TODO: The memory from the strdup()'s should be freed
    char* token = strdup(tmp_1st);
    while (( (token = strtok(token, " ")) != NULL) && (idx < count) ) {
        *(tmp_word_list + idx) = strdup(token); // assign token address
                                                // to word list
        token = NULL;
        idx++;
    }
    /* parse the 2nd string using spaces as a delimiter and put
     * the address of the token into the location list
     */
    idx=0;
    token = strdup(tmp_2nd);
    while (( (token = strtok(token, " ")) != NULL) && (idx < count-1) ) {
        *(tmp_loc_list + idx) = strdup(token);
        token = NULL;
        idx++;
    }

    /* results */
    *word_cnt = count;
    *word_list = tmp_word_list;
    *loc_list = tmp_loc_list;
    return;
}

void sort(char** word_list, char** loc_list, int word_cnt) {
    /* change the (char**)loc_list -> int[] */
    int* int_list = calloc(word_cnt+1, sizeof(int));

    for (int idx=0; (idx < word_cnt-1); idx++) {
        sscanf(loc_list[idx],"%d", &int_list[idx]);
    }

    /* figure out the "missing" location */
    int sum_val = (word_cnt*(word_cnt+1))/2;
    for ( int idx = 0; (idx < word_cnt); idx++ ) {
        sum_val -= int_list[idx];
    }
    int_list[word_cnt-1] = sum_val;

    /* loop through and place everything the correct position */
    char** sorted_list = calloc(word_cnt+1, sizeof(char*));
    for (int i=0; (i< word_cnt ); i++) {
        int idx = int_list[i]-1;
        sorted_list[idx] = word_list[i];
    }

    /* output -> stdout */
    for (int idx=0; (idx<word_cnt); idx++) {
        printf("%s", sorted_list[idx]);
        if (idx != (word_cnt-1)) { printf("%s", " "); }
    }
    printf("\n");

    /* memory cleanup */
    if ( sorted_list != NULL ) { free(sorted_list); }

    return;
}

int main(int argc, const char * argv[]) {

    FILE *file = fopen(argv[1], "r");
    char line[1024];
    char output[1024];
    int word_cnt=0;
    // NOTE: These are allocated in parse()!
    char **word_list = NULL, **loc_list = NULL;

    while (fgets(line, 1024, file)) {
        /* parse the string -> (line, str[] , str[], int)*/
        parse(line, &word_list, &loc_list, &word_cnt);

        /* assemble into correct order -> stdout */
        sort(word_list, loc_list, word_cnt);

        /* memory cleanup */
        if ( word_list != NULL ) { free(word_list); }
        if ( loc_list  != NULL ) { free(loc_list); }
    }
    return 0;
}
