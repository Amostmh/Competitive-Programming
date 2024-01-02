#include <bits/stdc++.h>

using namespace std;

vector<bool> isPrime(1000002,1);
vector<int> primes;
void sieve(int prime)
{
    if(prime == 2)
    {
        int i = 2;
        while(prime*i <= 1000002)
        {
            isPrime[prime*i] = 0;
            i += 1;
        }
    }
    else{
        for(int i = 3; prime*i < 1000002; i += 2)
        {
            isPrime[prime*i] = 0;
        }
    }
}

pair<string,int> countSteps(int starting_number);

void solve()
{
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        int room;
        pair<string,int> winner = {"",INT_MAX};

        for(int i =0 ; i < n; ++i)
        {
            cin >> room;
            pair<string,int> ans = countSteps(room);
            winner = min(winner,ans,[](pair<string,int> x, pair<string,int> y){return x.second < y.second;});
        }
        cout << winner.first << '\n';
    }
}

pair<string,int> countSteps(int starting_number)
{
    pair<string,int> out;
    int steps = 0;
    if(starting_number % 4 != 0)
    {
        //John wins;
        out.first = "Farmer John";

        for(int i = 4; i < starting_number; i += 4)
        {
            if(isPrime[starting_number-i])
            {
                starting_number -= i;
                steps += 1;
                steps += starting_number/2;
                out.second = steps;
                break;
            }
        }
    }
    else{
        // John loses;
        out.first = "Farmer Nhoj";
        steps += starting_number/2;
        out.second = steps;
    }
    return out;
}   
//Finding prime numbers by using the Sieve of Eratosthenes algorithm...

int main()
{
    for(int i = 2; i < isPrime.size(); ++i)
    {
        if(isPrime[i])
        {
            sieve(i);
        }
    }

    int k = 0;
    for(int i = 1; i < isPrime.size(); ++i)
    {
        if(isPrime[i])
        {
            k ++;
            primes.push_back(i);
        }
    }

    solve();
    return 0;
}