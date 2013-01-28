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

void nodeAdd(mylinknode_t* a_pHead, mylinknode_t* a_pNew)
{
    if(a_pHead == NULL)
    {
        a_pHead = a_pNew;
    }
    else
    {
        mylinknode_t* l_pTail = a_pHead;
        while(l_pTail->m_pNext)
        {
            l_pTail = l_pTail->m_pNext;
        }
        l_pTail->m_pNext = a_pNew;
    }
}

void nodeRemove(mylinknode_t* a_pHead, mylinknode_t* a_pRemove)
{
    mylinknode_t* l_pRoot = a_pHead;
    mylinknode_t* l_pPrev = NULL;
    while(l_pRoot)
    {
        if(l_pRoot.m_iValue == a_pRemove.m_iValue)
        {
            if(l_pRoot == a_pHead)
            {
                a_pHead = l_pRoot->m_pNext;
            }
            else
            {
                l_pPrev->m_pNext = l_pRoot->m_pNext;
            }
            break;
        }
        l_pPrev = l_pRoot;
        l_pRoot = l_pRoot->m_pNext;
    }
}
