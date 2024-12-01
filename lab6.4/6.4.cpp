#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

void generateArray(double* arr, int n, double min, double max) {
    for (int i = 0; i < n; ++i) {
        arr[i] = min + (rand() % (int)(max - min + 1)) + (rand() % 100) / 100.0;
    }
}

void printArray(double* arr, int n) {
    for (int i = 0; i < n; ++i) {
        cout << setw(8) << arr[i];  // Форматний вивід через setw(8)
    }
    cout << endl;
}

double sumNegativeElements(double* arr, int n) {
    double sum = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i] < 0) {
            sum += arr[i];
        }
    }
    return sum;
}

double productBetweenMinMax(double* arr, int n) {
    int minIndex = 0, maxIndex = 0;
    for (int i = 1; i < n; ++i) {
        if (arr[i] < arr[minIndex]) minIndex = i;
        if (arr[i] > arr[maxIndex]) maxIndex = i;
    }

    if (minIndex > maxIndex) swap(minIndex, maxIndex);

    double product = 1;
    for (int i = minIndex + 1; i < maxIndex; ++i) {
        product *= arr[i];
    }
    return product;
}

void sortEvenNumbers(double* arr, int n) {
    double temp;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if ((int)arr[i] % 2 == 0 && (int)arr[j] % 2 == 0 && arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    double* arr = new double[n];
    generateArray(arr, n, -20.0, 50.0);

    cout << "\nOriginal array:\n";
    printArray(arr, n);

    double sum = sumNegativeElements(arr, n);
    cout << "\nSum of negative elements: " << sum << endl;

    double product = productBetweenMinMax(arr, n);
    cout << "\nProduct of elements between max and min: " << product << endl;

    sortEvenNumbers(arr, n);
    cout << "\nSorted array with even numbers in ascending order:\n";
    printArray(arr, n);

    delete[] arr;
    return 0;
}
