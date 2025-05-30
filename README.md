# Mission Assignment and Tracking System

This project implements a system for managing and tracking missions assigned to drivers. It includes functionalities to create missions, assign them to drivers, validate mission completion, and display mission statuses.

## Features

### Core Functionalities

#### Mission Management

- **Create different types of missions:**
  - **Distance Mission:** Complete a certain distance within a time period.
  - **Count Mission:** Complete a specific number of tasks within a time period.
  - **Time Mission:** Spend a required amount of time on tasks.

#### Driver Management

- Add and manage drivers.
- Assign missions to drivers.
- Track mission statuses for each driver.
- Validate mission completion based on predefined criteria.

#### Validation and Reporting

- Validate inputs for mission creation and assignment.
- Display detailed mission statuses and completion records.

## File Structure

### Core Files

- `main.cpp`: Entry point that initializes the system and reads user commands.
- `driver.cpp`: Implements the `Driver` class, which manages missions assigned to a driver.
- `mamoriat.cpp`: Defines different mission types and their validation logic:
  - `DistanceMission`
  - `CountMission`
  - `TimeMission`
- `snap.cpp`: Implements the `Snap` class, the main controller that handles user inputs and system operations.
- `header.hpp`: Contains class definitions and shared structures.

### Output File

- `main.out`: Example output from running the program.

## How It Works

### Add Missions

Create a mission by specifying:
- Type of mission
- Start and end timestamps
- Target criteria (e.g., distance, count, or time)
- Reward amount

add_distance_mission <mission_id> <start_time> <end_time> <distance> <reward>

add_count_mission <mission_id> <start_time> <end_time> <count> <reward>

add_time_mission <mission_id> <start_time> <end_time> <time_minutes> <reward>

### Assign Missions

Assign an existing mission to a driver using:
- Mission ID
- Driver ID

assign_mission <mission_id> <driver_id>

this will automatically add a driver with driver_id to the Uber app if mission is valid

### Record Rides

Log rides for drivers including:
- Start time of the ride
- End time of the ride
- Driver ID
- Distance traveled

record_ride <start_time> <end_time> <driver_id> <distance>

### Check Status

Monitor the mission status and progress for each driver.

show_missions_status <driver_id>

### Mission Completion

Validate whether missions are completed based on their type and the driver's ride history.



