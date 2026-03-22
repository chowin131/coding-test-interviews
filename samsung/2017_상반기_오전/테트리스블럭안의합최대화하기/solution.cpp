#include <iostream>
using namespace std;
int n,m;
int M[200][200];
int Tr[5][4]={{0,0,0,0},{0,1,2,2},{0,1,1,2},{0,1,1,2},{0,1,1,0}};
int Tc[5][4]={{0,1,2,3},{0,0,0,1},{0,0,1,0},{0,0,1,1},{0,0,1,1}};
int calr[4]={1,1,-1,-1};
int calc[4]={1,-1,1,-1};
int func(int type){
    int result=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int c=0;c<4;c++){
                int temp=0;
                bool flag=0;
                for(int body=0;body<4;body++){
                    int nr=i+calr[c]*Tr[type][body],nc=j+calc[c]*Tc[type][body];
                    if(nr<0||nr>n-1||nc<0||nc>m-1){
                        flag=1;
                        break;
                    }
                    temp+=M[nr][nc];
                }
                if(flag) continue;
                result=max(result,temp);
            }
            for(int c=0;c<4;c++){
                int temp=0;
                bool flag=0;
                for(int body=0;body<4;body++){
                    int nr=i+calr[c]*Tc[type][body],nc=j+calc[c]*Tr[type][body];
                    if(nr<0||nr>n-1||nc<0||nc>m-1){
                        flag=1;
                        break;
                    }
                    temp+=M[nr][nc];
                }
                if(flag) continue;
                result=max(result,temp);
            }
        }
    }
    return result;
}
int main() {
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>M[i][j];
        }
    }
    int result=0;
    result=max(result,func(0));
    result=max(result,func(1));
    result=max(result,func(2));
    result=max(result,func(3));
    result=max(result,func(4));
    cout<<result;
    return 0;
}
