#include <iostream>

using namespace std;

int main() {


    int N;
    long long limit;
    long long normal;
    long long cnt=0;
    long long A ;
    long long B ;
    scanf("%d",&N);
    getchar();
    for(int i = 0 ; i < N ; i++)
    {
        scanf("%lld %lld", &limit, &normal);

        if(((limit)/5)>=((normal)/7))
        {
            cnt= (limit+normal)/12;
        } else
        {
            cnt=limit/5;
        }

        while((normal+limit)/12 < cnt) {
            if (cnt == 0)
                break;
            cnt--;

        }
        printf("%lld\n",cnt);
        cnt=0;
    }
    return 0;
}



//로직설명