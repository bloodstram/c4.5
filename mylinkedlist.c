#include "mylinkedlist.h"

int linkedListLen(mylinknode_t* a_pHead)
{
    int l_iLen = 0;
    mylinknode_t* l_pTmp = a_pHead;
    while(l_pTmp)
    {
        l_iLen++;
        l_pTmp = l_pTmp->m_pNext;
    }
    return l_iLen;
}

mylinknode_t* linkedListAdd(mylinknode_t* a_pHead, int a_iNewNodeValue, bool a_bUnique)
{
    mylinknode_t* l_pNewNode = (mylinknode_t *)malloc(sizeof(mylinknode_t));
    l_pNewNode->m_iValue = a_iNewNodeValue;
    l_pNewNode->m_pNext = NULL;
    
    if(a_bUnique)
    {
        a_pHead = nodeUniqAdd(a_pHead, l_pNewNode);
    }
    else
    {
        a_pHead = nodeAdd(a_pHead, l_pNewNode);
    }
    return a_pHead;
}

mylinknode_t* linkedListRemove(mylinknode_t* a_pHead, int a_iDelNodeValue)
{
    //find all nodes which have same value as input(a_iDelNodeValue)
    bool l_bFinish = false;
    while(!l_bFinish)
    {
        mylinknode_t* l_pRemove = a_pHead;
        while(l_pRemove)
        {
            if(l_pRemove->m_iValue == a_iDelNodeValue)
            {
                break;
            }
            l_pRemove = l_pRemove->m_pNext;
        }
        if(l_pRemove == NULL)
        {
            l_bFinish = true;
        }
        else
        {
            a_pHead = nodeRemove(a_pHead, l_pRemove);
            //release memory of the removed node
            free(l_pRemove);
        }
    }
    return a_pHead;
}

mylinknode_t* nodeAdd(mylinknode_t* a_pHead, mylinknode_t* a_pNew)
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
    return a_pHead;
}

mylinknode_t* nodeUniqAdd(mylinknode_t* a_pHead, mylinknode_t* a_pNew)
{
    if(a_pHead == NULL)
    {
        a_pHead = a_pNew;
    }
    else
    {
        mylinknode_t* l_pTail = a_pHead;
        bool l_bExisted = false;
        while(1)
        {
            if(l_pTail->m_iValue == a_pNew->m_iValue)
            {
                l_bExisted = true;
                break;
            }
            if(NULL == l_pTail->m_pNext)
            {
                break;
            }
            l_pTail = l_pTail->m_pNext;
        }

        if(!l_bExisted)
        {
            l_pTail->m_pNext = a_pNew;
        }
    }
    return a_pHead;
}

mylinknode_t* nodeRemove(mylinknode_t* a_pHead, mylinknode_t* a_pRemove)
{
    mylinknode_t* l_pRoot = a_pHead;
    mylinknode_t* l_pPrev = NULL;
    while(l_pRoot)
    {
        if(l_pRoot->m_iValue == a_pRemove->m_iValue)
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
    return a_pHead;
}

void linkedListClear(mylinknode_t* a_pHead)
{
    mylinknode_t* l_pRelease = NULL;
    while(a_pHead)
    {
        l_pRelease = a_pHead;
        a_pHead = a_pHead->m_pNext;
        free(l_pRelease);
    }
}
