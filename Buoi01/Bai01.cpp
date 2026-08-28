#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

#define MAX 10

int main() {
    int n;
    cin >> n;
    int a[MAX];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    // a. the minimum number of the array
    int min = a[0];
    for (int i = 0; i < n; i++) {
        if (min > a[i]) {
            min = a[i];
        }
    }
    cout << "Cau a: " << min << endl;

    //b. Calculate the sum of the list
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }
    cout << "Cau b: " << sum << endl;

    //c. Find the first negative number in the array
    int firstnegative = 0;
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (a[i] < 0 ) {
            firstnegative = a[i];
            found = true;
            break;
        }
    }
    if (found) cout << "Cau c:" << firstnegative << endl;
    if (!found) return 0;
    return 0;
}
