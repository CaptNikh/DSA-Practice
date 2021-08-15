// Input:
// N = 3
// Output:
// move disk 1 from rod 1 to rod 3
// move disk 2 from rod 1 to rod 2
// move disk 1 from rod 3 to rod 2
// move disk 3 from rod 1 to rod 3
// move disk 1 from rod 2 to rod 1
// move disk 2 from rod 2 to rod 3
// move disk 1 from rod 1 to rod 3
// 7
// Explanation: For N=3 , steps will be
// as follows in the example and total
// 7 steps will be taken.



class Solution{
    public:
    
        long long toh(int N, int from, int to, int aux) {
          
        if(N==1){
        cout<<"move disk "<<N<<" from rod "<<from<<" to rod "<<to<<"\n";
        return pow(2,N)-1;}
        
        toh(N-1,from,aux,to);
        cout<<"move disk "<<N<<" from rod "<<from<<" to rod "<<to<<"\n";
        toh(N-1,aux,to,from)+1;
        
        return pow(2,N) -1 ;
    }

};
