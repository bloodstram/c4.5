#include "c4_5.h"

/*compute the entropy of a dataset*/

//function: compute entropy for the dataset of bool type
//variable:
//  var - dataset array
//  n - length of var
float entropyCompute_Bool(const bool* var, int n)
{
    float l_fEntropy = 0.0f;
    int l_iVar = 2; //number of classes (true or false)
    
    int i; // just for loop
    
    printf("Compute entropy for boolean dataset:\n");
    for(i=0; i<n; i++)
    {
        printf("%d ", var[i]);
    }
    printf("\n");
    
    int l_iTrue = 0;
    for(i=0; i<n; i++)
    {
        if(var[i] == true)
        {
            l_iTrue++;
        }
    }
    float l_fP[2];
    l_fP[0] = (float)l_iTrue / (float)n;
    l_fP[1] = (float)(n - l_iTrue) / (float)n;
    
    for(i=0; i<l_iVar; i++)
    {
        l_fEntropy += -l_fP[i] * log2(l_fP[i]);
    }
    
    return l_fEntropy;
}

//function: compute entropy for the dataset of categorical type
//variable:
//  var - dataset array
//  n - length of var
float entropyCompute_Catg(const int* var, int n)
{
    float l_fEntropy = 0.0f;
    
    //find out how many categories in the dataset
    int i;
    mylinknode_t* categlist = NULL;
    for(i=0; i<n; i++)
    {
        categlist = linkedListAdd(categlist, var[i], true); //use uniqueadd
    }
    //display results
/*    printf("Original category array:\n");*/
/*    for(i=0; i<n; i++)*/
/*    {*/
/*        printf("%d ", var[i]);*/
/*    }*/
/*    printf("\n");*/
/*    printf("Final category list:\n");*/
/*    mylinknode_t* l_pTmp = categlist;*/
/*    while(l_pTmp)*/
/*    {*/
/*        printf("%d ", l_pTmp->m_iValue);*/
/*        l_pTmp = l_pTmp->m_pNext;*/
/*    }*/
/*    printf("\n");*/

    int l_iCategNum = linkedListLen(categlist);
    int* l_pVarPerCateg = (int *)malloc(l_iCategNum * sizeof(int));
    for(i=0; i<l_iCategNum; i++)
    {
        l_pVarPerCateg[i] = 0;
    }
    
    for(i=0; i<n; i++)
    {
        int j=0;
        mylinknode_t* l_pTmp = categlist;
        while(l_pTmp)
        {
            if(l_pTmp->m_iValue == var[i])
            {
                break;
            }
            j++;
            l_pTmp = l_pTmp->m_pNext;
        }
        l_pVarPerCateg[j]++;
    }
    
    for(i=0; i<l_iCategNum; i++)
    {
        float l_fP = (float)l_pVarPerCateg[i]/(float)n;
        l_fEntropy += -l_fP * log2(l_fP);
    }
    
    //release memory
    linkedListClear(categlist);
    free(l_pVarPerCateg);
    
    return l_fEntropy;
}
