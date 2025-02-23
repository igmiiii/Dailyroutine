#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> nums) {
    int answer = 0;
    
    int sum = 0;
    vector <int> temp;
    
    for(int i= 0; i<nums.size(); ++i)
    {
        for(int j= 0; j< nums.size() ; ++j)
        {
            for(int k= 0 ; k< nums.size(); ++k)
            {
                if(nums[i] != nums[j] && nums[j] != nums[k]&&  nums[i] != nums[k] &&i!=j && j != k && i !=k)
                {
                    sum = (nums[i]+nums[j]+nums[k]);
                    for(int l = 2; l <sum; ++l)
                    {
                        if(sum %l ==0)
                        {
                            temp.push_back(l);
                            
                        }
                        
                    }
                    if(temp.size()== 0)
                            {
                                answer +=1;
                            }
                    temp.clear();
                }
                sum = 0;
            }
        }
    }
    
    answer = answer/6 ;
    
    
    

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;

    return answer;
}