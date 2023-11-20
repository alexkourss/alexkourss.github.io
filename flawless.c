#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int flawless(unsigned long long int n,unsigned long long int target){
    unsigned long long int left;
    unsigned long long int right;
    //printf("A");
    if (n==0){
        //printf("%d",length);
        return 0;
    }
    int length = log10(n);
    
    while (length != -1){
        //printf("b");
        left = n / (unsigned long long int)pow(10,length);
        right = n % (unsigned long long int)pow(10,length);
        //printf("target: %lld\n",target);
        //printf("%lld-%lld\n",left,right);
        //printf("result: %lld\n",(left + right));
        if (left + right == target){
            //printf("here\n");
            return 1;
        }
        else{
            if (left <= target){
                  if (flawless(right,target-left)){
                    return 1;
                  }
                  
                }
        }
        length -= 1;
        if (length == 0){
            return 0;
        }
    }
    
    return 0;
}

int main(int argc, char *argv[]){
    if (argc != 3){
        return 1;
    }

    unsigned long long int start = atoll(argv[1]);
    unsigned long long int end = atoll(argv[2]);

    if (start > end || start < 1 || end > 1000000000000){
        return 1;
    }
    unsigned long long int i;
    long long sum = 0;
    int flag = 0;
    for (i = start; i <= end; i++){
        if ((int)sqrt(i) != sqrt(i)){
            continue;
        }
        //printf("%lld\n",i);
        flag = flawless(i,(unsigned long long int)sqrt(i));
        //printf("%d\n",(int)sqrt(i));
        if (flag){
            sum += i;
        }
    }
    printf("%lld\n",sum);
    return 0;
}