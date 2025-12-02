#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
    FILE* file;
int current= 50;
int pos=0;
char dir;
int counter=0;

int items_read=0;
    file= fopen("input.txt", "r");

    while((items_read=fscanf(file, " %c%d", &dir,&pos)) == 2){
if(pos>100){
    for(int i=0; i < (pos/100); i++){
            counter++;
        }
       int remainder=pos%100;

        if(dir == 'L'){
            current = (100 + current - remainder)%100;
        }else if (dir == 'R') {
            
            current = (current + remainder) % 100;
        } else {
            
        } 
        if(current==0){
            counter++;
        }

 
    }else{
        if(dir == 'L'){
            current = (100 + current - pos)%100;
        }else if (dir == 'R') {
            
            current = (current + pos) % 100;
        } else {
            
        }
        if(current==0){
            counter++;
        }
    }
}
    fclose(file);
    printf("The actual password is: %d\n", counter);


    return 0;
}