#include <iostream>
using namespace std;
/*
 the main fuctionality
 1- menu function
 2- add new patient function
 3- print all specionalizaiton with patient function
 4- get next patient to the doctor
 5- exit the system
*/
// array works as database

string names[20][5];
int status[20][5];

// to show if the specialztion if full of patiens of not;
int queue[20][1] = {0};

// menu function
int menu()
{
    int TheChoice = -1;
    cout << "Enter you choice" << endl;
    cout << "1) Add new patient " << endl;
    cout << "2) Print all patients " << endl;
    cout << "3) Get the next patient " << endl;
    cout << "4) Exit " << endl;
    cout << "**************************************************" << endl;
    cout << "Your choice is : ";
    cin >> TheChoice;
    if (!(TheChoice <= 4 && TheChoice >= 1))
    {
        cout << "Your choice in incorrect!!!!!!, please try again " << endl;
        cout << "**************************************************" << endl;
        return menu();
    }
    return TheChoice;
}

void AddPatient()
{
    int spec, s;
    string name;

    cout << "Enter the specialization and patient name and patient status : ";
    cin >> spec >> name >> s;
    // check if the specialization is full or not
    if (queue[spec][1] >= 5)
    {
        cout << "This Specialization is full of patient , Sorry you can't add this patient\n";
        cout << "**************************************************" << endl;
        return;
    }

    // put data into arrays
    status[spec][queue[spec][1]] = s;
    names[spec][queue[spec][1]] = name;
    // increament the queue
    queue[spec][1]++;
    cout << "Patient is added." << endl;
    cout << "**************************************************" << endl;
}

void printAllPatien()
{
    cout << "printAllPatien function" << endl;
}

void getNextPatient()
{
    cout << "getNextPatient function" << endl;
}

void MainProject()
{
    while (true)
    {

        int choice = menu();
        if (choice == 1)
        {
            AddPatient();
        }
        else if (choice == 2)
        {
            printAllPatien();
        }
        else if (choice == 3)
        {
            getNextPatient();
        }
        else
        {
            cout << "The Program is exit" << endl;
            break;
        }
    }
}

int main()
{

    MainProject();
    return 0;
}