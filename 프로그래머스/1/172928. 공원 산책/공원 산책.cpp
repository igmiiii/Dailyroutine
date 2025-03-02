#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    
    int sx = 0;
    int sy = 0;
    
    for(int i = 0 ; i<park.size(); ++i)
    {
        if(park[i].find('S') != string::npos)
        {
            sx = i;
            sy = park[i].find('S');
        }
    }
    
    for(string route : routes)
        {
            int tempsx = sx;
            int tempsy = sy;
            bool possible = true;
        
            switch(route[0])
            {
                case 'E':
                    
                    
                    
                    for(int i = 0; i< ((route[2]) - '0'); ++i )
                    {
                        if(tempsy+1 < park[0].size())
                        {
                            
                            if(park[tempsx][tempsy+1]!='X')
                            {

                                tempsy++;
                            }
                            else
                            {
                                possible = false;
                                break;
                            }
                        }
                        else
                        {
                            possible = false;
                            break;
                        }
                    }
                    
                    break;
                    
                case 'S':
                    
                    
                    for(int i = 0; i< ((route[2]) - '0'); ++i )
                    {
                        if(tempsx+1 < park.size())
                        {
                            
                            if(park[tempsx+1][tempsy]!='X')
                            {

                                tempsx++;
                            }
                            else
                            {
                                possible = false;
                                break;
                            }
                        }
                        else
                        {
                            possible = false;
                            break;
                        }
                    }
                    
                    break;
                    
                case 'N':
                    
                    
                    for(int i = 0; i< ((route[2]) - '0'); ++i )
                    {
                        if(tempsx-1 >= 0)
                        {
                            
                            if(park[tempsx-1][tempsy]!='X')
                            {

                                tempsx--;
                            }
                            else
                            {
                                possible = false;
                                break;
                            }
                        }
                        else
                        {
                            possible = false;
                            break;
                        }
                    }
                    
                    break;
                    
                case 'W':
                    
                    
                    for(int i = 0; i< ((route[2]) - '0'); ++i )
                    {
                        if(tempsy-1 >= 0)
                        {
                            
                            if(park[tempsx][tempsy-1]!='X')
                            {

                                tempsy--;
                            }
                            else
                            {
                                possible = false;
                                break;
                            }
                        }
                        else
                        {
                            possible = false;
                            break;
                        }
                    }
                    
                    break;
            }
        if (possible) {
            sx = tempsx;
            sy = tempsy;
        }
        }
    answer.push_back(sx);
    answer.push_back(sy);
    
    
    return answer;
}