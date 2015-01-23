#include<iostream>
#include<map>
#include<string>

using namespace std;
int main()
{
  map<string, int> hash;
  //hash["0"] = 0;
  string str;
  int n;
  cin>> n;
  while(n--)
  {
    cin>> str;
    //cout<<hash.end() << " "<<hash.find(str)<<endl;
    if(hash.find(str) == hash.end())
    {
      hash[str] = 0;
      cout<< "OK\n";
    }
    else
    {
      hash[str]++;
      cout<< str << hash[str]<<endl;
    }
    //cout<<endl<<n;
  }

  return 0;
}
