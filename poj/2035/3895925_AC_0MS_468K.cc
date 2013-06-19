#include <iostream>
#include <queue>
using namespace std;

queue<int> Q[11];
int Count[10], last[10];
int n, game, players;
bool unwinnable, Empty;
bool Debug = false;


void PlayGame(){
  int card, passes=0;
 
//  for(int i=0;i<players;i++) Count[i]=0;
  for(int i=0;i<11;i++) Count[i]=0;

 while(passes<=5300){
  for(int i=players-1; i>=0;i--){
    if(!Q[i].empty())   {
      Count[i]++;
      if(Count[i]==14) Count[i]=1;
      card = Q[i].front();
      Q[i].pop();
      if(card==Count[i]){  //pass card
if(Debug) cout<<"player "<<i<<" passed "<<card<<endl;
        Q[i+1].push(card);
        last[i]=card;
        passes=0;
      }
      else 
        Q[i].push(card);
    }
  }
  passes++;
 }
  //see if all queues empty
  Empty = true;
  for(int i=0;i<players;i++)
    if(!Q[i].empty())
      Empty = false;
  if(!Empty) unwinnable = true;
}


int main(){
  int x;

  cin>>n;
  for(int game=1; game<=n; game++)  {
    cin>>players;
    for(int i=0;i<52;i++){   //get cards
      cin>>x;
      Q[0].push(x);
    }
    unwinnable = false; 
    PlayGame();
    cout<<"Case "<<game<<":";
    if(unwinnable) cout<<" unwinnable"<<endl;
    else {
      for(int i=0;i<players;i++)
        cout<<' '<<last[i];
      cout<<endl;
    }
    //clean out all queuese
    for(int i=0;i<=players;i++)
      while(!Q[i].empty()) Q[i].pop();

  }

return 0;
}