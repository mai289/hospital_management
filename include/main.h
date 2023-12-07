#ifndef _MAIN_H_
#define _MAIN_H_

// 添加学生信息文件路径
#define STUFILE "../Information/stu.info"
#define NUMFILE "../Information/stunum.info"

// 分数信息
typedef struct _Score
{
    int Chinese;
    int Math;
    int English;
} Score;

// 学生信息
typedef struct _Student
{
    int stunum;
    char name[20];
    char gender[4]; 
    Score score;
} Student;

// 节点
typedef struct _Node
{
    Student student;
    struct _Node *next;
} Node;

// 链表
typedef struct _List
{
    Node *head;
    Node *tail;
    int number;
} List;

// 显示提示信息
void prompt();

// 录入学生信息
void inputStudent(List *plist);

// 打印学生信息
void printStudent(const List *plist);

// 统计学生人数
void countStudent(const List *plist);

// 查找学生
void seekStudent(const List *plist);

// 保存学生信息
void saveStudent(const List* plist);

// 读取学生信息
void loadStudent(List* plist);

// 修改学生信息
void modifyStudent(List* plist);

// 删除学生信息
void deleteStudent(List* plist);

// 按学号排序
void sortStudent(List* plist);

#endif