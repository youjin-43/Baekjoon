#include<stdio.h>
double h,w,gesu,n;
int main(void)
{
    scanf("%lf %lf %lf",&h,&w,&n);
    gesu = w*((n-2)/2);
    printf("%.20lf",gesu);
}
