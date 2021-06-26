#include "SmoothRandomGenerator.h"

/**
 * Constructor of the class SmoothRandomGenerator.
 * The constructor initialize all the random values used by the random generator
 * to generate smoother random number.
 * @param float distance Represent the distance between random values for the interpolation, greater the distance is, more precise the random generator will be.
 * @author Matrax
 * @version 1.0
 */
SmoothRandomGenerator::SmoothRandomGenerator(float distance) : m_distance(distance), m_value(0.0f), m_actual(0.0f), m_next(0.0f)
{
    std::srand(std::time(nullptr));
    this->m_actual = static_cast<float>(std::rand()) / static_cast<float>(RAND_MAX);
    this->m_next = static_cast<float>(std::rand()) / static_cast<float>(RAND_MAX);
    this->m_value = this->m_actual;
}

/**
 * Destructor of the SmoothRandomGenerator class.
 * This destructor do nothing.
 * @author Matrax
 * @version 1.0
 */
SmoothRandomGenerator::~SmoothRandomGenerator() {}

/**
 * This method return a random float number generated with interpolation
 * @return float A random float number generated with interpolation.
 * @author Matrax
 * @version 1.0
 */
float SmoothRandomGenerator::random()
{
    if(this->m_actual < this->m_next)
    {
        this->m_value = this->m_value + (this->m_next - this->m_actual) / this->m_distance;
        if(this->m_value >= this->m_next)
        {
                this->m_actual = this->m_next;
                this->m_value = this->m_next;
                this->m_next = static_cast<float>(std::rand()) / static_cast<float>(RAND_MAX);
        }
    } else if(this->m_actual > this->m_next) {

        this->m_value = this->m_value - (this->m_actual - this->m_next) / this->m_distance;
        if(this->m_value <= this->m_next)
        {
                this->m_actual = this->m_next;
                this->m_value = this->m_next;
                this->m_next = static_cast<float>(std::rand()) / static_cast<float>(RAND_MAX);
        }
    }

    return this->m_value;
}
