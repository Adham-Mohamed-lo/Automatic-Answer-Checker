#include <iostream>
#include <cmath>
#include <string>
#include <string.h>
#include <fstream>
#include <iomanip>
using namespace std;

string ret;

void registration()
{
    string user, password;
    cout << "select a username :";             //enter username
    getline(cin >> ws, user);

    cout << "select a password :";             //enter password
    getline(cin >> ws, password);

    ofstream mail;                                               //open file to write              
    mail.open("mails.txt", ios::app | ios::out);

    mail << "username: " << user << endl << "password: " << password << endl; //the data is saved into our file

    cout << endl;
    mail.close();
    cout << "successfully registered\n\n";
}
string login()
{
    string user, password;
    string u, p, Q;                                  // comparison string

    cout << "Enter your username : ";
    getline(cin >> ws, user);


    cout << "Enter your password : ";
    getline(cin >> ws, password);


    //ifstream for reading the file
    ifstream mail("mails.txt", ios::app);
    ifstream admin("admin.txt", ios::app);         //here mails.txt where our data will be saved

    getline(admin, u);
    getline(admin, p);


    if (u == "username: " + user && p == "password: " + password)
    {
        ret = "admin";
        return ret;
    }
    else
    {
        while (getline(mail, u), getline(mail, p))
        {

            if (u == "username: " + user && p == "password: " + password)
            {
                ret = "student";
                return ret;
            }

        }
    }
    admin.close();
    mail.close();
    ret = "wrong";
    return ret;
}
void Examnewfill()
{
    ofstream FCquestions;
    ofstream FMCQquestions;
    ofstream Fanswers;

    FCquestions.open("Cquestions.txt");
    FMCQquestions.open("MCQquestions.txt");
    Fanswers.open("Answers.txt");

    int Q = 0, x = 0;
    string question, answer;

    cout << "choose questions type\n1)complete\n2)MCQ\n";             //choose complete or mcq
    cin >> Q;
    cout << endl;
    if (Q == 1)
    {
        while (x != 1)
        {
            cout << "enter the questions\n";
            getline(cin >> ws, question);
            FCquestions << question << endl;

            cout << "enter the answer\n";
            getline(cin >> ws, answer);
            Fanswers << answer << endl;

            cout << endl << "If you need to stop inserting questions\nPress 1)done\nPress 2)continue\n";
            cin >> x;
            if (x == 1 || x == 2)
            {
                cout << endl;
            }
            else
            {
                cout << endl << "invalid\nchoise (1) activated" << endl;
                break;
            }
        }
    }
    else if (Q == 2)
    {
        while (x != 1)
        {
            string a, b, c, d;
            cout << "enter the questions\n";
            getline(cin, question);
            FMCQquestions << question << endl;

            cout << "enter the choises\n";
            cout << "a)";
            getline(cin >> ws, a);
            cout << "b)";
            getline(cin >> ws, b);
            cout << "c)";
            getline(cin >> ws, c);
            cout << "d)";
            getline(cin >> ws, d);
            FMCQquestions << "a)" << a << endl << "b)" << b << endl << "c)" << c << endl << "d)" << d << endl;

            cout << "enter the answer(a,b,c,d)\n";
            getline(cin >> ws, answer);
            Fanswers << answer << endl;

            cout << "If you need to stop inserting questions\nPress 1)done\nPress 2)continue\n";
            cin >> x;
            if (x == 1 || x == 2)
            {
                cout << endl;
            }
            else
            {
                cout << endl << "invalid\nchoise (1) activated" << endl;
                break;
            }
        }
    }
    cout << endl << "thank you";

    FCquestions.close();
    FMCQquestions.close();
    Fanswers.close();
}
void Examadd()
{
    ifstream FCquestions;
    ifstream FMCQquestions;
    ifstream Fanswers;

    FCquestions.open("Cquestions.txt", ios::app);
    FMCQquestions.open("MCQquestions.txt", ios::app);
    Fanswers.open("Answers.txt", ios::app);

    int  x = 0;
    string question, answer, CQ, MQ;

    getline(FCquestions, CQ);
    getline(FMCQquestions, MQ);


    if (CQ.empty() == 1 && MQ.empty() == 1)
    {
        cout << "no previous exams" << endl;
    }
    else
    {
        if (CQ.empty() == 0 && MQ.empty() == 1)
        {
            ofstream FCquestions;
            ofstream Fanswers;

            FCquestions.open("Cquestions.txt", ios::app);
            Fanswers.open("Answers.txt", ios::app);

            while (x != 1)
            {
                cout << "enter the questions\n";
                getline(cin >> ws, question);
                FCquestions << question << endl;

                cout << "enter the answer\n";
                getline(cin >> ws, answer);
                Fanswers << answer << endl;

                cout << endl << "If you need to stop inserting questions\nPress 1)done\nPress 2)continue\n";
                cin >> x;
                if (x == 1 || x == 2)
                {
                    cout << endl;
                }
                else
                {
                    cout << endl << "invalid\nchoise (1) activated" << endl;
                    break;
                }
            }

            FCquestions.close();
            Fanswers.close();
        }
        else if (CQ.empty() == 1 && MQ.empty() == 0)
        {
            ofstream FMCQquestions;
            ofstream Fanswers;

            FMCQquestions.open("MCQquestions.txt", ios::app);
            Fanswers.open("Answers.txt", ios::app);

            while (x != 1)
            {
                string a, b, c, d;
                cout << "enter the questions\n";
                getline(cin >> ws, question);
                FMCQquestions << question << endl;

                cout << "enter the choises\n";
                cout << "a)";
                getline(cin >> ws, a);
                cout << "b)";
                getline(cin >> ws, b);
                cout << "c)";
                getline(cin >> ws, c);
                cout << "d)";
                getline(cin >> ws, d);
                FMCQquestions << "a)" << a << endl << "b)" << b << endl << "c)" << c << endl << "d)" << d << endl;

                cout << "enter the answer(a,b,c,d)\n";
                getline(cin >> ws, answer);
                Fanswers << answer << endl;;

                cout << "If you need to stop inserting questions\nPress 1)done\nPress 2)continue\n";
                cin >> x;
                if (x == 1 || x == 2)
                {
                    cout << endl;
                }
                else
                {
                    cout << endl << "invalid\nchoise (1) activated" << endl;
                    break;
                }
            }

            FMCQquestions.close();
            Fanswers.close();
        }
    }

    cout << endl << "thank you";

    FCquestions.close();
    FMCQquestions.close();
    Fanswers.close();
}
void Exam()
{
    ifstream FCquestions;
    ifstream FMCQquestions;
    ifstream Fanswers;

    FCquestions.open("Cquestions.txt", ios::app);
    FMCQquestions.open("MCQquestions.txt", ios::app);
    Fanswers.open("Answers.txt", ios::app);

    int marks = 0, i = 0, num = 0;
    string MQ, MQ1, MQ2, MQ3, MQ4, MQ5, CQ, CQ1, A, Sanswer[1000];

    getline(FCquestions, CQ);
    getline(FMCQquestions, MQ1);

    if (CQ.empty() == 0 && MQ1.empty() == 1)
    {
        while (CQ.empty() == 0)
        {
            int  i = 0;
            cout << CQ << endl << endl;
            cout << "answer:";
            getline(cin >> ws, Sanswer[i]);
            cout << endl;

            getline(Fanswers, A);
            if (A == Sanswer[i])
            {
                marks++;
                i++;
                num++;
            }
            else
            {
                i++;
                num++;
            }
            getline(FCquestions, CQ);
        }
    }
    else if (CQ.empty() == 1 && MQ1.empty() == 0)
    {

        while (MQ1.empty() == 0)
        {
            getline(FMCQquestions, MQ2);
            getline(FMCQquestions, MQ3);
            getline(FMCQquestions, MQ4);
            getline(FMCQquestions, MQ5);
            cout << MQ1 << endl << endl << MQ2 << endl << MQ3 << endl << MQ4 << endl << MQ5 << endl << endl;

            cout << "choose the answer:";
            getline(cin >> ws, Sanswer[i]);
            cout << endl;

            getline(Fanswers, A);
            if (A == Sanswer[i])
            {
                marks++;
                i++;
                num++;
            }
            else
            {
                i++;
                num++;
            }
            getline(FMCQquestions, MQ1);
        }
    }

    FCquestions.close();
    FMCQquestions.close();
    Fanswers.close();
    cout << "\nyour mark is " << marks << "/" << num << endl;
}

int main()
{
    int choose;
    cout << "1) Register " << endl << "2) Login " << endl;
    cin >> choose;
    cout << endl;

    if (choose == 1)
    {
        registration();
        main();                                                           //return here main because then again we going to logged in
    }
    else if (choose == 2)
    {
        int tries = 1;
        while (tries <= 3)
        {
            login();
            if (ret == "admin")                                                       
            {
                cout << "Successfully Logged in\n\n";
                break;
            }
            else if (ret == "student")
            {
                cout << "Successfully Logged in\n\n";
                break;
            }
            else if (ret == "wrong" && tries <= 2)
            {
                cout << "Wrong username or password!\nPlease try Again\n";
                tries++;
            }
            else
            {
                cout << "Invalid: login is blocked";
                tries++;
            }
        }

    }
    else
    {
        cout << "invalid" << endl;
        main();
    }

    if (ret == "admin")
    {
        ret = "";
        cout << "Hello admin\n\nDo you want to\n1)Add questions to the previous exam\n2)Enter new exam\n";
        cin >> choose;
        cout << endl;

        if (choose == 1)
        {
            Examadd();
        }
        else if (choose == 2)
        {
            Examnewfill();
        }
    }
    if (ret == "student")
    {
        ret = "";
        int L = 0;
        cout << "1)Start exam" << endl;
        cin >> L;
        cout << endl;
        if (L == 1)
        {
            Exam();
            cout << "\nthank you";
        }
        else
        {
            cout << "\nthank you";
        }
    }
}
