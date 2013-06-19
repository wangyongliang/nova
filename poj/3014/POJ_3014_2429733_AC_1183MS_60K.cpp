#include<stdio.h> 
const int MAX_NUM = 4500; 
 const int MODULAR = 1000000007; 
 int count[MAX_NUM+2];  
 int main() 
 { 	
	 int nPlate, nCake; 	
	 scanf("%d %d", &nPlate, &nCake); 	
	 int plate, cake; 	
	 count[nCake] = 1; 	
	 for (plate = nPlate; plate > 1; --plate) 	
	 { 		
		 for (cake = nCake; cake >= plate; --cake) 		
		 { 			
			 count[cake-plate] += count[cake]; 			
			 if ( count[cake-plate] > MODULAR ) 				
				 count[cake-plate] %= MODULAR; 
		 } 	
	 } 	
	 int ans=0; 	
	 for (cake = 0; cake <= nCake; ++cake) 		
		 ans = (ans + count[cake]) % MODULAR; 	
	 printf("%d\n", ans); 	
	 return 0; 
 }