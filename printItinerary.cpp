#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

void printItinerary(unordered_map<string,string> map){
    unordered_set <string> to;
    string start;

    for(pair<string,string> m : map){
        to.insert(m.second);
    }
    for(pair<string,string> m : map){
        if(to.find(m.first)==to.end()){
            start = m.first;
        }
    }
    cout<<start<<"->";

    while(map.count(start)){
        cout<<map[start]<<"->";
        start = map[start];
    }
    
}

int main(){
    unordered_map <string,string> tickets;
    tickets["Chennai"] = "Bengaluru";
    tickets["Mumbai"] = "Delhi";
    tickets["Goa"] = "Chennai";
    tickets["Delhi"] = "Goa";
    
    printItinerary(tickets);
    
}