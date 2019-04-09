#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {

    FILE *file = fopen(argv[1], "r");
    char line[1024];

    while (fgets(line, 1024, file)) {
        int age = atoi(line);
        if ( age >= 0 && age <= 2){
            printf("Still in Mama's arms\n");
        }
        else if ( age >= 3 && age <= 4){
            printf("Preschool Maniac\n");
        }
        else if ( age >= 5 && age <= 11){
            printf("Elementary school\n");
        }
        else if ( age >= 12 && age <= 14){
            printf("Middle school\n");
        }
        else if ( age >= 15 && age <= 18){
            printf("High school\n");
        }
        else if ( age >= 19 && age <= 22){
            printf("College\n");
        }
        else if ( age >= 23 && age <= 65){
            printf("Working for the man\n");
        }
        else if ( age >= 66 && age <= 100){
            printf("The Golden Years\n");
        }
        else {printf("This program is for humans\n"); }
    }

    return 0;
}
