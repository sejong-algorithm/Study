//8월 14일 3:17 -> 15일 4시 26분 종료
// 약 5시간정도 걸림..
/*

그리디의 생각으로 자기 자리에서 가장 가까운 것을 찾는다.
 1. 체크가 필요한가?? -> 체크는 필요없다 왜냐하면 그것을 A로 바꿔준다음에 카운트 값만 저장한다.
 2. 그렇다면 처음건 그냥 계산하고 그다음 부터 생각하주면 된다.
 3. 그러면 앞으로 가는 것이랑 역방향으로 가는 것만 계산하면 된다.

<메모>
풀기는 풀었지만 i값 매겨주는 부분에서 애먹었고 길이가 초과했을떄 초기화 해주는 부분
 앞으로 갔다가 다시 역방향으로 가는 부분에서 굉장히 힘들었다.

 */
#include <string>
#include <vector>

using namespace std;

int solution(string name) {
    int answer = 0;
    int left_cnt=1;
    int right_cnt=1;
    int index_left=0;
    int index_right=name.length();
    string str ="A";

    for(int i = 0; i < name.length()-1; i++)
        str+="A";

    if('A'<=name[0]&&name[0]<='M')
        answer=name[0]-'A';
    else
        answer='Z'-name[0]+1;
    name[0]='A';

    while(1) {
        if (str == name)
            break;
        for (int i = index_left+left_cnt; left_cnt!=name.length(); i++) {

            if(i>name.length()-1) {
                i = 0;
            } else {
                if (name[i] == 'A')
                    left_cnt++;
                else
                    break;
            }
        }
        for(int i = index_right-right_cnt;right_cnt!=name.length();i--)
        {
            if(i<0 )
            {
                i=name.length();
            }
            else {
                if (name[i] == 'A')
                    right_cnt++;
                else
                    break;
            }
        }
        if(left_cnt<=right_cnt) {

            //길이를 초과해줬을 경우를 생각한다.
            if(index_left + left_cnt > name.length()-1) {
                index_left = left_cnt-1;
            }
            else
            {
                index_left = index_left + left_cnt;
            }
            if ('A' <= name[index_left] && name[index_left] <= 'M')
                answer += name[index_left]-'A'+ left_cnt;
            else
                answer +='Z'-name[index_left] + left_cnt+1;

            index_right=index_left;
        }
        else
        {
            //음수값이 나왔을 경우를 생각해줘야한다.
            //
            if(index_right - right_cnt < 0)
                index_right= name.length() + (index_right - right_cnt);
            else
                index_right=index_right - right_cnt;

            if ('A' <= name[index_right] && name[index_right] <= 'N')
                answer += name[index_right]-'A'+right_cnt;
            else
                answer +='Z'-name[index_right]+right_cnt+1;

            index_left=index_right;

        }
        name[index_left]='A';
        left_cnt=1;
        right_cnt=1;
    }
    //오른쪽으로 가는게 더 가까운지
    //역행하는게 더 가까운지 생각해보자



    return answer;
}

int main()
{
    int result;
    result=solution("ZZZ");
    printf("%d",result);

    return 0;
}

