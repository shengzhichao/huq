#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tree.h"
#include "show_creat.h"
#include "show_add.h"
#include "show_del.h"
#include "show_find.h"
#include "show_change.h"
#include "show.h"
#include "show_main.h"
#include "file.h"

void show_main()
{
    tree *root;
    char str[1500];
    root = (tree *)malloc(sizeof(struct treenode));
    while(1)
    {

        printf("****************家谱树操作*******************\n");
        printf("           1、新建家谱树                     \n");
        printf("           2、成员添加                       \n");
        printf("           3、成员信息查询                   \n");
        printf("           4、删除家谱成员                   \n");
        printf("           5、成员信息修改                   \n");
        printf("           6、家谱树显示                     \n");
        printf("           7、从文件中读取信息重建家谱树     \n");
        printf("           8、保存家谱到文件                 \n");
        printf("           0、退出                           \n");
        printf("*********************************************\n");
        printf("请输入您的选择：");
        int i, n;
        char order[105];
        scanf("%s%*c", order);
        if(strlen(order) > 1)
        {
            printf("指令错误，请重新输入！\n");
//            
            system("clear");
            continue;
        }
  //      
        system("clear");
        switch(order[0]-'0')
        {
        case 1:
            show_creat(root);
            break;
        case 2:
            show_add(&root);
            break;
        case 3:
            show_find(root);
            break;
        case 4:
            show_del(root);
            break;
        case 5:
            show_change(root);
            break;
        case 6:
            show(root);
            break;
        case 7:
            root = (tree *)read_from_file();
            break;
        case 8:
            write_to_file(&root);
            break;
        case 0:
            system("clear");
            return;
            break;
        default:
            printf("指令错误，请重新输入！\n");
        }
//        getchar();
//        system("clear");
        //    continue;
    }

}

