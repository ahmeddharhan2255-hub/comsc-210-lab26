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

//Function prototypes
void reading(vector<string>& vec1, list<string>& list1, set<string>& set1, ifstream& file,int arr[4][3]);
void sorting(vector<string> vec1, list<string> list1,int arr[4][3]);
void inserting(vector<string> vec1, list<string> list1, set<string> set1,int arr[4][3]);
void deleting(vector<string> vec1, list<string> list1, set<string> set1,int arr[4][3]);

int main() {

    int SIZE = 15;
    int COLS = 3;
    int ROWS = 4;

    //Slice 0 represents results of that run
    //Slice 1 represents accumulated results
    //Rows represent in order: Reading, Sorting
    //inserting, and deleting
    //Columns represent Vector, List, and Set
    int arr[2][4][3] = {};

    for(int i = 0; i < SIZE; i++){

        vector<string> vec1;
        list<string> list1;
        set<string> set1;

        ifstream file("names.txt");

        if(!file.is_open()){
            cout << "File could not be opened! Try Again!" << endl;
        return 1;
        }

        //Gather data for current experiment
        reading(vec1, list1, set1, file,arr[0]);
        sorting(vec1, list1,arr[0]);
        inserting(vec1, list1, set1,arr[0]);
        deleting(vec1, list1, set1,arr[0]);

        //Add data to cumulative
        for(int j = 0; j < ROWS; j++){
            for(int k = 0; k < COLS; k++){
                if(arr[0][j][k] != -1){
                    arr[1][j][k] += arr[0][j][k];
                  
                }
            }
        }
    }

    //Finding Average
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS; j++){
            arr[1][i][j] /= SIZE;
        }
    }

    //Data Output
    cout << "Number of simulations: " << SIZE << endl;

    cout << "Operation\tVector\t\tList\t\tSet" << endl;;

    cout << "Read";
    for(int i = 0; i < COLS; i++){
        cout << "\t\t" << arr[1][0][i];
    }
    cout << endl;

    cout << "Sort";
    for(int i = 0; i < COLS; i++){
        cout << "          " << arr[1][1][i];
    }
    cout << endl;

    cout << "Insert";
    for(int i = 0; i < COLS; i++){
        cout << "\t\t" << arr[1][2][i];
    }
    cout << endl;

    cout << "Delete";
    for(int i = 0; i < COLS; i++){
        cout << "\t\t" << arr[1][3][i];
    }
    return 0;
}

void reading(vector<string>& vec1, list<string>& list1, set<string>& set1, ifstream& file,int arr[4][3]){
    string code;

    auto start = high_resolution_clock::now();

    while(file >> code){
        vec1.push_back(code);
    }

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(end-start);
    arr[0][0] = duration.count();

    file.clear();
    file.seekg(0);

    auto start1 = high_resolution_clock::now();

    while(file >> code){
        list1.push_back(code);
    }

    auto end1 = high_resolution_clock::now();
    auto duration1 = duration_cast<nanoseconds>(end1-start1);
    arr[0][1] = duration1.count();

    file.clear();
    file.seekg(0);

    auto start2 = high_resolution_clock::now();

    while(file >> code){
        set1.insert(code);
    }

    auto end2 = high_resolution_clock::now();
    auto duration2 = duration_cast<nanoseconds>(end2-start2);
    arr[0][2] = duration2.count();
    
}

void sorting(vector<string> vec1, list<string> list1,int arr[4][3]){
    auto start1 = high_resolution_clock::now();

    sort(vec1.begin(),vec1.end());

    auto end1 = high_resolution_clock::now();
    auto duration1 = duration_cast<nanoseconds>(end1-start1);
    arr[1][0] = duration1.count();

    auto start = high_resolution_clock::now();

    list1.sort();

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(end-start);
    arr[1][1] = duration.count();

    arr[1][2] = -1;
    
}

void inserting(vector<string> vec1, list<string> list1, set<string> set1,int arr[4][3]){
    auto start = high_resolution_clock::now();

    vec1.insert(vec1.begin() + vec1.size()/2,"TESTCODE");

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(end-start);
    arr[2][0] = duration.count();

    auto it = list1.begin();
    advance(it,list1.size()/2);
    auto start1 = high_resolution_clock::now();

    list1.insert(it,"TESTCODE");

    auto end1 = high_resolution_clock::now();
    auto duration1 = duration_cast<nanoseconds>(end1-start1);
    arr[2][1]= duration1.count();

    auto start2 = high_resolution_clock::now();

    set1.insert("TESTCODE");

    auto end2 = high_resolution_clock::now();
    auto duration2 = duration_cast<nanoseconds>(end2-start2);
    arr[2][2] = duration2.count();

}

void deleting(vector<string> vec1, list<string> list1, set<string> set1,int arr[4][3]){
    auto it = list1.begin();
    advance(it,list1.size()/2);

    auto it2 = set1.begin();
    advance(it2,set1.size()/2);

    auto it3 = vec1.begin() + vec1.size()/2;

    auto start = high_resolution_clock::now();

    vec1.erase(it3);

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(end-start);
    arr[3][0] = duration.count();

    auto start1 = high_resolution_clock::now();

    list1.erase(it);

    auto end1 = high_resolution_clock::now();
    auto duration1 = duration_cast<nanoseconds>(end1-start1);
    arr[3][1] = duration1.count();

    auto start2 = high_resolution_clock::now();

    set1.erase(it2);

    auto end2 = high_resolution_clock::now();
    auto duration2 = duration_cast<nanoseconds>(end2-start2);
    arr[3][2] = duration2.count();

}

