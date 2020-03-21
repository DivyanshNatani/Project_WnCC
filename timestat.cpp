/*
input expected in different lines
i.e
each input as saperate command
*/
#include<bits/stdc++.h>
using namespace std;

double stod(string s)  //string to double
{

    char c[s.length()];
    for (int i = 0; i < sizeof(c); i++)
    {
        c[i] = s[i];
    }
    return atof(c);
}
double convTime(string s)  //convert to min format(1.25478min) from XmX.XXXs
{
    int len=s.length();
    double sec,mn;
    sec=stod(s.substr(len-6,5));
    mn=stod(s.substr(len-8,1));
    double time=mn+sec/60;
    cout<<"min : "<<mn<<"  sec : "<<sec<<endl;
    return time;
}
string convBackTime(double time)  //convert to XmX.XXXs format from min format
{
    int mn=((int)time);
    time=(time-mn)*60; //time converted to second
    double sec=(int)(time*1000);
    sec/=1000;//precision upto 3 digit
    ostringstream str1,str2;
    str1<<mn;
    str2<<sec;
    string ss=str1.str()+"m";
    ss=ss+str2.str()+"s";
    return ss;

}
double avg(double arr[], int len)  //for calculating avg
{
    double sum=0;
    for(int i=0; i<len; i++)
    {
        sum+=arr[i];
    }
    double avg=sum/len;
    return avg;
}

double stnDev(double arr[], double avg, int len) //for calculation of standard deviation
{
    cout<<"length of arr: "<<len<<endl;
    double sum=0;
    for(int i=0; i<len; i++)
    {
        sum+=pow(arr[i]-avg,2);
    }
    double stnD=sum/len;
    return sqrt(stnD) ;
}



int main()
{
    int n=3;
    double real[n], user[n], sys[n]; //array real, user, sys
//taking all input
    string s;
    for(int i=0; i<n; i++)
    {
        getline(cin, s);
        real[i]=convTime(s) ;
        getline(cin, s);
        user[i]=convTime(s) ;
        getline(cin, s);
        sys[i]=convTime(s) ;
    }
//processing input
    double avgr=avg(real,n), avgu=avg(user,n), avgs=avg(sys,n);
    double stndR=stnDev(real, avgr,n), stndU=stnDev(user, avgu,n) , stndS=stnDev(sys, avgs,n) ;

    int no_runs=0;//for third output and for calculating no of runs
    /*
    calculating no of runs
    and collecting all those runs in array
    */
    vector<int> storeIndex;
    for(int i=0; i<n; i++)
    {

        if(real[i]>(avgr-stndR) && real[i]<(avgr+stndR))
        {
            no_runs++;
            storeIndex.push_back(i); //will store index where it is between avg +/- standard deviation
        }
    }
//output
    cout<<"Number of runs :"<<no_runs<<endl;
    cout<<"Average Time Statistics"<<endl;
    cout<<"real "<<convBackTime(avgr)<<" user "<<convBackTime(avgu)<<" sys "<<convBackTime(avgs)<<endl;
    cout<<"Standard deviation of Time statistics"<<endl;
    cout<<"real "<<convBackTime(stndR)<<" user "<<convBackTime(stndU)<<" sys "<<convBackTime(stndS)<<endl;
    cout<<"No of runs within average-standard deviation to average+standard deviation"<<endl;
    for(int j=0; j<storeIndex.size(); j++)
    {
        cout<<"real "<<convBackTime(real[storeIndex[j]])<<" user "<<convBackTime(user[storeIndex[j]])<<" sys "<<convBackTime(sys[storeIndex[j]])<<endl;
    }

    return 0;

}
