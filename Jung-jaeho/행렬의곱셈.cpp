#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    int sum=0;

    // 행 끼리 다 곱하고 열끼리 곱해서 더해서 저장한다 결과값에다가
    //arr1는 -> 무조건 일로간다.
    //arr2 는 ㅣ 아래로 간다.
    for(int i = 0 ; i < arr1.size();i++)   //  첫번쨰 행렬의 2를 담당한다.
    {
        vector<int> temp;
        for(int j = 0 ; j < arr2[0].size();j++) // 두번째 행렬 바깥에 2를 담당한다 그럼 2*2 완성
        {
            sum=0;
            for(int z = 0 ; z < arr1[0].size();z++) //내부 3*3을 담당한다.
            {
                sum+=(arr1[i][z]*arr2[z][j]);  
            }  // 
            temp.push_back(sum);
        }
        answer.push_back(temp);
    }
    return answer;
}


int main()
{
    vector<vector<int>> arr1={{1,2,3},{4,5,6}};
    vector<vector<int>> arr2={{1,4},{2,5},{3,6}};
    vector<vector<int>> answer;
    answer = solution(arr1,arr2);

    return 0;
}


// 1 2 3    1 4  14 32
// 4 5 6    2 5  32 77
//          3 6

// 2 3 2   5 4 3
// 4 2 4   2 4 1
// 3 1 4   3 1 1
//
// 22 22 11
//

// 1 4  3 3
// 3 2  3 3
// 4 1

// 15 15
// 15 15
// 15 15
//arr1 : [[1, 2, 3], [4, 5, 6]]
//
//arr2 : [[1, 4], [2, 5], [3, 6]]
//
//return : [[14, 32], [32, 77]]

//if((temp.size() == arr1.size() )&& temp.size() == arr2[0].size())