#include<iostream>
#include<vector>
using namespace std;

int merge(vector<int>& a, vector<int>& b, vector<int>& res) {
    int i = 0, j = 0, k = 0, count = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i] <= b[j]) {
            res[k++] = a[i++];
        } else {
            // All remaining elements in 'a' form inversions with b[j]
            count += (a.size() - i);
            res[k++] = b[j++];
        }
    }
    while (i < a.size()) res[k++] = a[i++];
    while (j < b.size()) res[k++] = b[j++];
    return count;
}

int mergesort(vector<int>& v) {
    if (v.size() <= 1) return 0;
    int n = v.size();
    int n1 = n / 2, n2 = n - n1;
    vector<int> a(v.begin(), v.begin() + n1);
    vector<int> b(v.begin() + n1, v.end());

    int count = 0;
    count += mergesort(a);
    count += mergesort(b);
    count += merge(a, b, v);
    return count;
}

int main() {
    int arr[] = {5, 1, 3, 0, 4, 9, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> v(arr, arr + n);

    cout << "Before: ";
    for (int x : v) cout << x << " ";
    cout << endl;

    int inversions = mergesort(v);

    cout << "After:  ";
    for (int x : v) cout << x << " ";
    cout << endl;

    cout << "Inversions: " << inversions << endl;
}