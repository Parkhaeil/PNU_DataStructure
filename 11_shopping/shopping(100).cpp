#include <bits/stdc++.h>
#define rep(i, N) for(int i=0;i<(int)(N);i++)
using namespace std;
vector<pair<int,int>> inputVec;
vector<pair<int,int>> paybox;
int N,k,num,wi,idx,cnt;
int main()
{
    //freopen("input.txt","r",stdin);
    cin>>N>>k;
    if(N<k) k=N;
    rep(i,N){
        cin >> num >> wi;
        inputVec.push_back(make_pair(num,wi));
    }
    rep(j,k){
        paybox.push_back(inputVec[j]);
    }
    idx=k;

    while(cnt!=N){
        while(1){
            int bl=0;
            for(auto &x:paybox){
                if(x.first!=0&&x.second!=0){
                    x.second -=1;
                    if(x.second==0)bl=1;
                }
            }
            if(bl==1) break;
        }
        for(auto it=paybox.rbegin();it!=paybox.rend();it++){
            if(it->first!=0&&it->second==0){
                cout << it->first<<endl;
                cnt++;
                it->first = 0;
            }
        }
        for(auto it=paybox.begin();it!=paybox.end();it++){
            if(it->first==0 && idx != N){
                it->first = inputVec[idx].first;
                it->second = inputVec[idx].second;
                idx++;
            }


        }

    }



    return 0;
}
