#include <stdio.h>
#include <stdlib.h>
#include "Contact.h"

#define Contact_Debug   // 调试模式

// 初始化联系人名单
void Contact_Init(Contact_Typedef* Users)
{
    #ifdef Contact_Debug
    for (size_t i = 0; i < USER_NUM_MAX; i++)
    {
        Users[i].age  = 0  ;
    }
    Users[0].name = "X" ;
    Users[1].name = "Y" ;
    Users[2].name = "Z" ;
    Users[3].name = "W" ;
    Users[4].name = "X" ;

    Users[0].ID = "123" ;
    Users[1].ID = "234" ;
    Users[2].ID = "345" ;
    Users[3].ID = "456" ;
    Users[4].ID = "567" ;

    #else
    for (size_t i = 0; i < USER_NUM_MAX; i++)
    {
        Users[i].age  = 0  ;
        Users[i].name = "" ;
        Users[i].ID   = "" ;
    }
    #endif
}
// 显示所有联系人
void Contact_Display(const Contact_Typedef* Users)
{
    printf("\n---------------------\n");

    printf("\nUsers \t ID \t age \n");
    for (size_t i = 0; i < USER_NUM_MAX; i++)
    {
        printf("%s \t %s \t %d \t \n",Users[i].name , Users[i].ID , Users[i].age) ;
    }

    printf("\n---------------------\n");
}
// 对比两个字符串是否长度相等
int String_Compare(char* S1 , char* S2)
{
    int i = 0 ;
    for ( ; S1[i] != NULL && S2[i] != NULL ; i ++)
    {
        if (S1[i] != S2[i])
        {
            break; 
        }
    }
    return S1[i] == S2[i] ;
}
// 按姓名查找联系人
int Contact_Find_Name(const Contact_Typedef* Users)
{
    int Same_Name_Num = 0 ;
    char name[50];  // 修复：使用字符数组代替未初始化的指针
    printf("\nEnter Name:") ;
    scanf("%s",name) ;  // 字符串不需要&

    // 比较字符串是否相等
    for (size_t i = 0; i < USER_NUM_MAX; i++)
    {
        if (String_Compare(Users[i].name , name) == 1)
        {
            Same_Name_Num ++ ;
            printf("%s \t %s \t %d \t \n",Users[i].name , Users[i].ID , Users[i].age) ;
        }
    }
    return Same_Name_Num ;
}
// 按照ID号查找联系人,默认ID号不同,找到了就返回位置，没找到就返回-1
int Contact_Find_ID(const Contact_Typedef* Users , char* ID)
{
    // 比较字符串是否相等
    for (size_t i = 0; i < USER_NUM_MAX; i++)
    {
        if (String_Compare(Users[i].ID , ID) == 1)
        {
            #ifdef Contact_Debug
                printf("%s \t %s \t %d \t \n",Users[i].name , Users[i].ID , Users[i].age) ;
            #endif
            return i ;
        }
    }
    return -1 ;
}
// 修改指定ID联系人账号
void Contact_Change_ID(Contact_Typedef* Users , char *ID , char* New_ID , char* New_Name , int New_Age)
{
    int index = Contact_Find_ID(Users , ID) ;
    if (index == -1)
    {
        printf("\n\nFind Nobody\n\n") ;
        return ;
    }
    Users[index].ID = ID ;
    Users[index].name = New_Name ;
    Users[index].age = New_Age ;
    printf("Input OK!") ;
}

// 修改联系人
void Contact_Change(Contact_Typedef* Users)
{
    printf("Please Enter User ID:") ;
    char* ID[50] ;
    scanf("%s",ID) ;
    // 用户指定选择ID号进行修改操作
    int index = Contact_Find_ID(Users , ID) ;
    if (index == -1)
    {
        printf("\n\nFind Nobody\n\n") ;
        return ;
    }
    // 修改信息
    char *New_ID[50] = {0};
    char *New_Name[50] = {0};
    int New_Age = 0;
    Contact_Change_ID(Users , ID , New_ID , New_Name , New_Age) ;
}

// 控制界面
void Contact_Ctl(Contact_Typedef* Users)
{
    Contact_Display(Users);
    // printf("%d",Contact_Find_Name(Users));
    // printf("%d",Contact_Find_ID(Users) , "123");
}
