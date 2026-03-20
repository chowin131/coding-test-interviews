#include <bits/stdc++.h>
using namespace std;
int n;
int bt(int depth,int arr[21][21]);
int U(int depth,int arr[21][21]){
    int new_arr[21][21]={0};
    bool flag[21][21]={0};
    for(int j=0;j<n;j++) new_arr[0][j]=arr[0][j];
    for(int i=1;i<n;i++){
        for(int j=0;j<n;j++){
            int tar=arr[i][j];
            if(tar==0) continue;
            int r=i;
            while(r>1&&new_arr[r-1][j]==0) r--;
            if(new_arr[r-1][j]==0) new_arr[r-1][j]=tar;
            else if(new_arr[r-1][j]==tar&&flag[r-1][j]==0){
                new_arr[r-1][j]*=2;
                flag[r-1][j]=1;
            }
            else{
                new_arr[r][j]=tar;
            }
        }
    }
    return bt(depth+1,new_arr);
}
int D(int depth,int arr[21][21]){
    int new_arr[21][21]={0};
    bool flag[21][21]={0};
    for(int j=0;j<n;j++) new_arr[n-1][j]=arr[n-1][j];
    for(int i=n-2;i>=0;i--){
        for(int j=0;j<n;j++){
            int tar=arr[i][j];
            if(tar==0) continue;
            int r=i;
            while(r<n-2&&new_arr[r+1][j]==0) r++;
            if(new_arr[r+1][j]==0) new_arr[r+1][j]=tar;
            else if(new_arr[r+1][j]==tar&&flag[r+1][j]==0){
                new_arr[r+1][j]*=2;
                flag[r+1][j]=1;
            }
            else{
                new_arr[r][j]=tar;
            }
        }
    }
    return bt(depth+1,new_arr);
}
int L(int depth,int arr[21][21]){
    int new_arr[21][21]={0};
    bool flag[21][21]={0};
    for(int i=0;i<n;i++) new_arr[i][0]=arr[i][0];
    for(int j=1;j<n;j++){
        for(int i=0;i<n;i++){
            int tar=arr[i][j];
            if(tar==0) continue;
            int c=j;
            while(c>1&&new_arr[i][c-1]==0) c--;
            if(new_arr[i][c-1]==0) new_arr[i][c-1]=tar;
            else if(new_arr[i][c-1]==tar&&flag[i][c-1]==0){
                new_arr[i][c-1]*=2;
                flag[i][c-1]=1;
            }
            else{
                new_arr[i][c]=tar;
            }
        }
    }
    return bt(depth+1,new_arr);
}
int R(int depth,int arr[21][21]){
    int new_arr[21][21]={0};
    bool flag[21][21]={0};
    for(int i=0;i<n;i++) new_arr[i][n-1]=arr[i][n-1];
    for(int j=n-2;j>=0;j--){
        for(int i=0;i<n;i++){
            int tar=arr[i][j];
            if(tar==0) continue;
            int c=j;
            while(c<n-2&&new_arr[i][c+1]==0) c++;
            if(new_arr[i][c+1]==0) new_arr[i][c+1]=tar;
            else if(new_arr[i][c+1]==tar&&flag[i][c+1]==0){
                new_arr[i][c+1]*=2;
                flag[i][c+1]=1;
            }
            else{
                new_arr[i][c]=tar;
            }
        }
    }
    return bt(depth+1,new_arr);
}
int bt(int depth,int arr[21][21]){
    int result=0;
    if(depth>=5){
        for(int i=0;i<n;i++) for(int j=0;j<n;j++) result=max(arr[i][j],result);
        return result;
    }
    result=max(result,U(depth,arr));
    result=max(result,R(depth,arr));
    result=max(result,D(depth,arr));
    result=max(result,L(depth,arr));
    return result;
}
int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    int arr[21][21]={0};
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) cin>>arr[i][j];
    }
    if(n==1){
        cout<<arr[0][0];
        return 0;
    }
    cout<<bt(0,arr);
    return 0;
}
