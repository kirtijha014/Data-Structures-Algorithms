#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>
using namespace std;
int main()
{
    unordered_map<string,int>map;
    map["abc"] = 1;
    map["abc2"] = 2;
    map["abc3"] = 3;
    map["abc4"] = 4;
    map["abc5"] = 5;
    map["abc6"] = 6;
    unordered_map<string,int>::iterator it;
    it = map.begin();
    while(it != map.end()){
        cout << "Key : "  << it->first << "  Value : " << it->second;
        cout<<endl;
        it++;
    
    }
    //Some functions return iterator as the result 
    //Find
    vector<int>v;
    v.push_back(7);
    v.push_back(8);
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    vector<int>::iterator it1;
    it1 =  v.begin();
    while(it1 != v.end())
    {
        cout << *it1 << endl;
        it++;

    }


}