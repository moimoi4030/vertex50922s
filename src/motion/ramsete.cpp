/*#include "main.h"
#include <cmath>
#include <algorithm>

namespace Ramsete {
    // ==== Constants ====
    const double b = 2.0;                     // Tunable aggressiveness factor (1–3 recommended)
    const double zeta = 0.7;                  // Damping ratio (0.7–1.0 typical)
    const double wheelRadius = 3.25 / 2;          // Wheel radius in inches
    const double wheelBase = 13.0;            // Distance between left/right wheels (inches)
    const double maxPower = 127.0;            // Max motor power

    // ==== Unit Conversion Helpers ====
    inline double toRad(double deg) { return deg * M_PI / 180.0; }   // Degrees → Radians
    inline double toDeg(double rad) { return rad * 180.0 / M_PI; }   // Radians → Degrees

    // Keep an angle in the range [-180°, 180°]
    inline double normalizeAngleDeg(double a) {
        while (a > 180.0) a -= 360.0;
        while (a < -180.0) a += 360.0;
        return a;
    }

    // Global state
    Pose current{0, 0, 0};                     // Current robot pose
    TrajectoryPoint target{0, 0, 0, 0, 0};     // Target pose and velocity

    // safe sinc to avoid dividing by near-zero
    inline double safe_sinc(double x) {
        if (std::abs(x) < 1e-6) return 1.0 - (x * x) / 6.0;
        return std::sin(x) / x;
    }

    // Ramsete control calculation (returns linear velocity and angular velocity in rad/s)
    void calculateControl(double& v, double& omegaRad) {
        double currentThetaRad = toRad(current.thetaDeg);
        double targetThetaRad  = toRad(target.thetaDeg);
        double ethetaRad = targetThetaRad - currentThetaRad;

        while (ethetaRad > M_PI) ethetaRad -= 2 * M_PI;
        while (ethetaRad < -M_PI) ethetaRad += 2 * M_PI;

        double dx = target.x - current.x;
        double dy = target.y - current.y;
        double cosT = cos(currentThetaRad);
        double sinT = sin(currentThetaRad);
        double ex_r =  cosT * dx + sinT * dy;
        double ey_r = -sinT * dx + cosT * dy;

        double v_d = target.linear;
        double w_d = toRad(target.angularDeg);

        double k = 2.0 * zeta * std::sqrt(w_d * w_d + b * v_d * v_d);

        double v_out = v_d * std::cos(ethetaRad) + k * ex_r;
        double omega_out = w_d + b * v_d * safe_sinc(ethetaRad) * ey_r + k * ethetaRad;

        v = v_out;
        omegaRad = omega_out;
    }

    // Wrapper that returns angular velocity in degrees/sec for external callers
    void calculateControlDeg(double& v, double& omegaDeg) {
        double omegaRad;
        calculateControl(v, omegaRad);
        omegaDeg = toDeg(omegaRad);
    }

    // Control loop task
    void RamseteTask() {
        while (true) {
            // Update current robot pose from odometry
            current.x = chassis.getPose().x;
            current.y = chassis.getPose().y;
            current.thetaDeg = chassis.getPose().theta;

            // Compute control outputs
            double v, omegaRad;
            calculateControl(v, omegaRad);

            // Compute wheel angular velocities (rad/s) from linear and angular velocity
            double leftWheelRadPerSec  = (v - omegaRad * (wheelBase / 2.0)) / wheelRadius;
            double rightWheelRadPerSec = (v + omegaRad * (wheelBase / 2.0)) / wheelRadius;

            // Simple scaling from wheel angular velocity -> motor power (tunable)
            const double velocityToPower = 10.0; // tune this to match motor/gearset
            double leftPower  = std::clamp(leftWheelRadPerSec * velocityToPower, -maxPower, maxPower);
            double rightPower = std::clamp(rightWheelRadPerSec * velocityToPower, -maxPower, maxPower);


            // Send power to motor groups
            left.move(leftPower);
            right.move(rightPower);

            static int loopCounter = 0;
            if (++loopCounter % 10 == 0) {
                printf("[Ramsete] pose=(%.2f,%.2f,%.1fdeg) target=(%.2f,%.2f,%.1fdeg) v=%.3f omega=%.3frad/s Lp=%.1f Rp=%.1f\n",
                       current.x, current.y, current.thetaDeg,
                       target.x, target.y, target.thetaDeg,
                       v, omegaRad, leftPower, rightPower);
            }

            pros::delay(10);  // Update rate ~100 Hz
        }
    }

    // ==== Pose Reset Function ====
    void setPose(double x, double y, double thetaDeg) {
        // Reset internal state and external odometry
        current.x = x;
        current.y = y;
        current.thetaDeg = thetaDeg;
        chassis.setPose(x, y, thetaDeg);
    }
}*/

