#include<stdio.h>
#include<string.h>
    int main(){
        int stu_id[100],dis[100],n;
        char stu_name[100][30],course[100][20],gender[100][7];
        float price[100],pay[100];
        printf("______________ Input Student Information ______________\n");
        printf("> input number of student first : ");scanf("%d",&n);
        for(int i=0; i<n ; i++){
            printf("_______ Student [%d] _______\n",i+1);
            printf("> input name: ");fflush(stdin);fgets(stu_name[i],sizeof(stu_name[i]),stdin);
            printf("> input id: ");scanf("%d",&stu_id[i]);
            printf("> input gender: ");scanf("%s",gender[i]);
            printf("> input course: ");fflush(stdin);fgets(course[i],sizeof(course[i]),stdin);
        }
        for(int i=0; i<n ; i++){
            if(strcmp(gender[i],"female")==0){
                dis[i] = 50;
            }
        }

        for(int i=0; i<n ; i++){
            if(strcmp(course[i],"basic_it")==0){
                price[i] = 104.00;
                pay[i] = price[i] - dis[i]*price[i]/100;
            }else if(strcmp(course[i],"basic_code")==0){
                price[i] = 74.00;
                pay[i] = price[i] - dis[i]*price[i]/100;
            }else if(strcmp(course[i],"web_react")==0){
                price[i] = 84.00;
                pay[i] = price[i] - dis[i]*price[i]/100;
            }else if(strcmp(course[i],"network")==0){
                price[i] = 125.00;
                pay[i] = price[i] - dis[i]*price[i]/100;
            }else if(strcmp(course[i],"ui")==0){
                price[i] = 64.00;
                pay[i] = price[i] - dis[i]*price[i]/100;
            }else{
                price[i] = 150.00;
                pay[i] = price[i] - dis[i]*price[i]/100;
            }
        }
        printf("_________________ Student Information _________________\n");
        printf("%-10s %-10s %-10s %-10s %-10s %-10s %-10s \n","Student ID","Name","Gender","Course","Price","Discount","Payment");
        for(int i=0 ; i<n ; i++){
           printf("%-10d %-10s %-10s %-10s %-10.2f$ %-10d %-10.2f$ \n",stu_id[i],stu_name[i],gender[i],course[i],price[i],dis[i],pay[i]); 
        }
        return 0;
    }