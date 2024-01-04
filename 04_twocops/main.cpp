
#include <iostream>

using namespace std;

int pandan(int ln_Sumarr[],int n,int geori){
    for(int i=0;i<n;i++){
        if(geori<ln_Sumarr[i]) return i-1;
        else if(geori==ln_Sumarr[i]) return i;
    }
}
int C1_change (int t, int S1, int S2){
    if(t>=0 && t<= S1/2) return t;
    else if(t>S1/2 && t<=S1) return S1-t;
    else if(t>S1 && t<=S1+S2/2) return 2*S1+S2-t;
    return t;
}
int C2_change(int t,int S1, int S2){
    if(t>=0 && t<= S1/2) return S1-t;
    else if(t>S1/2 && t<=S1+S2/2) return t;
    return 2*S1+S2-t;
}

int point[100][2], ln_Sumarr[100], idx[2], geori[2],
i,j,n,x,y ,temp,ln_Sum,S1,S2,xy,pm,sigan,idx_pm;

int main()
{
    //freopen("input.txt","r",stdin);
    cin >> n;
    for(i; i<n; i++){
        cin >> x >> y;
        point[i][0] = x;
        point[i][1] = y;
    }
    point[n][0] = point[0][0];
    point[n][1] = point[0][1];

    for(j; j<n; j++){
        temp = point[j][0]-point[j+1][0] + point[j][1]-point[j+1][1];
        if(temp<0) temp *= -1;
        ln_Sum += temp;
        ln_Sumarr[j] = ln_Sum;
    }

    S1 = ln_Sumarr[n/2-2];
    S2 = ln_Sum - S1;

    cin >> sigan;
    sigan %= ln_Sum;

    geori[0]=C1_change(sigan,S1,S2);
    geori[1]=C2_change(sigan,S1,S2);

    idx[0] = pandan(ln_Sumarr,n,geori[0]);
    idx[1] = pandan(ln_Sumarr,n,geori[1]);
    for(int m;m<2;m++){
        temp = geori[m]-ln_Sumarr[idx[m]];
        idx[m] += 1;
        idx_pm=idx[m];
        xy = point[idx_pm+1][0]!=point[idx_pm][0]? 0 : 1;
        pm = xy && point[idx_pm+1][1]>point[idx_pm][1] || point[idx_pm+1][0]>point[idx_pm][0] ? 1 : -1;

        if(xy) cout << point[idx_pm][0] << " " << point[idx_pm][xy]+pm*temp << endl;
        else cout << point[idx_pm][xy]+pm*temp << " " << point[idx_pm][1] << endl;
    }


    return 0;
}

