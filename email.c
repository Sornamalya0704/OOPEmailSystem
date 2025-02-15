#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class Date
{
public:
    int day;
    int month;
    int year;
    void input()//check
    {
        cout<<"Enter date(1-31):";
        cin>>day;
        if (day>31 && day<1)
        {
            cout<<"Date out of range";
        }
        cout<<"Enter month(1-12):";
        cin>>month;
        if (month>12 && month<1)
        {
            cout<<"Month out of range";
        }
        cout<<"Enter year(eg 20XX):";
        cin>>year;
    }
};

class createAcc
{
public:
    string firstname;
    string lastname;
    Date DOB;
    string gender;
    string mailID;
    string pwd;
    string confirmpwd;
    void input()
    {
        cout<<"\n\n\t\tPlease enter your details for creating an account!!\n";
        cout<<"First name: ";
        cin>>firstname;
        cout<<"Last name:";
        cin>>lastname;
        cout<<"Date of birth";
        DOB.input();
        //age check
        cout<<"Gender:";
        cin>>gender;
        cout<<"Mail ID:";
        cin>>mailID;
        cout<<"Password:";//while loop
        cin>>pwd;
        cout<<"Confirm Password:";
        cin>>confirmpwd;
        if(pwd!=confirmpwd)
        {
            cout<<"Password and Confirm password not matching!";
        }
        else
        {
            ofstream file;
            file.open("mail.txt",ios::app);
            file <<mailID<<endl;
            file.close();
            ofstream file1;
            file1.open("password.txt",ios::app);
            file1 <<pwd<<endl;
            file1.close();

        }
    }
};
class loginMail
{
    public:
    string mailId, password;

    void login()
    {

        string mailline, passline;
        getchar();
        cout << "Enter your EmailId: ";
        getline(cin,mailId);
        cout << "Enter your password: ";
        getline(cin, password);
        bool is_success = false;
        ifstream mailfile("mail.txt");
        ifstream passfile("password.txt");
        while (getline(mailfile, mailline) && getline(passfile, passline))
        {
            if (mailline == mailId && passline == password)
            {
                is_success = true;
                break;
            }
        }
        mailfile.close();
        passfile.close();
        if (is_success)
        {
            cout << "Authentication successful!" << endl;
        }
        else
        {

                while(getline(mailfile,mailline))
                {
                    if (mailline!=mailId)
                {
                    string ch;
                    cout<<"This mail does not exists!\n";
                    cout<<"Do you want to create an account?(y/n):";
                    cin>>ch;
                    if (ch=="y")
                    {
                        createAcc p2;
                        p2.input();
                        login();
                    }
                    else
                    {
                        cout<<"Thank you for visiting our MAILING System!!";
                    }
                }
                }
                if(passline!=password)
                {
                    cout<<"You have entered a wrong passsword!Please try again.";
                    login();
                }
        }
    }
};
int main()
{
    int ch;
    cout<<"\t\t\t\t\tMAILING SYSTEM WELCOMES YOU!!\t\t\t\t\t";
    cout<<"\n1.Log in";
    cout<<"\n2.Create an Account";
    cout<<"\nEnter your choice(1/2):";
    cin>>ch;
    if (ch==2)
    {
        createAcc p1;
        p1.input();
        loginMail l1;
        l1.login();
    }
    else if(ch==1)
    {
        loginMail l2;
        l2.login();
    }
    return 0;
}
