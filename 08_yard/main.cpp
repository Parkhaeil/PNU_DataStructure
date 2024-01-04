#include <bits/stdc++.h>
///top을 쓸때는 empty를 조심하라.
using namespace std;
int i,j,
N,si,id,maxval,height=999;
vector<stack<int>> yard;
vector<stack<int>> solYard;
stack<int> jul;

bool cmpMax (stack<int> jul1, stack<int> jul2){
    if( jul1.size()==jul2.size() && jul2.size()!=0) return jul1.top() < jul2.top();
    else return jul1.size() <= jul2.size();
}

bool cmpMin (stack<int> jul1, stack<int> jul2){
    return jul1.size() <= jul2.size();
}

int main()
{
    //freopen("input.txt","r",stdin);

    cin >> N;
    for(i=0;i<N;i++){
        cin >> si;
        for(j=0;j<si;j++){
            cin >> id;
            jul.push(id);
        }
        yard.push_back(jul);
        jul = {};
    }

    while(1){
        auto maxStack = max_element(yard.begin(), yard.end(), cmpMax);
        auto minStack = min_element(yard.begin(), yard.end(), cmpMin);

        height = yard[maxStack-yard.begin()].size() - yard[minStack-yard.begin()].size();
        if(height<=1) break;

        maxval = maxStack->top();
        yard[minStack-yard.begin()].push(maxval);
        yard[maxStack-yard.begin()].pop();
    }

    for(auto X:yard){
        while (!X.empty()){
            jul.push(X.top());
            X.pop();
        }
        solYard.push_back(jul);
        jul = {};
    }

    for(auto X:solYard){
        if(X.empty()) cout << 0;
        while(!X.empty()){
            cout << X.top() << " ";
            X.pop();
        }
        cout << endl;
    }
    return 0;
}
