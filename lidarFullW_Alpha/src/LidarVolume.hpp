/*
 * File name: LidarVolume.cpp
 * Created on: 08-November-2017
 * Author: ravi
 */

#ifndef LIDARVOLUME_HPP_
#define LIDARVOLUME_HPP_

#include <math.h>

#include <iostream>
#include "pulsereader.hpp"
#include "pulsewriter.hpp"

class LidarVolume{

  public:
    //The min and max fields describing the boundary box(bb) that includes the 
    //first & last points of the sampled parts of the returning waveforms of 
    //all pulses
    int pulse_bb_x_min;
    int pulse_bb_y_min;
    int pulse_bb_z_min;
    int pulse_bb_x_max;
    int pulse_bb_y_max;
    int pulse_bb_z_max;

    //floor of the bb_mins
    int i_min;
    int j_min;
    int k_min;
    //ceil of the bb_maxes
    int i_max;
    int j_max;
    int k_max;

    //extent of x, y, and z as calculated from the pulse data (max - min)
    int pulse_x_extent;
    int pulse_y_extent;
    int pulse_z_extent;

    LidarVolume();

    //Read and store the mins and maxes from the header, calculate and store the
    //i, j,k values and the extents
    void calculateBoundingBox(PULSEreader *pReader);
};


#endif /* LIDARVOLUME_HPP_ */

