#include <iostream>

using namespace std;

int solution(int n)
{
    int answer = 0;

    while(1)
    {
        answer+=n%10;
        n=n/10;
        if(n==0)
            break;
    }
    return answer;
}
int main()
{
    solution(123);

    return 0;
}