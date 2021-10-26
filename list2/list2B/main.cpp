#include <bits/stdc++.h>
using namespace std;


void merger(long int main_array[], long int low, long int mid,long int high){
    long int i, j, k;
    long int left[mid-low+1]; //? Sub-array for elements in the left;
    long int right[high-mid]; //? Sub-array for elements in the right;
    for (long int b = 0; b < mid-low+1 ; ++b) { //! Copying elements to left sub-array;
        left[b] = main_array[low + b];
    }
    for (long int l = 0; l < high-mid ; ++l) { //! Copying elements to right sub-array
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

void merge_sort(long int main_array[], long int low, long int high){
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

    long int bars, coupons;

    cin >> bars;

    long int* choc_bars = new long int[bars];

    for (int i = 0; i < bars ; ++i) { //! Input receiver;
        cin >> choc_bars[i];
    }
    merge_sort(choc_bars,0,(bars-1)); //? Sorting the array;

    cin >> coupons;
    long int* coupons_array = new long int[coupons];

    for (int i = 0; i < coupons ; ++i) { //! Input Receiver;
        cin >> coupons_array[i];
    }



    for (int i = 0; i < coupons ; ++i) {
        long int temp = 0,temp_val = 0, total_val = 0;

        temp = coupons_array[i]; //? Selecting the coupon;

        for (long int j = bars; j > 0; --j) {
            if(j != (bars-temp+1)) {
                temp_val += choc_bars[j-1];
            }
        }

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