#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;
using ll = long long;
#define int ll
bool allSame(const vector<int> &v) {
    int a = v[0];
    for (int i :{1, 2}) {
        if (v[i] != a)return false;
    }
    return true;
}

bool anyTwoproducttttSame(vector<int> proddd) {
    int n = proddd.size();
    if (n <= 1)return false;
    if (n == 2)return proddd[0] == proddd[1];
    unordered_set<int> s;
    for (int i: proddd) {
        s.insert(i);
    }
    return s.size() <= 2;
}

bool anyZero(const vector<int> &A) {
    return A[0] == 0 || A[1] == 0 || A[2] == 0;
}

bool mulAdd(vector<pair<int, int>> givenTarget) {
    // a*x + y = p
    // b*x + y = q
    // c*x + y = r

    std::sort(givenTarget.begin(), givenTarget.end());

    do {
        for (int i = 0; i < 3; ++i) {
            int a = givenTarget[0].first, b = givenTarget[1].first, c = givenTarget[2].first;
            int p = givenTarget[0].second, q = givenTarget[1].second, r = givenTarget[2].second;
            if ((a != b) && ((p - q) % (a - b) == 0 && (a * q - b * p) % (a - b) == 0)) {
                int x = (p - q) / (a - b), y = (a * q - b * p) / (a - b);
                if ((c * x + y == r) || (c * x == r) || (c + y == r)) {
                    return true;
                }
                // if y == 0
                // a*x = p
                // b*x = q
                // c*x + Y = r

                if(y == 0)return true;
            }
        }
    } while (std::next_permutation(givenTarget.begin(), givenTarget.end()));


    return false;
}

bool addMul(vector<pair<int, int>> givenTarget) {
    // (a+x)*y = p
    // (b+x)*y = q
    // (c+x)*y = r

    std::sort(givenTarget.begin(), givenTarget.end());

    do {
        for (int i = 0; i < 3; ++i) {
            int a = givenTarget[0].first, b = givenTarget[1].first, c = givenTarget[2].first;
            int p = givenTarget[0].second, q = givenTarget[1].second, r = givenTarget[2].second;
            if ((p != q && a != b) && ((a * q - b * p) % (p - q) == 0 && (p - q) % (a - b) == 0)) {
                int x = (a * q - b * p) / (p - q), y = (p - q) / (a - b);
                if (((c + x) * y == r) || (c * y == r) || (c + x == r)) {
                    return true;
                }
            }
        }
    } while (std::next_permutation(givenTarget.begin(), givenTarget.end()));


    return false;
}

bool addAdd(vector<pair<int, int>> givenTarget) {
    // a+x = p
    // (b+x)+y = q
    // c+y = r
    std::sort(givenTarget.begin(), givenTarget.end());

    do {
        for (int i = 0; i < 3; ++i) {
            int a = givenTarget[0].first, b = givenTarget[1].first, c = givenTarget[2].first;
            int p = givenTarget[0].second, q = givenTarget[1].second, r = givenTarget[2].second;


            int x = p - a, y = r - c;
            if (q == b + (x + y)) {
                return true;
            }

        }
    } while (std::next_permutation(givenTarget.begin(), givenTarget.end()));


    return false;
}

bool multMult(vector<pair<int, int>> givenTarget) {
    // a*x = p
    // (b*x)*y = q
    // c*y = r
    std::sort(givenTarget.begin(), givenTarget.end());

    do {
        for (int i = 0; i < 3; ++i) {
            int a = givenTarget[0].first, b = givenTarget[1].first, c = givenTarget[2].first;
            int p = givenTarget[0].second, q = givenTarget[1].second, r = givenTarget[2].second;

            if (a != 0 && c != 0 && p % a == 0 && r % c == 0) {
                int x = p / a, y = r / c;
                if (q == (b * x * y)) {
                    return true;
                }
            }
        }
    } while (std::next_permutation(givenTarget.begin(), givenTarget.end()));


    return false;
}

bool addMult(vector<pair<int, int>> givenTarget) {

    // a+x = p
    // (b+x)*y = q
    // c*y = r



    // a*y = p
    // b+x = q
    // (c+x)*y = r

    // (a+x)*y = p
    // b*y = q
    // c+x = r


    // (a+x)*y = p
    // b+x = q
    // c*y = r

    std::sort(givenTarget.begin(), givenTarget.end());

    do {
        for (int i = 0; i < 3; ++i) {
            int a = givenTarget[0].first, b = givenTarget[1].first, c = givenTarget[2].first;
            int p = givenTarget[0].second, q = givenTarget[1].second, r = givenTarget[2].second;
            if (c != 0 && r % c == 0) {
                int x = p - a, y = r / c;
                if (q == (b + x) * y) {
                    return true;
                }
            }

        }
    } while (std::next_permutation(givenTarget.begin(), givenTarget.end()));


    return false;
}

bool multAdd(vector<pair<int, int>> givenTarget) {

    // a*x = p
    // (b*x)+y = q
    // c+y = r
    std::sort(givenTarget.begin(), givenTarget.end());

    do {
        for (int i = 0; i < 3; ++i) {
            int a = givenTarget[0].first, b = givenTarget[1].first, c = givenTarget[2].first;
            int p = givenTarget[0].second, q = givenTarget[1].second, r = givenTarget[2].second;
            if (a != 0 && p % a == 0) {
                int x = p / a, y = r - c;
                if ((b * x) + y == q) {
                    return true;
                }
            }

        }
    } while (std::next_permutation(givenTarget.begin(), givenTarget.end()));


    return false;
}


bool anyTwoSame(const vector<int> &v) {
    unordered_set<int> s;
    for (int i = 0; i < 3; ++i) {
        s.insert(v[i]);
    }
    return s.size() == 2;
}

void get_it_done() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

signed main() {
    get_it_done();

    int t;
    cin >> t;
    while (t--) {
        vector<int> given(3), target(3), diff(3), proddd;
        vector<pair<int, int>> vp(3);
        for (int i = 0; i < 3; ++i) {
            cin >> given[i];
        }
        for (int i = 0; i < 3; ++i) {
            cin >> target[i];
        }
        for (int i = 0; i < 3; ++i) {
            diff[i] = (target[i] - given[i]);
            vp[i] = make_pair(given[i], target[i]);
        }
        vector<int> diff_zero_infront(3);
        int i = count(diff.begin(), diff.end(), 0);


        for (int j = 0; j < 3; ++j) {
            if (diff[j] != 0)
                diff_zero_infront[i++] = diff[j];
        }
        diff = diff_zero_infront;
//        for(auto it: diff)cout << it << ' ';
//        cout << '\n';
        if (allSame(diff) && diff[0] == 0) {
            cout << 0 << '\n';
            continue;

        }
        for (i = 0; i < 3; ++i) {
            if ((given[i] != 0) && (target[i] != given[i]) && target[i] % given[i] == 0) {
                proddd.push_back(target[i] / given[i]);
            }
        }
        if (allSame(diff) || diff[0] == 0 && (diff[1] == diff[2] || anyTwoproducttttSame(proddd)) ||
            (diff[0] == 0 && diff[1] == 0)) {
            cout << 1 << '\n';
            continue;
        }


        if (proddd.size() == 3 && allSame(proddd)) {
            cout << 1 << '\n';
            continue;
        }


        if (anyZero(diff) || (proddd.size() == 2 && proddd[0] == proddd[1]) || anyTwoSame(diff)) {
            cout << 2 << '\n';
            continue;
        }
        if (mulAdd(vp) || addMul(vp)) {
            cout << 2 << '\n';
            continue;
        }
        if (addAdd(vp) || multMult(vp) || addMult(vp) || multAdd(vp)) {
            cout << 2 << '\n';
            continue;
        }

        cout << 3 << '\n';
    }


}