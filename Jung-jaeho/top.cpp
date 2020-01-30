#include <stack>
#include <queue>

using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> answer;
    int flag=0;

    for(int i = 0 ; i < heights.size(); i++)
    {

        for(int j=i-1 ; j>= 0 ; j--)
        {
            if(heights[i]<heights[j])
            {
                answer.push_back(1+j);
                flag=1;
                break;
            }
        }
        if(flag == 0){
            answer.push_back(0);
        }
        else{
            flag=0;
        }
    }
    return answer;
}