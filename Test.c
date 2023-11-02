#include "stdio.h"

int main() {
    char cp[] = "computer";
    char *cpp = &cp[0];
    printf("%c", *cpp++);
    printf("%c", *cpp++);
    printf("%c", *cpp++);
    printf("%c", *cpp++);
    printf("%c", *cpp++);
    printf("%c", *cpp++);
    printf("%c", *cpp++);
    printf("%c", *cpp++);
    printf("%c", *cpp++);

}

