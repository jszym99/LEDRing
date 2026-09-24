#include <sim.h>
#include <math.h>
#include <util.h>

#include <display.h> // Added for LEDCOUNT, definition should be moved

uint8_t pendulum(double time, double g_angle)
{
    // Constants
    const double g = G;//9.81;
    const double radius = 0.015;
    // const double time = 0.0072;
    // const uint16_t delay = (time - 0.0072) * 1000;
    const double dampening = 1;

    // Variables
    static double alpha = 0 * (M_PI / 180.0);
    // static double alpha = 0;
    // static double omega0 = 0;
    static double omega = 0;
    static double epsilon = 0;
    int16_t angle = 0;

    const uint16_t res = 360/LEDCOUNT;
    // uint16_t led = 0;

    epsilon = - (g / radius * sin(alpha + g_angle)) - dampening * omega;
    omega = omega + epsilon * time;
    alpha = alpha + omega * time;// + (epsilon * time * time) / 2;
    // omega = (alpha - alpha0) / time;

    // alpha0 = alpha;
    // omega0 = omega;

    angle = toDegrees(alpha) - 90 + 2.5;
    angle = angle % 360;
    if(angle < 0)
    {
        angle = 360 + angle;
    }
    return angle/res;
}

uint8_t pendulumSimp(double time, double g_x, double g_y)
{
    static double radius = 0.015;
    static double x[2] = {0.015,0};
    static double v[2] = {0,0};
    double p[2] = {0,0};
    double d[2] = {0,0};
    double d_len = 0;

    int16_t angle = 0;
    const uint16_t res = 360/LEDCOUNT;

    v[0] += g_x * time;
    v[1] += g_y * time;

    p[0] = x[0];
    p[1] = x[1];

    x[0] += v[0]*time;
    x[1] += v[1]*time;

    d[0] = -x[0];
    d[1] = -x[1];

    d_len = sqrt(d[0] * d[0] + d[1] * d[1]);

    x[0] += d[0] * (d_len - radius);
    x[1] += d[1] * (d_len - radius);

    v[0] = (x[0] - p[0])/time;
    v[1] = (x[1] - p[1])/time;

    angle = toDegrees(atan2(x[0],x[1])) + 2.5;
    if(angle < 0)
    {
        angle = 360 + angle;
    }
    angle = angle % 360;
    return angle/res;
}

uint8_t artificialHorizon(int8_t x, int8_t y, int8_t z)
{
    int16_t roll = toDegrees(-atan2(x,y));

    roll = fixAngle(roll);

    return roll/5;
}