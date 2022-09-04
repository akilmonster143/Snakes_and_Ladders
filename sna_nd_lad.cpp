#include<bits/stdc++.h>
using namespace std;
int main(){
    //random number generator for dice
    srand(time(0));
    //hash array to store snakes and ladders
    int hsh[101]={0};
    int c=0,f=0,k;
    //snakes in the game
    hsh[99]=41;
    hsh[91]=84;
    hsh[89]=53;
    hsh[76]=58;
    hsh[64]=45;
    hsh[54]=31;
    hsh[43]=18;
    hsh[40]=3;
    hsh[27]=5;
    //ladders in the game
    hsh[4]=25;
    hsh[8]=29;
    hsh[13]=46;
    hsh[33]=49;
    hsh[42]=63;
    hsh[50]=69;
    hsh[62]=81;
    hsh[67]=86;
    hsh[74]=92;
    //snakes and ladders chart
    vector<vector<int>> v;
    int k1=100;
    for(int i=0;i<10;i++){
        vector<int> z;
        if(i%2==0)
            for(int j=0;j<10;j++) z.push_back(k1--);
        else
        {
            k1-=9;
            for(int j=0;j<10;j++) z.push_back(k1++);
            k1-=11;
        }
        v.push_back(z);
    }
    //print snakes and ladders chart
    cout<<"========::::::    SNAKES AND LADDERS CHART   ::::::========="<<endl;
    //score of player1 and player2
    int p1=0,p2=0;
    //pipes to change positions b/w p1 nd p2
    int pipe[2]={0};
    pipe[0]=1;
    //base condition
    while(p1!=100&&p2!=100){
        //printing the chart
        cout<<"============================================================================"<<endl;
        cout<<endl;
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                if(v[i][j]==p1)
                cout<<"P1."<<"\t";
                else if(v[i][j]==p2)
                cout<<"P2."<<"\t";
                else if(hsh[v[i][j]]!=0){
                    if(hsh[v[i][j]]<v[i][j])
                    cout<<"🐍"<<"\t";
                    else
                    cout<<"🪜"<<"\t";
                }
                else
                cout<<v[i][j]<<"\t";
            }
            cout<<endl;
            cout<<endl;
        }
        cout<<"============================================================================"<<endl;
        cout<<endl;
        //code begins
        string s;
        if(pipe[0]){
        cout<<endl;
        cout<<endl;
        cout<<"::::: CHANCE GOES TO PLAYER 1 :: "<<endl;
        cout<<endl;
        cout<<endl;
        }
        else{
        cout<<endl;
        cout<<endl;
        cout<<"::::: CHANCE GOES TO PLAYER 2:: "<<endl;
        cout<<endl;
        cout<<endl;
        }
        //game starts
        cout<<"===Enter any key to spin dice===="<<endl;
        cin>>s;
        cout<<"*********************************"<<endl;
        k=(rand()%6)+1;
        //if you got 6
        if(k==6)
        cout<<"YOOOO.....""""** DICE SHOWS ::::: "<<k<<endl;
        else
        cout<<":::::: DICE SHOWS ::::: "<<k<<endl;
        //chance opens to a player when you got 6
        if(k==6&&pipe[0]&&c==0) c=1;
        if(k==6&&pipe[1]&&f==0) f=1;
        //player 1 game
        if(pipe[0]&&c==1){
            if(p1+k<=100){
                if(hsh[p1+k]==0){
                    p1+=k;
                    cout<<"Player 1 position is "<<p1<<endl;
                }
                else{
                    if(hsh[p1+k]>p1){
                        cout<<"Yooo...You are on a Ladder::"<<endl;
                        p1=hsh[p1+k];
                        cout<<"Player 1 position is "<<p1<<endl;
                    }
                    else{
                        cout<<"::::: ??You are bited by a snake:: ??: ::::"<<endl;
                        p1=hsh[p1+k];
                        cout<<"Player 1 position is "<<p1<<endl;
                    }
                }
            }
            else cout<<"No position To move player 1 :"<<endl;
        }
        //player 2 game
        if(pipe[1]&&f==1){
            if(p2+k<=100){
                if(hsh[p2+k]==0){
                    p2+=k;
                    cout<<"Player 2 position is "<<p2<<endl;
                }
                else{
                    if(hsh[p2+k]>p2){
                        cout<<"Yooo...You are on a Ladder::"<<endl;
                        p2=hsh[p2+k];
                        cout<<"Player 2 position is "<<p2<<endl;
                    }
                    else{
                        cout<<"::::: ??You are bited by a snake:: ??: ::::"<<endl;
                        p2=hsh[p2+k];
                        cout<<"Player 2 position is "<<p2<<endl;
                    }
                }
            }
            else cout<<"No position To move player 2 :"<<endl;
        }
        //change positions
        if(k==6&&pipe[0]) pipe[0]=1;
        else if(k==6&&pipe[1]) pipe[1]=1;
        else if(pipe[0]){
            pipe[1]=1;
            pipe[0]=0;
        }
        else if(pipe[1]){
            pipe[1]=0;
            pipe[0]=1;
        }
    }
    cout<<"============================================"<<endl;
    cout<<"YOOOOOOOOOOOOOOO............................."<<endl;
    if(p1==100) cout<<"P1 IS WINNER"<<endl;
    else cout<<"P2 IS WINNER"<<endl;
    cout<<"============================================"<<endl;
}
