#include <iostream>
#include <stack>
using namespace std;

class Matrix{
    int **arr;
    int row,column;

    public:

    Matrix(){
        cout<<"Enter the row: ";
        cin>>row;
        cout<<"Enter the column: ";
        cin>>column;
        cout<<"Enter the matrix: "<<endl;
        arr = new int*[row];
        for(int i=0;i<row;i++)
        arr[i] = new int[column];
        for(int i=0;i<row;i++){
            for(int j=0;j<column;j++){
                cin>>arr[i][j];
            }
        }
    }

     void check(){
        cout<<"in"<<endl;
        int i,j,temp,result=0;
        result = max_area(arr[0],column);
        for(i=1;i<row;i++){
            for(j=0;j<column;j++){
                if(arr[i][j]!=0)
                arr[i][j] += arr[i-1][j];
                temp = max_area(arr[i],column);
                result = max(result,temp);
            }
        }
        cout<<"The maximum area of the matrix is : "<<result<<endl;
    }
     int max_area(int ar[],int n){
        int i,tp,curr,res=0;
        stack <int> s;
        for(i=0;i<n;i++){
            while(!s.empty() && (ar[s.top()]>=ar[i])){
                tp = s.top();s.pop();
                curr = ar[tp]* (s.empty()? i: (i-s.top()-1));
                res = max(res,curr);
            }
            s.push(i);
        }

        while(!s.empty()){
            tp = s.top();s.pop();
            curr = ar[tp] * (s.empty()? n:(n-s.top()-1));
            res  = max (res,curr);
        }
        return res;
    }
};

int main(){
    Matrix m;
    m.check();
}