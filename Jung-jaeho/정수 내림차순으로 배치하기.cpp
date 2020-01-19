#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(long long n) {
    long long answer = 0;
    vector<int> arr;
    int temp = 1;
    while(n>0){
    arr.push_back(n%10);
    n=n/10;
    }
    sort(arr.begin(),arr.end());

    for(int i = 0; i < arr.size(); i++)
    {
        answer += arr[i] * temp;
        temp *=10;
    }
    return answer;
}