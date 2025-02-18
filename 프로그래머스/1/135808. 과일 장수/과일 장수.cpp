#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    
    sort(score.begin(), score.end());
    
    for(int i = 0 ; i< score.size()/m; ++i)
    {
    answer+= score[score.size()%m + m*i]*m;
        }
    
    return answer;
}