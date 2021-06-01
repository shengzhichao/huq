#include <stdio.h>
#include <string.h>

#include"Function.h"
#include "tree.h"

int a, b, flag1, c, d, e;//a记录name1的辈份，b记录name2的辈份
tree *p, *q;//p记录name1的位置, q记录name2的位置
/************************************************************
           Discribe:初始化各全局变量
************************************************************/
void chu()
{
    flag1 = 0;//标记变量
    c = 0;//标记变量
    d = 0;//标记变量
    e = 0;//标记变量
    a = 0;//标记name1的辈份
    b = 0;//标记name2的辈份
    p = NULL;
    q = NULL;
}
/************************************************************
           Discribe:查询成员信息
           Variable: tree *root   家谱树
               char name[]  查询人的姓名
           step:1、如果找到则输出信息
                2、递归查找左孩子
                3、递归查找右兄弟
************************************************************/
int find(tree *root, char name[])
{
    if(root == NULL)//主函数需要判断树是不是空的
    {
        return 0;
    }
    else
    {
        if(strcmp(root->name, name) == 0)//找到
        {
            printf("--------------------------------------------------\n");
            printf("姓   名：%s\n", name);
            printf("性   别：%c\n", root->sex);
            printf("辈   份：%d\n", root->degree);
            printf("子女数量：%d\n", root->num);
            if(strcmp(root->fathername, "wu") == 0)//成员为祖先
            {
                printf("没有父亲信息!\n");
            }
            else
            {
                printf("父亲姓名：%s\n", root->fathername);
            }
            printf("--------------------------------------------------\n");
            c = 1;
            p = root;
            return 1;
        }
        else
        {
            find(root->child, name);//递归查找左孩子
            find(root->brother, name);//递归查找右兄弟
        }
    }
    if(c == 0)
    {
        return 0;
    }
}
/************************************************************
           Discribe:查询成员孩子信息
           Variable: tree *root 家谱树
               char parent[] 查询人信息
			step:1、先找到第一个孩子
                 2、找孩子的右兄弟
************************************************************/
int find_parent(tree *root, char parent[])//查询成员全部孩子的信息
{
    if(root == NULL || root->child == NULL)//递归边界
    {
        return 0;
    }
    else
    {
        if(strcmp(root->name, parent) == 0)//找到
        {
            printf("%s一共有%d个孩子\n", root->name, root->num);
            tree *p = root->child;
            find(p, p->name);//第一个孩子信息
            tree *q = p->brother;
            while(p->brother)
            {
                find(q, q->name);//孩子的兄弟信息
                p = q;//name1的辈份大于name2的辈份
                q = q->brother;
            }
            d = 1;
            return 1;
        }
        find_parent(root->child, parent);//递归查找左孩子
        find_parent(root->brother, parent);//递归查找右兄弟

    }
    if(d == 0)
    {
        return 0;
    }
}
/************************************************************
           Discribe:查询两个人关系
           Variable: tree *root   家谱树
               char name1[]  查询人的姓名
			   char name2[]  查询人的姓名
		   step:1、找到两个人记录两个人的辈份以及位置
                2、比较两个人的辈份
					如果不同辈输出两个人辈份关系
					否则比较两个人是亲兄弟还是相隔几代的堂兄弟
************************************************************/
int find_connect(tree *root, char name1[], char name2[])
{
    if(root == NULL)
    {
        return 0;
    }
    else
    {
        if(strcmp(root->name, name1) == 0)//找到name1
        {
            a = root->degree;//记录name1辈份
            p = root;//记录name1位置;

        }
        else if(strcmp(root->name, name2) == 0)//找到name2
        {
            b = root->degree;//记录name2辈份
            q = root;//记录name2位置

        }
        find_connect(root->child, name1, name2);//递归查找左孩子
        find_connect(root->brother, name1, name2);//递归查找右兄弟
    }
    if(a != 0 && b != 0)
    {
        printf("--------------------------------------------------\n");
        if(a < b)//name1的辈份大于name2的辈份
        {
            printf("%s是长%s %d代的长辈\n", name1, name2, b-a);
        }
        else if(a > b)//name1的辈份小于name2的辈份
        {
            printf("%s是小%s %d代的晚辈\n", name1, name2, a-b);
        }
        else
        {
            if(strcmp(p->fathername, q->fathername) == 0)//是同一父亲
            {
                printf("%s和%s是亲兄弟\n", name1, name2);
            }
            else
            {
                while(strcmp(p->fathername, q->fathername) != 0)//一直到p和q是一个父亲为止
                {
                    p = p->parent;
                    q = q->parent;
                    e++;//记录相隔几代
                }
                printf("%s和%s是相隔%d代的堂兄弟\n", name1, name2, e);
            }
        }
        printf("--------------------------------------------------\n");
        a = 0;
        b = 0;
        c = 1;
        return 1;
    }
    if(c == 0)
        return 0;
}
/************************************************************
           Discribe:查询同一辈份成员信息
           Variable: tree *root   家谱树
               int class_num 要查询的辈份
           step:1、如果找到则输出信息
                2、递归查找左孩子
                3、递归查找右兄弟
************************************************************/
int find_same_class(tree *root, int class_num)
{
    if(root == NULL)
    {
        return 0;
    }
    else
    {
        if(root->degree == class_num)//找到这个辈份的人
        {
            find(root, root->name);//输出信息
            flag1 = 1;//标记有该辈份的人
        }
        find_same_class(root->child, class_num);//递归查找左孩子
        find_same_class(root->brother, class_num);//递归查找右孩子
    }
    if(flag1 == 0)//没有找到过该辈份的人
    {
        return 0;
    }
}
/************************************************************
           Discribe:输出三代人信息
           Variable: tree *root   家谱树
               char name[] 查询人的信息
           step:1、如果找到则输出信息
                2、查找父亲信息
                3、查找孩子信息
************************************************************/
void find_three(tree *root, char name[])
{
    tree *r;
    printf("--------------------------------------------------\n");
    printf("此人信息：\n");
    chu();
    if(!find(root, name))
    {
        printf("没有此人信息！\n");
        return;
    }
    printf("--------------------------------------------------\n");
    printf("%s父亲信息：\n", name);
    r = p;
    //chu();
    if(!find(root, r->fathername))
    {
        printf("没有此人信息！\n");
    }
    chu();
    printf("--------------------------------------------------\n");
    printf("%s孩子信息:\n", name);
    chu();
    if(!find_parent(root, name))
    {
        printf("没有此人信息！\n");
    }
    printf("--------------------------------------------------\n");
}
/************************************************************
           Discribe:查找要删除人信息
           Variable: tree *root   家谱树
               char name[] 查询人的信息
           out:此人的位置
************************************************************/
tree *find_point(tree *root, char name[])
{
    if(root==NULL)
    {
        return NULL;
    }
    else
    {
        if(strcmp(root->name, name)==0)//查找成功
        {
            p = root;
        }
        else
        {
            find_point(root->child, name);
            find_point(root->brother, name);
        }
    }
    return p;
}

/********************************************************
         Discribe:修改成员信息
         Variable:tree *root 家谱树
            char Name[] 成员原来的名字
            char Name_changed[] 成员修改后的名字
         step:1、查看成员是否存在
              2、如果存在则修改成员信息
********************************************************/
void change(tree *root, char Name[], char Name_changed[])
{
    tree *temp;
    temp = (tree *)find_point(root, Name);//查看该成员是否存在
    if(temp == NULL)//不存在
        printf("没有该成员信息！\n");
    else
    {
        strcpy(temp->name, Name_changed);//修改成员信息
        printf("该成员的信息已经成功修改！\n");
    }
}


/********************************************************
         Discribe: 删除成员信息
         Variable:tree *root 家谱树
            char name[] 成员信息
         step:1、查看成员是否存在
              2、如果存在则删除成员信息
********************************************************/
void Delete(tree *root, char name[])
{
    tree *temp_child, *temp;
    chu();//初始化
    temp_child = (tree *)find_point(root, name);//查看是否存在
    if(temp_child && temp_child == root)//存在且为祖先
    {
        printf("你不能删除祖先！\n");
        return ;
    }
    if(temp_child == NULL)//不存在
    {
        printf("没有该成员信息！\n");
        return ;
    }
    if(temp_child->parent->child == temp_child)//该成员直接连接在父亲上
    {
        temp_child->parent->child = NULL;
        temp_child->parent->child = temp_child->brother;
    }
    else
    {
        temp = temp_child->parent->child;//连接该孩子的上一个指针
        while(temp->brother != temp_child  && temp)
        {
            temp = temp->brother;
        }
        temp->brother = temp->brother->brother;
    }
    printf("该成员已被删除！\n");
}




