#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<double, int> p1, pair<double, int> p2){
    return p1.first>p2.first;
}

double fracKnap(vector<int> val, vector<int> wt, int W){
    int n = val.size();
    vector<pair<double, int>> ratio(n, {0.0, 0});
    for(int i = 0; i<n; i++){
        double r = val[i]/(double)wt[i];
        ratio[i] = make_pair(r, i);
    }
    sort(ratio.begin(), ratio.end(), compare);
    int ans = 0; 
    for(int i = 0; i<n; i++){
        int idx = ratio[i].second;
        if(wt[idx]<=W){
            W-=wt[idx];
            ans+=val[idx];
        }
        else{
            ans+=ratio[i].first*W;
            W=0;
            break;
        }
    }
    return ans;

}

int main(){
    vector<int> value = {60, 100, 120};
    vector<int> weight = {10,20,30};
    int W = 50;
    cout<<fracKnap(value, weight, W);
}