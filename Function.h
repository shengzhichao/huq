#ifndef Function_H
#define Function_H

/************************************************************
           Discribe:查询成员信息
           Variable: tree *root   家谱树
               char name[]  查询人的姓名
************************************************************/
int find(tree *root, char name[]);
/************************************************************
           Discribe:查询成员孩子信息
           Variable: tree *root 家谱树
               char parent[] 查询人信息
************************************************************/
int find_parent(tree *root, char parent[]);
/************************************************************
           Discribe:查询两个人关系
           Variable: tree *root   家谱树
               char name1[]  查询人的姓名
			   char name2[]  查询人的姓名
************************************************************/
int find_connect(tree *root, char name1[], char name2[]);
/************************************************************
           Discribe:查询同一辈份成员信息
           Variable: tree *root   家谱树
               int class_num 要查询的辈份
************************************************************/
//int find_same(tree *root, int class_num);
int find_same_class(tree *root, int class_num);
/************************************************************
           Discribe:初始化各全局变量
************************************************************/
void chu();
/************************************************************
           Discribe:输出三代人信息
           Variable: tree *root   家谱树
               char name[] 查询人的信息
************************************************************/
void find_three(tree *root, char name[]);
/************************************************************
           Discribe:查找要删除人信息
           Variable: tree *root   家谱树
               char name[] 查询人的信息
************************************************************/
tree *find_point(tree *root, char name[]);


/********************************************************
         Discribe:修改成员信息
         Variable:tree *root 家谱树
            char Name[] 成员原来的名字
            char Name_changed[] 成员修改后的名字
********************************************************/
void change(tree *root, char Name[], char Name_changed[]);

/********************************************************
         Discribe: 删除成员信息
         Variable:tree *root 家谱树
            char name[] 成员信息
********************************************************/
void Delete(tree *root, char name[]);
#endif
