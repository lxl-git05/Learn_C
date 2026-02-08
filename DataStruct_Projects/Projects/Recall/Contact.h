// 联系人名单结构体
typedef struct
{
    char *name ;	// 用户输入
    char *ID ;		// 用户输入
    int  age;		// 用户输入
}Contact_Typedef;

#define USER_NUM_MAX 5


// 初始化联系人名单
void Contact_Init(Contact_Typedef* Users) ;
// 控制界面
void Contact_Ctl(Contact_Typedef* Users) ;