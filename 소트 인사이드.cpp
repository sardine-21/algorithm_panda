#include <stdio.h>

int main(){
    int count = 0, num;
    scanf("%d", &num);
    //���� count�� num�� �ʱ�ȭ �� ����.
    
    int temp = num; // ������ ���Ŀ��� ����ϱ� ���ؼ� temp�� ������.
    while(num > 0){
        num /= 10;
        count++;
    }
    // ������ �ڸ����� �����Ͽ� count�� ������.
    
    
    int array[count]; // �ڸ����� ���� ��ŭ�� �迭�� ������.
    int i = 0;
    while(temp > 0){
        array[i] = temp % 10;
        temp /= 10;
        i++;
    } // �̹����� �ڸ����� �� ���� �迭�� �� ĭ�� ������.
    // �׷���, Ŀ�ٶ� �ϳ��� ���� �������� ���� ���հ� �������� �Ǿ���.
    
    for(int i = 0; i < count; i++){
        for(int j = 1+i; j < count; j++){
            if(array[j] >= array[i]){
                temp = array[j];
                array[j] = array[i];
                array[i] = temp;
            }
        }
    }
    // �Ʊ��� �� �����ϴ� ���� ���� - ��������
    
    for(int i = 0; i < count; i++){
        printf("%d", array[i]);
    }
    // ���ĵ� ���� �ϳ��� �ٽñ� �迭
    return 0;
}
