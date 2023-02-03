#include <stdio.h>
#include <stdlib.h>
#define A11 -50
#define A22 -21.5
#define A21 -19000
#define ein 1.5
float fun1(float V1)
{
    return(A11*V1-A11*ein);
}
float fun2(float V1, float V2)
{
    return(A21*V1+A22*V2-A21*ein);
}
int main()
{
    FILE *f1;
    FILE *f2;
    f1= fopen("lab21.csv","w");
    f2= fopen("lab22.csv","w");
    int i;
    float K1,K2,K3,K4,m1,m2,m3,m4,V1new,V2new,V2=0,V1=0,t, h=0.0002;
    for(i=0;i<800;i++){
            K1=fun1(V1);
            K2=fun1(V1+K1*h/2);
            K3=fun1(V1+K2*h/2);
            K4=fun1(V1+K3*h);
            V1new=V1+((K1+2*K2+2*K3+K4)/6)*h;
            m1=fun2(V1,V2);
            m2=fun2(V1+h/2,V2+m1*h/2);
            m3=fun2(V1+h/2,V2+m2*h/2);
            m4=fun2(V1+h,V2+m3*h);
            V2new=V2+((m1+2*m2+2*m3+m4)/6)*h;
            V1=V1new;
            V2=V2new;
            t=i*h;
            fprintf(f1,"%f\t",t);
            fprintf(f1,"%f\n",V1);
            fprintf(f2,"%f\t",t);
            fprintf(f2,"%f\n",V2);
    }
    fclose(f1);
    fclose(f2);
    return 0;
}
