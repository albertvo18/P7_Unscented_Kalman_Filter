#include <iostream>
#include "tools.h"

using Eigen::VectorXd;
using Eigen::MatrixXd;
using std::vector;

Tools::Tools() {}

Tools::~Tools() {}

VectorXd Tools::CalculateRMSE(const vector<VectorXd> &estimations,
                              const vector<VectorXd> &ground_truth) {
  /**
  TODO:
    * Calculate the RMSE here.
  */
  // initialize rmse matrix
  VectorXd rmse(4);
  rmse << 0,0,0,0;

  // current timestep t
  float t = estimations.size();
  if( t == 0){
    cout << "ERROR: CalculateRMSE(): t = estimations.size() == 0 " << endl;
    return rmse;
  }

  if(ground_truth.size() == 0){
    cout << "ERROR: CalculateRMSE():  ground_truth.size() == 0" << endl;
    return rmse;
  }

  // Make sure estimations t and ground_truth vectors have same size
  if(t != ground_truth.size()){
    cout << "ERROR: CalculateRMSE (): estimations t and ground_truth vectors must have the same size." << endl;
    return rmse;
  }

  // iterate through estimations and calculate diff between estimations and ground_truth
  for(unsigned int i=0; i < estimations.size(); ++i){
    VectorXd diff = estimations[i] - ground_truth[i];
    diff = diff.array()*diff.array();
    rmse += diff;
  }

  // Calculate RMSE
  rmse = rmse / t;
  rmse = rmse.array().sqrt();
  return rmse;
}
