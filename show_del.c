#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Function.h"
#include "tree.h"

void show_del(tree *root)
{
    char Name[15], for_sure, order[105];
    int num;
    while(1)
    {
        printf("*****************选择你的操作****************\n");
        printf("***************1：删除某一成员****************\n");
        printf("******************0：退出****************\n");
        scanf("%s", order);
        if(strlen(order) > 1)
        {
            printf("指令错误，请重新输入！\n");
            
            system("clear");
            continue;
        }
        if(order[0]-'0' == 1)//指令长度大于一
        {
            printf("***********请输入要删除成员的名字***************\n");
            scanf("%s%*c", Name);
            printf("***********您确认删除吗（y/n）***************\n");
            scanf("%c", &for_sure);
            if(for_sure == 'y')
            {
                Delete(root, Name);
            }
            else
            {
                system("clear");
                return ;
            }
        }
        else if(order[0]-'0' == 0)
        {
            system("clear");
            return ;
        }
        else
        {
            printf("指令错误，请重新输入！\n");
        }
    }
}

