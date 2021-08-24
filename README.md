# Hospital-Registration-System
A registration system for a hospital or clinic.


Patient = Structure containing name, age, sex, telNo, symptoms, diagnosis, medicine, bloodGroup and emergency

name[FNAME][2] = Stores array of name; 1st column is for first name, 2nd column for last name 

age = Stores age of patient

sex = Stores gender of patient

telNo = Stores telephone number of patient

symptoms = Stores symptoms of a patient

diagnosis= Stores the diagnosis of a patient

medicine = Stores the medicine of a patient

bloodGroup = Stores blood group of a patient

emergency = Stores the emergency status of a status

retrieveInfo() = Function to retrieve information from a file containing patient list and number of patients in the file

addDiagnosis() = Function for clinic staff to add diagnosis to patient

addPatient() = Function for user to add a new patient 

showPatient() = Function to display name and symptoms of a patient

save() = Function to save all changes made in the console to the files

showMenu() = Void function to show menu of the program

check() = To check the validity of user-input in the menu driven program

patientCount = Stores number of patients

choice = User input to select processes in the program menu

patientList[SIZE] = Stores an array of structures with 100 patient records

temp = To check the validity of the user-input 

flag = To control loop

patientID = Find the patient using patient ID

option = The option for user to choose in update

dir = The directory of the file in our local folder

countsave = To save the patient count in the local text files

outfile = To save all the information in the local text files

front() = The front page of the program

pt = the location of variable temp
