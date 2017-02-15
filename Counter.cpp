//*************************************************************************
//Author Name: Ryan Lockett
//File Name: Counter.cpp
//
//Purpose: This is the Counter class cpp file. This file contains
//		   all functions and constructors
//

//**************************************************************************


#include<iostream>
#include "Counter.h"

//default constructor, set maxCount to 9999, currentCount to 0, and overflow flags to false on creation
Counter::Counter()
{
	maxCount = 9999;
	currentCount = 0;
	isOverflow = false;
	trackOverflowMessage = false;
}

//default constructor, set maxCount to the passed in value, currentCount to 0, and overflow flags to false on creation
Counter::Counter(int newMaxCount)
{
	if(newMaxCount < 0 || newMaxCount > 9999) //if the passed in value isn't within the bounds of 0-9999 default the maxCount to 9999 
	{
		std::cout << "Error, cannot create a max counter that exceeds 99.99. Setting default value to 99.99." << std::endl;
		maxCount = 9999;
		currentCount = 0;
		isOverflow = false;
		trackOverflowMessage = false;
	}
	else
	{
		maxCount = newMaxCount; //set the max count to the passed in value
		currentCount = 0;
		isOverflow = false;
		trackOverflowMessage = false;
	}
}

//member function to increment cents
void Counter::incr1(int incrVal)
{
	currentCount += incrVal; //increment cents by requested value

	//check to see if this pushes the current count over the maximum
	if(currentCount > maxCount)
	{
		if(trackOverflowMessage == false) //only print this once when it first occurs
		{
			std::cout << "The current count has exceeded the maximum. Overflow now exists" << std::endl;
		}
		isOverflow = true;
		trackOverflowMessage = true;
	}
	return;
}

//member function to increment dimes
void Counter::incr10(int incrVal)
{
	currentCount += (incrVal * 10); //increment dimes by requested value

	//check to see if this pushes the current count over the maximum
	if(currentCount > maxCount)
	{
		if(trackOverflowMessage == false) //only print this once when it first occurs
		{
			std::cout << "The current count has exceeded the maximum. Overflow now exists" << std::endl;
		}
		isOverflow = true;
		trackOverflowMessage = true;
	}
	return;
}

//member function to increment dollars
void Counter::incr100(int incrVal)
{
	currentCount += (incrVal * 100); //increment dollars by requested value

	//check to see if this pushes the current count over the maximum
	if(currentCount > maxCount)
	{
		if(trackOverflowMessage == false) //only print this once when it first occurs
		{
			std::cout << "The current count has exceeded the maximum. Overflow now exists" << std::endl;
		}
		isOverflow = true;
		trackOverflowMessage = true;
	}
	return;
}

//member function to increment tens
void Counter::incr1000(int incrVal)
{
	currentCount += (incrVal * 1000); //increment tens by requested value

	//check to see if this pushes the current count over the maximum
	if(currentCount > maxCount)
	{
		if(trackOverflowMessage == false) //only print this once when it first occurs
		{
			std::cout << "The current count has exceeded the maximum. Overflow now exists" << std::endl;
		}
		isOverflow = true;
		trackOverflowMessage = true;
	}
	return;
}

//member function to reset currentCount
void Counter::reset()
{
	currentCount = 0; //reset currentCount
	std::cout << "The total count is now: " << currentCount << std::endl;
	isOverflow = false;
	trackOverflowMessage = false;
	return;
}

//member function to print overflow
void Counter::overFlow()
{
	if(isOverflow == true)
		std::cout << "Overflow exists" << std::endl;
	else
		std::cout << "No Overflow" << std::endl;

	return;
}

//member function to print the current counts
void Counter::printCounter()
{
	std::cout << "$"
		 << (currentCount / 1000) % 10 //print 1000s
		 << (currentCount / 100) % 10 //print 100s
		 << "."
		 << (currentCount / 10) % 10 //print 10s
		 << currentCount % 10 //print 1s
		 << " / "
		 << "$"
		 << (maxCount / 1000) % 10 //print 1000s
		 << (maxCount / 100) % 10 //print 100s
		 << "."
		 << (maxCount / 10) % 10 //print 10s
		 << maxCount % 10 //print 1s
		 << std::endl;

	return;
}