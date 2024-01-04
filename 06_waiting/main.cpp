#include <bits/stdc++.h>

using namespace std;

int N,k,
i,j,m,n,q,
waitNum;
string comeout;

int main()
{
    //freopen("input.txt","r",stdin);
    vector<vector<int>> room={{}};
    vector<int> chair={};

    cin >> N >> k;

    for(i=0;i<N;i++){
        cin >> comeout >> waitNum;
        if(comeout=="+"){

            if(room.empty()){
                chair.push_back(waitNum);
                room.push_back(chair);
                chair ={};
            }
            else{
                for(j=0;j<room.size();j++){
                    vector<int>& nowchair = room[j];
                    if(nowchair.empty()) nowchair.push_back(waitNum);
                    else if(nowchair==room.back()&&waitNum>nowchair.back()) nowchair.push_back(waitNum);
                    else if(nowchair.back() > waitNum){
                        if(nowchair.front() > waitNum && j!=0) room[j-1].push_back(waitNum);
                        else{
                            nowchair.push_back(waitNum);
                            sort(nowchair.begin(),nowchair.end());
                        }
                        break;
                    }
                }
            }
        }

        else if(comeout=="-"){

            for(auto& X:room){
                auto it = find(X.begin(),X.end(),waitNum);
                if(it!=X.end()) X.erase(it);
            }
        }

        for(n=0;n<room.size();n++){
                if(room[n].size()==0){
                    room.erase(room.begin() + n);
                    n--;
                }
                else if(room[n].size()==2*k){

                    chair.resize(k);
                    copy_n(room[n].begin()+k,k,chair.begin());
                    for(q=0;q<k;q++) room[n].pop_back();
                    room.insert(room.begin()+n+1,chair);
                    chair={};
                }
        }

    }
    //final_answer
    for(auto X:room){
        cout << X.front() << endl;
    }

    return 0;
}
