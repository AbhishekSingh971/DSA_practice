#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // this is the wrong method not work while count
    //  int countPrimes(int n) {
    //      int count = 0;
    //      for(int i=2; i<n;i++){
    //          if(i==2||i==3||i==5||i==7||i==11){
    //              count+=1;
    //          }else if(i%2 != 0 && i%3 != 0 && i%5!=0 && i%7 != 0 && i%11 != 0){
    //              continue;
    //          }else{
    //              count+=1;
    //          }
    //      }
    //      return count;
    //  }

    // Sieve of Eratosthenes
    int countPrimes(int n)
    {
        if (n < 2)
            return 0;
        vector<bool> isPrime(n, true);

        isPrime[0] = false, isPrime[1] = false;

        for (int i = 2; i * i < n; i++)
        {
            if (isPrime[i])
            {
                for (int j = i * i; j < n; j += i)
                {
                    isPrime[j] = false;
                }
            }
        }

        int count = 0;

        for (int i = 0; i < n; i++)
        {
            if(isPrime[i]) count++;
        }
        

        return count;
    }
};

int main()
{
    Solution sol;
    int n = 10;
    int result = sol.countPrimes(n);
    cout << "Number of primes less than " << n << ": " << result << endl;
    return 0;
}