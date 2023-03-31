#include<bits/stdc++.h>
using namespace std;
int binarysearch(int array[], int size, int target){
    int start = 0;
    int  end = size - 1;
    int mid = (start + end)/2;
    
    while(start<= end){  // 
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
    int n;cout<<"Enter the no. of element :- ";cin>>n;
    int array[n];
    cout<<"Enter the elements of array : \n";
    for(int i=0;i<n;i++){
        cin>>array[i];
    }
    sort(array, array + n);
    
    int Find;cout<<"\nEnter the element need to find:- ";cin>>Find;
    int result = binarysearch(array,n,Find);
    if (result==-1){
        cout<<"No such element is present in array :(";
    }
    else cout<<"Element is present at index : "<<result;
    
    return 0;
}