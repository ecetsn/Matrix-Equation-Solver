#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip> 
#include <time.h>



using namespace std;


struct matrisRC{
				int row ;
				int column;
			};


static bool exits;


vector<vector<int>> constructerS(string filename, matrisRC *myStruct, bool arrayExist, int *arr_ , int endNum, string matrixName ){
	
			vector<vector<int>> X;    
			ifstream input;
			string line;


			input.open(filename.c_str());  
				

			int num;

			exits = false;

			if (input.fail()){
				cout<< "Error" << endl;
			input.close();
			}

			int lineCount = 0;
			string s;
			while( getline(input,s) && !input.eof() )
                {
                lineCount++;
                }


			input.seekg(0);

			// get the row value and colum value of the matris
			getline(input,line);
			istringstream input_(line);
			input_ >> myStruct->row >> myStruct->column ; 

			vector<int> v(endNum);

			for (int i = 0; i < endNum; i++)
			{
				v.push_back(arr_[i]);
			}
                   
			while (getline(input, line)) {  
   
				vector<int> Y;          
				istringstream iss(line);
				while (exits == false && iss >> num ) { 
					
					int key = num;

					if (arrayExist == true && find(v.begin(), v.end(), key) == v.end()){
						cout << "Error" << endl;
						exits = true;
					}

					else if(arrayExist == false && num<0){
						cout << "Error" << endl;
						exits = true;
					}

					else if(( matrixName == "rhs" || matrixName == "res" ) && myStruct->column !=1){
						cout << "Error" << endl;
						exits = true;			
					}

					else if(Y.size() == myStruct->column){
						cout << "Error" << endl;
						exits = true;		
					}

					else if(X.size() == myStruct->row){
						cout << "Error" << endl;
						exits = true;	
					}

					else{
							
						Y.push_back(num); 

					}          
				}

				X.push_back(Y);              
			}				

	return X;
}

vector<vector<int>> constructerS(string filename, matrisRC *myStruct, bool arrayExist, string matrixName){

	int arr_[1] = { 0 };
	int end = 1;
	
	return constructerS( filename,  myStruct, arrayExist , arr_ , end , matrixName) ;

}

vector<vector<int>> matrix_lhs;
vector<vector<int>> matrix_rhs;
vector<vector<int>> matrix_res;
vector<int> matrix_rhs_1D;

matrisRC LHS;
matrisRC RHS;
matrisRC RES;

void findMatrix(string out_name);

void findRow(vector<int> & myRow, vector<int> & coeff, int start, int end, int rhs);

void inc(vector<int> & myV, int index);

static string myOut ;

int main()
{
	
	string lhs_name ; 
	string rhs_name ;
	string res_name ;

	cout <<"Enter LHS matrix filename: ";
	cin >> lhs_name;

	cout <<"Enter RHS matrix filename: ";
	cin >> rhs_name;

	cout <<"Enter RES matrix filename: ";
	cin >> res_name;

	cout <<"Enter output filename: ";
	cin >> myOut;


	ifstream lhs_stream, rhs_stream, res_stream;

	ofstream out;

	out.open(myOut,ios::app);

	lhs_stream.open(lhs_name.c_str());
	rhs_stream.open(rhs_name.c_str());
	res_stream.open(res_name.c_str());

	clock_t tStart = clock();

	int arr_lhs[] = { -1, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int arr_rhs[] = {  1, 2, 3, 4, 5, 6, 7, 8, 9 };
	

	// initialize the fisrt matrix and put the values in a vector
	matrix_lhs = constructerS(lhs_name,&LHS, true, arr_lhs, 10, "lhs");

	// if there is no error with the first matrix, do smt with the fisrt one
	if(!exits){
				
		// if there is an error with the first matrix, does not moving on and terminates the program 
			if (!exits)
			{
				matrix_rhs = constructerS(rhs_name,&RHS, true, arr_rhs, 9 , "rhs");

		// if there is an error with the second matrix, don't do the smt with it	
				for (int i = 0; i < matrix_rhs.size(); i++)
				{
					matrix_rhs_1D.push_back(matrix_rhs[i][0]);
				}

				if(!exits){
				
		// if there is an error with the second matrix, does not moving on and terminates 
						if(!exits){

							matrix_res = constructerS(res_name,&RES, false, "res");	

		// if there is an error with the third matrix, don't do the smt with it		

							findMatrix(myOut);

							out.close();

			//	cout<< "Time taken: "<< (double)(clock() - tStart)/CLOCKS_PER_SEC << endl;
							
	
							}
						}
					}
				}

    return 0;
}

static int rowC = 0;


void findRow(vector<int> & myV , vector<int> & coeff , int res, string out_name){

		out_name = myOut;

		ofstream out;

		out.open(out_name,ios::app);

		vector<int> myMiss ;
		int sum = 0;
		sum = res ;
		int sum_temp = 0;
		vector<int> myMissCoeff ; // 

		for (int i = 0 ; i < myV.size() ; i++){
			if(myV[i] == -1){
				myMiss.push_back(myV[i]);
				myMissCoeff.push_back(coeff[i]);
			}	
			else
			{
	
				sum = sum - myV[i]*coeff[i];
			}
		}

		for (int i = 1; i < myMiss.size() + 1; i++) // þuan için myMiss = 2  
			{
				myMiss[myMiss.size()-i]= 1 ; // tüm elemanlar 1
		}
		int num = 1 ;
	
		sum_temp = sum ;

		while(sum_temp != 0 ){ // myMiss teki karakterler sondan artacak
		
			sum_temp = sum ;

			for (int i = 1; i < myMiss.size() + 1; i++) 
			{
				sum_temp -= myMiss[myMiss.size()-i]*myMissCoeff[myMiss.size()-i];		
			}

			if(sum_temp != 0 || sum_temp < 0){ 
				inc(myMiss,myMiss.size()-1);
			}		
		}

		int misC = 0 ;
		for (int i = 0; i < myV.size(); i++)
		{
			if(myV[i]==-1){
				out << rowC << " " << i << " " << myMiss[misC] << endl;
				myV[i] = myMiss[misC] ;
				misC ++ ;
			}
		}	
}

void inc(vector<int> & myV, int index){ 

		if (myV[index] !=9 ){
				myV[index] ++;
		}
		else{
			myV[index] = 1;
			inc(myV,index-1);
		}	
}

void findMatrix(string out_name){

	int myCount = 0;
	for (int i = 0; i < LHS.row ; i++)
	{
		findRow(matrix_lhs[i] ,  matrix_rhs_1D ,matrix_res[i][0], out_name);
		rowC ++ ;
		
	}
}
