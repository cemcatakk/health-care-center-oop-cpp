#include <iostream>
using namespace::std;
class HealthCareInfo{
	private:
		string name;
		string surname;
		int age;
		int starvationRate;
	public:
		HealthCareInfo(string Name,string Surname,int Age){
			age=Age;
			name=Name;
			surname=Surname;
			starvationRate=100;
		}
		~HealthCareInfo(){
			cout<<getFullName()<<" quit the health center"<<endl;
		}
		string getName(){
			return name;
		}
		string getSurname(){
			return surname;
		}
		string getFullName(){
			return name+" "+surname;
		}
		int getStarvationRate(){
			return starvationRate;	
		}
		void setStarvationRate(int srate){
			starvationRate=srate;
		}
		bool checkStarvation(){
			if(starvationRate<20)return true;
			else return false;
		}
};

class Patient:public HealthCareInfo{
	private:
		string diseaseName;
	public:
		Patient(string name,string surname,int age,string DiseaseName):HealthCareInfo(name,surname,age){
			diseaseName=DiseaseName;
		}
		void setDiseaseName(string disname){
			diseaseName=disname;
		}
		bool checkStarvation(){
			if(getStarvationRate()<50)return true;
			else return false;
		}
		void takeACare(){
			setStarvationRate(getStarvationRate()-15);
			if(checkStarvation()){
				cout<<"Patient: "<<getName()<<" is hungry!!!"<<endl;
			}
		}
		~Patient(){
			cout<<getFullName()<<" was discharged!"<<endl;
		}
};
class Employee:public HealthCareInfo{
	private:
		int employeeId;
	public:
		Employee(string name,string surname,int age,int EmployeeID):HealthCareInfo(name,surname,age){
			employeeId=EmployeeID;
		}
		int getEmployeeId(){
			return employeeId;
		}
		bool checkStarvation(){
			if(getStarvationRate()<20){
				return true;
			}
			else return false;
		}
		void checkPatient(Patient *patient){
			patient->setStarvationRate(patient->getStarvationRate()-5);
			cout<<"The patient named "<<patient->getFullName()<<" is checking."<<endl;
			if(patient->checkStarvation()){
				cout<<patient->getFullName()<<" is starving."<<endl;
			}
		}
		~Employee(){
			cout<<getFullName()<<" quits the job in the health center."<<endl;
		}
};
class Doctor:public Employee{
	public:
		Doctor(string name,string surname,int age,int employeeId):Employee(name,surname,age,employeeId){
		}
		void checkPatient(Patient *patient){
			patient->setStarvationRate(patient->getStarvationRate()-5);
			cout<<"The patient named "<<patient->getFullName()<<" is checking."<<endl;
			patient->takeACare();
			cout<<getFullName()<<" gives medicine to patient"<<endl;
			if(patient->checkStarvation()){
				cout<<patient->getFullName()<<" is starving!"<<endl;
			}
		}
		~Doctor(){
			cout<<getFullName()<<" quit being a Doctor in this center!"<<endl;
		}
};
class Nurse:public Employee{
	public:
		Nurse(string name,string surname,int age,int employeeId):Employee(name,surname,age,employeeId){
			
		}
		void checkPatient(Patient *patient){
			patient->setStarvationRate(patient->getStarvationRate()-10);
			cout<<"The patient named "<<patient->getFullName()<<" is checking."<<endl;
			patient->takeACare();
			cout<<getFullName()<<" took care of the patient"<<endl;
			if(patient->checkStarvation()){
				cout<<patient->getFullName()<<" is starving!"<<endl;
			}
		}
		~Nurse(){
			cout<<getFullName()<<" quit being a Nurse in this center!"<<endl;
		}
};
int main(int argc, char** argv) {
	Doctor *david = new Doctor("David","Tennant",49,181971);
	Nurse *jodie = new Nurse("Jodie","Whittaker",38,171982);
	Patient *matt = new Patient("Matt","Smith",37,"xyzxyz");
	cout<<"All people in this health center:"<<endl;
	cout<<david->getFullName()<<endl;
	cout<<jodie->getFullName()<<endl;
	cout<<matt->getFullName()<<endl<<endl;
	cout<<"All employees works:"<<endl;
	for(int i=0;i<5;i++){
		cout<<jodie->getFullName()<<endl;
		jodie->checkPatient(matt);
		cout<<endl<<david->getFullName()<<endl;
		david->checkPatient(matt);
		cout<<endl;
	}
	delete david;
	delete jodie;
	delete matt;
	return 0;
}
