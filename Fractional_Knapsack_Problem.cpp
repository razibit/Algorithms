#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int n,w;
    cin >> n >> w;

    vector<pair<double, int>> items;
    
    for(int i=0;i<n;i++){
        int v,w;
        cin >> v >> w;

        double r = (double)v/w;
        items.push_back(make_pair(r,w));
    }

    sort(items.begin(),items.end(),[](pair<double,int> &a,pair<double,int>&b){
        return a.first > b.first;
    });

    int remCapacity = w;
    double val=0.0;

    for(int i=0;i<n;i++){
        int itemWeight = items[i].second;
        double ratio = items[i].first;

        if(remCapacity >= itemWeight){
            val += itemWeight * ratio;
            remCapacity -= itemWeight;
        }else{
            val += ratio*remCapacity;
            break;
        }
    }

    if(val == (int)val){
        cout << (int)val << endl;
    }else{
        cout.precision(8);
        cout << fixed << val << '\n';
    }

    return 0;

}