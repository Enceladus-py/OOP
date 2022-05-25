//--- 2021-2022 Summer Object Oriented Programing Assignment 3 ---//
//--------------------------//
//---Name & Surname: Berat Dalsuna
//---Student Number: 150200002
//--------------------------//

//-------------Do Not Add New Libraries-------------//
//-------------All Libraries Needed Were Given-------------//

#include "utils.h"

using namespace std;

StatisticalDistribution* choose_function(int dist_type){

    if (dist_type==0)
        return new NormalDistribution();
    else if(dist_type==1)
        return new UniformDistribution();
    else if(dist_type==2)
        return new ExponentialDistribution();
    else throw "Unidentified distribution function!";
}

double many_trials(StatisticalDistribution* dist,vector<double> x, double t_value, int trials, int sample_size, int seed_val){
    
    int success = 0;
    for(int i=0;i<trials;i++){
        vector<double> v = dist->sample(sample_size, seed_val);
        vector<double> s = dist->calculate_confidence_interval(v, sample_size, t_value);
        if(dist->getMean() >= s[0] && dist->getMean()<=s[2]) // if theoretical mean is in the interval
            success++;
        seed_val++;
    }

    return success/(float)trials;
}