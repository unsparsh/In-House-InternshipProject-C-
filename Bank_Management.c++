#include<iostream>                               
#include<conio.h>                                        //after changing of the id to account no and adding account type and removing father name and password
#include<stdio.h>                                        //after applying no validation codes
#include<fstream>                                        //after applying switch case in edit    
#include<windows.h>                                      //after applying the concept of intro and outro
#include<string.h>                                       //after applying the concept of tabular form of payment and show records
#include <cctype>                                        //after applying the concept of c and s for account type
#include <iomanip>                                       // For setw and setfill                                                      //after applying the concept of simple inheritance for the intro and outro

using namespace std;   

class style{
	public:                     //for the concept of inheritance
	void intro();
	void outro();	
};   

class bank : public style{
	private:
		char type;
		string id,pin,name,address,phone;
		float balance;
	public:
		void menu();
		void bank_management();
		void atm_management();
		void new_user();
	    void already_user();
	    void deposit();
	    void withdraw();
	    void transfer();
	    void payment();
	    void search();
	    void edit();
	    void del();
	    void show_records();
	    void show_payment();
	    void user_balance();
	    void with_atm();
	    void check_details();
	    bool digits(const string& str);	    
};

void bank::menu(){
	p:                              //it is known as label it is used for the goto statement;
	system("cls");             // to clear the complete screen and move to next
	int choice;
	char ch;
	string pin,pass,email;                  // we can use string as a data type in c++;
	cout<<"\n\n\t\t\t\t|----------------------|";
	cout<<"\n\t\t\t\t|SPRONI BANK MANAGEMENT|";
	cout<<"\n\t\t\t\t|----------------------|";
	cout<<"\n\n\t\tContol Panel";
	cout<<"\n\n1.Bank Management";
	cout<<"\n2.ATM Management";
	cout<<"\n3.Exit";
	cout<<"\n\nEnter your choice\n";
	cin>>choice;
    
    switch(choice){
    	case 1: 
    	system("cls");
    	cout<<"\n\n\t\tLogin Account";
    	cout<<"\n\n\tPIN Code:";
    	for(int i=1;i<=5;i++){
    		ch=getch();
    		pin+=ch;                                      //it is a new concept of add up we have to learn about it
		    cout<<"*";                                     //here the concept of salting is used
		}
		if(pin=="12345"){   //we can't input the things right now
			bank_management();
		}
		else{
			cout<<"\n\nYour PIN is incorrect....";
		}
		break;
		
		case 2:
			atm_management();
			break;
			
		case 3: outro();
			exit(0);                                                   // it is a inbuilt function
			
		default:
		cout<<"\n\n Invalid Input... Please Try again...";
		
	}
    getch();
    goto p;

}

void bank::bank_management(){
	p:
	system("cls");
	int choice;
	cout<<"\n\n\n\t\tBANK MANAGEMENT SYSTEM";
	cout<<"\n\n1.New User";
	cout<<"\n2.Already User";
	cout<<"\n3.Deposit Option";
	cout<<"\n4.Withdraw Option";
	cout<<"\n5.Transfer Option";
	cout<<"\n6.Payment Option";
	cout<<"\n7.Search User Record";
	cout<<"\n8.Edit User Record";
	cout<<"\n9.Delete User Record";
	cout<<"\n10.Show All Records";
	cout<<"\n11.Payment All Records";
	cout<<"\n12.Go Back";
	cout<<"\n\n Enter your choice: ";
	cin>>choice;
	switch(choice){
	case 1: new_user();
	break;	
	case 2: already_user();
	break;
	case 3: deposit();
	break;
	case 4: withdraw();
	break;
	case 5: transfer();
	break;
	case 6: payment();
	break;
	case 7: search();
	break;
	case 8: edit();
	break;
	case 9: del();
	break;
	case 10: show_records();
	break;
	case 11: show_payment();
	break;
    case 12: menu();
    default: 
	cout<<"\n\n Invalid Input... Please Try again...";
	}
	getch();                                   //for repeat;
	goto p;	
}
	
	
	
	
void bank::atm_management(){
	p:
	system("cls");
	int choice;
	cout<<"\n\n\t\t\tATM MANGEMENT SYSTEM";
	cout<<"\n\n1.User Login and Check Balance";    
	cout<<"\n2.Withdraw Amount";
	cout<<"\n3.Account Details";
	cout<<"\n4.Go Back";
	cout<<"\n\n Enter your choice: ";
	cin>>choice;
	switch(choice){
	case 1: user_balance();
	break;	
	case 2: with_atm();
	break;
	case 3: check_details();
	break;
    case 4: menu();
    default: 
	cout<<"\n\n Invalid Input... Please Try again...";
	}
	getch();                                   //for repeat;
	goto p;	
}


void bank::new_user(){
	p:                                                     //label
		system("cls");
	    fstream file;    //file is variable,fstream is list of files ,to check the ID is unique or not
		
		float b;
		string n,p,a,ph,i,t;              //short form of the details for checking the files
		                                                      
		cout<<"\n\n\t\t\tAdd New User";
		while (true) {
        cout << "\n\nAccount No(6 digit) : ";
        cin >> id;
        
        if (id.length() == 6 && digits(id)) {
            break;  // Valid account number, exit the loop
        } else {
            cout << "\n\nInvalid Account No... Please enter a 6-digit number....\n" << endl;
        getch();
        system("cls");
		}
        }
		cout<<"\n\nName : ";
		cin>>name;
		cout<<"\n\nAddress : ";
		cin>>address;
		while (true) {
        cout << "\n\nPin No(4 digit) : ";
        cin >> pin;
        
        if (pin.length() == 4 && digits(pin)) {
            break;  // Valid account number, exit the loop
        } else {
            cout << "\n\nInvalid Pin No... Please enter a 4-digit pin number....\n" << endl;
        getch();
		}
        }
        
		while (true) {
        cout << "\n\nPhone No(10 digit) : ";
        cin >> phone;
        
        if (phone.length() == 10 && digits(phone)) {
            break;  // Valid account number, exit the loop
        } else {
            cout << "\n\nInvalid Phone No... Please enter a 10-digit phone number....\n" << endl;
        getch();
		}
        }
		while (true) {
        cout << "\n\nEnter 'c' for Current Account or 's' for Savings Account : ";
        cin >> type;

        type = toupper(type);  // Convert to uppercase

        if (type == 'C' || type == 'S') {
            if (type == 'C') {
                cout << "\nYou've selected Current Account.\n" << endl;
            } else {
                cout << "\nYou've selected Savings Account.\n" << endl;
            }
            break;  // Exit the loop
        } else {
            cout << "\nInvalid input. Please enter 'c' for Current Account or 's' for Savings Account." << endl;
        }
    }
		cout<<"\n\nCurrent Balance : ";
		cin>>balance;
		file.open("s.txt",ios::in);         //to open the file
		if(!file){                                //if the file don't exist
			file.open("s.txt",ios::app|ios::out);
			file<<" "<<id<<" "<<" "<<name<<" "<<address<<" "<<pin<<" "<<phone<<" "<<type<<" "<<balance<<"\n";     //space bhejenge fir id bhejenge
			file.close();                       //basically agar file nhi hoga originally then it will create and store these things
		}		 
		else{
			file>>i>>n>>a>>p>>ph>>t>>b;                //agar file exist karti hai to file se record layenge
			while(!file.eof()){                             //jab tak end of file nhi hoti
			if(i==id){
				cout<<"\n\nAccount No Already Exist....";
				getch();
				goto p;                                    //getch k command ka wait kare fir seedha p mai chal jana chahiye taki fir se entry ho ske
			}                                             //if closed
			file>>i>>n>>a>>p>>ph>>t>>b;                   //fir layenge while loop mai fir search karega	
			}                                                 //while closed
			file.close();                  //file band hoga
			file.open("s.txt",ios::app|ios::out);
			file<<" "<<id<<" "<<" "<<name<<" "<<address<<" "<<pin<<" "<<phone<<" "<<type<<" "<<balance<<"\n";     //space bhejenge fir id bhejenge
			file.close();                        //basically fir se open kiya aur record bhijwa diya	
		}                                        //else closed
		cout<<"\n\nNew User Account Created Successfully";		
}                                                   //function closed

void bank::already_user(){
	system("cls");
	fstream file;
	string t_id;
	int found=0;
	cout<<"\n\n\t\t\tAlready User Account";
	file.open("s.txt",ios::in);             //open karke read mode
	if(!file){
		cout<<"\n\nFile Opening Error.....";        //if file don't exist
	}
	else{                                        //if file exist
		cout<<"\n\nAccount No : ";                        
		cin>>t_id;                                  //test id jo user input karega
		file>>id>>name>>address>>pin>>phone>>type>>balance;             //yeh sari data ham file se leke aayenge
		while(!file.eof()){
			if(t_id == id){
			system("cls");
			cout<<"\n\n\t\t\tAlready User Account ";
			cout<<"\n\n User ID : "<<id<<"   Pin Code : "<<pin;
			found++;                                                             //data mil gya
		    }                                                                    //if closed jo id se data layega aur found ka value badayega
			file>>id>>name>>address>>pin>>phone>>type>>balance;                
     	}file.close();                                                        //while closed
     	if(found==0){
     		cout<<"\n\nAccount No Don't Exist....";
		 }		                                                       
   }	                                                                          //bigger else closed
    
}

void bank::deposit(){
	fstream file;
	string t_id;
	fstream file1;
	int found=0;
	float dep;
	system("cls");
	cout<<"\n\n\t\t\tDeposit Amount Option";
	file.open("s.txt",ios::in);           //read mode
	if(!file){
		cout<<"\n\nFile Opening Error....";                 //if don't exist
	}
	else{
			cout<<"\n\nAccount No : ";                        
		cin>>t_id; 
		file1.open("s1.txt",ios::app|ios::out);                            //khola secondary ko
		                                 
		file>>id>>name>>address>>pin>>phone>>type>>balance;         //data fetch kiya original se   
		while(!file.eof()){
			if(t_id == id){
			system("cls");
		    cout<<"\n\nEnter Deposit Amount : ";
		    cin>>dep;
		    balance+=dep;                          //update ho gya balance
		    file1<<" "<<id<<" "<<" "<<name<<" "<<address<<" "<<pin<<" "<<phone<<" "<<type<<" "<<balance<<"\n";     //space bhejenge fir id bhejenge                       
			found++;                     //file.close();  nhi lagaya
			cout<<"\n\n\t\t\tYour Amount "<<dep<<" succesfully depsited....";                                                          
		    }    
			else
			{                                     //jo data aaya jo update nhi hua vo v file mai jayega
				file1<<" "<<id<<" "<<" "<<name<<" "<<address<<" "<<pin<<" "<<phone<<" "<<type<<" "<<balance<<"\n";							
			}                                                                
			file>>id>>name>>address>>pin>>phone>>type>>balance;                
     	}file.close(); 
		 file1.close();
		 remove("s.txt");          //remove kiya 
		 rename("s1.txt","s.txt");                                                    
     	
		 if(found==0){
     		cout<<"\n\nAccount No Don't Exist....";	
       	}
	              
    }  
} 
     
void bank::withdraw(){
    fstream file;
	string t_id;
	fstream file1;
	int found=0;
	float with;
	system("cls");
	cout<<"\n\n\t\t\tWithdraw Amount Option";
	file.open("s.txt",ios::in);           //read mode
	if(!file){
		cout<<"\n\nFile Opening Error....";                 //if don't exist
	}
	else{
			cout<<"\n\nAccount No : ";                        
		cin>>t_id; 
		file1.open("s1.txt",ios::app|ios::out);                            //khola secondary ko
		                                 
		file>>id>>name>>address>>pin>>phone>>type>>balance;         //data fetch kiya original se   
		while(!file.eof()){
			if(t_id == id){
			system("cls");
		    cout<<"\n\nEnter Withdraw Amount : ";
		    cin>>with;
		    if(with<=balance){
			
		    balance-=with;                          //update ho gya balance
		    file1<<" "<<id<<" "<<" "<<name<<" "<<address<<" "<<pin<<" "<<phone<<" "<<type<<" "<<balance<<"\n";     //space bhejenge fir id bhejenge                       
			                     
			cout<<"\n\n\t\t\tYour Amount "<<with<<" succesfully withdrawn....";                                                          
		    } 
			else{
				cout<<"Your current balance "<<balance<<" is less than "<<with;
			file1<<" "<<id<<" "<<" "<<name<<" "<<address<<" "<<pin<<" "<<phone<<" "<<type<<" "<<balance<<"\n";
			} 
			found++;
		}
			else{                                     //jo data aaya jo update nhi hua vo v file mai jayega
			file1<<" "<<id<<" "<<" "<<name<<" "<<address<<" "<<pin<<" "<<phone<<" "<<type<<" "<<balance<<"\n";				}                                                                
			file>>id>>name>>address>>pin>>phone>>type>>balance;                
     	}file.close(); 
		 file1.close();
		 remove("s.txt");          //remove kiya 
		 rename("s1.txt","s.txt");                                                    
     	if(found==0){
     		cout<<"\n\nAccount No Don't Exist....";
        }
    }
}   

void bank::transfer(){
	fstream file;
	fstream file1;
	string s_id,r_id;
	float amount;
	int found=0;
	system("cls");
	cout<<"\n\n\t\t\tPayment Transfer Option";
	file.open("s.txt",ios::in);
	if(!file){
		cout<<"\n\nFile Opening Error....";
	}
	else{
		cout<<"\n\nSender Account No For Transaction : ";
		cin>>s_id;
		cout<<"\n\nReceiver Account No For Transaction : ";
		cin>>r_id;
		cout<<"\n\nEnter Transfer Amount : ";
		cin>>amount;
		file>>id>>name>>address>>pin>>phone>>type>>balance;         //data fetch kiya original se
		while(!file.eof()){
			if(s_id==id && amount<=balance){
				found++;
			}
			else if(r_id==id){
				found++;
			}
			file>>id>>name>>address>>pin>>phone>>type>>balance;	
		}                                                                 //while closed
		file.close();
		if(found==2){                                                     //transaction perform
			file.open("s.txt",ios::in);
			file1.open("s1.txt",ios::app|ios::out);                       //dono file ko required mode mai on karke orignal se data le rhe hai
			file>>id>>name>>address>>pin>>phone>>type>>balance;
			while(!file.eof()){
				if(s_id==id){
				balance-=amount;                                      //sender se paise kat gye
                file1<<" "<<id<<" "<<" "<<name<<" "<<address<<" "<<pin<<" "<<phone<<" "<<type<<" "<<balance<<"\n";     //sender ka record new file mai dala	                                     
				}
				else if(r_id==id){
				balance+=amount;                                       //recevier k paise bad gye
				file1<<" "<<id<<" "<<" "<<name<<" "<<address<<" "<<pin<<" "<<phone<<" "<<type<<" "<<balance<<"\n";       //receiver ka record new file mai dala
				}
				else{
				file1<<" "<<id<<" "<<" "<<name<<" "<<address<<" "<<pin<<" "<<phone<<" "<<type<<" "<<balance<<"\n";    //baki logo ka record v aa gya	
				}
			file>>id>>name>>address>>pin>>phone>>type>>balance;               //loop chalta hi ja rha hai	
			}                                                                  //while closed
			file.close();
			file1.close();
			remove("s.txt");
			rename("s1.txt","s.txt");
			cout<<"\n\n\t\t\tTransaction Successful....";
		}                                                                  //transaction perform wala if khatam
		
		else{
			cout<<"\n\n\t\t\tAccount No or Balance input are invalid.....";
		}	
	}	
}

void bank::payment(){
	system("cls");
	fstream file,file1;
	int found=0;
	string t_id,b_name;
	float amount;
	SYSTEMTIME x;
	cout<<"\n\n\t\t\t Bills Payment Option";
	file.open("s.txt",ios::in);
	if(!file){
		cout<<"\n\nFile Opening Error....";
	}
	else{
		cout<<"\n\nAccount No : ";                                      //if file exist
		cin>>t_id;
		cout<<"\n\nBill Name : ";
		cin>>b_name;
		cout<<"\n\nBill Amount : ";
		cin>>amount;
		file1.open("s1.txt",ios::app|ios::out); 
		file>>id>>name>>address>>pin>>phone>>type>>balance;                //original se fetch
		while(!file.eof()){
			if(t_id==id&&amount<=balance){                                          //to check id and amount
			balance-=amount;                                         //update kiya balance
			file1<<" "<<id<<" "<<" "<<name<<" "<<address<<" "<<pin<<" "<<phone<<" "<<type<<" "<<balance<<"\n";    //new file mai jo kar rha uska data send kiya
			found++;	
			}
			else{
			file1<<" "<<id<<" "<<" "<<name<<" "<<address<<" "<<pin<<" "<<phone<<" "<<type<<" "<<balance<<"\n";                      //jo dusri datas hai unhe v bheja hai	
			}
		file>>id>>name>>address>>pin>>phone>>type>>balance;                     //loop chalane k liye		
		}                                               //while close  
		file.close();                                   //files closed
		file1.close();
		remove("s.txt");
		rename("s1.txt","s.txt");
		if(found==1){
			GetSystemTime(&x);                          //isse time lenge present
			file.open("bill.txt",ios::app|ios::out);                          //nyi file banayi bill naam se jaha sara record jayega
			file<<t_id<<" "<<" "<<b_name<<" "<<" "<<amount<<" "<<x.wDay<<"/"<<x.wMonth<<"/"<<x.wYear<<"\n";             //new file bill mai ye sab bheja hai
			file.close();
			cout<<"\n\n\t\t\t"<<b_name<<"  Bill Payment Successful......";	
		}
		else{
			cout<<"\n\n\t\t\tAccount No or Balance input are invalid.....";                    //agar amount jyada or id invalid	
		}	                                                   
	}                                                                                         //when file exist wala else close	
} 

void bank::search(){
	system("cls");
	fstream file;
	string t_id;
	int found=0;
	cout<<"\n\n\t\t\tSearch User Record";
	file.open("s.txt",ios::in);
	if(!file){
		cout<<"\n\nFile Opening Error....";
	}
	else{
		cout<<"\n\nAccount No : ";
		cin>>t_id;
	    file>>id>>name>>address>>pin>>phone>>type>>balance;
		while(!file.eof()){
			if(t_id==id){
				system("cls");
				cout<<"\n\n\t\t\tUser Record";
				cout<<"\n\n\n"<<"Account No : "<<id<<"\n\n";
				cout<<"Name : "<<name<<"\n\n";
				cout<<"Address : "<<address<<"\n\n";
				cout<<"Phone NO : "<<phone<<"\n\n";
				cout<<"Account Type : "<<type<<"\n\n";
				cout<<"Current Balance : "<<balance;
				found++;	
			}                                                           //if closed	
		file>>id>>name>>address>>pin>>phone>>type>>balance;     //loop chalane k liye	
		}                                                               //while closed
		file.close();
		if(found==0){
		    cout<<"\n\nAccount No Don't Exist....";	
		}		
	}	                                    //else closed
} 

void bank::edit(){
	system("cls");
	fstream file,file1;
	string t_id,pi,a,ph;
	char t;
	int ch;
	int found=0;
	cout<<"\n\n\t\t\tEdit User Record";
	file.open("s.txt",ios::in);
	if(!file){
		cout<<"\n\nFile Opening Error....";
	}
	else{
		cout<<"\n\n1.Address ";
		cout<<"\n2.PIN ";
		cout<<"\n3.Phone No ";
		cout<<"\n4.Account Type ";
		cout<<"\n\nEnter Your Choice : ";
		cin>>ch;
		switch(ch){
		case 1:        //address
		system("cls");
		cout<<"\n\nAccount No : ";
		cin>>t_id;
		file1.open("s1.txt",ios::app|ios::out);
		file>>id>>name>>address>>pin>>phone>>type>>balance;
		while(!file.eof()){
			if(t_id==id){
        		cout<<"\n\nNew Address : ";
		        cin>>a;
		        file1<<" "<<id<<" "<<" "<<name<<" "<<a<<" "<<pin<<" "<<phone<<" "<<type<<" "<<balance<<"\n";     //new file mai id aur balance ko chod kar sab bhej diya
		        cout<<"\n\n\t\t\tUser Record Edited Successfully....";
		        found++;
			}                                                           //if closed	
			else{
				file1<<" "<<id<<" "<<" "<<name<<" "<<address<<" "<<pin<<" "<<phone<<" "<<type<<" "<<balance<<"\n";      //other users data saved unbothered
			}
		file>>id>>name>>address>>pin>>phone>>type>>balance;     //loop chalane k liye	
		}                                                               //while closed
		file.close();
		file1.close();
		remove("s.txt");
		rename("s1.txt","s.txt");
		if(found==0){
		    cout<<"\n\nAccount No Don't Exist....";
	    }
		break;
		case 2 : 
		system("cls");
		cout<<"\n\nAccount No : ";
		cin>>t_id;
		file1.open("s1.txt",ios::app|ios::out);
		file>>id>>name>>address>>pin>>phone>>type>>balance;
		while(!file.eof()){
			if(t_id==id){
				system("cls");
        		while (true) {
		        cout << "\n\n New PIN(4 digit) : ";
		        cin >> pi;
		        
		        if (pi.length() == 4 && digits(pi)) {
		            break;  // Valid account number, exit the loop
		        } else {
		            cout << "\n\nInvalid Pin No... Please enter a 4-digit pin number....\n" << endl;
		        getch();
				}
		        }
		        file1<<" "<<id<<" "<<" "<<name<<" "<<address<<" "<<pi<<" "<<phone<<" "<<type<<" "<<balance<<"\n";     //new file mai id aur balance ko chod kar sab bhej diya
		        cout<<"\n\n\t\t\tUser Record Edited Successfully....";
		        found++;
			}                                                           //if closed	
			else{
				file1<<" "<<id<<" "<<" "<<name<<" "<<address<<" "<<pin<<" "<<phone<<" "<<type<<" "<<balance<<"\n";      //other users data saved unbothered
			}
		file>>id>>name>>address>>pin>>phone>>type>>balance;     //loop chalane k liye	
		}                                                               //while closed
		file.close();
		file1.close();
		remove("s.txt");
		rename("s1.txt","s.txt");
		if(found==0){
		    cout<<"\n\nAccount No Don't Exist....";
	    }
		break;
		
		case 3 :
			system("cls");
		cout<<"\n\nAccount No : ";
		cin>>t_id;
		file1.open("s1.txt",ios::app|ios::out);
		file>>id>>name>>address>>pin>>phone>>type>>balance;
		while(!file.eof()){
			if(t_id==id){
				system("cls");
        	    while (true) {
		        cout << "\n\nNew Phone No(10 digit) : ";
		        cin >> ph;
		        
		        if (ph.length() == 10 && digits(ph)) {
		            break;  // Valid account number, exit the loop
		        } else {
		            cout << "\n\nInvalid Phone No... Please enter a 10-digit phone number....\n" << endl;
		        getch();
				}
		        }
		        file1<<" "<<id<<" "<<" "<<name<<" "<<address<<" "<<pin<<" "<<ph<<" "<<type<<" "<<balance<<"\n";     //new file mai id aur balance ko chod kar sab bhej diya
		        cout<<"\n\n\t\t\tUser Record Edited Successfully....";
		        found++;
			}                                                           //if closed	
			else{
				file1<<" "<<id<<" "<<" "<<name<<" "<<address<<" "<<pin<<" "<<phone<<" "<<type<<" "<<balance<<"\n";      //other users data saved unbothered
			}
		file>>id>>name>>address>>pin>>phone>>type>>balance;     //loop chalane k liye	
		}                                                               //while closed
		file.close();
		file1.close();
		remove("s.txt");
		rename("s1.txt","s.txt");
		if(found==0){
		    cout<<"\n\nAccount No Don't Exist....";
	    }
		break;
		
		case 4:
			system("cls");
		cout<<"\n\nAccount No : ";
		cin>>t_id;
		file1.open("s1.txt",ios::app|ios::out);
		file>>id>>name>>address>>pin>>phone>>type>>balance;
		while(!file.eof()){
			if(t_id==id){
				system("cls");
        		while (true) {
		        cout << "\n\nEnter 'c' for Current Account or 's' for Savings Account : ";
		        cin >> t;
		
		        t = toupper(t);  // Convert to uppercase
		
		        if (t == 'C' || t == 'S') {
		            if (t == 'C') {
		                cout << "\nYou've selected Current Account.\n" << endl;
		            } else {
		                cout << "\nYou've selected Savings Account.\n" << endl;
		            }
		            break;  // Exit the loop
		        } else {
		            cout << "\nInvalid input. Please enter 'c' for Current Account or 's' for Savings Account." << endl;
		        }
		    }
		        file1<<" "<<id<<" "<<" "<<name<<" "<<address<<" "<<pin<<" "<<phone<<" "<<t<<" "<<balance<<"\n";     //new file mai id aur balance ko chod kar sab bhej diya
		        cout<<"\n\n\t\t\tUser Record Edited Successfully....";
		        found++;
			}                                                           //if closed	
			else{
				file1<<" "<<id<<" "<<" "<<name<<" "<<address<<" "<<pin<<" "<<phone<<" "<<type<<" "<<balance<<"\n";      //other users data saved unbothered
			}
		file>>id>>name>>address>>pin>>phone>>type>>balance;     //loop chalane k liye	
		}                                                               //while closed
		file.close();
		file1.close();
		remove("s.txt");
		rename("s1.txt","s.txt");
		if(found==0){
		    cout<<"\n\nAccount No Don't Exist....";
	    }
		break;
			
			
		
		default : cout<<"Invalid Input Please Try Again...";			
	}//switch	
}//else


}//function

void bank::del(){
	system("cls");
	fstream file,file1;
	string t_id;
	int found=0;
	cout<<"\n\n\t\t\tDelete User Record";
	file.open("s.txt",ios::in);
	if(!file){
		cout<<"\n\nFile Opening Error....";
	}
	else{
		cout<<"\n\nAccount No : ";
		cin>>t_id;
		file1.open("s1.txt",ios::app|ios::out);
		file>>id>>name>>address>>pin>>phone>>type>>balance;
		while(!file.eof()){
			if(t_id==id){
				system("cls");
				//ham file1 par data nhi bhejenge...
		        cout<<"\n\n\t\t\tUser Account Deleted Successfully....";
		        found++;
			}                                                           //if closed	
			else{
				file1<<" "<<id<<" "<<" "<<name<<" "<<address<<" "<<pin<<" "<<phone<<" "<<type<<" "<<balance<<"\n";      //other users data saved unbothered
			}
		file>>id>>name>>address>>pin>>phone>>type>>balance;     //loop chalane k liye	
		}                                                               //while closed
		file.close();
		file1.close();
		remove("s.txt");
		rename("s1.txt","s.txt");
		if(found==0){
		    cout<<"\n\nAccount No Don't Exist....";
	    }	
	}
}  


void bank::show_records() {
	system("cls");
    ifstream file("s.txt");

    if (!file) {
        cout << "File Opening Error." << endl;
        return;
    }

    cout << "\n\nUser Details:\n\n";
    cout << "\n+---------+---------------+-----------------+------------+-------+------------+";
    cout << "\n|  ID     |     Name      |      Address    |   Phone    | Type  |  Balance   |";
    cout << "\n+---------+---------------+-----------------+------------+-------+------------+";

    while (file >> id >> name >> address >> pin >> phone >> type >> balance) {
        cout << "\n|" << setw(8) << id << "|" << setw(15) << name << " | " << setw(15) << address << " |" << setw(12) << phone << "|"
             << setw(7) << type << "|" << setw(12) << balance << "|"; // Aligning the | symbol with balance
        cout << "\n+--------+----------------+-----------------+------------+-------+------------+";
        cout << "\n"; // Blank line between entries
    }

    file.close();
}

void bank::show_payment() {
    system("cls");
    fstream file;
    int found = 0;
    float amount;
    string name, c_date;
    
    cout << "\n\n\t\t\tBill Payment Records";
    
    file.open("bill.txt", ios::in);

    if (!file) {
        cout << "\n\nFile Opening Error....";
    } else {
        cout << "\n\n+----------+-----------------+------------+--------------+";
        cout << "\n| Account  |    Bill Name    |   Amount   |     Date     |";
        cout << "\n+----------+-----------------+------------+--------------+";

        while (file >> id >> name >> amount >> c_date) {
            cout << "\n| " << setw(8) << id << " |" << setw(17) << name << " | " << setw(10) << amount << "| " 
                 << setw(12) << c_date << " |";
            cout << "\n+----------+-----------------+------------+--------------+";
            found++;
        }

        file.close();

        if (found == 0) {
            cout << "\n\nDatabase is Empty.....";
        }
    }
}

void bank::user_balance(){
	system("cls");
	cout<<"\n\n\t\t\tUser Login & Check Balance";
	fstream file;
	int found=0;
	string t_id,t_pin;
	char ch;
	file.open("s.txt",ios::in);
	if(!file){
		cout<<"\n\nFile Opening Error....";
	}else{
		cout<<"\n\nUser ID : ";
		cin>>t_id;
		cout<<"\n\nPin Code : ";
		for(int i=1;i<=4;i++){
			ch=getch();
			t_pin+=ch;
			cout<<"*";
		}
		
		file>>id>>name>>address>>pin>>phone>>type>>balance;
		while(!file.eof()){
			if(t_id==id && t_pin==pin){
				cout<<"\n\n\t\t\tYour Current Balance : "<<balance;
				found++;
			}file>>id>>name>>address>>pin>>phone>>type>>balance;
		}
		file.close();
		if(found==0){
			cout<<"\n\n\t\t\tUser ID & Pin & Pass Invalid....";
		}
	
	}	
} 

void bank::with_atm(){
	
	fstream file;
	string t_id,t_pin;
	fstream file1;
	int found=0;
	float with;
	char ch;
	system("cls");
	cout<<"\n\n\t\t\tWithdraw Amount Option";
	file.open("s.txt",ios::in);           //read mode
	if(!file){
		cout<<"\n\nFile Opening Error....";                 //if don't exist
	}
	else{
		cout<<"\n\nAccount No : ";                        
		cin>>t_id; 
		cout<<"\n\nPin Code : ";
		for(int i=1;i<=4;i++){
			ch=getch();
			t_pin+=ch;
			cout<<"*";
		}
		file1.open("s1.txt",ios::app|ios::out);                            //khola secondary ko
		                                 
		file>>id>>name>>address>>pin>>phone>>type>>balance;         //data fetch kiya original se   
		while(!file.eof()){
			if(t_id == id&&t_pin==pin){
			system("cls");
		    cout<<"\n\nEnter Withdraw Amount : ";
		    cin>>with;
		    if(with<=balance){
			
		    balance-=with;                          //update ho gya balance
		    file1<<" "<<id<<" "<<" "<<name<<" "<<address<<" "<<pin<<" "<<phone<<" "<<type<<" "<<balance<<"\n";     //space bhejenge fir id bhejenge                       
			                     
			cout<<"\n\n\t\t\tYour Amount "<<with<<" succesfully withdrawn...."; 
			cout<<"\n\n\t\t\tCurrent Balance : "<<balance;                                                         
		    } 
			else{
				cout<<"Your current balance "<<balance<<" is less than "<<with;
			file1<<" "<<id<<" "<<" "<<name<<" "<<address<<" "<<pin<<" "<<phone<<" "<<type<<" "<<balance<<"\n";
			} 
			found++;
		}
			else{                                     //jo data aaya jo update nhi hua vo v file mai jayega
				file1<<" "<<id<<" "<<" "<<name<<" "<<address<<" "<<pin<<" "<<phone<<" "<<type<<" "<<balance<<"\n";							
				}                                                                
			file>>id>>name>>address>>pin>>phone>>type>>balance;                
     	}file.close(); 
		 file1.close();
		 remove("s.txt");          //remove kiya 
		 rename("s1.txt","s.txt");                                                    
     	if(found==0){
     		cout<<"\n\nInvalid Account No or Pin code....";
        }
    }	
}

void bank::check_details(){
	fstream file;
	string t_id,t_pin;
	int found=0;
	char ch;
	system("cls");
	cout<<"\n\n\t\t\tCheck Account Details";
	file.open("s.txt",ios::in);           //read mode
	if(!file){
		cout<<"\n\nFile Opening Error....";                 //if don't exist
	}
	else{
		cout<<"\n\nAccount No : ";                        
		cin>>t_id; 
		cout<<"\n\nPin Code : ";
		for(int i=1;i<=4;i++){
			ch=getch();
			t_pin+=ch;
			cout<<"*";
		}                                                            
		file>>id>>name>>address>>pin>>phone>>type>>balance;         //data fetch kiya original se   
		while(!file.eof()){
			if(t_id == id&&t_pin==pin){
			system("cls");
		    	cout<<"\n\n\t\t\tCheck Account Details";
				cout<<"\n\n\n"<<"Account No : "<<id<<"\n\n";
				cout<<"Name : "<<name<<"\n\n";
				cout<<"Address : "<<address<<"\n\n";
				cout<<"Phone NO : "<<phone<<"\n\n";
				cout<<"Account Type : "<<type<<"\n\n";
				cout<<"Current Balance : "<<balance;
			found++;
		}
        file>>id>>name>>address>>pin>>phone>>type>>balance;                
     	}file.close();                                                    
     	if(found==0){
     		cout<<"\n\nInvalid Account No or Pin code....";
        }
    }	
}
                                                                                                         
void style::intro(){
	cout<<"\n\n\n\n\n\n\t\t\t";
	for(int i=1;i<=100;i++){
		cout<<"*";
	}
	cout<<"\n\t\t\t ";
	for(int i=1;i<=98;i++){
		cout<<"*";
	}
	cout<<"\n\t\t\t  ";
	for(int i=1;i<=96;i++){
		cout<<"*";
	}
	cout<<"\n\n\t\t\t\t\t\t\t  Bank & ATM Management System\n\t\t\t\t\t\t\t\t Project in C++";
	
	cout<<"\n\n\t\t\t  ";
	for(int i=1;i<=96;i++){
		cout<<"*";
	}
	cout<<"\n\t\t\t ";
	for(int i=1;i<=98;i++){
		cout<<"*";
	}
	
	cout<<"\n\t\t\t";
	for(int i=1;i<=100;i++){
		cout<<"*";
	}
	getch();
	system("cls");
	cout<<"\n\n\n\n\n\n\t\t\t";
	for(int i=1;i<=100;i++){
		cout<<"*";
	}
	cout<<"\n\t\t\t ";
	for(int i=1;i<=98;i++){
		cout<<"*";
	}
	cout<<"\n\t\t\t  ";
	for(int i=1;i<=96;i++){
		cout<<"*";
	}
	cout<<"\n\n\t\t\t\t\t\t\t\t  MADE BY \n\n\t\t\t\t\t\t  PRONAY BHOUMICK AND SPARSH SINGH CHUNDAWAT\n\n\t\t\t\t\t\t\t\t SKIT JAIPUR\n\n\t\t\t\t\t\t\t\t BRANCH : AI\n\n\t\t\t\t\t\t\t\t SECTION : B";
	
	cout<<"\n\n\t\t\t  ";
	for(int i=1;i<=96;i++){
		cout<<"*";
	}
	cout<<"\n\t\t\t ";
	for(int i=1;i<=98;i++){
		cout<<"*";
	}
	
	cout<<"\n\t\t\t";
	for(int i=1;i<=100;i++){
		cout<<"*";
	}
	getch();			
}

bool bank::digits(const string& str){
	 for (size_t i = 0; i < str.length(); ++i) {
        if (!isdigit(str[i])) {
            return false;
        }
    }
    return true;	
}

void style::outro(){
	system("cls");
		cout<<"\n\n\n\n\n\n\t\t\t";
	for(int i=1;i<=100;i++){
		cout<<"*";
	}
	cout<<"\n\t\t\t ";
	for(int i=1;i<=98;i++){
		cout<<"*";
	}
	cout<<"\n\t\t\t  ";
	for(int i=1;i<=96;i++){
		cout<<"*";
	}
	cout<<"\n\n\t\t\t\t\t\t\t\t  THANKS FOR VISITING\n\t\t\t\t\t\t\t\t\t SPRONI\n\t\t\t\t\t\t\t\t Bank Management System";
	
	cout<<"\n\n\t\t\t  ";
	for(int i=1;i<=96;i++){
		cout<<"*";
	}
	cout<<"\n\t\t\t ";
	for(int i=1;i<=98;i++){
		cout<<"*";
	}
	
	cout<<"\n\t\t\t";
	for(int i=1;i<=100;i++){
		cout<<"*";
	}
	getch();	
}

int main(){
	bank obj;
	obj.intro();
	obj.menu();
	obj.outro();
	return 0;	
}