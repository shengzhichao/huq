#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "show.h"
#include "tree.h"
/************************************************************
           Discribe:展示家谱树信息
           Variable: tree *root 家谱树
************************************************************/
void show(tree *root)
{
    long long int aa;
    if(root == NULL) return ;//家谱树为空
    else
    {
        for(aa = 1; aa < root->degree; aa++)
        {
            printf("        ");
        }
        printf("%s\n", root->name);
        show(root->child);//输出孩子信息
        show(root->brother);//输出兄弟信息
    }
}

