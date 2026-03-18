#include <iostream>
#include <algorithm>
using namespace std;

struct Item {
    int weight, value;
};
bool cmp(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

int main() {
    int n, capacity;
    cout << "Enter number of items: ";
    cin >> n;

    Item arr[100];

    cout << "Enter value and weight:\n";
    for(int i = 0; i < n; i++) {
        cin >> arr[i].value >> arr[i].weight;
    }

    cout << "Enter capacity: ";
    cin >> capacity;

    sort(arr, arr + n, cmp);

    double totalValue = 0;

    for(int i = 0; i < n; i++) {
        if(capacity >= arr[i].weight) {
            capacity -= arr[i].weight;
            totalValue += arr[i].value;
        } else {
            totalValue += (double)arr[i].value * capacity / arr[i].weight;
            break;
        }
    }

    cout << "Maximum value: " << totalValue;

    return 0;
}
