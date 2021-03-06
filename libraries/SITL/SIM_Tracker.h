/// -*- tab-width: 4; Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil -*-
/*
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
/*
  antenna-tracker simulator class
*/

#ifndef _SIM_TRACKER_H
#define _SIM_TRACKER_H

#include "SIM_Aircraft.h"

/*
  a antenna tracker simulator
 */
class Tracker : public Aircraft
{
public:
    Tracker(const char *home_str, const char *frame_str);
    void update(const struct sitl_input &input);

    /* static object creator */
    static Aircraft *create(const char *home_str, const char *frame_str) {
        return new Tracker(home_str, frame_str);
    }

private:

    const bool onoff = false;
    const float yawrate = 9.0f;
    const float pitchrate = 1.0f;
    const float pitch_range = 45;
    const float yaw_range = 170;
    const float zero_yaw = 0;  // yaw direction at startup
    const float zero_pitch = 0; // pitch at startup
    bool verbose = false;
    uint64_t last_debug_us = 0;

    float pitch_input;
    float yaw_input;

    void update_position_servos(float delta_time, float &yaw_rate, float &pitch_rate);
    void update_onoff_servos(float &yaw_rate, float &pitch_rate);
};

#endif
