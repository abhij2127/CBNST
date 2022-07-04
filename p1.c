//Bisection Method
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define EPOCH 0.00001
#define F(x) x*log10(x)-1.2

int main(){
    float x1, x2, x0, root;
    int itr;
    int step = 1;
    printf("Enter Two intervals : ");
    scanf("%f%f",&x1,&x2);
    printf("Enter Maximun Iteration : ");
    scanf("%d",&itr);
    double f1,f2,f0;
    f1 = F(x1);
    f2 = F(x2);
    if(f1*f2>0){
        printf("Not legit Intervals!\n");
        return 0;
    }
    printf("\tstep\t\tx1\t\tx2\t\tx0\t\tf0\n");
    do{
        x0 = (x1+x2)/2;
        f1 = F(x1);
        f2 = F(x2);
        f0 = F(x0);
        printf("\t%d.\t%f\t%f\t%f\t%f\n",step, x1, x2, x0, f0);
        if(f0*f1<0){
            x2 = x0;
        }
        else{
            x1 = x0;
        }
        step+=1;
    }while (fabs(f0)>EPOCH);
    root = x0;
    printf("\t\tRoot = %f", root);
    return 0;
}
