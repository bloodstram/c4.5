#include "mylinkedlist.h"

int linkedListLen(mylinknode_t* a_pHead)
{
    int l_iLen = 0;
    mylinknode_t* l_pRoot = a_pHead;
    while(l_pRoot)
    {
        l_iLen++;
        l_pRoot = l_pRoot->m_pNext;
    }
    return l_iLen;
}

bool nodeAdd(mylinknode_t* a_pHead, mylinknode_t* a_pNew)
{
}
