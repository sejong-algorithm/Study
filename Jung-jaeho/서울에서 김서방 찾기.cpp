#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>

using namespace std;



string solution(vector<string> seoul) {
    string answer = "김서방은 ";
    string index =""; 

    for(int i = seoul.size()-1; i >= 0 ; i--){
        if(seoul.back() == "Kim")
        {
            index =to_string(i);
            break;
        }
        seoul.pop_back();
    };

    return "김서방은 "+index+"에 있다";
}