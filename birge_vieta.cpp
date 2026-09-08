#include <iostream>
#include <cmath>
using namespace std;

void get_coefs(int degree, float array[]);
void print_function(int degree , float array[]);
void setup_table(int degree, float coefs[], float table[][4]);
void calculate_table(int degree, float x, float table [][4]);
float x_new(int degree, float x, float table [][4]);
void print_table(int degree, float table[][4]);

int main(){
	cout << "**************************************************************\n";
	cout << "THIS PROGRAM USES BIRGE VIETA TO FIND THE ROOT OF A POLYNOMIAL\n";
	cout << "**************************************************************\n";

	int degree;
	int I;
	float x_o = 0;
	float x = 0;
	float tol;
	char choice;
	bool cond = false;
	
	//user inputs their function
	cout << "Enter the degree of the function: ";
	cin >> degree;
	float coefs[degree+1];
	get_coefs(degree, coefs);
	print_function(degree, coefs);
	
	cout << endl << "Enter a value for x_o: ";
	cin >> x;
	
	//create the table and filling it
	float table[degree+1][4];
	//user inputs their prefered approach
	cout << endl << endl << "for iteration enter 'I'" << endl << "for error enter 'E'" << endl;
	cin >> choice;
	
	if(choice == 'i' || choice == 'I'){
		cout << "Enter how many iterations would you like to do: ";
		cin >> I;
		cout << endl << endl;
		
		//we want it to calculates new x's till we reach the x_I entered by the user
		for(int i=1; i<=I; i++){
			setup_table(degree, coefs, table);
			calculate_table(degree, x, table);
			print_table(degree, table);
			x = x_new(degree, x, table);
			cout << "x_" << i << " = " << x << endl << endl << endl;
		}
	}
	
	else if(choice == 'e' || choice == 'E'){
		int i = 1;
		cout << "Enter your prefered error (TOL): ";
		cin >> tol;
		while(cond == false){
			setup_table(degree, coefs, table);
			calculate_table(degree, x, table);
			print_table(degree, table);
			x_o = x;
			x = x_new(degree, x, table);
			cout << "x_" << i << " = " << x << endl;
			if(abs(x-x_o) <= tol){
				cond = true;
				cout << "|x-x_o| is less than tol   <---- " << endl;
			}
			else{
				cout << "Condition Not satisfied" << endl << endl;
				i++;
			}
		}
	}
	else{
		cout << "please enter either e or i ";
	}
}

void setup_table(int degree, float coefs[], float table[][4]){
	//fill the first colomns (K) with the degrees. from heighest to lowest
		for(int i=degree; i>=0; i--){
			table[degree-i][0] = i;
		}
		
		//fill the second colomn (a) with coefs. from heighest degree to lowest
		for(int i=degree; i>=0; i--){
			table [degree-i][1] = coefs[i];
		}
		
		//fill the first row with the same value of the heighest coef
		for(int i=1; i<4; i++){
			table [0][i] = coefs[degree];
		}
}

void calculate_table(int degree, float x, float table [][4]){
	for(int colomn=2; colomn<4; colomn++){
		for(int row=1; row<=degree; row++){
			table [row][colomn] = (table [row][colomn-1]) + ((table [row-1][colomn]) * x);
		}
	}
}

float x_new(int degree, float x, float table [][4]){
	x = x - ((table[degree][2])/(table[degree-1][3]));
	return x;
}

void print_table(int degree, float table[][4]){
	for(int row=0; row<=degree; row++){
		for(int coulmn=0; coulmn<4; coulmn++){
			cout << table [row][coulmn] << "  ";
		}
		cout << endl;
	}
}

void print_function(int degree , float array[]){
	cout << endl;
	for (int i = degree; i >= 0; i--){
				//we want it to write the finction normaly, but if coffetion of power == 1 not to write them and the write a + if the coffectient is poistve
				if( (array[i] != 1 && array[i] != 0 && array[i] != -1) && (i != 1 && i!= 0) ){
					cout << array[i] << "x^" << i << " ";
				}
				else if( array[i] == 1 && (i != 1 && i!= 0) ){
					cout << "x^" << i << " ";
				}
				else if( (array[i] != 1 && array[i] != 0 && array[i] != -1) && i == 1  ){
					cout << array[i] << "x ";
				}
				
				else if( i == 0 ){
					cout << array[i];
				}
				
				else if ( array[i]  == 0){
					cout << "";
				}
				
				else if(array[i] == -1 && (i != 1 && i!= 0)){
					cout << "-x^" << i << " ";
				}
				
				else{
					cout << "x ";
				}
				if ( i >= 1 && array[i-1] > 0){
					cout << "+";
				}
			}
}

void get_coefs(int degree, float array[]){
	for (int i = 0; i <= degree ; i++){
				cout << "Enter a coffetient value for x^" << i << ": ";
				cin >> array[i];
	}
}
