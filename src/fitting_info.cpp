/*
 * File Name: fitter_info.cpp
 * Created On: 14 June 2019
 * Author: Aaron Orenstein
*/

#include "FittingInfoDriver.hpp"

int main(int argc, char *argv[]){
    FittingInfoDriver driver;

    //Parse command line arguments and get the input file name
    std::string file_name = driver.parse_args(argc, argv);
    if (file_name == "") return 1;

    std::cout << "\nProcessing  " << file_name << std::endl;

    //set up flightline data
    FlightLineData data;
    data.setFlightLineData(file_name);

    //Get output file names
    std::string name = driver.getTrimmedFileName(file_name);
    std::stringstream one;
    one << name << "_fittingInfo_[" << driver.lowerBound << "," <<
        driver.upperBound << "].csv";
    std::stringstream two;
    two << name << "_fittingInfo_stats.csv";
   
    //Get fitting data and write it to the output file
    driver.writeData(data, one.str(), two.str());

    std::cout << "Done" << std::endl;

    return 0;
}