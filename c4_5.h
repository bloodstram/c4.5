#ifndef C4_5
#define C4_5

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

enum Outlook_t {SUNNY, OVERCAST, RAINY};

struct PlayGolf
{
    enum Outlook_t m_eOutlook;
    int m_iTemp;
    int m_iHum;
    bool m_bWindy;
    bool m_bPlay;
};

float entropyCompute_Bool(const bool* classvar, int n);
float gainCompute_Bool(struct PlayGolf* dataset, int n);

#endif
