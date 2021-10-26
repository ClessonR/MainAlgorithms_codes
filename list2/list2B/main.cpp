#include <bits/stdc++.h>
using namespace std;


void merger(long long int main_array[], long long int low, long long int mid,long long int high){
    long long int i, j, k;
    long long int left[mid-low+1]; //? Sub-array for elements in the left;
    long long int right[high-mid]; //? Sub-array for elements in the right;
    for (long long int b = 0; b < mid-low+1 ; ++b) { //! Copying elements to left sub-array;
        left[b] = main_array[low + b];
    }
    for (long long int l = 0; l < high-mid ; ++l) { //! Copying elements to right sub-array
        right[l] = main_array[mid + 1 +l];
    }
    i=0;
    j=0;
    k=low;
    for (k = low; i < mid - low + 1 && j < high - mid; ++k) {
        if(left[i] <= right[j]) main_array[k] = left[i++];
        else main_array[k] = right[j++];
    }
    while (i < mid - low + 1){
        main_array[k++] = left[i++];
    }
    while (j < high-mid){
        main_array[k++] = right[j++];
    }

}

void merge_sort(long long int main_array[], long long int low, long long int high){
    if(low>=high){
        return;}
    merge_sort(main_array, low,(high+low)/2);
    merge_sort(main_array,((high+low)/2)+1,high);
    merger(main_array,low,((high+low)/2),high);
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long int bars, coupons;

    cin >> bars;

    long long int* choc_bars = new long long int[bars];

    for (long long int i = 0; i < bars ; ++i) { //! Input receiver;
        cin >> choc_bars[i];
    }
    merge_sort(choc_bars,0,(bars-1)); //? Sorting the array;

    cin >> coupons;
    long long int* coupons_array = new long long int[coupons];

    for (long long int i = 0; i < coupons ; ++i) { //! Input Receiver;
        cin >> coupons_array[i];
    }

    long long int total_val = 0;
    for (long long int i = 0; i <bars ; ++i) {
        total_val += choc_bars[i];
    }

    for (long int i = 0; i < coupons ; ++i) {
        long long int temp_val = 0, temp = 0;

        temp = coupons_array[i]; //? Selecting the coupon;

        temp_val = total_val - choc_bars[bars-temp];

        if(i!=coupons-1) {
            cout << temp_val << "\n";
        }
        else{
            cout << temp_val;
        }

    }

    //! Memory Dispensers;
    delete [] choc_bars;
    delete [] coupons_array;




    return 0;
}