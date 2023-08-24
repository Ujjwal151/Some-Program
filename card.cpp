#include <bits/stdc++.h>
using namespace std;
#define all(v) begin(v), end(v)
const vector<int> given10 = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99};
const vector<int> given11 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49};
const vector<int> given20 = {2, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 43, 44, 45, 46, 47, 48, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79};
vector<int> received10, received11, received20;
vector<int> absent10(100, -10), absent11(100, -11), absent20(100, -20);

void printvec(int n, vector<int> &v)
{
    int cnt = v.size() - count(all(v), -n);
    printf("\nSeries %d >> Absent: %d \n", n, cnt);
    for (auto x : v){
        if( x < 10) break;
        cout << x << " ";
    }
    cout << "\n";
}

void fun(vector<int> &received, int terminateValue)
{
    int id;
    cin >> id;
    while (id != terminateValue)
    {
        received.push_back(id);
        cin >> id;
    }
}

int32_t main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    fun(received10, -10);
    fun(received11, -11);
    fun(received20, -20);
    set_difference(all(given10), all(received10), begin(absent10));
    set_difference(all(given11), all(received11), begin(absent11));
    set_difference(all(given20), all(received20), begin(absent20));
    printvec(10, absent10);
    printvec(11, absent11);
    printvec(20, absent20);
    printf("\nTotal Given : %d\n", given10.size() + given11.size() + given20.size());
    printf("Total Received : %d\n", received10.size() + received11.size() + received20.size());
}
