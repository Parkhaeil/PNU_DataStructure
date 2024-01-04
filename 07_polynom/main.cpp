#include <bits/stdc++.h>

using namespace std;

bool mysort(pair<int,int> a, pair<int,int> b){
    return a.second > b.second;
}

int N, k, ci, ei,i,j;
int main() {
    //freopen("input.txt","r",stdin);

    cin >> N;
    vector<pair<int, int>> poly;

    for (i=0; i<N; i++) {
        cin >> k;
        for (j=0; j<k; j++) {
            cin >> ci >> ei;
            poly.push_back(make_pair(ci, ei));
        }
    }

    sort(poly.begin(),poly.end(),mysort);

    vector <pair<int,int>> final_poly;
    int temp=-1;
    for(auto X:poly){
        if(temp!=X.second){
            final_poly.push_back(X);
            temp=X.second;
        }
        else{
            final_poly.back().first += X.first;
        }
        if(final_poly.back().first==0){
            final_poly.erase(final_poly.end()-1);
            temp = -1;
        }

    }
    if(!final_poly.empty()){
        cout << final_poly.size()<<endl;
        for(auto X:final_poly){
            cout<< X.first << " " << X.second << endl;
        }
    }
    else cout << "0 0";

    return 0;
}
