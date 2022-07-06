#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define EPOCH 0.0001
//#define F(x) x*x*x-5*x+1
#define F(x) pow(x, 2)-30

int main(){
    float x0, x1, x2, f1, f2, f0, root;
    int iter, step=0, flag=0;
    printf("enter two initial guesses : ");
    scanf("%f%f", &x1, &x2);
    printf("Enter maximum iterations : ");
    scanf("%d", &iter);
    f1 = F(x1);
    f2 = F(x2);
    if(f1*f2>0){
        printf("Illegal Initial Guesses\n");
        exit(0);
    }
    else if(f1*f2==0){
        if(f1==0){
            printf("The root is %0.5f", x1);
        }
        else{
            printf("The root is %0.5f", x2);
        }
        exit(0);
    }
    do{
        x0 = (x1+x2)/2;
        f0 = F(x0);
        if(f0*f1<0){
            x2 = x0;
        }
        else if(f0*f2<0){
            x1 = x0;
        }
        else{
            root = x0;
            flag = 1;
            break;
        }
        printf("X0 : %f, F0 : %f\n", x0, f0);
        step++;
    }while(fabs(x1-x2)>EPOCH && step<iter);
    if(flag){
        printf("The Desired root is %0.5f", root);
    }
    else{
        root = x0;
        printf("The Desired root is %0.5f", root);
    }
    return 0;
}