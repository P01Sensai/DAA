#include<bits/stdc++.h>
using namespace std;
int binarysearch(int array[], int size, int target){
    int start = 0;
    int  end = size - 1;
    int mid = (start + end)/2;
    while(start<= end){
        if(array[mid]==target){
            return mid;
        }
        if(target > array[mid] ){
            start = mid +1;
        }else {
            end = mid -1;
        }
        mid = (start+ end)/2;
    }
    return -1;
}
int main(){
    int n;cin>>n;
    int array[n];
    for(int i=0;i<n;i++){
        cin>>array[i];
    }
    int c; cin>>c;
    int sol = binarysearch(array,n,c);
    cout<<"index is "<<sol;
    return 0;
}