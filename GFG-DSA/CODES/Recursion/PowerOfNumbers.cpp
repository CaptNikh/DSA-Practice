// Given a number and its reverse. Find that number raised to the power of its own reverse.
// Note: As answers can be very large, print the result modulo 109 + 7.

class Solution{
    public:
    //You need to complete this fucntion
    
    long long power(int N,int R)
    {
       return powerRec(N,R,1e9+7);
    }
    long long powerRec(int A, int B,long long C)
    {
        if(A==0)
         return 0;
        if(B==0)
         return 1;
         
        long long y;
        
        if(B%2==0)
        {
            y=powerRec(A,B/2,C);
            y=(y*y)%C;
        }
        else{
            y=A%C;
            y=(y*powerRec(A,B-1,C))%C;
        }
        return (y+C)%C;
    }

};
