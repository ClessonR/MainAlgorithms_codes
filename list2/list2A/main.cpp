#include <iostream>
#include <cmath>

using namespace std;

long long int binary_search(long long int *main_array, long long int l, long long int r, long long int find); //? A binary search function which receives an array, its number of elements and an item to find;

int main() {

    int number_elt, queries =0;

    cin >> number_elt; //? Number of elements in array
    cin >> queries; //? Number of queries to be made;

    long long int * array = new long long int [number_elt];


    long long int temp;
    for (int i = 0; i < number_elt; ++i) { //! Populating the array;
        cin >> temp;
        array[i] = temp;
    }

    for (int i = 0; i < queries ; ++i) { // ! Executing the queries
        cin >> temp;
        cout<< binary_search(array,0,(number_elt-1),temp)<< endl;
    }

    delete[] array; //? Memory Dispenser

    return 0;
}

long long int binary_search(long long int *main_array, long long int l, long long int r, long long int find){
    long long int m;
    if (l > r){
        return -1;
    }
    else{
        m = floor((l + r)/2);

        if(main_array[m] == find){
            return m;
        }
        else if(find > main_array[m]){
            binary_search(main_array, m+1, r, find);
        }
        else if(find < main_array[m]){
            binary_search(main_array, l, m-1, find);
        }
    }
}