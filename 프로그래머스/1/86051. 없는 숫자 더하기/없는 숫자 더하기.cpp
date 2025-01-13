#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;
    int sum = 0;
    
    for(int j = 0 ; j<numbers.size(); j++)
    {
        for( int i = 1 ; i<10 ; i++)
        {
            if( numbers[j] == i)
            {
            answer+= numbers[j];
            }
        }
    }
    for(int k =0; k<10 ; k++)
    {
        sum+= k;
    }
    
    return sum -answer;
}