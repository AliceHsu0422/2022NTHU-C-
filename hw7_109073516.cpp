#include <iostream>
#include <fstream>
#include <stdio.h>
#include <map>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>

#define VERBOSE 0

using namespace std;
void print_word_vector(vector<string> &A,int top);
void process_a_word(string cpp_word, vector<string> &A);
void process_a_line(string cpp_line,vector<string> &A);
int myfunction(string s1,string s2)
{
    return(s1<s2);
}

int main(int argc, char **argv)
{
    if(argc != 2)
    {
        printf("usage:%s<filename>\n",argv[0]);
        exit(-1);
    }
    ifstream InFile(argv[1]);
    if(!InFile)
    {
        printf("can't find %s \n",argv[1]);
        exit(-1);
    }
    string cpp_line;
    int line_count = 0;
    vector<string> A;
    //string p;

    getline(InFile, cpp_line);
    while(!cpp_line.empty())
    {
        if(VERBOSE>0)
        {
            printf("the %d-th line: \n",line_count);
            cout << cpp_line << endl;
        }
        process_a_line(cpp_line,A);
        line_count++;
        getline(InFile, cpp_line);
    }
    cout << "total number of lines:" << line_count << endl;
    sort(A.begin(),A.end(),myfunction);
    print_word_vector(A,1000);


    return 0;
}

void process_a_word(string cpp_word, vector<string> &A)
{
    bool if_exist = false;
    //string p;
    int i;
    for(i=0; i<(int)A.size(); i++)
    {
        if(cpp_word==A[i])
        {
            if_exist = true;
            break;
        }
    }
    if(if_exist==false)
    { // add a new word
        A.push_back(cpp_word);
    }
}


void process_a_line(string cpp_line,vector<string> &A)
{
    char c_line[1000000], *word;
    string cpp_word;
    if(cpp_line == "\n")
    {
        cout<<"An empty line!\n"<<endl;
    }
    strcpy(c_line,cpp_line.c_str());
    word = strtok(c_line,"\r\"-,:;.() ");
    while(word!=0)
    {
        cpp_word = word;
        process_a_word(cpp_word,A);
        word = strtok(NULL,"\r\"-,:;.() ");
    }
}

void print_word_vector(vector<string> &A,int top)
{
    for(int i = 0;i<top && i<(int)A.size();i++)
    {
        printf("the %d-th word is (%s)\n",i+1, A[i].c_str() );
    }
}

