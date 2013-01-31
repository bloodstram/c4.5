#include "c4_5.h"

/* compute the GAIN of class variable when it is divided into several subsets by attribute variable */

//function: compute gain for class variable divided by boolean attribute variable
//arguments:
//  attribvar - attribute variable
//  classvar - class variable
//  n - length of dataset
float gainCompute_Bool(const bool* attribvar, const bool* classvar, int n)
{
    float l_fGain = 0.0f;
    int i;
    
    //compute entropy of classvar
    float l_fOrigEntropy = entropyCompute_Bool(classvar, n);
    
    //divide classvar in two subset by attribvar
    int l_iTrues = 0;
    for(i=0; i<n; i++)
    {
        if(true == attribvar[i])
        {
            l_iTrues++;
        }
    }
    bool* l_pbSubClassvar1 = (bool *)malloc(l_iTrues * sizeof(bool));
    bool* l_pbSubClassvar2 = (bool *)malloc((n - l_iTrues) * sizeof(bool));
    int c1=0, c2=0;
    for(i=0; i<n; i++)
    {
        if(true == attribvar[i])
        {
            l_pbSubClassvar1[c1++] = classvar[i];
        }
        else
        {
            l_pbSubClassvar2[c2++] = classvar[i];
        }
    }
    
    //compute entropy for subsets
    float l_fEntropy1 = entropyCompute_Bool(l_pbSubClassvar1, l_iTrues);
    float l_fEntropy2 = entropyCompute_Bool(l_pbSubClassvar2, (n - l_iTrues));
    
    l_fGain = l_fOrigEntropy - (((float)l_iTrues/(float)n)*l_fEntropy1 + ((float)(n - l_iTrues)/(float)n)*l_fEntropy2);
    
    //release memory
    free(l_pbSubClassvar1);
    free(l_pbSubClassvar2);
    l_pbSubClassvar1 = NULL;
    l_pbSubClassvar2 = NULL;
    
    return l_fGain;
}

//function: compute gain for class variable divided by categorical attribute variable
//arguments:
//  attribvar - attribute variable
//  classvar - class variable
//  n - length of dataset
float gainCompute_Catg(const int* attribvar, const bool* classvar, int n)
{
    float l_fGain = 0.0f;
    
    return l_fGain;
}

//function: compute gain for class variable divided by categorical attribute variable
//arguments:
//  attribvar - attribute variable
//  classvar - class variable
//  n - length of dataset
float gainCompute_Num(const float* attribvar, const bool* classvar, int n)
{
    float l_fGain = 0.0f;
    
    return l_fGain;
}
