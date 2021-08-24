#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;
const int SIZE = 100;


struct Patient {
    string name[1][2];
    int age;
    char sex;
    string telNo;
    string symptoms;
    string diagnosis;
    string medicine;
    string bloodGroup;
    char emergency;
};

void front();
void showMenu();
void retrieveInfo(Patient[], int&);
void addPatient (Patient[], int&);
void addDiagnosis (Patient[]);
void updatePatient (Patient []);
void showPatient (Patient[]);
void save(Patient[], int&);
int check (int*);


int main(){
    
    int patientCount = 0, choice, temp;
    int *pt = &temp;
    
    Patient patientList[SIZE];
    
    front();
    retrieveInfo(patientList,patientCount);
    showMenu();
    cin >> temp;
    choice = check(pt);
    
    while (choice>0){
        
        
        switch(choice){
                
            case 1 : addPatient(patientList, patientCount);
                break;
                
            case 2 : addDiagnosis (patientList);
                break;
                
            case 3 : showPatient (patientList);
                break;
                
            case 4 : updatePatient(patientList);
                break;
                
            case 5 :save(patientList, patientCount);
                exit(1);
        }
        showMenu();
        cin >> temp;
        choice = check(pt);
        }
    return 0;
}


int check (int *temp){
    
    bool flag = false;
    
    while (flag==false){
        if (*temp<1 || *temp>5){
            cout << "\nInvalid. Choice must be between 1-5." << endl;
            cin >> *temp;}
        else
            return *temp;
    }
    return *temp;
}


void showMenu(){
    
    cout << "\nPress  1 to add patient \n";
    cout << "       2 to add symptoms \n";
    cout << "       3 to show patient's information \n";
    cout << "       4 to update patient's information \n";
    cout << "       5 to save & exit\n";
}


void addPatient (Patient patientList[], int &i){
    
    int temp;
    char y;
    
    cout << "Patient ID : " << i+1;
    
    cout << "\nEnter patient's name : ";
    cin >> patientList[i].name[0][0] >> patientList[i].name[0][1];
    
    cout << "\nEnter patient's age : ";
    cin >> temp;
    
    while (temp<1 || temp>120){
        cout << "Invalid input, age should be integer under 120 years old.\n";
        cin >> temp;
    }
    patientList[i].age = temp;
    
    cout << "\nEnter patient's sex : ";
    cin >> y;
    
    while(y!=0){
        if (y=='M' || y=='m' || y=='F' || y=='f'){
            patientList[i].sex = y;
            break;
        }
        else{
            cout << "Invalid input, sex should be M or F";
            cin >> y;
        }
    }
    patientList[i].sex = y;
    
    cout << "\nEnter patient's contact number : ";
    cin.ignore();
    getline(cin,patientList[i].telNo);
    cout << endl;
    
    cout << "Patient saved successfully. \n";
    ++i;
}


void addDiagnosis (Patient patientList[]){
    
    int patientID;
    
    cout << "\nEnter patient ID : ";
    cin >> patientID;
    --patientID;

    cout << "\nEnter symptoms : ";
    cin.ignore();
    getline(cin,patientList[patientID].symptoms);
    
    
    cout<<"\nEmergency treatment required? (Yes-Enter Y / No-Enter N) : ";                          // is it an emergency
    cin>>patientList[patientID].emergency;
    cout<<endl;
    
    if(patientList[patientID].emergency == 'N' || patientList[patientID].emergency == 'n'){      //non emergency situation
        cout << "\nEnter diagnosis    :";                                                           //diagnose n medicine
        cin.ignore();
        getline(cin,patientList[patientID].diagnosis);
        
        cout << "\nEnter medicine     : ";
        getline(cin,patientList[patientID].medicine);
        
        cout << "\nEnter patient blood group, if applicable. If not, enter NULL  : ";               //bloodGroup
        cin >> patientList[patientID].bloodGroup;
    }
    else if(patientList[patientID].emergency == 'Y' || patientList[patientID].emergency == 'y')   //emergency situation
        cout<<"\nWe have already notify the nearest hospital for assistance.";
    else
        cout<<"\nInvalid character. Enter Y or N only!";
    
    cout<<"\nPatient diagnosed successfully!\n";
}


void updatePatient (Patient patientList[]){
    
    int i, temp, option;
    char y;
    
    cout << "\nEnter Patient ID : ";
    cin >> i;
    --i;
    
    cout << "Which information do you want to update ? \n" << endl;
    cout << "1. Name   2. Age     3. Sex    4. Contact Number" << endl;
    cin >> option;
    
    switch(option){
    
        case 1 :    cout << "\nEnter patient's name : ";
                    cin >> patientList[i].name[0][0] >> patientList[i].name[0][1];
            break;
    
        case 2 :    cout << "\nEnter patient's age : ";
                    cin >> temp;
    
                    while (temp<1 || temp>120){
                        cout << "Invalid input, age should be integers.\n";
                        cin >> temp;
                    }
                    patientList[i].age = temp;
            break;
    
        case 3 :    cout << "\nEnter patient's sex : ";
                    cin >> y;
    
                    while(y!=0){
                        if (y=='M' || y=='m' || y=='F' || y=='f'){
                            patientList[i].sex = y;
                            break;
                        }
                        else{
                            cout << "Invalid input, sex should be M or F";
                            cin >> y;
                        }
                    }
            break;
    
        case 4 :    cout << "\nEnter patient's contact number : ";
                    cin.ignore();
                    getline(cin,patientList[i].telNo);
            break;
            
        default :   cout << "Invalid entry. The option is only 1-4" << endl;
            }
    
    cout << "\nPatient has been updated successfully. \n";
   
}


void showPatient (Patient patientList[]){
    
    int patientID;
    cout << "Enter patient ID : ";
    cin >> patientID;
    --patientID;
    
    cout << "Name           : " << patientList[patientID].name[0][0] << " " << patientList[patientID].name[0][1] << endl;
    cout << "Age            : " << patientList[patientID].age << endl;
    cout << "Sex            : " << patientList[patientID].sex << endl;
    cout << "Contact No     : " << patientList[patientID].telNo << endl;
    cout << "Symptoms       : " << patientList[patientID].symptoms << endl;
    cout << "Emergency      : " << patientList[patientID].emergency << endl;
    cout << "Diagnosis      : " << patientList[patientID].diagnosis << endl;
    cout << "Medicine       : " << patientList[patientID].medicine << endl;
    cout << "Blood Group    : " << patientList[patientID].bloodGroup << endl;
}


void retrieveInfo (Patient patientList[], int &patientcount){
    
    
    ifstream count;
    count.open("/Users/adrimohamad/Downloads/Sem 1/CSCI 1300/Group Project/Test Clinic 2/Test Clinic 2/patientCount.txt");
    
    if(count.fail())
        cout << "Failed open file" << endl;
    
    count >> patientcount;
    count.close();
    
    
    string patient[SIZE];
    string dir = "/Users/adrimohamad/Downloads/Sem 1/CSCI 1300/Group Project/Test Clinic 2/Test Clinic 2/patient";
    
    
    for (int i=0; i<patientcount; i++){
        
        patient[i] = dir + to_string(i+1) + ".txt";
        
        
        ifstream retrievepatient;
        retrievepatient.open (patient[i].c_str());
        
        if (retrievepatient.fail())
            cout << "Failed";
        
        retrievepatient >> patientList[i].name[0][0]>> patientList[i].name[0][1] ;
        
        retrievepatient >> patientList[i].age;
        
        retrievepatient >> patientList[i].sex;
        
        retrievepatient.ignore();
        getline(retrievepatient,patientList[i].telNo);
        
        getline(retrievepatient,patientList[i].symptoms);
        
        retrievepatient >> patientList[i].emergency ;
        
        retrievepatient.ignore();
        getline(retrievepatient,patientList[i].diagnosis);
        
        getline(retrievepatient,patientList[i].medicine);
        
        retrievepatient >> patientList[i].bloodGroup;
        retrievepatient.close();}
    
    
    cout << "Patient Count : " << patientcount << endl;
    
}



void save (Patient patientList[], int &patientcount){
    
    ofstream countsave;
    countsave.open("/Users/adrimohamad/Downloads/Sem 1/CSCI 1300/Group Project/Test Clinic 2/Test Clinic 2/patientCount.txt");  //put your file directory here
    countsave << patientcount;
    countsave.close();
    
    string patient[SIZE];
    string dir = "/Users/adrimohamad/Downloads/Sem 1/CSCI 1300/Group Project/Test Clinic 2/Test Clinic 2/patient";
    
    for (int i=0; i<patientcount; i++){
        
        patient[i] = dir + to_string(i+1) + ".txt";
        
        ofstream outfile;
        outfile.open (patient[i].c_str());
        
        if (outfile.fail())
            cout << "Failed";
        
        outfile << patientList[i].name[0][0] << " " << patientList[i].name[0][1] << endl;
        outfile << patientList[i].age << endl;
        outfile << patientList[i].sex << endl;
        outfile << patientList[i].telNo << endl;
        outfile << patientList[i].symptoms << endl;
        outfile << patientList[i].emergency << endl;
        outfile << patientList[i].diagnosis << endl;
        outfile << patientList[i].medicine << endl;
        outfile << patientList[i].bloodGroup << endl;

        outfile.close();
    }
    cout << "Saved Successfully !\n";
}


void front (){
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
    cout<<"\t\t\t\t\t@@ _______________________________________________________________________________________ @@\n";
    cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
    cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
    cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
    cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
    cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
    cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
    cout<<"\t\t\t\t\t@@|                                      WELCOME TO                                       |@@\n";
    cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
    cout<<"\t\t\t\t\t@@|                                   CLINIC ABU SEMAN                                    |@@\n";
    cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
    cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
    cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
    cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
    cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
    cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
    cout<<"\t\t\t\t\t@@|_______________________________________________________________________________________|@@\n";
    cout<<"\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n\n\n\t\t\t\t\t";
}

