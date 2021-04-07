#define true 1
#define false 0
#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/multicore.h"
#include <malloc.h>
int counter=0;
int coreflag=true;
int current=0;
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
        //printf("Hello from core1\t%d\n",counter);
        if(coreflag==true){
            int oldcurrent = current;
            current++;
            coreflag=false;
            if(checkprime(oldcurrent)){
                counter++;
                printf("Core1\t%d\n",oldcurrent);
            }
            else{
                printf("Core1 Meh\n");
            }   
        }
        else{
            counter++;
            printf("Weird!");
        }
    }
}
int main(){
    stdio_init_all();
    sleep_ms(3000);
    printf("A");
    multicore_launch_core1(core1);
    printf("B");
    while(true){
        //printf("Hello from core0\t%d\n",counter);
        if(coreflag==false){
            int oldcurrent = current;
            current++;
            coreflag=true;
            if(checkprime(oldcurrent)){
                counter++;
                printf("Core0\t%d\n",oldcurrent);
            }
            else{
                printf("Meh2\n");
            }
        }
        else{
            printf("MMMMMMEEEEEHHH\n");
        }
    }
}