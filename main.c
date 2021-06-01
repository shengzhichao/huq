#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "show_main.h"
int main()
{

    system("clear");
    printf("******************************************\n");
    printf("            欢迎来到家谱管理系统          \n");
    printf("******************************************\n");
    printf("***************按ENTER键继续**************\n");
    getchar();
    system("clear");
    show_main();//家谱树展示界面

    return 0;
}

