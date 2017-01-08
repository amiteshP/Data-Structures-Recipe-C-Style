//Program discusses how to find the minimum and maximum value in an array.

#include<stdio.h>

int main(){
    
    int arr[6];                         //an integer array declared having 6 integer bytes
    int i, min, max;
    scanf("%d", &arr[0]);               
    min = arr[0];                       //initially assigning 0th elemment as maximum and minimum
    max = arr[0];
    for(i=1; i<6; i++){
        scanf("%d", &arr[i]);           //We loop through the array and as we loop,
        if(arr[i]<min)min = arr[i];     //we check each element for min and max by
        if(arr[i]>max)max = arr[i];     //comparing it with the previous min/max(initially the 0th element).
    }
    printf("%d %d", min, max);          //Finally, we print the minimum and the maximum value.
    return 0;

}

