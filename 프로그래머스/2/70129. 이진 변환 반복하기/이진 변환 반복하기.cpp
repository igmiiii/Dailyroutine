#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    
    int count = 0;
    int zerocount = 0;
    
    while(s !="1" )
    {
        count++; 
        string temp ="";
    
        for(char c : s)
        {
            if( c == '0')
            {
                zerocount++;
            }
            else
            {
                temp+="1";
            }
        }
        int num = temp.size();
        string next = "";
        while(num>0)
        {
            
            next = to_string(num%2)+next;
            num = num/2;
        }
        s= next;
    }
    
    answer.push_back(count);
    answer.push_back(zerocount);
    
    return answer;
}