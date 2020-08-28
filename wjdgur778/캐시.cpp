    #include <string>
    #include <vector>
    #include<deque>
    #include<iostream>
    #include<list>
    using namespace std;

    int solution(int cache, vector<string> cities) {
        int answer = 0;
        list <string> deq;


        for (int i = 0; i < cities.size(); i++) {
            for (int j = 0; j < cities[i].size(); j++) {
                if (cities[i][j] < 97) {
                    cities[i][j] += 32;
                }
            }
        }//소문자로 변환

        for (int i = 0; i < cities.size(); i++) {
            if (cache == 0)return cities.size() * 5;
            else {
                if (deq.empty()) {
                    deq.push_back(cities[i]);
                    answer += 5;
                }
                else {
                    if (deq.size() == cache) {
                        bool f = false;
                        for (auto j = deq.begin(); j != deq.end(); j++) {
                            if (!j->compare(cities[i])) {
                                //hit
                                deq.erase(j);
                                deq.push_back(cities[i]);
                                f = true;
                                break;
                            }
                        }
                        if (f) {
                            answer++;
                        }
                        else {
                            deq.pop_front();
                            deq.push_back(cities[i]);
                            answer += 5;
                        }
                    }
                    else {
                        bool f = false;
                        for (auto j = deq.begin(); j != deq.end(); j++) {
                            if (!j->compare(cities[i])) {
                                //hit
                                deq.erase(j);
                                deq.push_back(cities[i]);
                                f = true;
                                break;
                            }
                        }
                        if (f) {
                            answer++;
                        }
                        else {
                            deq.push_back(cities[i]);
                            answer += 5;
                        }
                    }

                }
            }
        }
        return answer;
    }
    int main() {
      cout<<  solution(12, { "a", "b", "c", "b", "a", "c","b"});

        return 0;
    }