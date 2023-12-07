#include <stdio.h>
#include <stdlib.h>
#include "loadusr.h"

void loadusr(Usrlist* pusrlist)
{
    FILE* pfusr = fopen(USR_FILE, "r");
    if ( pfusr == NULL ) {
        printf("读取用户账号信息失败,跳过读取\n");
        return;
    }
    Usr_node* p = NULL;
    Usr_node* pfresh = (Usr_node*)malloc(sizeof(Usr_node));
    pfresh->next = NULL;
    while ( fread(&pfresh->usr, sizeof(Usr), 1, pfusr) == 1 ) {
        if ( !p ) {
            pusrlist->head = pusrlist->tail = p = pfresh;
            pfresh = malloc(sizeof(Usr_node));
            pfresh->next = NULL;
        } else {
            pusrlist->tail = p = p->next = pfresh;
            pfresh = malloc(sizeof(Usr_node));
            pfresh->next = NULL;
        }
    }

    free(pfresh);
    fclose(pfusr);
}