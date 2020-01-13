#include <string>
#include <vector>
#include<algorithm>
using namespace std;
//isdisit()함수가 있다.
bool solution(string s) {
	bool answer = true;
	if (s.length() == 4 || s.length() == 6)
	{
		for (int i = 0; i < s.length(); i++) {
			if ((int)s[i] < 48 || (int)s[i]>57) {
				return answer = false;
			}
		}
		return answer = true;
	}
	return answer = false;
}