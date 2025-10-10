#include <iostream>
#include <cmath>
using namespace std;


int degree;
double coff[1000];

double function( double x){
	double fx = 0;
	for (int i = 0; i <= degree; i++){
		fx += coff[i] * pow(x,i);
	}
	return fx;
}

int main(){
		char choice;
		int I;
		int i;
		bool cond;
		double e;
		double a;
		double b;
		double fa;
		double fb;
		double c;
		double oc;
		double fc;
		char again;
		char keepf;
		
		
		cout << "<------THIS PROGRAM CALCULATE THE ROOT FOR ANY POLYNOMIAL FUNCTION USING BISECTION METHOD------>" << endl;
					
		do{
			//Creating a function
			cout << "Enter the degree of the function: ";
			cin >> degree;
			for (int i = 0; i <= degree; i++){
				cout << "Enter a coffetient value for x^" << i << ": ";
				cin >> coff[i];
				} 
			
			do{
				cond = false;
				i = 1;
				
				
				cout << endl << "for Iterations Enter 'I'" << endl << "for Error Enter 'E' " << endl;
				cin >> choice;
			
				if(choice == 'I' || choice == 'i'){
					cout << "Enter how many Iterations would you like to do: ";
					cin >> I;
					
					cout << "Enter a value for a: ";
					cin >> a;
					
					cout << "Enter a value for b: ";
					cin >> b;
				
					for (int i = 1; i <= I; i++){
						c = (a+b) / 2;
						fa = function(a);
						fb = function(b);
						fc = function(c);
						
						cout << endl << "Iteration " << i << ": " << endl;
						cout
						<< "a = " << a << endl 
						<< "b = " << b << endl 
						<< "c = " << c << endl 
						<< "f(a) = " << fa << endl 
						<< "f(b) = " << fb << endl 
						<< "f(c) = " << fc << endl;
						
						if( fc * fa < 0){
							b = c;
						}
						else{
							a = c;
						}
						
					}
				}
				
			
				else if (choice == 'E' || choice == 'e'){
					cout << "Enter your prefered error: (the smaller the more accurate)" << endl;
					cin >> e;
					
					cout << "Enter a value for a: ";
					cin >> a;
					
					cout << "Enter a value for b: ";
					cin >> b;
				
					while (cond == false){
						oc = c;
						c = (a+b) / 2;
						fa = function(a);
						fb = function (b);
						fc = function (c);
						
						cout << endl << "Iteration " << i << ": " << endl;
						cout
						<< "a = " << a << endl 
						<< "b = " << b << endl 
						<< "c = " << c << endl 
						<< "f(a) = " << fa << endl 
						<< "f(b) = " << fb << endl 
						<< "f(c) = " << fc << endl;
						
						if( abs(fc) < e ){
							cond = true;
							cout << "|f(c)| is less than error   <-------------" << endl;
						}
						else{
							cout << "No" << endl;
						}
					
					
						if( i > 1 && abs( oc - c) < e ){
							cond =true;
							cout << "|C - C-node| is less than error   <-------------" << endl;
						}
						else{
							cout << "No" << endl;
						}
						
						if (cond == false){
							i ++;
							if( fc * fa < 0){
								b = c;
							}
							else{
								a = c;
							}
						}
					
					}
					
					cout << endl << "FINAL ANSWER: The root is ~= " << c << endl;
					
				}
				else{
					cout << "Please Enter a valid input";
				}
				
			cout << endl << "Would you like to start again? (Y/N) " << endl;
			cin >> again;
			if (again != 'Y' && again != 'y'){
				return 0;
			}
			
			cout << "Keep the function? " << endl;
			cin >> keepf;
			} while (keepf == 'Y' || keepf == 'y');
			
		} while(again == 'Y' || again == 'y');

}
