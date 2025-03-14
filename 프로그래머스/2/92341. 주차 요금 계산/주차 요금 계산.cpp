#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    
    map<string, queue<int>> Cars;
    
    int DefaultTime = fees[0];
    int DefaultFee = fees[1];
    int UnitMinute = fees[2];
    int UnitFee = fees[3];
    
    for(string s : records)
    {
        int Time = 0;
        Time += stoi(s.substr(0, 2))*60;
        Time += stoi(s.substr(3, 2));
        Cars[s.substr(6, 4)].push(Time);
    }
    
    for(auto& pair : Cars)
    {
        int Sum = 0;
        while(!pair.second.empty())
        {
            int Temp = pair.second.front();
            pair.second.pop();
            if(!pair.second.empty())
            {
                Sum += pair.second.front() - Temp;
                pair.second.pop();
            }
            else
            {
                Sum += 1439 - Temp;
            }
        }
        if(Sum<= DefaultTime)
        {
            answer.push_back(DefaultFee);
        }
        else
        {
            if((Sum - DefaultTime)%UnitMinute== 0)
            {
                answer.push_back(DefaultFee + ((Sum - DefaultTime)/UnitMinute) * UnitFee);
            }
            else
            {
                answer.push_back(DefaultFee + ((Sum - DefaultTime)/UnitMinute+1) * UnitFee);
            }
        }
    }
    
    return answer;
}