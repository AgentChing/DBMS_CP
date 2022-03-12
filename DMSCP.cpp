#include <bits/stdc++.h>
#include "dmscp.h"
using namespace std;

class Table{
public:
    string name;
    int attr_count;
    map <string, string> attr_type;
    map<string, vector<string> > attr_value;

    void showtable()
    {
        cout<<endl<<"Table name: "<<name<<" Attribute count: "<<attr_count<<endl;
        for(auto x: attr_type)
        {
            cout<<x.first<<" : "<<x.second<<"|  ";
        }
        cout<<endl;
        int s;
        for(auto x: attr_value)
        {
            cout<<x.first<<"\t";
            s = x.second.size();
        }
        for(int i=0;i<s;i++)
        {
            cout<<endl;
            for(auto x: attr_value)
            {
                cout<<x.second[i]<<"\t";
            }

        }
            cout<<endl;
    }
};

class Database{
unordered_map<string, vector<string> > metadata;
//string meta = "instructions.txt";
map<string , Table> database;

string metafile = "meta.txt";
string datafile = "data.txt";

public:
    Database(){
        loadData();
        showall();
    }

    void loadData()
    {
     ifstream meta(metafile);
     ifstream data(datafile);
     string line;
     while (getline (meta, line)) {
              vector<string> v = tokenizefile(line);
              stringstream num(v[1]);
              int n =0;
              num>>n;
              Table t;
              t.name = v[0];
              t.attr_count = n;
              v.erase(v.begin(),v.begin()+2);
              for(int i=0;i<v.size();i+=2)
              {
                  t.attr_type.insert(pair<string,string>(v[i],v[i+1]));
              }
              for(int i=0;i<n;i++)
              {
                  string line2;
                  getline (data, line2);
                  t.attr_value.insert(pair<string, vector<string> >(v[i*2],tokenizefile(line2)));
                  ///tablecolumns
              }
            database.insert(pair<string, Table>(t.name,t));
            }
        meta.close();
        data.close();

    }

    void showall()
    {
        for(auto x: database)
        {
            x.second.showtable();
        }
    }

    void storeData()
    {
        ofstream meta2;
        meta2.open("meta.txt");
        ofstream data2("data.txt");
        for(auto x: database)
        {
            meta2<<x.first<<" "<<x.second.attr_count<<" ";
            for(auto y: x.second.attr_type)
            {
                meta2<<y.first<<" "<<y.second<<" ";
                for(auto z: x.second.attr_value.find(y.first)->second)
                {
                    data2<<z<<" ";
                }
                data2<<endl;
            }
            meta2<<endl;
        }
        meta2.close();
        data2.close();
    }
};


void driver(Database d)
{
    string inst = "Instructions.txt";
    ifstream myfile(inst);
     string line;
     while (getline (myfile, line)) {
              vector<string> v = tokenizefile(line);
              for(int i=0;i<v.size();i++)
              {
                  ///cout<<v[i]<<endl;
              }
              if(absolutecompare(v[0],"CREATE"))
              {
                  cout<<"FOUND CREATE-------------";
              }
              else if(absolutecompare(v[0],"DROP"))
              {

                  cout<<"FOUND DROP-------------";
              }else if(absolutecompare(v[0],"SELECT"))
              {
                  cout<<"FOUND SELECT-------------";
              }else if(absolutecompare(v[0],"INSERT"))
              {
                  cout<<"FOUND INSERT-------------";

              }else if(absolutecompare(v[0],"DELETE"))
              {
                  cout<<"FOUND DELETE-------------";

              }else if(absolutecompare(v[0],"UPDATE"))
              {
                  cout<<"FOUND UPDATE-------------";

              }else if(absolutecompare(v[0],"QUIT"))
              {
                  cout<<"FOUND QUIT-------------";
                  d.storeData();
                  cout<<"\nDONE";

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
