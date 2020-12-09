#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<conio.h>
#include<iomanip>
#include<string>
#include <cstring>
#include <string.h>
using namespace std;
int sum=0;
int cart_count=0;
int cart_op=0;
string inputstring()
{
	string str;
	int c=0;
	loop:
		cout<<"Enter name*: ";
	cin>>str;
	for(int i=0;i<str.length();i++)
	{
		if(isalpha(str[i])||str[i]==' ')
		{
			c=1;
		}
		else
		c=0;
	}
	if(c==0)
	{
		cout<<"number detected in name !!!!!"<<endl<<"Enter your name again!!!!!!!!";
		goto loop;
	}
	else
	{
		return str;
	}
}
string passwordinput()
{
    char pass[32];//to store password.
    int i = 0;
    char a;//a Temp char
    for(i=0;;)//infinite loop
    {
        a=getch();//stores char typed in a
        if((a>='a'&&a<='z')||(a>='A'&&a<='Z')||(a>='0'&&a<='9'))
            //check if a is numeric or alphabet
        {
            pass[i]=a;//stores a in pass
            ++i;
            cout<<"*";
        }
        if(a=='\b'&&i>=1)//if user typed backspace
            //i should be greater than 1.
        {
            cout<<"\b \b";//rub the character behind the cursor.
            --i;
        }
        if(a=='\r')//if enter is pressed
        {
            pass[i]='\0';//null means end of string.
            i=0;
            break;//break the loop
        }
    }
    return pass;
}
class person
{
	protected:
		string name,password,username,email;
	public:
		virtual bool login(string user,string pass)=0;
		
};
class employee:public person
{
	public:
	int count1;//for checking wrong login credentiails
    bool login(string user,string pass)//login function for customer to gain access to market
    {
        int count;
        string n,u,e,p;
        system("cls");

		ifstream input("database.txt");
		while(input>>n>>u>>e>>p)
		{
			if(u == user && p == pass || e==user && p==pass)//check if usenamer or email and password match from file
			{
				count=1;
				name=n;
		
				if(count==1)	
				break;
				system("cls");
			}
		}
		input.close();
		if(count==1)
		{
			cout<<"\t\t\t\t*****************************************************************************************\n";
			cout<<"\n\t\t\t\t\t\t\t\tHello "<<n<<"\n\t\t\t\t\t\t\t\tLOGIN SUCESS\n\t\t\t\t\t\t\t\tWe're glad that you're here.\n\n";
			cout<<"\t\t\t\t*****************************************************************************************\n";
		}
		else
		{
			cout<<"\nLOGIN ERROR\nPlease check your username and password\n";
			cout<<"Enter USERNAME OR Email: ";
			cin>>user;
			cout<<"Enter password: ";
			pass=passwordinput();
			count1++;
			if(count1==5)//check if five wrong login credentials are given
			{
				cout<<"Too many times wrong credentials program will now close!!!!!!!!!!!!!!!!!!!!";
				exit(0);
				input.close();
			}
			login(user,pass);//call agian login if username or email or password is wrong 
		}
	}	
};
class manager:public employee
{
	public:
	char chr;
	int count1;//for checking wrong login credentiails
    bool login(string user,string pass)//login function for customer to gain access to market
    {
    	string scode;
    	char choice;
    	loop:
    	cout<<"Enter manager special code: ";
    	cin>>scode;
    	if(scode!="Man123")
    	{
    		cout<<"Not  right code!!!!!!!!!!!!!!!!!!!"<<endl;
    		loop2:
    		cout<<"Do you want to enter again(y for yes,N for no): ";
    		cin>>choice;
    		if(choice=='Y'||choice=='y')
    		{
    			goto loop;
			}
			else if(choice=='n'||choice=='N')
			{
				return 0;				
			}
			else
			{
				cout<<"Wrong input detected!!!!!!!"<<endl<<"Please Enter correctly!!!!!!!!!! "<<endl;
				goto loop2;
			}
		}
        int count;
        string n,u,e,p;
        system("cls");

		ifstream input1("manager.txt");
		while(input1>>n>>u>>e>>p)
		{
			if(u == user && p == pass || e==user && p==pass)//check if usenamer or email and password match from file
				{
					count=1;
					if(count==1)
					break;
					system("cls");
				}
		}	
		input1.close();
		if(count==1)
		{	cout<<"\t\t\t\t*****************************************************************************************\n";
			cout<<"\n\t\t\t\t\t\t\t\tHello "<<"\n\t\t\t\t\t\t\t\tManager: "<<n<<endl<<endl;
			cout<<"\t\t\t\t*****************************************************************************************\n";
			return true;
		}
		else
		{
			count1++;
			if(count1==5)//check if five wrong login credentials are given
				{
					cout<<"Too many times wrong credentials program will now close!!!!!!!!!!!!!!!!!!!!";
					input1.close();
					exit(0);
					
				}
			char choice2;//for asking choice of entering credentials again
			cout<<"\nLOGIN ERROR\nPlease check your username and password\n";
			cout<<"Do you want to enter again!!!!!!!"<<endl<<"(Y for Yes,N for no)";
			cin>>choice2;
			if(choice2=='Y'||choice2=='y')
			{
				cout<<"Enter USERNAME OR Email: ";
				cin>>user;
				cout<<"Enter password: ";
				pass=passwordinput();
				login(user,pass);//call agian login if username or email or password is wrong 
			}
			else if(choice2=='N'||choice2=='n')
			{
				return 0;
			}
			else
			{
				cout<<"Wrong input detected!!!!!!"<<endl;
				cout<<"Please Enter carefully!!!!!!!!!!!"<<endl;
			}
		}
	}
	int Report(string name, int price, int id, int quantity)
	{
		sum=sum+1;
		if(sum>1)
		{
			ofstream file("Report.txt", ios::app);
			file<<"\n\nItem Name: "<<name<<endl<<"Item Id: "<<id<<endl<<"Item Price: "<<price<<endl<<"Item Quantity: "<<quantity; 
			file.close();
			return 0;
		}
		else if(sum==1)
		{
			ofstream file("Report.txt", ios::trunc);
			file<<"Item Name: "<<name<<endl<<"Item Id: "<<id<<endl<<"Item Price: "<<price<<endl<<"Item Quantity: "<<quantity; 
			file.close();
			return 0;
		}
	}
};
class customer:public person
{
	public:
		int count1;//for checking wrong login credentiails
		signup()
		{
				ifstream file("database.txt");
				string n,u,e;
				string p;
				cout<<endl<<endl<<"****************************************************************************************************"<<endl<<endl;
				cout<<"\t\t\tfield marked (*) with this are required!!!!!!!!!!"<<endl<<endl;
				cout<<"Enter e-mail*(xyz123@abc.com): ";
				cin>>email;
				cout<<endl<<endl;
				cout<<"Enter name*: ";
				name=inputstring();
				cout<<endl<<endl;
				cout<<"Enter username *: ";
				cin>>username;
				cout<<endl<<endl;
				cout<<"Enter password*: ";
				password=passwordinput();
				cout<<endl<<endl;
				cout<<"**************************************************************************************************"<<endl<<endl;
				cout<<"Press any key to continue...................................";
				getch();
				system("cls");
				file.clear();
				file.seekg(0, ios::beg);
				while(file>>n>>u>>e>>p)
				{
					if(email==e)
					{
						cout<<"Enter new email!!!"<<endl;
						cin>>email;
						int c=0;
						c=1;
						if(c=1)
						{
							file.clear();
							file.seekg(0, ios::beg);
						}
						
					}
					if(username==u)
					{
						cout<<"Enter new username: ";
						cin>>username;
						int c =0;
						c=1;
						if(c=1)
						{
							file.clear();
							file.seekg(0, ios::beg);
						}
					}
				}
				file.close();
				ofstream file1("database.txt",ios::app);
				file1<<name<<endl;
				file1<<username<<endl;
				file1<<email<<endl;
				file1<<password<<endl;
				cout<<endl<<endl<<"*********************************************************************************************************";
				cout<<endl<<endl<<"\t\t\t\t\tSIGNUP IS SUCCESSFUL!!!!!!!!!!!!!!!";
				cout<<endl<<endl<<"*********************************************************************************************************";
				cout<<"Press any key to continue........................................";
				file1.close();
				
		}
   		bool login(string user,string pass)//login function for customer to gain access to market
    	{
        int count;
        string n,u,e,p;
        system("cls");

		ifstream input("database.txt");
		while(input>>n>>u>>e>>p)
		{
			if(u == user && p == pass || e==user && p==pass)//check if usenamer or email and password match from file
			{
				count=1;
				if(count==1)	
				break;
				system("cls");
				return true;
			}
		}
		input.close();
		if(count==1)
		{
			cout<<"\t\t*****************************************************************************************\n";
			cout<<"\n\t\t\t\t\t\tHello "<<n<<"\n\t\t\t\t\t\tLOGIN SUCESS\n\t\t\t\t\t\tWe're glad that you're here.\n\n";
			cout<<"\t\t*****************************************************************************************\n";
		}
		else
		{
			count1++;
			if(count1==5)//check if five wrong login credentials are given
			{
					cout<<"Too many times wrong credentials program will now close!!!!!!!!!!!!!!!!!!!!";
					exit(0);
					input.close();
			}
			char choice2;//for asking choice of entering credentials again
			cout<<endl<<endl<<"**************************************************************************************"<<endl<<endl;
			cout<<"\nLOGIN ERROR\nPlease check your username and password\n\n\n";
			loop2:
			cout<<"Do you want to enter again!!!!!!!"<<endl<<"(Y for Yes,N for no): ";
			cin>>choice2;
			system("cls");
			if(choice2=='Y'||choice2=='y')
			{
				cout<<endl<<endl<<"***********************************************************************************"<<endl<<endl;
				cout<<"Enter USERNAME OR Email (xyz123@abc.com): ";
				cin>>user;
				cout<<endl<<endl;
				cout<<"Enter password: ";
				pass=passwordinput();
				cout<<endl<<endl<<"***********************************************************************************";
				cout<<endl<<endl<<"Press any key to continue ..................................";
				getch();
				login(user,pass);//call agian login if username or email or password is wrong 
			}
			else if(choice2=='N'||choice2=='n')
			{
				return false;
			}
			else
			{
				cout<<"Wrong input detected!!!!!!"<<endl;
				cout<<"Please Enter carefully!!!!!!!!!!!"<<endl;
				goto loop2;
			}
		}
	}
	void AddToCart(string name, int price, int id, int quantity)
	{
		system("cls");
		int tprice;
		tprice=quantity*price;//for calculating the price of all the products
		cart_count=cart_count+1;
		if(cart_count>1)
		{	
		ofstream out;
	  	out.open("Cart.txt",ios::app);//if there is some data in the file it will add more data from the end
	  	out<<name<<endl;
		out<<id<<endl;
		out<<tprice<<endl;
		out<<quantity<<endl;
		out.close();
		}
		else if(cart_count==1)
		{
		ofstream out;
	  	out.open("Cart.txt",ios::trunc);//if there is some data in the file it will add more data from the end
	  	out<<name<<endl;
		out<<id<<endl;
		out<<tprice<<endl;
		out<<quantity<<endl;
		out.close();
		}
  	}
  	int ShowCart()
  	{
  		system("cls");
  		cout<<"line 1 contain the name of product\nline 2 contain the product id\nline 3 contain the price of product\nline 4 contain the quantity\n\n";	
	  	char chr;
	  	ifstream i("Cart.txt");	
		while(i)
		{
			i.get(chr);
			cout<<chr;
		}
		i.close();
		getch();
  	
  		return 0;
  	}
  	int update_report(string del)
  	{
  		int i, c=0, d=0, line_no = 1;
		char c1;
		string line;
		
		ifstream in("Report.txt");
		if (!in.is_open()) 
		{
		    cout << "Input file failed to open\n";
		}
		ofstream out("temp.txt");
		while (getline(in, line)) 
		{
			c=c+1;
		    if (line != del)
		    {
		        out << line << endl;
		    }
		    if(line==del)
		    {
		    	d=c;
			}
		}
		in.close();
		out.close();
		remove("Report.txt");
		rename("temp.txt", "Report.txt");
		
		ifstream is("Report.txt"); 
		ofstream ofs; 
		ofs.open("temp.txt", ofstream::out);  
		    
		while (is.get(c1)) 
		{  
		    if (c1 == '\n') 
		    line_no++; 
		    if ( line_no != (d-1) && line_no != (d+1) && line_no != d ) 
		    {	ofs << c1; 	 }
		}  
		ofs.close(); 
	    is.close(); 
	    remove("Report.txt");
	    rename("temp.txt", "Report.txt");
  		
  		return 0;
	}
  	int update_cart()
	{
		int i, c=0, d=0, line_no = 1;
		string del;
		char c1;
		string line;
		
		ifstream in("Cart.txt");
		if (!in.is_open()) 
		{
		    cout << "Input file failed to open\n";
		}
		ofstream out("temp.txt");
		YES:
		cout << "Please Enter the id No of product to delete\nIf you dont remember the id of your product, So please enter any number which is greater than 500 or less than 600\nType: " << endl;
		cin >> del;
		if(del=="20"|| del=="30"||del=="40"||del=="50"||del=="60"||del=="70"||del=="80"||del=="90"||del=="100"||del=="110"||del=="120"|| del=="130"||del=="140"||del=="150"||del=="160"||del=="170"||del=="180"||del=="190"||del=="200"||del=="210"||del=="220"|| del=="230"||del=="240"||del=="250"||del=="260"||del=="270"||del=="280"||del=="290"||del=="300"||del=="310")
		{
			while (getline(in, line)) 
			{
				c=c+1;
			    if (line != del)
			    {
			        out << line << endl;
			    }
			    if(line==del)
			    {
			    	d=c;
				}
			}
			in.close();
			out.close();
			remove("Cart.txt");
			rename("temp.txt", "Cart.txt");
			//process2:
			ifstream is("Cart.txt"); 
		    ofstream ofs; 
		    ofs.open("temp.txt", ofstream::out);  
		    
			while (is.get(c1)) 
			{  
			    if (c1 == '\n') 
			    line_no++; 
			    if ( line_no != (d-1) && line_no != (d+1) && line_no != d ) 
			    {	ofs << c1; 	 }
			}  
			ofs.close(); 
		    is.close(); 
		    remove("Cart.txt");
		    rename("temp.txt", "Cart.txt");
		    
		    update_report(del);
		    
		    cout<<"Successfully done!\npress any key to continue";
		    getch();
		}
		else 
		{
			system("cls");
			cout<<"Wrong Product id!!\nIf you dont remember the product ids, So please See the chart given below\n";
			char chr;
		  	ifstream i("ProductIDs.txt");	
			while(i)
			{
				i.get(chr);
				cout<<chr;
			}
			i.close();
			getch();
			system("cls");
			goto YES;
		}
		return 0; 
	}
	void buying()
	{
	int op, quantity, cat1, com, op2, op3, op4, op5, op6, data[3], price, id;
	char chr, line[15];
	
	MAIN://kahin bhi user chahay main menu pe ana to by using goto function yha tak paunch skta hai
	system("cls"); 
	cout<<"Hi! Sir, How Are You?\n\nPlease Select Your Category\n1)Electronic Devices\n2)Home Appliances\n3)Fashion\n4)Health And Beauty\n5)Sports\n6)Watches\n\n7)-> LOGOUT\nType your Option: ";
	cin>>op;
	if(op != 1 && op != 2 && op != 3 && op != 4 && op != 5 && op != 6 && op != 7 )
	{
		cout<<"Wrong input,  please try again";
		getch();
		system("cls");
		goto MAIN;
	}
	if(op==1)
	{
		A:
		system("cls");
		cout<<"1)Mobile\n2)Laptops\n\n0) Go back\nType: ";
		cin>>cat1;
		if(cat1!=1 && cat1 !=2 && cat1!=3 && cat1!=0)
		{
			cout<<"Wrong input Try Again";
			goto A;
		}
		if(cat1==0)
		{
			system("cls");
			goto MAIN;
		}
		if(cat1==1)
		{
			B:
			system("cls");
			cout<<"Please Choose Company\n1)Samsung\n2)IPhone\n\n0) Go to Home Page\n3)Go BackType: ";
			cin>>com;
			if(com!=1 && com !=2 && com!=3 && com!=0)
			{
				cout<<"Wrong input Try Again";
				goto B;
			}
			if(com==0)
			{
				system("cls");
				goto MAIN;
			}
			if(com==3)
			{
				system("cls");
				goto A;
			}
			if(com==1)
			{
				BACK://user jab bhi back ana chahy to yaha askta hai goto ke zariyay
				system("cls");
				cout<<"Please Choose your Favourite One:\n1)Samsung Note 8\n2)Samsung Galaxy A40\n\n0-> For Go Home Page\n3) Go Back\nType: ";
				cin>>op2;
				if(op2!=1 && op2 !=2 && op2 !=3 && op2 !=0)
				{
					cout<<"Wrong input Try Again";
					goto BACK;
				}
				if(op2==0)
				{
					system("cls");
					goto MAIN;
				}
				if(op2==3)
				{
					system("cls");
					goto B;
				}
				if(op2==1)//jis ko select kia uski file open hogi
				{
					system("cls");
					cout<<"Features: \n\n";
					ifstream i("Galaxy Note8.txt");	
					while(i)//read data from file
					{
						i.get(chr);
						cout<<chr;
					}
					i.close();
					cout<<"\n\nPress any key to continue!!";
					getch();
					system("cls");
					C:
					cout<<"Do you Want to Buy this Product?\n1)Yes\n2)No\n\n3)Go Back\n4)Go to HomePage\nType: ";
					cin>>op3;
					if(op3!= 1 && op3!= 2 && op3!=3 && op3!=4)
					{
						system("cls");
						cout<<"Wrong input, try again";
						getch();
						system("cls");
						goto C;
					}
					else if(op3==3)
					{
						goto BACK;
					}
					else if(op3==4)
					{
						system("cls");
						goto MAIN;
					}
					else if(op3==1)
					{
						cout<<"Quantity: ";
						cin>>quantity;
						cout<<"Thankyou, Sir!";
						getch();
						ifstream i("Galaxy Note8.txt");	
						for (int j = 1; j < 4; j++)
					    {
					    	i.ignore(7);//file me naam, id, aur price se pehlay 7 characters(include spaces) ignoure kiay takay sirf naam hi uthay file se
					    	if (j == 3)//j==3 means 3rd line jis may product ka naam hai wo uthaega
						    {
								i.read(line, 12);//product ka naam file me agya	
							}
							else
							{
						    	i>>data[j];//baqi dono lines means j=1, j=2 pe id aur price hai wo uthalay:
							}
						}
						i.close();
						price=data[1];//line 1 jokay data[1] me ayi, wo price hai;
						id=data[2];//line 2 jokay data[2] me ayi, wo id hai;
						string name(line);//naam ko char[] se string me convert krdia;
						manager m;
						m.Report(name, price, id, quantity);
						AddToCart(name, price, id, quantity);//function calling;
						system("cls");
						cout<<"Do You Want to Continue Shopping?\n1) Yes\n2) No\nType: ";
						cin>>op6;
						if(op6==1)
						{
							goto MAIN;
						}
						else if(op6==2)
						{
							D:
							system("cls");
							cout<<"1) See the Cart\n2) Go for bill\n3) Delete An item from cart\nType: ";
							cin>>cart_op;
							if(cart_op==1)
							{
								ShowCart();
								goto D;
							}
							else if(cart_op==2)
							{
//								Billing();
							}
							else if(cart_op==3)
							{
								update_cart();
								goto D;
							}
							else
							{
								cout<<"wrong input, try again";
								getch();
								system("cls");
								goto D;
							}
						}
					}
					else if(op3==2)
					{
						E1:
						system("cls");
						cout<<"1)Go back\n2)Go MainPage\nType: ";
						cin>>op4;
						if(op4==1)
						{
							goto BACK;//go back by using goto
						}
						else if(op4==2)
						{
							goto MAIN;// go main by using goto
						}
						else 
						{
							cout<<"wrong input, try again";
							getch();
							system("cls");
							goto E1;
						}
					}
				}
				else if(op2==2)
				{
					system("cls");
					cout<<"Features: \n\n";
					ifstream i("Galaxy A40.txt");	
					while(i)//read data from file
					{
						i.get(chr);
						cout<<chr;
					}
					i.close();
					cout<<"\n\nPress any key to continue!!";
					getch();
					system("cls");
					C2:
					cout<<"Do you Want to Buy this Product?\n1)Yes\n2)No\n\n3)Go Back\n4)Go to HomePage\nType: ";
					cin>>op3;
					if(op3!= 1 && op3!= 2 && op3!=3 && op3!=4)
					{
						system("cls");
						cout<<"Wrong input, try again";
						getch();
						system("cls");
						goto C2;
					}
					else if(op3==3)
					{
						goto BACK;
					}
					else if(op3==4)
					{
						system("cls");
						goto MAIN;
					}
					else if(op3==1)
					{
						cout<<"Quantity: ";
						cin>>quantity;
						cout<<"Thankyou, Sir!";
						getch();
						ifstream i("Galaxy A40.txt");	
						for (int j = 1; j < 4; j++)
					    {
					    	i.ignore(7);//file me naam, id, aur price se pehlay 7 characters(include spaces) ignoure kiay takay sirf naam hi uthay file se
					    	if (j == 3)//j==3 means 3rd line jis may product ka naam hai wo uthaega
						    {
								i.read(line, 10);//product ka naam file me agya	
							}
							else
							{
						    	i>>data[j];//baqi dono lines means j=1, j=2 pe id aur price hai wo uthalay:
							}
						}
						i.close();
						price=data[1];//line 1 jokay data[1] me ayi, wo price hai;
						id=data[2];//line 2 jokay data[2] me ayi, wo id hai;
						string name(line);//naam ko char[] se string me convert krdia;
						manager m;
						m.Report(name, price, id, quantity);
						AddToCart(name, price, id, quantity);//function calling;
						system("cls");
						cout<<"Do You Want to Continue Shopping?\n1) Yes\n2) No\nType: ";
						cin>>op6;
						if(op6==1)
						{
							goto MAIN;
						}
						else if(op6==2)
						{
							D2:
							system("cls");
							cout<<"1) See the Cart\n2) Go for bill\n3) Delete An item from cart\nType: ";
							cin>>cart_op;
							if(cart_op==1)
							{
								ShowCart();
								goto D2;
							}
							else if(cart_op==2)
							{
//								Billing();
							}
							else if(cart_op==3)
							{
								update_cart();
								goto D2;
							}
							else 
							{
								cout<<"wrong input, try again";
								getch();
								system("cls");
								goto D2;
							}
						}
					}
					else if(op3==2)
					{
						E2:
						system("cls");
						cout<<"1)Go back\n2)Go MainPage\nType: ";
						cin>>op4;
						if(op4==1)
						{
							goto BACK;
						}
						else if(op4==2)
						{
							goto MAIN;
						}
						else 
							{
								cout<<"wrong input, try again";
								getch();
								system("cls");
								goto E2;
							}
					}
				}
				else if(op2==0)
				{
					goto MAIN;
				}
				else 
				{
				cout<<"wrong input, try again";
				getch();
				system("cls");
				goto BACK;
				}
			}
			else if(com==2)
			{
				BACK1:
				system("cls");	
				cout<<"Please Choose your Favourite One\n1)IPhone7\n2)IPhone8\n\n0->For Go Back\n3)Go to Home Page\nType: ";
				cin>>op2;
				if(op2!= 1 && op2 != 2 && op2 != 3 && op2!= 0)
				{
					system("cls");
					cout<<"Wrong input, try again";
					getch();
					system("cls");
					goto BACK1;
				}
				if(op2==3)
				{
					goto MAIN;
				}
				if(op2==0)
				{
					goto B;
				}
				if(op2==1)
				{
					system("cls");
					cout<<"Features: \n\n";
					ifstream i("Iphone7.txt");	
					while(i)//read data from file
					{
						i.get(chr);
						cout<<chr;
					}
					i.close();
					cout<<"\n\nPress any key to continue!!";
					getch();
					system("cls");
					C3:
					cout<<"Do you Want to Buy this Product?\n1)Yes\n2)No\n\n3)Go Back\n4)Go to HomePageType: ";
					cin>>op3;
					if(op3!= 1 && op3!= 2 && op3!=3 && op3!=4)
					{
						system("cls");
						cout<<"Wrong input, try again";
						getch();
						system("cls");
						goto C3;
					}
					else if(op3==3)
					{
						goto BACK1;
					}
					else if(op3==4)
					{
						system("cls");
						goto MAIN;
					}
					else if(op3==1)
					{
						cout<<"Quantity: ";
						cin>>quantity;
						cout<<"Thankyou, Sir!";
						getch();
						ifstream i("Iphone7.txt");	
						for (int j = 1; j < 4; j++)
					    {
					    	i.ignore(7);//file me naam, id, aur price se pehlay 7 characters(include spaces) ignoure kiay takay sirf naam hi uthay file se
					    	if (j == 3)//j==3 means 3rd line jis may product ka naam hai wo uthaega
						    {
								i.read(line, 8);//product ka naam file me agya	
							}
							else
							{
						    	i>>data[j];//baqi dono lines means j=1, j=2 pe id aur price hai wo uthalay:
							}
						}
						i.close();
						price=data[1];//line 1 jokay data[1] me ayi, wo price hai;
						id=data[2];//line 2 jokay data[2] me ayi, wo id hai;
						string name(line);//naam ko char[] se string me convert krdia;
						manager m;
						m.Report(name, price, id, quantity);
						AddToCart(name, price, id, quantity);//function calling;
						system("cls");
						cout<<"Do You Want to Continue Shopping?\n1) Yes\n2) No\nType: ";
						cin>>op6;
						if(op6==1)
						{
							goto MAIN;
						}
						else if(op6==2)
						{
							D3:
							system("cls");
							cout<<"1) See the Cart\n2) Go for bill\n3) Delete An item from cart\nType: ";
							cin>>cart_op;
							if(cart_op==1)
							{
								ShowCart();
								goto D3;
							}
							else if(cart_op==2)
							{
//								Billing();
							}
							else if(cart_op==3)
							{
								update_cart();
								goto D3;
							}
							else 
							{
								cout<<"wrong input, try again";
								getch();
								system("cls");
								goto D3;
							}
						}
					}
					else if(op3==2)
					{
						E3:
						system("cls");
						cout<<"1)Go back\n2)Go MainPage\nType: ";
						cin>>op4;
						if(op4==1)
						{
							goto BACK1;
						}
						else if(op4==2)
						{
							goto MAIN;
						}
						else 
							{
								cout<<"wrong input, try again";
								getch();
								system("cls");
								goto E3;
							}
					}
				}
				else if(op2==2)
				{
					system("cls");
					cout<<"Features: \n\n";
					ifstream i("Iphone8.txt");	
					while(i)//read data from file
					{
						i.get(chr);
						cout<<chr;
					}
					i.close();
					cout<<"\n\nPress any key to continue!!";
					getch();
					system("cls");
					C4:
					cout<<"Do you Want to Buy this Product?\n1)Yes\n2)No\n\n3)Go Back\n4)Go to HomePageType: ";
					cin>>op3;
					if(op3!= 1 && op3!= 2 && op3!=3 && op3!=4)
					{
						system("cls");
						cout<<"Wrong input, try again";
						getch();
						system("cls");
						goto C4;
					}
					else if(op3==3)
					{
						goto BACK1;
					}
					else if(op3==4)
					{
						system("cls");
						goto MAIN;
					}
					else if(op3==1)
					{
						cout<<"Quantity: ";
						cin>>quantity;
						cout<<"Thankyou, Sir!";
						getch();
						ifstream i("Iphone8.txt");	
						for (int j = 1; j < 4; j++)
					    {
					    	i.ignore(7);//file me naam, id, aur price se pehlay 7 characters(include spaces) ignoure kiay takay sirf naam hi uthay file se
					    	if (j == 3)//j==3 means 3rd line jis may product ka naam hai wo uthaega
						    {
								i.read(line, 8);//product ka naam file me agya	
							}
							else
							{
						    	i>>data[j];//baqi dono lines means j=1, j=2 pe id aur price hai wo uthalay:
							}
						}
						i.close();
						price=data[1];//line 1 jokay data[1] me ayi, wo price hai;
						id=data[2];//line 2 jokay data[2] me ayi, wo id hai;
						string name(line);//naam ko char[] se string me convert krdia;
						manager m;
						m.Report(name, price, id, quantity);
						AddToCart(name, price, id, quantity);//function calling;
						system("cls");
						cout<<"Do You Want to Continue Shopping?\n1) Yes\n2) No\nType: ";
						cin>>op6;
						if(op6==1)
						{
							goto MAIN;
						}
						else if(op6==2)
						{
							D5:
							system("cls");
							cout<<"1) See the Cart\n2) Go for bill\n3) Delete An item from cart\nType: ";
							cin>>cart_op;
							if(cart_op==1)
							{
								ShowCart();
								goto D5;
							}
							else if(cart_op==2)
							{
//								Billing();
							}
							else if(cart_op==3)
							{
								update_cart();
								goto D5;
							}
							else 
							{
								cout<<"wrong input, try again";
								getch();
								system("cls");
								goto D5;
							}
						}
					}
					else if(op3==2)
					{
						system("cls");
						cout<<"1)Go back\n2)Go MainPage\nType: ";
						cin>>op4;
						if(op4==1)
						{
							goto BACK1;
						}
						else if(op4==2)
						{
							goto MAIN;
						}
					}
				}
				else if(op2==0)
				{
					goto MAIN;
				}
			}
		}
		else if(cat1==2)
		{
			B1:
			system("cls");
			cout<<"Please Choose Company\n1)HP\n2)Apple\n\n0) Go to Home Page\n3)Go BackType: ";
			cin>>com;
			if(com!=1 && com !=2 && com!=3 && com!=0)
			{
				cout<<"Wrong input Try Again";
				goto B1;
			}
			if(com==0)
			{
				system("cls");
				goto MAIN;
			}
			if(com==3)
			{
				system("cls");
				goto A;
			}
			if(com==1)
			{
				BACK2:
				system("cls");
				cout<<"Please Choose your Favourite One:\n1)HP EliteBook G4 Notebook PC\n2)HP Elitebook G5 Notebook PC - Customizable\n0-> For Go Back\nType: ";
				cin>>op2;
				if(op2==0)
				{
					goto B1;
				}
				if(op2==1)
				{
					system("cls");
					cout<<"Features: \n\n";
					ifstream i("HP EliteBook G4 Notebook PC.txt");	
					while(i)//read data from file
					{
						i.get(chr);
						cout<<chr;
					}
					i.close();
					cout<<"\n\nPress any key to continue!!";
					getch();
					system("cls");
					C5:
					cout<<"Do you Want to Buy this Product?\n1)Yes\n2)No\n\n3)Go Back\n4)Go to HomePageType: ";
					cin>>op3;
					if(op3!= 1 && op3!= 2 && op3!=3 && op3!=4)
					{
						system("cls");
						cout<<"Wrong input, try again";
						getch();
						system("cls");
						goto C5;
					}
					else if(op3==3)
					{
						goto BACK2;
					}
					else if(op3==4)
					{
						system("cls");
						goto MAIN;
					}
					else if(op3==1)
					{
						cout<<"Quantity: ";
						cin>>quantity;
						cout<<"Thankyou, Sir!";
						getch();
						ifstream i("HP EliteBook G4 Notebook PC.txt");	
						for (int j = 1; j < 4; j++)
					    {
					    	i.ignore(7);//file me naam, id, aur price se pehlay 7 characters(include spaces) ignoure kiay takay sirf naam hi uthay file se
					    	if (j == 3)//j==3 means 3rd line jis may product ka naam hai wo uthaega
						    {
								i.read(line, 15);//product ka naam file me agya	
							}
							else
							{
						    	i>>data[j];//baqi dono lines means j=1, j=2 pe id aur price hai wo uthalay:
							}
						}
						i.close();
						price=data[1];//line 1 jokay data[1] me ayi, wo price hai;
						id=data[2];//line 2 jokay data[2] me ayi, wo id hai;
						string name(line);//naam ko char[] se string me convert krdia;
						manager m;
						m.Report(name, price, id, quantity);
						AddToCart(name, price, id, quantity);//function calling;
						system("cls");
						cout<<"Do You Want to Continue Shopping?\n1) Yes\n2) No\nType: ";
						cin>>op6;
						if(op6==1)
						{
							goto MAIN;
						}
						else if(op6==2)
						{
							D6:
							system("cls");
							cout<<"1) See the Cart\n2) Go for bill\n3) Delete An item from cart\nType: ";
							cin>>cart_op;
							if(cart_op==1)
							{
								ShowCart();
								goto D6;
							}
							else if(cart_op==2)
							{
//								Billing();
							}
							else if(cart_op==3)
							{
								update_cart();
								goto D6;
							}
							else 
							{
								cout<<"wrong input, try again";
								getch();
								system("cls");
								goto D6;
							}
						}
					}
					else if(op3==2)
					{
						E5:
						system("cls");
						cout<<"1)Go back\n2)Go MainPage\nType: ";
						cin>>op4;
						if(op4==1)
						{
							goto BACK2;
						}
						else if(op4==2)
						{
							goto MAIN;
						}
						else 
							{
								cout<<"wrong input, try again";
								getch();
								system("cls");
								goto E5;
							}
					}
					else if(op2==0)
					{
						goto MAIN;
					}
					else 
						{
							cout<<"wrong input, try again";
							getch();
							system("cls");
							goto BACK2;
						}	
				}
				else if(op2==2)
				{
					system("cls");
					cout<<"Features: \n\n";
					ifstream i("HP EliteBook G5 Notebook PC - Customizable.txt");	
					while(i)//read data from file
					{
						i.get(chr);
						cout<<chr;
					}
					i.close();
					cout<<"\n\nPress any key to continue!!";
					getch();
					system("cls");
					C6:
					cout<<"Do you Want to Buy this Product?\n1)Yes\n2)No\n\n3)Go Back\n4)Go to HomePageType: ";
					cin>>op3;
					if(op3!= 1 && op3!= 2 && op3!=3 && op3!=4)
					{
						system("cls");
						cout<<"Wrong input, try again";
						getch();
						system("cls");
						goto C6;
					}
					else if(op3==3)
					{
						goto BACK2;
					}
					else if(op3==4)
					{
						system("cls");
						goto MAIN;
					}
					else if(op3==1)
					{
						cout<<"Quantity: ";
						cin>>quantity;
						cout<<"Thankyou, Sir!";
						getch();
						ifstream i("HP EliteBook G5 Notebook PC - Customizable.txt");	
						for (int j = 1; j < 4; j++)
					    {
					    	i.ignore(7);//file me naam, id, aur price se pehlay 7 characters(include spaces) ignoure kiay takay sirf naam hi uthay file se
					    	if (j == 3)//j==3 means 3rd line jis may product ka naam hai wo uthaega
						    {
								i.read(line, 15);//product ka naam file me agya	
							}
							else
							{
						    	i>>data[j];//baqi dono lines means j=1, j=2 pe id aur price hai wo uthalay:
							}
						}
						i.close();
						price=data[1];//line 1 jokay data[1] me ayi, wo price hai;
						id=data[2];//line 2 jokay data[2] me ayi, wo id hai;
						string name(line);//naam ko char[] se string me convert krdia;
						manager m;
						m.Report(name, price, id, quantity);
						AddToCart(name, price, id, quantity);//function calling;
						system("cls");
						cout<<"Do You Want to Continue Shopping?\n1) Yes\n2) No\nType: ";
						cin>>op6;
						if(op6==1)
						{
							goto MAIN;
						}
						else if(op6==2)
						{
							D7:
							system("cls");
							cout<<"1) See the Cart\n2) Go for bill\n3) Delete An item from cart\nType: ";
							cin>>cart_op;
							if(cart_op==1)
							{
								ShowCart();
								goto D7;
							}
							else if(cart_op==2)
							{
//								Billing();
							}
							else if(cart_op==3)
							{
								update_cart();
								goto D7;
							}
							else 
							{
								cout<<"wrong input, try again";
								getch();
								system("cls");
								goto D7;
							}
						}
					}
					else if(op3==2)
					{
						system("cls");
						E7:
						cout<<"1)Go back\n2)Go MainPage\nType: ";
						cin>>op4;
						if(op4==1)
						{
							goto BACK2;
						}
						else if(op4==2)
						{
							goto MAIN;
						}
						else 
							{
								cout<<"wrong input, try again";
								getch();
								system("cls");
								goto E7;
							}
					}
					else if(op2==0)
					{
						goto MAIN;
					}	
					else 
					{
						cout<<"wrong input, try again";
						getch();
						system("cls");
						goto BACK3;
					}
				}
			}
			else if(com==2)
			{
				BACK3:
				system("cls");
				cout<<"Please Choose your Favourite One:\n1)13.3 MacBook Air (Mid 2017) - 128GB Storage MQD32\n2)13.3 MacBook Pro Retina - 256GB PCIe SSD - macOS Sierra - Space Grey\n0->For Go Back\nType: ";
				cin>>op2;
					if(op2!= 1 && op2 != 2 && op2 != 3 && op2!= 0)
					{
						system("cls");
						cout<<"Wrong input, try again";
						getch();
						system("cls");
						goto BACK3;
					}
					if(op2==3)
					{
						goto MAIN;
					}
					if(op2==0)
					{
						goto B1;
					}
					if(op2==1)
					{
						system("cls");
						cout<<"Features: \n\n";
						ifstream i("13.3 MacBook Air (Mid 2017) - 128GB Storage MQD32.txt");	
						while(i)//read data from file
						{
							i.get(chr);
							cout<<chr;
						}
						i.close();
						cout<<"\n\nPress any key to continue!!";
						getch();
						system("cls");
						C7:
						cout<<"Do you Want to Buy this Product?\n1)Yes\n2)No\n\n3)Go Back\n4)Go to HomePageType: ";
						cin>>op3;
						if(op3!= 1 && op3!= 2 && op3!=3 && op3!=4)
						{
							system("cls");
							cout<<"Wrong input, try again";
							getch();
							system("cls");
							goto C7;
						}
						else if(op3==3)
						{
							goto BACK3;
						}
						else if(op3==4)
						{
							system("cls");
							goto MAIN;
						}
						else if(op3==1)
						{
							cout<<"Quantity: ";
							cin>>quantity;
							cout<<"Thankyou, Sir!";
							getch();
							ifstream i("13.3 MacBook Air (Mid 2017) - 128GB Storage MQD32.txt");	
							for (int j = 1; j < 4; j++)
						    {
						    	i.ignore(7);//file me naam, id, aur price se pehlay 7 characters(include spaces) ignoure kiay takay sirf naam hi uthay file se
						    	if (j == 3)//j==3 means 3rd line jis may product ka naam hai wo uthaega
							    {
									i.read(line, 16);//product ka naam file me agya	
								}
								else
								{
							    	i>>data[j];//baqi dono lines means j=1, j=2 pe id aur price hai wo uthalay:
								}
							}
							i.close();
							price=data[1];//line 1 jokay data[1] me ayi, wo price hai;
							id=data[2];//line 2 jokay data[2] me ayi, wo id hai;
							string name(line);//naam ko char[] se string me convert krdia;
							manager m;
							m.Report(name, price, id, quantity);
							AddToCart(name, price, id, quantity);//function calling
							system("cls");
							cout<<"Do You Want to Continue Shopping?\n1) Yes\n2) No\nType: ";
							cin>>op6;
							if(op6==1)
							{
								goto MAIN;
							}
							else if(op6==2)
							{
								D8:
								system("cls");
								cout<<"1) See the Cart\n2) Go for bill\n3) Delete An item from cart\nType: ";
								cin>>cart_op;
								if(cart_op==1)
								{
									ShowCart();
									goto D8;
								}
								else if(cart_op==2)
								{
	//								Billing();
								}
								else if(cart_op==3)
								{
									update_cart();
									goto D8;
								}
								else 
								{
									cout<<"wrong input, try again";
									getch();
									system("cls");
									goto D8;
								}
							}
						}
						else if(op3==2)
						{
							system("cls");
							cout<<"1)Go back\n2)Go MainPage\nType: ";
							cin>>op4;
							if(op4==1)
							{
								goto BACK3;
							}
							else if(op4==2)
							{
								goto MAIN;
							}
						}
					}
					else if(op2==2)
					{
						system("cls");
						cout<<"Features: \n\n";
						ifstream i("13.3 MacBook Pro Retina - 256GB PCIe SSD - macOS Sierra - Space Grey.txt");	
						while(i)//read data from file
						{
							i.get(chr);
							cout<<chr;
						}
						i.close();
						cout<<"\n\nPress any key to continue!!";
						getch();
						system("cls");
						C8:
						cout<<"Do you Want to Buy this Product?\n1)Yes\n2)No\n\n3)Go Back\n4)Go to HomePageType: ";
						cin>>op3;
						if(op3!= 1 && op3!= 2 && op3!=3 && op3!=4)
						{
							system("cls");
							cout<<"Wrong input, try again";
							getch();
							system("cls");
							goto C8;
						}
						else if(op3==3)
						{
							goto BACK3;
						}
						else if(op3==4)
						{
							system("cls");
							goto MAIN;
						}
						else if(op3==1)
						{
							cout<<"Quantity: ";
							cin>>quantity;
							cout<<"Thankyou, Sir!";
							getch();
							ifstream i("13.3 MacBook Pro Retina - 256GB PCIe SSD - macOS Sierra - Space Grey.txt");	
							for (int j = 1; j < 4; j++)
						    {
						    	i.ignore(7);//file me naam, id, aur price se pehlay 7 characters(include spaces) ignoure kiay takay sirf naam hi uthay file se
						    	if (j == 3)//j==3 means 3rd line jis may product ka naam hai wo uthaega
							    {
									i.read(line, 16);//product ka naam file me agya	
								}
								else
								{
							    	i>>data[j];//baqi dono lines means j=1, j=2 pe id aur price hai wo uthalay:
								}
							}
							i.close();
							price=data[1];//line 1 jokay data[1] me ayi, wo price hai;
							id=data[2];//line 2 jokay data[2] me ayi, wo id hai;
							string name(line);//naam ko char[] se string me convert krdia;
							manager m;
							m.Report(name, price, id, quantity);
							AddToCart(name, price, id, quantity);//function calling;
							system("cls");
							cout<<"Do You Want to Continue Shopping?\n1) Yes\n2) No\nType: ";
							cin>>op6;
							if(op6==1)
							{
								goto MAIN;
							}
							else if(op6==2)
							{
								D9:
								system("cls");
								cout<<"1) See the Cart\n2) Go for bill\n3) Delete An item from cart\nType: ";
								cin>>cart_op;
								if(cart_op==1)
								{
									ShowCart();
									goto D9;
								}
								else if(cart_op==2)
								{
	//								Billing();
								}
								else if(cart_op==3)
								{
									update_cart();
									goto D9;
								}
							}
						}
						else if(op3==2)
						{
							system("cls");
							cout<<"1)Go back\n2)Go MainPage\nType: ";
							cin>>op4;
							if(op4==1)
							{
								goto BACK1;
							}
							else if(op4==2)
							{
								goto MAIN;
							}
						}
					}
					else if(op2==0)
					{
						goto MAIN;
					}
				}
			}
		}
	else if(op==2)
	{
		BACK6:
		system("cls");
		cout<<"1)Blender\n2)Pressur Cookers\n3)Sofa Set\n\n0)Go back\nType: ";
		cin>>cat1;
		if(cat1==0)
		{
			goto MAIN;
		}
		if(cat1==1)
		{
			system("cls");
						cout<<"Features: \n\n";
						ifstream i("Blender.txt");	
						while(i)//read data from file
						{
							i.get(chr);
							cout<<chr;
						}
						i.close();
						cout<<"\n\nPress any key to continue!!";
						getch();
						system("cls");
						C9:
						cout<<"Do you Want to Buy this Product?\n1)Yes\n2)No\n\n3)Go Back\n4)Go to HomePageType: ";
						cin>>op3;
						if(op3!= 1 && op3!= 2 && op3!=3 && op3!=4)
						{
							system("cls");
							cout<<"Wrong input, try again";
							getch();
							system("cls");
							goto C9;
						}
						else if(op3==3)
						{
							goto BACK6;
						}
						else if(op3==4)
						{
							system("cls");
							goto MAIN;
						}
						else if(op3==1)
						{
							cout<<"Quantity: ";
							cin>>quantity;
							cout<<"Thankyou, Sir!";
							getch();
							ifstream i("Blender.txt");	
							for (int j = 1; j < 4; j++)
						    {
						    	i.ignore(7);//file me naam, id, aur price se pehlay 7 characters(include spaces) ignoure kiay takay sirf naam hi uthay file se
						    	if (j == 3)//j==3 means 3rd line jis may product ka naam hai wo uthaega
							    {
									i.read(line, 12);//product ka naam file me agya	
								}
								else
								{
							    	i>>data[j];//baqi dono lines means j=1, j=2 pe id aur price hai wo uthalay:
								}
							}
							i.close();
							price=data[1];//line 1 jokay data[1] me ayi, wo price hai;
							id=data[2];//line 2 jokay data[2] me ayi, wo id hai;
							string name(line);//naam ko char[] se string me convert krdia;
							manager m;
							m.Report(name, price, id, quantity);
							AddToCart(name, price, id, quantity);//function calling;
							system("cls");
							cout<<"Do You Want to Continue Shopping?\n1) Yes\n2) No\nType: ";
							cin>>op6;
							if(op6==1)
							{
								goto MAIN;
							}
							else if(op6==2)
							{
								D10:
								system("cls");
								cout<<"1) See the Cart\n2) Go for bill\n3) Delete An item from cart\nType: ";
								cin>>cart_op;
								if(cart_op==1)
								{
									ShowCart();
									goto D10;
								}
								else if(cart_op==2)
								{
	//								Billing();
								}
								else if(cart_op==3)
								{
									update_cart();
									goto D10;
								}
							}
						}
						else if(op3==2)
						{
							system("cls");
							cout<<"1)Go back\n2)Go MainPage\nType: ";
							cin>>op4;
							if(op4==1)
							{
								goto BACK6;
							}
							else if(op4==2)
							{
								goto MAIN;
							}
						}
					}
		else if(cat1==2)
		{
			system("cls");
						cout<<"Features: \n\n";
						ifstream i("Pressure Cooker.txt");	
						while(i)//read data from file
						{
							i.get(chr);
							cout<<chr;
						}
						i.close();
						cout<<"\n\nPress any key to continue!!";
						getch();
						system("cls");
						C10:
						cout<<"Do you Want to Buy this Product?\n1)Yes\n2)No\n\n3)Go Back\n4)Go to HomePageType: ";
						cin>>op3;
						if(op3!= 1 && op3!= 2 && op3!=3 && op3!=4)
						{
							system("cls");
							cout<<"Wrong input, try again";
							getch();
							system("cls");
							goto C10;
						}
						else if(op3==3)
						{
							goto BACK6;
						}
						else if(op3==4)
						{
							system("cls");
							goto MAIN;
						}
						else if(op3==1)
						{
							cout<<"Quantity: ";
							cin>>quantity;
							cout<<"Thankyou, Sir!";
							getch();
							ifstream i("Pressure Cooker.txt");	
							for (int j = 1; j < 4; j++)
						    {
						    	i.ignore(7);//file me naam, id, aur price se pehlay 7 characters(include spaces) ignoure kiay takay sirf naam hi uthay file se
						    	if (j == 3)//j==3 means 3rd line jis may product ka naam hai wo uthaega
							    {
									i.read(line, 13);//product ka naam file me agya	
								}
								else
								{
							    	i>>data[j];//baqi dono lines means j=1, j=2 pe id aur price hai wo uthalay:
								}
							}
							i.close();
							price=data[1];//line 1 jokay data[1] me ayi, wo price hai;
							id=data[2];//line 2 jokay data[2] me ayi, wo id hai;
							string name(line);//naam ko char[] se string me convert krdia;
							manager m;
							m.Report(name, price, id, quantity);
							AddToCart(name, price, id, quantity);//function calling;
							system("cls");
							cout<<"Do You Want to Continue Shopping?\n1) Yes\n2) No\nType: ";
							cin>>op6;
							if(op6==1)
							{
								goto MAIN;
							}
							else if(op6==2)
							{
								D11:
								system("cls");
								cout<<"1) See the Cart\n2) Go for bill\n3) Delete An item from cart\nType: ";
								cin>>cart_op;
								if(cart_op==1)
								{
									ShowCart();
									goto D11;
								}
								else if(cart_op==2)
								{
	//								Billing();
								}
								else if(cart_op==3)
								{
									update_cart();
									goto D11;
								}
							}
						}
						else if(op3==2)
						{
							system("cls");
							cout<<"1)Go back\n2)Go MainPage\nType: ";
							cin>>op4;
							if(op4==1)
							{
								goto BACK6;
							}
							else if(op4==2)
							{
								goto MAIN;
							}
						}
					}
		else if(cat1==3)
		{
			system("cls");
						cout<<"Features: \n\n";
						ifstream i("Sofa Set.txt");	
						while(i)//read data from file
						{
							i.get(chr);
							cout<<chr;
						}
						i.close();
						cout<<"\n\nPress any key to continue!!";
						getch();
						system("cls");
						C11:
						cout<<"Do you Want to Buy this Product?\n1)Yes\n2)No\n\n3)Go Back\n4)Go to HomePageType: ";
						cin>>op3;
						if(op3!= 1 && op3!= 2 && op3!=3 && op3!=4)
						{
							system("cls");
							cout<<"Wrong input, try again";
							getch();
							system("cls");
							goto C11;
						}
						else if(op3==3)
						{
							goto BACK6;
						}
						else if(op3==4)
						{
							system("cls");
							goto MAIN;
						}
						else if(op3==1)
						{
							cout<<"Quantity: ";
							cin>>quantity;
							cout<<"Thankyou, Sir!";
							getch();
							ifstream i("Sofa Set.txt");	
							for (int j = 1; j < 4; j++)
						    {
						    	i.ignore(7);//file me naam, id, aur price se pehlay 7 characters(include spaces) ignoure kiay takay sirf naam hi uthay file se
						    	if (j == 3)//j==3 means 3rd line jis may product ka naam hai wo uthaega
							    {
									i.read(line, 13);//product ka naam file me agya	
								}
								else
								{
							    	i>>data[j];//baqi dono lines means j=1, j=2 pe id aur price hai wo uthalay:
								}
							}
							i.close();
							price=data[1];//line 1 jokay data[1] me ayi, wo price hai;
							id=data[2];//line 2 jokay data[2] me ayi, wo id hai;
							string name(line);//naam ko char[] se string me convert krdia;
							manager m;
							m.Report(name, price, id, quantity);
							AddToCart(name, price, id, quantity);//function calling;
							system("cls");
							cout<<"Do You Want to Continue Shopping?\n1) Yes\n2) No\nType: ";
							cin>>op6;
							if(op6==1)
							{
								goto MAIN;
							}
							else if(op6==2)
							{
								D12:
								system("cls");
								cout<<"1) See the Cart\n2) Go for bill\n3) Delete An item from cart\nType: ";
								cin>>cart_op;
								if(cart_op==1)
								{
									ShowCart();
									goto D12;
								}
								else if(cart_op==2)
								{
	//								Billing();
								}
								else if(cart_op==3)
								{
									update_cart();
									goto D12;
								}
							}
						}
						else if(op3==2)
						{
							system("cls");
							cout<<"1)Go back\n2)Go MainPage\nType: ";
							cin>>op4;
							if(op4==1)
							{
								goto BACK6;
							}
							else if(op4==2)
							{
								goto MAIN;
							}
						}
					}
				}
	else if(op==3)
	{
		X:
		system("cls");
		cout<<"1)Mens Wear\n2)Womens Wear\n3)Kids Wear\n\n0) Go to Main\nType: ";
		cin>>cat1;
		if(cat1==0)
		{
			goto MAIN;
		}
		if(cat1==1)
		{
			BACK7:
			system("cls");
			cout<<"Please Choose Product\n1)Hoodies\n2)Shirts\n\n0) Go back\nType: ";
			cin>>com;
			if(com==0)
			{
				goto X;
			}
			if(com==1)
			{
			system("cls");
						cout<<"Features: \n\n";
						ifstream i("Mens Hoodie.txt");	
						while(i)//read data from file
						{
							i.get(chr);
							cout<<chr;
						}
						i.close();
						cout<<"\n\nPress any key to continue!!";
						getch();
						system("cls");
						C12:
						cout<<"Do you Want to Buy this Product?\n1)Yes\n2)No\n\n3)Go Back\n4)Go to HomePageType: ";
						cin>>op3;
						if(op3!= 1 && op3!= 2 && op3!=3 && op3!=4)
						{
							system("cls");
							cout<<"Wrong input, try again";
							getch();
							system("cls");
							goto C12;
						}
						else if(op3==3)
						{
							goto BACK7;
						}
						else if(op3==4)
						{
							system("cls");
							goto MAIN;
						}
						else if(op3==1)
						{
							cout<<"Quantity: ";
							cin>>quantity;
							cout<<"Thankyou, Sir!";
							getch();
							ifstream i("Mens Hoodie.txt");	
							for (int j = 1; j < 4; j++)
						    {
						    	i.ignore(7);//file me naam, id, aur price se pehlay 7 characters(include spaces) ignoure kiay takay sirf naam hi uthay file se
						    	if (j == 3)//j==3 means 3rd line jis may product ka naam hai wo uthaega
							    {
									i.read(line, 16);//product ka naam file me agya	
								}
								else
								{
							    	i>>data[j];//baqi dono lines means j=1, j=2 pe id aur price hai wo uthalay:
								}
							}
							i.close();
							price=data[1];//line 1 jokay data[1] me ayi, wo price hai;
							id=data[2];//line 2 jokay data[2] me ayi, wo id hai;
							string name(line);//naam ko char[] se string me convert krdia;
							manager m;
							m.Report(name, price, id, quantity);
							AddToCart(name, price, id, quantity);//function calling;
							system("cls");
							cout<<"Do You Want to Continue Shopping?\n1) Yes\n2) No\nType: ";
							cin>>op6;
							if(op6==1)
							{
								goto MAIN;
							}
							else if(op6==2)
							{
								D13:
								system("cls");
								cout<<"1) See the Cart\n2) Go for bill\n3) Delete An item from cart\nType: ";
								cin>>cart_op;
								if(cart_op==1)
								{
									ShowCart();
									goto D13;
								}
								else if(cart_op==2)
								{
	//								Billing();
								}
								else if(cart_op==3)
								{
									update_cart();
									goto D13;
								}
							}
						}
						else if(op3==2)
						{
							system("cls");
							cout<<"1)Go back\n2)Go MainPage\nType: ";
							cin>>op4;
							if(op4==1)
							{
								goto BACK7;
							}
							else if(op4==2)
							{
								goto MAIN;
							}
						}
					}
			else if(com==2)
			{
			system("cls");
						cout<<"Features: \n\n";
						ifstream i("Mens Shirts.txt");	
						while(i)//read data from file
						{
							i.get(chr);
							cout<<chr;
						}
						i.close();
						cout<<"\n\nPress any key to continue!!";
						getch();
						system("cls");
						C13:
						cout<<"Do you Want to Buy this Product?\n1)Yes\n2)No\n\n3)Go Back\n4)Go to HomePageType: ";
						cin>>op3;
						if(op3!= 1 && op3!= 2 && op3!=3 && op3!=4)
						{
							system("cls");
							cout<<"Wrong input, try again";
							getch();
							system("cls");
							goto C13;
						}
						else if(op3==3)
						{
							goto BACK7;
						}
						else if(op3==4)
						{
							system("cls");
							goto MAIN;
						}
						else if(op3==1)
						{
							cout<<"Quantity: ";
							cin>>quantity;
							cout<<"Thankyou, Sir!";
							getch();
							ifstream i("Mens Shirts.txt");	
							for (int j = 1; j < 4; j++)
						    {
						    	i.ignore(7);//file me naam, id, aur price se pehlay 7 characters(include spaces) ignoure kiay takay sirf naam hi uthay file se
						    	if (j == 3)//j==3 means 3rd line jis may product ka naam hai wo uthaega
							    {
									i.read(line, 11);//product ka naam file me agya	
								}
								else
								{
							    	i>>data[j];//baqi dono lines means j=1, j=2 pe id aur price hai wo uthalay:
								}
							}
							i.close();
							price=data[1];//line 1 jokay data[1] me ayi, wo price hai;
							id=data[2];//line 2 jokay data[2] me ayi, wo id hai;
							string name(line);//naam ko char[] se string me convert krdia;
							manager m;
							m.Report(name, price, id, quantity);
							AddToCart(name, price, id, quantity);//function calling;
							system("cls");
							cout<<"Do You Want to Continue Shopping?\n1) Yes\n2) No\nType: ";
							cin>>op6;
							if(op6==1)
							{
								goto MAIN;
							}
							else if(op6==2)
							{
								D14:
								system("cls");
								cout<<"1) See the Cart\n2) Go for bill\n3) Delete An item from cart\nType: ";
								cin>>cart_op;
								if(cart_op==1)
								{
									ShowCart();
									goto D14;
								}
								else if(cart_op==2)
								{
	//								Billing();
								}
								else if(cart_op==3)
								{
									update_cart();
									goto D14;
								}
							}
						}
						else if(op3==2)
						{
							system("cls");
							cout<<"1)Go back\n2)Go MainPage\nType: ";
							cin>>op4;
							if(op4==1)
							{
								goto BACK7;
							}
							else if(op4==2)
							{
								goto MAIN;
							}
						}
					}
		}
		else if(cat1==2)
		{
			BACK8:
				system("cls");
			cout<<"Please Choose Product\n1)Duppata\n2)Trousers\n\n0)Go back\nType: ";
			cin>>com;
			if(com==0)
			{
				goto X;
			}
			if(com==1)
			{
			system("cls");
						cout<<"Features: \n\n";
						ifstream i("Dupatta.txt");	
						while(i)//read data from file
						{
							i.get(chr);
							cout<<chr;
						}
						i.close();
						cout<<"\n\nPress any key to continue!!";
						getch();
						system("cls");
						C14:
						cout<<"Do you Want to Buy this Product?\n1)Yes\n2)No\n\n3)Go Back\n4)Go to HomePageType: ";
						cin>>op3;
						if(op3!= 1 && op3!= 2 && op3!=3 && op3!=4)
						{
							system("cls");
							cout<<"Wrong input, try again";
							getch();
							system("cls");
							goto C14;
						}
						else if(op3==3)
						{
							goto BACK8;
						}
						else if(op3==4)
						{
							system("cls");
							goto MAIN;
						}
						else if(op3==1)
						{
							cout<<"Quantity: ";
							cin>>quantity;
							cout<<"Thankyou, Sir!";
							getch();
							ifstream i("Dupatta.txt");	
							for (int j = 1; j < 4; j++)
						    {
						    	i.ignore(7);//file me naam, id, aur price se pehlay 7 characters(include spaces) ignoure kiay takay sirf naam hi uthay file se
						    	if (j == 3)//j==3 means 3rd line jis may product ka naam hai wo uthaega
							    {
									i.read(line, 15);//product ka naam file me agya	
								}
								else
								{
							    	i>>data[j];//baqi dono lines means j=1, j=2 pe id aur price hai wo uthalay:
								}
							}
							i.close();
							price=data[1];//line 1 jokay data[1] me ayi, wo price hai;
							id=data[2];//line 2 jokay data[2] me ayi, wo id hai;
							string name(line);//naam ko char[] se string me convert krdia;
							manager m;
							m.Report(name, price, id, quantity);
							AddToCart(name, price, id, quantity);//function calling;
							system("cls");
							cout<<"Do You Want to Continue Shopping?\n1) Yes\n2) No\nType: ";
							cin>>op6;
							if(op6==1)
							{
								goto MAIN;
							}
							else if(op6==2)
							{
								D15:
								system("cls");
								cout<<"1) See the Cart\n2) Go for bill\n3) Delete An item from cart\nType: ";
								cin>>cart_op;
								if(cart_op==1)
								{
									ShowCart();
									goto D15;
								}
								else if(cart_op==2)
								{
	//								Billing();
								}
								else if(cart_op==3)
								{
									update_cart();
									goto D15;
								}
							}
						}
						else if(op3==2)
						{
							system("cls");
							cout<<"1)Go back\n2)Go MainPage\nType: ";
							cin>>op4;
							if(op4==1)
							{
								goto BACK8;
							}
							else if(op4==2)
							{
								goto MAIN;
							}
						}
					}
			else if(com==2)
			{
			system("cls");
						cout<<"Features: \n\n";
						ifstream i("Trousers.txt");	
						while(i)//read data from file
						{
							i.get(chr);
							cout<<chr;
						}
						i.close();
						cout<<"\n\nPress any key to continue!!";
						getch();
						system("cls");
						C15:
						cout<<"Do you Want to Buy this Product?\n1)Yes\n2)No\n\n3)Go Back\n4)Go to HomePageType: ";
						cin>>op3;
						if(op3!= 1 && op3!= 2 && op3!=3 && op3!=4)
						{
							system("cls");
							cout<<"Wrong input, try again";
							getch();
							system("cls");
							goto C15;
						}
						else if(op3==3)
						{
							goto BACK8;
						}
						else if(op3==4)
						{
							system("cls");
							goto MAIN;
						}
						else if(op3==1)
						{
							cout<<"Quantity: ";
							cin>>quantity;
							cout<<"Thankyou, Sir!";
							getch();
							ifstream i("Trousers.txt");	
							for (int j = 1; j < 4; j++)
						    {
						    	i.ignore(7);//file me naam, id, aur price se pehlay 7 characters(include spaces) ignoure kiay takay sirf naam hi uthay file se
						    	if (j == 3)//j==3 means 3rd line jis may product ka naam hai wo uthaega
							    {
									i.read(line, 14);//product ka naam file me agya	
								}
								else
								{
							    	i>>data[j];//baqi dono lines means j=1, j=2 pe id aur price hai wo uthalay:
								}
							}
							i.close();
							price=data[1];//line 1 jokay data[1] me ayi, wo price hai;
							id=data[2];//line 2 jokay data[2] me ayi, wo id hai;
							string name(line);//naam ko char[] se string me convert krdia;
							manager m;
							m.Report(name, price, id, quantity);
							AddToCart(name, price, id, quantity);//function calling;
							system("cls");
							cout<<"Do You Want to Continue Shopping?\n1) Yes\n2) No\nType: ";
							cin>>op6;
							if(op6==1)
							{
								goto MAIN;
							}
							else if(op6==2)
							{
								D16:
								system("cls");
								cout<<"1) See the Cart\n2) Go for bill\n3) Delete An item from cart\nType: ";
								cin>>cart_op;
								if(cart_op==1)
								{
									ShowCart();
									goto D16;
								}
								else if(cart_op==2)
								{
	//								Billing();
								}
								else if(cart_op==3)
								{
									update_cart();
									goto D16;
								}
							}
						}
						else if(op3==2)
						{
							system("cls");
							cout<<"1)Go back\n2)Go MainPage\nType: ";
							cin>>op4;
							if(op4==1)
							{
								goto BACK8;
							}
							else if(op4==2)
							{
								goto MAIN;
							}
						}
					}
		}
		else if(cat1==3)
		{
			BACK9:
				system("cls");
			cout<<"Please Choose Product\n1)Hoodie\n2)Pents\n0) Go Back\nType: ";
			cin>>com;
			if(com==0)
			{
				goto X;
			}
			if(com==1)
			{
			system("cls");
						cout<<"Features: \n\n";
						ifstream i("Kids Hoodie.txt");	
						while(i)//read data from file
						{
							i.get(chr);
							cout<<chr;
						}
						i.close();
						cout<<"\n\nPress any key to continue!!";
						getch();
						system("cls");
						C16:
						cout<<"Do you Want to Buy this Product?\n1)Yes\n2)No\n\n3)Go Back\n4)Go to HomePageType: ";
						cin>>op3;
						if(op3!= 1 && op3!= 2 && op3!=3 && op3!=4)
						{
							system("cls");
							cout<<"Wrong input, try again";
							getch();
							system("cls");
							goto C16;
						}
						else if(op3==3)
						{
							goto BACK9;
						}
						else if(op3==4)
						{
							system("cls");
							goto MAIN;
						}
						else if(op3==1)
						{
							cout<<"Quantity: ";
							cin>>quantity;
							cout<<"Thankyou, Sir!";
							getch();
							ifstream i("Kids Hoodie.txt");	
							for (int j = 1; j < 4; j++)
						    {
						    	i.ignore(7);//file me naam, id, aur price se pehlay 7 characters(include spaces) ignoure kiay takay sirf naam hi uthay file se
						    	if (j == 3)//j==3 means 3rd line jis may product ka naam hai wo uthaega
							    {
									i.read(line, 15);//product ka naam file me agya	
								}
								else
								{
							    	i>>data[j];//baqi dono lines means j=1, j=2 pe id aur price hai wo uthalay:
								}
							}
							i.close();
							price=data[1];//line 1 jokay data[1] me ayi, wo price hai;
							id=data[2];//line 2 jokay data[2] me ayi, wo id hai;
							string name(line);//naam ko char[] se string me convert krdia;
							manager m;
							m.Report(name, price, id, quantity);
							AddToCart(name, price, id, quantity);//function calling;
							system("cls");
							cout<<"Do You Want to Continue Shopping?\n1) Yes\n2) No\nType: ";
							cin>>op6;
							if(op6==1)
							{
								goto MAIN;
							}
							else if(op6==2)
							{
								D17:
								system("cls");
								cout<<"1) See the Cart\n2) Go for bill\n3) Delete An item from cart\nType: ";
								cin>>cart_op;
								if(cart_op==1)
								{
									ShowCart();
									goto D17;
								}
								else if(cart_op==2)
								{
	//								Billing();
								}
								else if(cart_op==3)
								{
									update_cart();
									goto D17;
								}
							}
						}
						else if(op3==2)
						{
							system("cls");
							cout<<"1)Go back\n2)Go MainPage\nType: ";
							cin>>op4;
							if(op4==1)
							{
								goto BACK9;
							}
							else if(op4==2)
							{
								goto MAIN;
							}
						}
					}
			else if(com==2)
			{
			system("cls");
						cout<<"Features: \n\n";
						ifstream i("Kids Pents.txt");	
						while(i)//read data from file
						{
							i.get(chr);
							cout<<chr;
						}
						i.close();
						cout<<"\n\nPress any key to continue!!";
						getch();
						system("cls");
						C17:
						cout<<"Do you Want to Buy this Product?\n1)Yes\n2)No\n\n3)Go Back\n4)Go to HomePageType: ";
						cin>>op3;
						if(op3!= 1 && op3!= 2 && op3!=3 && op3!=4)
						{
							system("cls");
							cout<<"Wrong input, try again";
							getch();
							system("cls");
							goto C17;
						}
						else if(op3==3)
						{
							goto BACK9;
						}
						else if(op3==4)
						{
							system("cls");
							goto MAIN;
						}
						else if(op3==1)
						{
							cout<<"Quantity: ";
							cin>>quantity;
							cout<<"Thankyou, Sir!";
							getch();
							ifstream i("Kids Pents.txt");	
							for (int j = 1; j < 4; j++)
						    {
						    	i.ignore(7);//file me naam, id, aur price se pehlay 7 characters(include spaces) ignoure kiay takay sirf naam hi uthay file se
						    	if (j == 3)//j==3 means 3rd line jis may product ka naam hai wo uthaega
							    {
									i.read(line, 10);//product ka naam file me agya	
								}
								else
								{
							    	i>>data[j];//baqi dono lines means j=1, j=2 pe id aur price hai wo uthalay:
								}
							}
							i.close();
							price=data[1];//line 1 jokay data[1] me ayi, wo price hai;
							id=data[2];//line 2 jokay data[2] me ayi, wo id hai;
							string name(line);//naam ko char[] se string me convert krdia;
							manager m;
							m.Report(name, price, id, quantity);
							AddToCart(name, price, id, quantity);//function calling;
							system("cls");
							cout<<"Do You Want to Continue Shopping?\n1) Yes\n2) No\nType: ";
							cin>>op6;
							if(op6==1)
							{
								goto MAIN;
							}
							else if(op6==2)
							{
								D18:
								system("cls");
								cout<<"1) See the Cart\n2) Go for bill\n3) Delete An item from cart\nType: ";
								cin>>cart_op;
								if(cart_op==1)
								{
									ShowCart();
									goto D18;
								}
								else if(cart_op==2)
								{
	//								Billing();
								}
								else if(cart_op==3)
								{
									update_cart();
									goto D18;
								}
							}
						}
						else if(op3==2)
						{
							system("cls");
							cout<<"1)Go back\n2)Go MainPage\nType: ";
							cin>>op4;
							if(op4==1)
							{
								goto BACK9;
							}
							else if(op4==2)
							{
								goto MAIN;
							}
						}
					}
		}
	}
	else if(op==4)
	{
		BACK10:
		system("cls");
		cout<<"1)Facial Cleanser For Men\n2)Blood Pressure Monitor\n3)Facial Cleanser For Women\n\n0) Go Back\nType: ";
		cin>>cat1;
		if(cat1==0)
		{
			goto MAIN;
		}
		if(cat1==1)
		{
			system("cls");
						cout<<"Features: \n\n";
						ifstream i("Facial Cleanser For Men.txt");	
						while(i)//read data from file
						{
							i.get(chr);
							cout<<chr;
						}
						i.close();
						cout<<"\n\nPress any key to continue!!";
						getch();
						system("cls");
						C20:
						cout<<"Do you Want to Buy this Product?\n1)Yes\n2)No\n\n3)Go Back\n4)Go to HomePageType: ";
						cin>>op3;
						if(op3!= 1 && op3!= 2 && op3!=3 && op3!=4)
						{
							system("cls");
							cout<<"Wrong input, try again";
							getch();
							system("cls");
							goto C20;
						}
						else if(op3==3)
						{
							goto BACK10;
						}
						else if(op3==4)
						{
							system("cls");
							goto MAIN;
						}
						else if(op3==1)
						{
							cout<<"Quantity: ";
							cin>>quantity;
							cout<<"Thankyou, Sir!";
							getch();
							ifstream i("Facial Cleanser For Men.txt");	
							for (int j = 1; j < 4; j++)
						    {
						    	i.ignore(7);//file me naam, id, aur price se pehlay 7 characters(include spaces) ignoure kiay takay sirf naam hi uthay file se
						    	if (j == 3)//j==3 means 3rd line jis may product ka naam hai wo uthaega
							    {
									i.read(line, 14);//product ka naam file me agya	
								}
								else
								{
							    	i>>data[j];//baqi dono lines means j=1, j=2 pe id aur price hai wo uthalay:
								}
							}
							i.close();
							price=data[1];//line 1 jokay data[1] me ayi, wo price hai;
							id=data[2];//line 2 jokay data[2] me ayi, wo id hai;
							string name(line);//naam ko char[] se string me convert krdia;
							manager m;
							m.Report(name, price, id, quantity);
							AddToCart(name, price, id, quantity);//function calling;
							system("cls");
							cout<<"Do You Want to Continue Shopping?\n1) Yes\n2) No\nType: ";
							cin>>op6;
							if(op6==1)
							{
								goto MAIN;
							}
							else if(op6==2)
							{
								D21:
								system("cls");
								cout<<"1) See the Cart\n2) Go for bill\n3) Delete An item from cart\nType: ";
								cin>>cart_op;
								if(cart_op==1)
								{
									ShowCart();
									goto D21;
								}
								else if(cart_op==2)
								{
	//								Billing();
								}
								else if(cart_op==3)
								{
									update_cart();
									goto D21;
								}
							}
						}
						else if(op3==2)
						{
							system("cls");
							cout<<"1)Go back\n2)Go MainPage\nType: ";
							cin>>op4;
							if(op4==1)
							{
								goto BACK10;
							}
							else if(op4==2)
							{
								goto MAIN;
							}
						}
					}
		else if(cat1==2)
		{
			system("cls");
						cout<<"Features: \n\n";
						ifstream i("Blood Pressure Monitor.txt");	
						while(i)//read data from file
						{
							i.get(chr);
							cout<<chr;
						}
						i.close();
						cout<<"\n\nPress any key to continue!!";
						getch();
						system("cls");
						C19:
						cout<<"Do you Want to Buy this Product?\n1)Yes\n2)No\n\n3)Go Back\n4)Go to HomePageType: ";
						cin>>op3;
						if(op3!= 1 && op3!= 2 && op3!=3 && op3!=4)
						{
							system("cls");
							cout<<"Wrong input, try again";
							getch();
							system("cls");
							goto C19;
						}
						else if(op3==3)
						{
							goto BACK10;
						}
						else if(op3==4)
						{
							system("cls");
							goto MAIN;
						}
						else if(op3==1)
						{
							cout<<"Quantity: ";
							cin>>quantity;
							cout<<"Thankyou, Sir!";
							getch();
							ifstream i("Blood Pressure Monitor.txt");	
							for (int j = 1; j < 4; j++)
						    {
						    	i.ignore(7);//file me naam, id, aur price se pehlay 7 characters(include spaces) ignoure kiay takay sirf naam hi uthay file se
						    	if (j == 3)//j==3 means 3rd line jis may product ka naam hai wo uthaega
							    {
									i.read(line, 10);//product ka naam file me agya	
								}
								else
								{
							    	i>>data[j];//baqi dono lines means j=1, j=2 pe id aur price hai wo uthalay:
								}
							}
							i.close();
							price=data[1];//line 1 jokay data[1] me ayi, wo price hai;
							id=data[2];//line 2 jokay data[2] me ayi, wo id hai;
							string name(line);//naam ko char[] se string me convert krdia;
							manager m;
							m.Report(name, price, id, quantity);
							AddToCart(name, price, id, quantity);//function calling;
							system("cls");
							cout<<"Do You Want to Continue Shopping?\n1) Yes\n2) No\nType: ";
							cin>>op6;
							if(op6==1)
							{
								goto MAIN;
							}
							else if(op6==2)
							{
								D20:
								system("cls");
								cout<<"1) See the Cart\n2) Go for bill\n3) Delete An item from cart\nType: ";
								cin>>cart_op;
								if(cart_op==1)
								{
									ShowCart();
									goto D20;
								}
								else if(cart_op==2)
								{
	//								Billing();
								}
								else if(cart_op==3)
								{
									update_cart();
									goto D20;
								}
							}
						}
						else if(op3==2)
						{
							system("cls");
							cout<<"1)Go back\n2)Go MainPage\nType: ";
							cin>>op4;
							if(op4==1)
							{
								goto BACK10;
							}
							else if(op4==2)
							{
								goto MAIN;
							}
						}
					}
		else if(cat1==3)
		{
			system("cls");
						cout<<"Features: \n\n";
						ifstream i("Facial Cleanser For Women.txt");	
						while(i)//read data from file
						{
							i.get(chr);
							cout<<chr;
						}
						i.close();
						cout<<"\n\nPress any key to continue!!";
						getch();
						system("cls");
						C21:
						cout<<"Do you Want to Buy this Product?\n1)Yes\n2)No\n\n3)Go Back\n4)Go to HomePageType: ";
						cin>>op3;
						if(op3!= 1 && op3!= 2 && op3!=3 && op3!=4)
						{
							system("cls");
							cout<<"Wrong input, try again";
							getch();
							system("cls");
							goto C21;
						}
						else if(op3==3)
						{
							goto BACK10;
						}
						else if(op3==4)
						{
							system("cls");
							goto MAIN;
						}
						else if(op3==1)
						{
							cout<<"Quantity: ";
							cin>>quantity;
							cout<<"Thankyou, Sir!";
							getch();
							ifstream i("Facial Cleanser For Women.txt");	
							for (int j = 1; j < 4; j++)
						    {
						    	i.ignore(7);//file me naam, id, aur price se pehlay 7 characters(include spaces) ignoure kiay takay sirf naam hi uthay file se
						    	if (j == 3)//j==3 means 3rd line jis may product ka naam hai wo uthaega
							    {
									i.read(line, 15);//product ka naam file me agya	
								}
								else
								{
							    	i>>data[j];//baqi dono lines means j=1, j=2 pe id aur price hai wo uthalay:
								}
							}
							i.close();
							price=data[1];//line 1 jokay data[1] me ayi, wo price hai;
							id=data[2];//line 2 jokay data[2] me ayi, wo id hai;
							string name(line);//naam ko char[] se string me convert krdia;
							manager m;
							m.Report(name, price, id, quantity);
							AddToCart(name, price, id, quantity);//function calling;
							system("cls");
							cout<<"Do You Want to Continue Shopping?\n1) Yes\n2) No\nType: ";
							cin>>op6;
							if(op6==1)
							{
								goto MAIN;
							}
							else if(op6==2)
							{
								D22:
								system("cls");
								cout<<"1) See the Cart\n2) Go for bill\n3) Delete An item from cart\nType: ";
								cin>>cart_op;
								if(cart_op==1)
								{
									ShowCart();
									goto D22;
								}
								else if(cart_op==2)
								{
	//								Billing();
								}
								else if(cart_op==3)
								{
									update_cart();
									goto D22;
								}
							}
						}
						else if(op3==2)
						{
							system("cls");
							cout<<"1)Go back\n2)Go MainPage\nType: ";
							cin>>op4;
							if(op4==1)
							{
								goto BACK10;
							}
							else if(op4==2)
							{
								goto MAIN;
							}
						}
					}
	}
	else if(op==5)
		{
		BACK11:
		system("cls");
		cout<<"1)Cricket\n2)FootBall\n3)BasketBall\n\n0) Go Back\nType: ";
		cin>>cat1;
		if(cat1==0)
		{
			goto MAIN;
		}
		if(cat1==1)
		{
			system("cls");
						cout<<"Features: \n\n";
						ifstream i("Cricket.txt");	
						while(i)//read data from file
						{
							i.get(chr);
							cout<<chr;
						}
						i.close();
						cout<<"\n\nPress any key to continue!!";
						getch();
						system("cls");
						C22:
						cout<<"Do you Want to Buy this Product?\n1)Yes\n2)No\n\n3)Go Back\n4)Go to HomePageType: ";
						cin>>op3;
						if(op3!= 1 && op3!= 2 && op3!=3 && op3!=4)
						{
							system("cls");
							cout<<"Wrong input, try again";
							getch();
							system("cls");
							goto C22;
						}
						else if(op3==3)
						{
							goto BACK11;
						}
						else if(op3==4)
						{
							system("cls");
							goto MAIN;
						}
						else if(op3==1)
						{
							cout<<"Quantity: ";
							cin>>quantity;
							cout<<"Thankyou, Sir!";
							getch();
							ifstream i("Cricket.txt");	
							for (int j = 1; j < 4; j++)
						    {
						    	i.ignore(7);//file me naam, id, aur price se pehlay 7 characters(include spaces) ignoure kiay takay sirf naam hi uthay file se
						    	if (j == 3)//j==3 means 3rd line jis may product ka naam hai wo uthaega
							    {
									i.read(line, 11);//product ka naam file me agya	
								}
								else
								{
							    	i>>data[j];//baqi dono lines means j=1, j=2 pe id aur price hai wo uthalay:
								}
							}
							i.close();
							price=data[1];//line 1 jokay data[1] me ayi, wo price hai;
							id=data[2];//line 2 jokay data[2] me ayi, wo id hai;
							string name(line);//naam ko char[] se string me convert krdia;
							manager m;
							m.Report(name, price, id, quantity);
							AddToCart(name, price, id, quantity);//function calling;
							system("cls");
							cout<<"Do You Want to Continue Shopping?\n1) Yes\n2) No\nType: ";
							cin>>op6;
							if(op6==1)
							{
								goto MAIN;
							}
							else if(op6==2)
							{
								D23:
								system("cls");
								cout<<"1) See the Cart\n2) Go for bill\n3) Delete An item from cart\nType: ";
								cin>>cart_op;
								if(cart_op==1)
								{
									ShowCart();
									goto D23;
								}
								else if(cart_op==2)
								{
	//								Billing();
								}
								else if(cart_op==3)
								{
									update_cart();
									goto D23;
								}
							}
						}
						else if(op3==2)
						{
							system("cls");
							cout<<"1)Go back\n2)Go MainPage\nType: ";
							cin>>op4;
							if(op4==1)
							{
								goto BACK11;
							}
							else if(op4==2)
							{
								goto MAIN;
							}
						}
					}
		else if(cat1==2)
		{
			system("cls");
						cout<<"Features: \n\n";
						ifstream i("Football.txt");	
						while(i)//read data from file
						{
							i.get(chr);
							cout<<chr;
						}
						i.close();
						cout<<"\n\nPress any key to continue!!";
						getch();
						system("cls");
						C23:
						cout<<"Do you Want to Buy this Product?\n1)Yes\n2)No\n\n3)Go Back\n4)Go to HomePageType: ";
						cin>>op3;
						if(op3!= 1 && op3!= 2 && op3!=3 && op3!=4)
						{
							system("cls");
							cout<<"Wrong input, try again";
							getch();
							system("cls");
							goto C23;
						}
						else if(op3==3)
						{
							goto BACK11;
						}
						else if(op3==4)
						{
							system("cls");
							goto MAIN;
						}
						else if(op3==1)
						{
							cout<<"Quantity: ";
							cin>>quantity;
							cout<<"Thankyou, Sir!";
							getch();
							ifstream i("Football.txt");	
							for (int j = 1; j < 4; j++)
						    {
						    	i.ignore(7);//file me naam, id, aur price se pehlay 7 characters(include spaces) ignoure kiay takay sirf naam hi uthay file se
						    	if (j == 3)//j==3 means 3rd line jis may product ka naam hai wo uthaega
							    {
									i.read(line, 8);//product ka naam file me agya	
								}
								else
								{
							    	i>>data[j];//baqi dono lines means j=1, j=2 pe id aur price hai wo uthalay:
								}
							}
							i.close();
							price=data[1];//line 1 jokay data[1] me ayi, wo price hai;
							id=data[2];//line 2 jokay data[2] me ayi, wo id hai;
							string name(line);//naam ko char[] se string me convert krdia;
							manager m;
							m.Report(name, price, id, quantity);
							AddToCart(name, price, id, quantity);//function calling;
							system("cls");
							cout<<"Do You Want to Continue Shopping?\n1) Yes\n2) No\nType: ";
							cin>>op6;
							if(op6==1)
							{
								goto MAIN;
							}
							else if(op6==2)
							{
								D24:
								system("cls");
								cout<<"1) See the Cart\n2) Go for bill\n3) Delete An item from cart\nType: ";
								cin>>cart_op;
								if(cart_op==1)
								{
									ShowCart();
									goto D24;
								}
								else if(cart_op==2)
								{
	//								Billing();
								}
								else if(cart_op==3)
								{
									update_cart();
									goto D24;
								}
							}
						}
						else if(op3==2)
						{
							system("cls");
							cout<<"1)Go back\n2)Go MainPage\nType: ";
							cin>>op4;
							if(op4==1)
							{
								goto BACK11;
							}
							else if(op4==2)
							{
								goto MAIN;
							}
						}
					}
		else if(cat1==3)
		{
			system("cls");
						cout<<"Features: \n\n";
						ifstream i("BasketBall.txt");	
						while(i)//read data from file
						{
							i.get(chr);
							cout<<chr;
						}
						i.close();
						cout<<"\n\nPress any key to continue!!";
						getch();
						system("cls");
						C24:
						cout<<"Do you Want to Buy this Product?\n1)Yes\n2)No\n\n3)Go Back\n4)Go to HomePageType: ";
						cin>>op3;
						if(op3!= 1 && op3!= 2 && op3!=3 && op3!=4)
						{
							system("cls");
							cout<<"Wrong input, try again";
							getch();
							system("cls");
							goto C24;
						}
						else if(op3==3)
						{
							goto BACK11;
						}
						else if(op3==4)
						{
							system("cls");
							goto MAIN;
						}
						else if(op3==1)
						{
							cout<<"Quantity: ";
							cin>>quantity;
							cout<<"Thankyou, Sir!";
							getch();
							ifstream i("BasketBall.txt");	
							for (int j = 1; j < 4; j++)
						    {
						    	i.ignore(7);//file me naam, id, aur price se pehlay 7 characters(include spaces) ignoure kiay takay sirf naam hi uthay file se
						    	if (j == 3)//j==3 means 3rd line jis may product ka naam hai wo uthaega
							    {
									i.read(line, 10);//product ka naam file me agya	
								}
								else
								{
							    	i>>data[j];//baqi dono lines means j=1, j=2 pe id aur price hai wo uthalay:
								}
							}
							i.close();
							price=data[1];//line 1 jokay data[1] me ayi, wo price hai;
							id=data[2];//line 2 jokay data[2] me ayi, wo id hai;
							string name(line);//naam ko char[] se string me convert krdia;
							manager m;
							m.Report(name, price, id, quantity);
							AddToCart(name, price, id, quantity);//function calling;
							system("cls");
							cout<<"Do You Want to Continue Shopping?\n1) Yes\n2) No\nType: ";
							cin>>op6;
							if(op6==1)
							{
								goto MAIN;
							}
							else if(op6==2)
							{
								D25:
								system("cls");
								cout<<"1) See the Cart\n2) Go for bill\n3) Delete An item from cart\nType: ";
								cin>>cart_op;
								if(cart_op==1)
								{
									ShowCart();
									goto D25;
								}
								else if(cart_op==2)
								{
	//								Billing();
								}
								else if(cart_op==3)
								{
									update_cart();
									goto D25;
								}
							}
						}
						else if(op3==2)
						{
							system("cls");
							cout<<"1)Go back\n2)Go MainPage\nType: ";
							cin>>op4;
							if(op4==1)
							{
								goto BACK11;
							}
							else if(op4==2)
							{
								goto MAIN;
							}
						}
					}
	}
	else if(op==6)
	{
		BACK12:
			system("cls");
		cout<<"1)Hublot Men Watch\n2)Men's Fashion Luxury Watch\n3)Women's' Fashion Luxury Watch\nType: ";
		cin>>cat1;
		if(cat1==0)
		{
			goto MAIN;
		}
		if(cat1==1)
		{
			system("cls");
						cout<<"Features: \n\n";
						ifstream i("Hublot Men Watch.txt");	
						while(i)//read data from file
						{
							i.get(chr);
							cout<<chr;
						}
						i.close();
						cout<<"\n\nPress any key to continue!!";
						getch();
						system("cls");
						C25:
						cout<<"Do you Want to Buy this Product?\n1)Yes\n2)No\n\n3)Go Back\n4)Go to HomePageType: ";
						cin>>op3;
						if(op3!= 1 && op3!= 2 && op3!=3 && op3!=4)
						{
							system("cls");
							cout<<"Wrong input, try again";
							getch();
							system("cls");
							goto C25;
						}
						else if(op3==3)
						{
							goto BACK12;
						}
						else if(op3==4)
						{
							system("cls");
							goto MAIN;
						}
						else if(op3==1)
						{
							cout<<"Quantity: ";
							cin>>quantity;
							cout<<"Thankyou, Sir!";
							getch();
							ifstream i("Hublot Men Watch.txt");	
							for (int j = 1; j < 4; j++)
						    {
						    	i.ignore(7);//file me naam, id, aur price se pehlay 7 characters(include spaces) ignoure kiay takay sirf naam hi uthay file se
						    	if (j == 3)//j==3 means 3rd line jis may product ka naam hai wo uthaega
							    {
									i.read(line, 9);//product ka naam file me agya	
								}
								else
								{
							    	i>>data[j];//baqi dono lines means j=1, j=2 pe id aur price hai wo uthalay:
								}
							}
							i.close();
							price=data[1];//line 1 jokay data[1] me ayi, wo price hai;
							id=data[2];//line 2 jokay data[2] me ayi, wo id hai;
							string name(line);//naam ko char[] se string me convert krdia;
							manager m;
							m.Report(name, price, id, quantity);
							AddToCart(name, price, id, quantity);//function calling;
							system("cls");
							cout<<"Do You Want to Continue Shopping?\n1) Yes\n2) No\nType: ";
							cin>>op6;
							if(op6==1)
							{
								goto MAIN;
							}
							else if(op6==2)
							{
								D26:
								system("cls");
								cout<<"1) See the Cart\n2) Go for bill\n3) Delete An item from cart\nType: ";
								cin>>cart_op;
								if(cart_op==1)
								{
									ShowCart();
									goto D26;
								}
								else if(cart_op==2)
								{
	//								Billing();
								}
								else if(cart_op==3)
								{
									update_cart();
									goto D26;
								}
							}
						}
						else if(op3==2)
						{
							system("cls");
							cout<<"1)Go back\n2)Go MainPage\nType: ";
							cin>>op4;
							if(op4==1)
							{
								goto BACK12;
							}
							else if(op4==2)
							{
								goto MAIN;
							}
						}
					}
		else if(cat1==2)
		{
			system("cls");
						cout<<"Features: \n\n";
						ifstream i("Men's Fashion Luxury Watch.txt");	
						while(i)//read data from file
						{
							i.get(chr);
							cout<<chr;
						}
						i.close();
						cout<<"\n\nPress any key to continue!!";
						getch();
						system("cls");
						C26:
						cout<<"Do you Want to Buy this Product?\n1)Yes\n2)No\n\n3)Go Back\n4)Go to HomePageType: ";
						cin>>op3;
						if(op3!= 1 && op3!= 2 && op3!=3 && op3!=4)
						{
							system("cls");
							cout<<"Wrong input, try again";
							getch();
							system("cls");
							goto C26;
						}
						else if(op3==3)
						{
							goto BACK12;
						}
						else if(op3==4)
						{
							system("cls");
							goto MAIN;
						}
						else if(op3==1)
						{
							cout<<"Quantity: ";
							cin>>quantity;
							cout<<"Thankyou, Sir!";
							getch();
							ifstream i("Men's Fashion Luxury Watch.txt");	
							for (int j = 1; j < 4; j++)
						    {
						    	i.ignore(7);//file me naam, id, aur price se pehlay 7 characters(include spaces) ignoure kiay takay sirf naam hi uthay file se
						    	if (j == 3)//j==3 means 3rd line jis may product ka naam hai wo uthaega
							    {
									i.read(line, 12);//product ka naam file me agya	
								}
								else
								{
							    	i>>data[j];//baqi dono lines means j=1, j=2 pe id aur price hai wo uthalay:
								}
							}
							i.close();
							price=data[1];//line 1 jokay data[1] me ayi, wo price hai;
							id=data[2];//line 2 jokay data[2] me ayi, wo id hai;
							string name(line);//naam ko char[] se string me convert krdia;
							manager m;
							m.Report(name, price, id, quantity);
							AddToCart(name, price, id, quantity);//function calling;
							system("cls");
							cout<<"Do You Want to Continue Shopping?\n1) Yes\n2) No\nType: ";
							cin>>op6;
							if(op6==1)
							{
								goto MAIN;
							}
							else if(op6==2)
							{
								D27:
								system("cls");
								cout<<"1) See the Cart\n2) Go for bill\n3) Delete An item from cart\nType: ";
								cin>>cart_op;
								if(cart_op==1)
								{
									ShowCart();
									goto D27;
								}
								else if(cart_op==2)
								{
	//								Billing();
								}
								else if(cart_op==3)
								{
									update_cart();
									goto D27;
								}
							}
						}
						else if(op3==2)
						{
							system("cls");
							cout<<"1)Go back\n2)Go MainPage\nType: ";
							cin>>op4;
							if(op4==1)
							{
								goto BACK12;
							}
							else if(op4==2)
							{
								goto MAIN;
							}
						}
					}
		else if(cat1==3)
		{
			system("cls");
						cout<<"Features: \n\n";
						ifstream i("Women's Fashion Luxury Watch.txt");	
						while(i)//read data from file
						{
							i.get(chr);
							cout<<chr;
						}
						i.close();
						cout<<"\n\nPress any key to continue!!";
						getch();
						system("cls");
						C27:
						cout<<"Do you Want to Buy this Product?\n1)Yes\n2)No\n\n3)Go Back\n4)Go to HomePageType: ";
						cin>>op3;
						if(op3!= 1 && op3!= 2 && op3!=3 && op3!=4)
						{
							system("cls");
							cout<<"Wrong input, try again";
							getch();
							system("cls");
							goto C27;
						}
						else if(op3==3)
						{
							goto BACK12;
						}
						else if(op3==4)
						{
							system("cls");
							goto MAIN;
						}
						else if(op3==1)
						{
							cout<<"Quantity: ";
							cin>>quantity;
							cout<<"Thankyou, Sir!";
							getch();
							ifstream i("Women's Fashion Luxury Watch.txt");	
							for (int j = 1; j < 4; j++)
						    {
						    	i.ignore(7);//file me naam, id, aur price se pehlay 7 characters(include spaces) ignoure kiay takay sirf naam hi uthay file se
						    	if (j == 3)//j==3 means 3rd line jis may product ka naam hai wo uthaega
							    {
									i.read(line, 15);//product ka naam file me agya	
								}
								else
								{
							    	i>>data[j];//baqi dono lines means j=1, j=2 pe id aur price hai wo uthalay:
								}
							}
							i.close();
							price=data[1];//line 1 jokay data[1] me ayi, wo price hai;
							id=data[2];//line 2 jokay data[2] me ayi, wo id hai;
							string name(line);//naam ko char[] se string me convert krdia;
							manager m;
							m.Report(name, price, id, quantity);
							AddToCart(name, price, id, quantity);//function calling;
							system("cls");
							cout<<"Do You Want to Continue Shopping?\n1) Yes\n2) No\nType: ";
							cin>>op6;
							if(op6==1)
							{
								goto MAIN;
							}
							else if(op6==2)
							{
								D28:
								system("cls");
								cout<<"1) See the Cart\n2) Go for bill\n3) Delete An item from cart\nType: ";
								cin>>cart_op;
								if(cart_op==1)
								{
									ShowCart();
									goto D28;
								}
								else if(cart_op==2)
								{
	//								Billing();
								}
								else if(cart_op==3)
								{
									update_cart();
									goto D28;
								}
							}
						}
						else if(op3==2)
						{
							system("cls");
							cout<<"1)Go back\n2)Go MainPage\nType: ";
							cin>>op4;
							if(op4==1)
							{
								goto BACK12;
							}
							else if(op4==2)
							{
								goto MAIN;
							}
						}
					}
	}
	else if(op==7)
	{
		system("cls");
		cout<<"You Are Successfully LogOut\nThankYou Sir For Visiting!";
	}
}
};
class normal:public customer
{
	public:
	bool login(string user,string pass)//login function for customer to gain access to market
   	{
        int count;
        string n,u,e,p;
        system("cls");

		ifstream input("normal.txt");
		while(input>>n>>u>>e>>p)
		{
			if(u == user && p == pass || e==user && p==pass)//check if usenamer or email and password match from file
			{
				count=1;
				if(count==1)	
				break;
				system("cls");
				return true;
			}
		}
		input.close();
		if(count==1)
		{
			cout<<"\t\t*****************************************************************************************\n";
			cout<<"\n\t\t\t\t\t\tHello "<<n<<"\n\t\t\t\t\t\tLOGIN SUCESS\n\t\t\t\t\t\tWe're glad that you're here.\n\n";
			cout<<"\t\t*****************************************************************************************\n";
		}
		else
		{
			count1++;
			if(count1==5)//check if five wrong login credentials are given
			{
				cout<<"Too many times wrong credentials program will now close!!!!!!!!!!!!!!!!!!!!";
				exit(0);
				input.close();
			}
			char choice2;//for asking choice of entering credentials again
			cout<<endl<<endl<<"**************************************************************************************"<<endl<<endl;
			cout<<"\nLOGIN ERROR\nPlease check your username and password\n\n\n";
			loop2:
			cout<<"Do you want to enter again!!!!!!!"<<endl<<"(Y for Yes,N for no): ";
			cin>>choice2;
			system("cls");
			if(choice2=='Y'||choice2=='y')
			{
				cout<<endl<<endl<<"***********************************************************************************"<<endl<<endl;
				cout<<"Enter USERNAME OR Email (xyz123@abc.com): ";
				cin>>user;
				cout<<endl<<endl;
				cout<<"Enter password: ";
				pass=passwordinput();
				cout<<endl<<endl<<"***********************************************************************************";
				cout<<endl<<endl<<"Press any key to continue ..................................";
				getch();
				normal n1;
				n1.login(user,pass);//call agian login if username or email or password is wrong 
			}
			else if(choice2=='N'||choice2=='n')
			{
				return false;
			}
			else
			{
				cout<<"Wrong input detected!!!!!!"<<endl;
				cout<<"Please Enter carefully!!!!!!!!!!!"<<endl;
				goto loop2;
			}
		}
	}	
	signup()
	{
				ifstream file("normal.txt");
				string n,u,e;
				string p;
				cout<<endl<<endl<<"****************************************************************************************************"<<endl<<endl;
				cout<<"\t\t\tfield marked (*) with this are required!!!!!!!!!!"<<endl<<endl;
				cout<<"Enter e-mail*(xyz123@abc.com): ";
				cin>>email;
				cout<<endl<<endl;
				name=inputstring();
				cout<<endl<<endl;
				cout<<"Enter username *: ";
				cin>>username;
				cout<<endl<<endl;
				cout<<"Enter password*: ";
				password=passwordinput();
				cout<<endl<<endl;
				cout<<"**************************************************************************************************"<<endl<<endl;
				cout<<"Press any key to continue...................................";
				getch();
				system("cls");
				file.clear();
				file.seekg(0, ios::beg);
				while(file>>n>>u>>e>>p)
				{
					if(email==e)
					{
						cout<<"Enter new email!!!"<<endl;
						cin>>email;
						int c=0;
						c=1;
						if(c=1)
						{
							file.clear();
							file.seekg(0, ios::beg);
						}
						
					}
					if(username==u)
					{
						cout<<"Enter new username: ";
						cin>>username;
						int c =0;
						c=1;
						if(c=1)
						{
							file.clear();
							file.seekg(0, ios::beg);
						}
					}
				}
				file.close();
				ofstream file1("normal.txt",ios::app);
				file1<<name<<endl;
				file1<<username<<endl;
				file1<<email<<endl;
				file1<<password<<endl;
				cout<<endl<<endl<<"*********************************************************************************************************";
				cout<<endl<<endl<<"\t\t\t\t\tSIGNUP IS SUCCESSFUL!!!!!!!!!!!!!!!";
				cout<<endl<<endl<<"\t\t\t\t\tYOUR CODE IS 7700";
				cout<<endl<<endl<<"*********************************************************************************************************";
				cout<<endl<<"Press any key to continue........................................";
				file1.close();		
		}
};
class valued:public customer
{
	public:
	bool login(string user,string pass)//login function for customer to gain access to market
    {
        int count;
        string n,u,e,p;
        system("cls");

		ifstream input("valued.txt");
		while(input>>n>>u>>e>>p)
		{
			if(u == user && p == pass || e==user && p==pass)//check if usenamer or email and password match from file
			{
				count=1;
				if(count==1)	
				break;
				system("cls");
				return true;
			}
		}
		input.close();
		if(count==1)
		{
			cout<<"\t\t*****************************************************************************************\n";
			cout<<"\n\t\t\t\t\t\tHello "<<n<<"\n\t\t\t\t\t\tLOGIN SUCESS\n\t\t\t\t\t\tWe're glad that you're here.\n\n";
			cout<<"\t\t*****************************************************************************************\n";
		}
		else
		{
			count1++;
			if(count1==5)//check if five wrong login credentials are given
			{
				cout<<"Too many times wrong credentials program will now close!!!!!!!!!!!!!!!!!!!!";
				exit(0);
				input.close();
			}
			char choice2;//for asking choice of entering credentials again
			cout<<endl<<endl<<"**************************************************************************************"<<endl<<endl;
			cout<<"\nLOGIN ERROR\nPlease check your username and password\n\n\n";
			loop2:
			cout<<"Do you want to enter again!!!!!!!"<<endl<<"(Y for Yes,N for no): ";
			cin>>choice2;
			system("cls");
			if(choice2=='Y'||choice2=='y')
			{
				cout<<endl<<endl<<"***********************************************************************************"<<endl<<endl;
				cout<<"Enter USERNAME OR Email (xyz123@abc.com): ";
				cin>>user;
				cout<<endl<<endl;
				cout<<"Enter password: ";
				pass=passwordinput();
				cout<<endl<<endl<<"***********************************************************************************";
				cout<<endl<<endl<<"Press any key to continue ..................................";
				getch();
				valued v1;
				v1.login(user,pass);//call agian login if username or email or password is wrong 
			}
			else if(choice2=='N'||choice2=='n')
			{
				return false;
			}
			else
			{
				cout<<"Wrong input detected!!!!!!"<<endl;
				cout<<"Please Enter carefully!!!!!!!!!!!"<<endl;
				goto loop2;
			}
		}
	}
	signup()
	{
				ifstream file("valued.txt");
				string n,u,e;
				string p;
				cout<<endl<<endl<<"****************************************************************************************************"<<endl<<endl;
				cout<<"\t\t\tfield marked (*) with this are required!!!!!!!!!!"<<endl<<endl;
				cout<<"Enter e-mail*(xyz123@abc.com): ";
				cin>>email;
				cout<<endl<<endl;
				name=inputstring();
				cout<<endl<<endl;
				cout<<"Enter username *: ";
				cin>>username;
				cout<<endl<<endl;
				cout<<"Enter password*: ";
				password=passwordinput();
				cout<<endl<<endl;
				cout<<"**************************************************************************************************"<<endl<<endl;
				cout<<"Press any key to continue...................................";
				getch();
				system("cls");
				file.clear();
				file.seekg(0, ios::beg);
				while(file>>n>>u>>e>>p)
				{
					if(email==e)
					{
						cout<<"Enter new email!!!"<<endl;
						cin>>email;
						int c=0;
						c=1;
						if(c=1)
						{
							file.clear();
							file.seekg(0, ios::beg);
						}
						
					}
					if(username==u)
					{
						cout<<"Enter new username: ";
						cin>>username;
						int c =0;
						c=1;
						if(c=1)
						{
							file.clear();
							file.seekg(0, ios::beg);
						}
					}
				}
				file.close();
				ofstream file1("valued.txt",ios::app);
				file1<<name<<endl;
				file1<<username<<endl;
				file1<<email<<endl;
				file1<<password<<endl;
				cout<<endl<<endl<<"*********************************************************************************************************";
				cout<<endl<<endl<<"\t\t\t\t\tSIGNUP IS SUCCESSFUL!!!!!!!!!!!!!!!";
				cout<<endl<<endl<<"\t\t\t\t\tYOUR CODE IS 8800";
				cout<<endl<<endl<<"*********************************************************************************************************";
				cout<<endl<<"Press any key to continue........................................";
				file1.close();		
		}
};
class vip:public customer
{
	public:
		bool login(string user,string pass)//login function for customer to gain access to market
    	{	
	        int count;
	        string n,u,e,p;
	        system("cls");
	
			ifstream input("vip.txt");
			while(input>>n>>u>>e>>p)
			{
				if(u == user && p == pass || e==user && p==pass)//check if usenamer or email and password match from file
				{
					count=1;
					if(count==1)	
					break;
					system("cls");
					return true;
				}
			}
			input.close();
			if(count==1)
			{
					cout<<"\t\t*****************************************************************************************\n";
					cout<<"\n\t\t\t\t\t\tHello "<<n<<"\n\t\t\t\t\t\tLOGIN SUCESS\n\t\t\t\t\t\tWe're glad that you're here.\n\n";
					cout<<"\t\t*****************************************************************************************\n";
			}
			else
			{
					count1++;
					if(count1==5)//check if five wrong login credentials are given
					{
						cout<<"Too many times wrong credentials program will now close!!!!!!!!!!!!!!!!!!!!";
						exit(0);
						input.close();
					}
					char choice2;//for asking choice of entering credentials again
					cout<<endl<<endl<<"**************************************************************************************"<<endl<<endl;
					cout<<"\nLOGIN ERROR\nPlease check your username and password\n\n\n";
					loop2:
					cout<<"Do you want to enter again!!!!!!!"<<endl<<"(Y for Yes,N for no): ";
					cin>>choice2;
					system("cls");
					if(choice2=='Y'||choice2=='y')
					{
						cout<<endl<<endl<<"***********************************************************************************"<<endl<<endl;
						cout<<"Enter USERNAME OR Email (xyz123@abc.com): ";
						cin>>user;
						cout<<endl<<endl;
						cout<<"Enter password: ";
						pass=passwordinput();
						cout<<endl<<endl<<"***********************************************************************************";
						cout<<endl<<endl<<"Press any key to continue ..................................";
						getch();
						vip i1;
						i1.login(user,pass);//call agian login if username or email or password is wrong 
					}
					else if(choice2=='N'||choice2=='n')
					{
						return false;
					}
					else
					{
						cout<<"Wrong input detected!!!!!!"<<endl;
						cout<<"Please Enter carefully!!!!!!!!!!!"<<endl;
						goto loop2;
					}
			}
		}
	public:
		signup()
		{
				ifstream file("vip.txt");
				string n,u,e;
				string p;
				cout<<endl<<endl<<"****************************************************************************************************"<<endl<<endl;
				cout<<"\t\t\tfield marked (*) with this are required!!!!!!!!!!"<<endl<<endl;
				cout<<"Enter e-mail*(xyz123@abc.com): ";
				cin>>email;
				cout<<endl<<endl;
				cout<<"Enter name*: ";
				name=inputstring();
				cout<<endl<<endl;
				cin>>username;
				cout<<endl<<endl;
				cout<<"Enter password*: ";
				password=passwordinput();
				cout<<endl<<endl;
				cout<<"**************************************************************************************************"<<endl<<endl;
				cout<<"Press any key to continue...................................";
				getch();
				system("cls");
				file.clear();
				file.seekg(0, ios::beg);
				while(file>>n>>u>>e>>p)
				{
					if(email==e)
					{
						cout<<"Enter new email!!!"<<endl;
						cin>>email;
						int c=0;
						c=1;
						if(c=1)
						{
							file.clear();
							file.seekg(0, ios::beg);
						}
					}
					if(username==u)
					{
						cout<<"Enter new username: ";
						cin>>username;
						int c =0;
						c=1;
						if(c=1)
						{
							file.clear();
							file.seekg(0, ios::beg);
						}
					}
				}
				file.close();
				ofstream file1("vip.txt",ios::app);
				file1<<name<<endl;
				file1<<username<<endl;
				file1<<email<<endl;
				file1<<password<<endl;
				cout<<endl<<endl<<"*********************************************************************************************************";
				cout<<endl<<endl<<"\t\t\t\t\tSIGNUP IS SUCCESSFUL!!!!!!!!!!!!!!!";
				cout<<endl<<endl<<"\t\t\t\t\tYOUR CODE IS 9900";
				cout<<endl<<endl<<"*********************************************************************************************************";
				cout<<endl<<"Press any key to continue........................................";
				file1.close();			
	}
};


class Inventory
{    
   
	int itemNo;
	int qty;
	
	public:
	friend class manager;	
	void deleteInventory(int id, Inventory &i) ;
	void displayData(Inventory &at);
	void getdata();
	void addInventory ( Inventory &i );
    void updateInventory(int id,  Inventory &at);
	void decrementInventory(int id,  Inventory &at);
	int ShowReport()
 	{
 		char chr;
 		ifstream i("Report.txt");	
		while(i)
		{
			i.get(chr);
			cout<<chr;
		}
		i.close();
		return 0;
	}
	friend ostream & operator << (ostream &out, const Inventory & obj){
     out << obj.itemNo << " " <<obj.qty<<"\n";
     return out;
     }
    /* 
    * Read data from stream object and fill it in member variables
    */
    friend istream & operator >> (istream &in,  Inventory &obj){
     in >> obj.itemNo;
     in >> obj.qty;
     return in;
     }

	void set_qty(int qt)	{ qty = qt;	}	
	int get_qty(){ return qty;	}	 
	
	void set_itemNo(int in)	{ itemNo = in;	}	
	int get_itemNo(){ return itemNo;	}	 	 
};

void Inventory::addInventory( Inventory &i )
{   
    int pID;
    int pQty;
    cout<<"Enter product id and qty\n";
    cin>>pID;
    cin>>pQty;
    i.set_itemNo(pID);
    i.set_qty(pQty);
	ofstream add("inventory1.txt",ios::app|ios::out|ios::ate);
	add<<i;
	add.close();
	getch();
	cout<<"Item added successfully\n";
	getch();
}

void Inventory::getdata(){
    char ch;
    cin.get(ch);
    cout<<"Enter id : ";
    cin>>itemNo;
    cout<<"Enter Qty : ";
    cin>>qty;				
    cout<<"\n";
}

void Inventory::displayData(Inventory &at){
    ifstream dis("inventory1.txt",ios::in);
    dis.seekg(0);
    cout<<"ID \t" <<"QTY\n";
    while(!dis.eof())
    {  dis >> at;
       cout<<at.get_itemNo()<<"\t";
       cout<<at.get_qty()<<"\t"<<"\n";
    }
    dis.close();
    
}

void Inventory::decrementInventory(int id,  Inventory &at) //to decrement inventory in a file
{  
   int a; 
   fstream file;
   file.open("inventory1.txt",ios::in|ios::out|ios::ate);
   if(!file)
   {
   	cout<<"file cannot be opnned"<<endl;
   }
   else{
    //object stores file data
   int rec=0;  //counter to set pointer in file
    file.seekg(0);
	while(!file.eof()){ 
        file >> at; 	
   	    rec++;
   	    if(at.get_itemNo() == id){   
   	   	a = at.get_qty();
   	   	--a;
   	   	at.set_qty(a);
   	   	int location = (rec-1)*(sizeof(at));  //calculates pointer to set it back to updated object location in file
   	   	file.seekp(location);
  	   	file << at << endl;  //write object back to file
			  	  }
	}
	file.close();   
    }
}

void Inventory::updateInventory(int id, Inventory &at) //to update inventory in a file
{  
   int settingQty;
   cout<<"Enter amount of qty: ";
   cin>>settingQty;
   int a; 
   fstream file;
   file.open("inventory1.txt",ios::in|ios::out|ios::ate);
   if(!file)
   {
   	cout<<"file cannot be opnned"<<endl;
   }
   else{
    //object stores file data
    int rec=0;  //counter to set pointer in file
    file.seekg(0);
	while(!file.eof()){ 
        file >> at; 	
   	    rec++;
   	    if(at.get_itemNo() == id){   
   	   	at.set_qty(settingQty);
   	   	int location = (rec-1)*(sizeof(at));  //calculates pointer to set it back to updated object location in file
   	   	file.seekp(location);
  	   	file << at << endl;  //write object back to file
			  	  }
	}
	file.close();   
    }
   
}
void Inventory::deleteInventory(int id, Inventory &i){
	
	ofstream temp;
	ifstream inv;

    inv.open("inventory1.txt",ios::in|ios::ate);  //opens up original file and a temp file
    if(!inv)
    {
    	cout<<"file could not be opened"<<endl;
	}
	else
	{
		temp.open("temp.txt",ios::out|ios::ate|ios::trunc);
		inv.seekg(0);
	    while(!inv.eof())
	    {  
	     inv >> i;
	    	if(i.get_itemNo() != id)
	    	{
	           temp << i ;  
	    	}
		}
		
	}
    
	inv.close();
	temp.close();
	getch();
	cout<<"Item deleted successfully\n";
	getch();
	remove("inventory1.txt");
	rename("temp.txt","inventory1.txt");	
}






bool maindisplay()
{
	cout<<"****************************************************************************************************************************"<<endl<<endl<<endl;
    cout<<"\t\t****** *        *   *****   *****    ******  *******  *******   ****   ****   *******  *****  *******"<<endl;
	cout<<"\t\t*        *     *    *   *   *   *    *       *        *         *   * *   *   *     *  *   *     * "<<endl;
	cout<<"\t\t*         *   *     *   *   *   *    *       *        *         *    *    *   *     *  *   *     *"<<endl;
	cout<<"\t\t******     * *      *****   * * *    *****   *******  *******   *    *    *   *******  * **      *"<<endl;
	cout<<"\t\t*         *   *     *       * *      *             *        *   *         *   *     *  * *       *"<<endl;
	cout<<"\t\t*        *     *    *       *  *     *             *        *   *         *   *     *  *  *      *"<<endl;
	cout<<"\t\t****** *         *  *       *   *    ******  *******  *******   *         *   *     *  *   *     *"<<endl<<endl<<endl;
	cout<<"****************************************************************************************************************************"<<endl<<endl;
	cout<<"MAKE YOUR LIFE EASIER !!!!!!!!!!!!!!!!!!!"<<endl;
	cout<<"ANYTHING YOU NEED WE ARE HERE TO FULLFILL IT.............."<<endl;
	cout<<"GOT ANY COMPLAINTS ......."<<endl;
	cout<<"Contact us at (+92)3110237524"<<endl;
	cout<<endl<<endl<<"Press any key to continue.............................";
	getch();
	
	return true;
}
main()
{
	
    int code,code1,count,count1;
    bool a,b;//for checking the person has logged in or not
    string user,pass;
    char choice,choice1,choice2;
    maindisplay();
    system("cls");
    do
    {
		loop1:	//for getting back to main choices
		cout<<endl<<endl<<"*********************************************************************************************************"<<endl<<endl;
    	cout<<endl<<"1) For Customer"<<endl<<endl<<endl<<"2) For Manager"<<endl<<endl<<endl<<"3) For Exit"<<endl<<endl;
    	cout<<endl<<endl<<"*********************************************************************************************************"<<endl<<endl;
    	cout<<endl<<"ENTER YOUR CHOICE: ";
		cin>>choice;    
	    system("cls");
	    switch(choice)
	    {	
    		case '1':
	        {	
	        	do
	        	{
	           		loop:
	           		cout<<endl<<endl<<"*********************************************************************************************************"<<endl<<endl;
	           		cout<<"\nDo You Want To Login OR Sign up\n\n\n1) For Login\n\n\n2) For Signup\n\n\n3) For Back To Selection\n\n\n ";
	           		cout<<endl<<endl<<"*********************************************************************************************************"<<endl<<endl;
	       			cout<<"\nENTER YOUR CHOICE: ";
		        	cin>>choice2;
		        	system("cls");
		        	switch(choice2)
		        	{
		        		case '1':
		        		{
				        	char cho;
				        	int g=0;
				        	AGAIN:
				        	cout<<"Are you a Normal or VIP or Valued Customer.......(N for normal,I for VIP,V for Valued): ";
				        	cin>>cho;
				        	if(cho!='v'&&cho!='V'&&cho!='n'&&cho!='N'&&cho!='i'&&cho!='I')
							{
								g=g+1;
								if(g==5)
								{
									cout<<"Wrong choice !!!!!!!!!!!!!!!!!!!!!!!\nBack to main menu......"<<endl;
									cout<<"Press any key to continue!!!!";
									getch();
									system("cls");
								}
								else
								{
								cout<<"Wrong choice !!!!!!!!!!!!!!!!!!!!!!!"<<endl;
								cout<<"Press any key to continue!!!!";
								getch();
								system("cls");
								goto AGAIN;
								}
							}
				        	if(cho=='V'||cho=='v')
				        	{
				        		cout<<"Enter your valued customer code: ";
				        		cin>>code;
				        		if(code==8800)
				        		{
					        		valued v1;
					        		cout<<endl<<endl<<"***********************************************************************************"<<endl<<endl;
									cout<<"Enter USERNAME OR Email (xyz123@abc.com): ";
									cin>>user;
									cout<<endl<<endl;
									cout<<"Enter password: ";
									pass=passwordinput();
									cout<<endl<<endl<<"***********************************************************************************";
									cout<<endl<<endl<<"Press any key to continue ..................................";
									getch();
									a=v1.login(user,pass);
									if(a==1)
									{
										cout<<endl<<"Valued customer!!!!!!"<<endl;
					                	getch();
					                	cout<<endl<<endl;
					                	v1.buying();
									}
									else
									{
										cout<<"Login Error!!!!!!!!!!!!"<<endl<<endl;
										cout<<"Press Any key to continue.....................";
										getch();
										system("cls");
									}
								}
								else
								{
									cout<<"Wrong code!!!!!!!!!!!!"<<endl;
									cout<<"Press Any key to continue.....................";
									getch();
									system("cls");
								}
							}
							if(cho=='N'||cho=='n')
				        	{
				        		cout<<"Enter your Normal customer code: ";
				        		cin>>code;
				        		if(code==7700)
				        		{
					        		normal n1;
					        		cout<<endl<<endl<<"***********************************************************************************"<<endl<<endl;
									cout<<"Enter USERNAME OR Email (xyz123@abc.com): ";
									cin>>user;
									cout<<endl<<endl;
									cout<<"Enter password: ";
									pass=passwordinput();
									cout<<endl<<endl<<"***********************************************************************************";
									cout<<endl<<endl<<"Press any key to continue ..................................";
									getch();
									a=n1.login(user,pass);
									if(a==1)
									{
										cout<<endl<<"Normal customer!!!!!!"<<endl;
					                	getch();
					                	cout<<endl<<endl;
					                	n1.buying();
									}
									else
									{
										cout<<"Login Error!!!!!!!!!!!!"<<endl<<endl;
										cout<<"Press Any key to continue.....................";
										getch();
										system("cls");
									}
								}
								else
								{
									cout<<"Wrong code!!!!!!!!!!!!"<<endl;
									cout<<"Press Any key to continue.....................";
									getch();
									system("cls");
								}
							}
							if(cho=='I'||cho=='i')
				        	{
				        		cout<<"Enter your VIP customer code: ";
				        		cin>>code;
				        		if(code==9900)
				        		{
					        		vip i1;
					        		cout<<endl<<endl<<"***********************************************************************************"<<endl<<endl;
									cout<<"Enter USERNAME OR Email (xyz123@abc.com): ";
									cin>>user;
									cout<<endl<<endl;
									cout<<"Enter password: ";
									pass=passwordinput();
									cout<<endl<<endl<<"***********************************************************************************";
									cout<<endl<<endl<<"Press any key to continue ..................................";
									getch();
									a=i1.login(user,pass);
									if(a==1)
									{
										cout<<endl<<"VIP customer!!!!!!"<<endl;
					                	getch();
					                	cout<<endl<<endl;
					                	i1.buying();
									}
									else
									{
										cout<<"Login Error!!!!!!!!!!!!"<<endl<<endl;
										cout<<"Press Any key to continue.....................";
										getch();
										system("cls");
									}
								}
								else
								{
									cout<<"Wrong code!!!!!!!!!!!!"<<endl;
									cout<<"Press Any key to continue.....................";
									getch();
									system("cls");
								}
							}
							else
							{
								getch();
								system("cls");		
							}
							break;
						}
			        	case '2':
			        	{
			        		char choi;
			        		customer m1;
			        		cout<<endl<<endl<<"******************************************************************************************************"<<endl<<endl;
			        		cout<<"Sign up Categories!!!!!!!!!!!!!"<<endl<<endl;
			        		cout<<"1) Normal Customer: The most basic type of customer having 24/7 market support usually having no discounts on purchases!!!!!!"<<endl<<endl;
			        		cout<<"2) Valued Customer: A More prestige type of customer having 24/7 support market mostly getting benefits of new discounted rates!!!!"<<endl<<endl;
							cout<<"3) Vip Customer: Our most loyal customer type having 24/7 market support getting the new and updated things before anyone else\nand getting most discounted offers"<<endl<<endl;
							cout<<"Enter the customer type you want to signup in\n\nN for Normal customer\n\nV for Valued Customer\n\nI for VIP customer\n\nChoice: ";
							cin>>choi;
							if(choi=='n'||choi=='N')
							{
								normal n1;
								n1.signup();
							}
							if(choi=='v'||choi=='V')
							{
								valued v1;
								v1.signup();
							}
							if(choi=='i'||choi=='I')
							{
								vip i1;
								i1.signup();
							}
							else
							{
								cout<<endl<<"Back to menu!!!!!!!!!!!!! ";
							}
			        		getch();
			        		system("cls");
			        		break;
						}
						case '3':
						{
							system("cls");
							break;
						}
						default:
						{
							cout<<"You have inputted wrong please renter your choice again!!!!!!"<<endl;
			        		goto loop;
							break;
						}
	        		}
    			}
		    	while(choice2<=2);
		    	break;
		    }
    		case '2':
    		{
    				cout<<endl<<endl<<"********************************* MANAGER PORTAL *******************************************"<<endl<<endl;
    				cout<<"Please enter the following details"<<endl<<endl;
            		cout<<"USERNAME or Email (abc123@xyz.com): ";
            		cin>>user;
            		cout<<endl<<endl;
            		cout<<"PASSWORD :";
            		pass=passwordinput();
            		cout<<endl<<endl;
            		cout<<"**************************************************************************************";
            		cout<<endl<<endl<<"Press any key to continue...........................";
            		getch();
            		cout<<endl<<endl;
    				manager m1;
					b=m1.login(user,pass);
					cout<<endl<<endl<<"Press any key to continue..............";
					getch();
					if(b==1)
					{   
					    int pID;
						int choice3;
						char ch;
						system("cls");
						do{
						cout<<endl<<endl<<"*****************************************************************************************"<<endl<<endl;
						cout<<endl<<endl<<"What operations you want to perform\n\n1 For Getting all item detail\n\n2 For adding stock of a item\n\n3 For Deleting an item\n\n4 For getting weekly report\n\n5 Update Stock\n\n6 to Exit\n\nEnter Choice: ";
						cin>>choice3;
						switch(choice3)
						{
							case 1:
								system("cls");
								Inventory i1;
								cout<<"\tInventory\n\n";
								i1.displayData(i1);
								cout<<endl<<endl<<"Press any key to continue........................";
								getch();
								system("cls");
								break;
							case 2:
								system("cls");
								Inventory i2;
								i2.addInventory(i2);
								system("cls");
								break;
							case 3:
								system("cls");
								cout<<"Enter product id to be deleted\n";
								cin>>pID;
								Inventory i3;
								i3.deleteInventory(pID,i3);
								system("cls");
								break;
						    case 4:
						    	system("cls");
						    	Inventory i4;
						    	i4.ShowReport();
						    	cout<<endl<<endl<<"Press any key to continue...............";
						    	getch();
						    	
						    	system("cls");
						    	break;
						    case 5:
						    	system("cls");
							    Inventory i5;
							    cout<<"Enter product id";
								cin>>pID;
								i5.updateInventory(pID,i5);
								system("cls");			
							default:
							   break;		
						}
					    }while(choice3!=6);
					}
					system("cls");
					break;
			}
			case '3':
			{
				cout<<"Thanyou Sir for Your Visiting!";
				exit(0);
				break;
			}
			default:
			{
				cout<<"Please reneter your choice: "<<endl;
				goto loop1;	
			}
        }
	}
	while(choice);
}
