#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool solution(vector<string> phone_book) {
	bool answer = true;

	for (int i = 0; i < phone_book.size(); i++)
	{
		for (int j = 0; j < phone_book.size(); j++)
		{
			if (phone_book[i].size() <= phone_book[j].size() && i != j)
			{
				// phone_book[j]의 0번째 인덱스부터 phone_book[i].size()길이 만큼  phone_book[i]와 같은지 비교한다.
				if (phone_book[j].compare(0, phone_book[i].size(), phone_book[i]) == 0)
				{	// if ( phone_book[j].substr(0,phone_book[i].size()) == phone_book[i] ) 랑 같구나...
					// 하지만 substr 은 실행시간이 길어서 가급적 안쓴다.(파싱할 때도 안쓴다고 한다.)
					answer = false;	// 같은게 있으면 더 이상 for문 돌지 않고 false를 반환한다.
					return answer;
				}
			}
		}
	}

	return answer;
}
int main()
{
	vector<string> phone_book
		= {"119",
			"97674223",
			"1195524421"};

	//cout << solution(phone_book) << endl;

	// 참고로 compare의 정의는
	// b1.comapre(n번째 인덱스부터, a1의 크기, a1)
	// 이 '0' 이면 같다
	/*
	string a1 = "123";
	string b1 = "123456";

	if (b1.substr(0, 3) == "123")
	{
		cout << "1 같다" << endl;
	}
	cout << "a1.size() : " << a1.size() << endl;
	if (b1.compare(0, a1.size(), a1) == 0)
	{
		cout << "2 같다" << endl;
	}*/

	return 0;
}