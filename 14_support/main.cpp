#include <bits/stdc++.h>

using namespace std;

struct Guest {
    int arriveTime;
    int id;
    int consultTime;
};
struct cmp {
    bool operator()(const Guest & a, const Guest & b) {
        if(a.consultTime==b.consultTime) {
            return a.arriveTime > b.arriveTime;
        } else {
            return a.consultTime < b.consultTime;
        }
    }
};



priority_queue < Guest , vector<Guest>, cmp > Room ;
vector <Guest> personList;

int N, whoaT,whoid, whocT, i, t;

void pickup(){
    while(true){
        if(!personList.empty()&&personList.back().arriveTime <= t){
            Room.push(personList.back());
            personList.pop_back();
        } else
            break;
    }
}

int main()
{
    //freopen("input.txt","r",stdin);
    cin >> N;
    for(i=0;i<N;i++){
        cin >> whoaT >> whoid >> whocT;
        Guest who;
        who.arriveTime = whoaT;
        who.id = whoid;
        who.consultTime = whocT;
        personList.push_back(who);
    }
    reverse(personList.begin(),personList.end());
//    for(auto w : personList){
//        cout << w.arriveTime <<" "<<w.id<<" "<<w.consultTime<<endl;
//    }

    t=30;//reset
    pickup();


//    while ( !Room.empty() ) {
//        cout << "½ÃÀÛÀü: "<<Room.top().arriveTime <<" "<< Room.top().id<<" "<<Room.top().consultTime<<endl;
//        Room.pop();
//    }

    while(true){
        if(!Room.empty()){

            Guest visit = Room.top();
            if(visit.consultTime > 10){
                Room.pop();
                t+=visit.consultTime/2;
                visit.arriveTime=t;
                visit.consultTime-=visit.consultTime/2;
                Room.push(visit);
            }
            else{
                t += visit.consultTime;
                cout << visit.id << endl;
                Room.pop();
            }
            pickup();
        }
        else{
            if(!personList.empty()){
                Room.push(personList.back());
                t=personList.back().arriveTime;
                personList.pop_back();
            }
            else break;

        }

    }
    return 0;
}
