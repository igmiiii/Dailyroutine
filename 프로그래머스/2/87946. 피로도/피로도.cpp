#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    
    vector<int> Numbers;
    
    for(int i = 0; i< dungeons.size(); ++i)
    {
        Numbers.push_back(i);
    }
    
    do
    {
        int Time = 0;
        int K = k;
        for(int i : Numbers)
        {
            if(K >= dungeons[i][0])
            {
                Time++;
                K = K-dungeons[i][1];
            }
            else
            {
                break;
            }
        }
        if(Time>answer)
        {
            answer = Time;
        }
    }
    while(next_permutation(Numbers.begin(), Numbers.end()));
    
    return answer;
}