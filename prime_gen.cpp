#include <bits/stdc++.h>

using namespace std;

vector<bool> number_line(100002,1);

void sieve(int prime)
{
    if(prime == 2)
    {
        int i = 2;
        while(prime <= 100002)
        {
            number_line[prime*i] = 0;
            i += 1;
        }
    }
    else{
        for(int i = 3; i < 100002; i += 2)
        {
            number_line[prime*i] = 0;
        }
    }
}

//Finding prime numbers by using the Sieve of Eratosthenes algorithm...

int main()
{
    for(int i = 2; i < number_line.size(); ++i)
    {
        if(number_line[i])
        {
            sieve(i);
        }
    }
}