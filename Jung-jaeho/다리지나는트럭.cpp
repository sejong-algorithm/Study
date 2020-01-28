#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int truck_num = 0;
    int truck = 0;
    queue<int> bridge;

    for(int i = 0 ; i < truck_weights.size() ; i++){
        truck = truck_weights[i];

        while(1){
            if(bridge.empty()){
                bridge.push(truck);
                truck_num += truck;
                answer++;
                break;
            }
            else if(bridge.size() == bridge_length){
                truck_num -= bridge.front();
                bridge.pop();
            }
            else{
                if(truck_num + truck <= weight){
                    truck_num += truck;
                    bridge.push(truck);
                    answer++;
                    break;
                }
                else{
                    bridge.push(0);
                    answer++;
                }
            }
        }
    }
    return answer + bridge_length;
}