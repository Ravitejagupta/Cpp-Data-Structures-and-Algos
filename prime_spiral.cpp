#include <iostream>
#include <vector>

using namespace std;

const int MAX_START = 50;   // maximum starting number


/***** Complete this program. *****/

void do_diagonal(const int n, const int start);
bool is_prime(int n);

/**
 * The main: Generate and print prime spirals of various sizes.
 */
int main()
{
    do_diagonal(5, 1);
    do_diagonal(25, 11);
    do_diagonal(35, 0);
    do_diagonal(50, 31);
    do_diagonal(101, 41);
}


void do_diagonal(const int n, const int start){
   
   cout<<"Diagonal Matrix of Size "<<n<<" starting at "<<start<<endl;
   if (n%2 == 0) {
      cout<<"***** Error: Size "<<n<<" must be odd."<<endl;
   }
   else if(start > MAX_START || start < 1){
      cout<<"***** Error: Starting value 0 < 1 or > 50"<<endl;
   }
   else{
   vector<vector<int>>arr; //Vector Declaration.
   
   arr.resize(n);
   for (int i = 0; i < n; i++){
    arr[i].resize(n);
   }
   
   int i = 0;
   int num = start;
   
   while(i<n-1){
      for (int j=0;j<=i;j++){
         arr[i-j][j] = num;
         num++;
      }
      i++;
   }
   
   for(int i=0;i<n;i++){
      arr[n-i-1][i] = num;
      num++;
   }
   
   while(i>0){
      for (int j=0;j<i;j++){
         arr[n-1-j][j+n-i] = num;
         num++;
      }
      i--;
   }
   
   cout<<endl;
   for (int i=0;i<n;i++){
      for (int j =0;j<n;j++){
         if(is_prime(arr[i][j])) cout<<"#";
         else cout<<".";
         // cout<<arr[i][j]<<" ";
      }
      cout<<endl;
   }
   }
      cout<<endl;
}

bool is_prime(int n){
   if (n==1) return false;
   if (n==2) return true;
   for (int i=2; i< n*0.5; i++){
      if (n%i == 0) return false;
   }
   return true;
}
