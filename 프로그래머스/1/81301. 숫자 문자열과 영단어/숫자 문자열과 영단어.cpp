#include <string>
#include <vector>
#include <unordered_map>
#include <cctype>

using namespace std;

int solution(string s) {
    int answer = 0;
    string temp = "";
    string result = "";
    
    
    unordered_map <string, string> wordToDigit =
    {
        {"zero", "0"}, {"one", "1"}, {"two", "2"}, {"three", "3"}, {"four", "4"}, {"five", "5"}, {"six", "6"}, {"seven", "7"}, {"eight", "8"}, {"nine", "9"}
    };
    
    for(char c: s)
    {
        if(isdigit(c))
        {
            result += c;
        }
        else
        {
            temp += c;
            if(wordToDigit.find(temp)!=wordToDigit.end())
            {
                result += wordToDigit[temp];
                temp = "";
            }
                
            
        }
    }
    
    answer = stoi(result);
    
    
    
    return answer;
}