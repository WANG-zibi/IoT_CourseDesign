#ifndef SIMULATOR_H
#define SIMULATOR_H
#include <QtGlobal>
#include <QTime>
#include <cmath>
class Simulator
{
public:
    Simulator();
    static float GenerateLightIntensity();
    static float GenerateTemperature();
    static float GenerateHumidity();
    //生成随机数
    static float generateRand(float min, float max);



};

#endif // SIMULATOR_H
