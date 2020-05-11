#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


int gcd(int a, int b);
int solution(int arr[], size_t arr_len) {
    int hello[15];
    int answer = 0;

    for(int i = 0 ; i < arr_len;i++)
    {
        hello[i]=arr[i];
    }

    for(int i = 0 ; i < arr_len;i++) {
        hello[i + 1] = (hello[i] * hello[i + 1]) / gcd(hello[i], hello[i + 1]);
    }
    answer=hello[arr_len-1];

    return answer;
}
int gcd(int a, int b)
{
    int c;
    while (b != 0)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int main()
{
    int result=0;
    int arr[4]={2,6,8,14};

    result=solution(arr,4);
    printf("%d",result);

    return 0;
}