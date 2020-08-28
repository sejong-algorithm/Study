#include <string>
#include<iostream>
#include <vector>
#include<algorithm>
using namespace std;


int solution(vector<int> people, int limit) {
    int answer = 0;
    int sum = 0;
    int bout = 0;
    int i = 0;
    sort(people.begin(), people.end());

    while (i < people.size()) {

        if (sum + people[i] <= limit && bout <= 1) {
            sum += people[i];
            bout++;
            i++;
        }
        else {
            bout = 0;
            sum = 0;
            answer++;
        }
    }
    if (sum > 0) {
        answer++;
    }

    return answer;

}
int main() {
    vector<int> a(9, 0);
    for (int i = 0; i < 9; i++) {
        cin >> a[i];
    }

    cout << solution(a,10);
    return 0;
}