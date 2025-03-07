#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    
    sort(citations.begin(), citations.end(), [](int a, int b){return a>b;});
    
    int max = citations[0];
    
    for(int j = max ; j >= 0 ; --j )
    {
        int count = 0;
        int under = 0;
        for(int i : citations)
        {
            if(j<=i)
            {
                count++;
            }
            else
            {
                under++;
            }
        }
        if(j <= count && under <= j)
        {
            answer = j;
            break;
        }
    }
    
    return answer;
}