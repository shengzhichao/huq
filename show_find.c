#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tree.h"
#include "Function.h"
void show_find(tree *root)
{
    while(1)
    {
        printf("***************成员信息查询****************\n");
        printf("           1、查找成员信息\n");
        printf("           2、查找成员孩子信息\n");
        printf("           3、查找两个人的关系\n");
        printf("           4、查找成员三代人信息\n");
        printf("           5、查找同一辈份成员信息\n");
        printf("           0、退出\n");
        printf("******************************************\n");
        printf("请输入您的选择：");
        int n, class, i;
        char name[15], name1[15], order[105];
        scanf("%s%*c", order);
        if(strlen(order) > 1)//指令长度大于一
        {
            printf("指令错误，请重新输入！\n");
            
            system("clear");
            continue;
        }
        switch(order[0]-'0')
        {
        case 1:
            printf("请输入要查询成员的姓名:");
            scanf("%s%*c", name);
            chu();
            if(!find(root, name))
            {
                printf("没有该成员信息！\n");
            }
            break;
        case 2:
            printf("请输入要查询成员的姓名:");
            scanf("%s%*c", name);
            chu();
            if(!find_parent(root, name))
            {
                printf("没有该成员信息！\n");
            }
            break;
        case 3:
            printf("请输入两个查询成员的姓名（名字之间用空格隔开）:\n");
            scanf("%s %s%*c", name, name1);
            chu();
            if(!find_connect(root, name, name1))
            {
                printf("没有该成员信息！\n");
            }
            break;
        case 4:
            printf("请输入要查询成员的姓名:");
            scanf("%s%*c", name);
            find_three(root, name);
            break;
        case 5:
            printf("请输入要查询辈份:");
            scanf("%d%*c", &class);
            chu();
            if(!find_same_class(root, class))
           // if(!find_connect(root, class))
            {
                printf("没有该辈份成员信息！\n");
            }
            break;
        case 0:
            system("clear");
            return;
            break;
        default:
            printf("指令错误，请重新输入！\n");
        }
        printf("***************按ENTER键继续**************\n");
        getchar();
        system("clear");
    }
}

