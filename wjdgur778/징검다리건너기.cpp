//#include<iostream>
//#include<string>
//#include<vector>
//#include<stack>
//#include<algorithm>
//using namespace std;
//
//// 拙生檎 什澱 祢習
//
///*
//2,4,5,3,2,1,4,2,5,1
//
//
//
//    け          け  
//  けけ      け  け  
//  けけけ    け  け  
//けけけけけ  けけけ  
//けけけけけけけけけけ 
//
//*/
//
//int solution(vector<int> stones, int k) {
//    int answer = 200000;
//    stones.push_back(200000001);
//    stack <int> stak;
//    stak.push(0);
//    
//    for (int i = 1; i < stones.size(); i++) {
//        int cnt = 0;
//        if (stones[stak.top()] < stones[i]) {
//            int tmp = 0;
//            while (!stak.empty() && stones[stak.top()] < stones[i]) {
//                tmp = stak.top();
//                stak.pop();
//            }
//            int dist = 0;
//
//            if (stak.empty()) {
//                dist = i;
//            }
//            else {
//                dist = i - stak.top() - 1;
//            }
//                
//            if (k <= dist) {
//                answer = min(answer, stones[tmp]);
//            }
//        }
//
//        stak.push(i);
//    }
//    if (answer == 200000) return 0;
//    else return answer;
//}
//
//int main()
//{
//
//    cout << solution({ 5,4,3,2,1 },3);
//
//    return 0;
//}

#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

/*
            stones	             k	 result
[2, 4, 5, 3, 2, 1, 4, 2, 5, 1]	 3	   3
*/

int solution(vector<int> stones, int k) {

	int answer;
	int s = 1;
	int e = *max_element(stones.begin(), stones.end());


	while (s <= e) {
		int mid = (s + e) / 2;
		int sum = 0;
		int tmp = 0;
		int cnt = 0;
		bool f = false;
		for (int i = 0; i < stones.size(); i++) {

			sum = stones[i] - mid;
			
			if (sum <= 0) {
				cnt++;
			}


			else {
				tmp = max(tmp, cnt);
				cnt = 0;
			}
			if (i == stones.size() - 1 ) tmp = max(tmp, cnt);

		}

		if (k > tmp) {
			s = mid + 1;
		}
		else {
			e = mid - 1;
			answer = mid;

		//	if (s > e) answer = mid;
		}

	}

	return answer;

}


int main() {

	cout << solution({ 2, 4, 5, 3, 2, 1, 1, 2, 5, 1 },3);

	
	return 0;
}