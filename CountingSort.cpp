#include <stdio.h>
int main(void){
  int count[5] = {0,0,0,0,0};
  int data[20] = { 1,4,2,5,3, 2,3,4,5,2, 2,2,3,4,1, 4,2,5,5,1 };
   for(int i=0; i<20; i++){
     count[data[i]-1]++;
   } // 결과 출력
   for(int i=0; i<5; i++){
     if(count[i] != 0){ // 0일때는 출력 안해도 되니깐
     for(int j=0; j<count[i]; j++) { 
       printf("%d ", i+1);
     }
   }
 }
 return 0;
}​
