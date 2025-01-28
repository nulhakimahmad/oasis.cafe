#include <iostream>  
#include <string.h> 
#include <conio.h> //keybind for keyboard(ascivalue)
#include <ctime>   //set timer dt
#include <iomanip> //set width
#include <stdlib.h>

 
using namespace std;

//GLOBAL VARIABLES

string   fname[100];

int order, food, customer, count, qfood[10], shift, input;
float fprice[10], totprice[10], pay, change, totfood, totdrink;  
float amount, grandprice=0;
float total_price;
int i = 0, y = 0;
float tota[20];
time_t now = time(0); // date & time
char* dt=ctime(&now);
char cashier[100], nextorder, type;

char key;
int asciiValue;



void calcPrice1();
void calcPrice2();
void calcPrice3();
void calcPrice4();

char intro();
void fmenu();
float receipt();
float report();
         
char intro()
{
	char character;

    cout<<"\t\t\n                                                                                             " <<endl;
    cout<<"        ,ad8888ba,                        88             ,ad8888ba,                ad88            " <<endl;
    cout<<"       d8*'    `*8b                       **            d8*'    `*8b              d8*              " <<endl;
    cout<<"      d8'        `8b                                   d8'                        88               " <<endl;
    cout<<"      88          88 ,adPPYYba, ,adPPYba, 88 ,adPPYba, 88            ,adPPYYba, MM88MMM ,adPPYba,  " <<endl;
    cout<<"      88          88 **     `Y8 I8[    ** 88 I8[    ** 88            **     `Y8   88   a8P_____88  " <<endl;
    cout<<"      Y8,        ,8P ,adPPPPP88  `*Y8ba,  88  `*Y8ba,  Y8,           ,adPPPPP88   88   8PP*******  " <<endl;
    cout<<"       Y8a.    .a8P  88,    ,88 aa    ]8I 88 aa    ]8I  Y8a.    .a8P 88,    ,88   88   *8b,   ,aa  " <<endl;
    cout<<"        `*Y8888Y*'   `*8bbdP*Y8 `*YbbdP*' 88 `*YbbdP*'   `*Y8888Y*'  `*8bbdP*Y8   88    `*Ybbd8*'  " <<endl;




	cout << "\n\n\t\t\t ----------OasisCafe Ordering System----------"<<endl;
	cout << "\t\t\t|                                             |"<<endl;
	cout << "\t\t\t|     Brought To You By uitm squadron   :     |"<<endl;
	cout << "\t\t\t|                                             |"<<endl;
	cout << "\t\t\t|      NULHAKIM                               |"<<endl;
	cout << "\t\t\t|  MUHAMMAD FADLI                             |"<<endl;
	cout << "\t\t\t|        MUHAMMAD AIMAN                       |"<<endl;
	cout << "\t\t\t|      MUHAMMAD ABID                          |"<<endl;
	cout << "\t\t\t|                                             |"<<endl;
	cout << "\t\t\t ---------------------------------------------"<<endl;
	
	
	cout << "\n\t\t\tPress Y to continue and press N to exit [y/n] : ";
	cin >> character;
   
    switch(character){

		case 'N' :
		case 'n' :
			cout<<"\n\t\t\tOopps";
			exit(EXIT_SUCCESS);	
			break;
		default :
			break;
    }
    return 0;
}
void fmenu()
{ 
    cout <<endl;
    cout << "\t\t\t -----------------------------------------------------------"<<endl;
    cout << "\t\t\t|                      OasisCafe - Menu                     |"<<endl;
    cout << "\t\t\t -----------------------------------------------------------"<<endl;
    cout <<endl;
    cout << "\t\t\t+------------ A ------------+\t+------------ B ------------+"<<endl;
    cout << "\t\t\t| Food  : Deluxe Burger     |\t| Food  : Supreme Tacos     |    *Add on RM 2"<<endl;
    cout << "\t\t\t| Price : RM 20.50          |\t| Price : RM 15.20          |         for"    <<endl;
    cout << "\t\t\t+---------------------------+\t+---------------------------+     [F-Fries/"  <<endl;
    cout << "\t\t\t                                                                 O-OnionRings]*"<<endl;
    cout << "\t\t\t+------------ C ------------+\t+------------ D ------------+"<<endl;
    cout << "\t\t\t| Food  : Giga Oblong       |\t| Food  : Colossal Burritos |"<<endl;
    cout << "\t\t\t| Price : RM 10.90          |\t| Price : RM 17.30          |"<<endl;
    cout << "\t\t\t+---------------------------+\t+---------------------------+"<<endl;  
    cout<<endl;
    cout << "\t\t\t+------------ Caffeine --------------- Hot ------ Cold -----+"<<endl;  
    cout << "\t\t\t| 1.Kopi Bakar Original                RM7        RM8       |"<<endl;
    cout << "\t\t\t| 2.Kopi Bakar Hazelnut/Chocolate/     RM8        RM9       |"<<endl;
    cout << "\t\t\t|            Vanilla/Creme Brule                            |"<<endl;
    cout << "\t\t\t| 3.Kopi Kedah                         RM6        RM7       |"<<endl;
    cout << "\t\t\t+-----------------------------------------------------------+"<<endl;
    cout<<endl;
    cout << "\t\t\t+--------- Non-Caffeine -------------- Hot ------ Cold -----+"<<endl;
    cout << "\t\t\t| 4.ChocoMilky                         RM7        RM8       |"<<endl;
    cout << "\t\t\t| 5.Vanillala                          RM7        RM8       |"<<endl;
    cout << "\t\t\t| 6.ChocoVanilla                       RM7        RM8       |"<<endl;
    cout << "\t\t\t| 7.Milky Thai Greentea                RM7        RM8       |"<<endl;
    cout << "\t\t\t+-----------------------------------------------------------+"<<endl; 
    cout << "*Press [ ESC ] on *choose order* to confirm              " << endl;
    cout << "Do not press [ ENTER ] on *choose order*" << endl;   
    cout << "Press [ ENTER ] after insert quantity " << endl;
}


int main()
{
    intro();

    do
    {

        //shift:
        ///////////////////////////////////////////////
        cout<<"\n\t\t\tEnter the cashier's name : ";
        cin>>ws;
        cin.getline(cashier,20);
        cout<<"\t\t\tEnter Shift : ";
        cin>>shift;

        do
        {
            system("cls");
            fmenu(); //call function
            cout<<endl;
            
            amount = 0; // RESET AMOUNT
            order = 0;
            i = 0;
            grandprice = 0;

        
            while(1)
            {
                
                total_price = 0; // RESET TOTAL PRICE FOR DRINK
                
                cout<<"choose order : ";
                key=getch(); //ascii Value
                food=key;

                if(food==65||food==97) // A || a
                {
                    cout<<key;
                    cout<<"\tQuantity : ";
                    cin>>qfood[i];
                    fname[i]="Deluxe Burger";
                    fprice[i]=20.50;
                    totprice[i]=fprice[i]*qfood[i];   
                    
                }
                else if(food==66||food==98){ //B
                    cout<<key;
                    cout<<"\tQuantity : ";
                    cin>>qfood[i];
                    fname[i]="Supreme Tacos";
                    fprice[i]=15.20;
                    totprice[i]=fprice[i]*qfood[i];
                    
                }
                else if(food==67||food==99){ //C
                    cout<<key;
                    cout<<"\tQuantity : ";
                    cin>>qfood[i];            
                    fname[i]="Giga Oblong";
                    fprice[i]=10.90;
                    totprice[i]=fprice[i]*qfood[i];
                
                }
                else if(food==68||food==100){ //D
                    cout<<key;
                    cout<<"\tQuantity : ";
                    cin>>qfood[i];
                    fname[i]="Colossal Burritos";
                    fprice[i]=17.30;
                    totprice[i]=fprice[i]*qfood[i];
        
                }
                else if(food==70||food==102){ ////fries-F
                    cout<<key;
                    cout<<"\tQuantity : ";
                    cin>>qfood[i];
                    fname[i]="*Fries";
                    fprice[i]=2.0;
                    totprice[i]=fprice[i]*qfood[i];
        
                }
                else if(food==79||food==111){  /////onionRings-O
                    cout<<key;
                    cout<<"\tQuantity : ";
                    cin>>qfood[i];
                    fname[i]="*Onion Rings";
                    fprice[i]=2.0;
                    totprice[i]=fprice[i]*qfood[i];
                    
                }
                /////////////////////////////////////////////////// DRINK MENU ////////////////////////////////////////////////
                else if(food==49){
                    cout<<key;
                    cout<<"\tQuantity : ";
                    cin>>qfood[i];       
                    calcPrice1();  //function call to choose either hot /cold drink
                    fname[i]="Kopi Bakar Original";

                }
                else if(food==50){

                    char ktype;
                    cout<<key;
                    cout<<"\n\tKopi Bakar [H-Hazelnut/ C-Chocolate/ V-Vanilla/ B-Creme Brule] : ";
                    cin>>ktype;


                    if(ktype=='H'||ktype=='h'){
                        cout<<"\tYou Choose Kopi Bakar Hazelnut"<<endl;
                        fname[i]="Kopi Bakar Hazelnut";
                    }

                    else if(ktype=='C'||ktype=='c'){
                        cout<<"\tYou Choose Kopi Bakar Chocolate"<<endl;
                        fname[i]="Kopi Bakar Chocolate";
                    }

                    else if(ktype=='V'||ktype=='v'){
                        cout<<"\tYou Choose Kopi Bakar Vanilla"<<endl;
                        fname[i]="Kopi Bakar Vanilla";
                    }
                        
                    else if(ktype=='B'||ktype=='b'){
                        cout<<"\tYou Choose Kopi Bakar Cream Brule"<<endl;
                        fname[i]="Kopi Bakar Cream Brule";
                    }
                    else{
                        cout<<"\tinvalid code"<<endl;
                    }


                    cout<<"\t\t\tQuantity : ";
                    cin>>qfood[i];
                    calcPrice2();  //function call to choose either hot /cold drink
                    
                    //fname[i]="Kopi Bakar Hazelnut";

                    // order++;
                }
                else if(food==51){
                    cout<<key;
                    cout<<"\tQuantity : ";
                    cin>>qfood[i];     
                    calcPrice3();  //function call to choose either hot /cold drink    
                    
                    fname[i]="Kopi Kedah";

                    // order++;
                }
                else if(food==52){
                    cout<<key;
                    cout<<"\tQuantity : ";
                    cin>>qfood[i];
                    calcPrice4();  //function call to choose either hot /cold drink
                    fname[i]="ChocoMilky";

                    // order++;
                }
                else if(food==53){
                    cout<<key;
                    cout<<"\tQuantity : ";
                    cin>>qfood[i];
                    calcPrice4();  //function call to choose either hot /cold drink
                    fname[i]="Vanillala";

                    // order++;
                }
                else if(food==54){
                    cout<<key;
                    cout<<"\tQuantity : ";
                    cin>>qfood[i];
                    calcPrice4();  //function call to choose either hot /cold drink
                    fname[i]="ChocoVanilla";

                    // order++;
                }
                else if(food==55){
                    cout<<key;
                    cout<<"\tQuantity : ";
                    cin>>qfood[i];
                    calcPrice4();  //function call to choose either hot /cold drink
                    fname[i]="Milky Thai Greentea";

                    // order++;
                }
                else if(food==27) //27 for ESC key
                    break;
                    
                else
                    cout<<"Invalid code please re-enter code"<<endl;  

 

                order++;
                i++;
                
            }/////////////////////////////////////////////end of INFINITE loop

            receipt(); //function call
            
            cout<<"\n  Next order? [y-yes,n-no] : ";
            cin>>nextorder;

            customer++; // utk kira bilangan customer setiap kali loop diulang
            y++; ////utk masukkan data ke array customer seterusnya bila loop

        } while (nextorder=='y'||nextorder=='Y'); /////// END OF FIRST ORDER///////////////////////////////////////////////////////




        system("cls");
        
        cout << "\n\n"<< endl;
        cout << "\t\t\t+------------------------------------------------+"<<endl;
        cout << "\t\t\t|         Daily Sales Report - OasisCafe         |"<<endl;
        cout << "\t\t\t+------------------------------------------------+"<<endl;
        cout << endl;

        report(); // function call

        
        cout<<"\n";
        system("PAUSE");
        cout << "\n\n\t\t\tMenu : "<<endl;
        cout << endl;
        cout << "\t\t\t1. Order again"<<endl;
        cout << "\t\t\t2. Exit"<<endl;
        
        cout << "\n\t\t\tEnter :";
        cin >> input;
        

        
    } while (input == 1); //LOOP THE WHOLE CODING
	return 0;
    
}

float receipt()
{
    system("cls");

    cout.setf(ios::fixed);
    cout.precision(2);

    cout << endl;
    cout << "\t\t\t+------------------------------------------------+"<<endl;
    cout << "\t\t\t|               Receipt OasisCafe                |"<<endl;
    cout << "\t\t\t+------------------------------------------------+"<<endl;
    cout << endl;
    cout << "                      "<<dt<<endl;
    cout << "\t\t\t  Tel  : 03-3*9-3****     Fax   : 013-7186200"<<endl;
    cout << "\t\t\t  Till : R3451            Order : M35042627"<<endl;
    cout << endl;
    cout << endl;
    cout << "\t\t\t  Cashier :  "<<cashier<<endl;
    cout << "\t\t\t  Shift   :  SHIFT-"<<shift<<endl;
    cout << endl;
    cout << endl;
    cout << "\t\t\t+------------------------------------------------+"<<endl;
    cout << "\t\t\t| Description                Qty        Amount   |"<<endl;
    cout << "\t\t\t+------------------------------------------------+"<<endl;


    for(int i=0; i<order; i++)
    {	
        cout << "\t\t\t"<< setw(22)<<left <<fname[i]<< setw(6)<<"        "<<setw(10) << qfood[i] << totprice[i] <<endl;

        amount=amount+totprice[i];  //calculation
        
    }

    int paymethod, transferVia;
    cout << "                                                "<<endl;
    cout << "\n\t\t\tYour total cost   : RM "<<amount<<endl;
    
    while(1)
    {    
        cout << "\n\t\t\tPayment with ( 1.Transfer/ 2.Cash ) : ";
        cin >> paymethod;

        if(paymethod==1)
        {
            cout <<"\t\t\t   1. Transfer to Account No. XXXXXXXXXXXX"<<endl;
            cout <<"\t\t\t   2. eWallet transfer"<<endl;
            cout <<"\t\t\t   3. Debit card"<<endl;
            cout <<"\t\t\t   Enter : ";
            cin >> transferVia;
            if(transferVia==1)
                break;
            else if(transferVia==2){
                break;}
            else if(transferVia==3){
                cout << "\t\t\tPlease attach your card"<<endl;
                break;}
            else
                cout<<"\t\t\tInvalid code please re-enter code"<<endl;
        }
        else if(paymethod==2){
            cout<<"\t\t\tCash at counter."<<endl;
            break;}
        else
            cout<<"\t\t\tInvalid code please re-enter code"<<endl; 
    }
    cout << "\t\t\tAmount payment     : RM ";
    cin >> pay;

    tota[y]=amount;

    change = pay-amount;  //calculation
    cout << "\t\t\tTotal change      : RM "<<change<<endl;

    return 0;
}


float report() //Daily Sales Report
{
	
	for (int y=0; y<customer; y++)
	{
        cout<<endl;
		cout<<                 "\t\t\t  CUSTOMER        TOTAL PRICE"<<endl;
		cout<<"\t\t\t"<<setw(6)<<right<< y+1 <<setw(16)<<"RM "<< tota[y] <<endl;
        cout<<"\t\t\t=================================================="<<endl;


        grandprice = grandprice+tota[y];
	}


	// cout<<"\n\t\t\t    TOTAL"<<setw(16)<<"RM "<<grandprice <<endl;
	cout<<"\n\t\t\t  TOTAL REVENUE :  RM "<<grandprice<<endl<<endl;	

	return 0;
}	
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////// CALCPRICE DRINK ///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
void calcPrice1()
{

	for (count=1;count<=qfood[i];count++)
	{

		cout<<"\t\t\tHot or Cold [H/C] : ";
		cin>>type;
		
		if(type=='H'||type=='h')
		{
			fprice[i]=7.00;
		}
		else if (type=='C'||type=='c')
		{
			fprice[i]=8.00;
		}
		total_price+=fprice[i];
	}
	totprice[i]=total_price;
}
void calcPrice2()
{

	for (count=1;count<=qfood[i];count++)
	{

		cout<<"\t\t\tHot or Cold [H/C] : ";
		cin>>type;
		
		if(type=='H'||type=='h')
		{
			fprice[i]=8.00;
		}
		else if (type=='C'||type=='c')
		{
			fprice[i]=9.00;
		}
		total_price+=fprice[i];
	}
	totprice[i]=total_price;
}
void calcPrice3()
{

	for (count=1;count<=qfood[i];count++)
	{

		cout<<"\t\t\tHot or Cold [H/C] : ";
		cin>>type;
		
		if(type=='H'||type=='h')
		{
			fprice[i]=6.00;
		}
		else if (type=='C'||type=='c')
		{
			fprice[i]=7.00;
		}
		total_price+=fprice[i];
	}
	totprice[i]=total_price;
}
void calcPrice4()
{

	for (count=1;count<=qfood[i];count++)
	{

		cout<<"\t\t\tHot or Cold [H/C] : ";
		cin>>type;
		
		if(type=='H'||type=='h')
		{
			fprice[i]=7.00;
		}
		else if (type=='C'||type=='c')
		{
			fprice[i]=8.00;
		}
		total_price+=fprice[i];
	}
	totprice[i]=total_price;
}
