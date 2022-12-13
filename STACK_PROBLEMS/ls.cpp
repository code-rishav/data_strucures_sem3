#include <iostream>
#include "linear_search.h"
using namespace std;
int main(){
    Lsearch<char> l;
    cout<<"Element found at: "<<l.search('r');
}