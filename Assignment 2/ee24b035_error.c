/*
Name : Likhit Datta Tammana
Roll no : EE24B035
Date : 22/08/2024
Description : Finding error in sin(x) using truncated value
input : value of x
output : estimated value and error in sin(x)
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int factorial(int a)
{
    if(a<0)
    {
        printf("-ve factorial dont exist\n");
        exit(0);
    }
    int f=1;
    for(int j=1;j<=a;j++)
        f*=j;
    return f;
}
int main(int argc, char **argv)
{
    if(argc!=3)
    {
        printf("Usage : %s <n> <x>\n",argv[0]);
        return 1;
    }
    
    int n = atoi(argv[1]);
    double x = atof(argv[2]);
    if(fabs(x)>1)
    {
        printf("Enter x between -1 and 1(preferably)\n");
        return 2;
    }

    double est, err;
    est = err =0.0;
    for(int i=0; i<=n; i+=1)
    {
        if(i%4==1)
            est += pow(x,i) / factorial(i);
        if(i%4==3)
            est += (-1) * pow(x,i) / factorial(i);
    }
    err = fabs(sin(x)-est);
    printf("Estimated value is = %.6f \nError in value is = %.6f \n",est,err);
    return 0;
}
