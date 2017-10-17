#include "QuickBug.h"

/*
  Look at QuickBug.h and then complete the implementation.
*/

void QuickBug::move(int dx){
   Bug::move(2*dx);
}



Bug.cpp

#include "Bug.h"

Bug::Bug()
{
   x = 0;
}

int Bug::getPosition() const
{
   return x;
}

void Bug::move(int amount)
{
   x = x + amount;
}
Bug.h

#ifndef BUG_H
#define BUG_H
/**
   A bug that lives on a line and occupies integer positions.
*/
class Bug
{
public:
   /**
      Constructs a bug with position zero.
   */
   Bug();

   /**
      Gets the position of this bug.
      
      @return the position
   */
   virtual int getPosition() const;

   /**
      Moves this bug by a given amount.
      @param amount the amount to move by
   */
   virtual void move(int amount);
      
private:
   int x;   
};
#endif
QuickBug.h

#ifndef QUICKBUG_H
#define QUICKBUG_H
#include "Bug.h"

/**
   A QuickBug moves twice as fast as a regular Bug. 
*/
class QuickBug : public Bug
{
 public:
   virtual void move(int dx);
};
#endif
