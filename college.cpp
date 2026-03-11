#include <iostream>
#include <string>
using namespace std;

struct Student {
    int regID;
    string name;
    int score;
};

// -------- Merge Sort (by Registration ID) --------
void merge(Student arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    Student L[n1], R[n2];

    for(int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for(int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;

    while(i < n1 && j < n2) {
        if(L[i].regID <= R[j].regID) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < n1) {
        arr[k] = L[i];
        i++; k++;
    }

    while(j < n2) {
        arr[k] = R[j];
        j++; k++;
    }
}

void mergeSort(Student arr[], int l, int r) {
    if(l < r) {
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// -------- Quick Sort (by Score Descending) --------
int partition(Student arr[], int low, int high) {
    int pivot = arr[high].score;
    int i = low - 1;

    for(int j = low; j < high; j++) {
        if(arr[j].score > pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(Student arr[], int low, int high) {
    if(low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void displayTop10(Student arr[], int n) {
    cout << "\nTop Students:\n";
    int limit = (n < 10) ? n : 10;

    for(int i = 0; i < limit; i++) {
        cout << arr[i].regID << " "
             << arr[i].name << " "
             << arr[i].score << endl;
    }
}

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    Student s[n];

    for(int i = 0; i < n; i++) {
        cout << "Enter RegID Name Score: ";
        cin >> s[i].regID >> s[i].name >> s[i].score;
    }

    // Sort by Registration ID using Merge Sort
    mergeSort(s, 0, n - 1);

    cout << "\nSorted by Registration ID:\n";
    for(int i = 0; i < n; i++)
        cout << s[i].regID << " " << s[i].name << " " << s[i].score << endl;

    // Sort by Score using Quick Sort (Descending)
    quickSort(s, 0, n - 1);

    displayTop10(s, n);

    return 0;
}
