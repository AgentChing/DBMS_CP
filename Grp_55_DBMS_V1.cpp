#include<bits/stdc++.h>

using namespace std;

class Table{
    string name;
    ///Store attributes here

public:
    void setName(string tbl_name)
    {
        name = tbl_name;
    }
    string getName()
    {
        return name;
    }
    void setAttributes(///take your attributes in your order )
    {
        ///process it and store it in this instance.
    }

};

class Database{
    vector<Table*> db;

public:
    void createTable(string tbl_name, string tbl_attributes)
    {
        Table T;
        T.setName(tbl_name);
        ///1. process attributes by using T.setAttributes();

        db.push_back(T);
        T.clear();
    }
    void dropTable(string name)
    {
        for(int i=0;i<db.size();i++)
        {
            if(db[i].getName() == name)
            {
                db.erase(db.begin()+i);
                break;
            }
        }
    }
    void insertValue(string name, string values)
    {
        for(int i=0;i<db.size();i++)
        {
            if(db[i].getName() == name)
            {
                ///process the values and insert them accordingly.
                break;
            }
        }
    }

};

vector<string> tokenizer(string line)
{
 vector<string> tokens;
 ///Convert lines to tokens in this token vector and return it
 return tokens;
}

void driver()
{
    fstream file("<File location>");
    string line;
    Database db;
    while (getline (file, line))
        {
            vector<string> tokens = tokenizer(line);
            ///transform(token[0].begin(), token[0].end(), token[0].begin(), ::tolower);

            if(tokens[0]=="create")//CREATE TABLE Table_name (attribute_name attribute_type CHECK/NOT COnstrains/NULL)
            {
                ///here token[0] is create, token[1] is "table", token[2] is the name of table, token[3] is the attributes list with "curly braces".
                db.create(token[2],token[3]);
            }
            else if(tokens[0]=="drop") //DROP TABLE table_name;
            {
                db.dropTable(token[2]);
            }
            else if(tokens[0]=="insert")//INSERT INTO table_name VALUES ( val1, val2, … );
            {
                ///here token[0] = insert, token[1] = into, token[2] = table_name, token[3] = (values).
                db.insertValue(token[2], token[3]);


            }
            else if(tokens[0]=="alter")
            {

            }
        }

        file.close();

}


int main()
{




    return 0;
}
