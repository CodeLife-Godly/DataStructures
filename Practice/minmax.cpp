#include <bits/stdc++.h>
using namespace std;

int get_min(int a,int b){
    int min = (a<b) ? a:b;
    return min;
}
int get_max(int a,int b){
    int max = (a>b) ? a:b;
    return max;
}
void min_max(vector<int>& v){
    if(v.size()>2){
        int min = get_min(v[0],v[1]);
        int max = get_max(v[0],v[1]);
        for(int i=2;i<v.size();i+=2){
            if(i+1<v.size()){
            int temp_min = get_min(v[i],v[i+1]);
            int temp_max = get_max(v[i],v[i+1]);

            min = get_min(temp_min,min);
            max = get_max(temp_max,max);
         }
            else{
                min = get_min(min,v[i]);
                max = get_max(max,v[i]);
            }
        }
        cout << "Minimum is:" << min << endl;
        cout << "Maximum is:" << max << endl;
    }
    else if(v.size()==2){
        int min = get_min(v[0],v[1]);
        int max = get_max(v[0],v[1]);

        cout << "Minimum is:" << min << endl;
        cout << "Maximum is:" << max << endl;
    }
    else{
        cout << "Minimum and Maximum is:" << v[0];
    }    
}

int main(){
    int size;
    cout << "Enter the size of array:";
    cin >> size;
    vector<int> v(size);
    cout << "Enter the details of array:" << endl;
    for(int i=0;i<v.size();++i){
        cin >> v[i];
    }
    cout << "Finding the min-max in array:" << endl;
    min_max(v);
    return 0;
}