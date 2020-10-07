#include <stdio.h>
#include <algorithm>
#include <iostream>

using namespace std;

int Dp[1000001];

int main(void){

    int N;
    scanf("%d", &N);

    Dp[1] = 0;

    for (int i = 2; i <= N; i++)
    {
        Dp[i] = Dp[i - 1] + 1;
        if (i % 2 == 0)
            Dp[i] = min(Dp[i], Dp[i / 2] + 1);
        if (i % 3 == 0)
            Dp[i] = min(Dp[i], Dp[i / 3] + 1);
    }

    printf("%d\n", Dp[N]);
    return 0;
}

