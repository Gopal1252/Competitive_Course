#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+5;
int bit[N] = {0};

//update(i, +1) — Insert number i
void update(int i, int delta, int n) {
    while (i <= n) {
        bit[i] += delta;
        i += i & -i;
    }
}

//query(i) — Count of numbers ≤ i
int query(int i) {
    int sum = 0;
    while (i > 0) {
        sum += bit[i];
        i -= i & -i;
    }
    return sum;
}

//find_kth(k) — Find the k-th smallest number
//We do binary search on the prefix sums.
int find_kth(int k, int n) {
    int l = 1, r = n, ans = -1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (query(mid) >= k) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return ans; // kth smallest number
}

//rank(x) — Count of numbers strictly < x
int Rank(int x) {
    return query(x - 1);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    //Insert elements: [3, 1, 4, 1, 5, 9]

    update(3, +1, N);
    update(1, +1, N);
    update(4, +1, N);
    update(1, +1, N);
    update(5, +1, N);
    update(9, +1, N);

    //find_kth(3) → should return 3
    cout<<find_kth(3,N)<<"\n";

    // rank(4) → how many numbers < 4? → should return 3
    cout<<Rank(4)<<"\n";

    return 0;
}