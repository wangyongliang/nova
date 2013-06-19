 
 #include <iostream>
 #include <algorithm>
 using namespace std;
 
 int main () {
   int SC;
   cin >> SC;
   for( int S=1; S<=SC; S++ ){
     cout << "Scenario #" << S << ":" << endl;
     
     //--- Read the test case.
     int m, p;
     cin >> m >> p;
     int t[24];
     for( int i=0; i<p; i++ )
       cin >> t[i];
     
     //--- Sort.
     sort( t, t+p );
     
     //--- Analyze.
     int solved = 0, score = 0, sum = 0;
     for( int i=0; i<p; i++ ){
       sum += t[i];
       if( sum <= m ){
 	solved++;
 	score += sum;
       }
     }
     
     //--- Answer.
     cout << "Steve wins with " << solved << " solved problems and a score of " << score << "." << endl << endl;
   }
}
 
