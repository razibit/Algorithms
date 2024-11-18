#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<pair<int,int>> se(n);
        for(int i=0;i<n;i++){
            cin >> se[i].first >> se[i].second;
        }

        sort(se.begin(),se.end(),[](pair<int,int> &a, pair<int,int> &b){
            return a.second < b.second;
        });

        
        
        int c=1,current = se[0].second;
        for(int i=1;i<n;i++){
            if(se[i].first>=current){
                c++;
                current = se[i].second;
            }
        }
        cout << c << '\n';
    }
}