#include <stdio.h>
#include <stdlib.h>
#include "addusr.h"
#include "usrway.h"

void addusr(Usrlist* pusrlist, Usr* pusr)
{
    FILE* pfusr = fopen(USR_FILE, "a");

    // �����ڵ�
    Usr_node *p = (Usr_node*)malloc(sizeof(Usr_node));
    p->next = NULL;
    p->usr.account = -1;
    p->usr.passward = -1;

    printf("�������˺�: ");
    scanf("%ld", &p->usr.account);

    // ����Ƿ��Ѵ��ڸ��û���Ϣ
    Usr_node* q = NULL;
    for ( q=pusrlist->head; q; q=q->next ) {
        if ( p->usr.account == q->usr.account ) {
            printf("�Ѵ��ڸ��û�\n");
            free(p);
            return;
        } else if ( p->usr.account <= 0 ) {
            printf("��Ч�˺�\n");
            free(p);
            return;
        }
    }

    int result = 0;
    long passward = 0;
    long passagain = 0;
    printf("����������: ");
    scanf("%ld", &passward);
    if ( passward < 0 ) {
        printf("���벻��Ϊ����,����������\n");
    } else if ( passward < 100000 ) {
        printf("�������,����������\n");
    } else {
        printf("��ȷ������: ");
        scanf("%ld", &passagain);
        if ( passagain == passward ) {
            p->usr.passward = passward;
            result = 1;
        } else {
            printf("���벻һ��\n");
        }
    }

    if ( result ) {
        // ���ڵ���뵽β��
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

        // �����û���Ϣ
        if ( fwrite(&pusrlist->tail->usr, sizeof(Usr), 1, pfusr) == 1 ) {
            printf("�û�ע��ɹ�\n");
        } else {
            printf("�û���Ϣ����ʧ��\n");
        }
    }

    free(p);
    fclose(pfusr);
}