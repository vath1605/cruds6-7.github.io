#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>
    int code[100],qty[100];
    char name[100][30];
    float price[100];
    int i,n,op;
    
    void input(){
        printf("_______________ [ Product %d ] _______________\n",i+1);
        printf("> Input product code : ");scanf("%d",&code[i]);
        printf("> Input product name : ");scanf("%s",name[i]);
        printf("> Input product qty : ");scanf("%d",&qty[i]);
        printf("> Input prodcut price : ");scanf("%f",&price[i]);
    }
    
    float total(){
        return price[i]*qty[i];
    }

    int dis(){
        if(total()>=1 && total()<10){
            return 5;
        }else if(total()>=10 && total()<20){
            return 10;
        }else{
            return 15;
        }
    }

    float payment(){
        return total() - dis()*total()/100;
    }
    
    void header(){
        printf("%10s %10s %10s %10s %10s %10s %10s \n","Name","Code","QTY","Price","Total","Discount","Payment");
    }
    void output(){
        printf("%10s %10d %10d %10.2f %10.2f %10d %10.2f\n",name[i],code[i],qty[i],price[i],total(),dis(),payment());
    }
    int main(){
        do{

        printf("__________________ E-Mart __________________\n");
        printf("| > 1. Input Product Information .         |\n");
        printf("| > 2. Output Product Information .        |\n");
        printf("| > 3. Search Product Information .        |\n");
        printf("| > 4. Update Product Information .        |\n");
        printf("| > 5. Delete Product Information .        |\n");
        printf("| > 6. Insert Product Information .        |\n");
        printf("| > 7. Sort Product Information .          |\n");
        printf("| > 8. Add Product .                       |\n");
        printf("| > 9. Cashing Money .                     |\n");
        printf("| > 10. Clear Screen .                     |\n");
        printf("| > 11. Exit Program .                     |\n");
        printf("|__________________________________________|\n");
        printf("->> Pick any option : ");scanf("%d",&op);
            switch(op){
                case 1:{
                    printf("_________________ INPUT PRODUCT _________________\n");
                    printf("> input number of product : ");scanf("%d",&n);
                    for(i=0 ; i<n ; i++){
                        input();
                    }
                }break;
                case 2:{
                    printf("_________________ OUTPUT PRODUCT _________________\n");
                    header();
                    for(i=0;i<n;i++){
                        output();
                    }
                }break;
                case 3:{
                    printf("_________________ SEARCH PRODUCT _________________\n");
                    int sCode;
                    bool isFound = false;
                    printf("> Input Product Code To Search: ");scanf("%d",&sCode);
                    for(i=0;i<n;i++){
                        if(sCode == code[i]){
                            header();
                            output();
                            isFound=true;
                        }
                    }
                    if(isFound){
                        printf("Searching Product Successfully...\n");
                    }else{
                        printf("Searching Product Is Not Found... \n");
                    }
                }break;
                case 4:{
                    printf("_________________ UPDATE PRODUCT _________________\n");
                    int uCode;
                    bool isUpdated = false;
                    printf(" > Input Product Code To Update: ");scanf("%d",&uCode);
                    for(i=0;i<n;i++){
                        if(uCode == code[i]){
                            input();
                            isUpdated=true;
                        }
                    }
                    if(isUpdated){
                        printf("Product Information Updated Successfully...\n");
                    }else{
                        printf("Product Information Cannot Update...\n");
                    }
                }break; 
                case 5:{
                    printf("_________________ DELETE PRODUCT _________________\n");
                    int dCode;
                    bool isDeleted = false;
                    printf("> Input Product Code To Delete: ");scanf("%d",&dCode);
                    for(i=0;i<n;i++){
                        if(dCode==code[i]){
                            for(int j=i;j<n;j++){
                                code[j]=code[j+1];
                                strcpy(name[j],name[j+1]);
                                qty[j]=qty[j+1];
                                price[j]=price[j+1];
                            }
                            n--;
                            isDeleted = true;
                        }
                    }
                    if(isDeleted){
                        printf("Product Information Deleted Successfully...\n");
                    }else{
                        printf("Product Information Cannot Delete...\n");
                    }
                }break;
                case 6:{
                    printf("_________________ INSERT PRODUCT _________________\n");
                    int iCode;
                    bool isInsert = false;
                    printf("> Input Prodcuct Code To Insert: ");scanf("%d",&iCode);
                    for(i=0;i<n;i++){
                        if(iCode==code[i]){
                            isInsert=true;
                        }
                    }
                    if(isInsert){

                    }else{
                        printf("Invalid Code...\n");
                        break;
                    }
                    for(i=0;i<n;i++){
                        if(iCode==code[i]){
                            for(int j=n;j>=i;j--){
                                code[j]=code[j-1];
                                strcpy(name[j],name[j-1]);
                                qty[j]=qty[j-1];
                                price[j]=price[j-1];
                            }
                            n++;
                            input();
                            printf("Insert Product Is Successfully...\n");
                            break;
                        }
                    }
                }break;
                case 7:{
                    printf("_________________ SORT PRODUCT _________________\n");
                    int tCode,tQty;
                    char tName[30];
                    float tPrice;
                    bool isSorted = false;
                    for(i=0;i<n;i++){
                        for(int j=i+1;j<n;j++){
                            if(price[i]<price[j]){
                                tCode=code[i];
                                code[i]=code[j];
                                code[j]=tCode;

                                tQty = qty[j];
                                qty[j]=qty[i];
                                qty[i] = tQty;

                                tPrice = price[i];
                                price[i] = price[j];
                                price[j] = tPrice;

                                strcpy(tName,name[i]);
                                strcpy(name[i],name[j]);
                                strcpy(name[j],tName);

                                isSorted=true;
                            }
                        }
                    }
                    if(isSorted){
                        printf("Product Information Is Sort Successfully...\n");
                    }else{
                        printf("Prodcut Cannot Sort...\n");
                    }
                }break;
                case 8:{
                    printf("_________________ ADD PRODUCT _________________\n");
                    int newPro;
                    printf("> Input Number Of New Product: ");scanf("%d",&newPro);
                    for(i=n;i<n+newPro;i++){
                        input();
                    }
                    n+=newPro;
                    printf("Product Added Successfully...\n");
                }break;
                case 9:{
                    printf("_________________ CASHING MONEY _________________\n");
                    float money,invoid=0,subMoney;
                    for(i=0;i<n;i++){
                        invoid+=payment();
                    }
                    printf("Total Amount : %.2f \n",invoid);
                    printf("> Input Money For Cashing: ");scanf("%f",&money);
                    if(money>invoid){
                        subMoney = money-invoid;
                        printf("Luy Sol : %.2f\n",subMoney);
                    }else if(invoid>money){
                        subMoney = invoid-money;
                        printf(" Bro Kvas Luy Hz , Kvas : %.2f\n",subMoney);
                    }else{
                        printf("Thanks for coming...get in later\n");
                    }
                }break;
                case 10:{
                    system("clear");
                }break;
            }
        }while(op!=11);

        return 0;
    }