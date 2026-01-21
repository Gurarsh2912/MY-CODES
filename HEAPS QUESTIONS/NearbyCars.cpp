#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Car{
public:
    int idx;
    int dist;

    Car(int idx, int dist){
        this->idx = idx;
        this->dist = dist;
    }

    bool operator < (const Car& obj) const {
        return this->dist > obj.dist;
    }
};

void nearbyCar(vector<pair<int,int>> pos, int k){
    vector <Car> cars;
    for(int i=0; i<pos.size(); i++){
        int distSq = pos[i].first*pos[i].first + pos[i].second*pos[i].second;
        cars.push_back(Car(i, distSq));
    }

    priority_queue<Car> pq(cars.begin(), cars.end());

    for(int i = 0; i<k; i++){
        cout<<"Car:"<< pq.top().idx<<endl;
        pq.pop();
    }
}

int main(){
    vector<pair<int,int>> pos;
    pos.push_back(make_pair(3,3));
    pos.push_back(make_pair(5,-1));
    pos.push_back(make_pair(-2,4));

    int k = 2;

    nearbyCar(pos, k);
}