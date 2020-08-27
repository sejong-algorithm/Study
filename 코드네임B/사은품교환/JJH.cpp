#include <iostream>

using namespace std;

int main() {

    int N ,K;
    int result=0;
    int min=100000;
    int min_idx=0;
    int input[100000]={0};

    scanf("%d %d",&N,&K);

    for(int i = 0 ; i< N ; i++)
    {
        scanf("%d", &input[i]);
        if(min>input[i])
        {
            min=input[i];
            min_idx=i;
        }
    }

    min=100000;

    for(int i = min_idx-(K-1); i <= min_idx+(K-1);i++)
    {
        result=(i/(K-1));
        result=result+((N-(i+K))/(K-1));
        //본체 하나 뺴기
        result++;

        if((i%(K-1))>0)
            result++;
        if((N-(i+K))%(K-1)!=0)
            result++;

        if(min>result)
            min=result;
    }
    cout<<min<<endl;
    return 0;
}


//로직설명
//1. 가장 작은 값 위치부터 앞으로 K-1 뒤로 K-1 민큼 포문을 돌려서
//2. k 맨앞주소 부터 나누기 하고
//3. K 맨뒤부터 나누기 해주고
//4. 나머지들 양쪽 더해주고
//5. 본체 더해주고
//6. 더 작은 값이 나오면 그것으로 바꾸어준다.

