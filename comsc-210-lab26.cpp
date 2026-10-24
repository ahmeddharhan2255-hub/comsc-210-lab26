// COMSC-210 | Lab 26 | Ahmad Dharhan

#include <iostream>
#include <chrono>
#include <fstream>
#include <vector>
#include <set>
#include <list>
#include <algorithm>
#include <iterator>
using namespace std;
using namespace std::chrono;

void reading(vector<string>& vec1, list<string>& list1, set<string>& set1, ifstream& file);
void sorting(vector<string> vec1, list<string> list1);
void inserting(vector<string> vec1, list<string> list1, set<string> set1);
void deleting(vector<string> vec1, list<string> list1, set<string> set1);

int main() {

    int SIZE = 15;

    //Slice 0 represents results of that run
    //Slice 1 represents accumulated results
    //Rows represent in order: Reading, Sorting
    //inserting, and deleting
    //Columns represent Vector, List, and Set
    int arr[2][4][3] = {};

    vector<string> vec1;
    list<string> list1;
    set<string> set1;

    ifstream file("names.txt");

    if(!file.is_open()){
        cout << "File could not be opened! Try Again!" << endl;
        return 1;
    }

    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < 4; j++){
            for(int k = 0; k < 3; k++){

            }
        }    
    }

    

    return 0;
}

void reading(vector<string>& vec1, list<string>& list1, set<string>& set1, ifstream& file){
    cout << "Reading";
    string code;

    auto start = high_resolution_clock::now();

    while(file >> code){
        vec1.push_back(code);
    }

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(end-start);
    cout << "\t\t" << duration.count();

    file.clear();
    file.seekg(0);

    auto start1 = high_resolution_clock::now();

    while(file >> code){
        list1.push_back(code);
    }

    auto end1 = high_resolution_clock::now();
    auto duration1 = duration_cast<nanoseconds>(end1-start1);
    cout << "\t\t" << duration1.count();

    file.clear();
    file.seekg(0);

    auto start2 = high_resolution_clock::now();

    while(file >> code){
        set1.insert(code);
    }

    auto end2 = high_resolution_clock::now();
    auto duration2 = duration_cast<nanoseconds>(end2-start2);
    cout << "\t\t"<< duration2.count();
    
    cout << endl;
}

void sorting(vector<string> vec1, list<string> list1){
    cout << "Sorting";
    auto start1 = high_resolution_clock::now();

    sort(vec1.begin(),vec1.end());

    auto end1 = high_resolution_clock::now();
    auto duration1 = duration_cast<nanoseconds>(end1-start1);
    cout << "\t\t" << duration1.count();

    auto start = high_resolution_clock::now();

    list1.sort();

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(end-start);
    cout << "\t" << duration.count();

    cout << "\t\t" << -1;
    cout << endl;
}

void inserting(vector<string> vec1, list<string> list1, set<string> set1){
    cout << "Inserting";
    auto start = high_resolution_clock::now();

    vec1.insert(vec1.begin() + vec1.size()/2,"TESTCODE");

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(end-start);
    cout << "\t" << duration.count();

    auto it = list1.begin();
    advance(it,list1.size()/2);
    auto start1 = high_resolution_clock::now();

    list1.insert(it,"TESTCODE");

    auto end1 = high_resolution_clock::now();
    auto duration1 = duration_cast<nanoseconds>(end1-start1);
    cout << "\t\t" << duration1.count();

    auto start2 = high_resolution_clock::now();

    set1.insert("TESTCODE");

    auto end2 = high_resolution_clock::now();
    auto duration2 = duration_cast<nanoseconds>(end2-start2);
    cout << "\t\t"<< duration2.count();
    
    cout << endl;
}

void deleting(vector<string> vec1, list<string> list1, set<string> set1){
    cout <<"Deleting";
    auto it = list1.begin();
    advance(it,list1.size()/2);

    auto it2 = set1.begin();
    advance(it2,set1.size()/2);

    auto it3 = vec1.begin() + vec1.size()/2;

    auto start = high_resolution_clock::now();

    vec1.erase(it3);

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(end-start);
    cout << "\t" << duration.count();

    auto start1 = high_resolution_clock::now();

    list1.erase(it);

    auto end1 = high_resolution_clock::now();
    auto duration1 = duration_cast<nanoseconds>(end1-start1);
    cout << "\t\t" << duration1.count();

    auto start2 = high_resolution_clock::now();

    set1.erase(it2);

    auto end2 = high_resolution_clock::now();
    auto duration2 = duration_cast<nanoseconds>(end2-start2);
    cout << "\t\t"<< duration2.count();
    
    cout << endl;

}