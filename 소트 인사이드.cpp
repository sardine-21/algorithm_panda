#include <stdio.h>

int main(){
    int count = 0, num;
    scanf("%d", &num);
    //변수 count와 num의 초기화 및 저장.
    
    int temp = num; // 변수를 이후에도 사용하기 위해서 temp에 저장함.
    while(num > 0){
        num /= 10;
        count++;
    }
    // 변수의 자리수를 측정하여 count에 저장함.
    
    
    int array[count]; // 자릿수의 길이 만큼의 배열이 생성됨.
    int i = 0;
    while(temp > 0){
        array[i] = temp % 10;
        temp /= 10;
        i++;
    } // 이번에는 자리수의 각 값을 배열의 각 칸에 저장함.
    // 그래서, 커다란 하나의 수가 여러개의 수의 집합과 같아지게 되었음.
    
    for(int i = 0; i < count; i++){
        for(int j = 1+i; j < count; j++){
            if(array[j] >= array[i]){
                temp = array[j];
                array[j] = array[i];
                array[i] = temp;
            }
        }
    }
    // 아까의 수 정렬하는 경우와 같다 - 버블정렬
    
    for(int i = 0; i < count; i++){
        printf("%d", array[i]);
    }
    // 정렬된 수를 하나씩 다시금 배열
    return 0;
}
