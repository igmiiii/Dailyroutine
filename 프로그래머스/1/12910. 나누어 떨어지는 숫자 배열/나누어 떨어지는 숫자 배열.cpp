#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> vec;
    
    for(int i= 0; i < arr.size(); i++)
    {
        if(arr[i]%divisor ==0)
        {
            vec.push_back(arr[i]);
        }
    }
    if(vec.empty())
    {
        vec.push_back(-1);}
    sort(vec.begin(), vec.end());
    
    
    return vec;
}