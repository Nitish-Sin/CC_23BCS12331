#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int>tokens={200,100};
    int power=150;

    int low=0;
    int high=tokens.size()-1;
    int score=0;

    sort(tokens.begin(),tokens.end());

    while(low<=high){
        if(power>=tokens[low]){
            score+=1;
            power-=tokens[low];
            low+=1;
        }
        else if(low<high&&score>0){
            score-=1;
            power+=tokens[high];
            high-=1;
        }
        else{
            break;
        }
    }

    cout<<score;

    return 0;
}
