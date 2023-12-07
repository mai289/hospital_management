#ifndef _MAIN_H_
#define _MAIN_H_

// ���ѧ����Ϣ�ļ�·��
#define STUFILE "../Information/stu.info"
#define NUMFILE "../Information/stunum.info"

// ������Ϣ
typedef struct _Score
{
    int Chinese;
    int Math;
    int English;
} Score;

// ѧ����Ϣ
typedef struct _Student
{
    int stunum;
    char name[20];
    char gender[4]; 
    Score score;
} Student;

// �ڵ�
typedef struct _Node
{
    Student student;
    struct _Node *next;
} Node;

// ����
typedef struct _List
{
    Node *head;
    Node *tail;
    int number;
} List;

// ��ʾ��ʾ��Ϣ
void prompt();

// ¼��ѧ����Ϣ
void inputStudent(List *plist);

// ��ӡѧ����Ϣ
void printStudent(const List *plist);

// ͳ��ѧ������
void countStudent(const List *plist);

// ����ѧ��
void seekStudent(const List *plist);

// ����ѧ����Ϣ
void saveStudent(const List* plist);

// ��ȡѧ����Ϣ
void loadStudent(List* plist);

// �޸�ѧ����Ϣ
void modifyStudent(List* plist);

// ɾ��ѧ����Ϣ
void deleteStudent(List* plist);

// ��ѧ������
void sortStudent(List* plist);

#endif