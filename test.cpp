#include<iostream>
#include<string>
#include<map>
#include<conio.h>
#include<fstream>
using namespace std;
struct user
{
  string username,userpassword;
};

void hidePassword(string& password){
  char ch;
  password = "";
  while ((ch = _getch()) != 13)
  {
    if (ch == 8)
    {
      if (password.length()>0)
      {
        password.pop_back();
        cout << "\b \b";
      }
      
    }else{
      password += ch;
      cout << "#";
    }
    
  }
}
void login(){
  ifstream file("server.txt");
  string line;
  bool found = false;
  string name,pass;
  cout << "\t\tEnter username:";
  cin >> name;
  cout << "\t\tEnter password:";
  hidePassword(pass);
  while (getline(file,line))
  {
    if (line.find(name) != string::npos)
    {
      if (line.find(pass) != string::npos)
      {
        found = true;
        break;
      } 
    }
  }
  if (found)
  {
    cout << "\nsuccessfully login"<< endl;
    file.close();
    return;
  }else{
    system("cls");
    cout << "user and password not valid.....!" << endl;
    login();
  }

  
}
void regitration(){
  ofstream file("server.txt",ios::app);
  user us;
  cout << "Enter username\t\t:";
  cin >> us.username;
  cout << "Enter password\t\t:";
  hidePassword(us.userpassword);
  file << us.username << "\t" << us.userpassword << endl;
  file.close();
}
int main(){
  cout << "\t\t____________________________________________________"<< endl;
  cout << "\t\t                     Wellcome                       "<< endl;
  cout << "\t\t____________________________________________________"<< endl;
  cout << "\t\t____ 1) login                                       "<< endl;
  cout << "\t\t____ 2) regitration                                 "<< endl;
  cout << "\t\t____ 3) exit                                        "<< endl;
  int opt;
  cout << "\t\tYou'r selection => ";
  cin >> opt;
  switch (opt)
  {
    case 1:
      login();
      break;
    case 2:
      regitration();
      break;
    case 3:
      cout << "Bye Bye..........!";
      return 0;
      break;
    
    default:
      system("cls");
      cout <<"You need to select option in avobe"<<endl;
      main();
      break;
  }

}