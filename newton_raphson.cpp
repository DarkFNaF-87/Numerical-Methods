#include <iostream>
#include <cmath>
using namespace std;

int f_degree;
float f_coff[100];

int f_dash_degree;
float f_dash_coff[100];

float get_output(int degree, float coff[], float input); //needs to see both degree and arr of coff! //returns output of input
void differentiate(int degree, float coff[], int& degree_dash, float coff_dash[]); // needs globals. // calculate and store g_dash_coff and g_dash_degree from same names but for g.
void print_function(int degree , float array[]); //no need to acess globals //neatly type any function using an int input and an array containing the coff.
void get_coff(int degree, float array[]); //no need to access golbas // gets the coff of any function ascendingly by inputing the degree and the arr it will store to

int main(){
	char choice;
	float x;
	float x_o;
	float e;
	float lamda_guide;
	int I;
	int i;
	bool cond;
	
	cond = false;
	i = 1;
	
	cout << "Enter the degree of the function: ";
	cin >> f_degree;
	get_coff(f_degree, f_coff);
	
	cout << endl << "Your function is: " << endl << endl << "f(x) = ";
	print_function(f_degree, f_coff);
		
	differentiate(f_degree, f_coff, f_dash_degree, f_dash_coff);
	cout << endl << "f_dash(x) = ";
	print_function(f_dash_degree, f_dash_coff);
	
	cout << endl << "Enter a starting point: ";
	cin >> x_o;
	
	//User chooses wether they want iterations or error
	cout << endl << endl << "for iteration enter 'I'" << endl << "for error enter 'E'" << endl;
	cin >> choice;
	
	if(choice == 'I' || choice == 'i'){
		cout << "Enter how many iterations would you like to do: ";
		cin >> I;
		cout << endl << endl;
		
		for(int i = 1; i <= I; i++){
			x = x_o - ( get_output(f_degree, f_coff, x_o) / get_output(f_dash_degree, f_dash_coff, x_o) );
			cout << "Iteration " << i << ": "<< endl;
			cout << "x_"<< i-1 <<" = " << x_o << endl;
			cout << "f(x_"<< i-1 <<") = " << get_output(f_degree, f_coff, x_o) << endl;
			cout << "f_dash(x_"<< i-1 <<") = " << get_output(f_dash_degree, f_dash_coff, x_o) << endl;
			cout << "x_"<< i <<" = " << x << endl;
			
			x_o = x;
		}
	}
	else if (choice == 'E' || choice == 'e'){
		cout << "Enter the TOL (error): ";
		cin >> e;
		cout << endl << endl;
		
		while(cond == false){
				x = x_o - ( get_output(f_degree, f_coff, x_o) / get_output(f_dash_degree, f_dash_coff, x_o) );
				
				cout << "Iteration " << i << ": "<< endl;
				cout << "x_"<< i-1 <<" = " << x_o << endl;
				cout << "f(x_"<< i-1 <<") = " << get_output(f_degree, f_coff, x_o) << endl;
				cout << "f_dash(x_"<< i-1 <<") = " << get_output(f_dash_degree, f_dash_coff, x_o) << endl;
				cout << "x_"<< i <<" = " << x << endl;
				
				if (abs(x_o - x) <= e){
					cout << "|x_i - X_i-1| is less than error   <-------------" << endl << endl;
					cond = true;
				}
				if(cond == false){
					x_o = x;
					cout << "No" << endl << endl;
					i++;
				}
			}
	}
	else{
		cout << "Please enter either 'e' or 'i' " << endl;
	}
}

void differentiate(int degree, float coff[], int& degree_dash, float coff_dash[]){
	for (int i = 1; i <= degree; i++){
		coff_dash[i-1] = i * coff[i];
	}
	degree_dash = degree - 1;
}


// should keep either this or the one below it. // the remaining one shoud calculate output for any function given it's degree, coffs and an input.
float get_output(int degree, float coff[], float input){
	float total = 0;
	for (int i = 0; i <= degree; i++){
		total += coff[i] * pow(input, i);
	}
	return total;
}

//this function cout any polynomial function you want you only need to give it the maximun degree of the function and the coffient of that degree decreasingly till you reach the coffient of x^0
void print_function(int degree , float array[]){
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

//this function asks user for the cofftients of an n-th degree function that the user entered
void get_coff(int degree, float array[]){
	for (int i = 0; i <= degree ; i++){
				cout << "Enter a coffetient value for x^" << i << ": ";
				cin >> array[i];
	}
}
