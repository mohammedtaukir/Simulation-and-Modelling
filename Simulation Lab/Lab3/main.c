#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define a 5
#define b 3
#define m 16
int main()
{
    int f[20]={ },rn,i,j,r0=45;
    float E,chi_sq=0,chi_sptab=24.96;
    for(i=0;i<100;i++)
    {
        rn=(a*r0+b)% m;
        r0=rn;
        for(j=0;j<16;j++)
        {
            if(j==rn)
            {
                f[j]=f[j]+1;
            }
        }
    }
    printf("The frequency are:\n");
    for(i=0;i<16;i++)
    {
        printf("%d\n",f[i]);
    }
    E=100.0/16.0;
    for(i=0;i<16;i++)
    {
        chi_sq=chi_sq+pow((f[i]-E),2)/E;
    }
    printf("\nThe calculated value of Chi-Square is %f\n",chi_sq);
    if(chi_sptab > chi_sq)
    {
        printf("\nH0 is not rejected.");
    }
    else
    {
        printf("\nH0 is rejected");
    }
    return 0;
}
