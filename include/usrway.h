#ifndef _USRWAY_H_
#define _USRWAY_H_

// ����û���Ϣ�ļ�·��
#define USR_FILE "../Information/usr.info"

#define ROOT_ACCOUNT 0
#define ROOT_PAASWARD 10086

// �û���Ϣ
typedef struct _Usr {
    long account;
    long passward;
} Usr;

//  �û��ڵ�
typedef struct _Usr_Node {
    Usr usr;
    struct _Usr_Node* next;
} Usr_node;

// �û�����
typedef struct _Usrlist {
    Usr_node* head;
    Usr_node* tail;
} Usrlist;

#include "loadusr.h"

// ��¼����
void usrway(Usrlist* pusrlist, Usr* pusr);

#endif