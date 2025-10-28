#include <iostream>

using namespace std;

int main() {
    int n;

    cout << "Enter the number of elements: ";
    cin >> n;

    if(n<=0)
        {
    cout<<"Invalid array size ";
    return 0;
    }

    int arr[n];

    cout << "Enter the elements: ";
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }


    double average = double(sum) / n;
    cout << "Average: " << average << endl;

    return 0;
}
