#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = s;
    for(int i = 0; i<s.length();i++){
        if('A'<= s[i] && 'Z'>= s[i]) //대문자이면
        {
            if(s[i]+n>'Z')
                answer[i]= s[i]+n-26;
            else{
                answer[i]=s[i]+n;
            }
        }
        else if(' '==s[i])//
             {
                answer[i]=' ';
        }
        else{
            if(s[i]+n>'z') {
                answer[i] = s[i]+n-26;
            }
            else{
                answer[i]=s[i]+n;
            }
        }
    }
    return answer;
}