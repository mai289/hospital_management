#ifndef _USRWAY_H_
#define _USRWAY_H_

// 添加用户信息文件路径
#define USR_FILE "../Information/usr.info"

#define ROOT_ACCOUNT 0
#define ROOT_PAASWARD 10086

// 用户信息
typedef struct _Usr {
    long account;
    long passward;
} Usr;

//  用户节点
typedef struct _Usr_Node {
    Usr usr;
    struct _Usr_Node* next;
} Usr_node;

// 用户链表
typedef struct _Usrlist {
    Usr_node* head;
    Usr_node* tail;
} Usrlist;

#include "loadusr.h"

// 登录界面
void usrway(Usrlist* pusrlist, Usr* pusr);

#endif