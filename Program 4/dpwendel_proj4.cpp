/*
 Copyright Douglas Wendel 2020
 Project 4
 */
#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <cassert>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::min;
using std::map;

string input;
std::map<std::pair<int, int>, int> dp_table;
std::map<std::pair<int, int>, string> dp_table2;
//the p function returns an integer of i and j
int p(int i, int j) {
    //assert(false);
    //if (i==2 and j==2) cout << "were calling p " << i << " , " << j << endl;
    int ret_val;
    int ret_val2 = -1;
    auto i_j = std::make_pair(i,j);
    if(dp_table.count(i_j)) {
        ret_val2 = dp_table.find(i_j)->second;
        //if (i==2 and j==2) cout << "dptables contains " << ret_val2 << endl;
    }
    if(i==j) //could be off by 1, -1
        ret_val = 1;
    else if(i > j)
        ret_val = 0;
    else if(input.at(i) == input.at(j))
        ret_val = p(i + 1, j-1) + 2;
    else
        ret_val = std::min(p(i + 1, j) +2, p(i,j-1)+2);
    
   //if (i==2 and j==2)  cout << "computed value for i j is " << ret_val <<endl;
    if(ret_val2 != -1)
       assert((ret_val == ret_val2));
    dp_table.insert(std::make_pair(i_j, ret_val)); //inserts the values
    return ret_val;
}

string pal(int i, int j) {
     string ret_val;
     auto i_j = std::make_pair(i,j);
     if(dp_table2.count(i_j)) {
         ret_val = dp_table2.find(i_j)->second;
     }
     if(i==j) //could be off by 1, -1
         ret_val = input.at(i);
     else if(i > j)
         ret_val = "";
     else if(input.at(i) == input.at(j))
         ret_val = input.at(i) + pal(i + 1, j-1) + input.at(j);
     else {
         string s = input.at(i) + pal(i + 1,j) + (char)toupper(input.at(i));
         string s2 = (char)toupper(input.at(j)) + pal(i, j-1) + input.at(j);
         //ret_val = std::min(p(i + 1, j) +2, p(i,j-1)+2);3
         if(s.size() < s2.size()) {
             ret_val = s;
         }
         else
             ret_val = s2;
     }
     dp_table2.insert(std::make_pair(i_j, ret_val)); //inserts the values
     return ret_val;
}

int main(int argc, char* argv[]) {
    while(getline(std::cin, input)){
        dp_table.clear();
        if(input.size() == 0) {
            break;
        }
        int length = p(0,input.size()-1); //base case
        string minPal = pal(0, input.size()-1);
        //cout << input.size() << " " << input << "    " << length << endl;
        cout << length << " " << minPal << endl;
    }
}



