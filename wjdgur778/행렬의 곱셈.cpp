#include <string>
#include <vector>
#include <sstream>
#include<iostream>
using namespace std;

string solution(string s) {
    string answer = "";
    stringstream a;
    string tmp;
    int index = 0;
    a.str(s);
    for (int i = 0; i < s.size(); i++) {
        s[i] = tolower(s[i]);
    }
    while (a >> tmp) {
        if (index < s.size()) {
            s[index] = toupper(s[index]);
        }
        index += tmp.size() + 1;
    }
    return s;
}
int main() {
    cout<<solution("33psdf sdoijsdf sodifjsdf");
    return 0;
}