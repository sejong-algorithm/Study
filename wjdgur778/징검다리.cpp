#include <string>
#include <vector>
#include<iostream>
#include<algorithm>
using namespace std;
// 최소를 찾아가는 방향으로
/*
------------------------------------------------
distance	        rocks          	n	return
   25     	[2, 14, 11, 21, 17]  	2	   4
------------------------------------------------
*/
int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    sort(rocks.begin(), rocks.end());
    rocks.push_back(distance);
    int s = 0;
    int e = distance;

    //mid 는 최소 distance
    //rocks 

    while (s <= e) {
            
        int prev = 0;
        int candi = 999999999;
        int removed_rocks = 0;
        int mid = (s + e) / 2;
        for (int i = 0; i < rocks.size(); i++) {
            if (mid > rocks[i] - prev) {
                removed_rocks += 1;
                //cout <<"value : "<< rocks[i] - prev << endl;
            }
            else {
                //가능한 모든곳의 최솟값?
                    
                candi = min(candi, rocks[i] - prev);
                prev = rocks[i];
              //  cout << "prev : " << prev << " " << "mid : " << mid << endl;

            }
        }

        if (removed_rocks <= n) {
            s = mid + 1;
            answer = candi;
        }
        else {
            e = mid - 1;
        }
        cout << endl;
    }
    
    return answer;
}

int main()
{
    cout << solution(58, {3,6,16,26,29,32,42,52,55 }, 3);
    return 0;
}