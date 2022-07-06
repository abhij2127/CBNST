//Regula Falsi 
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define F(x) 3*x + sin(x) - exp(x)
float equate(float x0, float x1, float f0, float f1){
    return x0 - (((x1-x0)/(f1-f0))*f0);
}

int main(){
    float x2, x1, x0, f0, f1, f2;
    float e;
    int step=0, iter;
    printf("Enter two initial guesses : ");
    scanf("%f%f", &x0, &x1);
    printf("Enter maximum iteration : ");
    scanf("%d", &iter);
    printf("enter tolerable error : ");
    scanf("%f", &e);
    f0 = F(x0);
    f1 = F(x1);
    do{
        x2 = equate(x0, x1, f0, f1);
        printf("%f\n",x2);
        f2 = F(x2);
        if(f2*f0<0){
            x1 = x2;
            f1 = f2;
        }
        else{
            x0 = x2;
            f0 = f2;
        }
        step++;
        if(step>iter){
            break;
        }

    }while(fabs(f2)>e);

    printf("The desired root is : %f\n", x2);
    return 0;
}