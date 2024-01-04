#include <bits/stdc++.h>

using namespace std;

int N,K,pi,i,j;
stack<int> onebon;
stack<int> nowst;
stack<int> ans;
int cur=1,bl=0;

void stackSort( stack<int>&s1 ){
    stack<int> s2;
    while(!s1.empty()){
        int tmp = s1.top();
        s1.pop();
        while(!s2.empty()&&s2.top()>tmp){
            s1.push(s2.top());
            s2.pop();
        }
        s2.push(tmp);
    }
    s1=s2;
}

void func (stack<int> onebon, stack<int> nowst, int cur, int tot){
    if(cur == N){
        if(tot == K){
            ans = nowst;
        }
        return;
    }
    int tmp=onebon.top();
    onebon.pop();
    func (onebon, nowst, cur+1, tot);

    nowst.push(tmp);
    func (onebon, nowst, cur+1, tot+tmp);
}
int main()
{
    //freopen("input.txt","r",stdin);
    cin >> N >> K;
    for(i=0;i<N;i++){
        cin >> pi;
        onebon.push(pi);
    }
    stackSort(onebon);
    func(onebon,nowst,0,0);

    if (!ans.empty()) {
        while (!ans.empty()) {
            cout << ans.top() << endl;
            ans.pop();
        }
    } else {
        cout << "0";
    }




    return 0;
}
