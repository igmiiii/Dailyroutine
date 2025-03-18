#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    int Day = 0;
    
    queue<int> Progresses;
    queue<int> Speeds;
    
    for(int i : progresses)
    {
        Progresses.push(i);
    }
    
    for(int i : speeds)
    {
        Speeds.push(i);
    }
    
    while(!Progresses.empty())
    {
        int Temp = 0;
        Day++;
        int Progress = Progresses.front() + Speeds.front() * Day;
        while(Progress>=100)
        {
            Temp++;
            Progresses.pop();
            Speeds.pop();
            if(!Progresses.empty())
            {
                Progress = Progresses.front() + Speeds.front() * Day;
            }
            else
            {
                Progress= 99;
            }
        }
        if(Temp>0)
        {
            answer.push_back(Temp);
        }
    }
    
    return answer;
}