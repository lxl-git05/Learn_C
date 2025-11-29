#include <stdio.h>
#include <stdlib.h>
#include "max.h"    // 引用自己的头文件

int main(void)
{
    int a = 10, b = 20;

    int c = max(a, b);  

    printf("Hello World\n");
    printf("c = %d\n", c);

    return 0;
}