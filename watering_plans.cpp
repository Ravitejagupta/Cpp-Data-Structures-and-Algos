# Assignment 1 - Watering Plans.

/***** #includes here. *****/
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

/***** Define constants here. *****/

const int UNITS_PER_CAN = 3;

   int plant_count;            // count of plants
   int plant_number;           // plant #1, #2, #3, ...
   int unwatered_count;        // count of unwatered plants
   int water_amount;           // amount of water in the watering can
   int steps;                  // number of steps taken
   int cum_steps;              // cumulative number of steps taken for a plan
   int cum_step_units_near;    // cumulative step-units for Plan Near
   int cum_step_units_far;     // cumulative step-units for Plan Far
   bool trip_done;             // true if a trip is done
   
   const string INPUT_FILE_NAME = "counts.txt";


/***** Declare functions here. *****/

int cumulative_step_unit_near(int plant_count);
int cumulative_step_unit_far(int plant_count);


/**
 * The main. For each count of plants, simulate Plan Near and Plan Far,
 * and decide which plan was better.
 */
 
int main()
{
    /***** Complete this main. *****/
    
   ifstream input;
   input.open(INPUT_FILE_NAME);
   if (input.fail())
   {
     cout << "Failed to open " << INPUT_FILE_NAME << endl;
     return -1;
   }

   do
   {
      input >> plant_count;
      /* return zero and end the program if plant count is invalid number*/
      if (plant_count <= 0) return 0;
      
      /*Calculate cumulative step units for both near and far*/
      int cumulative_step_units_near = cumulative_step_unit_near(plant_count);
      int cumulative_step_units_far = cumulative_step_unit_far(plant_count);
      
      /*Compare and display the results */
      
      if (cumulative_step_units_far < cumulative_step_units_near){
         cout<<endl;
         cout<<"*** With "<<plant_count<<" plants, Plan far is better with "<<cumulative_step_units_near - cumulative_step_units_far <<" fewer step-units."<<endl;
      }
      
      else if (cumulative_step_units_far > cumulative_step_units_near){
         cout<<endl;
         cout<<"*** With "<<plant_count<<" plants, Plan near is better with "<<cumulative_step_units_far - cumulative_step_units_near <<" fewer step-units."<<endl;
      }
      
      else{
         cout<<endl;
         cout<<"*** With "<<plant_count<<" plants, Both require same effort"<<endl;
      }
   }while (plant_count > 0);
   
   return 0;
}

/***** Define functions here. *****/

int cumulative_step_unit_near(int plant_count){
   
   cout << endl;
	cout << "==========================" << endl;
	cout << " Plan Near with " << plant_count << " plants" << endl;
	cout << "==========================" << endl;
	cout << endl;
	cout << "Where      Cum. steps  Water amt.  Cum. step-units" << endl;
	cout << "---------  ----------  ----------  ---------------" << endl;
	
	unwatered_count = plant_count;
   cum_steps = 0;
   cum_step_units_near = 0;
   
   
   
   // Loop once per trip from the faucet until all the plants are watered.
   // During each loop, fill the can, water plants according to plan,
   // and return to the faucet.
   
   while (unwatered_count > 0){
      // Walk to the Nearest unwatered plant with a full can.
      water_amount = UNITS_PER_CAN;
      
      plant_number = plant_count - unwatered_count + 1;
      steps = plant_number;
      cum_steps += steps;
      cum_step_units_near += steps*water_amount;

      // Water plants while walking back towards the faucet.
      // Loop once per plant until either the can is empty
      // or all the plants have been watered.
      // During each loop, water one plant.
   do
   {
      cout << "Plant " << setw(2) << plant_number
      << setw(9)  << cum_steps
      << setw(11) << water_amount
      << setw(16) << cum_step_units_near << endl;

      water_amount--;
      unwatered_count--;
      trip_done = (water_amount == 0) || (unwatered_count == 0);
      
      if (!trip_done)
      {
         // Walk towards the faucet to the next unwatered plant.
         plant_number++;
         cum_steps++;
         cum_step_units_near += water_amount;
      }
   } while (!trip_done);
   
   // Walk back to the faucet with an empty or partially filled can.
   steps = plant_number;
   cum_steps += steps;
   cum_step_units_near += steps*water_amount;

   cout << "FAUCET "
   << setw(10) << cum_steps
   << setw(11) << water_amount
   << setw(16) << cum_step_units_near << endl;
   }
   cout<<endl;
   cout<<"Plan Near: Total steps = "<< cum_steps<<", Total step-units = "<<cum_step_units_near<<endl;
   
   return cum_step_units_near;
}

int cumulative_step_unit_far(int plant_count){
   
   cout << endl;
	cout << "==========================" << endl;
	cout << " Plan Far with " << plant_count << " plants" << endl;
	cout << "==========================" << endl;
	cout << endl;
	cout << "Where      Cum. steps  Water amt.  Cum. step-units" << endl;
	cout << "---------  ----------  ----------  ---------------" << endl;
	
	unwatered_count = plant_count;
   cum_steps = 0;
   cum_step_units_far = 0;
   
   
   // Loop once per trip from the faucet until all the plants are watered.
   // During each loop, fill the can, water plants according to plan,
   // and return to the faucet.
   
   while (unwatered_count > 0){
      // Walk to the farthest unwatered plant with a full can.
      water_amount = UNITS_PER_CAN;
      plant_number = unwatered_count;
      steps = plant_number;
      cum_steps += steps;
      cum_step_units_far += steps*water_amount;

      // Water plants while walking back towards the faucet.
      // Loop once per plant until either the can is empty
      // or all the plants have been watered.
      // During each loop, water one plant.
   do
   {
      cout << "Plant " << setw(2) << plant_number
      << setw(9)  << cum_steps
      << setw(11) << water_amount
      << setw(16) << cum_step_units_far << endl;

      water_amount--;
      unwatered_count--;
      trip_done = (water_amount == 0) || (unwatered_count == 0);
      
      if (!trip_done)
      {
         // Walk towards the faucet to the next unwatered plant.
         plant_number--;
         cum_steps++;
         cum_step_units_far += water_amount;
      }
   } while (!trip_done);
   
   // Walk back to the faucet with an empty or partially filled can.
   steps = plant_number;
   cum_steps += steps;
   cum_step_units_far += steps*water_amount;

   cout << "FAUCET "
   << setw(10) << cum_steps
   << setw(11) << water_amount
   << setw(16) << cum_step_units_far << endl;
   }
   cout<<endl;
   cout<<"Plan Far: Total steps = "<< cum_steps<<", Total step-units = "<<cum_step_units_far<<endl;
   
   return cum_step_units_far;
}
