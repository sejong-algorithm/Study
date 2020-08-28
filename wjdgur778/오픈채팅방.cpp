#include <string>
#include <vector>
#include<map>
#include<iostream>
using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map <string, string> check;
    string func;
    vector<string> id;
    string tmp ;
    string nick;
               
    for (int i = 0; i < record.size(); i++) {
        func.push_back(record[i][0]);
        nick = "";
        tmp = "";
        int j;
        if (record[i][0] != 'L') {
            for (j = 6;; j++) {
                if (j == 6 && record[i][j] == ' ') {
                    continue;
                }
                if (record[i][j] != ' ') {
                    tmp.push_back(record[i][j]);
                }
                else {

                    while (j+1 < record[i].size()) { nick.push_back(record[i][j+1]); 
                    j++;
                    }
                    id.push_back(tmp);
                    if (check.find(tmp) != check.end()) {
                        check[tmp] = nick;
                    }
                    else {
                        check.insert(make_pair(tmp, nick));
                    }
                    break;
                }
            }

        }
        else {
            for (j = 6; j < record[i].size(); j++) {
                tmp.push_back(record[i][j]);
            }
            id.push_back(tmp);
        }
    }
    for (int i = 0; i < func.size(); i++) {
        if (func[i] == 'E') {
            answer.push_back((check[id[i]] + "´ÔÀÌ µé¾î¿Ô½À´Ï´Ù."));
        }
        else if (func[i] == 'L') {
            answer.push_back((check[id[i]] + "´ÔÀÌ ³ª°¬½À´Ï´Ù."));
        }
        else {
            continue;
        }
    }

    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << endl;
    }
    return answer;
}



int main() {
    solution({ "Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan" });
    return 0;
}