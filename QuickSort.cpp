#include <iostream>
#include <vector>
using namespace std;


int partition(int arr[], int si, int ei){
    int pvt = arr[ei];
    int i = si-1;
    for(int j = si; j<ei; j++){
        if(arr[j]<=pvt){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[ei]);
    return i+1;

}

void quickSort(int arr[], int si , int ei){
    if(si>=ei){
        return;
    }
    int pvtIdx = partition(arr, si, ei);
    quickSort(arr, si, pvtIdx-1);
    quickSort(arr, pvtIdx+1, ei);
}

int main(){
    int arr[] = {12,34,11,2,35,54,22,60,4};
    quickSort(arr, 0 , 8);
    cout<<"After sorting"<<endl;
    for(auto it : arr){
        cout<<it<<" ";
    }
}