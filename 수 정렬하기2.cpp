#include <stdio.h>
 
int main(){
    int num = 0;
    // 0으로 초기화된 변수 num을 정의함.
    scanf("%d", &num);
    // 가장 상위의 숫자(앞으로 나올 수의 개수)를 num에 저장함.
    
 
    int array[num] = {0};
    // num 개의 index를 가지는 배열 array를 정의함. 값은 없다(=0이다).
    for(int i = 0; i < num; i++){
        scanf("%d", &array[i]);
    } // for문을 사용해서 값을 배열에 저장함. 순서는 나와있는 대로.
    int temp = 0;
    for(int i = 0; i < num; i++){
        for(int j = i; j < num; j++){
            if(array[i] > array[j]){ // 5 2 3 4 1
                temp = array[j];
                array[j] = array[i];
                array[i] = temp;
            } 
            /*
            어떤 종류의 정렬을 사용해서든 배열을 재정렬 할 수 있으나, 
            예전의 나는 버블 정렬을 사용해서 정렬을 구현하였음.
            num의 범위가 1 <= num && num <= 1000이므로, 
            가장 많이 loop하는 경우도 num ** 2로 , 최대 100만번에 해당함.
            보통 1초에 연산을 10억번 가량 하므로, 시간 내에 처리 가능하다.
            
            버블 정렬의 구조:
            1. 첫번째 인덱스의 수(i=1)부터 시작
            2. 옆에 있는 인덱스의 수(i+1)와 지금 인덱스의 수(i)를 비교함.
            3. 만약에 수가 크다면 두 수를 바꾼다. -> 현재 코드의 구조.
            4. 바꾼 후에는 현재 인덱스를 1 늘려서(i = i+1) 2,3의 과정을 반복한다.
            5. 내부 for문이 완료되면 i=2, i=3, ...의 순으로 반복을 계속함.
            */
        }
    }
    for(int i = 0; i < num; i++){ 
    	printf("%d\n", array[i]);
    	}
    return 0;
}
