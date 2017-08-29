# Floor Cleaning Rover
<strong>EL101 Digital Logic Circuits Project</strong><br>
An obstacle avoiding, floor cleaning Arduino Uno based rover.

## Components Used
```
1. Arduino UNO
2. 12V DC motors (x2)
3. L293D IC
4. 7805 Voltage Regulator
5. HC-SRO4 UltraSonic Sensor (For obstacle avoidance)
6. 9V power supply x2 + A Power bank for Arduino
7. Breadboard
8. Connecting Wires
9. Rover Body (We made it ourselves)
10. Robot Wheels (x2)
11. Cleaning Brush
```
## Algorithm
![path](https://cloud.githubusercontent.com/assets/13731530/25047229/19048140-2153-11e7-84a1-a19b72e22290.png)

When the rover is kept in one corner of an empty room, it follows a path similar to the one shown in the image above.
Everytime it encounters a wall (obstacle), it alternates between a 90 degree left and right turn.
The algorithm is designed to cover the entire surface of the floor it is kept on.

**Limitations:**
* It will follow the reverse path once it reaches the stop point. Has to be manually stopped once done.
* The algorithm only works for an empty, open room with no objects on the floor.
It will detect and avoid the objects if present, but will not cover the entire surface area of the floor.

## Images
![Floor Cleaning Rover](https://user-images.githubusercontent.com/13731530/29819608-0009f86c-8cdf-11e7-8c9c-f8724aa4c117.jpg)
