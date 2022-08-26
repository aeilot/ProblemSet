#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

#define ll long long

vector<char> flags;
vector<ll> prime;
ll p;

int isPrime(ll n) {
    if (n < 2) return 0;
    ll n1 = sqrt(n);
    for (ll i = 2; i <= n1; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

void sift(ll n) {
    flags.resize(n + 1, 1);
    p = 0;
    flags[0] = flags[1] = 0;
    ll n1 = sqrt(n);
    for (ll i = 2; i <= n1; i++) {
        if (flags[i] == 1) {
            flags[i] = isPrime(i);
        }
        if (flags[i] == 1) {
            ll n2 = n / i;
            for (ll j = 2; j <= n2; j++) {
                flags[j * i] = 0;
            }
        }
    }
    for (ll i = 0; i <= n; i++) {
        if (flags[i] == 1) {
            prime.push_back(i);
            p++;
        }
    }
}

int main() {
    sift(600851475143);
    for (ll i = p - 1; i >= 0; i--) {
        if (600851475143 % prime[i] == 0) {
            printf("%lld\n", prime[i]);
            break;
        }
    }
    return 0;
}