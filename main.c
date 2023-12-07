#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <conio.h>
#include "main.h"
#include "loadusr.h"
#include "usrway.h"
#include "addusr.h"
#include "login.h"

int main()
{
    // ����ն�
    system("cls");

    // ��������
    List list;
    list.head = NULL;
    list.tail = NULL;
    list.number = 0;
    Usrlist usrlist;
    usrlist.head = NULL;
    usrlist.tail = NULL;

    // ��ȡѧ����Ϣ
    loadStudent(&list);

    // ��ȡ�û���Ϣ
    loadusr(&usrlist);

    // ��¼
    Usr usr = {-1,-1};
    usrway(&usrlist, &usr);

    while ( true )
    {
        // ��ʾ��ʾ���ȴ�����
        prompt();
        char inputch = _getch();
        printf("\n");
        switch (inputch)
        {
        case '1': // ¼��ѧ����Ϣ
            inputStudent(&list);
            break;
        case '2': // ��ӡѧ����Ϣ
            printStudent(&list);
            break;
        case '3': // ͳ��ѧ������
            countStudent(&list);
            break;
        case '4': // ����ѧ����Ϣ
            seekStudent(&list);
            break;
        case '5': // �޸�ѧ����Ϣ
            modifyStudent(&list);
            break;
        case '6': // ɾ��ѧ����Ϣ
            deleteStudent(&list);
            break;
        case '7': // ��ѧ������
            sortStudent(&list);
            break;
        case '8': // �˳�ϵͳ
            system("cls");
            printf("��ӭ�ٴ�ʹ��,�ټ�\n");
            exit(0);
        default:
            break;
        }

        // ��ͣ����
        system("pause");
        // ����ն�
        system("cls");
        // ��ջ�����
        fflush(stdin);
    }

    return 0;
}

void prompt()
{
    printf("*********************************\n");
    printf("*\tѧ����Ϣ����ϵͳ\t*\n");
    printf("*********************************\n");
    printf("*\t��ѡ�����б�\t\t*\n");
    printf("*********************************\n");
    printf("*\t1.¼��ѧ����Ϣ\t\t*\n");
    printf("*\t2.��ӡѧ����Ϣ\t\t*\n");
    printf("*\t3.ͳ��ѧ������\t\t*\n");
    printf("*\t4.����ѧ����Ϣ\t\t*\n");
    printf("*\t5.�޸�ѧ����Ϣ\t\t*\n");
    printf("*\t6.ɾ��ѧ����Ϣ\t\t*\n");
    printf("*\t7.���ɼ�����\t\t*\n");
    printf("*\t8.�˳�ϵͳ\t\t*\n");
    printf("*********************************\n");
    printf("\n");
}

void inputStudent(List *plist)
{
    // �����ڵ�
    Node *p = (Node *)malloc(sizeof(Node));
    p->next = NULL;
    printf("������ѧ����Ϣ:\t\t(��ʽ: ѧ�� ���� �Ա� ���ĳɼ� ��ѧ�ɼ� Ӣ��ɼ�)\n");
    scanf("%d %s %s %d %d %d", &p->student.stunum, p->student.name, p->student.gender,
          &p->student.score.Chinese, &p->student.score.Math, &p->student.score.English);

    // ����Ƿ��Ѵ��ڸ�ѧ����Ϣ
    Node* q = NULL;
    for ( q=plist->head; q; q=q->next ) {
        if ( q->student.stunum == p->student.stunum ) {
            printf("��¼���ѧ����Ϣ\n");
            return;
        }
    }

    // ���ڵ���뵽β��
    if ( plist->head ) {
        plist->tail = plist->tail->next = p;
    } else {
        plist->tail = plist->head = p;
    }
    plist->number++;
    printf("¼��ѧ����Ϣ�ɹ�\n");

    // ����ѧ����Ϣ���ļ�
    saveStudent(plist);
}

void printStudent(const List *plist)
{
    Node *p;
    for ( p = plist->head; p; p = p->next ) {
        printf("ѧ ��:    %d\n", p->student.stunum);
        printf("�� ��:    %s\n", p->student.name);
        printf("�� ��:    %s\n", p->student.gender);
        printf("���ĳɼ�: %d\n", p->student.score.Chinese);
        printf("��ѧ�ɼ�: %d\n", p->student.score.Math);
        printf("Ӣ��ɼ�: %d\n", p->student.score.English);
        printf("\n");
    }
}

void countStudent(const List *plist)
{
    printf("ѧ��������Ϊ%d\n", plist->number);
}

void seekStudent(const List *plist)
{
    printf("���������ѧ����ѧ�Ż�����:");
    char seek_info[10] = {'\0'};
    scanf("%s", seek_info);
    printf("\n");
    Node *p;
    int result = 1;
    for ( p=plist->head; p; p=p->next) {
        char str_stunum[20];
        sprintf(str_stunum,"%d",p->student.stunum);
        if ( !strcmp(seek_info,p->student.name) || !strcmp(seek_info,str_stunum) ) {
            printf("ѧ ��:    %d\n", p->student.stunum);
            printf("�� ��:    %s\n", p->student.name);
            printf("�� ��:    %s\n", p->student.gender);
            printf("���ĳɼ�: %d\n", p->student.score.Chinese);
            printf("��ѧ�ɼ�: %d\n", p->student.score.Math);
            printf("Ӣ��ɼ�: %d\n", p->student.score.English);
            printf("\n");
            result = 0;
        }
    }
    if ( result ) {
        printf("δ�ҵ���ѧ��\n");
    }
}

void saveStudent(const List* plist)
{
    Node* p;
    FILE* pfstu = fopen(STUFILE, "w");
    if ( pfstu == NULL ) {
        printf("�ļ�����ʧ��\n");
        return;
    }
    for ( p=plist->head; p; p=p->next) {
        if ( fwrite(&p->student, sizeof(Student), 1, pfstu) != 1 ) {
            printf("����%s����", p->student.name);
        }
    }
    FILE* pfnum = fopen(NUMFILE, "w");
    if ( pfnum == NULL ) {
        printf("�ļ�����ʧ��\n");
        return;
    }
    if ( fwrite(&plist->number, sizeof(int), 1, pfnum) != 1 ){
        printf("ѧ�������������");
    }
    fclose(pfstu);
    fclose(pfnum);
}

void loadStudent(List* plist)
{
    FILE* pfstu = fopen(STUFILE, "r");
    if ( !pfstu ) {
        printf("δ�ҵ��ļ�,��������ȡ\n");
        return;
    }
    Node* p = NULL;
    Node* pfresh = malloc(sizeof(Node));
    while ( fread(&pfresh->student, sizeof(Student), 1, pfstu) == 1 ) {
        if ( !p ) {
            plist->head = plist->tail = p = pfresh;
            pfresh = malloc(sizeof(Node));
        } else {
            plist->tail = p = p->next = pfresh;
            pfresh = malloc(sizeof(Node));
        }
    }
    FILE* pfnum = fopen(NUMFILE, "r");
    if ( !pfnum ) {
        printf("δ�ҵ��ļ�,��������ȡ\n");
        return;
    }
    if ( fread(&plist->number, sizeof(int), 1, pfnum) != 1 ) {
        printf("��ȡ�ļ�����\n");
    }
    free(pfresh);
    fclose(pfstu);
    fclose(pfnum);
}

void modifyStudent(List* plist)
{
    int stunum = 0;
    printf("������ѧ��ѧ��: ");
    scanf("%d", &stunum);
    Node* p;
    int result = 1;
    for ( p=plist->head; p; p=p->next ) {
        if ( p->student.stunum == stunum ) {
            printf("������ѧ������,�Ա�,���ĳɼ�,��ѧ�ɼ�,Ӣ��ɼ�: ");
            scanf("%s %s %d %d %d", p->student.name, p->student.gender, &p->student.score.Chinese, \
            &p->student.score.Math, &p->student.score.English);
            printf("����ѧ����Ϣ�ɹ�\n");
            result = 0;
            break;
        }
    }
    if ( result ) {
        printf("δ�ҵ�ѧ����Ϣ\n");
    }
    saveStudent(plist);
}

void deleteStudent(List* plist)
{
    int stunum = 0;
    printf("������ѧ��ѧ��: ");
    scanf("%d", &stunum);
    Node *q, *p;
    int result = 1;
    for ( q=NULL, p=plist->head; p; q=p, p=p->next ) {
        if ( p->student.stunum == stunum ) {
            if ( q ) {
                q->next = p->next;
            } else {
                plist->head = p->next;
            }
            plist->number--;
            printf("ѧ����Ϣɾ���ɹ�\n");
            free(p);
            p = NULL;
            result = 0;
            break;
        }
    }
    if ( result ) {
        printf("δ�ҵ���ѧ��\n");
    }
    saveStudent(plist);
}

void sortStudent(List* plist)
{
    Node *p, *q;
    Student stu;
    for ( p=plist->head; p->next!=NULL; p=p->next ) {
        for ( q=p->next; q!=NULL; q=q->next ) {
            if ( p->student.stunum > q->student.stunum ) {
                stu = p->student;
                p->student = q->student;
                q->student = stu;
            }
        }
    }
    printf("�Ѱ�ѧ������\n");
    saveStudent(plist);
}

