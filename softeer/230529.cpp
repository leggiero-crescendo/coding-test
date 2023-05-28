#include <iostream>
#include <vector>
using namespace std;

int N, T;
vector<long long> C, D;

bool test(long long testSets) {
    long long now = C[0];
    for (int i = 0; i < N - 1; i++) {
        if (now >= testSets) {
            now = C[i + 1] + D[i];
        }
        else if (now + D[i] >= testSets) {
            now = C[i + 1] + (now + D[i] - testSets);
        }
        else {
            return false;
        }
    }
    if (now >= testSets) {
        return true;
    }
    else {
        return false;
    }
}

long long Bsearch(long long start, long long end) {
    if (start == end) {
        return start;
    }
    long long mid = (start + end + 1) / 2;
    if (test(mid)) {
        return Bsearch(mid, end);
    }
    else {
        return Bsearch(start, mid - 1);
    }
}

int main() {
    cin >> N >> T;
    for (int t = 0; t < T; t++) {
        vector<long long> Questions(2 * N - 1);
        for (int i = 0; i < 2 * N - 1; i++) {
            cin >> Questions[i];
        }
        
        C.clear();
        D.clear();
        for (int i = 0; i < N - 1; i++) {
            C.push_back(Questions[2 * i]);
            D.push_back(Questions[2 * i + 1]);
        }

        C.push_back(Questions[2 * (N - 1)]);

        cout << Bsearch(0, 2 * (long long)1e12) << endl;
    }

    return 0;
}
