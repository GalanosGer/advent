#include <stdio.h>
#include <stdlib.h>

int count_digits(long long n){
    int counter = 0;
    do {
        n /= 10;
        counter++;
    } while (n != 0);
    return counter;
}


int is_invalid(long long curr){

    int k=count_digits(curr);

    long long temp=curr;
    int digits[20];
    for(int i=k-1; i>=0; i--){
        digits[i]= temp%10;
        temp/=10;
    }

    for(int p=1; p<= k/2; p++){
        if(k % p != 0) continue;

        int valid=1;

        for(int i=p;i<k;i++){
            if(digits[i]!= digits[i % p]){
                valid=0;
                break;
            }
        }
        if(valid) return 1;

    }
    return 0;
}
int main() {
    FILE* file;

    long long u = 0;
    long long h = 0;
    long long sum = 0;
   

    file = fopen("input2.txt", "r");
    if (!file) return 1;

    while (fscanf(file, "%lld-%lld", &u, &h) == 2) {

        long long curr = u;

        while (curr <= h) {
            if(is_invalid(curr)){
                sum+=curr;
            }
            curr++;
        }
        int c = fgetc(file); // skip comma
        if (c == EOF) break;
    }

    printf("Sum is: %lld\n", sum);

    fclose(file);
    return 0;
}