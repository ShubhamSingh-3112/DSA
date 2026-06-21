#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Car{
    public:
    int idx;
    int x,y;
    int distSq;
    Car(int idx,int x,int y){
        this->idx = idx;
        this->x = x;
        this->y = y;
        this->distSq = (x*x) + (y*y);
    }
    bool operator < (const Car&obj) const{
        return this->distSq > obj.distSq;
    }
};

void nearbyCars(vector<pair<int,int>> &positions,int k){
    vector<Car> cars;
    for(int i=0;i<positions.size();i++){
        cars.push_back(Car(i,positions[i].first,positions[i].second));
    }
    priority_queue<Car> p(cars.begin(),cars.end());
    for(int i=0;i<k;i++){
        cout<<p.top().idx<<endl;
        p.pop();
    }
}

int main(){
    vector<pair<int,int>> positions;
    positions.push_back(make_pair(3,3));
    positions.push_back(make_pair(5,-1));
    positions.push_back(make_pair(-2,4));
    nearbyCars(positions,2);
}