#include <stdlib.h>
#include <stdbool.h>

typedef struct MyLinkNode
{
    int m_iValue;
    struct MyLinkNode* m_pNext;
}mylinknode_t;

int linkedListLen(mylinknode_t* a_pHead);
void nodeAdd(mylinknode_t* a_pHead, mylinknode_t* a_pNew);
void nodeRemove(mylinknode_t* a_pHead, mylinknode_t* a_pRemove);
