//Copyright Douglas Wendel 2020
#include <iostream>
#include <vector>
#include<iterator>
using namespace std;
void SolveHuger(int n, vector<string> a, vector<string> b,vector<string> c);
int moveStackofPairs(int n, vector<string> &a, vector<string> &b,vector<string> &c, int temp);
void print(vector<string> a, vector<string> b,vector<string> c);
int main(int argc, char* argv[]) {
    int n;
    cin >> n;
    std::vector<string> a;//peg 1
    //char x = "A";
    string alpha [26]= {"A","B","C","D","E","F","G","H","I","J","K","L","M",
    "N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
    int numbers = 1;
    int counter = 0;
    for(int i = 0; i < n*2; i+=2) {
        a.push_back(alpha[counter]);
        a.push_back(to_string(numbers));
        counter++;
        numbers++;
    }
    std::vector<string> b; //peg 2
    std::vector<string> c; //peg 3
    cout << "Starting At" << endl;
    print(a,b,c);
    SolveHuger(n,a,b,c);
    cout << "Done!\n";
    return 0;
}
void SolveHuger(int n, vector<string> a, vector<string> b, vector<string> c) {
    //cout << "Starting At" << endl;
    int temp = 1;
    if(n < 2) {
        //a to c.
        cout << "Step " << temp << ": Move disk " << a.back() << " from peg 0 to peg 2" << endl;
        c.push_back(a.back());
        a.pop_back();
        print(a,b,c);
        temp++;
        //a to b.
        cout << "Step " << temp << ": Move disk " <<a.back() << " from peg 0 to peg 1" << endl;
        b.push_back(a.back());
        a.pop_back();
        print(a,b,c);
        temp++;
    }
    else {
        temp = moveStackofPairs(n-1,a,b,c, temp);
        //a to c.
        cout << "Step " << temp << " : Move disk " << a.back() << " from peg 0 to peg 2" << endl;;
        c.push_back(a.back());
        a.pop_back();
        print(a,b,c);
        temp++;
        // another from a to c.
        cout << "Step " << temp << " : Move disk " << a.back() << " from peg 0 to peg 2" << endl;
        c.push_back(a.back());
        a.pop_back();
        print(a,b,c);
        temp++;
        moveStackofPairs(n-1,b,a,c, temp);
        //c to b.
        cout << "Step " << temp << ": Move disk " << c.back() << " from peg 2 to peg 1" << endl;
        b.push_back(c.back());
        c.pop_back();
        print(a,b,c);
        temp++;
        SolveHuger(n-1,a,b,c);
    }
}
 int moveStackofPairs(int n, vector<string> &a, vector<string> &b,vector<string> &c, int temp) {
    if(n<2){
        //a to c
        cout << "Step " << temp << " : Move disk " << a.back() << " from peg 0 to peg 2" << endl;
        c.push_back(a.back());
        a.pop_back();
        print(a,b,c);
        temp++;
        //a to b
        cout << "Step " << temp << ": Move disk " <<a.back() << " from peg 0 to peg 1"<< endl;
        b.push_back(a.back());
        a.pop_back();
        print(a,b,c);
        temp++;
        //c to b
        cout << "Step " << temp << ": Move disk " << c.back() << " from peg 2 to peg 1"<< endl;
        b.push_back(c.back());
        c.pop_back();
        print(a,b,c);
        temp++;
        return temp;
    }
    else {
        moveStackofPairs(n-1,a,b,c, temp);
        //a to c
        cout << "Step " << temp << ": Move disk " << a.back() << "from peg 0 to peg 2"<< endl;
        c.push_back(a.back());
        a.pop_back();
        print(a,b,c);
        //a to c
        temp++;
        cout << "Step " << temp << ": Move disk " << a.back() << "from peg 0 to peg 2"<< endl;
        c.push_back(a.back());
        a.pop_back();
        print(a,b,c);
        moveStackofPairs(n-1, b,a,c,temp);
        //c to b
        temp++;
        cout << "Step " << temp << ": Move disk " << c.back() << "from peg 2 to peg 2"<< endl;
        b.push_back(c.back());
        c.pop_back();
        print(a,b,c);
 
        //c to b
        temp++;
        cout << "Step " << temp << ": Move disk " << c.back() << "from peg 2 to peg 1"<< endl;
        b.push_back(c.back());
        c.pop_back();
        print(a,b,c);
        moveStackofPairs(n-1,a,b,c,temp);
    }
}
void print(vector<string>a, vector<string> b,vector<string> c) {
    int step;
    cout << "0:";
    for(int i =0; i < a.size(); i++){
        cout << a[i];
    }
    cout << endl;
    cout << "1:";
    for(int i = 0; i < b.size(); i++){
        cout << b[i];
    }
    cout << endl;
    cout << "2:";
    for(int i =0; i < c.size(); i++){
        cout << c[i];
    }
    cout << endl;
}
