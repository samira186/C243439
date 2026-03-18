#include <iostream>
#include <algorithm>
using namespace std;

struct Activity {
    int start, finish;
};
bool cmp(Activity a, Activity b) {
    return a.finish < b.finish;
}

int main() {
    int n;
    cout << "Enter number of activities: ";
    cin >> n;

    Activity a[100];

    cout << "Enter start and finish time:\n";
    for(int i = 0; i < n; i++) {
        cin >> a[i].start >> a[i].finish;
    }

    sort(a, a + n, cmp);

    cout << "Selected activities:\n";

    int i = 0;
    cout << "(" << a[i].start << "," << a[i].finish << ") ";

    for(int j = 1; j < n; j++) {
        if(a[j].start >= a[i].finish) {
            cout << "(" << a[j].start << "," << a[j].finish << ") ";
            i = j;
        }
    }

    return 0;
}
