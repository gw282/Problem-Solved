#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int time = 0;
    int idx = 0;
    int weight_on_bridge = 0;
    queue<int> bridge;

    while (idx < truck_weights.size()) {
        time++;

        if (bridge.size() == bridge_length) {
            weight_on_bridge -= bridge.front();
            bridge.pop();
        }

        if (weight_on_bridge + truck_weights[idx] <= weight) {
            bridge.push(truck_weights[idx]);
            weight_on_bridge += truck_weights[idx];
            idx++;
        } else {
            bridge.push(0);
        }
    }

    time += bridge_length;

    return time;
}