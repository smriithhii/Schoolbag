#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;

class SchoolBag;   //class forwarding

class Sanitizer
{
public:
    string brand;
    string ssize;            //sanitizer size
    float quan;              //quantity;
    string chemicals[2];     //chemicals present in it

    void getDetSan()
    {
        cout<<"\n\t\tSanitizer Details"<<endl;
        cout<<"Enter brand: "<<endl;
        cin>>brand;
        cout<<"Enter size of the bottle: "<<endl;
        cin>>ssize;
        cout<<"Enter quantity of sanitizer bottle: "<<endl;
        cin>>quan;
        for(int i=0;i<2;i++)
        {
            cout<<"Enter the chemicals "<<i+1<<") in it: ";
            cin>>chemicals[i];
        }
    }

    void dispDetSan()
    {
        cout<<"\n\t\tSanitizer Details"<<endl;
        cout<<"Brand: "<<brand<<endl;
        cout<<"Size of the bottle: "<<ssize<<endl;
        cout<<"Quantity of sanitizer bottle: "<<quan<<endl;
        for(int i=0;i<2;i++)
        {
            cout<<"The chemicals in it "<<i+1<<" ";
            cout<<chemicals[i];
        }
    }


};

class SchoolBag
{
public:
    string brand;
    string color;;
    int nOfStuff;
    Sanitizer s;    //aggregation
    void sanit()
    {
        s.getDetSan();
    }
};

void getContent(SchoolBag &s1)              //non-member functions
{
    cout<<"\t\tContents of the bag"<<endl;
    cout<<"Enter brand: "<<endl;
    cin>>s1.brand;
    cout<<"Enter color of the bag: "<<endl;
    cin>>s1.color;
    cout<<"Enter the number of items present in the bag: "<<endl;
    cin>>s1.nOfStuff;
}


void dispContent(SchoolBag &s1)
{
    cout<<"\n\t\tContents of the bag"<<endl;
    cout<<"Brand of the bag: "<<s1.brand<<endl;
    cout<<"Color of thr bag: "<<s1.color<<endl;
    cout<<"No of stuff present in the bag: "<<s1.nOfStuff<<endl;
}


class tag
{
    public:
        string name;
        int level;
        char sec;
};

istream& operator>>(istream& in,tag &t1)      //stream operator overloading (cin)
{
    cout<<"\n\nEnter the tag details: \n";
    cout<<"Enter name: ";
    in>>t1.name;
    cout<<"Enter level: ";
    in>>t1.level;
    cout<<"Enter section: ";
    in>>t1.sec;
    return cin;
}

ostream& operator<<(ostream& out,tag &t1)    //stream operator overloading (cout)
{
    out<<"\ntag details\n";
    out<<t1.name;
    out<<t1.level;
    out<<t1.sec;
    return out;
}

class NoteBook:public SchoolBag
{
public:
    string size;                  //long size, short size and pocketsize
    int pages;
    string shape;                 //rectangular or square shaped
    string pType;                 //as in made from wood or soft paper or made wood free
    string r;                     //ruled or unruled
    string subject;

    void getDetails()
    {
        cout<<"\n\t\tGetting notebook details"<<endl;
        cout<<"Enter the subject of the notebook: "<<endl;
        cin>>subject;
        cout<<"Enter the size of the notebook: "<<endl;
        cin>>size;
        cout<<"Enter the no of pages: "<<endl;
        cin>>pages;
        cout<<"Enter the shape of the notebook: "<<endl;
        cin>>shape;
        cout<<"Enter the type of paper used(w-wood,s-soft paper,wf-woodfree): "<<endl;
        cin>>pType;
        cout<<"Ruled or unruled: "<<endl;
        cin>>r;
    }

    void dispDetails()
    {
        cout<<"\n\t\tNotebook details\n"<<endl;
        cout<<"Subject of the notebook: "<<subject<<endl;
        cout<<"Size of the notebook: "<<size<<endl;
        cout<<"No of pages: "<<pages<<endl;
        cout<<"Shape of the notebook: "<<shape<<endl;
        cout<<"Type of paper used(w-wood,s-soft paper,wf-woodfree): "<<pType<<endl;
        cout<<"Ruled or unruled: "<<r<<endl;
    }

    void write()                               //function to write in the notebook
    {
        cout<<"\nWriting in the notebook"<<endl;
        string line="";
        ofstream f1;
        f1.open("notebook.txt",ios::app);
        while(line!="-1")
        {
            getline(cin,line);
            f1<<line<<endl;
        }
        f1.close();
        cout<<"Written into the notebook"<<endl;
    }
    void read()                                 //function to read the notebook
    {
        cout<<"\nReading the notebook"<<endl;
        string line;
        ifstream f1;
        f1.open("notebook.txt",ios::in);
        while(f1)
        {
          getline(f1,line);
          cout<<line<<endl;
        }
        f1.close();
        cout<<"Notebook read"<<endl;
    }
};

class Book:public SchoolBag
{
public:
    string sub;
    int pg;
    static int c;                        //static variable
    virtual void get()                   //virtual function
    {
        c+=1;
        cout<<"\n\ngetting Details of book\n\n";
        cout<<"Enter the subject: ";
        cin>>sub;
        cout<<"Enter the number of pages in the book: ";
        cin>>pg;
    }

    void disp()
    {
        c+=1;
        cout<<"\n\ndetails of book\n";
        cout<<"Subject: "<<sub<<endl;
        cout<<"Number of pages in the book: "<<pg<<endl;
    }

    void readBook()                       //reads the data stored in the respective subject book file
    {
        string f;
        string line;
        f=sub+".txt";
        ifstream f1;
        f1.open(f,ios::in);
        if(f1.is_open())
        {
            cout<<"Reading the book"<<endl;
            while(f1)
            {
                getline(f1,line);
                cout<<line<<endl;
            }
        }
        else
            cout<<"No book with title "<<sub;
        f1.close();
    }
};
int Book::c=0;     //initialising static variable

class Bottle
{
public:
    string shape;
    string color;
    float qty;               //quantity
    string material;         //material of waterbottle as in flask or plastic or metal

    Bottle()                                       //default constructor
    {
        shape="";
        color="";
        qty=0;
        material="";
    }
    Bottle(string s, string c,float qu,string t)   //parameterized constructor
    {
        shape=s;
        color=c;
        qty=qu;
        material=t;
    }
    Bottle(const Bottle &b)                        //copy constructor
    {
        shape=b.shape;
        color=b.color;
        qty=b.qty;
        material=b.material;
    }

    void getBotDet()
    {
        cout<<"\n\t\tGetting water bottle details"<<endl;
        cout<<"Enter the shape of the water bottle: "<<endl;
        cin>>shape;
        cout<<"Enter color of the bottle: "<<endl;
        cin>>color;
        cout<<"Enter the material of water bottle: "<<endl;
        cin>>material;
        cout<<"Enter the quantity of the bottle: "<<endl;
        cin>>qty;
    }

    void dispBotDet()
    {
        cout<<"\t\tDisplaying water bottle details"<<endl;
        cout<<"Shape of the water bottle: "<<shape<<endl;
        cout<<"Color of the bottle: "<<color<<endl;
        cout<<"Material of water bottle: "<<material<<endl;
        cout<<"Quantity of the bottle: "<<qty<<endl;
    }

    template<typename t>         //using template finding how much more quantity of water can be filled
    t remaining_capacity()
    {
        t filled;
        cout<<"Enter the quantity filled in the bottle: "<<endl;
        cin>>filled;
        t remaining=qty-filled;
        cout<<"Remaining capacity = ";
        return remaining;
    }
};

class Pouch:public SchoolBag
{
public:
    int tobj;
    bool compass,div;
    int divisions;
    int n;
    void getpouchdetails()
    {
        cout<<"\nGetting pouch details\n";
        cout<<"Enter the number of divisions in the pouch: ";
        cin>>divisions;
        cout<<"Enter the number of objects in the pouch: ";
        cin>>n;
    }

    void dispPouchdetails()
    {
        cout<<"\nPouch details: \n";
        cout<<"Number of divisions in the pouch: "<<divisions<<endl;
        cout<<"Number of objects in the pouch: "<<n<<endl;
    }

    void print(int n)
    {
        int i;
        string obj[n];
        for(int i=0;i<n;i++)
        {
            cout<<"Enter an object";
            cin>>obj[i];

        }

        for(int i=0;i<n;i++)
            cout<<obj[i]<<endl;
    }

    friend void geometrybox(Pouch p);             //friend function

};

void geometrybox(Pouch p)
{
    cout<<"Enter number of triangular scales: ";
    cin>>p.tobj;
    cout<<"have a compass(1/0): ";
    cin>>p.compass;
    cout<<"includes divider(1/0): ";
    cin>>p.div;

    cout<<"Details of geometry box:"<<endl;
    cout<<p.tobj<<endl;
    if(p.compass==1)
        cout<<"has a compass"<<endl;
    else
        cout<<"dont have a compass"<<endl;
    if(p.div==1)
        cout<<"Has a divider"<<endl;
    else
        cout<<"dont have a divider"<<endl;
}

class laptop:public Book            //multilevel inheritance
{
public:
    string brand;
    int gb;
    void get()
    {
        cout<<"\n\ngetting laptop details\n";
        cout<<"Enter the brand: ";
        cin>>brand;
        cout<<"size of ram: ";
        cin>>gb;
        cout<<"Enter the subject: ";
        cin>>sub;
        cout<<"Enter the number of pages in the book: ";
        cin>>pg;
    }

    void display()
    {
        cout<<"\t\tDisplaying details of the laptop"<<endl;
        cout<<"Subject: "<<sub<<endl;
        cout<<"Number of pages in the book: "<<pg<<endl;
        cout<<"Brand: "<<brand<<endl;
        cout<<"Size of ram: "<<gb<<endl;
    }
};



class lunchbag:public SchoolBag   //abstract class
{
public:
    string colour;
    string shape;
    virtual void content()=0;     // pure virtual function
};

class lunchbox:public lunchbag     //multilevel inheritance
{
public:
    int n;
    string food;
    bool juice;
    void content()
    {
        cout<<"Enter lunch box details\n";
        cout<<"Enter number of boxes: ";
        cin>>n;
        cout<<"Enter the shape: ";
        cin>>shape;
        cout<<"Enter colour: ";
        cin>>colour;
        cout<<"Juice included?(1-yes, 0-no)";
        cin>>juice;
    }

    void dispContent()
    {
        cout<<"\n\nDetails of lunchbox\n";
        cout<<"Number of boxes: "<<n<<endl;
        cout<<"Shape: "<<shape<<endl;
        cout<<"Color: "<<color<<endl;
        if (juice ==1)
            cout<<"Juice included"<<endl;
        else if (juice==0)
            cout<<"Juice not included: "<<endl;
    }
};

int main()
{
    SchoolBag sb;
    getContent(sb);
    sb.sanit();
    tag t1;
    cin>>t1;
    NoteBook n1;
    n1.getDetails();
    Book b1,b2;
    b1.get();
    b2.get();
    Bottle bot;
    bot.getBotDet();
    Pouch p1;
    p1.getpouchdetails();
    geometrybox(p1);
    lunchbox lu1;
    lu1.content();
    laptop l1;
    l1.get();

    // displaying all the details and doing read write operations with the objects
    int ch;
    dispContent(sb);
    cout<<t1;
    n1.dispDetails();
    while(1)
    {
        cout<<"1. write in notebook\n2.Read the notebook\n0.exit ";
        cin>>ch;
        if(ch==1)
            n1.write();
        else if(ch==2)
            n1.read();
        else
            break;
    }
    b1.disp();
    b2.disp();
    cout<<"Number of books: "<<b1.c;
    cout<<"do you want to read the books?(1 - yes, 0- no): ";
    cin>>ch;
    if(ch==1)
    {
        b1.readBook();
        b2.readBook();
    }
    bot.dispBotDet();
    cout<<bot.remaining_capacity<int>();
    cout<<bot.remaining_capacity<float>();
    p1.dispPouchdetails();
    p1.print(p1.n);
    lu1.dispContent();
    l1.display();
    cout<<"Do you want to read the book as softcopy? (yes -1 / no -0): ";
    cin>>ch;
    if(ch==1)
        l1.readBook();
    return 0;
}
