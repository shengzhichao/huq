#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

void show_creat(tree *root)
{
    while(1)
    {
        printf("***************新建家谱树*****************\n\n");
        printf("            1、建立家谱\n");
        printf("            0、退出\n\n");
        printf("           （性别：男 M;  女 F）\n");
        printf("******************************************\n");
        printf("请输入您的选择：");
        int n;
        char order[105];
        scanf("%s", order);
        if(strlen(order) > 1)//指令长度大于一
        {
            printf("指令错误，请重新输入！\n");
            
            system("clear");
            continue;
        }
        switch(order[0]-'0')
        {
        case 1:
            create(root);
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

