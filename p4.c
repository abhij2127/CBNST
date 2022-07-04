//Secant Method
//same as regula falsi with just one small change at see below for 'here'
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define EPS 0.00005
#define F(x) x*x*x-5*x+1
int main(){
    float x0, x1, x2;
    float f0, f1, f2;
    int N;
    int step = 1;
    printf("Enter the number of iterations : ");
    scanf("%d",&N);
    for(x1=0.0; ;){
        f1 = F(x1);
        if(f1>0){
            break;
        }
        else{
            x1+=0.1;
        }
    }
    x0 = x1-0.1;
    f0 = F(x0);

    do {
        x2=x1-((x1-x0)/(f1-f0))*f1; //here
        f2 = F(x2);
        if(f0*f2>0){
            x1 = x2;
            f1 = f2;
        }
        else{
            x0 = x2;
            f0 = f2;
        }
        printf("\n\t%d\t%f\t%f\n",step,x2,f2);
        if(fabs(f2)<EPS){
            break;
        }
        step+=1;
    } while(step<=N);
    printf("Root of the equation is : %f", x2);
    return 0;
}
