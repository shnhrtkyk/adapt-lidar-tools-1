// File name: LidarVolume.cpp
// Created on: 08-November-2017
// Author: ravi

#ifndef LIDARVOLUME_HPP_
#define LIDARVOLUME_HPP_

class LidarVolume{

  public:
    //The padded min and max fields describing the bounding box(bb) that 
    //includes the first & last points of the sampled parts of the returning 
    //waveforms of all pulses. 
    double bb_x_min_padded;
    double bb_y_min_padded;
    double bb_z_min_padded;
    double bb_x_max_padded;
    double bb_y_max_padded;
    double bb_z_max_padded;
 
    int bb_i_min;
    int bb_j_min;
    int bb_k_min;
    int bb_i_max;
    int bb_j_max;
    int bb_k_max;

    //extent of x, y, and z as calculated from the pulse data (max - min)
    int i_extent;
    int j_extent;
    int k_extent;
    
    //number of peaks to be saved into 
    int numOfPeaks;
    
    //current position in peaks array
    int currentPeak;    
    
    std::vector<int>* voxel;
    
    LidarVolume();

    //Read and store the mins and maxes from the header, calculate and store the
    //i, j,k values and the extents
    void setBoundingBox(double ld_xMin, double ld_xMax, double ld_yMin,
                              double ld_yMax, double ld_zMin, double ld_zMax);
    void insertPeak();
    void allocateMemory();
    void deallocateMemory();
    int position(int i, int j, int k);
    void gps_to_voxel_x();
    void gps_to_voxel_y();
    void gps_to_voxel_z();

};


#endif /* LIDARVOLUME_HPP_ */

