//S121-Lab07-Kim-Recursion.cpp
//Author:   Toni Kim
//Goal:     

#include <iostream>
#include <vector>
using namespace std;

//function definitions-----------------------------------------------------
bool binarySearch(int key, int lo, int hi, vector<int>& list){
    //match not found (base case)
    if (lo > hi){
        return false;
    }

    //find middle element
    int mid = (lo + hi) / 2;

    //match is found
    if(key==list[mid]){
        return true;
    } 
    
    if (key < list[mid]){
        return binarySearch(key, lo, mid - 1, list); // search left half
    }else{
        return binarySearch(key, mid+1, hi, list); // search right half
    }
}


vector<int> intersect(vector<int> list1, vector<int> list2){
    vector<int> intersected;
    for (int i : list1){
        if(binarySearch(i, 0, list2.size()-1, list2)){
            intersected.push_back(i);
        }
    }
    return intersected;
}


void showVector(vector<int> v, string caption=""){
    cout<< endl << caption << endl;
    for (int i : v){
        cout<<i << "\t";
    }    
}


//MAIN------------------------------------------------------------------
int main(){
    vector<int> list1 {1, 4, 5, 6, 7, 9, 20, 21 };
    vector<int> list2 {3, 4, 5, 6, 8, 9, 11 };

    vector<int> list3 = intersect(list1, list2);

    showVector(list1, "List 1:");
    showVector(list2, "List 2:");
    showVector(list3, "Intersected List:");

}

