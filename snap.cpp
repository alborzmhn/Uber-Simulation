#include "header.hpp"

Snap::Snap(){}

void Snap::read_input()
{
    while (true)
    {
        string order = "";
        cin >> order;
        if (order == "add_distance_mission")
        {
            add_distance_mission();
        }
        else if (order == "add_count_mission")
        {
            add_count_mission();
        }
        else if (order == "add_time_mission")
        {
            add_time_mission();
        }
        else if (order == "assign_mission")
        {
            assign_mission();
        }
        else if (order == "record_ride")
        {
            record_ride();
        }
        else if (order == "show_missions_status")
        {
            show_missions_status();
        }
    }
}

void Snap::show_missions_status()
{
    int driver_id;
    cin >> driver_id;
    if (check_driver_existence(driver_id))
        find_driver_by_id(driver_id)->show_missions();
}

void Snap::record_ride()
{
    long int start_time, end_time;
    int driver_id, distance;
    cin >> start_time >> end_time >> driver_id >> distance;
    if (check_driver_existence(driver_id))
        find_driver_by_id(driver_id)->check_completed_mission(start_time, end_time, distance);
}

void Snap::assign_mission()
{
    int mission_id, driver_id;
    cin >> mission_id >> driver_id;
    if (check_mission_existence(mission_id))
    {
        if (!check_driver_existence(driver_id))
        {
            Driver *p = new Driver(driver_id);
            drivers.push_back(p);
            // cout << "driver added successfuly\n";
        }
        find_driver_by_id(driver_id)->add_mission(find_mission_by_id(mission_id));
    }
}

Driver *Snap::find_driver_by_id(int driver_id)
{
    for (int i = 0; i < drivers.size(); i++)
    {
        if (drivers[i]->get_driver_id() == driver_id)
        {
            return drivers[i];
        }
    }
}

bool Snap::check_driver_existence(int driver_id)
{
    for (int i = 0; i < drivers.size(); i++)
    {
        if (drivers[i]->get_driver_id() == driver_id)
        {
            return true;
        }
    }
    return false;
}

bool Snap::check_mission_existence(int mission_id)
{
    for (int i = 0; i < missions.size(); i++)
    {
        if (missions[i]->get_mamoriat_id() == mission_id)
        {
            return true;
        }
    }
    cout << "MISSION_NOT_FOUND\n";
    return false;
}

Mission *Snap::find_mission_by_id(int mission_id)
{
    for (int i = 0; i < missions.size(); i++)
    {
        if (missions[i]->get_mamoriat_id() == mission_id)
        {
            return missions[i];
        }
    }
}

bool Snap::is_mission_id_available(int mission_id)
{

    for (int i = 0; i < missions.size(); i++)
    {
        if (missions[i]->get_mamoriat_id() == mission_id)
        {
            cout << "DUPLICATE_MISSION_ID\n";
            return false;
        }
    }
    return true;
}

bool Snap::correctness_of_start_end(long int start_time, long int end_time)
{
    if (start_time < end_time)
    {
        return true;
    }
    cout << "INVALID_ARGUMENTS\n";
    return false;
}

void Snap::add_distance_mission()
{
    int mission_id;
    long int start_timestamp;
    long int end_timestamp;
    int target_distance_in_meters;
    int reward;
    cin >> mission_id >> start_timestamp >> end_timestamp >> target_distance_in_meters >> reward;
    if (is_mission_id_available(mission_id) && correctness_of_start_end(start_timestamp, end_timestamp) && are_two_arguments_positive(reward, target_distance_in_meters))
    {
        Mission *p = new Distance_mission(mission_id, start_timestamp, end_timestamp, reward, target_distance_in_meters);
        missions.push_back(p);
        cout << "OK\n";
    }
}

void Snap::add_count_mission()
{
    int mission_id;
    long int start_timestamp;
    long int end_timestamp;
    int target_number;
    int reward;
    cin >> mission_id >> start_timestamp >> end_timestamp >> target_number >> reward;
    if (is_mission_id_available(mission_id) && correctness_of_start_end(start_timestamp, end_timestamp) && are_two_arguments_positive(reward, target_number))
    {
        Mission *p = new Count_mission(mission_id, start_timestamp, end_timestamp, reward, target_number);
        missions.push_back(p);
        cout << "OK\n";
    }
}

void Snap::add_time_mission()
{
    int mission_id;
    long int start_timestamp;
    long int end_timestamp;
    int target_time_in_minutes;
    int reward;
    cin >> mission_id >> start_timestamp >> end_timestamp >> target_time_in_minutes >> reward;
    if (is_mission_id_available(mission_id) && correctness_of_start_end(start_timestamp, end_timestamp) && are_two_arguments_positive(reward, target_time_in_minutes))
    {
        Mission *p = new Time_mission(mission_id, start_timestamp, end_timestamp, reward, target_time_in_minutes);
        missions.push_back(p);
        cout << "OK\n";
    }
}

bool Snap::are_two_arguments_positive(int argument1, int argument2)
{
    if (argument1 > ZERO && argument2 > ZERO)
        return true;
    cout << "INVALID_ARGUMENTS\n";
    return false;
}
