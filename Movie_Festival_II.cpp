#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    vector<pair<int, int>> arr(n);

    for(int i=0;i<n;i++){
        cin >> arr[i].first >> arr[i].second;
    }

    sort(arr.begin(),arr.end(),[](pair<int, int>&a, pair<int, int> &b){
        return a.second < b.second;
    });

    for(int)


}