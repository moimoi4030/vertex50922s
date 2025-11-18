#pragma once 

namespace Ramsete {
    extern const double b;
    extern const double zeta;   
    extern const double wheelRadius;  
    extern const double wheelBase;

    struct Pose {
        double x, y, thetaDeg;
    };
    struct TrajectoryPoint {
        double x, y, thetaDeg;   // degrees
        double linear;           // velocity (in/s)
        double angularDeg;       // omega (deg/s)
    };

    extern Pose current;
    extern TrajectoryPoint target;

    extern double leftPower;
    extern double rightPower;
    double clamp(double val, double minVal, double maxVal);
    double normalizeAngleDeg(double a);
    double sinDeg(double deg);
    double cosDeg(double deg);

    void calculateControl(double& v, double& omegaDeg);
    void RamseteTask();
    void setPose(double x, double y, double thetaDeg);
}