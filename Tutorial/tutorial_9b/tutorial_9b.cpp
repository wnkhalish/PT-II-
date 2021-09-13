//------------------------------------------------------------------------------
// Faculty of Computing, Universiti Teknologi Malaysia
// SCSJ1023- Programming Technique II
// Semester 1, 2018/2019
// Tutorial 9b : Polymorphism
//
//------------------------------------------------------------------------------

#include <iostream>
using namespace std;

// The class Person is FULLY given
// Do not change anything for this class
class Person
{
  protected:
	string name;

  public:
	Person(string name = "") { setName(name); }
	string getName() const { return name; }
	void setName(string name) { this->name = name; }
};

class Doctor : public Person
{
  protected:
	string department;

  public:
	Doctor(string n = "", string d = "") // n is doctor's name,  d is department
	{
	}
	void setDepartment(string d) { department = d; }
	string getDepartment() const { return d; }
};

class Guardian : public Person
{
  protected:
	string phone;

  public:
	Guardian(string n = "", string p = "") // n is guardian's name,  p is phone number
	{
	}
	void setPhone(string p) { phone = p; }
	string getPhone() const { return p; }
};

class Patient : public Person
{
  protected:
	Doctor *doctor;
	Guardian guardian;

  public:
	Patient(string pn = "", string pi = "", // patient's name and the illness
			string gn = "", string gp = "") // guardian's name and phone number
	{
		name = pn;
		illness = pi;
		guardian.setName(gn);
		guardian.setPhone(gp);
		doctor = NULL;
	}

	void print() const
	{
		cout << "Patient's Name   :" << name << endl;
		cout << "Illness          :" << ilness << endl;
		cout << "Guardian's Name  :" << guardian.setName() << endl;
		cout << "Guardian's Phone :" << guardian.setPhone() << endl;

		if (d !NULL)
		{
			cout << "Doctor's Name    :" << doctor->getName() << endl;
			cout << "Doctor's Dept.   :" << doctor->getDepartment() << endl;

			cout << " *** No doctor assigned yet *** " << endl;
		}
		else
		{
			void assignDoctor(Doctor * doctor)
			{
				doctor = doctor;
			}
		}
	}
};

class Outpatient : public Patient
{
  private:
	string diagnosis;

  public:
	Outpatient(string pn = "", string pi = "", // patient's name and illness
			   string gn = "", string gp = "", // guardian's name and phone number
			   string pdiagnosis = "")		   // diagnosis type
	{
		diagnosis = pdiagnosis;
	}

	void print() const
	{
		cout << "Patient Type:  OUTPATIENT " << endl;
		cout << "Diagnosis   :  " << diagnosis << endl;
		cout << endl;
	}
};

class Inpatient : public Patient
{
  private:
	string ward;

  public:
	Inpatient(string pn = "", string pi = "", // patient's name and illness
			  string gn = "", string gp = "", // guardian's name and phone number
			  string pward = "")			  // patient's ward
	{
		ward = pward;
	}

	void print() const
	{
		cout << "Patient Type:  INPATIENT " << endl;
		cout << "Ward        :  " << ward << endl;
		cout << endl;
	}
};

// The menu function is fully given
int menu()
{
	cout << endl;
	cout << "========== Menu ==========" << endl;
	cout << "1. List Doctors" << endl;
	cout << "2. List Patients" << endl;
	cout << "3. Assign Doctor" << endl;
	cout << "4. Exit" << endl;
	cout << endl;

	int choice;
	cout << "Choose an operation [1-4] => ";
	cin >> choice;

	cin.ignore();
	cout << endl;

	return choice;
}

int main()
{
	const int NDOC = 2;		// Number of of doctor.
	const int NPATIENT = 3; // Number of patients.

	// For convenience (for copy-and-paste purposes), the data of doctors and patients
	//  are given at the bottom of this program.

	Doctor doctors[NDOC] = {Doctor("Dr. Ramli", "ICU"),
							Doctor("Dr. Kamariah", "Radiology")};

	Patient *patients[NPATIENT] = { new Outpatient("Rozita", "Sprained ankle", "Salleh", "4466", "X-ray"),
									new Inpatient("Nurdiana", "Respiratory failure", "Jalil", "7731", "ICU 101"),
									new Outpatient("Ali", "Coronary artery", "Bakar", "1234", "CT Scan") int c = menu();

	while (c != 4)
	{

		switch (c)
		{
		case 1: // List Doctors
			for (int i = 0; i < NDOC; i++)
				cout << "Doctor's Name: " << doctor[i].getName() "\t"
					 << "Department: " << doctor[i].getDepartment() << endl;

			break;

		case 2: // List Patients
			for (int i = 0; i < NPATIENT; i++)
				cout << "Patient #" << patient[i].getName() << endl;
			cout << endl;

			break;

		case 3: // Assign Doctor
				// The operation regarding getting inputs from the user is given
				// You must use the exception handling strategy
				// to handle the "out of range" error

			int pIndex; // The array index of the patient to be assigned with a doctor.
			int dIndex; // The array index of the doctor to assign to the patient.

			cout << "Enter the patient index and doctor index => ";
			cin >> pIndex >> dIndex;

			break;

			try
			{
				if (pIndex < 0) || () 
			}

			c = menu();
		}

		return 0;
	}

	/*

Doctors and patients data

Doctors:
name and department

Dr. Ramli , ICU
Dr. Kamariah ,  Radiology

Patients:
name, illness,guardian'name, guardian's phone, diagnosis, ward number, and patient type

Rozita   , Sprained ankle , Salleh , 4466, X-ray , Outpatient
Nurdiana , Respiratory failure , Jalil, 7731, ICU 101, Inpatient
Ali , Coronary artery , Bakar , 1234 ,CT Scan, Outpatient

*/
