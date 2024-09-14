#include<iostream>
using namespace std;

void heapify(int arr[], int n, int i){
    int biggest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && arr[left] > arr[biggest]){
        biggest = left;
    }

    if( right < n && arr[right] > arr[biggest]){
        biggest = right;
    }

    if(biggest != i){
        swap(arr[biggest],arr[i]);

        heapify(arr, n, biggest);
    }
}

void heapSort(int arr[],int n){
    for(int i = n/2-1;i>=0;i--){
        heapify(arr,n,i);
    }

    for(int i = n-1; i>0;i--){

        swap(arr[0],arr[i]);
        
        heapify(arr,i,0);
    }
}

void printingArray(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << '\n';
}

int main(){
    cout << "Enter size of the array:" << '\n';
    int n;
    cin >> n;
    int arr[n];
    for(int i =0;i<n;i++){
        cin >> arr[i];
    }

    heapSort(arr,n);
    cout << "Sorted Array is \n";
    printingArray(arr,n);

    return 0;
}