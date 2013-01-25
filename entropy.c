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
    
    
    return l_fEntropy;
}
