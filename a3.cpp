#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <locale>
#include "stack.h"
#include <iomanip>
#include<assert.h>

using namespace std;

string result (string s1 , string s2 , string s3) ;
int periority (string star) ;

int main(int argc , char *argv[])
{
    string numbersconc[100] ;
    char y[10] ;
    int b1=0 ; // brace balance
    int b2=0 ; //brace balance
    int nodig=0 ;
    int x =strlen(argv[1]) ;
    if(argc==1)
    {
        double noin ;
        noin=0.00 ;
        cout<<noin ;
        return 0 ;
    }
    if(argv[1][x-1]=='-' || argv[1][x-1]=='+' || argv[1][x-1]=='/' || argv[1][x-1]=='x' || argv[1][x-1]=='(')
    {
        cout<<"Invalid Expression" ;
        return 0 ;
    }
    if(argv[1][0]=='x' || argv[1][0]=='/' || argv[1][0]=='+' || argv[1][0]==')')
    {
        cout<<"Invalid Expression" ;
        return 0 ;
    }
    for(int h=0 ; h<x-1 ; h++)
    {
        if(argv[1][h]=='+' && (argv[1][h+1]=='+' || argv[1][h+1]=='x' || argv[1][h+1]=='/'))
        {
            cout<<"Invalid Expression" ;
            return 0 ;
        }
        if(argv[1][h]=='-' && (argv[1][h+1]=='+' || argv[1][h+1]=='x' || argv[1][h+1]=='/'))
        {
            cout<<"Invalid Expression" ;
            return 0 ;
        }
        if (argv[1][h]=='(' && (argv[1][h+1]=='+' || argv[1][h+1]=='x' || argv[1][h+1]=='/'))
        {
            cout<<"Invalid Expression" ;
            return 0 ;
        }
        if(argv[1][h]=='/' && (argv[1][h+1]=='+' || argv[1][h+1]=='x' || argv[1][h+1]=='/'))
        {
            cout<<"Invalid Expression" ;
            return 0 ;
        }
        if(argv[1][h]=='x' && (argv[1][h+1]=='+' || argv[1][h+1]=='x' || argv[1][h+1]=='/'))
        {
            cout<<"Invalid Expression" ;
            return 0 ;
        }
        if(argv[1][h]==')' && argv[1][h+1]=='(')
        {
            cout<<"Invalid Expression" ;
            return 0 ;
        }
        if(argv[1][h]=='(' && argv[1][h+1]==')')
        {
            cout<<"Invalid Expression" ;
            return 0 ;
        }
    }
    // brace balanced
    for(int e=0 ; e<x ; e++)
    {
        if(argv[1][e]=='(')
            b1++ ;
        if (argv[1][e]==')')
            b2++ ;
        if(argv[1][e]==' ')
        {
            cout<<"Invalid Expression" ;
            return 0 ;
        }
        switch(argv[1][e])
        {
        case '0' :
            break ;
        case '1':
            break ;
        case '3':
            break ;
        case '4':
            break ;
        case '5':
            break ;
        case '2':
            break ;
        case '6':
            break ;
        case '7':
            break ;
        case '8':
            break ;
        case '9':
            break ;
        case '+':
            break ;
        case '-':
            break ;
        case '/':
            break ;
        case 'x':
            break;
        case '(':
            break ;
        case ')' :
            break ;
        default:
            nodig=1 ;

        }
    }
    if(b1!=b2)
    {
        cout<<"Invalid Expression" ;
        return 0 ;
    }
    if(nodig==1)
    {
        cout<<"Invalid Expression" ;
        return 0 ;
    }

    int i  ;
    for (i=0 ; i<x ; i++)
    {
        y[i]=argv[1][i] ;
    }
    y[i]=0 ;
    std :: string t1(y);
    int len=t1.length() ;
    string temp ;
    string temp2 ;
    int findex=0 ;
    int flag=0 ;
    int flag2=0 ;
    // concatenate tenth and hundred numbers
    int j=0 ;
    for (j=0 ; j<len ; j++)
    {
        if(t1[j]!='+' && t1[j]!='-' && t1[j]!='x' && t1[j]!='/' && t1[j]!='(' && t1[j]!=')')
        {
            temp=t1[j] ;
            j++ ;
            flag2=1 ;
            while(t1[j]!='+' && t1[j]!='-' && t1[j]!='x' && t1[j]!='/' && t1[j]!='(' && t1[j]!=')' && j!=len)
            {
                flag=1 ;
                temp=temp+t1[j] ;
                j++ ;
                if(j==len)
                {
                    break ;
                }
            }
        }
        if (flag2==1)
        {
            numbersconc[findex]=temp ;
            j-- ;
        }
        else
        {
            temp2=t1[j] ;
            numbersconc[findex]=temp2 ;

        }
        if (flag==1)
        {

        }
        else
        {

        }
        flag2=0 ;
        flag=0 ;
        findex++ ;
    }
    /*for (int c=0 ; c<findex ; c++)
    {
        cout<<numbersconc[c]<<endl ;
    }*/
    string final2[100] ;
    string ftemp ;
    string ftemp2 ;
    int index0 = 0 ;
    int aindex=0 ;
    for(int c=0 ; c<findex ; c++)
        final2[c]=numbersconc[c] ;
    // concatenate minus in the first of expression
    if (numbersconc[0]=="-" && (numbersconc[1]!="+" && numbersconc[1]!="-" && numbersconc[1]!="(" && numbersconc[1]!=")" && numbersconc[1]!="x" && numbersconc[1]!="/"))
    {
        final2[0]=numbersconc[0]+numbersconc[1] ;
        index0=1 ;
        for(int c=1 ; c<findex ; c++)
            final2[c]=numbersconc[c+1] ;
    }
    // concatenate minus in the middle of expression
    for (int k=0 ; k<findex-index0 ; k++ )
    {
        if((final2[k]=="x" || final2[k]=="/" || final2[k]=="-" || final2[k]=="+" || final2[k]=="(") && (final2[k+1]=="-"))
        {
            final2[k+1]=final2[k+1]+final2[k+2] ;
            for (int z=0 ; k+3+z<findex-index0-aindex ; z++)
            {
                final2[k+2+z]=final2[k+3+z] ;
            }
            aindex++ ;
        }
    }
    final2[findex-index0-aindex]="END" ;
   // cout<<"final2 is"<<endl ;
   /* for(int c=0 ; c<=findex-index0-aindex ; c++)
    {
        cout<<final2[c]<<endl ;
    }*/
    stacklist stnu ;
    stacklist stop ;
    int pi=0 ;
    int first=1 ;
    int empt;
    int second=1 ;
    string pop2 ;
    string pop1 ;
    string popo ;
    string fresult ;
    string toptemp ;
    string brace ;
    int topper ;
    int finalper ;
    while(1)
    {
        if(final2[pi]=="END")
        {
            break ;
        }
        else
        {
            if(final2[pi]!="+" && final2[pi]!="-" && final2[pi]!="x" && final2[pi]!="/" && final2[pi]!="(" && final2[pi]!=")" )
            {
                stnu.push(final2[pi]);
                pi++ ;
            }
            else
            {
                if(first==1)
                {
                    stop.push(final2[pi]);
                    pi++ ;
                    first=0 ;
                    if(final2[0]=="(" && second==1)
                    {
                        first=1 ;
                        second=0 ;
                    }
                    toptemp=stop.top() ;
                }
                else if (final2[pi]=="(")
                {
                    stop.push(final2[pi]);
                    pi++ ;
                    first=1 ;
                }
                else if ((toptemp=="/" || toptemp=="x") && (final2[pi]=="+" || final2[pi]=="-" || final2[pi]=="x" || final2[pi]=="/"))
                {
                    topper=periority(toptemp) ;
                    finalper=periority(final2[pi]) ;
                    while(topper>=finalper)
                    {
                        pop1=stnu.pop();
                        pop2=stnu.pop() ;
                        popo=stop.pop() ;
                        fresult=result(pop1,pop2,popo) ;
                        stnu.push(fresult) ;
                        empt=stop.IsEmpty() ;
                        if(empt==1)
                        {
                            break ;
                        }
                        else
                        {
                            toptemp=stop.top() ;
                            topper=periority(toptemp) ;
                        }
                    }
                    stop.push(final2[pi]) ;
                    pi++ ;
                    toptemp=stop.top() ;
                }
                else if (final2[pi]==")")
                {
                    do{
                        pop1=stnu.pop() ;
                        pop2=stnu.pop() ;
                        popo=stop.pop() ;
                        fresult=result(pop1,pop2,popo) ;
                        stnu.push(fresult) ;
                        toptemp=stop.top() ;
                    }while(toptemp!="(") ;
                    brace=stop.pop() ;
                    empt=stop.IsEmpty() ;
                    if(empt==1)
                    {
                        pi++ ;
                        if(final2[pi]=="END")
                        {
                            break ;
                        }
                        else
                        {
                            stop.push(final2[pi]) ;
                            toptemp=stop.top() ;
                            pi++ ;
                        }
                    }
                    else
                    {
                        toptemp=stop.top() ;
                        pi++ ;
                    }
                }
                else if ((toptemp=="+" || toptemp=="-") && (final2[pi]=="+" || final2[pi]=="-"))
                {
                    topper=periority(toptemp) ;
                    finalper=periority(final2[pi]) ;
                    while(topper>=finalper)
                    {
                        pop1=stnu.pop() ;
                        pop2=stnu.pop() ;
                        popo=stop.pop() ;
                        fresult=result(pop1,pop2,popo) ;
                        stnu.push(fresult) ;
                        empt=stop.IsEmpty() ;
                        if(empt==1)
                        {
                            break ;
                        }
                        else
                        {
                            toptemp=stop.top() ;
                            topper=periority(toptemp) ;
                        }
                    }
                    stop.push(final2[pi]) ;
                    pi++ ;
                    toptemp=stop.top() ;
                }
                else
                {
                    stop.push(final2[pi]) ;
                    toptemp=stop.top() ;
                    pi++ ;
                }
            }
        }
    }
    while(!stop.IsEmpty())
    {
        pop1=stnu.pop() ;
        pop2=stnu.pop() ;
        popo=stop.pop() ;
        fresult=result(pop1,pop2,popo) ;
        stnu.push(fresult) ;
    }
    fresult=stnu.pop() ;
    cout<<fixed<<showpoint<<setprecision(2)<<atof(fresult.c_str())  ;
    return 0;
}
string result(string s1 , string s2 , string s3)
{
    double res ;
    if(s3=="+")
    {
       res=(atof(s2.c_str()))+(atof(s1.c_str())) ;

    }
    else if (s3=="-")
    {
        res=(atof(s2.c_str()))-(atof(s1.c_str())) ;
    }
    else if (s3=="x")
    {
        res=(atof(s2.c_str()))*(atof(s1.c_str())) ;
    }
    else
    {
        //assert(atof(s1.c_str())==0) ;
        if(atof(s1.c_str())==0)
        {
            cout<<"Invalid Expression" ;
            exit(0) ;
        }
        else
        {
            res=(atof(s2.c_str()))/(atof(s1.c_str())) ;
        }
       // res=(atof(s2.c_str()))/(atof(s1.c_str())) ;

    }
    std::ostringstream strd ;
    strd << res ;
    std::string strs = strd.str() ;
    return strs ;
}

int periority(string star)
{
    int f ;
    if(star=="+")
    {
        f=1 ;
    }
    else if (star=="-")
    {
        f=1 ;
    }
    else if (star=="x")
    {
        f=2 ;
    }
    else if (star=="/")
    {
        f=2 ;
    }
    else
    {
        f=0 ;
    }
    return f ;
}
