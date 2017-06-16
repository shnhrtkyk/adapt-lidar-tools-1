/*
 * File name: FullWaveformIngestion.cpp
 * Created on: 02-June-2017
 * Author: ravi
 */

#include <iostream>
#include "FullWaveformIngestion.hpp"

//Default constructor
FullWaveformIngestion::FullWaveformIngestion(){
  // enter default values
  sampleUnitsBetAnchorAndTarget = 1000.;
}

/*
* Calculate the actual coordinate
* Could be either actual anchor or actual target for x, y and z
*/
double FullWaveformIngestion::calculateActualCoordinate(double coordinate, 
                              double scaleFactor, double offset){
  double actualCoordinate = (coordinate * scaleFactor) + offset;
  return actualCoordinate;
}

/*
* Calculate the deviation
* Could be for x, y or z
*/
double FullWaveformIngestion::calculateDeviation(double anchor, double target){
  double deviation = (target - anchor)/sampleUnitsBetAnchorAndTarget;
  return deviation;
}

/*
* Calculate the return location
* Could be for x, y or z
*/
double FullWaveformIngestion::calculateReturnLocation(double actualAnchor, 
                              double deviation, double time){
  double returnLocation = actualAnchor + (time * deviation);
  return returnLocation;
}