#include <iostream>
using namespace std;
int max_area(int ar[],int size){
    int i,j,curr,res=0;
    for(i=0;i<size;i++){
        curr = ar[i];
        for(j=i-1;j>=0;j--){
            if(ar[j]>=ar[i])
            curr+= ar[i];
            else
            break;
        }
        for(j=i+1;j<size;j++){
            if(ar[j]>=ar[i])
            curr+= ar[i];
            else
            break;
        }
        res = max(res,curr);

    }
    return res;

}
int main(){
    int arr[] = {2,3,5,1,6,8,4,6,3};
    cout<<"Maximum Area: "<<max_area(arr,9)<<endl;
}