#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

vector<int> primes = {2};

int main() {
    bool is_prime;
    int i = 3;
    while(primes.size() < 10001) {
        is_prime = true;
        for (int j = 0; j < primes.size(); j++) {
            if (i % primes[j] == 0) {
                is_prime = false;
                break;
            }
        }
        if (is_prime == true) {
            primes.push_back(i);
            i += 2;
        }
        if (is_prime == false) {
            i += 2;
        }
    } 
    
   cout << primes[10000];
}