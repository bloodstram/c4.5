#ifndef MYLINKEDLIST
#define MYLINKEDLIST

#include <stdlib.h>
#include <stdbool.h>

typedef struct MyLinkNode
{
    int m_iValue;
    struct MyLinkNode* m_pNext;
}mylinknode_t;

int linkedListLen(mylinknode_t* a_pHead);
mylinknode_t* linkedListAdd(mylinknode_t* a_pHead, int a_iNewNodeValue, bool  a_bUnique);//if a_bUnique is true, node value cannot repeat.
mylinknode_t* linkedListRemove(mylinknode_t* a_pHead, int a_iDelNodeValue);
void linkedListClear(mylinknode_t* a_pHead);
mylinknode_t* nodeAdd(mylinknode_t* a_pHead, mylinknode_t* a_pNew);
mylinknode_t* nodeUniqAdd(mylinknode_t* a_pHead, mylinknode_t* a_pNew);
mylinknode_t* nodeRemove(mylinknode_t* a_pHead, mylinknode_t* a_pRemove);

#endif
