#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = n;
    int plus = 1, minus = 1;
    while (n > 0) {
        if (n % 2 == 1) {
            if ((n / 2) % 2 == 1) {
                answer -= minus;
                answer += plus;
                plus *= 2;
            }
            else {
                answer -= minus;
                answer += (minus * 2);
                return answer;
            }
        }
        n /= 2;
        minus *= 2;
    }


    return answer;
}
int main() {

    solution(78);

    return 0;
}