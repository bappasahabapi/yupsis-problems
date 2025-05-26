

/* 
## Problem 1: Mojo and Mutki Exchange Calculation

intitial:

 int mojos =4;
 int muktis =0;
 totalEaten=0;
 
 for every 3 motkas exchange I get 1 mojo;
 
## Final output: 
Total = ? Mojos consumed



while (mojos>0){
	

 totalEaten = mojos+totalEaten  = 4+0
 mutkis =mojos +muktis; = 4+0 =4
 mojos =0
 
 exchange:
 mojos = mutkis/3 =4/3 =1
 muktis=mutkis =mutkis%3 =4%3 =1
	

}

*/

#include <iostream>
using namespace std;

int main()
{
	
	int mojos;
	cout<<"Enter the no of mojos you buy: "<<endl;
	cin>>mojos;
	
	int mutkis =0;
	int totalEaten =0;
	
	while(mojos>0){
		totalEaten =totalEaten+mojos;
		mutkis =mojos+mutkis;
		mojos=0;
		
		// exchange part
		mojos =mutkis/3;
		mutkis=mutkis %3;
		
	}
	
		cout<<"Unused mutkis: "<<mutkis<<endl;
		cout<<"Total mojos consumed: "<<totalEaten<<endl;

    return 0;
}