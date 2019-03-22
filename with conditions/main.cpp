#include <iostream>
#include <string>
#include <cstdlib> // header for use of system("cls")
#include <conio.h> // header for use of getch()

using namespace std;

class student {
public:
    string firstname;
         string lastname;
              int age=0;
                   string major;


void add_student() // function for the entry of the number of student
{
        string fn,ln,m;
        int a;

        cout<<endl <<"Enter First Name: ";
           cin>>fn;
             cout<<"Enter Last Name: ";
                cin>>ln;
                  cout<<"Enter Age: ";
                     cin>>a;
                      while(!cin.good()) //sees if the input is good (same data type)
                     {
                         cin.clear();                 //it kind of clears the input (clears the error flag)
                         cin.ignore(INT_MAX, '\n'); // skips to the next newline
                         cout<<"Please enter the 'integer value\n";
                         cout << "Enter Age: "; //Re-ask
                         cin >> a;
                     }
                      cout<<"Enter Major: ";
                          cin>>m;

            firstname = fn;
             lastname = ln;
                    age = a;
                      major = m;

}


void view_student() // function for the list view of the entry of the added student
{
        cout<<"First name: "<<firstname<<endl;
           cout<<"Last name: "<<lastname<<endl;
              cout<<"Age: "<<age<<endl;
                 cout<<"Major: "<<major<<endl;
}

int modify_student(string ln) // function for the modification of the entry student
{
        if(lastname==ln)
            return 1;
                   else
                      return 0;
}


void delete_student()
{
       firstname = "";
               lastname = "";
                    age=0;
                        major = "";
}

};

int main()
{
    int input=0, num=0;

    student students[10];

    while(input!=5)
     {



       string ln;
            int stnum=1;

       system("cls");

       cout<<"\n 1. Add student\n 2. View list\n 3. Modify list\n 4. Delete entry\n 5. Exit the program\n" <<endl;
          cout<<"\nEnter the number (1~5) to carry out the listed function: " << endl;
             cin>>input;

switch(input)
{

    char ans;


    case 1:

       Add:
       students[num].add_student(); num++;
           cout<<endl<<"Entry successful\n";
               cout<<"\nDo you want to add more? (Y/N): ";
                  cin>>ans;
                      if(ans=='Y'||ans=='y')
                          goto Add; // goto takes the processor to the carryout the same process.
                              else
                                  break;

    case 2:

       cout<<"\n\nFollowing are the list of all the students\n";

       for(int a =0;a<num;a++)
         {
            if(students[a].firstname!="") {
                cout<<"\nStudent number  "<<stnum<<"  information"<<":\n\n";
                    students[a].view_student();
                       stnum++;
        }

    }
    cout << "\nPress 'Enter' to go back to main menu.";
       getch();
           break;

    case 3:

        modify:
        cout<<"\nEnter the last name of the student you want to modify: ";
           cin>>ln;

        for(int b=0;b<num;b++)
        {
            if(students[b].modify_student(ln))
                {
                    students[b].add_student();
                    cout<<endl<<"Modified successfully\n";
                      break;
                }

              else if (b==num-1)
              {
                cout<<"\nNo student found\n";
                   break;
              }
        }
     //cout<<endl<<"Modified successfully\n";
         cout<<"\nDo you want to modify more? (Y/N): ";
            cin>>ans;

    if(ans=='Y'||ans=='y')
     goto modify;
    else
        break;




    case 4:

        delte:
        cout<<"\nEnter the last name of the student you want to delete: ";
           cin>>ln;

        for(int b=0;b<num;b++)
        {
            if(students[b].modify_student(ln))
              {
                  students[b].delete_student();
                  cout<<endl<<"Deleted successfully\n";
                    break;
              }

        else if (b==num-1)
         {
                cout<<"\nNo student found\n";
                break;
                }
        }

      //cout<<endl<<"Deleted successfully\n";
         cout<<"\nDo you want to delete more? (Y/N): ";
            cin>>ans;

      if(ans=='Y'||ans=='y')
        goto delte;
      else
        break;

    case 5:
        cout<<"\nProgram successfully terminated.\n\n";
        break;
}
}
return(0);
}
