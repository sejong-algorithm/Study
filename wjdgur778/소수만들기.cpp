#include <vector>
#include <iostream>
#include<algorithm>
#include<math.h>
using namespace std;
vector<int> arr;
vector<bool>Select;
int answer = 0;
int Size;
int prime(int n) {
    for (int i = 2; i <= sqrt(n); i++) {
        if (n / i == 0) return 1;
    }
    return 0;
}

void dfs(int idx, int cnt, int sum) {
    if (cnt == 3) {
        answer += prime(sum);
        return;
    }

    for (int i = idx; i < Size; i++) {
        if (Select[i] == true)continue;
        sum += arr[i];
        Select[i] = true;

        dfs(i, cnt + 1, sum);
        Select[i] = false;
    }

}

int solution(vector<int> nums) {
    //sort(nums.begin(),nums.end());
    //dfs를 이용한 완전탐색을 해야 하는것?

    arr = nums;
    Size = nums.size();
    for (int i = 0; i < arr.size(); i++) {
        Select.push_back(false);
    }
    dfs(0, 0, 0);

    return answer;
}
int main() {
    
    solution({ 1,2,3,4 });
    return 0;
}