using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = 0;
    answer = money;
    
    for (int i = 1 ; i <= count ; i++)
    {
    answer -= (long long)price*i;
    }
    
    
    if(answer >= 0)
    {
        return 0;
    }
    return -answer;
}