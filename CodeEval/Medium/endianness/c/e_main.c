#include <stdio.h>

int main(int argc, const char * argv[]) {
    unsigned char t[2] = {1,0};
    /* so a char is usually 8 bytes and a short is usually 16 byes,
     * so our array is packed as 0b00 00 00 01 , 0b00 00 00 00 in
     * memory, so when read as a short it's either read as 1 in
     * little endian or 256 in big endian, though we only need to
     * check the one.*/
    unsigned char s = *(short*)t;
    if (s == 1) {
        printf("LittleEndian\n");
    } else {
        printf("BigEndian\n");
    }
    return 0;
}
