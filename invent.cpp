// Problem 2: Inventory Management with Multiple Units

/* 
initial_stock = {"tons": 1, "kilograms": 0, "grams": 0, "milligrams": 0}
Result:	 {"tons": 1, "kilograms": 0, "grams": 0, "milligrams": 0}

after_sale = update_stock(initial_stock, {"tons": 0, "kilograms": 0, "grams": 1, "milligrams": 0}, "sell")
Result: {'tons': 0, 'kilograms': 999, 'grams': 999, 'milligrams': 0}


after_purchase = update_stock(after_sale, {"tons": 0, "kilograms": 0, "grams": 1001, "milligrams": 0}, "purchase")
Result: {'tons': 1, 'kilograms': 0, 'grams': 1, 'milligrams': 0}

*/


#include <iostream>
using namespace std;



const long long MG_IN_TON =1000000000;
const long long MG_IN_KG =1000000;
const long long MG_IN_G =1000;


//conver to milligrams

long long toMilligrams(int ton, int kg, int g, int mg){
	
	return ton *MG_IN_TON + kg*MG_IN_KG + g*MG_IN_G + mg;
}



// converter to milligrams to desire units

void fromMilligrams(long long totolMg){
	
	int tons = totolMg / MG_IN_TON;
	totolMg %=MG_IN_TON;
	
	int kg = totolMg / MG_IN_KG;
	totolMg  %= MG_IN_KG;
	
	
	int g = totolMg / MG_IN_G;
	totolMg %= MG_IN_G;
	
	int mg =totolMg;
	
	 // {"tons": 1, "kilograms": 0, "grams": 0, "milligrams": 0}

	cout <<"{\"tons\" :"<<tons<<", \"kilograms\":"<<kg <<", \"grmas\":"<<g<<", \"milligrams\":"<<mg<<"}"<<endl;
	

}


int main(){
	
	int t, kg, g, mg;
	cout <<"enter your starting stock: "<<endl;
	
	cout <<"tons: "; cin>>t;
	cout <<"kilograms: "; cin>>kg;
	cout <<"grams: "; cin>>g;
	cout <<"milligrams: "; cin>>mg;
	
	
	long long total = toMilligrams(t,kg,g,mg);
	
	
	while(true){
		
		string op;
		cout<<"\n type 'sell' , 'buy' or 'exit'";
		cin>>op;
		
		if(op == "exit") break;
		
		int ct, ckg, cg,cmg;
		 
		cout<<"How much to "<<op <<endl;
		
		cout<<"tons: "; cin>>ct;
		cout<<"kilograms: "; cin>>ckg;
		cout<<"grams: "; cin>>cg;
		cout<<"milligrams: "; cin>>cmg;
		
		long long change =toMilligrams(ct, ckg,cg,cmg);
		
		
		if(op == "sell"){
			if(change>total){
				cout<<"Not enough stock to sell"<<endl;
			}else{
				total =total-change;
				cout<<"after_sale"<<endl;
			}
		}else if(op == "buy"){
			total =total+change;
			cout<<"after_purchase"<<endl;
			
		}else{
			cout<<"invalid"<<endl;
		}
		
		fromMilligrams(total);
		
	}
	
	return 0;
	
}


	
	
