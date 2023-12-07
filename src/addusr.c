#include <stdio.h>
#include <stdlib.h>
#include "addusr.h"
#include "usrway.h"

void addusr(Usrlist* pusrlist, Usr* pusr)
{
    FILE* pfusr = fopen(USR_FILE, "a");

    // 创建节点
    Usr_node *p = (Usr_node*)malloc(sizeof(Usr_node));
    p->next = NULL;
    p->usr.account = -1;
    p->usr.passward = -1;

    printf("请输入账号: ");
    scanf("%ld", &p->usr.account);

    // 检查是否已存在该用户信息
    Usr_node* q = NULL;
    for ( q=pusrlist->head; q; q=q->next ) {
        if ( p->usr.account == q->usr.account ) {
            printf("已存在该用户\n");
            free(p);
            return;
        } else if ( p->usr.account <= 0 ) {
            printf("无效账号\n");
            free(p);
            return;
        }
    }

    int result = 0;
    long passward = 0;
    long passagain = 0;
    printf("请输入密码: ");
    scanf("%ld", &passward);
    if ( passward < 0 ) {
        printf("密码不能为负数,请重新输入\n");
    } else if ( passward < 100000 ) {
        printf("密码过短,请重新输入\n");
    } else {
        printf("请确认密码: ");
        scanf("%ld", &passagain);
        if ( passagain == passward ) {
            p->usr.passward = passward;
            result = 1;
        } else {
            printf("密码不一致\n");
        }
    }

    if ( result ) {
        // 将节点插入到尾部
        if ( pusrlist->head ) {
            pusrlist->tail = pusrlist->tail->next = p;
        } else {
            pusrlist->tail = pusrlist->head = p;
        }

        Usr_node* t;
        printf("yes\n");
        for ( t=pusrlist->head; t; t=t->next ) {
            printf("%p\n",&t->next);
            printf("%ld\n",t->usr.account);
        }

        // 保存用户信息
        if ( fwrite(&pusrlist->tail->usr, sizeof(Usr), 1, pfusr) == 1 ) {
            printf("用户注册成功\n");
        } else {
            printf("用户信息保存失败\n");
        }
    }

    free(p);
    fclose(pfusr);
}