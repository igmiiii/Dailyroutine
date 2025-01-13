#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    
    if( arr.size() ==1)
    {
        arr.pop_back();
        arr.push_back(-1);
    }
    else
    {
        arr.erase(min_element(arr.begin(), arr.end()));
    }
    return arr;
}