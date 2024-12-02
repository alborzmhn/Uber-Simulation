# Mission Assignment and Tracking System

This project implements a system for managing and tracking missions assigned to drivers. It includes functionalities to create missions, assign them to drivers, validate mission completion, and display mission statuses.

## Features

### Core Functionalities
1. **Mission Management**:
   - Create different types of missions:
     - **Distance Mission**: Complete a certain distance within a time period.
     - **Count Mission**: Complete a specific number of tasks within a time period.
     - **Time Mission**: Spend a required amount of time on tasks.

2. **Driver Management**:
   - Assign missions to drivers.
   - Track mission statuses for each driver.
   - Validate mission completion based on predefined criteria.

3. **Validation and Reporting**:
   - Validate inputs for mission creation and assignment.
   - Display detailed mission statuses and completion records.

## File Structure

### Core Files
- **`main.cpp`**: Entry point that initializes the system and reads user commands.
- **`driver.cpp`**: Implements the `Driver` class, which manages missions assigned to a driver.
- **`mamoriat.cpp`**: Defines different mission types and their validation logic:
  - `DistanceMission`
  - `CountMission`
  - `TimeMission`
- **`snap.cpp`**: Implements the `Snap` class, the main controller that handles user inputs and system operations.

### Output File
- **`main.out`**: Example output from running the program.

## How It Works

1. **Add Missions**:
   - Create a mission by specifying its type, start and end timestamps, target criteria (e.g., distance, count, or time), and reward amount.

2. **Assign Missions**:
   - Assign a mission to a driver by providing the mission ID and driver ID.

3. **Track Mission Status**:
   - Check the status of missions assigned to a driver.
   - Record rides to update mission progress.

4. **Mission Completion**:
   - Validate mission completion based on progress and criteria.

## Example Commands

### Add Missions
```plaintext
add_distance_mission 1 1670000000 1670100000 5000 100
add_count_mission 2 1670000000 1670100000 10 150
add_time_mission 3 1670000000 1670100000 60 200
