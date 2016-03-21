#ifndef _RUNNER_EXPE
#define _RUNNER_EXPE

#include <string>
#include <set>
#include <map>
#include <vector>
#include <tuple>
#include <chrono>

struct timeperiod
{
    long int start;
    long int stop;
};

struct parameter
{
    std::string name;
    double value;
};

struct Experiment
{
    typedef std::pair<std::string, std::chrono::milliseconds> Duration;

    std::map<std::string, double> parameters;
    std::set<std::string> units;
    std::map<int, std::vector<Duration>> activations;
    std::map<std::string, std::vector<timeperiod>> plots;

    std::string name;
    std::chrono::milliseconds duration;

    Experiment();

    void set_name(const std::string& _name);

    void store_param(parameter& param);

    void add_unit(std::string& unit);

    void add_activation(const std::string& unit, const timeperiod& period);
   
    void add_plot(const std::string& unit, const timeperiod& period);

    void summary() const;
};

#endif
