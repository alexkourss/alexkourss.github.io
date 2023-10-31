#include <stdlib.h>
#include <stdio.h>
//long long* numbers;
int main(int argc, char **argv) {
   
    if (argc != 3) { //if the initial arguments are not 3 then the program stops
    	printf("program must be called with three arguments\n");
	return 1;
    }	
    long long N;
    int Max = 0;
    int temp = 0;
    
    int start = atoi(argv[1]); // start of the loop
    int end = atoi(argv[2]); // end of the loop
    //printf("start: %d end: %d\n",start,end);
    int* counters = (int*)malloc((end+1)*sizeof(int));     
    if (counters == NULL) {
    printf("Memory allocation failed\n");
    return 1;
}
    for (int i = 0; i <= end; i++) {
    counters[i] = i;
    //printf("%d\n",counters[i]);
} 
printf("%d",counters[end]);
return 0;
   int counter;
    //numbers = (long long*)malloc(100000000 * sizeof(int));


    /* printf("%d",counters[10]);
    for (int i = 0; i < end; i++) {
	numbers[i] = start + i; 
	//printf("number[%d]: %d\n",i,numbers[i]);
    }*/
    if (start < 1 || start > 100000000 || end < 1 || end > 100000000 ) { // Checks if the start and the end of loop are greater than 0 and smaller than 100.000.000
	//printf("0\n");
        return 0;
    }
    
    for (int i = start; i <= end; i++) { //This loop is used to check every number in a given range
	N = i; // Changing the value of N to the number of the current loop
	int found = 0;
	counter = 0;
	while (N != 1) {  // Calculates the length
		counter += 1;
		if (N % 2 == 0) {
	    	
		
		if (counters[N/2] != 0){
			printf("%d\n",counters[N/2LL]);
			//printf("counter before %d counter after %lld counter inside %lld number: %lld initial number: %d\n",counter,counter + counters[(N)/2],(N)/2,N,i);
			counter += counters[(N)/2];
			printf("counter: %d\n",counter);
			N = 1;
			found = 1;
		}
		if (N != 1) {
			N /= 2;
		}

	}	
		else  {
	    	N = (3 * N + 1 );
                
		}
	}
	if (found == 0) {
		//printf("here");
		counter += 1;
	}
	if (counter > Max) { //Checking if the current length is the bigest one 
			  //if it is then we change the value of Max to counter
            Max = counter;
        }
	
	counters[i] = counter;
	//printf("counters: %lld temp: %d numbers: %lld number: %d\n" ,counters[i],temp,numbers[temp],i);
	temp += 1;
	     //Setting counter to 0 for the next number
    }
    //free(numbers);
    free(counters);
    printf("%d\n",Max); //Outputs the biggest length
    return 0;
}
