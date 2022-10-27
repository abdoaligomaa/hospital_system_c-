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
bool status[20][5];

// to show if the specialztion if full of patiens of not;
int queue[20][1] = {0};

// shift right function
void shiftRight(int spec, string name[], bool statu[])
{
    int len = queue[spec][0];

    for (int i = len; i >= 1; i--)
    {
        name[i] = name[i - 1];
        statu[i] = statu[i - 1];
    }
    // increase number of patients in this specialization
    queue[spec][0]++;
}

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
    int spec;
    bool s;
    string name;

    cout << "Enter the specialization and patient name and patient status : ";
    cin >> spec >> name >> s;
    // convert from 0 base to 1 base
    spec--;

    // check if the specialization is full or not
    if (!(spec >= 0 && spec <= 19))
    {
        cout << "This Specialization not found you should enter number from 1 to 20\n";
        cout << "**************************************************" << endl;
        return AddPatient();
    }
    if (queue[spec][1] >= 5)
    {
        cout << "This Specialization is full of patient , Sorry you can't add this patient\n";
        cout << "**************************************************" << endl;
        return;
    }

    // put data into arrays

    if (s == 0)
    {
        status[spec][queue[spec][0]] = s;
        names[spec][queue[spec][0]] = name;
        // increament the queue
        queue[spec][0]++;
    }
    else if (s == 1)
    {
        // shift all specializaton to right and put the new patient in start
        shiftRight(spec, names[spec], status[spec]);
        names[spec][0] = name;
        status[spec][0] = s;
    }

    cout << "Patient is added." << endl;
    cout << "**************************************************" << endl;
}

void printAllPatien()
{
    for (int i = 0; i < 20; i++)
    {
        if (queue[i][0] == 0)
            continue;
        // print all patients for all specializations
        cout<< "Patients in specailzation : "<<i+1<<endl;
        for (int j=0;j<queue[i][0];j++){
            cout<< "patient number : "<<j+1<< ", name :"<<names[i][j]<<", status : "<<status[i][j]<<endl; 
        }
        cout<<endl<<endl;
    }

    // cout << "printAllPatien function" << endl;
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