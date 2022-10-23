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
    cout << "AddPatient function" << endl;
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
            cout<<"The Program is exit"<<endl;
            break;
        }
    }
}

int main()
{

    MainProject();
    return 0;
}