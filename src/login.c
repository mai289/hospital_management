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
    printf("�������˺�: ");
    scanf("%ld", &account);
    if ( account == ROOT_ACCOUNT ) {
        printf("���������Ա����: ");
        scanf("%ld", &passward);
        noaccount = 0;
        if ( passward == ROOT_PAASWARD ) {
            pusr->account = ROOT_ACCOUNT;
            pusr->passward = ROOT_PAASWARD;
            printf("��ӭ����,����Ա\n");
            return;
        } else {
            printf("�������\n");
        }
    }
    for ( p=pusrlist->head; p; p=p->next ) {
        if ( p->usr.account == account ) {
            noaccount = 0;
            printf("����������: ");
            scanf("%ld", &passward);
            if ( p->usr.passward == passward ) {
                pusr->account = account;
                pusr->passward = passward;
                printf("��¼�ɹ�\n");
                break;
            } else {
                printf("�������\n");
                break;
            }
        }
        printf("1\n");
        printf("%ld\n",p->usr.account);
        printf("%p\n", &p->next);
        system("pause");
    }
    if ( noaccount ) {
        printf("�޴��û�\n");
    }
}
