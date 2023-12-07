#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include "usrway.h"
#include "login.h"
#include "addusr.h"

void usrway(Usrlist* pusrlist, Usr* pusr)
{
    char inputch = '0';
    while ( pusr->account == -1 ) {
        printf("*********************************\n");
        printf("*\t学生信息管理系统\t*\n");
        printf("*********************************\n");
        printf("*\t    登陆界面\t\t*\n");
        printf("*********************************\n");
        printf("*\t     1.登录\t\t*\n");
        printf("*\t     2.注册\t\t*\n");
        printf("*\t     3.退出\t\t*\n");
        printf("*********************************\n");
        printf("\n");
        inputch = _getch();
        switch ( inputch )
        {
        case '1':
            printf("***登录***\n");
            login(pusrlist, pusr);
            break;
        case '2':
            printf("***注册***\n");
            addusr(pusrlist, pusr);
            break;
        case '3':
            system("cls");
            printf("欢迎再次使用,再见\n");
            exit(0);
        default:
            printf("请输入功能选项\n");
            break;
        }

        system("pause");
        system("cls");
    }
}
