#include<iostream>
#include<string>
using namespace std;

 class binary
 {
    private:
        string s;
        void chk_bin(void);

    public:
        void read(void);
        void ones(void);
        void display(void);
};

void binary :: read(void){
    cout<<"Enter a binary number"<<endl;
    cin>>s;
    chk_bin();        // nesting of member function
}

void binary :: chk_bin(void){
    for(int i = 0; i < s.length(); i++){
        if(s.at(i) != '0' && s.at(i) != '1'){
            cout<<"incorrect binary format"<<endl;
            exit(0);
        }

    }
}

void binary :: ones(void){
    for(int i = 0; i < s.length(); i++){
        if(s.at(i) == '0')
        s.at(i) = '1';
        else if (s.at(i) == '1')
        s.at(i) = '0';
    }
}

void binary :: display(void){
    for(int i = 0 ; i < s.length(); i++){
        cout<<s.at(i);
    }
    cout<<endl;
}


int main(){
    binary b;
    b.read();

    //b.chk_bin();
    // cant call it since it is private

    b.display();
    b.ones();
    b.display();
}
