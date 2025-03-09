#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    
    int sum = 0;
    int seconds = 0;
    queue<int> Trucks;
    
    for(int i = 0; i<truck_weights.size(); ++i)
    {
        if(Trucks.size() == bridge_length)
        {
            sum-=Trucks.front();
            Trucks.pop();
        }
        seconds++;
        if(sum+truck_weights[i]<=weight)
        {
            sum+=truck_weights[i];
            Trucks.push(truck_weights[i]);
        }
        else
        {
            sum+=0;
            Trucks.push(0);
            --i;
        }
    }
    
    answer= seconds+bridge_length;
    return answer;
}