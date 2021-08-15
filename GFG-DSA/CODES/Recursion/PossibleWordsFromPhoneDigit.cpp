class Solution
{
    public:
    void func(string str[],int arr[],int N,string x,vector<string> &s,int i)
    {
        if(i==N)
        {
            s.push_back(x);
            return;
        }
        int a = arr[i];
        string p = str[a];
        for(int j=0;j<p.length();j++)
        {
            func(str,arr,N,x+p[j],s,i+1);
        }
    }
    vector<string> possibleWords(int arr[], int N)
    {
       string str[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
       vector<string> s;
       string x ="";
       func(str,arr,N,x,s,0);
       return s;
    }
    
};
