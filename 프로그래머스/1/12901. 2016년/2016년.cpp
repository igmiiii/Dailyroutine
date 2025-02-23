#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    
    int day = 0;
    vector<string> week = {"FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU"};
    
    vector <int> month = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    for(int i = 0; i < a-1; ++i)
    {
        day += month[i];
        
    }
    
    day+=(b -1);
    
    answer += week[day%7];
    
    
    
    return answer;
}