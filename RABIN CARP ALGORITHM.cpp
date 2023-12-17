//PROGRAM TO EXECUTE RABIN KARP ALGORITHM USING C++

#include<stdio.h>
#include<string.h>
#include<iostream>
#include<vector>
#include<fstream>
#include<string>
using namespace std;

//d : TOTAL NUMBER OF CHARACTERS
#define d 256

/*
    pat : PATTERN
    txt : TEXT
    q   : A PRIME NUMBER
*/

//FUNCTION TO GET INPUT STRING

void get_input(vector<char>& a)
{
    char c;
    while (1)
    {
        c = getchar();
        if (c == '\n')
        break;
        a.push_back(c);
    }
    return;
}


//FUNCTION FOR PATTERN SEARCHING

int search(char *pat, char *txt, int q)
{
    int M = strlen(pat);
    int N = strlen(txt);
    int i, j;
    int p = 0;  // HASH VALUE FOR PATTERN
    int t = 0; // HASH VALUE FOR TEXT
    int h = 1;

    //THE VALUE OF h WOULD BE "pow(d, M-1)%q"
    for (i = 0; i < M-1; i++)
        h = (h*d)%q;

    // CALCULATE THE HASH VALUE OF PATTERN AND FIRST WINDOW OF THE TEXT
    for (i = 0; i < M; i++)
    {
        p = (d * p + pat[i]) % q;
        t = (d * t + txt[i]) % q;
    }

    // SLIDE THE PATTERN OVER TEXT ONE BY ONE
    for (i = 0; i <= N - M; i++)
    {

        // CHECK THE HASH VALUES OF CURRENT WINDOW OF TEXT AND PATTERN
        // IF THE HASH VALUES MATCH THEN ONLY CHECK FOR CHARACTERS ONE BY ONE
        if ( p == t )
        {
            //CHECK FOR CHARACTERS ONE BY ONE
            for (j = 0; j < M; j++)
            {
                if (txt[i + j] != pat[j])
                    break;
            }
            if (j == M)  // IF p == t AND pat[0...M-1] = txt[i, i+1, ...i+M-1]
            {
                printf("PATTERN FOUND AT INDEX %d \n", i);
                return 0;
            }


        }

        // CALCULATE HASH VALUE FOR NEXT WINDOW OF TEXT: REMOVE LEADING DIGIT,ADD TRAILING DIGIT
        if ( i < N - M )
        {
            t = (d * (t - txt[i] * h) + txt[i + M]) % q;

            // WE MAY GET NEGATIVE VALUE FOR t CONVERT IT INTO POSITIVE VALUE
            if (t < 0)
                t = (t + q);
        }

    }

    cout<<endl;
    return 1;

}

int isPrime(int n)
{
                if(n<=1)
                {
                                return 1;
                }
                for(int i=2;i<n;i++)
                {
                                if(n%i==0)
                                {
                                                return 1;
                                }
                }
                cout<<endl;
                return 0;
}
int patternCheck(string h)
{
                int l=h.length();
                for(int i=0;i<l;i++)
                {
                                if(h[i]>=60 && h[i]<=90)
                                {
                                                continue;
                                }
                                else
                                {
                                                return 0;
                                }
                }
                return 1;
}
//MAIN FUNCTION

int main()
{
                //CREATING VECTORS FOR TEXT AND PATTERN
                string temp;
                cout<<"\t\t\t\t\t\t DNA PATTERN MATCHING"<<endl;
                cout<<"\t\t\t\t\t\t***********************"<<endl;
                cout<<"ENTER THE DNA PATTERN TO BE SEARCHED:"<<endl;
                R2 : cin>>temp;
                int plen=temp.length();
                if(!patternCheck(temp))
                {
                                cout<<"THE PATTERN CONTAINS NON CAPITAL ALPHABETS.PLEASE RE-ENTER : " ;
                                goto R2;
                }
                vector<char> pat(temp.begin(),temp.end());
                cout<<endl<<endl;

                char *text,*pattern;
                pattern=&pat[0];
                pattern[pat.size()]='\0';

                int q,checkp;
                cout<<"ENTER ANY PRIME NUMBER (FOR FINDING HASH VALUE):"<<endl;
                l1: cin>>q;
                checkp=isPrime(q);
                if(checkp !=0)
                {
                                cout<<"ENTERED NUMBER IS NOT PRIME!!! RE-ENTER A PRIME NUMBER!"<<endl;
                                goto l1;
                }
                cout<<endl<<endl;
                int chromo;
                cout<<"ENTER THE CHROMOSOME NUMBER IN WHICH YOU WANT TO SEARCH : ";;
                l2:cin>>chromo;

                if(chromo <= 0 || chromo >21)
                {
                                cout<<"ENTER A VALID CHROMOSOME NUMBER!!!!"<<endl<<endl;
                                goto l2;
                }
                int check=1;
                switch(chromo)
                {
                                case 1:{
                                                ifstream fin;
                                                fin.open("CHROMOSOME 1.txt",ios::in);
                                                if(!fin)
                                                {
                                                                cout<<"FILE NOT FOUND"<<endl;
                                                }
                                                else
                                                {
                                                                while(!fin.eof())
                                                                {
                                                                                string tp;
                                                                                getline(fin,tp);
                                                                                vector<char> txt(tp.begin(),tp.end());
                                                                                text=&txt[0];
                                                                                text[txt.size()]='\0';
                                                                                check = search(pattern, text, q);
                                                                                if(check==0)
                                                                                {
                                                                                                break;
                                                                                }
                                                                }
                                                                if(check!=0)
                                                                {
                                                                                cout<<"THE ENTERED PATTERN DOESN'T MATCH WITH ANY DNA SEQUENCE OF CHROMOSOME "<<chromo<<". THE ENTERED SEQUENCE MAYBE A MUTATED SEQUENCE"<<endl;
                                                                }
                                                                fin.close();
                                                }
                                                break;
                                }
                                case 2:{
                                                ifstream fin;
                                                fin.open("CHROMOSOME 2.txt",ios::in);
                                                if(!fin)
                                                {
                                                                cout<<"FILE NOT FOUND"<<endl;
                                                }
                                                else
                                                {
                                                                while(!fin.eof())
                                                                {
                                                                                string tp;
                                                                                getline(fin,tp);
                                                                                vector<char> txt(tp.begin(),tp.end());
                                                                                text=&txt[0];
                                                                                text[txt.size()]='\0';
                                                                                check = search(pattern, text, q);
                                                                                if(check==0)
                                                                                {
                                                                                                break;
                                                                                }
                                                                }
                                                                if(check!=0)
                                                                {
                                                                                cout<<"THE ENTERED PATTERN DOESN'T MATCH WITH ANY DNA SEQUENCE OF CHROMOSOME "<<chromo<<".THE ENTERED SEQUENCE MAYBE A MUTATED SEQUENCE"<<endl;
                                                                }
                                                                fin.close();
                                                }
                                                break;
                                }
                                case 3:{
                                                ifstream fin;
                                                fin.open("CHROMOSOME 3.txt",ios::in);
                                                if(!fin)
                                                {
                                                                cout<<"FILE NOT FOUND"<<endl;
                                                }
                                                else
                                                {
                                                                while(!fin.eof())
                                                                {
                                                                                string tp;
                                                                                getline(fin,tp);
                                                                                vector<char> txt(tp.begin(),tp.end());
                                                                                text=&txt[0];
                                                                                text[txt.size()]='\0';
                                                                                check = search(pattern, text, q);
                                                                                if(check==0)
                                                                                {
                                                                                                break;
                                                                                }
                                                                }
                                                                if(check!=0)
                                                                {
                                                                                cout<<"THE ENTERED PATTERN DOESN'T MATCH WITH ANY DNA SEQUENCE OF CHROMOSOME "<<chromo<<".THE ENTERED SEQUENCE MAYBE A MUTATED SEQUENCE"<<endl;
                                                                }
                                                                fin.close();
                                                }
                                                break;
                                }
                                case 4:{
                                                ifstream fin;
                                                fin.open("CHROMOSOME 4.txt",ios::in);
                                                if(!fin)
                                                {
                                                                cout<<"FILE NOT FOUND"<<endl;
                                                }
                                                else
                                                {
                                                                while(!fin.eof())
                                                                {
                                                                                string tp;
                                                                                getline(fin,tp);
                                                                                vector<char> txt(tp.begin(),tp.end());
                                                                                text=&txt[0];
                                                                                text[txt.size()]='\0';
                                                                                check = search(pattern, text, q);
                                                                                if(check==0)
                                                                                {
                                                                                                break;
                                                                                }
                                                                }
                                                                if(check!=0)
                                                                {
                                                                                cout<<"THE ENTERED PATTERN DOESN'T MATCH WITH ANY DNA SEQUENCE OF CHROMOSOME "<<chromo<<".THE ENTERED SEQUENCE MAYBE A MUTATED SEQUENCE"<<endl;
                                                                }
                                                                fin.close();
                                                }
                                                break;
                                }
                                case 5:{
                                                ifstream fin;
                                                fin.open("CHROMOSOME 5.txt",ios::in);
                                                if(!fin)
                                                {
                                                                cout<<"FILE NOT FOUND"<<endl;
                                                }
                                                else
                                                {
                                                                while(!fin.eof())
                                                                {
                                                                                string tp;
                                                                                getline(fin,tp);
                                                                                vector<char> txt(tp.begin(),tp.end());
                                                                                text=&txt[0];
                                                                                text[txt.size()]='\0';
                                                                                check = search(pattern, text, q);
                                                                                if(check==0)
                                                                                {
                                                                                                break;
                                                                                }
                                                                }
                                                                if(check!=0)
                                                                {
                                                                                cout<<"THE ENTERED PATTERN DOESN'T MATCH WITH ANY DNA SEQUENCE OF CHROMOSOME "<<chromo<<".THE ENTERED SEQUENCE MAYBE A MUTATED SEQUENCE"<<endl;
                                                                }
                                                                fin.close();
                                                }
                                                break;
                                }
                                case 6:{
                                                ifstream fin;
                                                fin.open("CHROMOSOME 6.txt",ios::in);
                                                if(!fin)
                                                {
                                                                cout<<"FILE NOT FOUND"<<endl;
                                                }
                                                else
                                                {
                                                                while(!fin.eof())
                                                                {
                                                                                string tp;
                                                                                getline(fin,tp);
                                                                                vector<char> txt(tp.begin(),tp.end());
                                                                                text=&txt[0];
                                                                                text[txt.size()]='\0';
                                                                                check = search(pattern, text, q);
                                                                                if(check==0)
                                                                                {
                                                                                                break;
                                                                                }
                                                                }
                                                                if(check!=0)
                                                                {
                                                                                cout<<"THE ENTERED PATTERN DOESN'T MATCH WITH ANY DNA SEQUENCE OF CHROMOSOME "<<chromo<<".THE ENTERED SEQUENCE MAYBE A MUTATED SEQUENCE"<<endl;
                                                                }
                                                                fin.close();
                                                }
                                                break;
                                }
                                case 7:{
                                                ifstream fin;
                                                fin.open("CHROMOSOME 7.txt",ios::in);
                                                if(!fin)
                                                {
                                                                cout<<"FILE NOT FOUND"<<endl;
                                                }
                                                else
                                                {
                                                                while(!fin.eof())
                                                                {
                                                                                string tp;
                                                                                getline(fin,tp);
                                                                                vector<char> txt(tp.begin(),tp.end());
                                                                                text=&txt[0];
                                                                                text[txt.size()]='\0';
                                                                                check = search(pattern, text, q);
                                                                                if(check==0)
                                                                                {
                                                                                                break;
                                                                                }
                                                                }
                                                                if(check!=0)
                                                                {
                                                                                cout<<"THE ENTERED PATTERN DOESN'T MATCH WITH ANY DNA SEQUENCE OF CHROMOSOME "<<chromo<<".THE ENTERED SEQUENCE MAYBE A MUTATED SEQUENCE"<<endl;
                                                                }
                                                                fin.close();
                                                }
                                                break;
                                }
                                case 8:{
                                                ifstream fin;
                                                fin.open("CHROMOSOME 8.txt",ios::in);
                                                if(!fin)
                                                {
                                                                cout<<"FILE NOT FOUND"<<endl;
                                                }
                                                else
                                                {
                                                                while(!fin.eof())
                                                                {
                                                                                string tp;
                                                                                getline(fin,tp);
                                                                                vector<char> txt(tp.begin(),tp.end());
                                                                                text=&txt[0];
                                                                                text[txt.size()]='\0';
                                                                                check = search(pattern, text, q);
                                                                                if(check==0)
                                                                                {
                                                                                                break;
                                                                                }
                                                                }
                                                                if(check!=0)
                                                                {
                                                                                cout<<"THE ENTERED PATTERN DOESN'T MATCH WITH ANY DNA SEQUENCE OF CHROMOSOME "<<chromo<<".THE ENTERED SEQUENCE MAYBE A MUTATED SEQUENCE"<<endl;
                                                                }
                                                                fin.close();
                                                }
                                                break;
                                }
                                case 9:{
                                                ifstream fin;
                                                fin.open("CHROMOSOME 9.txt",ios::in);
                                                if(!fin)
                                                {
                                                                cout<<"FILE NOT FOUND"<<endl;
                                                }
                                                else
                                                {
                                                                while(!fin.eof())
                                                                {
                                                                                string tp;
                                                                                getline(fin,tp);
                                                                                vector<char> txt(tp.begin(),tp.end());
                                                                                text=&txt[0];
                                                                                text[txt.size()]='\0';
                                                                                check = search(pattern, text, q);
                                                                                if(check==0)
                                                                                {
                                                                                                break;
                                                                                }
                                                                }
                                                                if(check!=0)
                                                                {
                                                                                cout<<"THE ENTERED PATTERN DOESN'T MATCH WITH ANY DNA SEQUENCE OF CHROMOSOME "<<chromo<<".THE ENTERED SEQUENCE MAYBE A MUTATED SEQUENCE"<<endl;
                                                                }
                                                                fin.close();
                                                }
                                                break;
                                }
                                case 10:{
                                                ifstream fin;
                                                fin.open("CHROMOSOME 10.txt",ios::in);
                                                if(!fin)
                                                {
                                                                cout<<"FILE NOT FOUND"<<endl;
                                                }
                                                else
                                                {
                                                                while(!fin.eof())
                                                                {
                                                                                string tp;
                                                                                getline(fin,tp);
                                                                                vector<char> txt(tp.begin(),tp.end());
                                                                                text=&txt[0];
                                                                                text[txt.size()]='\0';
                                                                                check = search(pattern, text, q);
                                                                                if(check==0)
                                                                                {
                                                                                                break;
                                                                                }
                                                                }
                                                                if(check!=0)
                                                                {
                                                                                cout<<"THE ENTERED PATTERN DOESN'T MATCH WITH ANY DNA SEQUENCE OF CHROMOSOME "<<chromo<<".THE ENTERED SEQUENCE MAYBE A MUTATED SEQUENCE"<<endl;
                                                                }
                                                                fin.close();
                                                }
                                                break;
                                }
                                case 11:{
                                                ifstream fin;
                                                fin.open("CHROMOSOME 11.txt",ios::in);
                                                if(!fin)
                                                {
                                                                cout<<"FILE NOT FOUND"<<endl;
                                                }
                                                else
                                                {
                                                                while(!fin.eof())
                                                                {
                                                                                string tp;
                                                                                getline(fin,tp);
                                                                                vector<char> txt(tp.begin(),tp.end());
                                                                                text=&txt[0];
                                                                                text[txt.size()]='\0';
                                                                                check = search(pattern, text, q);
                                                                                if(check==0)
                                                                                {
                                                                                                break;
                                                                                }
                                                                }
                                                                if(check!=0)
                                                                {
                                                                                cout<<"THE ENTERED PATTERN DOESN'T MATCH WITH ANY DNA SEQUENCE OF CHROMOSOME "<<chromo<<".THE ENTERED SEQUENCE MAYBE A MUTATED SEQUENCE"<<endl;
                                                                }
                                                                fin.close();
                                                }
                                                break;
                                }
                                case 12:{
                                                ifstream fin;
                                                fin.open("CHROMOSOME 12.txt",ios::in);
                                                if(!fin)
                                                {
                                                                cout<<"FILE NOT FOUND"<<endl;
                                                }
                                                else
                                                {
                                                                while(!fin.eof())
                                                                {
                                                                                string tp;
                                                                                getline(fin,tp);
                                                                                vector<char> txt(tp.begin(),tp.end());
                                                                                text=&txt[0];
                                                                                text[txt.size()]='\0';
                                                                                check = search(pattern, text, q);
                                                                                if(check==0)
                                                                                {
                                                                                                break;
                                                                                }
                                                                }
                                                                if(check!=0)
                                                                {
                                                                                cout<<"THE ENTERED PATTERN DOESN'T MATCH WITH ANY DNA SEQUENCE OF CHROMOSOME "<<chromo<<".THE ENTERED SEQUENCE MAYBE A MUTATED SEQUENCE"<<endl;
                                                                }
                                                                fin.close();
                                                }
                                                break;
                                }
                                case 13:{
                                                ifstream fin;
                                                fin.open("CHROMOSOME 13.txt",ios::in);
                                                if(!fin)
                                                {
                                                                cout<<"FILE NOT FOUND"<<endl;
                                                }
                                                else
                                                {
                                                                while(!fin.eof())
                                                                {
                                                                                string tp;
                                                                                getline(fin,tp);
                                                                                vector<char> txt(tp.begin(),tp.end());
                                                                                text=&txt[0];
                                                                                text[txt.size()]='\0';
                                                                                check = search(pattern, text, q);
                                                                                if(check==0)
                                                                                {
                                                                                                break;
                                                                                }
                                                                }
                                                                if(check!=0)
                                                                {
                                                                                cout<<"THE ENTERED PATTERN DOESN'T MATCH WITH ANY DNA SEQUENCE OF CHROMOSOME "<<chromo<<".THE ENTERED SEQUENCE MAYBE A MUTATED SEQUENCE"<<endl;
                                                                }
                                                                fin.close();
                                                }
                                                break;
                                }
                                case 14:{
                                                ifstream fin;
                                                fin.open("CHROMOSOME 14.txt",ios::in);
                                                if(!fin)
                                                {
                                                                cout<<"FILE NOT FOUND"<<endl;
                                                }
                                                else
                                                {
                                                                while(!fin.eof())
                                                                {
                                                                                string tp;
                                                                                getline(fin,tp);
                                                                                vector<char> txt(tp.begin(),tp.end());
                                                                                text=&txt[0];
                                                                                text[txt.size()]='\0';
                                                                                check = search(pattern, text, q);
                                                                                if(check==0)
                                                                                {
                                                                                                break;
                                                                                }
                                                                }
                                                                if(check!=0)
                                                                {
                                                                                cout<<"THE ENTERED PATTERN DOESN'T MATCH WITH ANY DNA SEQUENCE OF CHROMOSOME "<<chromo<<".THE ENTERED SEQUENCE MAYBE A MUTATED SEQUENCE"<<endl;
                                                                }
                                                                fin.close();
                                                }
                                                break;
                                }
                                case 15:{
                                                ifstream fin;
                                                fin.open("CHROMOSOME 15.txt",ios::in);
                                                if(!fin)
                                                {
                                                                cout<<"FILE NOT FOUND"<<endl;
                                                }
                                                else
                                                {
                                                                while(!fin.eof())
                                                                {
                                                                                string tp;
                                                                                getline(fin,tp);
                                                                                vector<char> txt(tp.begin(),tp.end());
                                                                                text=&txt[0];
                                                                                text[txt.size()]='\0';
                                                                                check = search(pattern, text, q);
                                                                                if(check==0)
                                                                                {
                                                                                                break;
                                                                                }
                                                                }
                                                                if(check!=0)
                                                                {
                                                                                cout<<"THE ENTERED PATTERN DOESN'T MATCH WITH ANY DNA SEQUENCE OF CHROMOSOME "<<chromo<<".THE ENTERED SEQUENCE MAYBE A MUTATED SEQUENCE"<<endl;
                                                                }
                                                                fin.close();
                                                }
                                                break;
                                }
                                case 16:{
                                                ifstream fin;
                                                fin.open("CHROMOSOME 16.txt",ios::in);
                                                if(!fin)
                                                {
                                                                cout<<"FILE NOT FOUND"<<endl;
                                                }
                                                else
                                                {
                                                                while(!fin.eof())
                                                                {
                                                                                string tp;
                                                                                getline(fin,tp);
                                                                                vector<char> txt(tp.begin(),tp.end());
                                                                                text=&txt[0];
                                                                                text[txt.size()]='\0';
                                                                                check = search(pattern, text, q);
                                                                                if(check==0)
                                                                                {
                                                                                                break;
                                                                                }
                                                                }
                                                                if(check!=0)
                                                                {
                                                                                cout<<"THE ENTERED PATTERN DOESN'T MATCH WITH ANY DNA SEQUENCE OF CHROMOSOME "<<chromo<<".THE ENTERED SEQUENCE MAYBE A MUTATED SEQUENCE"<<endl;
                                                                }
                                                                fin.close();
                                                }
                                                break;
                                }
                                case 17:{
                                                ifstream fin;
                                                fin.open("CHROMOSOME 17.txt",ios::in);
                                                if(!fin)
                                                {
                                                                cout<<"FILE NOT FOUND"<<endl;
                                                }
                                                else
                                                {
                                                                while(!fin.eof())
                                                                {
                                                                                string tp;
                                                                                getline(fin,tp);
                                                                                vector<char> txt(tp.begin(),tp.end());
                                                                                text=&txt[0];
                                                                                text[txt.size()]='\0';
                                                                                check = search(pattern, text, q);
                                                                                if(check==0)
                                                                                {
                                                                                                break;
                                                                                }
                                                                }
                                                                if(check!=0)
                                                                {
                                                                                cout<<"THE ENTERED PATTERN DOESN'T MATCH WITH ANY DNA SEQUENCE OF CHROMOSOME "<<chromo<<".THE ENTERED SEQUENCE MAYBE A MUTATED SEQUENCE"<<endl;
                                                                }
                                                                fin.close();
                                                }
                                                break;
                                }
                                case 18:{
                                                ifstream fin;
                                                fin.open("CHROMOSOME 18.txt",ios::in);
                                                if(!fin)
                                                {
                                                                cout<<"FILE NOT FOUND"<<endl;
                                                }
                                                else
                                                {
                                                                while(!fin.eof())
                                                                {
                                                                                string tp;
                                                                                getline(fin,tp);
                                                                                vector<char> txt(tp.begin(),tp.end());
                                                                                text=&txt[0];
                                                                                text[txt.size()]='\0';
                                                                                check = search(pattern, text, q);
                                                                                if(check==0)
                                                                                {
                                                                                                break;
                                                                                }
                                                                }
                                                                if(check!=0)
                                                                {
                                                                                cout<<"THE ENTERED PATTERN DOESN'T MATCH WITH ANY DNA SEQUENCE OF CHROMOSOME "<<chromo<<".THE ENTERED SEQUENCE MAYBE A MUTATED SEQUENCE"<<endl;
                                                                }
                                                                fin.close();
                                                }
                                                break;
                                }
                                case 19:{
                                                ifstream fin;
                                                fin.open("CHROMOSOME 19.txt",ios::in);
                                                if(!fin)
                                                {
                                                                cout<<"FILE NOT FOUND"<<endl;
                                                }
                                                else
                                                {
                                                                while(!fin.eof())
                                                                {
                                                                                string tp;
                                                                                getline(fin,tp);
                                                                                vector<char> txt(tp.begin(),tp.end());
                                                                                text=&txt[0];
                                                                                text[txt.size()]='\0';
                                                                                check = search(pattern, text, q);
                                                                                if(check==0)
                                                                                {
                                                                                                break;
                                                                                }
                                                                }
                                                                if(check!=0)
                                                                {
                                                                                cout<<"THE ENTERED PATTERN DOESN'T MATCH WITH ANY DNA SEQUENCE OF CHROMOSOME "<<chromo<<".THE ENTERED SEQUENCE MAYBE A MUTATED SEQUENCE"<<endl;
                                                                }
                                                                fin.close();
                                                }
                                                break;
                                }
                                case 20:{
                                                ifstream fin;
                                                fin.open("CHROMOSOME 20.txt",ios::in);
                                                if(!fin)
                                                {
                                                                cout<<"FILE NOT FOUND"<<endl;
                                                }
                                                else
                                                {
                                                                while(!fin.eof())
                                                                {
                                                                                string tp;
                                                                                getline(fin,tp);
                                                                                vector<char> txt(tp.begin(),tp.end());
                                                                                text=&txt[0];
                                                                                text[txt.size()]='\0';
                                                                                check = search(pattern, text, q);
                                                                                if(check==0)
                                                                                {
                                                                                                break;
                                                                                }
                                                                }
                                                                if(check!=0)
                                                                {
                                                                                cout<<"THE ENTERED PATTERN DOESN'T MATCH WITH ANY DNA SEQUENCE OF CHROMOSOME "<<chromo<<".THE ENTERED SEQUENCE MAYBE A MUTATED SEQUENCE"<<endl;
                                                                }
                                                                fin.close();
                                                }
                                                break;
                                }
                                case 21:{
                                                ifstream fin;
                                                fin.open("CHROMOSOME 21.txt",ios::in);
                                                if(!fin)
                                                {
                                                                cout<<"FILE NOT FOUND"<<endl;
                                                }
                                                else
                                                {
                                                                while(!fin.eof())
                                                                {
                                                                                string tp;
                                                                                getline(fin,tp);
                                                                                vector<char> txt(tp.begin(),tp.end());
                                                                                text=&txt[0];
                                                                                text[txt.size()]='\0';
                                                                                check = search(pattern, text, q);
                                                                                if(check==0)
                                                                                {
                                                                                                break;
                                                                                }
                                                                }
                                                                if(check!=0)
                                                                {
                                                                                cout<<"THE ENTERED PATTERN DOESN'T MATCH WITH ANY DNA SEQUENCE OF CHROMOSOME "<<chromo<<".THE ENTERED SEQUENCE MAYBE A MUTATED SEQUENCE"<<endl;
                                                                }
                                                                fin.close();
                                                }
                                                break;
                                }

                    }
                    getchar();
}

