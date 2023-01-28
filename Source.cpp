#include<iostream>
#include<string>

#define SIZE 70
#define SUB 3
using namespace std;

class Student {
	int    regNo;
	string name;
	int    subMarks[SUB];
	double average;
	char   grade;
public:
	Student() :regNo(0), name(" "), average(0.0), grade(' ')
	{
		for (int i = 0; i < SUB; i++)
		{
			subMarks[i] = 0;
		}
	}

	void mySetter();
	void myGetter();
	int  getReg();

};

int Student::getReg()
{
	return regNo;
}
void Student::mySetter()
{	
	int sum = 0;
	
	cout << " Enter RegNo: ";
	while (true)
	{
		cin >>regNo;
		if (regNo > 1000 && regNo < 9999)
			break;
		else
			cout << " Invalid Range !!! \n Enter Again: ";
	}

	cin.ignore(10, '\n');
	cout << " Enter Name: ";
	getline(cin, name);

	cout << " Enter Marks: ";
	for (int j = 0; j < SUB; j++)
	{
		while (true)
		{
			cin >> subMarks[j];
			if (subMarks[j] >= 0 && subMarks[j] <= 100)
				break;
			else
				cout << " Invalid Range !!! \n Enter Again: ";
		}
		sum += subMarks[j];
	}
	average = (sum * 1.0) / SUB;

	if (average >= 80)
		grade = 'A';
	else if (average >= 70)
		grade = 'B';
	else if (average >= 60)
		grade = 'C';
	else if (average >= 50)
		grade = 'D';
	else
		grade = 'F';

}
void Student::myGetter()
{
	cout << "\n " << regNo << "  " << name << "  ";
	for (int i = 0; i < SUB; i++)
	{
		cout << subMarks[i] << " ";
	}
	cout << average << "  " << grade << "  ";
	cout << endl;
}

int main()
{
	Student student[SIZE];
	int n = 0, regNo, index = 0;
	char ch;
	while (true) {
		cout << "\n ------------(MAIN MENU)-----------\n";
		cout << " 1) CREATE DATABASE \n";
		cout << " 2) GETTER \n";
		cout << " 3) APPEND NEW RECORD \n";
		cout << " 4) DELETION \n";
		cout << " 5) UPDATION \n";
		cout << " 6) SORTING \n";
		cout << " 7) EXIT \n\n";

		cout << " Enter Your Choice: ";
		cin >> ch;

		switch (ch) {
		case '1':
			cout << "\n Enter The Total Number Of Student: ";
			while (true)
			{
				cin >> n;
				if (n < 70 && n > 0)
				{
					break;
				}
				else
					cout << " Invalid Range !!! \n Enter Again: ";
			}
			for (int i = 0; i < n; i++)
			{
				cout << " Enter The Data For Student No " << i + 1 << endl;
				student[i].mySetter();
				cout << endl;
			}
			break;
		case '2':
			if (n == 0)
				cout << " Data Base is Empty ...!!! \n First Create Database Then Perform Getter Operation.\n";
			else
			{
				for (int i = 0; i < n; i++)
				{
					student[i].myGetter();
				}
			}
			
			break;
		case '3':
			cout << " Enter The Data For Student You Want To Append ..."<< endl;
			student[n].mySetter();
			n++;
			cout << "\n Append New Record Successfully ... !!!\n";
			break;
		case '4':
			if (n == 0)
				cout << " Data Base is Empty ...!!! \n First Create Database Then Perform Delete Operation.\n";
			else
			{
				cout << "n: " << n;
				cout << " Enter The RegNo Of Student You Want To Delete: ";
				cin >> regNo;
				for (int i = 0; i < n; i++)
				{
					if (student[i].getReg() == regNo)
					{
						index = i;
						break;
					}
				}
				if (index)
				{
					for (int i = index; i < n; i++)
					{
						student[i] = student[i + 1];
					}
					n--;
					index = 0;
					cout << "\n Delete The Record Successfully ... !!!\n";
				}
				else
					cout << "\n RegNo Not Found ... !!!\n";
			}
			break;
		case '5':
			if (n == 0)
				cout << " Data Base is Empty ...!!! \n First Create Database Then Perform Update Operation.\n";
			else
			{
				cout << " Enter The RegNo Of Student You Want To Update: ";
				cin >> regNo;
				for (int i = 0; i < n; i++)
				{
					if (student[i].getReg() == regNo)
					{
						index = i;
						break;
					}
				}
				if (index)
				{
					student[index].mySetter();
					index = 0;
					cout << "\n Delete The Record Successfully ... !!!\n";
				}
				else
					cout << "\n RegNo Not Found ... !!!\n";
			}
			break;
		case '6':
			if (n == 0)
				cout << " Data Base is Empty ...!!! \n First Create Database Then Perform Sorting.\n";
			else
			{
				for (int i = 0; i < n - 1; i++)
				{
					for (int j = i + 1; j < n; j++)
					{
						if (student[i].getReg() > student[j].getReg())
						{
							swap(student[i], student[j]);
						}
					}
				}
				cout << "\n Sort The Data Successfully ... !!!\n";
			}
			break;
		case '7':
			exit(-1);
		default:
			cout << "\n Invalid Input ... !!!\n";
		}

	}
}