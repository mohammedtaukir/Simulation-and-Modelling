#include <stdio.h>
#include <stdlib.h>
#define k1 0.008
#define k2 0.002

float chem1(float c1, float c2, float c3, float t)
{
    return(c1+(k2*c3-k1*c1*c2)*t);
}

float chem2(float c1, float c2, float c3, float t)
{
    return(c2+(k2*c3-k1*c1*c2)*t);
}

float chem3(float c1, float c2, float c3, float t)
{
    return(c3+(2*k1*c1*c2-2*k2*c3)*t);
}

int main()
{
    FILE *fp;
    fp= fopen("lab.csv","w");
    float c1=25, c2=50, c3=0, t=0, temp_c1, temp_c2, temp_c3;
    do{
            temp_c1=chem1(c1,c2,c3,t);
            temp_c2=chem2(c1,c2,c3,t);
            temp_c3=chem3(c1,c2,c3,t);
            fprintf(fp,"%f\t",t);
            fprintf(fp,"%f\t",temp_c1);
            fprintf(fp,"%f\t",temp_c2);
            fprintf(fp,"%f\n",temp_c3);
            c1=temp_c1;
            c2=temp_c2;
            c3=temp_c3;
            t+=0.25;
    }while(t<10);
    fclose(fp);
    return 0;
}
