#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tree.h"
#include "Function.h"

void show_add(tree **root)
{
	tree *temp, *temp1;
    while(1)
    {
        printf("******************成员添加****************\n");
        printf("       1、添加新成员作为整个家谱的祖先\n");
        printf("       2、添加新成员作为某一成员的孩子\n");
        printf("       0、退出\n\n");
        printf("           （性别：男 M;  女 F）\n");
        printf("******************************************\n");
        printf("请输入您的选择：");
        int n, flag = 0;
        char name[105], ch, name1[105], order[105];
        scanf("%s%*c", order);
        if(strlen(order) > 1)//指令长度大于1
        {
            printf("指令错误，请重新输入！\n");
            
            system("clear");
            continue;
        }
        switch(order[0]-'0')
        {
        case 1:
            printf("请输入祖先姓名：");
            scanf("%s%*c", name);
            printf("请输入祖先性别：");
            scanf("%c%*c", &ch);
            chu();

            temp = (tree *)find_point(*root, name);//查找成员位置
            if(temp == NULL)//未找到
            {if(NULL == (add_zuxian(*root,name, ch)))
                               break;
                               else
                    *root = add_zuxian(*root, name, ch);}
	        else
	        	printf("家谱中已存在该成员！\n");
            break;
        case 2:
            printf("请输入新成员姓名：");
            scanf("%s%*c", name);
            printf("请输入新成员父亲姓名：");
            scanf("%s%*c", name1);
            printf("请输入新成员性别：");
            scanf("%c%*c", &ch);
            chu();
            temp = (tree *)find_point(*root, name);//查找成员位置
            chu();
            temp1 = (tree *)find_point(*root, name1);//查找父亲位置
            if(temp1)//找到父亲
			{
				if(temp == NULL)
					add(*root, name, name1, ch, &flag);
				else
					printf("家谱中已存在该成员！\n");
			}
	        else
	        	printf("添加成员失败！\n");
            if(flag)//添加成功
            {
                printf("添加成功！\n");
            }
            /*else
            {
            	printf("添加成员失败！\n");
            }*/
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

