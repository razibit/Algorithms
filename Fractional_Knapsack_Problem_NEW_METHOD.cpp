#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,w;
    cin >> n >> w;

    vector<pair<double ,double>> vw(n);
    vector<pair<double ,double>> rw;

    for(int i=0;i<n;i++){
        cin >> vw[i].first >> vw[i].second;
        double ratio = (double)vw[i].first/vw[i].second;
        rw.push_back({vw[i].second,ratio});
        //rw[i] = {vw[i].second,ratio};
    }

    sort(rw.begin(),rw.end(),[](pair<double,double>a,pair<double,double>b){
        return a.second>b.second;
    });

    double cload = 0.0,value=0.0; //current load // w = capacity

    for(int i =0;i<n;i++){
        
            if((w-cload)>=rw[i].first){
                value += rw[i].first*rw[i].second;
                cload += rw[i].first;
            }
            else{
                double rest = w - cload;
                value += rest * rw[i].second;
                break;
            }
    }

    cout << fixed << setprecision(8) << value << '\n';

}