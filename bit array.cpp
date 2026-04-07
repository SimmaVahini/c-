#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    long long N, S, P, Q;
    if (!(cin >> N >> S >> P >> Q)) return 0;

    // 2^31 bits = 2^26 unsigned ints (32 bits each)
    const unsigned int limit = 1u << 31;
    vector<unsigned int> bitset((limit >> 5), 0);

    unsigned int current = S % limit;
    unsigned int count = 0;

    for (int i = 0; i < N; ++i) {
        // Check if the bit at position 'current' is already set
        if (!(bitset[current >> 5] & (1u << (current & 31)))) {
            bitset[current >> 5] |= (1u << (current & 31));
            count++;
        } else {
            // Once we hit a value already in the bitset, 
            // the sequence will repeat and no new distinct values will appear.
            break; 
        }
        current = (current * P + Q) % limit;
    }

    cout << count << endl;
    return 0;
}
   
