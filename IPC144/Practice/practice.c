#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    int x;

    printf("Enter x : ");
    scanf("%d", &x);
    printf("Value stored in x   :%d\n", x);
    printf("Address of x        :%x\n", &x);

    return 0;
}