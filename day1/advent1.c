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
if(file == NULL){
    printf("Error reading file");
}

    while((items_read=fscanf(file, " %c%d", &dir,&pos)) == 2){
        for(int i =0; i<pos;i++){
            
            
            if(dir == 'L'){
                current = (100 + current - 1)%100;
            }else if (dir == 'R') {
                current = (current + 1) % 100;
            }else{
                printf("Wrong direction input");
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