#include <string>
#include <vector>
#include <deque>

using namespace std;

int solution(string arrangement) {
    int answer = 0;
    int panel=0; //
    int stick=0;
    char prev = arrangement[0];
    char now;

    for(int i = 1 ; i <arrangement.length();i++){
        now=arrangement[i];
        if(prev == '(' && now == '(')
        {
            answer++;
            stick++;
        }
        else if(prev == '(' && now == ')')
        {
            answer+=+stick;
        }
        else if(prev == ')' && now == ')')
        {
            stick--;
        }
        else {
        }
        prev=now;
    }
    return answer;
}