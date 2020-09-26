//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//
//int solution(vector<int> money) {
//	vector<pair<int, int>>vec;
//	int size = money.size();
//	int answer = 0;
//	for (int i = 0; i < size; i++) {
//		vec.push_back({ money[i],money[i] });
//	}
//	if (size == 3) {
//		return answer = max(max(money[0], money[1]), money[2]);
//	}
//	else if (size == 4) {
//		return answer = max(money[0] + money[2], money[1] + money[3]);
//	}
//	else {
//		bool f = false;
//		//vec[2].second += vec[0].second;
//		for (int i = 3; i < money.size(); i++) {
//			int f_m = max(vec[i - 3].first, vec[i - 3].second);
//			int s_m = max(vec[i - 2].first, vec[i - 2].second);
//
//			if (i == 3) {
//				if (f_m > s_m) {
//					f = true;
//				}
//				else f = false;
//			}
//			vec[i].first += f_m;
//			vec[i].second += s_m;
//			if (f) {
//				if (i == money.size() - 2)break;
//			}
//		}
//		if (f) {
//			return answer = max(max(max(vec[size - 2].first, vec[size - 2].second), max(vec[size - 3].first, vec[size - 3].second)), max(vec[size - 4].first, vec[size - 4].second));
//		}
//		else {
//			return answer = max(max(max(vec[size - 1].first, vec[size - 1].second), max(vec[size - 2].first, vec[size - 2].second)), max(vec[size - 3].first, vec[size - 3].second));
//
//		}
//	}
//}
//
//int main() {
//
//	cout << solution({ 5,5,5,1,1,5,5,6,5,6 });
//
//	return 0;
//}

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int solution(vector<int> money) {
	vector<pair<int, int>>vec,o_vec;
	int size = money.size();
	int answer = 0;
	int ano_ans = 0;
	for (int i = 0; i < size; i++) {
		vec.push_back({ money[i],money[i] });
	}
	o_vec = vec;
	if (size == 3) {
		return answer = max(max(money[0], money[1]), money[2]);
	}
	else if (size == 4) {
		return answer = max(money[0] + money[2], money[1] + money[3]);
	}
	else {
		vec[2].second += vec[0].second;
		for (int i = 3; i < money.size()-1; i++) {
			int f_m = max(vec[i - 3].first, vec[i - 3].second);
			int s_m = max(vec[i - 2].first, vec[i - 2].second);
			vec[i].first += f_m;
			vec[i].second += s_m;
		}
		 answer = max(max(max(vec[size - 2].first, vec[size - 2].second), max(vec[size - 3].first, vec[size - 3].second)), max(vec[size - 4].first, vec[size - 4].second));

		 o_vec[3].second += o_vec[1].second;
		 for (int i = 4; i < money.size() ; i++) {
			 int f_m = max(o_vec[i - 3].first, o_vec[i - 3].second);
			 int s_m = max(o_vec[i - 2].first, o_vec[i - 2].second);
			 o_vec[i].first += f_m;
			 o_vec[i].second += s_m;
		 }
		 ano_ans = max(max(max(o_vec[size - 1].first, o_vec[size - 1].second), max(o_vec[size - 2].first, o_vec[size - 2].second)), max(o_vec[size - 3].first, o_vec[size - 3].second));
		 return max(answer, ano_ans);
	}
}

int main() {

	cout << solution({ 8,1,7,1,3,6,5,1,5});

	return 0;
}