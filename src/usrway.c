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
        printf("*\tѧ����Ϣ����ϵͳ\t*\n");
        printf("*********************************\n");
        printf("*\t    ��½����\t\t*\n");
        printf("*********************************\n");
        printf("*\t     1.��¼\t\t*\n");
        printf("*\t     2.ע��\t\t*\n");
        printf("*\t     3.�˳�\t\t*\n");
        printf("*********************************\n");
        printf("\n");
        inputch = _getch();
        switch ( inputch )
        {
        case '1':
            printf("***��¼***\n");
            login(pusrlist, pusr);
            break;
        case '2':
            printf("***ע��***\n");
            addusr(pusrlist, pusr);
            break;
        case '3':
            system("cls");
            printf("��ӭ�ٴ�ʹ��,�ټ�\n");
            exit(0);
        default:
            printf("�����빦��ѡ��\n");
            break;
        }

        system("pause");
        system("cls");
    }
}
