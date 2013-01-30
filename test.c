#include "c4_5.h"

int main()
{
    //initial dataset
    struct PlayGolf l_psDataset[] = {{SUNNY, 85, 85, false, false},
                                     {SUNNY, 80, 90, true, false},
                                     {OVERCAST, 83, 78, false, true},
                                     {RAINY, 70, 96, false, true},
                                     {RAINY, 68, 80, false, true},
                                     {RAINY, 65, 70, true, false},
                                     {OVERCAST, 64, 65, true, true},
                                     {SUNNY, 72, 95, false, false},
                                     {SUNNY, 69, 70, false, true},
                                     {RAINY, 75, 80, false, true},
                                     {SUNNY, 75, 70, true, true},
                                     {OVERCAST, 72, 90, true, true},
                                     {OVERCAST, 81, 75, false, true},
                                     {RAINY, 71, 80, true, false}};
    
    
    float l_fEntropy = 0.0f;
    int i;
    
    //for bool variable
/*    bool l_pbClassVar[14];*/
/*    for(i=0; i<14; i++)*/
/*    {*/
/*        l_pbClassVar[i] = l_psDataset[i].m_bPlay;*/
/*    }*/
/*    l_fEntropy = entropyCompute_Bool(l_pbClassVar, 14);*/

    //for categorical variable
/*    int l_pOutlook[14];*/
/*    for(i=0; i<14; i++)*/
/*    {*/
/*        l_pOutlook[i] = l_psDataset[i].m_eOutlook;*/
/*    }*/
/*    l_fEntropy = entropyCompute_Catg(l_pOutlook, 14);*/
/*    */

    //for numerical variable
    float l_pfTemperature[14];
    for(i=0; i<14; i++)
    {
        l_pfTemperature[i] = l_psDataset[i].m_iTemp;
    }
    l_fEntropy = entropyCompute_Num(l_pfTemperature, 14, 70.0f);

    printf("Entropy: %f\n", l_fEntropy);
    
    return 0;
}
