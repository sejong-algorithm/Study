#include <string>
#include<algorithm>
#include<set>
#include <iostream>

using namespace std;

multiset <string> s,s_1;
int gyo = 0;

int solution(string str1, string str2) {
    int answer = 0;
    string t = "*";
    //대문자면 32 더해
        //97~
        //65~
    string tmp = "";

    int size_a = str1.size();
    int size_b = str2.size();
    for (int i = 0; i < size_a-1 ; i++) {
        if (((65 <= str1[i] && 91 > str1[i]) || (97 <= str1[i] && 123 > str1[i])) && ((65 <= str1[i + 1] && 91 > str1[i + 1]) || (97 <= str1[i + 1] && 122 > str1[i + 1]))) {
            if (str1[i] < 97) {
                tmp += str1[i] + 32;
            }//대문자면 소문자
            else tmp += str1[i];


            if (str1[i + 1] < 97) {
                tmp += str1[i + 1] + 32;
            }//대문자면 소문자
            else tmp += str1[i + 1];

            s.insert(tmp);
            tmp = "";
        }
    }

    for (int i = 0; i < size_b-1; i++) {
        if (((65 <= str2[i] && 91 > str2[i]) || (97 <= str2[i] && 123 > str2[i])) && ((65 <= str2[i + 1] && 91 > str2[i + 1]) || (97 <= str2[i + 1] && 122 > str2[i + 1]))) {
            if (str2[i] < 97) {
                tmp += str2[i] + 32;
            }//대문자면 소문자
            else tmp += str2[i];


            if (str2[i + 1] < 97) {
                tmp += str2[i + 1] + 32;
            }//대문자면 소문자
            else tmp += str2[i + 1];

                s_1.insert(tmp);
            
            tmp = "";
        }
    }


    
    if (s.size() >= s_1.size()) {
        for (auto iter = s_1.begin(); iter!= s_1.end(); iter++) {
            if (s.find(*iter) != s.end()) {
                gyo++;
                s.erase(s.find(*iter));
                s.insert(" ");
            }
        }

    }
    else {
        for (auto iter = s.begin(); iter != s.end(); iter++) {
            if (s_1.find(*iter) != s_1.end()) {
                gyo++;
                s_1.erase(s_1.find(*iter));
                s_1.insert(" ");
            }
        }
    }
    if (s.size() == 0 && s_1.size() == 0)return 1 * 65536;
    else if ((s.size() != 0 && s_1.size() == 0) || s.size() == 0 && s_1.size() != 0) return 0;

    answer = ((double)gyo / ((s.size()+s_1.size())-gyo)) * 65536;
    return answer;
}

int main() {
    string a="Zzzz";
    string b="1ZZZ";


    cout<<solution(a,b);


    return 0;
}