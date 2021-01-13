#include "simulator.h"


float Simulator::GenerateLightIntensity()
{

    return generateRand(5.0f,400.0f);
}

float Simulator::GenerateTemperature()
{
    return generateRand(10.0f,30.0f);
}

float Simulator::GenerateHumidity()
{
    return generateRand(10.0f,25.0f);
}

float Simulator::generateRand(float min, float max)
{
    {
        static bool seedStatus;
        if (!seedStatus)
        {
            qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));
            seedStatus = true;
        }
        if(min>max)
        {
            float temp=min;
            min=max;
            max=temp;
        }

        double diff = fabs(max-min);
        double m1=(double)(qrand()%100)/100;
        double retval=min+m1*diff;
        return retval;
    }
}
