# autonomous-lawnmower
Code for the project on the design and fabrication of an autonomous lawnmower, initially implemented on an Arduino Uno. 3 InfraRed sensors provoded readings of obstacles, according to which the lawnmower would turn left or right. 

The #define functions at the start of the code correspond to various pins of the Arduino Uno. In the void(setup) section, the board is instructed to read signals from sensors or give outputs to motors, connected via motor driver boards. 

The void(loop) contains the bulk of the code, and is supported by functions controlling forward motion, backward motion and turns. The action for the turn is set by the reading from the sensors - for example, a reading from the left sensor will cause the robot to turn right. 
