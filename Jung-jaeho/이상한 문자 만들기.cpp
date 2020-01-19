#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int flag = 1;
    for(int i = 0; i < s.length(); i++) {

        if(s[i] == ' ') {
            answer += " ";
            flag = 1;
        }
        else {
            if(flag==1) {
                flag = 0;
                if(s[i] >= 'A' && s[i] <= 'Z') answer += s[i];
                else {
                    answer += s[i] - 32;
                }
            }
            else {
                flag = 1;
                if(s[i] >= 'a' && s[i] <= 'z') answer += s[i];
                else {
                    answer += s[i] + 32;
                }
            }
        }
    }
    return answer;
}