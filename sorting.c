#include<stdio.h>
int main(){
   int arr[]={2,23,4,65,43,42,9,-45};
   int n=len(arr),temp=0;
   for(int i=0;i<n;i++){
       for(int j=0;j<n-i;j++){
        if(arr[j]>arr[j-1]){
            temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
        }
       }
   }
   printf("%d,",arr);
return 0;
}