  _  __    _ _       __     ___     _                   __  __       _   _               ____       _            _   _             
 | |/ /___(_) |  _   \ \   / (_)___(_) ___  _ __    _  |  \/  | ___ | |_(_) ___  _ __   |  _ \  ___| |_ ___  ___| |_(_) ___  _ __  
 | ' // _ \ | | | | | \ \ / /| / __| |/ _ \| '_ \  (_) | |\/| |/ _ \| __| |/ _ \| '_ \  | | | |/ _ \ __/ _ \/ __| __| |/ _ \| '_ \ 
 | . \  __/ | | | |_| |\ V / | \__ \ | (_) | | | |  _  | |  | | (_) | |_| | (_) | | | | | |_| |  __/ ||  __/ (__| |_| | (_) | | | |
 |_|\_\___|_|_| | ._,_| \_/  |_|___/_|\___/|_| |_| (_) |_|  |_|\___/ \__|_|\___/|_| |_| |____/ \___|\__\___|\___|\__|_|\___/|_| |_|
                |_|                                                                                                                

OVERVIEW:

Accelerometer is a device that is used for measuring the acceleration forces. The forces may be continuous or static; it may also be related to mobile devices, sense of movement or vibrations.

So, we can say that ACCELERATION = CHANGE IN VELOCITY or SPEED/TIME

Mathematically, it can be represented as follows: 

Acceleration = Δv / Δt = (vf - vi)/(tf - ti)


INDUSTRIAL APPLICATIONS:

Accelerometer is used in various dimensions of the industry. Some of the day to day applications include - fitness trackers, safety collision mechanism on vehicles, wind gust detection in meteorology, process control (door open/shut) in buildings etc.


WHAT DOES THIS PROGRAM DO:

The program written in Embedded C helps to detect the motions relayed by the sensor. The motion activity is classified as IDLE or STATIC, depending upon the steadiness of the sensor.

if  (SENSOR = FAST)
    then FAST MOTION

if  (SENSOR = SLOW)
    then SLOW MOTION


PROCEDURE ON CLASSIFICATION OF MOTION:

1.  The sensor was placed on the hand and the activities were classified based on the values obtained on Putty
2.  Keil µVision was used for data capturing
3.  100 samples of data was taken for data classification
4.  Mean and Standard Deviation of the data captured for X axis was used for activity classification
5.  The range of the threshold was set by trial and error method after taking multiple trials for each activity


NOTE:- This project was a fulfilment for The Sensor Network course which was a part of my Master's pursuit!