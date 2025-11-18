#pragma once
#include <cmath>

#define EIGEN_DONT_VECTORIZE
#define EIGEN_DISABLE_UNALIGNED_ARRAY_ASSERT
#include "Eigen/Dense"

// utilities
inline double deg2rad(double deg) {
    return deg * M_PI / 180.0;
}

inline double rad2deg(double rad) {
    return rad * 180.0 / M_PI;
}


class State {
    public:
        double x;
        double y;
        double theta;

        // inital state
        State(double init_x = 0.0, double init_y = 0.0, double init_thetaDeg = 0.0) {
            x = init_x;
            y = init_y;
            theta = deg2rad(init_thetaDeg);
        }
};

class EKF {
    private:
        State robot;
        Eigen::Matrix3d P;
        Eigen::Matrix3d Q;
        Eigen::Matrix3d R;
        double dt;
    
    public:
        EKF(double init_x = 0.0, double init_y = 0.0, double init_theta = 0.0, double timestep = 0.01);
        
        void predict(double v, double w);
        void update(double measured_x, double measured_y, double measured_theta);

        State getState() const {
            State filtered;
            filtered.x = robot.x;
            filtered.y = robot.y;
            filtered.theta = rad2deg(robot.theta);
            return filtered;
        }
};