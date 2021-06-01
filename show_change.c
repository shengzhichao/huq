#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"
#include "Function.h"

void show_change(tree *root)
{
    while(1)
    {
        printf("******************成员信息修改**************\n\n");
        printf("           1、信息修改\n");
        printf("           2、确认修改\n");
        printf("           3、撤销修改\n");
        printf("           0、退出\n\n");
        printf("******************************************\n");
        printf("请输入您的选择：");
        int n, d;
        char order[105];
        scanf("%s%*c", order);
        if(strlen(order) > 1)//指令长度大于一
        {
            printf("指令错误，请重新输入！\n");
            
            system("clear");
            continue;
        }
        char name[15], name1[15];
        switch(order[0]-'0')
        {
        case 1:
            printf("请输入要修改成员的姓名：");
            scanf("%s%*c", name);
            printf("请输入修改后的姓名：");
            scanf("%s%*c", name1);
            printf("是否确认修改？\n");
            scanf("%d%*c", &d);
            if(d == 2)
            {
                change(root, name, name1);
            }
            else
            {
                printf("撤销成功！");
            }
            break;
        case 0:
            system("clear");
            return;
            break;
        default:
            printf("指令错误，请重新输入！\n");
        }
        
        system("clear");
    }
}

