#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 1;
    
    int rowsize = 0;
    vector <int> mx;
    vector<vector<int>> newsizes;
    
    for(vector<int> vec : sizes)
    {
        sort(vec.begin(), vec.end());
        newsizes.push_back(vec);
    }
    
    rowsize = newsizes[0].size();
    
    for(int i = 0; i<rowsize; ++i)
    {
        int colmax = newsizes[0][i];
        for(int row= 1; row<newsizes.size(); ++row)
        {
            colmax= max(colmax, newsizes[row][i]);
        }
        mx.push_back(colmax);
    }
    
    for(int j : mx)
    {
        answer*= j;
    }
    
    
    return answer;
}