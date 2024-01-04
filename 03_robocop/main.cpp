#include <bits/stdc++.h>

using namespace std;

int
point[100][2], sec, line[100],sol_pnt[6][2],ln_Sumarr[100],
x,y,n,  i,j,k,l,m,
sigan,temp,ln_Sum,idx;

int get_stript(int a[],int n,int sec){
    for(int i;i<n;i++){
        if(sec<a[i]){
            return i-1;
        }
        else if(sec==a[i])
            return i;
    }
}

int dir_xy(int point[][2],int idx){
    if(point[idx+1][0]!=point[idx][0]) return 0;
    else return 1;
}
int dir_pm(int xy,int point[][2],int idx){
    if(xy){
        if(point[idx+1][1]>point[idx][1]) return 1;
        return -1;
    }
    else {
        if(point[idx+1][0]>point[idx][0]) return 1;
        return -1;
    }
}
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

    for(k; k<5;k++){
        cin >> sigan;
        sec= sigan % ln_Sum;
        idx = get_stript(ln_Sumarr,n,sec);
        temp = sec-ln_Sumarr[idx];
        idx += 1; //point index = (ln_Sumarr index) + 1

        int xy = dir_xy(point,idx);
        int pm = dir_pm(xy,point,idx);

        if(xy) cout << point[idx][0] << " " << point[idx][xy]+pm*temp << endl;
        else cout << point[idx][xy]+pm*temp << " " << point[idx][1] << endl;
        }

    return 0;
}


