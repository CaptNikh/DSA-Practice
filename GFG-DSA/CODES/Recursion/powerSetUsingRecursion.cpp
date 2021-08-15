void subsets(string s,string curr,int i,vector<string> &arr)
{
    if(i==s.length())
    {
    arr.push_back(curr);
    return;
    }
    subsets(s,curr,i+1,arr);
    subsets(s,curr+s[i],i+1,arr);
}
vector <string> powerSet(string s)
{
    vector<string> arr;
    subsets(s,"",0,arr);
    return arr;
}
