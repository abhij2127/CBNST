//Iteration Method
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define EPOC 0.0005
#define F(x) x*x*x-2*x+1
#define g(x) (x*x*x+1)/2

void Iter(float x0, float e, int N);

int main(int argc, char const *argv[]) {
    float x0, x1; //initial guess
    float e; //tolerable error
    int t; //number of iteration allowed
    int step = 1;
    float error;
    printf("Enter Initial guess : ");
    scanf("%f", &x0);
    printf("Enter tolerable error : ");
    scanf("%f", &e);
    printf("Enter number of iterations allowed : ");
    scanf("%d",&t);
    Iter(x0, e, t);
    /***printf("\n\tstep\tx0\tf(x0)\tx1\tf(x1)\n");
    do{
        x1 = g(x0);
        printf("\t%d\t%f\t%f\t%f\t%f\n", step, x0, F(x0), x1, F(x1));
        step = step+1;
        if(step>t){
            printf("Do not converges in given number of iterations\n");
            break;
        }
        x0 = x1;
    }while(fabs(F(x1))>e);**/
    return 0;
}

void Iter(float x0, float e, int N){
    float x1;
    float f0, f1;
    float error;
    int step = 1;

    printf("\n\tstep\tx0\tf(x0)\tx1\tf(x1)\n");

    do{
        x1 = g(x0);
        printf("\t%d\t%f\t%f\t%f\t%f\n", step, x0, F(x0), x1, F(x1));
        error = fabs(x0 - x1);
        if(error<EPOC){
            break;
        }
        x0 = x1;
        step+=1;
        if(step>N){
            printf("Do not converges\n");
            return;
        }

    }while(fabs(F(x1))>e);
    printf("Root is : ", x1);
}
