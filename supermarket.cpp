#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<fstream>

using namespace std; 

class shopping
{
    private:
      int pcode;
      float price;
      float discount;
      string pname;

      public:
      void menu();
      void administrator();
      void buyer();
      void add();
      void edit();
      void remov();
      void list();
      void receipt();
};

 void shopping :: menu()
 {
     m:
     int choice;
     string email;
     string password ;//login purpose

     cout<<"\t\t\t\t_________________________________\n";
     cout<<"\t\t\t\t                                 \n";
     cout<<"\t\t\t\t       SUPERMARKET MAIN MENU     \n";
     cout<<"\t\t\t\t                                 \n";
     cout<<"\t\t\t\t_________________________________\n";

     cout<<"\t\t\t\t |  1) Administrator   |\n";
     cout<<"\t\t\t\t |                     |\n";
     cout<<"\t\t\t\t |  2) buyer           |\n";
     cout<<"\t\t\t\t |                     |\n";
     cout<<"\t\t\t\t |  3)exit             |\n";
     cout<<"\t\t\t\t |                     |\n";
     cout<<"\t\t\t\t  Please Select";
     cin>>choice;

     switch(choice)
     {
     case 1:
     {
        cout<<"\t\t\t  Please Login  \n";
        cout<<"\t\t\t  Enter Email   \n";
        cin>>email;
        cout<<"\t\t\t  Enter Password   \n";
        cin>>password;

        if(email=="jesus@gmail.com" && password=="jesus@123")
        {
            administrator();
        }
        else{
            cout<<"Invalid Password";
        }
        break;
     }
    case 2:
    {
        buyer();
    }

    case 3:
    {
        exit(0);
    }

    default:
    {
        cout<<"Please select from the given options";
    }

}
goto m;//m-label,goto is a jump statement ,jumps to the main menu
 }

void shopping :: administrator()
{
    m:
    int choice;
    cout<<"\n\n\n\n\t\t  administrator menu";
    cout<<"\n\t\t\t|_____1)Add the product_____| ";
    cout<<"\n\t\t\t|_____                 _____| ";
    cout<<"\n\t\t\t|_____2)Modify the product__| ";
    cout<<"\n\t\t\t|_____                 _____| ";
    cout<<"\n\t\t\t|____3)delete the product___| ";
    cout<<"\n\t\t\t|_____                 _____| ";
    cout<<"\n\t\t\t|____4)Back to main menu____| ";

    cout<<"please enter your choice";
    cin>>choice;

    switch(choice)
    {
        case 1:
        add();
        break;

        case 2:
        edit();
        break;

        case 3:
          remov();
          break;

        case 4:
          menu();
          break;

        default:
         cout<<"invalid choice";
    }
    goto m;
}

void shopping :: buyer()
{
    m:
    int choice;
    cout<<"\n\n\n\n\t\t  buyer menu";
    cout<<"\n\t\t\t|_____1)Buy the product_____| ";
    cout<<"\n\t\t\t|_____                 _____| ";
    cout<<"\n\t\t\t|____2)Go Back to main menu_| ";

    cout<<"please enter your choice";
    cin>>choice;

    switch(choice)
    {
        case 1:
          receipt();
          break;

          case 2:
            menu();
            break;
            default:
             cout<<"invalid choice";
    }
    goto m;
}

void shopping :: add()
{
    m:
     fstream data;
     int c;
     int token =0;
     float p;
     float d;
     string n;

    cout<<"\n\n\t\t\t  Add new product";
    cout<<"\n\n\t\t\t  Product code of the product";
    cin>>pcode;
    cout<<"\n\n\t\t\t  Name of the product";
    cin>>pname;
    cout<<"\n\n\t\t\t  Price of the product";
    cin>>price;
    cout<<"\n\n\t Discount on product";
    cin>>discount;
//storing these product in a file we use file handling operations

data.open("database.txt",ios::in);//reading mode

if(!data)//if file doesn't exist 
{
    data.open("database.txt",ios::app |ios::out);//open in writing mode
    data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<discount<<"\n";
    data.close();
}
else//if file exist we read from file
{
    data>>c>>n>>p>>d;

    while(!data.eof())
    {
        if(c==pcode)
        {
            token++;//if admin same pcode token++
        }
        data>>c>>n>>p>>d;
    }
    data.close();


  if(token==1)
    goto m;
  else//token is unique
  {
    data.open("database.txt",ios::app |ios::out);
    data<<" "<<pcode<<pname<<" "<<price<<" "<<discount<<"\n";
    data.close();
  }
}
cout<<"record inserted";
}

void shopping :: edit() 
{
    fstream data,data1;
    int pkey;
    int token=0;
    int c;
    int p;
    int d;
    string n;
    
    cout<<"\n\t\t Modify the record";
    cout<<"\n\t\t product code";
    cin>>pkey;

    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"\n\n file doesn't exist";
    }
    else
    {
        data1.open("database1.txt",ios::app|ios::out);//append,writing  
        //save the edited data and rename to data

        data>>pcode>>pname>>price>>discount;
        while(!data.eof())
        {
            if(pkey==pcode)//pkey-admin wants to edit
            {
                cout<<"\n\t\t code of the product ";
                cin>>c;
                cout<<"\n\t\t name of the product";
                cin>>n;
                cout<<"\n\t\t  price";
                cin>>p;
                cout<<"\n\t\t discount;";
                cin>>d;
                data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
                cout<<"\n\t\t record edited";
                token++;
            }
            else//if code doesn't match
            {
              data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<discount<<"\n";
            }
            data>>pcode>>pname>>price>>discount;

        }
        data.close();
        data1.close();
        
        remove("database.txt");
        rename("database1.txt","database.txt");//name is changed

        if(token==0)
        {
            cout<<"\n\n record not found sorry";
        }
    }

}

void shopping:: remov()
{
    fstream data,data1;
    int pkey;
    int token =0;
    cout<<"\n\n\t delete product";
    cout<<"\n\n\t product code";
    cin>>pkey;
    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"\n\n file doesn't exist";
    }
    else
    {
        data1.open("database1.txt",ios::app|ios::out);//append,writing  
        //save the edited data and rename to data

        data>>pcode>>pname>>price>>discount;
        while(!data.eof())
        {
            if(pkey==pcode)//pkey-admin wants to edit
            {
                cout<<"\n\n\t product deleted sucessfully";
                token++;
            }
            else 
            {
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<discount<<"\n";
            }
            data>>pcode>>pname>>price>>discount;
        }
        data.close();
        data1.close();
    
        remove("database.txt");
        rename("database1.txt","database.txt");
  
         if(token==0)
        {
            cout<<"\n\n record not found sorry";
        }
    }
}

void shopping:: list()
{
    fstream data;
    data.open("database.txt",ios::in);
    cout<<"\n\n|_____________________|\n";
    cout<<"productno\t\tname\t\tprice";
    cout<<"\n\n|_____________________|\n";
    data>>pcode>>pname>>price>>discount;
    while(!data.eof())
    {
        cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\n";
        data>>pcode>>pname>>price>>discount;

    }
    data.close();
}

void shopping::receipt()
{
  fstream data;
  int arrc[100];//codes
  int arrq[100];//quantity
  char choice;
  int c=0;
  float amount=0;
  float discount=0;
  float total=0;

  cout<<"\n\n\t\t\t RECEIPT";
  data.open("database.txt",ios::in);
  if(!data)
  {
      cout<<"\n\n empty database";
  }
  else
{
  data.close();//close the file
  list();//pro available in sp
  cout<<"\n_____________________\n";
  cout<<"\n                     \n";
  cout<<"\n    place the order  \n";
  cout<<"\n                     \n";
  cout<<"\n_____________________\n";

  do
  {
    m:
    cout<<"\n\n enter the product code";
    cin>>arrc[c];
    cout<<"\n\n enter the product quantity";
    cin>>arrq[c];
    for(int i=0;i<c;i++)
    {
        if(arrc[c]==arrc[i])//duplicate pro code or not
        {
            cout<<"\n\n duplicate product code.please try again";
            goto m;
        }
    }
   
    c++;
    cout<<"\n\n do u want to buy another product or not?if yes then press y else n for no";
    cin>>choice;


 }while (choice =='y');


 cout<<"\n\n\t\t___________RECEIPT___________\n";

 cout<<"\nproduct no\tproduct name\tproduct quantity\tprice\tamount\t amt with discount\n";
 for(int i=0;i<c;i++)
 {
    data.open("database.txt",ios::in);
    data>>pcode>>pname>>price>>discount;
    
    while(!data.eof())
    {
       
        if(int(pcode)==int(arrc[i]))
        {
            amount=price*arrq[i];
            discount=amount-(amount*discount/100);
            total+=discount;
            cout<<"\n"<<pcode<<"\t\t"<<pname<<"\t\t"<<arrq[i]<<"\t\t"<<price<<"\t"<<amount<<"\t\t"<<discount;

         }
         
         data>>pcode>>pname>>price>>discount;
    }
     data.close();
 }


}
  cout<<"\n\n_________________";
  cout<<"\n total amount :"<<total;

}
int main()
{
    shopping s;
    s.menu();
}