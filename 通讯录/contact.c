#include "contact.h"

void InitContact(struct Contact* ps)
{
    memset(ps->data, 0, sizeof(ps->data));
    ps->size = 0;
}

static int FindByName(struct Contact* const ps, char const name[MAX_NAME])          //static修饰函数只能在contact.c内部使用
{
    int i = 0;
    for ( i = 0; i < ps->size; i++)
    {
        if(0 == strcmp(ps->data[i].name,name))
        {
            return i;       //找到了
        }
    }
    //找不到
    return -1;
}


void AddContact(struct Contact *ps)
{
    if (ps->size == MAX)
    {
        printf("通讯录已满，无法增加\n");
    }
    else
    {
        printf("请输入名字:>");
        scanf("%s", ps->data[ps->size].name);
        printf("请输入年龄:>");
        scanf("%d", &(ps->data[ps->size].age));         //数组不用取地址，本身传过去的就是地址，但是数字要
        printf("请输入性别:>");
        scanf("%s", ps->data[ps->size].sex);
        printf("请输入电话:>");
        scanf("%s", ps->data[ps->size].tele);
        printf("请输入地址:>");
        scanf("%s", ps->data[ps->size].addr);

        ps->size++;                 //为添加下一个人做准备
        printf("添加成功\n");
    }
    
}

void ShowContact(const struct Contact *ps)
{
    if (ps->size == 0)
    {
        printf("通讯录为空格\n");
    }
    else
    {
        printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "名字", "年龄", "性别", "电话", "地址");
        int i = 0;
        for ( i = 0; i < ps->size; i++)
        {
            printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n",
                   ps->data[i].name,
                   ps->data[i].age,
                   ps->data[i].sex,
                   ps->data[i].tele,
                   ps->data[i].addr);
        }
        
    }
    
}

void DelContact(struct Contact *ps)
{
    char name[MAX_NAME];
    printf("请输入要删除人的名字:>");
    scanf("%s", &name);
    //1.查找要删除的人在什么位置
    int pos = FindByName(ps, name);     //找到了返回名字所在元素的下标，找不到返回-1
    //2.删除
    if (pos == -1)
    {
        printf("要删除的人不存在\n");
    }
    else
    {
        //删除数据
        int j = 0;
        for ( j = pos; j < ps->size - 1; j++)
        {
            ps->data[j] = ps->data[j + 1];
        }
        ps->size--;
        printf("删除成功\n");
    }
    
    
}

void SearchContact(const struct Contact *ps)
{
    char name[MAX_NAME];
    printf("请输入要查找人的名字:>");
    scanf("%s", &name);
    int pos = FindByName(ps, name);
    if (pos == -1)
    {
        printf("要查找的人不存在\n");
    }
    else
    {
        printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "名字", "年龄", "性别", "电话", "地址");
        printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n",
                   ps->data[pos].name,
                   ps->data[pos].age,
                   ps->data[pos].sex,
                   ps->data[pos].tele,
                   ps->data[pos].addr);
    }
    
}

void ModifyContact(struct Contact *ps)
{
    char name[MAX_NAME];
    printf("请输入要修改人的名字:>");
    scanf("%s", &name);
    int pos = FindByName(ps, name);
    if (pos == -1)
    {
        printf("要查找的人不存在\n");
    }
    else
    {
        printf("请输入名字:>");
        scanf("%s", ps->data[pos].name);
        printf("请输入年龄:>");
        scanf("%d", &(ps->data[pos].age));     
        printf("请输入性别:>");
        scanf("%s", ps->data[pos].sex);
        printf("请输入电话:>");
        scanf("%s", ps->data[pos].tele);
        printf("请输入地址:>");
        scanf("%s", ps->data[pos].addr);

        printf("修改完成\n");
    }
    
}

void SortContact(struct Contact *ps1,struct Contact *ps2)
{
    for (int i = 0; i < ps1->size - 1; i++)
    {
        for (int j = 0; j < ps1->size - 1 - i; j++)
        {
            if (ps1->data[j].age > ps1->data[j + 1].age)
            {
                ps2->data[0] = ps1->data[j];
                ps1->data[j] = ps1->data[j + 1];
                ps1->data[j + 1] = ps2->data[0];
            }
            
        }
        
    }
    
    
    printf("排序完成\n");
}