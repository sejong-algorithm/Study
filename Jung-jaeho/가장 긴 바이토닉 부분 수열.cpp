#include <iostream>
#include <algorithm>

using namespace std;


int main() {
    int arr[1001];
    int dp1[1001];
    int dp2[1001];
    int ans, N,temp;
    int result=0;

    cin >> N;

    for(int i = 1; i <= N; i++) {
        cin >> arr[i];
        temp=0;
        for(int j = i-1; j > 0; j--) {
            if(arr[i] > arr[j])
                temp=max(dp1[j],temp);
        }
        dp1[i] = temp + 1;
    }

    for(int i = N; i >= 1; i--) {
        temp=0;
        for(int j = i+1; j <= N; j++) {
            if(arr[i] > arr[j])
                temp=max(dp2[j],temp);
        }
        dp2[i] = temp + 1;
    }

    for(int i = 0 ; i <= N;i++)
    {
        if(result<dp1[i]+dp2[i])
            result=dp1[i]+dp2[i];
    }
    result--;
    cout << result;
    return 0;
}


//S1 < S2 < ... Sk-1 < Sk > Sk+1 > ... SN-1 > SN

//