#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    
    unordered_set<int> Sum;
    vector<int> Temp= elements;
    
    for(int j = 0 ; j< elements.size(); ++j )
    {
        Temp = elements;
        
        for(int i = 0 ; i<elements.size(); ++i)
        {
            int sum =0 ;
            rotate(Temp.begin(), Temp.begin()+1, Temp.end());
            
            for(int k = 0; k<j+1; ++k)
            {
                sum+= Temp[k];
            }
            Sum.insert(sum);
        }
    }
    answer = Sum.size();
                
    return answer;
}