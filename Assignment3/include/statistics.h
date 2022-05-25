//--- 2021-2022 Summer Object Oriented Programing Assignment 3 ---//
//--------------------------//
//---Name & Surname: Berat Dalsuna
//---Student Number: 150200002
//--------------------------//

#ifndef __STATISTICS_H
#define __STATISTICS_H

//-------------Do Not Add New Libraries-------------//
//-------------All Libraries Needed Were Given-------------//

#include <vector>

using namespace std;

class StatisticalDistribution {
    private:
        double mean;
    public:
        double getMean() const;
        void setMean(double);
        virtual vector<double> sample(int, int) = 0;
        vector<double> calculate_confidence_interval(vector<double>,int,double);
};

class NormalDistribution: public StatisticalDistribution {
    private:
        double stddev;
    public:
        NormalDistribution();
        vector<double> sample(int, int);
};

class UniformDistribution: public StatisticalDistribution {
    private:
        double a;
        double b;
    public:
        UniformDistribution();
        vector<double> sample(int, int);
};

class ExponentialDistribution: public StatisticalDistribution {
    private:
        double lambda;
    public:
        ExponentialDistribution();
        vector<double> sample(int, int);
};

#endif