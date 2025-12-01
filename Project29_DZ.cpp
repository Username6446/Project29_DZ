#include <iostream>
#include "Array.h"

int main() {
    cout << "=== Test 1: Int Array & Add ===" << endl;
    Array<int> arr;
    arr.SetSize(2, 2);

    arr.Add(10);
    arr.Add(20);
    arr.Print();

    arr.Add(30);
    arr.Print();

    cout << "\n=== Test 2: GetAt & [] ===" << endl;
    cout << "Element at 1: " << arr.GetAt(1) << endl;

    cout << "Trying invalid index:" << endl;
    arr[10] = 99;

    arr[1] = 99;
    cout << "Element at 1 after change: " << arr[1] << endl;

    cout << "\n=== Test 3: InsertAt & RemoveAt ===" << endl;
    arr.InsertAt(0, 5);
    arr.Print();

    arr.RemoveAt(2);
    arr.Print();

    arr.RemoveAt(100);

    cout << "\n=== Test 4: FreeExtra ===" << endl;
    cout << "Before FreeExtra -> Capacity: " << arr.GetSize() << endl;
    arr.FreeExtra();
    cout << "After FreeExtra -> Capacity: " << arr.GetSize() << endl;

    cout << "\n=== Test 5: Append & Copy ===" << endl;
    Array<int> arr2;
    arr2.Add(100);
    arr2.Add(200);

    arr.Append(arr2);
    arr.Print();

    Array<int> arr3 = arr;
    cout << "Copied array: ";
    arr3.Print();

    return 0;
}