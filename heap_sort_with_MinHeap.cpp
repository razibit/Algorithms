#include<bits/stdc++.h>
using namespace std;

void minHeapify(vector<int>&arr,int n,int i){
    int smallest = i; 
    int leftchild = 2*i+1;
    int rightchild = 2*i+2;

    if(leftchild<n && arr[leftchild]<arr[smallest]){
        smallest = leftchild;
    }

    if(rightchild<n && arr[rightchild]<arr[smallest]){
        smallest = rightchild;
    }

    if(smallest != i){
        swap(arr[smallest],arr[i]);
        minHeapify(arr,n,smallest);// performing heapfication again* to avoid any sort of violation of minheap structure
                                   //heapifying at new position = 'smallest' 
    }
}

void heapSort(vector<int>&arr,int n){
    for(int i = (n/2)-1; i >= 0; i--){
        minHeapify(arr,n,i);
    }
    
    for(int i = n-1; i>0; i--){
        swap(arr[i],arr[0]);
        minHeapify(arr,i,0);
    }

}

void printingHeapSort(vector<int>&arr,int n){
    for(int i=0;i<n;i++){
        cout << arr[i] << " " ;
    }
    cout << '\n';
}

    
int main(){
    int n;
    cout << "Heap Sort | Descending Order\n-------------------\n";
    cout << "Enter the size of the array:\n";
    cin >> n;

    vector<int> arr(n);

    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    heapSort(arr,n);

    cout << "Sorted Array: ";
    printingHeapSort(arr,n);
    cout << '\n';
}