#include <bits/stdc++.h>
#define RemoveFirst(container) if (!container.empty()) container.erase(container.begin())

using namespace std;

struct mystruct {
    string T;
    char G;
    int B;
    double S;
    int D;

} myelement ;

bool mysort(const mystruct &a, const mystruct &b) {
    if(a.B==b.B){
        if(a.D==b.D){
            return a.S < b.S;
        }
        return a.D > b.D;
    }
    return a.B > b.B;
}

int N,k,i,j,m;
vector<mystruct> mysong;
void AddIfNotExists(vector<string>vec, string value) {
    // ���� ������ value�� ã��
    auto it = find(vec.begin(), vec.end(), value);

    // ���� value�� ã�� ���ϸ� ���Ϳ� �߰�
    if (it == vec.end()) {
        vec.push_back(value);
    }
}

int main()
{
    freopen("input.txt","r",stdin);
    cin >> N >> k;

    for(i;i<N;i++){
    cin >>  myelement.T >> myelement.G >> myelement.B >> myelement.S >> myelement.D;
    mysong.push_back(myelement);
    }

    sort( mysong.begin( ), mysong.end( ), mysort );



    for(int i;i<N-1;i++){
        if(mysong[i].G == mysong[i+1].G){
            for(int j=i+2;j<N;j++){
                if(mysong[i].G != mysong[j].G){
                    mysong.pop(mysong[j]);
                    mysong.insert(i+1,mysong[j]);
                    mysong.pop(mysong[j]);         }

            }
        }

    }

    for(auto x: sort_name){
        cout << x << endl;
    }
    return 0;
}
