#include <iostream>
#include "console.h"
#include "lexicon.h"
#include <vector>
#include <random.h>
#include<iterator>
using namespace std;

 int findmedian(vector<int> &vec, int begin, int mid, vector<int>::iterator end);

 int main() {

    vector<int> vc {2,36,5,21,8,13,11,20,5,4,1};
    int mid= (vc.size()%2==0)? vc.size()/2: (vc.size()-1)/2;
    int t=findmedian(vc, 0, mid, vc.end());
    cout << t;
    return 0;
}

 int findmedian(vector<int> &vec, int begin, int mid, vector<int>::iterator end){
     if (vec.size()==1){
         int median=vec[0];
         return median;
     }

     vector<int>::iterator ptr;
     int pow=0;
     int random_n=randomInteger(begin,(vec.size()-1)-pow);
     int v=vec[random_n];
     end=vec.end();
     int count=0;
     int temp=0;
     for (ptr=vec.begin()+begin; ptr!=end; ++ptr) {
        if (*ptr<v) {
            temp=*ptr;
            vec.erase(ptr);
            vec.emplace(vec.begin(),temp);
         } else if (*ptr>v) {
             count++;
             temp=*ptr;
             vec.erase(ptr);
             vec.emplace(vec.end(),temp);
         }
 }

     pow=vec.size() - count;
     begin=pow;
     if (pow < mid){
        return findmedian(vec,pow,mid,end);
    } else if (pow == mid) {return vec[mid];
    } else {
        return findmedian (vec,0, mid, end-pow);
    }

 }
