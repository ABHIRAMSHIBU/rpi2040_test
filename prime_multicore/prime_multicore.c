#define true 1
#define false 0
#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/multicore.h"
#include <malloc.h>
int value=0;
int done=false;
int out=false;
int count=0;
int checkprime(int number){
    if(number==0){
        return false;
    }
    else if(number==1){
        return false;
    }
    else if(number==2){
        return true;
    }
    else{
        for(int i=2;i<number;i++){
            if(number%i==0){
                return false;
            }
            else{
                return true;
            }
        }
    }
}
void core1(){
    while(true){
        done=false;
        int oldval=value;
        if(checkprime(oldval)){
            out=true;
            //count++;
            printf("%A%d\t%d\tcore1\n",oldval,count);
        }
        else{
            out=false;
        }
        done=true;
        while(oldval==value){
        }
        if(count%1000<=10){
            printf("B%d\n",count);
        }
    }
}
int main() {
    stdio_init_all();
    int flag=true;
    char c=0;
    while(c!='\n'){
        c=getchar();
    }
    int i=-1;
    while(true){
        i++;
        value=i;
        if(flag){
            multicore_launch_core1(core1);
            flag = false;
        }
        i++;
        if(checkprime(i)){
            count++;
            printf("A%d\t%d\tcore0\n",i,count);
        }
        while(done!=true){}
        if(out){
            count++;
        }
    }
    return 0;
}

