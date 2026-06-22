#include<iostream>
#include<unordered_map>
#include<unordered_set>
using namespace std;
void itinerary(unordered_map<string,string>tickets){
    unordered_set<string> to;
    for(auto item:tickets){
        to.insert(item.second);
    }
    string start = "";
    for(auto item:tickets){
        if(to.find(item.first)==to.end()){
            start = item.first;
            break;
        }
    }
    cout<<start<<"->";
    while(tickets.count(start)!=0){
        cout<<tickets[start]<<"->";
        start = tickets[start];
    }
    cout<<"End";
}
int main(){
    unordered_map<string, string> tickets = {
    {"Chennai", "Bengaluru"},
    {"Mumbai", "Delhi"},
    {"Goa", "Chennai"},
    {"Delhi", "Goa"}
};  itinerary(tickets);
}