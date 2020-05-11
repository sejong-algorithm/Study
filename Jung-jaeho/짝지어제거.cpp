#include <iostream>
#include<string>
#include <stack>

using namespace std;


//스택을 활용하여 같은 것이 있으면 팝을 하고 같은것이 없으면 계속 넣는 형식으로 구현한다.

int solution(string s)
{
    int answer = 0;

    stack<char> stk;

    stk.push(s[0]);

    for(int i = 1 ; i < s.length(); i++)
    {

        if(stk.empty())
        {
            stk.push(s[i]);
        }
        else if(stk.top()!=s[i])
        {
            stk.push(s[i]);
        }
        else{
            stk.pop();
        }
    }

    if(stk.empty())
        return 1;
    else
        return 0;
}
int main()
{
    string str = "baabaa";
    int result=0;

    result=solution(str);
    printf("%d",result);


    return 0;
}


//스택을 이용해서 같은거 들어오면 팝하기