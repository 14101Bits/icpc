#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool canChoose(const vector<pair<ll,ll>> & segs, int K, ll x){
    int cnt = 0;
    ll lastR = -1e18;

    for(auto[L,R] : segs){
        if(L-lastR >=x){
        cnt++;
        lastR =R;}
    if(cnt >= K){return true;}
    }
return false;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N,K;
    cin>>N>>K;
   vector<pair<ll,ll>> segs(N);
    for(int i = 0; i < N; i++){
ll L,R;
cin>>L>>R;
segs[i] = make_pair(L,R);

}
sort(segs.begin(), segs.end(),[](auto a,auto b){
if(a.second != b.second){return a.second < b.second;}
return a.first < b.first;
});
if(!canChoose(segs, K, 1)){
cout<<-1<<endl;
return 0;
}
ll ok =1;
ll ng = 1e18;
while(ng-ok>1){
ll mid = (ok+ng)/2;
if(canChoose(segs, K, mid)) ok = mid;
else ng = mid;
}
cout<<ok<<endl;
    return 0;

}