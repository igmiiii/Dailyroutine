#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
    int count1 = 0;
    int count2 = 0;
    
    for(int i = 0; i< goal.size(); ++i)
    {
        if(goal[i]==cards1[count1] || goal[i]==cards2[count2] )
        {
            if(goal[i]==cards1[count1])
            {
                count1 ++;
            }
            else if(goal[i]==cards2[count2])
            {
                count2 ++;
            }
        }
        else
        {
            return "No";
        }
    }
    
    
    
    
    return "Yes";
}