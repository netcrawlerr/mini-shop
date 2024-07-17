/*
        A project About Mini-Shop	
*/

#include <iostream>
#include <windows.h>
#include <cstring>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

// PROTOTYPING FUNCTIONS
void welcome();
void login_options();
void admin_login();
void display_items();
void customer_purchase();
void admin_delete_items();
void admin_add_items();

int choice;

//STRUCTURE FOR ITEMS
struct item_info{
	 string item;
	 int   price;
	 int   quantity;
};


//MAIN FUNCTION STARTS HERE
int main()
{
    
	system("color 70");
	welcome();
	 
	do{
		login_options();
	}while(choice !=3);
    return 0;
}

// Creating Welcome Function 

void welcome(){
	cout << "\t\t\t *  *  *   ****  *       ****   ****    *****    ****   " << endl;
    cout << "\t\t\t *  *  *  *      *      *      *    *  *  *  *  *        "<< endl;
    cout << "\t\t\t *  *  *  *****  *      *      *    *  *  *  *  *****    " << endl;
    cout << "\t\t\t *  *  *  *      *      *      *    *  *  *  *  *         " << endl;
    cout << "\t\t\t  *****    ****  *****   ****   ****   *  *  *   ****     " << endl;
    cout<<"\n";
    cout<<"\t\t\t========================================================\n\n";
    cout<<"\t\t\t           This is a Simple Mini-Shop Program\n\n";
    cout<<"\t\t\t========================================================\n";
}

// Creating Function To Display Options

void login_options(){

	cout<<"1. Login As an Mini-Shop Admin \n\n";
    cout<<"2. Purchase As a Customer\n\n";
    cout<<"3. Exit The Program\n";
    cout<<">>> ";
	cin>>choice;
    system("cls");
    
    		
    		   	switch(choice)
				{
				case 1:
					admin_login();
					break;
				case 2:
					customer_purchase();
					break;
				case 3:
					cout<<"\n\nProgram Terminated\n\n\n\n";
					break;
			  	default:
				   	cout<<"\nINVALID INPUT !!!!\n";
					break;
				}
}

void admin_login(){
	char name[10];
	int ID;
	char username[10];
	strcpy(username,"abc");
	/*
		 admin name as "abc"
		 admin id which is an integer 123

	*/
	
	cout<<"\nEnter Admin Credentials: \n";
	cout<<"Name: "; cin>>name;
	cout<<"ID (Must be An integer): "; cin>>ID;
	int comp = strcmp(name, username);

	
		if(comp==0 && ID == 123){
            cout<<"\n1. To Add Items: \n";
			cout<<"\n2. To Remove Items: \n";
			int admin_choice;
			cin>>admin_choice;

                        switch (admin_choice)
                        {
                        case 1:
                             admin_add_items();
                             break;
                        case 2:
                            admin_delete_items();
                             break;                      
                        default:
                            cout<<"\nInvalid Input !!!\n";
                            break;
                        }
                        
			
		}
		else
		{
			cout<<"\nUsing Incorrect Credentials!!\n\n";
			
		}
	
}


// FUNCTION TO DELETE ITEMS
void admin_delete_items(){
	display_items();
string holder;
    int i;
    int starter = 1;
    cout<<"enter the number of item you want removed\n>>";
    cin>>i;

  { ifstream input("items.txt",ios::in);
    ofstream output("temp.txt", ios::out | ios::trunc);
    while(getline(input, holder))
    {
        if(starter != i)
        {
            output<<holder<<endl;
        }
        starter++;
    }
    input.close();
    output.close();


    ofstream input1("items.txt", ios::out | ios::trunc);
    ifstream output1("temp.txt", ios::in);
    while(getline(output1, holder))
    {
            input1<<holder<<endl;
    }
    input.close();
    output.close();}
	starter =1;
  { ifstream input("prices.txt", ios::in);
    ofstream output("temp.txt", ios::out | ios::trunc);
    while(getline(input, holder))
    {
        if(starter != i)
        {
            output<<holder<<endl;
        }
        starter++;
    }
    input.close();
    output.close();


    ofstream input1("prices.txt");
    ifstream output1("temp.txt");
    while(getline(output1, holder))
    {
            input1<<holder<<endl;
    }
    input.close();
    output.close();
  }
	starter = 1;
  { ifstream input("stock.txt");
    ofstream output("temp.txt");
    while(getline(input, holder))
    {
        if(starter != i)
        {
            output<<holder<<endl;
        }
        starter++;
    }
    input.close();
    output.close();


    ofstream output1("stock.txt", ios::out | ios::trunc);
    ifstream input1("temp.txt");
    while(getline(input1, holder))
    {
            output1<<holder<<endl;
    }
    input.close();
    output.close();}
    cout<<"\n\n Item Removed Successfully !!!!\n\n";
}

//FUNCTION TO ADD ITEMS
void admin_add_items(){
    int n;
	cout<<"enter number of items you want to add\n";
	cin>>n;
	item_info add[n];
	for(int i=0;i<n;i++){
    ofstream wt;
    cout<<"enter the item\n";
    wt.open("items.txt",ios::app);
    cin>>add[i].item;
    wt<<add[i].item<<endl;
    wt.close();
    cout<<"enter the price\n";
    ofstream wrt;
	wrt.open("prices.txt",ios::app);
	cin>>add[i].price;
	wrt<<add[i].price<<endl;
	wrt.close();
	ofstream rt;
    cout<<"enter its quantity\n";
    rt.open("stock.txt",ios::app);
    cin>>add[i].quantity;
    rt<<add[i].quantity<<endl;
    rt.close();
	}
	cout<<"\n\n Item/s Added Succesfully\n\n";
}

// FUNTION TO DISPLAY ITEMS
void display_items(){
    cout<<" Item "<<"----------"<<" Price "<< " ---------- "<<" Stock \n\n";
string price_fromFile;
string stock_fromFile;
string items_fromFile;
    ifstream fin,fin1,fin2;
    fin.open("items.txt",ios::in);
     fin1.open("prices.txt",ios::in);
      fin2.open("stock.txt",ios::in);
    
    int a = 1;
    while (getline(fin,items_fromFile) && getline(fin1,price_fromFile) && getline(fin2,stock_fromFile))
    {
        cout<<a<<'.'<<items_fromFile<<setw(17 - items_fromFile.length())<<price_fromFile<<setw(22)<<stock_fromFile<<"\n\n";
    	a++;
	} 
        
}

// PURCHASING FUNCTION
void customer_purchase(){
  // this is to show that the item should be displayws
    display_items();
    int total = 0, amnt, price, start = 1, itm, line, cnt = 0;
    string sprice, sline;

    cout<<"\n>>>> Press the item you want to purchase"<<endl;
    cout<<"\n>>>> Press '0' when you are done"<<endl;

    while(true)
    {

        cout<<"item->> ";
        cin>>itm;
          ifstream sFile2("items.txt", ios::in);
        while(getline(sFile2, sline))
        {
                cnt++;
        }
        sFile2.close();
     {
      if (itm == 0)
        {
        	cout<<"=================================================================================================\n";
            cout<<"\nTransaction done:\n"<<endl;
            break;
        }
      if (itm < 0 || itm > cnt)
        {
            cout<<"\nInvalid input. Try again.\n"<<endl;
            continue;
        }



        cout<<"\nAmount of item required->> ";
        cin>>amnt;
        if(amnt <= 0)
        {
            cout<<"\nInvalid Input Try Again"<<endl;
            continue;
        }

     }
       ifstream pFile("prices.txt", ios::in);

        while(getline(pFile, sprice))
        {
            price = stoi(sprice);
            if(start == itm)
            {
                total += price * amnt;
                break;
            }
            start++;
        }
        pFile.close();

        start = 1;
        ifstream sFile("stock.txt", ios::in);
        ofstream oFile("temp.txt", ios::out);
        while(getline(sFile, sline))
        {
            line = stoi(sline);
            if(start == itm)
            {
                if (amnt > line)
                {
                    cout<<"\nInsufficient Amount\n"<<endl;
                    oFile<<line<<endl;
                    start++;
                    continue;
                }
                line -= amnt;
                oFile<<line<<endl;
            }
            else{
                oFile<<line<<endl;
            }
            start++;
        }
        oFile.close();
        sFile.close();


        ofstream sFile1("stock.txt", ios::out | ios::trunc);
        ifstream oFile1("temp.txt", ios::in);
        while(getline(oFile1, sline))
        {
                sFile1<<sline<<endl;
        }
        oFile.close();
        sFile.close();

    }
    cout<<"The Total Price Of Your Purchase is >>> "<<total<<endl<<"\nThank You For Shopping With Us\n\n";   
	cout<<"=================================================================================================\n\n";
}


















/*

add item 
remove items
change password
change price of items

*/







