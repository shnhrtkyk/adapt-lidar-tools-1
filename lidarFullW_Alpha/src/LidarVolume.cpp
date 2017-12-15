/*
 * File name: LidarVolume.cpp
 * Created on: 08-November-2017
 * Author: ravi
  * Modified by: Nicholas Chapa
 */

#include "LidarVolume.hpp"
#include <math.h>


//Default constructor
LidarVolume::LidarVolume(){
  //initialize to zero
  pulse_bb_x_min = 0;
  pulse_bb_y_min = 0;
  pulse_bb_z_min = 0;
  pulse_bb_x_max = 0;
  pulse_bb_y_max = 0;
  pulse_bb_z_max = 0;

  pulse_bb_i_min = 0;
  pulse_bb_j_min = 0;
  pulse_bb_k_min = 0;
  pulse_bb_i_max = 0;
  pulse_bb_j_max = 0;
  pulse_bb_k_max = 0;

  pulse_x_extent = 0;
  pulse_y_extent = 0;
  pulse_z_extent = 0;
  
  peaks lvPeaks;
  lvPeaks.time = 0;
  lvPeaks.amp = 0;
  lvPeaks.width = 0;
}

void LidarVolume::calculateBoundingBox(double ld_xMin, double ld_yMin, double ld_zMin, double ld_xMax, double ld_yMax, double ld_zMax){  

  pulse_bb_x_min = ld_xMin;
  pulse_bb_y_min = ld_yMin;
  pulse_bb_z_min = ld_zMin;
  pulse_bb_x_max = ld_xMax;
  pulse_bb_y_max = ld_yMax;
  pulse_bb_z_max = ld_zMax;

  pulse_bb_i_min = (int) floor(pulse_bb_x_min) - 10;
  pulse_bb_j_min = (int) floor(pulse_bb_y_min) - 10;
  pulse_bb_k_min = (int) floor(pulse_bb_z_min) - 10;
  pulse_bb_i_max = (int) ceil(pulse_bb_x_max) + 10;
  pulse_bb_j_max = (int) ceil(pulse_bb_y_max) + 10;
  pulse_bb_k_max = (int) ceil(pulse_bb_z_max) + 10;

  pulse_x_extent = pulse_bb_i_max - pulse_bb_i_min;
  pulse_y_extent = pulse_bb_j_max - pulse_bb_j_min;
  pulse_z_extent = pulse_bb_k_max - pulse_bb_k_min;
}

void LidarVolume::allocateMemory(){
  //TODO: Allocate memory for bounding box data, check with cathie
}

void LidarVolume::addPeaks(struct peaks& peaks) {
  //lvPeaks.time = peaks.time;
  //lvPeaks.amp = peaks.amp;
  //lvPeaks.width = peaks.width;
}

void LidarVolume::addPeaks(double peakTime, double peakAmp, double peakWidth){
  //TODO: Add vector of peaks to lidar volume
  //lvPeaks.time = peakTime;
  //lvPeaks.amp = peakAmp;
  //lvPeaks.width = peakWidth;
}

void LidarVolume::getIndexes(double xPulse, double yPulse, double zPulse){
  int i_pulse = floor(xPulse - pulse_bb_x_min);
  int j_pulse = floor(yPulse - pulse_bb_y_min);
  int k_pulse = floor(zPulse - pulse_bb_z_min);
}

