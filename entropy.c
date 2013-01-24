#include "c4_5.h"

/*compute the entropy of a class variable*/

//function: compute entropy for class variable of bool type
//variable:
//  classvar - class variable array
//  n - length of classvar
float entropyCompute_Bool(const bool* classvar, int n)
{
    float l_fEntropy = 0.0f;
    int l_iVar = 2; //number of classes (true or false)
    
    int i; // just for loop
    
    printf("Compute entropy for boolean dataset:\n");
    for(i=0; i<n; i++)
    {
        printf("%d ", classvar[i]);
    }
    printf("\n");
    
    int l_iTrue = 0;
    for(i=0; i<n; i++)
    {
        if(classvar[i] == true)
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
