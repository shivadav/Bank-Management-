#include<iostream.h>
#include<stdlib.h>
#include<conio.h>
#include<fstream.h>
#include<ctype.h>
#include<String.h>
#include<iomanip.h>
#include<dos.h>
#include<process.h>	
#include<stdio.h>

// Functions used
int check(int ac);                                         // to check account no. availability   (no use)
int chk(char n[]);                                       // to check user's name
int pswrdchk(char a[]);                           // to check the password
void insert();                                             // to insert a record in a file
void deposit();                                        // for depositing
void withdrawal();                                 // for withdrawal
void del();                                               // for deletion of account
void select();                                          // for selected view
void modify();                                         // for modification
void intro();                                     
void pass();
void dip();
void menu();
void help();
void temp();

// Class declaration
class banking
{
int acnt_no;
char name[30];
char ad[100];
double bal;

public:
char pswrd[20];
void getdata();                                             // to enter data from user
void showdata();                                         // to show data on screen
void showtable();                                        // to show tabular data
void dep_with(char a,double n);            // for deposit and withdrawal
void disp();                                                 // for display during deposit and withdrawal
int retacnt();                                             // to return account number
void change_data(char ch);                 // used in case of modification
int retbal();                                             // to return balance
};

void banking::getdata()
{
	int x,t,n;
	acnt_no=32767;
	y2:
	gotoxy(5,8);
	cout<<"Enter your name           :                  ";
	gotoxy(33,8);
	gets(name);
	t=chk(name);
	if(!t)
	{goto y2;}

	gotoxy(5,10);
	cout<<"Enter address             : ";
	gets(ad);

	y3:
	gotoxy(5,12);
	cout<<"Enter your password       :             ";
	gotoxy(45,2);
	cout<<"password should be of 6 chars ";
       gotoxy(33,12);
       gets(pswrd);
       delay(100);
       gotoxy(33,12);
       cout<<"**********";
       n=pswrdchk(pswrd);
       if(!n)
       {goto y3;}

       gotoxy(26,23);
       cout<<"Creating account ...........";
       for(int i=0;i<6;i++)
       {
		delay(500);
		cout<<".";
       }
       //gotoxy(26,23);
       //cout<<"ACCOUNT CREATED..                 ";
       bal=500.0;

       y1:
       gotoxy(5,4);
       randomize();
       acnt_no=random(acnt_no);
       x=check(acnt_no);
       if(!x)
       {goto y1;}
       else
       cout<<"Your account number :"<<acnt_no;

       delay(1800);
       clrscr();
}

void banking::showdata()
{
	clrscr();
	gotoxy(10,5);
	cout<<"Account number   :"<<acnt_no;
	gotoxy(10,7);
	cout<<"Name of user     :"<<name;
	gotoxy(10,9);
	cout<<"Address of user  :"<<ad;
	gotoxy(10,11);
	cout<<"Balance of user  :"<<bal;
	gotoxy(10,13);
	cout<<"Password of user :"<<pswrd;
}



int banking::retacnt()
{
	return(acnt_no);
}


int banking::retbal()
{
	return bal;
}

void banking::showtable()
{

cout<<acnt_no<<"        ";
cout<<name<<"             ";
cout<<bal<<"            ";
cout<<pswrd<<"         ";
cout<<ad;
cout<<endl;

}


void banking::dep_with(char a,double n)
{
switch(a)
	{
	case 'd':

	bal=bal+n;
	n=0.0;
	break;

	case 'w':
	bal=bal-n;
	n=0.0;
	break;
	}
}


void banking::disp()
{
gotoxy(45,11);
cout<<"Name of user    :"<<name;
gotoxy(45,13);
cout<<"Address of user :"<<ad;
gotoxy(45,15);
cout<<"Balance of user :"<<bal;
}



void banking::change_data(char ch)
{
	int t,n;
	switch(ch)
	{
	case 'n':
		y2:
	gotoxy(5,8);
	cout<<"Enter your name           :                  ";
	gotoxy(33,8);
	gets(name);
	t=chk(name);
	if(!t)
	{goto y2;}
	break;

	case 'd':
	gotoxy(5,8);
	cout<<"Enter address             : ";
	gets(ad);
	break;

	case 'p':
		y3:
	gotoxy(5,8);
	cout<<"Enter your password       :             ";
	gotoxy(45,2);
	cout<<"password should be of 6 chars ";
       gotoxy(33,8);
       gets(pswrd);
       delay(100);
       gotoxy(33,8);
       cout<<"**********";
       n=pswrdchk(pswrd);
       if(!n)
       {goto y3;}
       break;

       default:

	x2:
	gotoxy(5,8);
	cout<<"Enter your name           :                  ";
	gotoxy(33,8);
	gets(name);
	t=chk(name);
	if(!t)
	{goto x2;}


	gotoxy(5,10);
	cout<<"Enter address             : ";
	gets(ad);


	x3:
	gotoxy(5,12);
	cout<<"Enter your password       :             ";
	gotoxy(45,2);
	cout<<"password should be of 6 chars ";
       gotoxy(33,12);
       gets(pswrd);
       delay(100);
       gotoxy(33,12);
       cout<<"**********";
       n=pswrdchk(pswrd);
       if(!n)
       {goto x3;}

       }
}





// functions used

// To prevent tow similar account no.
int check(int ac)
{


	banking obj;
	ifstream x("bank.dat",ios::binary);
	while(x.read((char*)&obj,sizeof(obj)))
	{
		if(obj.retacnt()==ac)
		{

			x.close();
			return 0;
		}
	}
	x.close();
	return 1;
}



// To check user's name

int chk(char n[])
{
	int m=0,i;
	for(i=0;i<strlen(n);i++)
	{
		if(!(isalpha(n[i])||n[i]==' '))
		m++;
	}
	if(m!=0)
	{       gotoxy(45,2);
		cout<<"Invalid name                  ";
		delay(800);
		gotoxy(45,2);
		cout<<"                              ";

		return 0;
	}
	return 1;
}



// To check the password

int pswrdchk(char a[])
{
gotoxy(45,2);
cout<<"                              ";
	if(!(strlen(a)==6))
	{       gotoxy(45,2);
		cout<<"Warning..!!                   ";
		delay(1000);
		gotoxy(45,2);
		cout<<"                              ";
	       //	gotoxy(45,3);
	       //	cout<<"pswrd should be of min 6 char ";
	       //	gotoxy(10,9);
	       //	cout<<"enter another password  :";
		return 0;
	}


	return 1;
}


// To insert a record in a file

void insert()
{
	clrscr();
	banking obj;
	ofstream y;

	x:
	clrscr();
	gotoxy(5,6);
	cout<<"Enter the details";
	char a;
	obj.getdata();

	x1:
	gotoxy(26,23);
	cout<<"sure to create this account(y/n)..";
	a=getch();

	switch(a)
	{
	case 'y':
	break;
	case 'n':
	return;
	default:
	goto x1;
	}
	clrscr();
	gotoxy(30,12);
	cout<<"ACCOUNT CREATED";
	delay(1000);
	y.open("bank.dat",ios::binary|ios::app);
	y.write((char*)&obj,sizeof(obj));
	y.close();

	x2:
	clrscr();
	gotoxy(26,23);
	cout<<"Want to create more account(y/n)..";
	a=getch();
	switch(a)
	{
	case 'y':
	goto x;
	case 'n':
	return;
	default:
	goto x2;
	}
}

// for depositing
void deposit()
{
	clrscr();
	int ac;
	int c=0;
	double b;
	char ps[20];

	banking obj;



	fstream mod;
	mod.open("bank.dat",ios::binary|ios::in|ios::out);

	if(mod.eof())
	{       cout<<"File could not be open !! Press any Key...";
		getch();
		mod.close();
		return;
	}
	dip();
	gotoxy(36,5);
	cout<<"DEPOSIT";

	gotoxy(5,8);
	cout<<"Enter account number  :         ";
	gotoxy(28,8);
	cin>>ac;

	while(!mod.eof()&&c==0)
	{
		mod.read((char*)&obj,sizeof(obj));

		if(obj.retacnt()==ac)
		{
			c=1;
			y2:
			gotoxy(5,10);
			cout<<"Enter your password  :          ";
			gotoxy(27,10);
			gets(ps);
			delay(100);
			gotoxy(27,10);
			cout<<"*********";

			if(strcmpi(obj.pswrd,ps)!=0)
			{
				gotoxy(45,2);
				cout<<"Incorrect password..!!     ";
				delay(800);
				gotoxy(45,2);
				cout<<"                           ";
				goto y2;
			}

			obj.disp();
			gotoxy(5,12);
			cout<<"Enter amount to be deposited  :";
			cin>>b;
			obj.dep_with('d',b);

		       //	obj.bal=obj.bal+b;
		       int pos=-1*sizeof(obj);
			mod.seekp(pos,ios::cur);
			mod.write((char*)&obj,sizeof(obj));
			mod.close();
			clrscr();
			gotoxy(30,12);
			cout<<"TRANSACTION COMPLETE..!!";
			delay(1000);
			break;
		}
	}
	if(c==0)
	{
		gotoxy(45,2);
		cout<<"Invalid account number..!!";
		delay(1000);
		gotoxy(45,2);

		cout<<"                          ";
		mod.close();
		return;
	}
       //	m.close();
}

// For withdrawal

void withdrawal()
{
	clrscr();
	int ac;
	int c=0;
	double b;
	char ps[20];

	banking obj;


	fstream nod;
	nod.open("bank.dat",ios::binary|ios::in|ios::out);

	if(nod.eof())
	{       cout<<"File could not be open !! Press any Key...";
		getch();
		nod.close();
		return;
	}

	dip();
	gotoxy(35,5);
	cout<<"WITHDRAWAL";

	gotoxy(5,8);
	cout<<"Enter account number  :         ";
	gotoxy(28,8);
	cin>>ac;

	while(!nod.eof()&&c==0)
	{
		nod.read((char*)&obj,sizeof(obj));
		if(obj.retacnt()==ac)
		{
			c=1;
			y2:
			gotoxy(5,10);
			cout<<"Enter your password  :          ";
			gotoxy(27,10);
			gets(ps);
			delay(100);
			gotoxy(27,10);
			cout<<"*********";
			if(strcmpi(obj.pswrd,ps)!=0)
			{
				gotoxy(45,2);
				cout<<"Incorrect password..!!     ";
				delay(800);
				gotoxy(45,2);
				cout<<"                           ";
				goto y2;
			}

			obj.disp();
			gotoxy(5,12);
			cout<<"Enter withdrawal amount  :";
			cin>>b;
			if((b+500.0)<=obj.retbal())
			{
				obj.dep_with('w',b);
				int pos=-1*sizeof(obj);
				nod.seekp(pos,ios::cur);
				nod.write((char*)&obj,sizeof(obj));
				nod.close();
				clrscr();
				gotoxy(30,12);
				cout<<"TRANSACTION COMPLETE..!!";
				delay(1000);
				break;
			}
			else
			{
				gotoxy(45,2);
				cout<<"Withdrawal not possible..!!";
				delay(1500);
				gotoxy(45,2);
				cout<<"                           ";
				clrscr();
				gotoxy(30,12);
				cout<<"TRANSACTION FAILED..!!";
				delay(1000);
				break;
			}
		}
	}
	if(c==0)
	{
		gotoxy(45,2);
		cout<<"Invalid account number..!! ";
		delay(1000);
		gotoxy(45,2);
		cout<<"                           ";
		nod.close();
		return;
	}
       //	n.close();
}



// For tabular view

void table()
{       clrscr();
	banking obj;
	ifstream p("bank.dat",ios::binary);

	if(p.eof())
	{
		cout<<"File could not open!!Press any key..";
		getch();
		p.close();
		return;
	}
      //	dip();
	gotoxy(35,3);
	cout<<"ALL RECORDS";
	for(int i=0;i<80;i++)
	{
	gotoxy(i,4);

	cout<<(char)(223); }
	cout<<endl<<endl;
	cout<<"Act no.       Name            Balance        Password       Address"<<endl;

	while(p.read((char*)&obj,sizeof(obj)))
	{
		obj.showtable();
	}
	p.close();
	getch();
}


// for selected view
void select()
{
	clrscr();
	int a,c=0;
	banking obj;


	ifstream k("bank.dat",ios::binary);
	gotoxy(32,5);
	cout<<"SELECTED VIEW";

	gotoxy(5,8);
	cout<<"Enter account number  :         ";
	gotoxy(28,8);
	cin>>a;

	while(!k.eof())
	{
		k.read((char*)&obj,sizeof(obj));
		if(obj.retacnt()==a)
		{
			c=1;
			obj.showdata();

			break;
		}
	}
	k.close();

	if(c==0)
	{
		gotoxy(45,2);
		cout<<"Invalid account number..!! ";
		delay(800);
		gotoxy(45,2);
		cout<<"                           ";
		return;
	}
	getch();
}


// For deletion of record
void del()
{
	clrscr();
	int ac,c=0;
	char a='o';
	banking obj;
	ifstream de;
	de.open("bank.dat",ios::binary);
	if(de.eof())
	{
		gotoxy(45,2);
		cout<<"File could not open!!Press any key..";
		getch();
		de.close();
		return;
	}

	 dip();
	gotoxy(5,8);
	cout<<"Enter account number  :         ";
	gotoxy(28,8);
	cin>>ac;

	while(!de.eof())
	{
		de.read((char*)&obj,sizeof(obj));
		if(obj.retacnt()==ac)
		{
			//c=1;
			gotoxy(45,9);
			cout<<"Details";
			obj.disp();

			y1:
			gotoxy(26,23);
			cout<<"Sure to delete account(y/n)..";
			a=getch();
			c=1;
			switch(a)
			{
				case 'y':
				clrscr();
				gotoxy(30,12);
				cout<<"ACCOUNT DELETED";
				delay(1000);
				break;
				case 'n':
				clrscr();
				de.close();
				getch();
				return;
				default:
				goto y1;
			}
		}
		if(a=='y')
		break;
	}

	if(c==0)
	{       gotoxy(45,2);
		cout<<"Account not exist..!!";
		delay(1500);
		de.close();
		return;
	}
	ofstream ne;
	ne.open("temp.dat");
	de.seekg(0,ios::beg);
	while(de.read((char*)&obj,sizeof(obj)))
	{

		if(obj.retacnt()!=ac)
		{
			ne.write((char*)&obj,sizeof(obj));
		}
	}
	ne.close();
	de.close();
	remove("bank.dat");
	rename("temp.dat","bank.dat");

       getch();
}


// For modification of record
void modify()
{
	clrscr();
	int ac,c=0,m;
	char ch;
	dip();
	banking obj;
	fstream modi;
	modi.open("bank.dat",ios::binary|ios::in|ios::out);
	if(modi.eof())
	{
		cout<<"File could not open!!Press any key..";
		getch();
		modi.close();
		return;
	}
	gotoxy(5,8);
	cout<<"Enter acnt. no. to be modified :";
	cin>>ac;

	while(!modi.eof())
	{
		modi.read((char*)&obj,sizeof(obj));
		if(obj.retacnt()==ac)
		{
			c=1;
			gotoxy(50,9);
			cout<<"Previous details";
			obj.disp();
			getch();
			clrscr();

			y1:
			dip();
			gotoxy(27,9);
			cout<<"Modify procedure";
			gotoxy(30,11);
			cout<<"N -> Name";
			gotoxy(30,13);
			cout<<"D -> Address";
			gotoxy(30,15);
			cout<<"P -> Password";
			gotoxy(30,17);
			cout<<"A -> All";
			ch=getch();
			clrscr();
			if(ch=='n'||ch=='a'||ch=='d'||ch=='p');
			else
			goto y1;

			obj.change_data(ch);
			int pos=(-1*sizeof(obj));
			modi.seekp(pos,ios::cur);
			modi.write((char*)&obj,sizeof(obj));
			clrscr();
			gotoxy(30,12);
			cout<<"Record updated";
			delay(1500);
			break;
		}
	}
	modi.close();

	if(c==0)
	{
	gotoxy(45,2);
	cout<<"Account does not exist";
	delay(1000);
	}
}


void pass()
{
	clrscr();
	dip();
	int c=0;
	char a[10]="winlof";
	char b[10];

	x1:
	gotoxy(5,12);
	cout<<"Enter password  :            ";
	gotoxy(23,12);
	gets(b);
	delay(200);
	gotoxy(23,12);
	cout<<"**********";

	if(strcmpi(a,b)==0);

	else
	{
		c++;
		gotoxy(45,2);
		cout<<"Wrong password..!!";
		delay(1000);
		gotoxy(45,2);
		cout<<"                  ";

		if(c<2)
		goto x1;

		else
		{
			clrscr();
			gotoxy(20,14);
			cout<<"You have exceeded the limit..!!";
			delay(1000);
			clrscr();
			gotoxy(25,14);
			cout<<"Program terminating..";
			for(int i=0;i<=6;i++)
			{
			cout<<".";
			delay(500);
			}
			clrscr();
			exit(0);
		}
	}
}



void intro()
{
int i;
	clrscr();
	gotoxy(33,18);
	cout<<"Please wait..";
	for(i=32;i<47;i++)
	{       gotoxy(i,19);
		cout<<(char)(223);
		gotoxy(i,20);
		cout<<(char)(223);
	}
	i=0;

	gotoxy(32,19);
	cout<<(char)(219);
	gotoxy(46,19);
	cout<<(char)(219);

	gotoxy(32,19);
	for(i=1;i<=15;i++)
	{
		cout<<(char)(219);
		if(i<6)
		delay(300);
		else if(i>=6&&i<=10)
		delay(700);
		else
		delay(300);
	}
       //	getch();
}


void menu()
{

	clrscr();
	 int i;
	 dip();
	 for(i=2;i<79;i++)
		{
		 gotoxy(i,3);
		cout<<(char)(223);
		}
	 gotoxy(35,2);
	cout<<"BANKING ";


	for(i=50;i<75;i++)
	{
		gotoxy(i,6);
		cout<<(char)(223);
	}
	for(i=50;i<75;i++)
	{
		gotoxy(i,9);
		cout<<(char)(223);
	}
	for(i=10;i<35;i++)
	{
		gotoxy(i,6);
		cout<<(char)(223);
	}
	for(i=10;i<35;i++)
	{
		gotoxy(i,9);
		cout<<(char)(223);
	}
	for(i=10;i<35;i++)
	{
		gotoxy(i,12);
		cout<<(char)(223);
	}
	for(i=10;i<35;i++)
	  {
	   gotoxy(i,15);
	   cout<<(char)(223);
	   }
	    for(i=10;i<35;i++)
	    {
	    gotoxy(i,18);
	    cout<<(char)(223);
	    }
    for(i=10;i<35;i++)
    {
    gotoxy(i,21);
    cout<<(char)(223);
    }
     gotoxy(14,4);
     cout<<"Create new account";

     gotoxy(18,7);
     cout<<"Withdrawal";

     gotoxy(19,10);
     cout<<"Deposit";

     gotoxy(17,13);
     cout<<"view Balance";

     gotoxy(20,16);
     cout<<"Modify";

     gotoxy(21,19);
     cout<<"Help";

     gotoxy(22,22);
     cout<<"Exit";

     gotoxy(59,4);
     cout<<"Removal";

     gotoxy(55,7);
     cout<<"Tabular view";

     gotoxy(2,24);
     cout<<"Press CAPITAL letter to cont...";
     temp();


}


void dip()
{
	int i;
	for(i=2;i<79;i++)
	{
		gotoxy(i,1);
		cout<<(char)(223);
		gotoxy(i,25);
		cout<<(char)(220);

	}

	for(i=1;i<=25;i++)
	{
		gotoxy(79,i);
		cout<<(char)(177);
		gotoxy(1,i);
		cout<<(char)(177);
	 }
}



void help()
{
	clrscr();
	dip();
	gotoxy(15,5);
	cout<<"Press 'C' for creating new account";
	gotoxy(15,7);
	cout<<"Press 'W' for withdrawal";
	gotoxy(15,9);
	cout<<"Press 'D' for depositing";
	gotoxy(15,11);
	cout<<"Press 'B' for balance and details";
	gotoxy(15,13);
	cout<<"Press 'M' for change/modify";
	gotoxy(15,15);
	cout<<"Press 'R' for deletiom of an account";
	gotoxy(15,17);
	cout<<"Press 'T' for tabular view";
	gotoxy(15,19);
	cout<<"Press 'H' for help menu";
	gotoxy(15,21);
	cout<<"Press 'E' for exiting the program";
	getch();

 }


void temp()
{
	char a;
	a=getch();

	switch(a)
	{
	case 'c':
	insert();
	break;
	case 'd':
	deposit();
	break;
	case 'w':
	withdrawal();
	break;
	case 'r':
	del();
	break;
	case 'b':
	select();
	break;
	case 'm':
	modify();
	break;
	case 'h':
	help();
	break;
	case 't':
	table();
	break;
	case 'e':
	clrscr();
	delay(800);
	exit(0);
	case 'i':
	remove("bank.dat");
	break;

	}


}

void main()
{
	intro();
	pass();

	while(1)
	{
	clrscr();
	menu();
	}
       //	getch();
}
