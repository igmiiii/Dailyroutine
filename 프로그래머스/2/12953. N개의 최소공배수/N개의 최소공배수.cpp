#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> arr) {
    int answer = 0;
    
    int max = *max_element(arr.begin(), arr.end());
    int n = 1;
    int multiple = 1;
    
    while(multiple != answer)
    {
        multiple = max* n;
        n++;
        for(int i : arr)
        {
            if(multiple % i ==0)
            {
                answer= multiple;
            }
            else
            {
                answer= 0;
                break;
            }
        }
    }
    
    return answer;
}