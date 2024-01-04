#include <bits/stdc++.h>

using namespace std;

int cur=1;
vector <char> charvec;
int N, startCnt, endCnt;
char mychar;

typedef struct Fraction{
	long long bunja;
	long long bunmo;
} Fraction;
stack <Fraction> st;
Fraction addFraction(Fraction a, Fraction b, Fraction c) {
    Fraction result;
    result.bunmo = a.bunmo * b.bunmo * c.bunja;
    result.bunja = a.bunja * b.bunmo * c.bunja + c.bunmo * b.bunja * a.bunmo;

    long long mygcd = __gcd(result.bunja, result.bunmo);

    result.bunja /= mygcd;
    result.bunmo /= mygcd;

    return result;
}

Fraction makeFrac(stack <Fraction> st){
    while(cur!=N){
        cur++;
        if(charvec[cur-1]=='('){

            stack <Fraction> tmpst={};
            Fraction tmp = makeFrac(tmpst);
            if(cur!=N){
                st.push(tmp);
            }
            else{
                cout << tmp.bunja << " " << tmp.bunmo;
            }
        }
        else if(charvec[cur-1]==')'){
            Fraction a,b,c;
            c = st.top();
            st.pop();
            b = st.top();
            st.pop();
            a = st.top();
            st.pop();
            return addFraction(a,b,c);
        }
        else{
            char intchar = charvec[cur-1];
            int myint = intchar - '0';
            Fraction myfrac;
            myfrac.bunja = (long long) myint;
            myfrac.bunmo = (long long) 1;
            st.push(myfrac);
        }

    }
}

int main(){

    //freopen("input.txt", "r", stdin);
    cin >> N ;
    for (int i=0; i<N; i++){
        cin >> mychar;
        if(mychar =='(') startCnt++;
        else if(mychar == ')')endCnt++;
        charvec.push_back(mychar);
    }

    if(startCnt!=endCnt)
        cout << -1;
    else{
        Fraction Final = makeFrac(st);
        if (Final.bunmo == 1) cout << Final.bunja;
        else cout << Final.bunja << " " << Final.bunmo;
    }


    return 0;
}
