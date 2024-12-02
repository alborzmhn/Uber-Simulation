#include "header.hpp"

Driver::Driver(int driver_id_)
{
    driver_id = driver_id_;
}
int Driver::get_driver_id()
{
    return driver_id;
}

void Driver::show_missions()
{
    if (driver_have_missions())
    {
        cout << "missions status for driver " << driver_id << ":\n";
        for (int i = 0; i < missions.size(); i++)
        {
            cout << "mission: " << missions[i]->get_mamoriat_id() << "\n";
            cout << "start timestamp: " << missions[i]->get_start_mamoriat() << "\n";
            if (datas[i].status)
                cout << "end timestamp: " << datas[i].end_time << "\n";
            else
                cout << "end timestamp: -1\n";
            cout << "reward: " << missions[i]->get_reward_amount() << "\n";
            if (datas[i].status)
                cout << "status: completed\n";
            else
                cout << "status: ongoing\n";
            if (i != missions.size() - ONE)
                cout << "\n";
        }
    }
}

bool Driver::driver_have_missions()
{
    if (missions.size() > 0)
        return true;
    cout << "DRIVER_MISSION_NOT_FOUND\n";
    return false;
}

void Driver::check_completed_mission(long int start_time, long int end_time, int distance)
{
    if (end_time > start_time)
    {
        cout << "completed missions for driver " << driver_id << ":\n";
        for (int i = 0; i < missions.size(); i++)
        {
            if (!datas[i].status)
            {
                if (missions[i]->check_complete(start_time, end_time, distance, driver_id, datas[i]))
                    datas[i].status = TRUE;
                cout << datas[i].count << " " << datas[i].distance << " " << datas[i].seconds << "\n";
            }
        }
    }
    else
        cout << "INVALID_ARGUMENTS\n";
}

int Driver::find_index_mission_in_vector(long int start_time)
{
    int count = ZERO;
    for (int i = 0; i < missions.size(); i++)
    {
        if (start_time >= missions[i]->get_start_mamoriat())
        {
            count++;
        }
    }
    return count;
}

void Driver::add_mission(Mission *adding_mission)
{
    if (!check_mission_existence(adding_mission->get_mamoriat_id()))
    {
        int index = find_index_mission_in_vector(adding_mission->get_start_mamoriat());
        missions.insert(missions.begin() + index, adding_mission);
        missions_data temp = {ZERO, ZERO, ZERO, ZERO};
        datas.insert(datas.begin() + index, temp);
        cout << "OK\n";
    }
}

bool Driver::check_mission_existence(int mission_id)
{
    for (int i = 0; i < missions.size(); i++)
    {
        if (missions[i]->get_mamoriat_id() == mission_id)
        {
            cout << "DUPLICATE_DRIVER_MISSION\n";
            return true;
        }
    }
    return false;
}
