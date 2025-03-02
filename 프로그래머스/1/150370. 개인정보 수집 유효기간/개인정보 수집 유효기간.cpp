#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    
    unordered_map <char, int> term;
    
    for(string s: terms)
    {
        term[s[0]] = stoi(s.substr(2));
        
    }
    
    vector<int> vectoday;
    
    vectoday.push_back(stoi(today.substr(0, 4)));
    vectoday.push_back(stoi(today.substr(5, 2)));
    vectoday.push_back(stoi(today.substr(8, 2)));
    
    for(int i = 0 ; i<privacies.size(); ++i)
    {
        string privacy = privacies[i];
        vector <int> temp;
        temp.push_back(stoi(privacy.substr(0, 4)));
        temp.push_back(stoi(privacy.substr(5, 2)));
        temp.push_back(stoi(privacy.substr(8, 2)));
        
        int month = term[privacy[11]];
        
        temp[1] += month;  // 월을 더한 후
        if (temp[1] > 12) {
            temp[0] += temp[1] / 12;  // 연도에 추가된 월을 더해줌
            temp[1] = temp[1] % 12;   // 12개월을 넘는다면 나머지 처리
            if (temp[1] == 0) {  // 12월을 넘어가면 1월로 처리
                temp[1] = 12;
                temp[0]--;
            }
        }
        
        
        
        
            
        if(vectoday[0]>temp[0])
        {
            answer.push_back(i+1);
        }
        else if(vectoday[0]==temp[0] && vectoday[1]>temp[1])
        {
            answer.push_back(i+1);
        }
        else if(vectoday [0] == temp[0] && vectoday[1] == temp[1]&& vectoday[2]>=temp[2])
        {
            answer.push_back(i+1);
        }
        
        
        
    }
    
    
    return answer;
}