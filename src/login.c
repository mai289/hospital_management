#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "usrway.h"
#include "login.h"


void login(Usrlist* pusrlist, Usr* pusr)
{
    long account = 0;
    long passward = 0;
    int noaccount = 1;
    Usr_node* p = NULL;
    printf("请输入账号: ");
    scanf("%ld", &account);
    if ( account == ROOT_ACCOUNT ) {
        printf("请输入管理员密码: ");
        scanf("%ld", &passward);
        noaccount = 0;
        if ( passward == ROOT_PAASWARD ) {
            pusr->account = ROOT_ACCOUNT;
            pusr->passward = ROOT_PAASWARD;
            printf("欢迎回来,管理员\n");
            return;
        } else {
            printf("密码错误\n");
        }
    }
    for ( p=pusrlist->head; p; p=p->next ) {
        if ( p->usr.account == account ) {
            noaccount = 0;
            printf("请输入密码: ");
            scanf("%ld", &passward);
            if ( p->usr.passward == passward ) {
                pusr->account = account;
                pusr->passward = passward;
                printf("登录成功\n");
                break;
            } else {
                printf("密码错误\n");
                break;
            }
        }
        printf("1\n");
        printf("%ld\n",p->usr.account);
        printf("%p\n", &p->next);
        system("pause");
    }
    if ( noaccount ) {
        printf("无此用户\n");
    }
}
