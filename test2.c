// Fixed Point Iteration method
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define F(x) pow(x, 3)-2*x+1
#define f(x) (pow(x, 3) + 1)/2
#define df(x) (3*x*x)/2

int main(){
    float x1, x2, x0, f0, f1, f2, e;
    int step=0, iter;
    printf("Enter maximum tolerable error : ");
    scanf("%f", &e);
    printf("enter maximum number of iterations : ");
    scanf("%d", &iter);
    int i = 1;
    for(x1=1;;x1++){
        f1 = F(x1);
        if(f1>0){
            break;
        }
    }
    for(x2=x1-1;;x2--){
        f2 = F(x2);
        if(f2<0){
            break;
        }
    }
    x0 = (x1+x2)/2;
    do{
        x1 = f(x0);
        step++;
        if(step>=iter){
            printf("Insufficient iterations! Does not converge\n");
            exit(0);
        }
        x0 = x1;
    }while(F(x1)>e);
    printf("Root of equation after %d iteration is : %f", step, x1);
    return 0;
}