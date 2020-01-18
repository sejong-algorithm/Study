#include <string>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    int cnt = 0;
    int delay = 0;
    int flag = 0;
    //작업진도 100 , 작업속도 100

    while(1){
        cnt=0;
        delay++;
        if(flag == progresses.size())
            break;

        for (int i = flag; i < progresses.size(); i++){
            if ((progresses[flag] + (speeds[flag] * delay)) >= 100){
                flag++;
                cnt++;
            }
        }
        if (cnt != 0)
            answer.push_back(cnt);
    }
    return answer;
}
int main(){
    vector<int> progresses={93,30,55};
    vector<int> speeds = {1,30,5};
    vector<int> answer;

    answer=solution(progresses,speeds);


}