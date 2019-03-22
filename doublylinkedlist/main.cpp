#include <iostream>
#include <cstdlib> // header for use of system("cls")
#include <conio.h> // header for use of getch()

using namespace std;

struct node{
     string firstName;
     string lastName;
     int age;
     string major;
     node *next = NULL;
     node *prev = NULL;
};

class Students{

private:
       node *head;
       node *tail;

public:

Students(){
       head = NULL;
       tail = NULL;
    }

    //function for adding the students.
void addStudents(){

      if(head==NULL){
        head = new node;
        cout << "Enter First Name: ";
        cin>>  head->firstName ;
        cout << "Enter Last Name: ";
        cin>>  head->lastName ;
        cout << "Enter Age: ";
        cin>> head->age;
           while(!cin.good()) //sees if the input is good (same data type)
                     {
                         cin.clear();                 //it kind of clears the input (clears the error flag)
                         cin.ignore(INT_MAX, '\n'); // skips to the next newline
                         cout<<"Please enter the 'integer value\n";
                         cout << "Enter Age: "; //Re-ask
                         cin >> head->age;
                     }
        cout << "Enter the Major: ";
        cin>> head->major;
        head->next = NULL;
        head->prev = NULL;
        tail = head;
      }
      else{
        node *ptr;
        ptr = tail;
        tail = new node;
        cout <<endl << "Enter First Name: ";
        cin>>tail->firstName ;
        cout << "Enter Last Name: ";
        cin>>tail->lastName ;
        cout << "Enter Age: ";
        cin>> tail->age;
           while(!cin.good()) //sees if the input is good (same data type)
                     {
                         cin.clear();                 //it kind of clears the input (clears the error flag)
                         cin.ignore(INT_MAX, '\n'); // skips to the next newline
                         cout<<"Please enter the 'integer value\n";
                         cout << "Enter Age: "; //Re-ask
                         cin >> tail->age;
                     }
        cout << "Enter the Major: ";
        cin>> tail->major;
        tail->prev = ptr;
        ptr->next = tail;
      }
}

void viewList(){
        int num=1;
        if(head==NULL){
            cout<< "\nList is Empty.\n";
            cout<<"\nPress 'Enter' to go back to main menu.";
        }
        else{
            node *ptr;
            ptr= head;
            cout<<"\nFollowing are the list of the Students.\n" ;
            do{
            cout<<"\nStudent number  "<<num<<"  information"<<":\n\n";
                cout<<"Firstname: " << ptr->firstName<<endl;
                cout<<"Lastname: " << ptr->lastName<<endl;
                cout<< "Age: " << ptr->age<<endl;
                cout<< "Major: " << ptr->major<<endl;
                ptr = ptr->next;
                num++;
            }while(ptr!=NULL);
            cout<<"\nPress 'Enter' to go back to main menu.";
            }
    }

void modifyList(){

    string ln;

        cout<< "\nEnter the last name of the student you want to modify."<<endl;
        cin>> ln;

            if(head==NULL){
                cout<< "\nList is empty";
                            cout<<"\nPress 'Enter' to go back to main menu.";

            }
        else{
            node *ptr;
            ptr= head;
            do{
                if(ptr->lastName==ln){
                    cout<<"\nRe-enter the information.\n"<<endl;
                    cout<<"Enter First Name: " ;
                    cin>> ptr->firstName;
                    cout<<"Enter Last Name: ";
                    cin>> ptr->lastName;
                    cout<< "Enter Age: ";
                    cin>>ptr->age;
                     while(!cin.good()) //sees if the input is good (same data type)
                     {
                         cin.clear();                 //it kind of clears the input (clears the error flag)
                         cin.ignore(INT_MAX, '\n'); // skips to the next newline
                         cout<<"Please enter the integer value\n";
                         cout << "Enter Age: "; //Re-ask
                         cin >> head->age;
                     }
                    cout<< "Enter Major: ";
                    cin>> ptr->major;
                    cout<<"\nModified Successfully\n";
                }
                ptr = ptr->next;
            }while(ptr!=NULL);
        }
        }


void deleteStudent(){
            int ans;

            delte:
            string ln;

		if (head == NULL){
			cout << "\nList is Empty!";
			            cout<<"\nPress 'Enter' to go back to main menu.";

			return;
		}

		cout<<"\nEnter the Lastname of the Student you want to delete."<< endl;
		cin>>ln;

		while (head->lastName == ln){
			node *temp = head;
			if (head->next != NULL){
				head = head->next;
				head->prev = NULL;
				delete temp;
				cout << endl << ln << " has been deleted." << endl;
			}
			else{
				head = NULL;
				tail = NULL;
				delete temp;
				cout << endl << ln << " has been deleted." << endl;
				return;
			}
		}

    node *current, *next;

		current = head;
		next = current->next;

		while (current->next != NULL){
			while (next->lastName == ln){
				node *temp;
				temp = next;
				if (next->next == NULL){
					current->next = NULL;
					tail = current;
					delete temp;
					cout << endl << ln << " has been deleted." << endl;
					return;
				}
				else{
					next = next->next;
					current->next = next;
					next->prev = current;
					delete temp;
					cout << endl << ln << " has been deleted." << endl;
				}
			}
			current = current->next;
			next = current->next;
		}
}
};

int main()
{
    int input=0,num=0;
    char ans;

    Students *s = new Students();

    while(input!=5){

            system("cls");

    cout<<"\n 1.Add Students.\n 2.View list.\n 3.Modify list.\n 4.Delete list.\n 5.Exit from the program. " << endl;
    cout<<"\n\nPlease Enter (1~5) to perform the above task. " << endl;
    cin>> input;

    switch(input){

case 1 :
    Add:
    cout<<"\n"; s->addStudents();
    cout<<"\nEntry Successful.\n" << endl;
    cout << "Do you want to add more Student? (Y/N)" << endl;
    cin>> ans;
     if(ans=='Y' || ans=='y'){
        goto Add;
     }
     else
    break;
case 2 :
     s->viewList();
     getch();
        break;
case 3:
    modify:
    s->modifyList();
    cout<<"\nDo you want to modify other? (Y/N) "<<endl;
    cin>>ans;
     if(ans=='Y' || ans=='y'){
        goto modify;
     }
     else
    break;
case 4 :
    delet:
    s->deleteStudent();
     cout<<"\nDo you want to delete other? (Y/N)"<<endl;
    cin>>ans;
     if(ans=='Y' || ans=='y'){
        goto delet;
     }
     else
    break;
case 5 :
    cout<<"\nProgram has been successfully terminated.\n";
    break;
    }
    }
    return 0;
}
