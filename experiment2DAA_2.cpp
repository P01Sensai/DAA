#include<bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

vector<int> quickSort(vector<int> arr)
{
    if (arr.size() <= 1) {
        return arr;
    }

    int pivotIndex = arr.size() / 2;
    int pivotValue = arr[pivotIndex];

    vector<int> left, right, equal;

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] < pivotValue) {
            left.push_back(arr[i]);
        } else if (arr[i] > pivotValue) {
            right.push_back(arr[i]);
        } else {
            equal.push_back(arr[i]);
        }
    }

    left = quickSort(left);
    right = quickSort(right);

    vector<int> sorted;
    sorted.reserve(left.size() + equal.size() + right.size());

    sorted.insert(sorted.end(), left.begin(), left.end());
    sorted.insert(sorted.end(), equal.begin(), equal.end());
    sorted.insert(sorted.end(), right.begin(), right.end());

    return sorted;
}

int main()
{
    int n;
    cout << "Enter the size of unsorted array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the unsorted array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    arr = quickSort(arr);

    cout << "The sorted array \n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}