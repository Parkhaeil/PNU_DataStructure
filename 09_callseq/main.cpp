#include <bits/stdc++.h>
using namespace std;

int N, k1, k2, i;
char name;
string word;
vector<vector <string>> funcs;
vector<string> func;
vector<char> funcname;
map<char, bool> running;
bool check;

vector <string> callseq(vector<vector<string>> funcs, vector<char> funcname, stack<string> calstack, vector<string> solVec, char name, int N) {
    if (check == 1 || running[name]) {check = 1; return solVec;}
    else running[name] = true;
    int j;
    for (j = 0; j < N; j++){
        if (funcname[j] == name) break;
    }

    string last;
    for (string wordf : funcs[j]){
        if (isupper(wordf[0])) {
            calstack.push(wordf);
            solVec = callseq(funcs, funcname, calstack, solVec, wordf[0], N);
        }
        else {
            solVec.push_back(string(1,name) + "-" + wordf);
        }

        if (wordf == funcs[j].back()) calstack.pop();
    }
    running[name] = false;
    return solVec;
}

int main() {
    cin >> N >> k1 >> k2;

    for (i = 0; i < N; i++){
        cin >> name;
        funcname.push_back(name);
        running[name] = false;
        while (true) {
            cin >> word;
            if (word == "$") break;
            func.push_back(word);
        }
        funcs.push_back(func);
        func = {};
    }
    stack<string> calstack;
    calstack.push("M");
    vector<string> solVec;
    solVec = callseq(funcs, funcname, calstack, solVec, 'M', N);

    if (check == 1) {cout << "DEADLOCK"; return 0;}

    for (int k : {k1, k2}) {
        if (abs(k) > solVec.size())
            cout << "NONE" << endl;
        else if (k < 0) {
            k = solVec.size()+k;
            cout << solVec[k] << endl;
        }
        else cout << solVec[k-1] << endl;
    }
    return 0;
}
