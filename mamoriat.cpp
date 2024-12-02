#include "header.hpp"

Mission::Mission(){}
Mission::Mission(int _mamoriat_id, long int _start_mamoriat, long int _end_mamoriat, int _reward_amount)
{
    mamoriat_id = _mamoriat_id;
    start_mamoriat = _start_mamoriat;
    end_mamoriat = _end_mamoriat;
    reward_amount = _reward_amount;
}

int Mission::get_mamoriat_id()
{
    return mamoriat_id;
}

void Mission::print_record_ride(long int end_time)
{
    cout << "mission: " << mamoriat_id << "\n";
    cout << "start tiemstamp: " << start_mamoriat << "\n";
    cout << "end timestamp: " << end_time << "\n";
    cout << "reward: " << reward_amount << "\n\n";
}

long int Mission::get_start_mamoriat()
{
    return start_mamoriat;
}

int Mission::get_reward_amount()
{
    return reward_amount;
}

long int Mission::get_end_mamoriat()
{
    return end_mamoriat;
}

Time_mission::Time_mission(int _mamoriat_id, long int _start_mamoriat, long int _end_mamoriat, int _reward_amount, int _target_time_in_minutes)
    : Mission(_mamoriat_id, _start_mamoriat, _end_mamoriat, _reward_amount)
{
    target_time_in_minutes = _target_time_in_minutes;
}

bool Time_mission::check_complete(long int start_time, long int end_time, int distance, int driver_id, missions_data &mission_data)
{
    if (start_time < start_mamoriat || end_time > end_mamoriat)
        return false;
    mission_data.seconds += end_time - start_time;
    if (mission_data.seconds >= target_time_in_minutes)
    {
        mission_data.end_time = end_time;
        print_record_ride(end_time);
        return true;
    }
    return false;
}

Distance_mission::Distance_mission(int _mamoriat_id, long int _start_mamoriat, long int _end_mamoriat, int _reward_amount, int _target_distance_in_meters)
    : Mission(_mamoriat_id, _start_mamoriat, _end_mamoriat, _reward_amount)
{
    target_distance_in_meters = _target_distance_in_meters;
}

bool Distance_mission::check_complete(long int start_time, long int end_time, int distance, int driver_id, missions_data &mission_data)
{
    if (start_time < start_mamoriat || end_time > end_mamoriat)
        return false;
    mission_data.distance += distance;
    if (mission_data.distance >= target_distance_in_meters)
    {
        mission_data.end_time = end_time;
        print_record_ride(end_time);
        return true;
    }
    return false;
}

Count_mission::Count_mission(int _mamoriat_id, long int _start_mamoriat, long int _end_mamoriat, int _reward_amount, int _target_number)
    : Mission(_mamoriat_id, _start_mamoriat, _end_mamoriat, _reward_amount)
{
    target_number = _target_number;
}

bool Count_mission::check_complete(long int start_time, long int end_time, int distance, int driver_id, missions_data &mission_data)
{
    if (start_time < start_mamoriat || end_time > end_mamoriat)
        return false;
    mission_data.count++;
    if (mission_data.count >= target_number)
    {
        mission_data.end_time = end_time;
        print_record_ride(end_time);
        return true;
    }
    return false;
}
