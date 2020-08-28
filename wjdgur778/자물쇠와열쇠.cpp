#include<iostream>
#include <string>
#include <vector>

using namespace std;



bool solution(vector<vector<int>> key, vector<vector<int>> l) {
    int m = key.size();
    int n = l.size();
    int k_cnt = 0;
    int l_cnt = 0;
    bool answer = false;
    vector<vector<int>> lock((2 * m) + n - 2, vector<int>((2 * m) + n - 2, 0));


    //키를 아무리 넣어도 안열리는 경우
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            if (key[i][j] == 1)k_cnt++;

        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (l[i][j] == 0)l_cnt++;
        }
    }
    if (l_cnt > k_cnt) return answer;


    //init "lock"
    for (int i = m - 1; i < m - 1 + n; i++) {
        for (int j = m - 1; j < m + n - 1; j++) {
            lock[i][j] = l[i - m + 1][j - m + 1];
        }
    }
    for (int i = 0; i < (2 * m) + n - 2; i++) {
        for (int j = 0; j < (2 * m) + n - 2; j++) {
            cout<<lock[i][j]<<" ";
        }
        cout << endl;
    }

    bool f = true;
    int cnt = 0;
    for (int q = 0; q < 4; q++) {

        //logic
        for (int i = 0; i < m + n - 1 ; i++) {
            for (int j = 0; j < m + n - 1; j++) {
                f = true;
                cnt = 0;
                for (int k = 0; k < m; k++) {
                    for (int l = 0; l < m; l++) {

                        if (k + i >= m - 1 && k + i < m + n - 1 && l + j >= m - 1 && l + j < m + n - 1) {

                            if (key[k][l] == 1 && lock[k + i][l + j] == 0) {
                                cnt++;
                            }
                            if (key[k][l] == 1 && lock[k + i][l + j] == 1) {
                                f = false;
                                break;
                            }
                        }
                    }
                }
                if (cnt == l_cnt) return true;
                if (f == false) break;
            }

        }

        if (q == 3)break;
        //spin
        vector<vector<int>> t_key(m, vector<int>(m, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                t_key[i][j] = key[m - j - 1][i];
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                cout << t_key[i][j] << " ";

            }
            cout << endl;
        }
        key = t_key;
    }




    return answer;
}

int main() {

   cout<< solution({ 
        { 0,0,0 },
        { 1,1,0 },
        { 0,0,0 } 
        },
        { 
        {1,1,1},
        {1,0,1},
        {1,1,1} });
    return  0;
}