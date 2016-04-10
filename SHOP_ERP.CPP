#include<conio.h>
#include<iostream.h>
#include<stdio.h>
#include<string.h>
#include<fstream.h>
#include<dos.h>
#include<process.h>
#include<stdlib.h>
#include<ctype.h>

#define PWD 10
#define NM 25
#define ADD 10
#define PHO
#define SIZER 10
char a[10]; //Global String
  // ITEM CLASS
class item
{
  public:
  int itemcode;
  char itemname[NM];
  long int itemcost,itemprice;
  int d1, m1, y1 ;
  void add_item();
  void del_item();
  void mod_item();
  void date();

}i;
 // STOCK CLASS
class stock : public item
{
	   public:
	   int qty;
	   void add_item();
	   void add_stock();
	   void mod_stock();
	   void dis_stock();
		void dis_item();
}s ;
  // CUSTOMER CLASS
class customer
{
   public:
   int cust_id;
   char cust_name[NM],cust_add[ADD];
   char phone[PHO];
   void add_cust();
   void del_cust();
   void mod_cust();
   void dis_cust();
}c;
 // BILL CLASS
class bill: public customer,public stock
{
   public:
   int billno;
   double amt[SIZER];
   double total,btotal;
   int i,c,tcode[SIZER],tprice[SIZER],tqty[SIZER],dis;
   char tname[30][SIZER];
   void create_bill(void);
   void dis_bill(void);
   void cust(void);
   void item(void);
   void stock(int,int);
}b;
class menu
{
  public :
	void main_menu();
	void bill_menu();
	void item_menu();
	void stock_menu();
	void cust_menu();
	void password();
}m;

void ventry(char t[],int);
void pass1(char r[]);
void close(void);
void menu_des(void);
void bill_des(void);
/*	EXTRA FUNCTION		*/
int AreUsure(int i,int j);       // ASK FOR SURE 1-Y 2-N
/*	DISPLAY SQUARE ON SCREE */
void displaySqDL(int i1,int i2,int j1,int j2,int k1,int k2,int l1,int l2);
void displaySq(int i1,int i2,int j1,int j2,int k1,int k2,int l1,int l2);
/*	DISPLAY BAR		*/
void displayRbar(int i1,int j1,int sz);
void displayLbar(int i1,int j1,int sz);
void displayDbar(int i1,int j1,int sz);

/*  MAIN MENU */
void menu::main_menu()
{
	int i;
	char ch,r;
	clrscr();
	menu_des();
	gotoxy(35,5);
	cout<<"M A I N M E N U";
	gotoxy(28,9);
	cout<<"BILL MENU         [B]";
	gotoxy(28,11);
	cout<<"ITEM MENU         [I]";
	gotoxy(28,13);
	cout<<"STOCK MENU        [S]";
	gotoxy(28,15);
	cout<<"CUSTOMER MENU     [C]";
	gotoxy(28,17);
	cout<<"EXIT              [E]";
	gotoxy(24,24);
	cout<<"ENTER YOUR CHOICE      : ";
	cin>>r;
	ch=toupper(r);
	switch(ch)
	{
	 case 'B':
		bill_menu();
		break;
	 case 'I':
		item_menu();
		break;
	 case 'S':
		stock_menu();
		break;
     case 'C':
      	cust_menu();
     	break;
     case 'E' :
	close();
		break;
     default :
     	gotoxy(28,29);
     	cout<<"PLZ,ENTER CORRECT CHOICE";
     	getch();
     	m.main_menu();
   }
}
/******************************* BILL MENU*******************/
void menu::bill_menu(void)
{
	 char r,ch;
	 clrscr();
	 menu_des();
	 textcolor(14);
	 gotoxy(32,5);
	 cprintf(" B I L L  M E N U");
	 gotoxy(28,9);
	 cprintf("CREATE BILL      [C]");
	 gotoxy(28,11);
	 cprintf("DISPLAY BILL     [D]");
	 gotoxy(28,13);
	 cprintf("MAIN MENU        [M]");
	 gotoxy(28,15);
	 cprintf("EXIT             [E]");
	 gotoxy(24,24);
	 cprintf("ENTER YOUR CHOICE : ");
	 cin>>r;
	 ch=toupper(r);
	 switch(ch)
	 {
		case 'C':
			b.create_bill();
			break;
		case 'D':
			b.dis_bill();
			break;
		case 'M':
			m.main_menu();
			break;
		case 'E':
			close();
			break;
		default :
			gotoxy(28,29);
			cout<<"PLZ,ENTER CORRECT CHOICE";
			getch();
			m.bill_menu();
	 }
}

/******************************* ITEM MENU*******************/
void menu::item_menu()
{
	 char ch,r;
	 menu_des();
	 textcolor(14);
	 gotoxy(32,5);
	 cprintf(" I T E M  M E N U");
	 gotoxy(28,9);
	 cprintf("ADD NEW ITEM        [A]");
	 gotoxy(28,11);
	 cprintf("UPDATE ITEM         [U]");
	 gotoxy(28,13);
	 cprintf("REMOVE ITEM         [R]");
	 gotoxy(28,15);
	 cprintf("DISPLAY ITEM        [D]");
	 gotoxy(28,17);
	 cprintf("MAIN MENU           [M]");
	 gotoxy(28,19);
	 cprintf("EXIT                [E]");
	 gotoxy(24,24);
	 cprintf("ENTER YOUR CHOICE : ");
	 cin>>r;
	 ch=toupper(r);
	 switch(ch)
	 {
		case 'A':
			s.add_item();
			break;
		case 'U':
			i.mod_item();
			break;
		case 'R':
			i.del_item();
			break;
		case 'D':
			s.dis_item();
			break;
		case 'M':
			m.main_menu();
			break;
		case 'E':
			close();
			break;
		default :
			gotoxy(28,29);
			cout<<"PLZ,ENTER CORRECT CHOICE";
			getch();
		m.item_menu();
	 }
}

/* STOCK MENU */
void menu::stock_menu()
{
	 char ch,r;
	 menu_des();
	 textcolor(14);
	 gotoxy(32,5);
	 cprintf(" S T O C K  M E N U");
	 gotoxy(28,9);
	 cprintf("ADD NEW STOCK        [A]");
	 gotoxy(28,11);
	 cprintf("UPDATE  STOCK        [U]");
	 gotoxy(28,13);
	 cprintf("DISPLAY STOCK        [D]");
	 gotoxy(28,15);
	 cprintf("MAIN MENU            [M]");
	 gotoxy(28,17);
	 cprintf("EXIT                 [E]");
	 gotoxy(24,24);
	 cprintf("ENTER YOUR CHOICE : ");
	 cin>>r;
	 ch=toupper(r);
	 switch(ch)
	 {
		  case 'A':
			s.add_stock();
			break;
		 case 'U':
			s.mod_stock();
			break;
			 case 'D':
			s.dis_stock();
			break;
			 case 'M':
			m.main_menu();
			break;
			 case 'E':
			close();
			break;
			 default :
		gotoxy(28,29);
		cout<<"PLZ,ENTER CORRECT CHOICE";
			getch();
		m.stock_menu();
	 }
}

  /******************************* CUSTOMER MENU*******************/
void menu::cust_menu()
{
	 char  r,ch;
	 menu_des();
	 textcolor(14);
	 gotoxy(32,5);
	 cprintf(" C U S T O M E R  M E N U");
	 gotoxy(28,9);
	 cprintf("ADD NEW CUSTOMER        [A]");
	 gotoxy(28,11);
	 cprintf("UPDATE CUSTOMER DETAIL  [U]");
	 gotoxy(28,13);
	 cprintf("REMOVE CUSTOMER DETAIL  [R]");
	 gotoxy(28,15);
	 cprintf("DISPLAY CUSTOMER DETAIL [D]");
	 gotoxy(28,17);
	 cprintf("MAIN MENU               [M]");
	 gotoxy(28,19);
	 cprintf("EXIT                    [E]");
	 gotoxy(24,24);
	 cprintf("ENTER YOUR CHOICE : ");
	 cin>>r;
	 ch=toupper(r);
	 switch(ch)
	 {
		case 'A':
	  c.add_cust();
	  break;
		case 'U':
	 c.mod_cust();
		 break;
		case 'R':
	 c.del_cust();
		 break;
		case 'D':
	 c.dis_cust();
		 break;
		case 'M':
	 m.main_menu();
		 break;
		case 'E':
	 close();
		 break;
		default :
		 gotoxy(28,29);
		 cout<<"PLZ,ENTER CORRECT CHOICE";
		 getch();
		 m.cust_menu();
	 }
}
/*******************  ADD NEW ITEM  *********************/
void stock :: add_item(void)
{

	int count=0;
	char a[10],ch;
	menu_des();
	textcolor(14);
	gotoxy(28,5);
	cprintf("A D D I T E M  M E N U");
	ifstream additem("ITEM.TXT",ios::in);
	if(additem!=NULL)
	{
		while(!additem.eof())
		{
			additem>>itemcode>>itemname;
			count=itemcode;
			count++;
		}
	itemcode=count;
	gotoxy(20,8);
	cout<<"           ITEM CODE :        "<<itemcode;
		displaySq(44,7,58,7,44,9,58,9);
	gotoxy(20,11);
	cout<<"           ITEM NAME :";

	displaySq(44,10,58,10,44,12,58,12);
	gotoxy(48,11);
	ventry(itemname,0);

	gotoxy(20,14);
	cout<<"ITEM UNIT COST PRICE :     ";
	displaySq(44,13,58,13,44,15,58,15);
	gotoxy(48,14);
	ventry(a,1);
	itemcost = atoi(a);
	gotoxy(20,17);
	cout<<"ITEM UNIT SALE PRICE :     ";

	displaySq(44,16,58,16,44,18,58,18);
	gotoxy(48,17);
	ventry(a,1);
	itemprice = atoi(a);
	gotoxy(20,20);
	cout<<"            ITEM QTY :     ";
	displaySq(44,19,58,19,44,21,58,21);
	gotoxy(48,20);
	ventry(a,1);
	qty = atoi(a);

	gotoxy(20,24);

   }
   else
   {
	itemcode=1;
	gotoxy(20,8);
	cout<<"           ITEM CODE :        "<<itemcode;
		displaySq(44,7,58,7,44,9,58,9);
	gotoxy(20,11);
	cout<<"           ITEM NAME :";

	displaySq(44,10,58,10,44,12,58,12);
	gotoxy(48,11);
	ventry(itemname,0);

	gotoxy(20,14);
	cout<<"ITEM UNIT COST PRICE :     ";
	displaySq(44,13,58,13,44,15,58,15);
	gotoxy(48,14);
	ventry(a,1);
	itemcost = atoi(a);
	gotoxy(20,17);
	cout<<"ITEM UNIT SALE PRICE :     ";

	displaySq(44,16,58,16,44,18,58,18);
	gotoxy(48,17);
	ventry(a,1);
	itemprice = atoi(a);
	gotoxy(20,20);
	cout<<"            ITEM QTY :     ";
	displaySq(44,19,58,19,44,21,58,21);
	gotoxy(48,20);
	ventry(a,1);
	qty = atoi(a);
   }
   additem.close();
   gotoxy(20,24);
   cout<<"SAVE ITEM INFORMATION (Y/N):";
   cin>>ch;
  if(ch=='y' ||ch=='Y')
  {   ofstream additem1("ITEM.TXT",ios::app);
	  additem1<<itemcode<<"\t"<<itemname<<"\n";
	  additem1.close();
	  ofstream app_stock("STOCK.TXT",ios::app);
	  app_stock<<itemcode<<"\t"<<itemname<<"\t"<<itemcost<<"\t"<<itemprice<<"\t"<<qty<<"\n";
	  app_stock.close();
   }
  else
  {
	m.item_menu();
  }
   gotoxy(20,24);
   clreol();
   gotoxy(20,24);
   cout<<"ADD MORE ITEM (Y/N):";
   cin>>ch;
  if(ch=='y'||ch=='Y')
  {
	  add_item();
  }
  else
  {
	 m.item_menu();
  }
}
 /*UPDATE ITEM INFORMATION*/
void item :: mod_item()
{
	int no,count=0;
	char a[10];
	menu_des();
	gotoxy(25,5);
	cout<<"U P D A T E  I T E M  M E N U";
	gotoxy(28,9);
	cout<<"ENTER ITEM CODE : ";
	cin>>no;
	ifstream mod_item("ITEM.TXT",ios::in);
	ofstream temp("TEMP.TXT",ios::app);
	while(1)
	{
		mod_item>>itemcode;
		mod_item>>itemname;
		if(mod_item.eof())
		{
		 break;
		}
		else
		{
			if(itemcode == no)
			{
					count=1;
					gotoxy(20,11);
					cout<<"ITEM CODE";
					gotoxy(30,11);
					cout<<"ITEM NAME";

					gotoxy(50,11);
					cout<<"ITEM NAME(Short)";
					gotoxy(4,12);
					cout<<"---------------------------------------------------------------------------";
					gotoxy(20,13);
					cout<<itemcode;
					gotoxy(30,13);
					cout<<itemname;
					gotoxy(28,16);
					cout<<"ITEM CODE : "<<itemcode;
					gotoxy(28,18);
					cout<<"ITEM NAME : ";
					ventry(itemname,0);
					temp<<itemcode<<"\t"<<itemname<<"\n";
			}
			else
			{
					temp<<itemcode<<"\t"<<itemname<<"\n";
			}
		}
		}
	temp.close();
	mod_item.close();
	remove("ITEM.TXT");
	rename("TEMP.TXT","ITEM.TXT");
	if(count==0)
	{
		gotoxy(24,24);
		cout<<"RECORD NOT FOUNT";
		   getch();
	}
	else
	{
		gotoxy(24,24);
		cout<<" FILE SUCESSFULLY UPDATED >> :";
		getch();
	}
	m.item_menu();
}

/*DISPLAY ITEM*/

void stock :: dis_item()
{
	int i;
	ifstream dis_stock("STOCK.TXT",ios::in);
	clrscr();
	menu_des();
	gotoxy(27,5);
	cout<<"D I S P L A Y  I T E M  M E N U";
	displaySqDL(17,8,40,8,17,22,40,22);
	displaySqDL(52,8,79,8,52,22,79,22);
	//displaySq(62,10,79,10,62,21,79,23);
	gotoxy(3,8); cprintf("ฬ");
	for(i=4;i<=78;i++)
	{
		if(i==17||i==40||i==52)
			cprintf("ห");
		else
			cprintf("อ");
	}cprintf("น");
	gotoxy(3,10); cprintf("ฬ");
	for(i=4;i<=78;i++)
	{
		if(i==17||i==40||i==52)
			cprintf("ฮ",197);
		else
			cprintf("อ",196);
	}cprintf("น");
	gotoxy(3,22); cprintf("ฬ");
	for(i=4;i<=78;i++)
	{
		if(i==17||i==40||i==52)
			cprintf("ส");
		else
			cprintf("อ");
	}
	cprintf("น");
	gotoxy(5,9);
	cout<<"ITEM CODE";
	gotoxy(25,9);
	cout<<"ITEM NAME";
	gotoxy(42,9);
	cout<<"ITEM COST";
	gotoxy(55,9);
	cout<<"ITEM PRICE";
	i=10;
	while(1)
	{
		dis_stock>>itemcode;
		if(itemcode==0)
				break;
		if(dis_stock.eof())
		{
				break;
		}
		else
		{
				i=i+1;
			dis_stock>>itemname;
			dis_stock>>itemcost;
			dis_stock>>itemprice;
			dis_stock>>qty;
			gotoxy(5,i);
			cout<<itemcode;
			gotoxy(25,i);
			cout<<itemname;
			gotoxy(45,i);
			cout<<itemcost;
			gotoxy(55,i);
			cout<<itemprice;

		}
	}
	dis_stock.close();
	gotoxy(23,23);
	cout<<"press ENTER To continue >>";
getch();
	m.item_menu();
}

/*REMOVE ITEM INFORMATION*/

void item :: del_item()
{
	int no,count=0;
	menu_des();
	gotoxy(24,5);
	cout<<"R E M O V E  I T E M  M E N U";
	gotoxy(24,9);
	cout<<"ENTER ITEM CODE :  ";
	cin>>no;
	ifstream del_item("ITEM.TXT",ios::in);
	ofstream temp("TEMP.TXT",ios::app);
	while(1)
	{

		del_item>>itemcode;
		del_item>>itemname;
		if(del_item.eof())
		{
		 break;
		}
		else
		{
			if(itemcode == no)
			{
				 count=1;
					 gotoxy(20,11);cout<<"ITEM CODE";
					 gotoxy(30,11);cout<<"ITEM NAME";
					 gotoxy(4,12);cout<<"---------------------------------------------------------------------------";
					 gotoxy(20,13);cout<<itemcode;
				 gotoxy(30,13);cout<<itemname;
			}
			else
			{
					temp<<itemcode<<"\t"<<itemname<<"\n";
			}
		}
	 }
	temp.close();
	del_item.close();
	remove("ITEM.TXT");
	rename("TEMP.TXT","ITEM.TXT");
	if(count==0)
	{
		gotoxy(24,24);
		cout<<"RECORD NOT FOUNT";
		   getch();
	}
	else
	{
		gotoxy(24,24);
		cout<<" FILE SUCESSFULLY deleye.";
		getch();
	}
	m.item_menu();
}

/*ADD NEW STOCK*/

void stock :: add_stock(void)
{
   int no,flag=0;
   char a[10],ch;
   menu_des();
   gotoxy(24,5);
   cout<<"A D D  N E W  S T O C K  M E N U";
	gotoxy(20,8);
	cout<<"           ITEM CODE :";
	displaySq(44,7,58,7,44,9,58,9);
   gotoxy(48,8);
   cin>>no;
   ifstream open_item("ITEM.TXT",ios::in);
   while(!open_item.eof())
   {
		open_item>>itemcode;
		open_item>>itemname;
		if(itemcode == no)
		{
			 flag=1;
			 gotoxy(20,11);
			 cout<<"           ITEM NAME :     "<<itemname;
			displaySq(44,10,58,10,44,12,58,12);
			gotoxy(48,11);
			gotoxy(20,14);
			cout<<"ITEM UNIT COST PRICE :     ";
			displaySq(44,13,58,13,44,15,58,15);
			gotoxy(48,14);
			ventry(a,1);
			itemcost = atoi(a);
			gotoxy(20,17);
			cout<<"ITEM UNIT SALE PRICE :     ";
			displaySq(44,16,58,16,44,18,58,18);
			gotoxy(48,17);
			ventry(a,1);
			itemprice = atoi(a);
			gotoxy(20,20);
			cout<<"            ITEM QTY :     ";
			displaySq(44,19,58,19,44,21,58,21);
			gotoxy(48,20);
			ventry(a,1);
			qty = atoi(a);
			gotoxy(20,24);
			cout<<"SAVE STOCK INFORMATION (Y/N):";
			cin>>ch;
			 if(ch=='y' ||ch=='Y')
			 {
				 ofstream app_stock("STOCK.TXT",ios::app);
				 app_stock<<itemcode<<"\t"<<itemname<<"\t"<<itemcost<<"\t"<<itemprice<<"\t"<<qty<<"\n";
					 app_stock.close();
			 }
			  else
			 {
				 m.stock_menu();
			  }
			  gotoxy(20,24);
			  clreol();
			  gotoxy(20,24);
			  cout<<"ADD MORE STOCK (Y/N):";
			  cin>>ch;
			  if(ch=='y'||ch=='Y')
			  {
				  add_stock();
			  }
			  else
			  {
				 m.stock_menu();
			  }
					 break;
		}
	}
	if(flag != 1)
	{
		gotoxy(32,24);
		cout<<"Record Not Found........";
		getch();
	}
	open_item.close();
	 m.stock_menu();
 }
/*UPDATE STOCK INFORMATION*/
void stock :: mod_stock()
{
	int no,count=0;
	char a[10];
	menu_des();
	gotoxy(24,5);
	cout<<"U P D A T E  S T O C K  M E N U";
	gotoxy(28,8);
	cout<<"ENTER ITEM CODE : ";
	cin>>no;
	gotoxy(28,8);
	clreol();
	gotoxy(79,8);
	cout<<"บ";
	ifstream mod_stock("STOCK.TXT",ios::in);
	ofstream temp("TEMP.TXT",ios::app);
	while(1)
	{       mod_stock>>itemcode;
		mod_stock>>itemname;
		mod_stock>>itemcost;
		mod_stock>>itemprice;
		mod_stock>>qty;
		if(mod_stock.eof())
		{
			break;
		}
		else
		{
			if(itemcode == no)
			{
				count=1;
				gotoxy(5,9);
				cout<<"ITEM CODE";
				gotoxy(15,9);
				cout<<"ITEM NAME";
				gotoxy(28,9);
				cout<<"ITEM COST";
				gotoxy(40,9);
				cout<<"ITEM PRICE";
				gotoxy(50,9);
				cout<<"ITEM QTY";
				gotoxy(4,10);
				cout<<"--------------------------------------------------------------------------";
				gotoxy(5,11);
				cout<<itemcode;
				gotoxy(15,11);
				cout<<itemname;
				gotoxy(28,11);
				cout<<itemcost;
				gotoxy(40,11);
				cout<<itemprice;
				gotoxy(50,11);
				cout<<qty;
					gotoxy(28,13);
					cout<<"ITEM CODE: "<<itemcode;
					gotoxy(28,15);
					cout<<"ITEM NAME : "<<itemname;
					gotoxy(28,17);
					cout<<"ITEM UNIT COST PRICE : ";
					ventry(a,1);
					itemcost = atoi(a);
					gotoxy(28,19);
					cout<<"ITEM UNIT SALE PRICE : ";
					ventry(a,1);
					itemprice = atoi(a);
					gotoxy(28,21);
					cout<<"ITEM QTY : ";
					ventry(a,1);
					qty=qty+atoi(a);
					temp<<itemcode<<"\t"<<itemname<<"\t"<<itemcost<<"\t"<<itemprice<<"\t"<<qty<<"\n";
			}
			else
			{
					temp<<itemcode<<"\t"<<itemname<<"\t"<<itemcost<<"\t"<<itemprice<<"\t"<<qty<<"\n";
			}
		}
		}
	temp.close();
	mod_stock.close();
	remove("STOCK.TXT");
	rename("TEMP.TXT","STOCK.TXT");
	if(count==0)
	{
		gotoxy(24,24);
		cout<<"RECORD NOT FOUNT.....";
		   getch();
	}
	else
	{
	gotoxy(24,24);
	cout<<" FILE SUCESSFULLY UPDATED............";
	getch();
	}
	m.stock_menu();
}
/*DISPLAY STOCK*/
void stock::dis_stock()
{
	int i;
	ifstream dis_stock("STOCK.TXT",ios::in);
	clrscr();
	menu_des();
	gotoxy(27,5);
	cout<<"D I S P L A Y  S T O C K  M E N U";
	displaySqDL(17,8,40,8,17,22,40,22);
	displaySqDL(52,8,66,8,52,22,66,22);
	//displaySq(62,10,79,10,62,21,79,23);
	gotoxy(3,8); cprintf("ฬ");
	for(i=4;i<=78;i++)
	{
		if(i==17||i==40||i==52||i==66)
			cprintf("ห");
		else
			cprintf("อ");
	}cprintf("น");
	gotoxy(3,10); cprintf("ฬ");
	for(i=4;i<=78;i++)
	{
		if(i==17||i==40||i==52||i==66)
			cprintf("ฮ",197);
		else
			cprintf("อ",196);
	}cprintf("น");
	gotoxy(3,22); cprintf("ฬ");
	for(i=4;i<=78;i++)
	{
		if(i==17||i==40||i==52||i==66)
			cprintf("ส");
		else
			cprintf("อ");
	}
	cprintf("น");
	gotoxy(5,9);
	cout<<"ITEM CODE";
	gotoxy(25,9);
	cout<<"ITEM NAME";
	gotoxy(42,9);
	cout<<"ITEM COST";
	gotoxy(55,9);
	cout<<"ITEM PRICE";
	gotoxy(68,9);
	cout<<"ITEM QTY";
	i=10;
	while(1)
	{
		dis_stock>>itemcode;
		if(itemcode==0)
				break;
		if(dis_stock.eof())
		{
				break;
		}
		else
		{
				i=i+1;
			dis_stock>>itemname;
			dis_stock>>itemcost;
			dis_stock>>itemprice;
			dis_stock>>qty;
			gotoxy(5,i);
			cout<<itemcode;
			gotoxy(25,i);
			cout<<itemname;
			gotoxy(45,i);
			cout<<itemcost;
			gotoxy(55,i);
			cout<<itemprice;
			gotoxy(68,i);
			cout<<qty;
		}
	}
	dis_stock.close();
	gotoxy(23,23);
	cout<<"press ENTER To continue >>";

	getch();
	m.stock_menu();
}

/*ADD NEW CUSTOMER*/

void customer :: add_cust(void)
{
   int count=0;
   char a[10],ch;
   menu_des();
   gotoxy(24,5);
   cout<<"A D D  N E W  C U S T O M E R  M E N U";
   ifstream addcust("CUSTOMER.TXT",ios::in);
   if(addcust!=NULL)
   {
   while(!addcust.eof())
   {
	 addcust>>cust_id>>cust_name>>cust_add;
	 count=cust_id;
	 count++;
   }
   cust_id=count;
   gotoxy(28,9);
   cout<<"CUSTOMER CODE : "<<cust_id;
   gotoxy(28,11);
   cout<<"CUSTOMER NAME : ";
   gotoxy(48,11);
   ventry(cust_name,0);
   gotoxy(28,13);
   cout<<"CUSTOMER ADDRESS : ";
   gotoxy(48,13);
   ventry(cust_add,0);

   }
   else
   {
		cust_id=1;
		gotoxy(28,9);
		cout<<"CUSTOMER CODE : "<<cust_id;
		gotoxy(28,11);
		cout<<"CUSTOMER NAME : ";
		gotoxy(48,11);
		ventry(cust_name,0);
		gotoxy(28,13);
		cout<<"CUSTOMER ADDRESS : ";
		gotoxy(48,13);
		ventry(cust_add,0);
		gotoxy(48,15);

   }
   addcust.close();
   gotoxy(20,24);
   cout<<"SAVE CUSTOMER INFORMATION (Y/N):";
   cin>>ch;
  if(ch=='y' ||ch=='Y')
  {
	 ofstream addcust1("CUSTOMER.TXT",ios::app);
	 addcust1<<cust_id<<"\t"<<cust_name<<"\t"<<cust_add<<"\n";
	 addcust1.close();
   }
  else
  {
	  m.cust_menu();
  }
   gotoxy(20,24);
   //clreol();
   gotoxy(20,24);
   cout<<"ADD MORE CUSTOMER (Y/N):";
   cin>>ch;
   if(ch=='y'||ch=='Y')
   {
	  add_cust();
   }
   else
   {
	 m.cust_menu();
   }
}

/*UPDATE ITEM INFORMATION*/

void customer :: mod_cust()
{
	int no,count=0;
	char a[10];
	menu_des();
	gotoxy(24,5);
	cout<<"U P D A T E  C U S T O M E R  M E N U";
	gotoxy(28,8);
	cout<<"ENTER CUSTOMER ID: ";
	cin>>no;
	ifstream mod_cust("CUSTOMER.TXT",ios::in);
	ofstream temp("TEMP.TXT",ios::app);
	while(1)
	{    	mod_cust>>cust_id;
		mod_cust>>cust_name;
		mod_cust>>cust_add;
		if(mod_cust.eof())
		{
			break;
		}
		else
		{
			if(cust_id == no)
			{
					count=1;
					gotoxy(10,9);
					cout<<"CUSTOMER ID";
					gotoxy(22,9);cout<<"CUSTOMER NAME";
					gotoxy(36,9);cout<<"CUSTOMER ADDRESS";
					gotoxy(4,10);cout<<"---------------------------------------------------------------------------";
					gotoxy(10,11);cout<<cust_id;
					gotoxy(22,11);cout<<cust_name;
					gotoxy(36,11);cout<<cust_add;
					gotoxy(28,13);
					cout<<"CUSTOMER ID : "<<cust_id;
					gotoxy(28,15);
					cout<<"CUSTOMER NAME : ";
					ventry(cust_name,0);
					gotoxy(28,17);
					cout<<"CUSTOMER ADDRESS : ";
					ventry(cust_add,0);
					temp<<cust_id<<"\t"<<cust_name<<"\t"<<cust_add<<"\n";
			}
		else
		{
			  temp<<cust_id<<"\t"<<cust_name<<"\t"<<cust_add<<"\n";
		}
	}
}
	temp.close();
	mod_cust.close();
	remove("CUSTOMER.TXT");
	rename("TEMP.TXT","CUSTOMER.TXT");
	if(count==0)
	{
		gotoxy(24,24);
		cout<<"RECORD NOT FOUNT";
		   getch();
	}
	else
	{
	gotoxy(24,24);
	cout<<" FILE SUCESSFULLY UPDATED..........";
	getch();
	}
	m.cust_menu();

}
/*DISPLAY ITEM*/
void customer :: dis_cust()
{       int i=10;
	ifstream dis_cust("CUSTOMER.TXT",ios::in);
	menu_des();
	gotoxy(24,5);
	cout<<"D I S P L A Y  C U S T O M E R  M E N U";
	displaySqDL(17,8,40,8,17,22,40,22);
	//displaySqDL(52,8,66,8,52,22,66,22);
	//displaySq(62,10,79,10,62,21,79,23);
	gotoxy(3,8); cprintf("ฬ");
	for(i=4;i<=78;i++)
	{
		if(i==17||i==40)
			cprintf("ห");
		else
			cprintf("อ");
	}cprintf("น");
	gotoxy(3,10); cprintf("ฬ");
	for(i=4;i<=78;i++)
	{
		if(i==17||i==40)
			cprintf("ฮ",197);
		else
			cprintf("อ",196);
	}cprintf("น");
	gotoxy(3,22); cprintf("ฬ");
	for(i=4;i<=78;i++)
	{
		if(i==17||i==40)
			cprintf("ส");
		else
			cprintf("อ");
	}
	cprintf("น");

	gotoxy(6,9);
	cout<<"CUSTOMER ID";
	gotoxy(20,9);
	cout<<"CUSTOMER NAME";
	gotoxy(44,9);
	cout<<"CUSTOMER ADDRESS";
	i=11;
	while(1)
	{
		dis_cust>>cust_id;
		if(cust_id==0)
			break;
		if(dis_cust.eof())
		 {
				break;
		 }
		else
		{
			i=i+1;
			dis_cust>>cust_name;
			dis_cust>>cust_add;
			gotoxy(6,i);
			cout<<cust_id;
			gotoxy(20,i);
			cout<<cust_name;
			gotoxy(44,i);
			cout<<cust_add;

		 }
	}
	dis_cust.close();
	getch();
	m.cust_menu();
}

/*REMOVE ITEM INFORMATION*/

void customer :: del_cust()
{
	int no,count=0;
	menu_des();
	gotoxy(24,6);
	cout<<"R E M O V E  C U S T O M E R M E N U";
	gotoxy(28,8);
	cout<<"ENTER CUSTOMER ID : ";
	cin>>no;
	gotoxy(28,8);
	clreol();
	gotoxy(79,8);
	cout<<"บ";
	ifstream del_cust("CUSTOMER.TXT",ios::in);
	ofstream temp("TEMP.TXT",ios::app);
	while(1)
	{
		del_cust>>cust_id;
		del_cust>>cust_name;
		del_cust>>cust_add;
		if(del_cust.eof())
		{
			 break;
		}
		else
		{
			if(cust_id == no)
			{
					count=1;
					gotoxy(10,9);
					cout<<"CUSTOMER ID";
					gotoxy(22,9);cout<<"CUSTOMER NAME";
					gotoxy(36,9);cout<<"CUSTOMER ADDRESS";
					gotoxy(4,10);cout<<"---------------------------------------------------------------------------";
					gotoxy(10,11);cout<<cust_id;
					gotoxy(22,11);cout<<cust_name;
					gotoxy(36,11);cout<<cust_add;
			}
			else
			{
					temp<<cust_id<<"\t"<<cust_name<<"\t"<<cust_add<<"\n";
			}
		}
		}
	temp.close();
	del_cust.close();
	remove("CUSTOMER.TXT");
	rename("TEMP.TXT","CUSTOMER.TXT");
	if(count==0)
	{
		gotoxy(24,24);
		cout<<"RECORD NOT FOUNT";
		   getch();
	}
	else
	{
		gotoxy(24,24);
		cout<<"REMOVE SUCESSFULLY ..........";
		getch();
	}
	m.cust_menu();
}

void bill :: create_bill(void)
{

   int count=0,no;
   char ch;
   c=1;
   clrscr();
   bill_des();
   gotoxy(60,5);
   date();
   gotoxy(26,3);
   cout<<"\xDB\xDB\xDB\xDB\xB2  SMART SHOP ERP  \xB2\xDB\xDB\xDB\xDB";
   ifstream addbill("BILL.TXT",ios::in);
   if(addbill!=NULL)
   {
   while(!addbill.eof())
   {
	 addbill>>billno>>c>>cust_id>>cust_name>>cust_add;
	 for(int i=1;i<=c;i++)
	 {
		addbill>>tcode[i]>>tname[i]>>tprice[i]>>tqty[i]>>amt[i];

	 }
	 addbill>>total>>dis>>btotal;
	 count=billno;
	 count++;
	}
	c=1;
	total=0;
	billno=count;
	gotoxy(7,5);
	cout<<"BILL : "<<billno;
	gotoxy(4,11);
	cout<<"SRNO.";
	gotoxy(13,11);
	cout<<"ITEM CODE";
	gotoxy(25,11);
	cout<<"ITEM NAME";
	gotoxy(43,11);
	cout<<"RATE";
	gotoxy(53,11);
	cout<<"QTY";
	gotoxy(65,11);
	cout<<"AMOUNT";
	b.cust();
	tcode[1]=0;
	tprice[1]=0;
	tqty[1]=0;
	b.item();
 }
 else
 {
	billno=1;
	gotoxy(7,5);
	cout<<"BILL : "<<billno;
	gotoxy(4,11);
	cout<<"SRNO.";
	gotoxy(13,11);
	cout<<"ITEM CODE";
	gotoxy(25,11);
	cout<<"ITEM NAME";
	gotoxy(43,11);
	cout<<"RATE";
	gotoxy(53,11);
	cout<<"QTY";
	gotoxy(65,11);
	cout<<"AMOUNT";
	b.cust();
	tcode[1]=0;
	tprice[1]=0;
	tqty[1]=0;
	b.item();

  }
   addbill.close();
   getch();
   m.bill_menu();
}

void bill::cust()
{
		int no;
		int flag=0;
		gotoxy(7,6);
		cout<<"CUSTOMER ID : ";
		ventry(a,1);
		no= atoi(a);
		gotoxy(79,6);
		cout<<"ณ";
	ifstream open_cust("CUSTOMER.TXT",ios::in);
	while(!open_cust.eof())
	{
		open_cust>>cust_id;
		open_cust>>cust_name;
		open_cust>>cust_add;
		if(cust_id == no)
		{
			 flag=1;
			 gotoxy(7,7);
			 cout<<"CUSTOMER NAME : "<<cust_name;
			 gotoxy(7,8);
			 cout<<"CUSTOMER ADDRESS : "<<cust_add;
			 b.item();
			 break;
		}
	}
	if(flag != 1)
	{
		gotoxy(25,24);
		cout<<" << Record Not Found. >> :: ";
		getch();
		gotoxy(25,24);
		clreol();
		gotoxy(79,24);
		cout<<"ณ";
		b.cust();
	}
	open_cust.close();
}
void bill::item()
{      int no,sqty;
	   char a[10],ch,r;
	   item:
	   int flag=0;
	   gotoxy(6,12+c);
	   cout<<c;
	   gotoxy(13,12+c);
	   ventry(a,1);
	   no = atoi(a);
	   ifstream open_item("STOCK.TXT",ios::in);
	while(!open_item.eof())
	{
		open_item>>itemcode;
		open_item>>itemname;
		open_item>>itemcost;
		open_item>>itemprice;
		open_item>>qty;
		if(itemcode == no)
		{
		displaySq(10,21,22,21,10,25,22,25);
		displaySq(40,21,50,21,40,25,50,25);
		displaySq(62,21,79,21,62,25,79,25);
		gotoxy(3,21); cprintf("ร");
		for(i=4;i<=78;i++)
		{
			if(i==10||i==22||i==40||i==50)
				cprintf("ล");
			else
				cprintf("ฤ");
		}	cprintf("ด");
		gotoxy(3,23); cprintf("ร");
		for(i=4;i<=78;i++)
		{
			if(i==10||i==22||i==40||i==50)
				cprintf("ล");
			else
				cprintf("ฤ");
		}cprintf("ด");
		gotoxy(3,25); cprintf("ภ");
		for(i=4;i<=78;i++)
		{
			if(i==10||i==22||i==40||i==50)
				cprintf("ม");
			else
				cprintf("ฤ");
		}cprintf("ู");
			gotoxy(12,22);
			cout<<"A_ITEM CODE";
			gotoxy(24,22);
			cout<<"A_ITEM NAME";
			gotoxy(43,22);
			cout<<"A_RATE";
			gotoxy(52,22);
			cout<<"A_QTY";
			 gotoxy(13,24);
			 cout<<itemcode;
			 gotoxy(25,24);
			 cout<<itemname;
			 gotoxy(43,24);
			 cout<<itemprice;
			 gotoxy(53,24);
			 cout<<qty;
			 flag=1;
			 gotoxy(22,12+c);
			 cout<<"ณ";
			 gotoxy(23,12+c);
			 cout<<itemname;
			 gotoxy(40,12+c);
			 cout<<"ณ";
			 gotoxy(41,12+c);
			 cout<<itemprice;
			 gotoxy(50,12+c);
			 cout<<"ณ";
			 gotoxy(3,21); cprintf("ร");
			 for(i=4;i<=78;i++)
			 {
				cprintf("ฤ");
			 }
			 cprintf("ด");

			 gotoxy(51,12+c);
			 ventry(a,1);
			 sqty = atoi(a);
			 gotoxy(2,24);
			clreol();
			gotoxy(2,22);
			clreol();
			gotoxy(2,23);
			clreol();
			displaySq(3,2,79,2,3,25,79,25);
			gotoxy(3,21); cprintf("ร");
			 for(i=4;i<=78;i++)
			 {
				cprintf("ฤ");
			 }
			 cprintf("ด");


			 if(qty-sqty<=0)
			 {
				//gotoxy(10,24);
				gotoxy(25,24);
				cout<<"<< NOT A STOCK >> :: ";
				getch();
				//gotoxy(11,12+c);
				//gotoxy(23,12+c);
				//gotoxy(40,12+c);
				//gotoxy(51,12+c);
				goto item;

			 }
			else
			{
				gotoxy(62,12+c);
				cout<<"ณ";
				gotoxy(66,12+c);
				amt[c]=sqty*itemprice;
				cout<<amt[c];
				gotoxy(79,12+c);
				cout<<"ณ";
				gotoxy(3,24);
				clreol();
				gotoxy(79,24);
				cout<<"ณ";
				total=total+amt[c];
				break;
			 }
		}
	 }
	if(flag != 1)
	{
		gotoxy(25,24);
		cout<<" << Record Not Found >> ::";
		getch();
		gotoxy(15,24);
		clreol();
		gotoxy(79,24);
		cout<<"ณ";
		goto item;
	}
	gotoxy(15,24);
	cout<<"ADD MORE ITEM (Y/N) : ";
	cin>>ch;
	r=toupper(ch);
	gotoxy(15,24);
	clreol();
	if(r=='Y')
	{
		tcode[c]=itemcode;
		strcpy(tname[c],itemname);
		tprice[c]=itemprice;
		tqty[c]=sqty;
		c++;
		goto item;
	}
	else
	{
		tcode[c]=itemcode;
		strcpy(tname[c],itemname);
		tprice[c]=itemprice;
		tqty[c]=qty;
	}
	gotoxy(15,24);
	clreol();
	gotoxy(3,24);
	cout<<"ณ";
	gotoxy(79,24);
	cout<<"ณ";
	gotoxy(15,24);
	cout<<"SAVE BILL (Y/N) : ";
	cin>>ch;
	r=toupper(ch);
	gotoxy(15,24);
	clreol();
	if(r=='Y')
	{
	  displaySq(38,21,75,21,38,25,75,25);
	  gotoxy(41,22);
	  cout<<"AMOUNT : ";
	  gotoxy(64,22);
	  cout<<total;
	  dis=total*0.10;
	  btotal=total-dis;
	  gotoxy(41,23);
	  cout<<"DISCOUNT : ";
	  gotoxy(64,23);
	  cout<<dis;
	  gotoxy(41,24);
	  cout<<"TOTAL AMOUNT : ";
	  gotoxy(64,24);
	  cout<<btotal;
	  getch();
	  ofstream outfile("BILL.TXT", ios::app);
	  outfile<<billno<<"\t"<<c<<"\t"<<cust_id<<"\t"<<cust_name<<"\t"<<cust_add<<"\t";
	  for(int i=1;i<=c;i++)
	  {
		outfile<<"\t"<<tcode[i]<<"\t"<<tname[i]<<"\t"<<tprice[i]<<"\t"<<tqty[i]<<"\t"<<amt[i];
		b.stock(tcode[i],tqty[i]);
	  }
	  outfile<<"\t"<<total<<"\t"<<dis<<"\t"<<btotal;
	outfile<<"\n";
	outfile.close();
	m.bill_menu();
	textmode(64);
	}
	else
	{
	 m.bill_menu();
	}
	open_item.close();
}
void bill::dis_bill()
{
	int i;
	ifstream dis_bill("bill.TXT",ios::in);
	clrscr();
	bill_des();
	gotoxy(60,5);
	date();
	gotoxy(26,3);
	cout<<"\xDB\xDB\xDB\xDB\xB2  SMART SHOP ERP  \xB2\xDB\xDB\xDB\xDB";
	gotoxy(40,6);
	cout<<"D I S P L A Y  S T O C K  M E N U";
	gotoxy(1,7);
	while(1)
	{
		dis_bill>>billno;
		if(billno==0)
			break;
		if(dis_bill.eof())
		{
				break;
		}
		else
		{
			dis_bill>>c>>cust_id>>cust_name>>cust_add;
			gotoxy(7,5); cout<<"BILL : "<<billno;
			gotoxy(4,11); cout<<"SRNO.";
			gotoxy(13,11); cout<<"ITEM CODE";
			gotoxy(25,11); cout<<"ITEM NAME";
			gotoxy(43,11); cout<<"RATE";
			gotoxy(53,11); cout<<"QTY";
			gotoxy(65,11); cout<<"AMOUNT";
			gotoxy(7,6);cout<<"CUSTOMER ID:"<<cust_id;
			gotoxy(7,7);cout<<"CUSTOMER NAME:"<<cust_name;
			gotoxy(7,8);cout<<"CUSTOMER ADDRESS:"<<cust_add;
			for(i=1;i<=c;i++)
			{
				dis_bill>>tcode[i]>>tname[i]>>tprice[i]>>tqty[i]>>amt[i];
				gotoxy(4,12+i); cout<<i;
				gotoxy(13,12+i); cout<<tcode[i];
				gotoxy(25,12+i); cout<<tname[i];
				gotoxy(43,12+i); cout<<tprice[i];
				gotoxy(53,12+i); cout<<tqty[i];
				gotoxy(65,12+i); cout<<amt[i];
			   //	cout<<i<<"\t"<<tcode[i]<<"\t   "<<tname[i]<<"\t\t"<<tprice[i]<<"\t   "<<tqty[i]<<"\t\t"<<amt[i]<<"\n";
			}
		}
		dis_bill>>total>>dis>>btotal;
		displaySq(3,21,55,21,3,25,55,25);
		gotoxy(5,22); cout<<"AMOUNT RS.  : "<<total;
		gotoxy(5,23); cout<<"DISCOUNT 10%: "<<dis;
		gotoxy(5,24); cout<<"BILL AMOUNT : "<<btotal;
		bill_des();
		gotoxy(60,23); cout<<"CONTINUE > ";
		getch();
	}
	dis_bill.close();
	getch();
	m.bill_menu();
}
/* STOCK MANAGEMENT */
void bill :: stock(int tcod,int tqt)
{
	   //	int tcod,tqt;
	ifstream mod_stock("STOCK.TXT",ios::in);
	ofstream temp("TEMP.TXT",ios::app);
	while(1)
	{       mod_stock>>itemcode;
		mod_stock>>itemname;
		mod_stock>>itemcost;
		mod_stock>>itemprice;
		mod_stock>>qty;
		if(mod_stock.eof())
		{
		 break;
		}
		else
		{
			if(itemcode == tcod)
			{
				qty=qty-tqt;
					temp<<itemcode<<"\t"<<itemname<<"\t"<<itemcost<<"\t"<<itemprice<<"\t"<<qty<<"\n";
			}
			else
			{
					temp<<itemcode<<"\t"<<itemname<<"\t"<<itemcost<<"\t"<<itemprice<<"\t"<<qty<<"\n";
			}
		}
		}
	temp.close();
	mod_stock.close();
	remove("STOCK.TXT");
	rename("TEMP.TXT","STOCK.TXT");

}
/*PASSWORD FUNCTION*/
void menu::password(void)
{
  int i;
  char user[10],pass[10];
	  clrscr();
	  textcolor(15);
	  displaySqDL(4,5,70,5,4,20,70,20);
	  displaySq(12,17,60,17,12,19,60,19);

	  gotoxy(30,7);
	  cout<<"<< WELCOME >>";
	  delay(10);
	  gotoxy(32,10);
	  cout<<"<< TO >>";
	  delay(10);
	  gotoxy(24,13);
	  cout<<"<< ~SMART SHOP ERP S\W~ >>";
	  delay(10);
	  gotoxy(1,14);
	  delay(10);
	  textcolor(3);
	  gotoxy(20,18);
	  cprintf("DEVELOPED BY  : BHAVYA, MALAV ");
	  delay(10);
	  gotoxy(22,24);
	  textcolor(BLINK+WHITE);
	  cprintf(":: PRESS ENTER TO CONTINUE ::");
	  delay(10);
	  textcolor(14);
	  getch();
	A: for (i=25; i>=1; i--)
	  {
		delay(50) ;
		gotoxy(1,i) ;
		clreol() ; //liNE CLEAR
	  }
	 menu_des();
	 gotoxy(28,5);
	 cout<<"WELCOME TO SMART SHOP ERP";
	 gotoxy(32,9);
	 cout<<"<< LOGIN USER >>";
	 gotoxy(18,12);
	 cout<<"ENTER USER NAME : ";
	 displaySq(39,11,64,11,39,13,64,13);
	 gotoxy(42,12);
	 pass1(user);
	 displaySq(39,14,64,14,39,16,64,16);
	 gotoxy(18,15);
	 cout<<"ENTER PASSWORD  : ";
	 gotoxy(42,15);
	 pass1(pass);
	 if((strcmp(user,"E")==0 || strcmp(user,"e")==0) && (strcmp(pass,"E")==0 || strcmp(pass,"e")==0))
	 {
		close();
	 }
	 if((strcmp(user,"ADMIN")==0 || strcmp(user,"admin")==0) && (strcmp(pass,"ADMIN")==0 || strcmp(pass,"admin")==0) )
	 {
		int j=0;
	   for(i=50;i>=22;i--)
	   {
			clrscr();
			displaySq(45-j,11,80-j,11,45-j,15,80-j,15);
			gotoxy(i,13);
			cout<<"WELCOME SMART SHOP ERP :";
			delay(100);
			j++;
	  }
	  clrscr();
	  displaySq(45-j,11,80-j+10,11,45-j,15,80-j+10,15);
	  gotoxy(i,13);
	  cout<<"WELCOME SMART SHOP ERP(ENTER) ::";
	  getch();
	  m.main_menu();   //Main Menu
	 }
	 else
	 {
		textcolor(BLINK+RED);
	   gotoxy(23,23);
	   cprintf("PLZ,ENTER CORRECT PASSWORD >> ");
	   textcolor(15);
	   getch();
	   goto A;
	   m.password();
	 }
	 getch();
}
/***********************************BILL DESIGN***********************/
void bill_des()
{
	   int i;
	   textmode(C80);
	   textbackground(BLACK);
	   textcolor(YELLOW);
	  // clrscr();
	 displaySq(3,2,79,2,3,25,79,25);

	for(i=4;i<=78;i++)
	{
		gotoxy(i,4);
		cout<<"=";
		gotoxy(i,9);
		cout<<"=";
	}
	displaySq(10,10,22,10,10,21,22,21);
	displaySq(40,10,50,10,40,21,50,21);
	displaySq(62,10,79,10,62,21,79,21);
	gotoxy(3,10); cprintf("ร");
	for(i=4;i<=78;i++)
	{
		if(i==10||i==22||i==40||i==50||i==62)
			cprintf("ย");
		else
			cprintf("ฤ");
	}cprintf("ด");
	gotoxy(3,12); cprintf("ร");
	for(i=4;i<=78;i++)
	{
		if(i==10||i==22||i==40||i==50||i==62)
			cprintf("%c",197);
		else
			cprintf("%c",196);
	}cprintf("ด");
	gotoxy(3,21); cprintf("ร");
	for(i=4;i<=78;i++)
	{
		if(i==10||i==22||i==40||i==50||i==62)
			cprintf("ม");
		else
			cprintf("ฤ");
	}
	cprintf("ด");
/*
	gotoxy(3,12);
	cout<<"ฬออออออหอออออออออออหอออออออออออออออออหอออออออออหอออออออออออหออออออออออออออออน";
	gotoxy(3,21);
	cout<<"ฬออออออสอออออออออออสอออออออออออออออออสอออออออออสอออออออออออสออออออออออออออออน";
	for(i=13;i<=20;i++)
	{
	 gotoxy(10,i);
	 cout<<"บ";
	 gotoxy(22,i);
	 cout<<"บ";
	 gotoxy(40,i);
	 cout<<"บ";
	 gotoxy(50,i);
	 cout<<"บ";
	 gotoxy(62,i);
	 cout<<"บ";
	} */
 }
/*********************** MENU DESIGN*****************************/
void menu_des()
{      int i;
	   clrscr();
	   gotoxy(3,2);
	   textcolor(15);
	   displaySqDL(3,2,79,2,3,25,79,25);
	   displayDbar(3,22,75);
		gotoxy(4,4);
		cout<<"===========================================================================";
		gotoxy(4,6);
		cout<<"===========================================================================";
	gotoxy(27,3);
	cout<<"\xDB\xDB\xDB\xDB\xB2  SMART SHOP ERP  \xB2\xDB\xDB\xDB\xDB";
}
/*********************** CONDITION *****************************/
void ventry(char t[],int code)
 {
  int i=0;

  if(code==0)
  {

	while((t[i]=getch())!='\r' && i<30)
	 if((t[i]>=48 && t[i]<=57) ||t[i]=='_'||(t[i]>=97 && t[i]<=122) || (t[i]>=65 && t[i]<=90) || t[i]==32 || t[i]==8|| t[i]==44)
	  {
			printf("%c",t[i]);
			i++;
	  }
  }
  else if(code==1)
  {
		t[0]=0;
		while((t[i]=getch())!='\r' && i<7)
		if((t[i]>=48 && t[i]<=57) || t[i]==46 || t[i]==8 )
		{
			printf("%c",t[i]);
			i++;
		}
  }
  t[i]='\0';
}
/*********************** PASSWORD VALIDETION *****************************/
void pass1(char r[])
 {
	 int i=0;
		while((r[i]=getch())!='\r' && i<10)
		if((r[i]>=97 && r[i]<=122) || (r[i]>=65 && r[i]<=90) || r[i]==32)
		{
			printf("*",r[i]);
			i++;
		}
		else if(r[i]==8)         //BACK SPACE
		{
			printf("\b \b");
			i-=2;
		}
	r[i]='\0';
}
/*********************** DATE FUNCTION *****************************/
void item :: date()
{
	struct date d;
	getdate(&d);
	d1 = d.da_day ;
	m1 = d.da_mon ;
	y1 = d.da_year ;
	cout <<"Date: " <<d1 <<"/" <<m1 <<"/" <<y1 ;
}
/*********************** CLOSE FUNCTION*****************************/
void close()
{
	   clrscr();
	   gotoxy(24,12);
	   cout<<"THANK YOU........";
	   getch();
	   exit(1);
}

void main()
{
  textmode(C80);
  textbackground(BLACK);
  textcolor(YELLOW);
  clrscr();
  m.password();
  getch();
  lab:;
}
int AreUsure(int i,int j)        /* DISPLAY WITH BOX 1-Y & 2-N */
{
	int ch;
	textcolor(4);displaySq(i,j,i+20,j,i,j+6,i+20,j+6);
	textcolor(15);
	gotoxy(i+4,j+1); cprintf("Are You Sure ?");
	textcolor(4);
	gotoxy(i+8,j+2); cprintf("1. Yes");
	gotoxy(i+8,j+3); cprintf("2. No");
	textcolor(7);
	gotoxy(i+2,j+5); cprintf("<< Enter (1/2): ");
	AreUSure: ch=getch();
	if(!(ch=='1'|| ch=='2'))  //CHECK
	{ goto AreUSure; }
	return ch;

}


/*	DESIGN SQUARE FUNCTION		*/

void displaySq(int i1,int i2,int j1,int j2,int k1,int k2,int l1,int l2)
{
	int i;
	gotoxy(i1,i2); cprintf("ฺ");
	gotoxy(j1,j2);  cprintf("ฟ");
	gotoxy(k1,k2); cprintf("ภ");
	for(i=1;i<=j1-(i1+1);i++)        //LOOP FOR '-'
	{
		gotoxy(i1+i,i2); cprintf("ฤ");
		gotoxy(k1+i,k2); cprintf("ฤ");
	}
	for(i=1;i<=k2-(i2+1);i++)      //LOOP FOR  '|'
	{
		gotoxy(i1,i2+i);  cprintf("ณ");
		gotoxy(j1,j2+i); cprintf("ณ");
	}
	gotoxy(l1,l2); cprintf("ู");
}

/*	DESIGN DOUBLE LINE SQUARE FUNCTION		*/


void displaySqDL(int i1,int i2,int j1,int j2,int k1,int k2,int l1,int l2)
{
	int i;
	gotoxy(i1,i2); cprintf("ษ");
	gotoxy(j1,j2);  cprintf("ป");
	gotoxy(k1,k2); cprintf("ศ");
	for(i=1;i<=j1-(i1+1);i++)
	{
		gotoxy(i1+i,i2); cprintf("อ");
		gotoxy(k1+i,k2); cprintf("อ");
	}
	for(i=1;i<=k2-(i2+1);i++)
	{
		gotoxy(i1,i2+i); cprintf("บ");
		gotoxy(j1,j2+i);  cprintf("บ");
	}
	gotoxy(l1,l2); cprintf("ผ");
}

/*	DESIGN "น"   FUNCTION	  */

void displayRbar(int i1,int j1,int sz)
{
	int i;
	gotoxy(i1,j1);
	for(i=1;i<=sz;i++)
	{ cprintf("อ");}
	cprintf("น");

}

/*	DESIGN "ฬ"   FUNCTION	  */

void displayLbar(int i1,int j1,int sz)
{
	int i;
	gotoxy(i1,j1); cprintf("ฬ");
	for(i=1;i<=sz;i++)
	{ cprintf("อ");}
}

/*	DESIGN "น" "ฬ"   FUNCTION	  */

void displayDbar(int i1,int j1,int sz)
{
	int i;
	gotoxy(i1,j1); cprintf("ฬ");
	for(i=1;i<=sz;i++)
	{ cprintf("อ");}
	gotoxy(i1+i,j1); cprintf("น");
}

/*	CONVERT INTEGER INTO CHARACTER 	*/

char convCh(int q)
{
	char  qc;
	qc=(q==1?'1':q==2?'2':q==3?'3':q==4?'4':q==5?'5':q==6?'6':q==7?'7':q==8?'8':q==9?'9':q==10?'A':q==11?'B':q==12?'C':'D');
	return qc;
}
