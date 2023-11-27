#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;



//function to calculate age
int age_calculation(int birth){
	const int YEAR = 2023;
	int age = YEAR - birth;
	return age;
}


//function to pick out the initials from last name
string lastnameInitial(string last_name){
		string last_initial = last_name.substr(0,1);
	
	return last_initial;
}
	
	
//1st option
void menu1(string last_name[], char initial_array[], int age_array[], double gpa_array[], string degree_array[], int size ){
	
		//diaplays data in table form
	for(int i=0; i<size; i++){
	cout<<setw(9)<<last_name[i]<<"\t"<<initial_array[i]<<"\t\t"<<age_array[i]<<"\t"<<gpa_array[i]<<"\t "<<degree_array[i]<<endl;	
	}
	cout<<" "<<endl;
	
	
}

//2nd option
void menu2(string last_name[], string last_initial[], char initial_array[], int id_array[], int age_array[], double gpa_array[], int size ){
	
				//diaplays data in table form
		for(int i=0; i<size; i++){
				cout<<setw(9)<<last_name[i]<<"\t"<<last_initial[i]<<"\t\t\t"<<initial_array[i]<<"\t\t\t"<<id_array[i]<<"\t"<<age_array[i]<<"\t"<<gpa_array[i]<<endl;	
			}
	cout<<" "<<endl;
}
//3rd option

void DisplayTable(int nElements, string initial[], int id[], double gpa[], string lastname[],int size)
{
	cout<<"Last Name Initial\t ID \t\tGPA"<<endl;
	cout<<"------------------------------------------"<<endl;
    for(int i=0; i<size; i++){
				cout<<setw(9)<<initial[i]<<"\t\t"<<id[i]<<"\t"<<gpa[i]<<endl;	
			}
}



//4th option
void menu4(string last_name[], string last_initial[], int id_array[], int size)
{
	
	cout<<"Search last name initial: ";
	string l_initial; //last name initial searched
	cin>>l_initial;
	cout<<" "<<endl;
	if(!(l_initial>="A"&&l_initial<="Z")){
		cout<<"Please enter a capital letter between A to Z"<<endl;
	}
	else{
		cout<<"Last Name\tID"<<endl;
		cout<<"------------------"<<endl;
		int found = 0; //counts number of matching results found
		for(int i=0; i<size; i++){ 
			if(l_initial==last_initial[i]){
			cout<<setw(9)<<last_name[i]<<"\t"<<id_array[i]<<endl;
			found++;	
			}
		}
		cout<<" "<<endl;
		if(found == 0){
			cout<<"NO MATCHING RESULTS FOUND!"<<endl;
		}
	}
	}

//5th option
void menu5(string last_name[], string last_initial[], char initial_array[], int id_array[], int age_array[], double gpa_array[],string degree_array[], int size ){
	
	
		for(int i=0; i<size; i++){
				cout<<setw(9)<<last_name[i]<<"\t"<<last_initial[i]<<"\t\t\t"<<initial_array[i]<<"\t\t\t"<<id_array[i]<<"\t"<<age_array[i]<<"\t"<<gpa_array[i]<<"\t"<<degree_array[i]<<endl;	
			}
	cout<<" "<<endl;
}

void Swap(int index, int minIndex, string initial[], int id[], int birth_year[], double gpa[], int age[], string lastname[], string degree[], char firstname[])
{
    string tempstr;
    char tempchar;
    double temp;
    // Swap initial array elements
    tempstr = initial[index];
    initial[index] = initial[minIndex];
    initial[minIndex] = tempstr;
    // Swap lastname array elements
    tempstr = lastname[index];
    lastname[index] = lastname[minIndex];
    lastname[minIndex] = tempstr;
    // Swap id array elements
    temp = id[index];
    id[index] = id[minIndex];
    id[minIndex] = temp;
    // Swap age array elements
    temp = age[index];
    age[index] = age[minIndex];
    age[minIndex] = temp;
    // Swap gpa array elements
    temp = gpa[index];
    gpa[index] = gpa[minIndex];
    gpa[minIndex] = temp;
    // Swap degree array elements
    tempstr = degree[index];
    degree[index] = degree[minIndex];
    degree[minIndex] = tempstr;
    // Swap firstname array elements
    
    tempchar = firstname[index];
    firstname[index] = firstname[minIndex];
    firstname[minIndex] = tempchar;
    
}
void SortAscending(int nElements, string initial[], int id[], int birth_year[], double gpa[], int age[], string lastname[], string degree[], char firstname[])
{
    double min;
    int minPos;
    for (int i = 0; i < nElements - 1; i++)
    {
        min = gpa[i];
        minPos = i;
        for (int j = i + 1; j < nElements; j++)
        {
            if (gpa[j] < min)
            {
                min = gpa[j];
                minPos = j;
            }
        }
        Swap(i, minPos, initial, id, birth_year, gpa, age, lastname, degree, firstname);
    }
}





int main(){
	
	//declarinng variables
	const int CAPACITY = 300;
	const double GPA_TIER1 = 4.0;
	const double GPA_TIER2 = 3.3;
	const double GPA_TIER3 = 2.7;
	const double GPA_TIER4 = 2.0;
	const int OPT1 = 1;
	const int OPT2 = 2;
	const int OPT3 = 3;
	const int OPT4 = 4;
	const int OPT5 = 5;
	const int OPT6 = 6;
	const int OPT7 = 7;
	
		
	int size = 0;
	string l_name; 
	char initial;					
	int id;				
	int year_of_birth;
	int age;
	double gpa;
	int i=0;
	int userchoice;	
	
	
	
	//array declarations
	string last_name[CAPACITY];		
	int id_array[CAPACITY];				
	int birthyear[CAPACITY];		
	double gpa_array[CAPACITY];					
	char initial_array[CAPACITY];		
	int age_array[CAPACITY];	
	string degree_array[CAPACITY];
	string last_initial[CAPACITY];
	
	//reades form file "StudentRec.txt"
	ifstream inFile;
    inFile.open("StudentRec.txt"); 	
    
    //check if file exists
    while (inFile.fail()){

		cout << "File does not exsist!! ";

	}

	//discards unwanted lines from file
	for(int i=0; i<3; i++)
	{
		string line;
		getline(inFile,line);
	}
	
	//gets input from file and stores it in arrays
	while(!inFile.eof())
	{
	inFile>>l_name>>initial>>id>>year_of_birth>>gpa;
	last_name[i]=l_name;
	initial_array[i]=initial;
	id_array[i]=id;
	birthyear[i]=year_of_birth;
	gpa_array[i]=gpa;
	age_array[i] = age_calculation(birthyear[i]); // uses the retuen value of age_calculation function	
	last_initial[i] = lastnameInitial(last_name[i]); // uses the retuen value of lastnameInitial function
	
	i++;
	size++;
	}
	
	//closes the file after sorting elements into arrays
	inFile.close();
	
	
	cout<<"----------------------------------MENU----------------------------------------"<<endl;
	cout<<"¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯"<<endl;
	cout<<"|1  |Print list from file                                                     |"<<endl;
	cout<<"|2  |Print the entire class list with inclusion of last name initial and age  |"<<endl;
	cout<<"|3  |Print class list sorted by GPA                                           |"<<endl;
	cout<<"|4  |Print list of students which match a given lastname initial              |"<<endl;
	cout<<"|5  |Calculate and display the corresponding degree classification            |"<<endl;
	cout<<"|6  |Produce a file called Enrollments.txt                                    |"<<endl;
	cout<<"|7  |Exit program                                                             |"<<endl;
	cout<<"¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯"<<endl;	
	cout<<" "<<endl;
	cout<<"Due to the tables being extensive, please view the Application in full-screen :)"<<endl;
	cout<<" "<<endl;
	
	//loops stops if the user enter 7
	while (userchoice != OPT7){
		
		cout<<"Enter Option (1, 2, 3, 4, 5, 6 or 7): ";
		cin>> userchoice;
		//input validation....
			if(cin.fail()){
			cin.clear();
			string dummy;
			cin>>dummy;
		}
		//if the user chooses the first option
		if(userchoice==OPT1){	
			for (int i = 0; i < size; i++) {
        			if (gpa_array[i] == GPA_TIER1) {
				        degree_array[i] =  "First-class honours";
				    } 
					else if ( GPA_TIER2 <= gpa_array[i]) {
				        degree_array[i] =  "Upper Second-class honours";
				    } 
					else if ( GPA_TIER3 <= gpa_array[i]) {
				        degree_array[i] =  "Lower Second-class honours";   
				    }
					else if ( GPA_TIER4 <= gpa_array[i]) {
				        degree_array[i] =  "Third class honours";  
					}
					else {
				         degree_array[i] =  "Orinary degree (no honours)";
				    }
        		
    		}
    	
			cout<<"Last Name\tF.Name Initial \tAge \t GPA \t Degree Classification "<<endl;
			cout<<"----------------------------------------------------------------"<<endl;
			menu1(last_name, initial_array, age_array, gpa_array, degree_array, size ); 
			
		}
		//if the user chooses the 2nd option
		else if(userchoice==OPT2){
			cout<<"Last Name\tLast Name Initial \tFirst Name Initial \tID \t\tAge \tGPA"<<endl;
			cout<<"--------------------------------------------------------------------------------------------"<<endl;
			menu2(last_name, last_initial,  initial_array, id_array, age_array, gpa_array, size );
		
		
		}
		//if the user chooses the 3rd option
		else if(userchoice==OPT3){
			
		
		SortAscending(size, last_initial, id_array, birthyear, gpa_array, age_array, last_name,degree_array, initial_array);
    	DisplayTable(size, last_initial, id_array, gpa_array, last_name, size);
			
 		}
		
		//if the user chooses the 4th option
		else if(userchoice==OPT4){
 			
			menu4(last_name,last_initial, id_array, size);
		
	 }
	 	//if the user chooses the 5th option
		else if (userchoice == OPT5){
			
			for (int i = 0; i < size; i++) {
        			if (gpa_array[i] == GPA_TIER1) {
				        degree_array[i] =  "First-class honours";
				    } 
					else if ( GPA_TIER2 <= gpa_array[i]) {
				        degree_array[i] =  "Upper Second-class honours";
				    } 
					else if ( GPA_TIER3 <= gpa_array[i]) {
				        degree_array[i] =  "Lower Second-class honours";   
				    }
					else if ( GPA_TIER4 <= gpa_array[i]) {
				        degree_array[i] =  "Third class honours";  
					}
					else {
				         degree_array[i] =  "Orinary degree (no honours)";
				    }
        		
    		}
    		
			cout<<"Last Name\tLast Name Initial \tFirst Name Initial \tID \t\tAge \tGPA \tDegree Classification"<<endl;
			cout<<"-----------------------------------------------------------------------------------------------------------------------------"<<endl;
			menu5(last_name, last_initial,  initial_array, id_array, age_array, gpa_array,degree_array, size );
			
			
		}
		//if the user chooses the 6th option
		else if (userchoice == OPT6){
			for (int i = 0; i < size; i++) {
        			if (gpa_array[i] == GPA_TIER1) {
				        degree_array[i] =  "First-class honours";
				    } 
					else if ( GPA_TIER2 <= gpa_array[i]) {
				        degree_array[i] =  "Upper Second-class honours";
				    } 
					else if ( GPA_TIER3 <= gpa_array[i]) {
				        degree_array[i] =  "Lower Second-class honours";   
				    }
					else if ( GPA_TIER4 <= gpa_array[i]) {
				        degree_array[i] =  "Third class honours";  
					}
					else {
				         degree_array[i] =  "Orinary degree (no honours)";
				    }
        		
    		}
    		//uses output form the 5th menu and prints it into "Enrollment.txt"
			menu5(last_name, last_initial,  initial_array, id_array, age_array, gpa_array,degree_array, size );
			ofstream output_data;
			output_data.open("Enrollment.txt");
			output_data<<"Last Name\tLast Name Initial \tFirst Name Initial \tID \t\tAge \tGPA \tDegree Classification"<<endl;
			output_data<<"-----------------------------------------------------------------------------------------------------"<<endl;
			for (int i=0;i<size;i++){
			output_data<<setw(9)<<last_name[i]<<"\t"<<last_initial[i]<<"\t\t\t\t\t"<<initial_array[i]<<"\t\t\t"<<id_array[i]<<"\t"<<age_array[i]<<"\t"<<gpa_array[i]<<"\t"<<degree_array[i]<<endl;	
			}
			cout<<"\n------Data Extraction Complete!------"<<endl<<endl;
			output_data.close();
		
		
		}
		//ensures user only enter a valid option
		if(!(userchoice>=OPT1 && userchoice<=OPT7)){
			cout<<"Please select a menu between 1 and 7"<<endl;
	}

	
	}
	
	
	return 0;
}

	


