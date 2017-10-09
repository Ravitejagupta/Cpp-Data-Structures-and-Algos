#include <cmath>
#include "Polygon.h"

using namespace std;

Polygon::Polygon()
{
   
}

void Polygon::add(Point p)
{
      points.push_back(p);
}

Point Polygon::get(int i) const
{
 return points[i];  
}

double Polygon::circumference() const
{   
   double result = 0;
   double distance;
   
   for (int i =0;i<points.size();i++){
      if (i == points.size()-1){
         Point p=get(i);
         distance=p.distance(points[0]);
         result=result+distance;
      }
      else{
            Point q=get(i);
            distance=q.distance(points[i+1]);
            result=result+distance;
         }
   }
   
   return result;
}
////////////////////////////////////////////////////////

/*
In the constructor, copy constructor, assignment operator, destructor
print messages "Constructing ...", "Copying ...", "Assigning ... to ...", "Destroying ...", and do what else is necessary. 
 */

#include <iostream>
#include "Trace.h"

using namespace std;
                   
Trace::Trace(string s) 
{ 
	str = s; 
	cout << "Constructing " << s << endl; 
}
	
Trace::Trace(const Trace& other) 
{ 
   str = other.str;

   cout << "Copying  " << other.str << endl;
}

Trace& Trace::operator=(const Trace& other)
{
   
   

   cout << "Assigning  " << other.str  << "  to "<< str <<endl;
   str = other.str;
}

Trace::~Trace()
{
   cout << "Destroying  " << str << endl;
}

//////////////////////////////////////////////

#include <iostream>
#include "Seq.h"

/*
  A Seq is a sequence of Box objects. The constructor Seq(int length)
  constructs a sequence of Box objects of the given length, all 
  constructed with the default constructor. Implement that constructor
  and the "big 3" memory management functions.
*/
  
Seq::Seq(int length)
{
   len = length;
   boxes = new Box[len];
}

Seq::Seq(const Seq& other)
{
   len = other.len;
   boxes = new Box[len];
 
}

Seq& Seq::operator=(const Seq& other)
{
   delete [] boxes;
   len = other.len;
   boxes = new Box[len];
   return *this;
}

Seq::~Seq()
{
 delete [] boxes;
}

///////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

/**
   In this implementation of the Pair class, you will NOT COPY
   Box objects. Instead, when copying Pair objects, copy the pointers
   and increment the refcount of the box whose pointer you copied,
   so that the refcount always tells you how many pointers point
   to it. If the refcount goes to zero, delete the Box object.

   Note that the Pair(int v1, int v2) constructor also shares
   the Box object if v1 equals v2. 
*/

#include "Pair.h"

Pair::Pair(int v1, int v2)
{
   cout<<"Constructing first in parameter constructor"<<endl;
   first = new Box(v1);
   if (v1 == v2){
    cout<<"Assigning second to first in parameter constructor"<<endl;
      second = first;}
   else{
   cout<<"Constructing second in parameter constructor"<<endl;
      second = new Box(v2);}
   first->refcount++;
   second->refcount++;
}
   
Pair::Pair(const Pair& other) : first(other.first), second(other.second)
{
   cout<<"copy constructor called"<<first->refcount<<" "<<endl;
   first->refcount++;
   cout<<"ref value of first in cpy ctr"<<first->refcount<<endl;
   second->refcount++;
   cout<<"ref  value of second in copy ctr"<<second->refcount<<endl;
   
}

Pair& Pair::operator=(const Pair& other)
{
    if(this->first->refcount>1){
         first->refcount--;
      }else{
         delete this->first;
      }
      this->first=other.first;
  
   
   if(other.second != other.first){
      if(this->second->refcount>1){
         second->refcount--;
      }else{
         delete this->second;
      }
      this->second=other.second;
   }
   else{
      if(this->second->refcount>1){
         second->refcount--;
      }else{
         delete this->second;
      }
      this->second=this->first;
   }

return *this;
}


Pair::~Pair()
{
   cout<<"Destructor called"<<endl;
 if(this->first->refcount>=1){
    
    delete this->first;
 }
 if(this->second->refcount>=1){
    
      
       delete this->second;
 }
 
}
