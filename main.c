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
    // 清空终端
    system("cls");

    // 创建链表
    List list;
    list.head = NULL;
    list.tail = NULL;
    list.number = 0;
    Usrlist usrlist;
    usrlist.head = NULL;
    usrlist.tail = NULL;

    // 读取学生信息
    loadStudent(&list);

    // 读取用户信息
    loadusr(&usrlist);

    // 登录
    Usr usr = {-1,-1};
    usrway(&usrlist, &usr);

    while ( true )
    {
        // 显示提示并等待输入
        prompt();
        char inputch = _getch();
        printf("\n");
        switch (inputch)
        {
        case '1': // 录入学生信息
            inputStudent(&list);
            break;
        case '2': // 打印学生信息
            printStudent(&list);
            break;
        case '3': // 统计学生人数
            countStudent(&list);
            break;
        case '4': // 查找学生信息
            seekStudent(&list);
            break;
        case '5': // 修改学生信息
            modifyStudent(&list);
            break;
        case '6': // 删除学生信息
            deleteStudent(&list);
            break;
        case '7': // 按学号排序
            sortStudent(&list);
            break;
        case '8': // 退出系统
            system("cls");
            printf("欢迎再次使用,再见\n");
            exit(0);
        default:
            break;
        }

        // 暂停程序
        system("pause");
        // 清空终端
        system("cls");
        // 清空缓冲区
        fflush(stdin);
    }

    return 0;
}

void prompt()
{
    printf("*********************************\n");
    printf("*\t学生信息管理系统\t*\n");
    printf("*********************************\n");
    printf("*\t请选择功能列表\t\t*\n");
    printf("*********************************\n");
    printf("*\t1.录入学生信息\t\t*\n");
    printf("*\t2.打印学生信息\t\t*\n");
    printf("*\t3.统计学生人数\t\t*\n");
    printf("*\t4.查找学生信息\t\t*\n");
    printf("*\t5.修改学生信息\t\t*\n");
    printf("*\t6.删除学生信息\t\t*\n");
    printf("*\t7.按成绩排序\t\t*\n");
    printf("*\t8.退出系统\t\t*\n");
    printf("*********************************\n");
    printf("\n");
}

void inputStudent(List *plist)
{
    // 创建节点
    Node *p = (Node *)malloc(sizeof(Node));
    p->next = NULL;
    printf("请输入学生信息:\t\t(格式: 学号 姓名 性别 语文成绩 数学成绩 英语成绩)\n");
    scanf("%d %s %s %d %d %d", &p->student.stunum, p->student.name, p->student.gender,
          &p->student.score.Chinese, &p->student.score.Math, &p->student.score.English);

    // 检查是否已存在该学生信息
    Node* q = NULL;
    for ( q=plist->head; q; q=q->next ) {
        if ( q->student.stunum == p->student.stunum ) {
            printf("已录入该学生信息\n");
            return;
        }
    }

    // 将节点插入到尾部
    if ( plist->head ) {
        plist->tail = plist->tail->next = p;
    } else {
        plist->tail = plist->head = p;
    }
    plist->number++;
    printf("录入学生信息成功\n");

    // 保存学生信息到文件
    saveStudent(plist);
}

void printStudent(const List *plist)
{
    Node *p;
    for ( p = plist->head; p; p = p->next ) {
        printf("学 号:    %d\n", p->student.stunum);
        printf("姓 名:    %s\n", p->student.name);
        printf("性 别:    %s\n", p->student.gender);
        printf("语文成绩: %d\n", p->student.score.Chinese);
        printf("数学成绩: %d\n", p->student.score.Math);
        printf("英语成绩: %d\n", p->student.score.English);
        printf("\n");
    }
}

void countStudent(const List *plist)
{
    printf("学生总人数为%d\n", plist->number);
}

void seekStudent(const List *plist)
{
    printf("请输入查找学生的学号或姓名:");
    char seek_info[10] = {'\0'};
    scanf("%s", seek_info);
    printf("\n");
    Node *p;
    int result = 1;
    for ( p=plist->head; p; p=p->next) {
        char str_stunum[20];
        sprintf(str_stunum,"%d",p->student.stunum);
        if ( !strcmp(seek_info,p->student.name) || !strcmp(seek_info,str_stunum) ) {
            printf("学 号:    %d\n", p->student.stunum);
            printf("姓 名:    %s\n", p->student.name);
            printf("性 别:    %s\n", p->student.gender);
            printf("语文成绩: %d\n", p->student.score.Chinese);
            printf("数学成绩: %d\n", p->student.score.Math);
            printf("英语成绩: %d\n", p->student.score.English);
            printf("\n");
            result = 0;
        }
    }
    if ( result ) {
        printf("未找到该学生\n");
    }
}

void saveStudent(const List* plist)
{
    Node* p;
    FILE* pfstu = fopen(STUFILE, "w");
    if ( pfstu == NULL ) {
        printf("文件加载失败\n");
        return;
    }
    for ( p=plist->head; p; p=p->next) {
        if ( fwrite(&p->student, sizeof(Student), 1, pfstu) != 1 ) {
            printf("保存%s错误", p->student.name);
        }
    }
    FILE* pfnum = fopen(NUMFILE, "w");
    if ( pfnum == NULL ) {
        printf("文件加载失败\n");
        return;
    }
    if ( fwrite(&plist->number, sizeof(int), 1, pfnum) != 1 ){
        printf("学生数量保存错误");
    }
    fclose(pfstu);
    fclose(pfnum);
}

void loadStudent(List* plist)
{
    FILE* pfstu = fopen(STUFILE, "r");
    if ( !pfstu ) {
        printf("未找到文件,已跳过读取\n");
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
        printf("未找到文件,已跳过读取\n");
        return;
    }
    if ( fread(&plist->number, sizeof(int), 1, pfnum) != 1 ) {
        printf("读取文件错误\n");
    }
    free(pfresh);
    fclose(pfstu);
    fclose(pfnum);
}

void modifyStudent(List* plist)
{
    int stunum = 0;
    printf("请输入学生学号: ");
    scanf("%d", &stunum);
    Node* p;
    int result = 1;
    for ( p=plist->head; p; p=p->next ) {
        if ( p->student.stunum == stunum ) {
            printf("请输入学生姓名,性别,语文成绩,数学成绩,英语成绩: ");
            scanf("%s %s %d %d %d", p->student.name, p->student.gender, &p->student.score.Chinese, \
            &p->student.score.Math, &p->student.score.English);
            printf("保存学生信息成功\n");
            result = 0;
            break;
        }
    }
    if ( result ) {
        printf("未找到学生信息\n");
    }
    saveStudent(plist);
}

void deleteStudent(List* plist)
{
    int stunum = 0;
    printf("请输入学生学号: ");
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
            printf("学生信息删除成功\n");
            free(p);
            p = NULL;
            result = 0;
            break;
        }
    }
    if ( result ) {
        printf("未找到该学生\n");
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
    printf("已按学号排序\n");
    saveStudent(plist);
}

