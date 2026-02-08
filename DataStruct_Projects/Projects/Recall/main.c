#include <stdio.h>
#include <stdlib.h>
#include "Contact.h"

int main(void)
{
    // 初始化联系人名单
    Contact_Typedef Users;
    Contact_Init(&Users);
    // 控制面板
    Contact_Ctl(&Users) ;

    printf("\nHello\n") ;
    return 0;
}