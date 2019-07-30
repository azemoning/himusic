#include <fstream>
#include <iostream>
#include <limits>
#include <string>
#include <conio.h>

using namespace std;

template <typename T>
T get_input(const string &strQuery);

string get_username();
string get_password();

void save_user(const string &username, const string &password);
void login();
void register_user();
void admin_menu();
void user_menu();
void bestSeller();
void main_menu();

template <typename T>
T get_input(const string &strQuery)
{
    cout << strQuery << "\n> ";
    T out = T();

    while (!(cin >> out)) {
        cin.clear();
        cin.ignore(numeric_limits <streamsize>::max(), '\n');
        cout << "Error!" "\n";
        cout << strQuery << "\n> ";
    }

    return out;
}

string getpass(const char *prompt, bool show_asterisk=true)
{
  const char BACKSPACE=8;
  const char RETURN=13;

  string password;
  unsigned char ch=0;

  cout <<prompt<<endl;

  while((ch=getch())!=RETURN)
    {
       if(ch==BACKSPACE)
         {
            if(password.length()!=0)
              {
                 if(show_asterisk)
                 cout <<"\b \b";
                 password.resize(password.length()-1);
              }
         }
       else if(ch==0 || ch==224)
         {
             getch();
             continue;
         }
       else
         {
             password+=ch;
             if(show_asterisk)
                 cout <<'*';
         }
    }
  cout <<endl;
  return password;
}

string get_password()
{
    string password1 = getpass("Enter password : ", true);
    string password2 = getpass("Re-enter password : ");

    while (password1 != password2) {
        cout << "Error! Passwords do not match." "\n";
        password1 = getpass("Enter password : ", true);
        password2 = getpass("Enter password : ", true);
    }

    return password1;
}

string get_username()
{
    string username = get_input <string>("Please enter a username.");
    cout << "Username: \"" << username << "\"\n";

    while (get_input <string>("Confirm? [ Y | N ]") != "Y") {
        username = get_input <string>("Please enter a username.");
        cout << "Username: \"" << username << "\"\n";
    }

    return username;
}

void login()
{
    string username;
    string password;
    string match_password;
    ulang:
    cout << "Enter username : " << endl;
    cin >> username;
    string filename = "username/"+username;
    ifstream infile(filename);
    password = getpass("Enter password : ", true);
    infile >> match_password;

    if ((filename == "username/administrator") && (match_password == password))
    {
        admin_menu();
    }

    else if (match_password == password)
    {
        bestSeller();
    }

    else
    {
        cout << "Incorrect username or password, please login again.\n";
        goto ulang;
    }
}

void main_menu()
{
    system("cls");
    int choice = get_input <int>(
        "\tWelcome to HiMusic" "\n\n"
        "Hello, Would you like to log in or register?" "\n\n"
        "[1] Login" "\n"
        "[2] Register" "\n"
        "[3] Exit");

    switch (choice)
    {
    case 1:
        login();
        break;
    case 2:
        register_user();
        break;
    case 3:
        break;
    }
}

void register_user()
{
    string username = get_username();
    string password = get_password();
    save_user(username, password);
    cout << "User created succesfully!\n\n";

    if (get_input <string> ("Do you want to login? [ Y | N ]") == "Y")
    {
        system("cls");
        login();
    }
}

void save_user(const string &username, const string &password)
{
    string filename = "username/"+username;//+".txt";
    ofstream file(filename);
    file << password << "\n";
}
