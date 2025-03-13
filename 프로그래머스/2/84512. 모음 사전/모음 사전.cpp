#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int solution(string word) {
    int answer = 0;
    
    vector<char> Alphabets = {'A', 'E', 'I', 'O', 'U', ' '};
    set<string> order;
    
    for(char v : Alphabets)
    {
        for(char o : Alphabets)
        {
            for(char w : Alphabets)
            {
                for(char e : Alphabets)
                {
                    for(char l : Alphabets)
                    {
                        
                        
                            string temp = "";
                            temp = temp + v + o+ w + e + l;
                            temp.erase(remove(temp.begin(), temp.end(), ' '), temp.end());
                            order.insert(temp);
                        
                    }
                }
            }
        }
    }
    
    int index = 0;
    for(auto it = order.begin(); it != order.end(); ++it, ++index)
    {
        if(*it == word)
        {
            answer = index;
            break;
        }
    }
    
    return answer;
}