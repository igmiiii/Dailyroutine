#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string phone_number) {
    string answer = "";
    
    vector <char> Star;
    
    for (int i= 0; i<phone_number.size(); i++)
    {
        Star.push_back(phone_number[i]);
    }
    
    for(int i= 0; i<phone_number.size()-4 ;i++ )
    {
        Star[i]='*';
    }
    
    for(char j : Star)
    {
        answer += j;
    }
    
    
    return answer;
}