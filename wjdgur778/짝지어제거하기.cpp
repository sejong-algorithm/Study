#include <iostream>
#include<stack>
#include<string>
using namespace std;

int solution(string s)
{
    int answer = 0;
    if (s.size() % 2 != 0) return 0;

    stack<char> comp;
    comp.push(s[0]);
    for (int i = 1; s.size(); i++) {
        if (comp.empty()) {
            comp.push(s[i]);
            continue;
        }
        if (comp.top() != s[i]) {
            comp.push(s[i]);
        }
        else {
            comp.pop();
        }
    }
    if (comp.empty()) return 1;
    else return 0;
}
int main() {


    solution("baabba");

    return 0;
}