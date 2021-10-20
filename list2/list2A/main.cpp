#include <iostream>
#include <cmath>



using namespace std;

long int binary_search(long int main_array[],long int l,long int r,long int find); //? A binary search function which receives an array, its number of elements and an item to find;

int main() {

    long int number_elt, queries =0;

    cin >> number_elt; //? Number of elements in array
    cin >> queries; //? Number of queries to be made;

    long int* array = new  long int [number_elt];



    for (int i = 0; i < number_elt; ++i) { //! Populating the array;
        cin >> array[i];
    }

    long int temp;
    for (int i = 0; i < queries ; ++i) { // ! Executing the queries
        cin >> temp;
        cout<< binary_search(array,0,(number_elt-1),temp)<< '\n';
    }

    delete[] array; //? Memory Dispenser

    return 0;
}

long int binary_search(long int main_array[], long int l, long int r, long int find){
    long int m;
    if (l > r)
    {
        return -1;
    }
    else
    {
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
