cd 
#include <bits/stdc++.h>;
using namespace std;


class SgTree{
     
     vector<int> seg;


    public:
    SgTree(int n){
          seg.resize(4*n+1);
    }

void build(int idx,int low,int high,int arr[]){

    if(low==high){
        seg[idx] = arr[low];
        return;
    }
    

    int mid = (low+high)/2;
    build(2*idx+1,low,mid,arr);
    build(2*idx+2,mid+1,high,arr);

    seg[idx] = min(seg[2*idx+1],seg[2*idx+2]);

    return;
}


int query (int i,int low,int high,int l,int r){
    //no overlap low high l r or l r low high 
    if(high < l || r<low){
     return INT_MAX;
    }
 
    // complete overlap l low high r
    else if(low>=l && high<=r){
        return seg[i];
    }

    
    // partial overlap
    else{
        int mid = (low+high)/2;
        int left = query(2*i+1,low,mid,l,r);
        int right = query(2*i+2,mid+1,high,l,r);
        return min(left,right);

    }

}   

void update(int i, int val,int idx,int low,int high,int arr[]){

    if(low==high){
        arr[i] = val;
        seg[idx] = val;
        return; 
    }


    int mid = (low+high)/2;
    
    if(i<=mid){
         update(i,val,2*idx+1,low,mid,arr);
    }
    else{
         update(i,val,2*idx+2,mid+1,high,arr);
    }
 
    seg[idx] = min(seg[2*i+1],seg[2*i+2]);

    return;
}


   

    

};



int main() {
	
    int n;

    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<int> seg(4 * n);

    SgTree sg1(n);

    sg1.build(0, 0, n - 1, arr);

    int q;
    cin>>q;
    

    while(q-->0){
      int l,r;
      cin>>l>>r;

      cout<<sg1.query(0,0,n-1,l,r)<<endl;
    }


    int idx,val;
    cin>>idx>>val;
    
    sg1.update(2,6,0,0,n-1,arr);

   


    // for(auto val:seg){
    //     cout<<val<<" ";
    // }

    // cout<<endl;

   





    return 0;

}
