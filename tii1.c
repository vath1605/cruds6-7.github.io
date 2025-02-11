#include<stdio.h>
    int main(){ 
        float salary[12],min,max;
        for(int i=0 ; i < 12 ; i++){
            printf("> input salary in %d month : ",i+1);scanf("%f",&salary[i]);
        }
        max=salary[0];
        for(int i=0; i<12 ; i++){
            if(max < salary[i]){
                max = salary[i];
            }
        }
        printf("Max of salary : %.2f $\n",max);
        min = salary[0];
        for(int i=0; i<12 ; i++){
            if(salary[i] < min){
                min = salary[i];
            }
        }
        printf("Min of salary : %.f $\n",min);
        return 0;
    }