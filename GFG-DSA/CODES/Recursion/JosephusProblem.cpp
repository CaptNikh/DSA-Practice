Given the total number of persons n and a number k which indicates that k-1 persons are skipped and kth person is killed in circle in a fixed direction.
The task is to choose the safe place in the circle so that when you perform these operations starting from 1st place in the circle, you are the last one remaining and survive.

Example 1:

Input:
n = 3 k = 2
Output: 3
Explanation: There are 3 persons so 
skipping 1 person i.e 1st person 2nd 
person will be killed. Thus the safe 
position is 3.
  
  
int myJosephus(int n, int k)
{
   if(n==1)
   return 0;
   
   return (myJosephus(n-1,k) + k)%n;
}
int josephus(int n,int k)
{
    return myJosephus(n,k)+1;
}
