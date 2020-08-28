//,Â¡°Ë´Ù¸®
#include<iostream>
#include<vector>
#include<math.h>

using namespace std;



//x*x + x <= 2 *y :Â¦¼ö
//x*x + 2 *x <=2*y -2 : È¦¼ö

int main() {

	int t;
	long long n;
	long long ans = 0;
	cin >> t;
	for (int i = 0; i < t; i++) {

		cin >> n;
		ans = (-1 + sqrt(1 + 8 * n)) / 2;
		cout << (ans);
		cout << endl;

	}


	return 0;
}