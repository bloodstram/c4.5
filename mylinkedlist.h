#include <stdio.h>

typedef struct MyLinkNode
{
    int m_iValue;
    struct MyLinkNode* m_pNext;
}mylinknode_t;

int linkedListLen(mylinknode_t* a_pHead);
bool nodeAdd(mylinknode_t* a_pHead, mylinknode_t* a_pNew);
bool nodeRemove(mylinknode_t* a_pHead, mylinknode_t* a_pRemove);
