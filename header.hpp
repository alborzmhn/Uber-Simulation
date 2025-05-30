#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef struct missions_data missions_data;
#define ZERO 0
#define TRUE 1
#define ONE 1

struct missions_data
{
    int distance;
    int count;
    int seconds;
    int status;
    long int end_time;
};

class Mission
{
public:
    Mission();
    Mission(int _mamoriat_id, long int _start_mamoriat, long int _end_mamoriat, int _reward_amount);
    virtual bool check_complete(long int start_time, long int end_time, int distance, int driver_id, missions_data &mission_data) = 0;
    int get_mamoriat_id();
    void print_record_ride(long int end_time);
    long int get_start_mamoriat();
    int get_reward_amount();
    long int get_end_mamoriat();

protected:
    int mamoriat_id;
    long int start_mamoriat;
    long int end_mamoriat;
    int reward_amount;
};

class Time_mission : public Mission
{
public:
    Time_mission(int _mamoriat_id, long int _start_mamoriat, long int _end_mamoriat, int _reward_amount, int _target_time_in_minutes);
    bool check_complete(long int start_time, long int end_time, int distance, int driver_id, missions_data &mission_data);

private:
    int target_time_in_minutes;
};

class Distance_mission : public Mission
{
public:
    Distance_mission(int _mamoriat_id, long int _start_mamoriat, long int _end_mamoriat, int _reward_amount, int _target_distance_in_meters);
    bool check_complete(long int start_time, long int end_time, int distance, int driver_id, missions_data &mission_data);

private:
    int target_distance_in_meters;
};

class Count_mission : public Mission
{
public:
    Count_mission(int _mamoriat_id, long int _start_mamoriat, long int _end_mamoriat, int _reward_amount, int _target_number);
    bool check_complete(long int start_time, long int end_time, int distance, int driver_id, missions_data & mission_data);

private:
    int target_number;
};

class Driver
{
public:
    Driver(int driver_id_);
    int get_driver_id();
    void show_missions();
    bool driver_have_missions();
    void check_completed_mission(long int start_time, long int end_time, int distance);
    int find_index_mission_in_vector(long int start_time);
    void add_mission(Mission *adding_mission);
    bool check_mission_existence(int mission_id);

private:
    vector<Mission *> missions;
    int driver_id;
    vector<missions_data> datas;
};


class Snap
{
public:
    Snap();
    void read_input();
    void show_missions_status();
    void record_ride();
    void assign_mission();
    Driver *find_driver_by_id(int driver_id);
    bool check_driver_existence(int driver_id);
    bool check_mission_existence(int mission_id);
    Mission *find_mission_by_id(int mission_id);
    bool is_mission_id_available(int mission_id);
    bool correctness_of_start_end(long int start_time, long int end_time);
    void add_distance_mission();
    void add_count_mission();
    void add_time_mission();
    bool are_two_arguments_positive(int argument1, int argument2);

private:
    vector<Driver *> drivers;
    vector<Mission *> missions;
};