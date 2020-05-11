#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";
    int flag=0;

    if ('a' <= s[0] && 'z' >= s[0]) {
        s[0] = s[0] - 'a' + 'A';
    }

    for(int i = 1 ; i < s.length(); i++)
    {
        if(s[i]==' ' && ((s[i+1]>='a')&&(s[i+1]<='z'))) // 앞 공백 뒤 소문자
        {
            s[i+1]=s[i+1]+'A'-'a';
            i++;
        }
        else if(s[i]==' ' && ((s[i+1]>='A')&&(s[i+1]<='Z')))// 앞 공백 뒤 대문자
        {
            i++;
        }
        else if(s[i]>='A' && s[i]<='Z') //그냥 중간에 대문자가 나온 경우
        {
            s[i]=s[i]-'A'+'a';
        }
    }

    answer=s;
    cout << s << endl;
    return answer;
}

int main()
{
    string result;

    result=solution("h      z   Zero zZreo");

    return 0;
}

//맨앞이 소문자면 대문자로 바꾼다.
// 띄어쓰기 생각해서 소문자면 대문자로 바꿔준다.