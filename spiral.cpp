#include <iostream>

using namespace std;



const int MAX_SIZE  = 101;  // maximum size of the square matrix
const int MAX_START = 50;   // maximum starting number
int arr[MAX_SIZE][MAX_SIZE]; // array declaration

/*Declaring Functions */

void do_spiral(const int n, const int start); /*both makes and prints spiral*/

void make_spiral(int arr[MAX_SIZE][MAX_SIZE], const int n, const int start); /* Makes Spiral */

void print_spiral(int arr[MAX_SIZE][MAX_SIZE],const int n); /* Prints Spiral*/


int main()
{
    do_spiral(1, 1);
    do_spiral(5, 1);
    do_spiral(9, 11);
    do_spiral(12, 13);
    do_spiral(15, 17);
}


/***** Complete this program. *****/



void do_spiral(const int n, const int start){

   cout<<"Spiral of Size "<<n<<" starting at "<<start<<endl;

   if (n%2 == 0) {

      cout<<"***** Error: Size "<<n<<" must be odd.";

      cout<<endl;

   }

   else{

   make_spiral(arr, n, start);

   print_spiral(arr, n);

   }

   cout<<endl;

}

void make_spiral(int arr[MAX_SIZE][MAX_SIZE], const int n, const int start){
   
   cout<<endl; 

   int spiral_count = 1; /* Spiral count*/

   int num = start; /* assigning start to variable num */

   int x = n/2; /* x coordinate*/

   int y = n/2; /* y coordinate*/

   arr[x][y] = num; /* assigning middle element of matrix to start*/

   num++;

   while (spiral_count < n && x<=n && y<=n){
      
      /* Assuming variable x and y coordinates as v and w respectively as spiral proceeds */
      
      if(spiral_count%2 == 0){

         for (int w=y-1;w>=y-spiral_count;w--){

            arr[x][w] = num;

            num++;

         }

         y = y - spiral_count;

         for (int v=x+1;v<=x+spiral_count;v++){

            arr[v][y] = num;

            num++;

         }

         x = x + spiral_count;

         spiral_count++;

      }

      else{ 
         
         /* Assuming variable x and y coordinates as v and w respectively as spiral proceeds */

         for (int w=y+1;w<=y+spiral_count;w++){

          arr[x][w] = num;

          num++;

         }

         y = y + spiral_count;

         for (int v=x-1;v>=x-spiral_count;v--){

            arr[v][y] = num;

            num++;  

         }

         x = x - spiral_count;

         spiral_count++;

      }

   }

   for (int last=1;last<n;last++){

      arr[n-1][last] = num;

      num++;

   }
   
}

void print_spiral(int arr [MAX_SIZE][MAX_SIZE],const int n){
   
   for (int row = 0; row < n; row++){

      cout<<" ";

      for (int column = 0; column < n; column++){ 

         if (arr[row][column]<10) cout<<"  ";

         else if (arr[row][column]<100) cout<<" ";

         cout<<arr[row][column]<<" ";

      }

      cout<<endl;

   }
}
