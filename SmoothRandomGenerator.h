#ifndef SMOOTHRANDOMGENERATOR_H
#define SMOOTHRANDOMGENERATOR_H

#include <cstdlib>
#include <ctime>

/**
 * This class create a smooth random number generator
 * using interpolation between random number to generate a smoother random.
 * @brief This class create a smooth random number generator
 * @author Matrax
 * @version 1.0
 */
class SmoothRandomGenerator
{

    private:

        //Attributes
        float m_distance;
        float m_value;
        float m_actual;
        float m_next;

    public:

        //Constructors and destructor
        SmoothRandomGenerator() = delete;
        SmoothRandomGenerator(float distance);
        ~SmoothRandomGenerator();

        //Methods
        float random();

};

#endif
