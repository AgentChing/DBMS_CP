#include <bits/stdc++.h>
#include "dmscp.h"
using namespace std;



class Database{
unordered_map<string, vector<string> > metadata;
//string meta = "instructions.txt";
string meta = "meta.txt";

public:
    Database(){
     ifstream myfile(meta);
     string line;
     while (getline (myfile, line)) {
              vector<string> v = tokenizefile(line);
              for(int i=0;i<v.size();i++)
              {
                  ///cout<<v[i]<<endl;  ///Replace this part withcode which actually updates the database
              }
              cout<<endl;
            }
            myfile.close();


    }


};


void driver(Database d)
{
    string inst = "instructions.txt";
    ifstream myfile(inst);
     string line;
     while (getline (myfile, line)) {
              vector<string> v = tokenizefile(line);
              for(int i=0;i<v.size();i++)
              {
                  cout<<v[i]<<endl; ///read instructions and process
              }
              cout<<endl;
            }
            myfile.close();
}


int main()
{
    Database d;
    driver(d);



    return 0;
}
