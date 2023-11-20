/*
1.存放1000个好友信息
名字
电话
性别
地址
年龄
2.增加好友信息
3.删除指定名字的好友信息
4.查找好友信息
5.修改好友信息
6.打印好友信息
7.排序
*/

#include "contact.h"


void menu()
{
    printf(" —— —— —— —— —— —— —— —— —— —— —— —— —— —— —— —— \n");
    printf("|           1. 添加信息       2. 删除信息        |\n");
    printf("|           3. 查找信息       4. 修改信息        |\n");
    printf("|           5. 显示信息       6. 信息排序        |\n");
    printf("|                      0.exit                    |\n");
    printf(" —— —— —— —— —— —— —— —— —— —— —— —— —— —— —— —— \n");
}

int main()
{
    int input = 0;
    //创建通讯录

    struct Contact con;        //con就是通讯录，里边包含：1000的元素的数和size
    //初始化通讯录
    InitContact(&con);
    do
    {
        menu();
        printf("请选择:> ");
        scanf("%d", &input);
        switch (input)
        {
        case ADD:
            AddContact(&con);        //增加一个信息
            break;
        case DEL:
            DelContact(&con);        //删除一个信息
            break;  
        case SEARCH:
            SearchContact(&con);      //查找信息
            break;
        case MODIFY:
            ModifyContact(&con);       //修改信息
            break;
        case SHOW:
            ShowContact(&con);       //显示信息
            break;
        case SORT:
            SortContact(&con, &tmp);     //排序
            break;
        case 0:
            printf("退出通讯录!\n");
            break;
        default:
            printf("选择错误!\n");
            break;
        }
    } while (input);
    
    return 0;
}