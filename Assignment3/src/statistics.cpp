//--- 2021-2022 Summer Object Oriented Programing Assignment 3 ---//
//--------------------------//
//---Name & Surname: Berat Dalsuna
//---Student Number: 150200002
//--------------------------//

//-------------Do Not Add New Libraries-------------//
//-------------All Libraries Needed Were Given-------------//

#include "statistics.h"
#include <random>
#include <iostream>

using namespace std;

// Methods for Statistical Distribution

double StatisticalDistribution::getMean() const{
    return mean;
}

void StatisticalDistribution::setMean(double d){
    mean = d;
}


vector<double> StatisticalDistribution::calculate_confidence_interval(vector<double> sample,int n,double t){
    vector<double> v;
    double deviation = 0;
    double sum = 0; // sum of (x-xi)^2
    double smean = 0; // sample mean

    for(auto i:sample){
        smean += i;
    }
    smean /= n;

    for(auto i:sample){
        sum += ((smean-i)*(smean-i));
    }
    sum /= (n-1);

    deviation = sqrt(sum);

    v.push_back(smean-t*deviation/sqrt(n));
    v.push_back(smean);
    v.push_back(smean+t*deviation/sqrt(n));

    return v;
}

// Methods for Normal Distribution

NormalDistribution::NormalDistribution(){
    setMean(0.0);
    stddev = 1.0;
}

vector<double> NormalDistribution::sample(int sample_size,int seed_val){
    vector<double> v;
    default_random_engine generator;
    generator.seed(seed_val);
    normal_distribution<double> distribution(getMean(),stddev);
    for(int i=0;i<sample_size;i++){
        double number = distribution(generator);
        v.push_back(number);
        seed_val++;
    }
    return v;
}

// Methods for Uniform Distribution

UniformDistribution::UniformDistribution(){
    setMean(0.0);
    a = -1.0;
    b = 1.0;
}

vector<double> UniformDistribution::sample(int sample_size,int seed_val){
    vector<double> v;
    default_random_engine generator;
    generator.seed(seed_val);
    uniform_real_distribution<double> distribution(a,b);
    for(int i=0;i<sample_size;i++){
        double number = distribution(generator);
        v.push_back(number);
        seed_val++;

    }
    return v;   
}

// Methods for Exponential Distribution

ExponentialDistribution::ExponentialDistribution(){
    setMean(1.0);
    lambda = 1.0;
}

vector<double> ExponentialDistribution::sample(int sample_size,int seed_val){
    vector<double> v;
    default_random_engine generator;
    generator.seed(seed_val);
    exponential_distribution<double> distribution(lambda);
    for(int i=0;i<sample_size;i++){
        double number = distribution(generator);
        v.push_back(number);
        seed_val++;
    }
    return v;   
}