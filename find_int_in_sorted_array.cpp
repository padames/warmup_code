#include <iostream>
#include <sys/resource.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <algorithm>
#include <vector>

using namespace std;

bool exists(int *ints, int size, int k){
    if (size <= 0) {
        cout << " =========END size==0 ========" << endl << endl; 
        return false;
    }
    cout << " ======= Entering \"exists\" =======" << endl;
    cout << "size = " << size << endl;
 

    int size_left = size/2;

    if ( size_left == 0 ) {
        cout << " Found size_left == 0" << endl;
        cout << " *ints == k ?? ==> " << *ints <<  " == " << k << "? ==> " << boolalpha << "" << (*ints == k) << endl;
        cout << " =========The End========" << endl << endl; 
        bool result = (*ints == k)? true: false;
        return result;
    }
    
    if ( ints[size_left -1] > k ) {
        cout << "ints[size_left - 1] > k ==> " << ints[size_left-1] << " > " << k << endl;
        return exists( ints, size_left, k); 
    } else {
        cout << "ints[size_left - 1] <= k ==> " << ints[size_left-1] << " >= " << k << endl;
        return exists( ints + size_left, size - size_left, k);
    }
    // int *end_left = ints + size_left;
    // int *begin_left = ints;

    // cout << " ======= First left =======" << endl;
    
    // cout << " size_left = " << size_left << endl;
    // cout << " begin_left = " << begin_left << endl;
    // cout << " end_left = " << end_left << endl;

    // if (end_left == std::find(begin_left, end_left, k)) {
    //     auto begin_right = end_left;
    //     auto end_right = begin_left + size;
    //     int size_right = end_right - begin_right;

    //     cout << " ======= Now right =======" << endl;
    //     cout << " size_right = " << size_right << endl;
    //     cout << " begin_right = " << begin_right << endl;
    //     cout << " end_right = " << end_right << endl;

    //     return exists( begin_right, size_right, k);
    // }
    // else {
    //     return true;
    // }
    // cout << " =========END bad========" << endl << endl; 
    // return false;
}

int main() {
    int ints[] = {-9, 14, 37, 46, 102};
    cout << std::boolalpha << exists(ints, 5, 102) << endl;
    cout << std::boolalpha << exists(ints, 5, 36) << endl;
}