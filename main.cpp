/**
    @author Cemal Yetismis
    @version 1.0 3/11/2021
*/
#include <iostream>
#include <memory>
#include <vector>
#include "action.h"
#include "message.h"
#include "email.h"
#include "sprinkler.h"
#include "coolingsprinkler.h"
#include "component.h"
#include "emergency_center.h"
#include "sensor.h"
#include "gassensor.h"
#include "smokesensor.h"
#include "text.h"
#include "motionsensor.h"
#include "call.h"
#include "alarm.h"
#include "sensorTypeEnum.h"



const std::string vendor ="Disney";

int main()
{

    //DEFINE EMERGENCY CENTER
    auto emergencyCenter=std::make_shared <emergency_center>("Twix");

    //MOTION SENSOR IN TWIX
    auto motionSensorTwix = std::make_shared <Motionsensor>("Twix",vendor,SensorType::Motion);
    auto motionSensorTwixAction = std::make_shared <call>("Peacekeeping force","155",AlarmLevel::High);
    //Activate Permanently
    motionSensorTwix->operator++();
    motionSensorTwix->addAction(motionSensorTwixAction);

    // DEFINE Planet X_AE_A_12 COLLECTION
    auto planet_X_AE_A_12 = std::make_shared <emergency_center>("X_AE_A_12");

    //DEFINE Planet X_AE_A_12 Atmosphere COLLECTION
    auto planet_X_AE_A_12_atmsophere = std::make_shared <emergency_center>("Atmosphere");

    //Planet X_AE_A_12 Atmosphere Gas sensor
    auto gasSensorAtmosphere_X_AE_A_12 = std::make_shared <Gassensor>("Oxgen",1000000000,"Planet X_AE_A_12 Atmosphere",vendor,SensorType::Gas);
    auto gasSensorAtmospherAlarm = std::make_shared <Alarm>(AlarmLevel::High);
    auto gasSensorAtmospheretextAction = std::make_shared <Text>("scientists","Oxgen level is low","545878539842",AlarmLevel::High);
    gasSensorAtmosphere_X_AE_A_12->addAction(gasSensorAtmospheretextAction);
    gasSensorAtmosphere_X_AE_A_12->addAction(gasSensorAtmospherAlarm);

    //Planet X_AE_A_12 Surface Smoke Sensors
    auto smokeSensorRedstone = std::make_shared <SmokeSensor>("Planet X_AE_A_12 Redstone",vendor,SensorType::Smoke);
    auto smokeSensorRedstoneCoolingSprinkler = std::make_shared <CoolingSprinkler>(AlarmLevel::Medium);
    smokeSensorRedstone->addAction(smokeSensorRedstoneCoolingSprinkler);
    auto smokeSensorOrangestone = std::make_shared <SmokeSensor>("Planet X_AE_A_12 Orangestone",vendor,SensorType::Smoke);
    auto smokeSensorOrangestoneCoolingSprinkler = std::make_shared <CoolingSprinkler>(AlarmLevel::Medium);
    smokeSensorOrangestone->addAction(smokeSensorOrangestoneCoolingSprinkler);

    //DEFINE Planet LV-426 Collection
    auto planet_LV_426 = std::make_shared <emergency_center>("LV_426");

    //DEFINE Planet LV-426 Atmosphere Collection
    auto planet_LV_426_atmosphere = std::make_shared <emergency_center>("Atmosphere");

    //Planet LV-426 Atmosphere Gas sensor
    auto gasSensorAtmosphere_LV_426 = std::make_shared <Gassensor>("Oxgen",1200000000,"Planet LV-426 Atmosphere",vendor,SensorType::Gas);
    auto gasSensorAtmosphereAction_LV_426 = std::make_shared <Alarm>(AlarmLevel::High);
    gasSensorAtmosphere_LV_426->addAction(gasSensorAtmosphereAction_LV_426);

    //Planet LV-426 Atmosphere Motion Sensor
    auto motionSensorAtmosphere_LV_426 = std::make_shared <Motionsensor>("Planet LV-426 Atmosphere",vendor,SensorType::Motion);
    auto motionSensorAtmosphereTextAction_LV_426=std::make_shared <Text>("scientists","Oxgen level is low","545878539842",AlarmLevel::High);
    auto motionSensorAtmosphereCallAction_LV_426  = std::make_shared <call>("Peacekeeping force","155",AlarmLevel::High);
    motionSensorAtmosphere_LV_426->operator++();
    motionSensorAtmosphere_LV_426->addAction(motionSensorAtmosphereTextAction_LV_426);
    motionSensorAtmosphere_LV_426->addAction(motionSensorAtmosphereCallAction_LV_426);

    //Planet LV-426 Moon Unit Collection
    auto planet_LV_426_MoonUnit = std::make_shared <emergency_center>("MoonUnit");

    //Planet LV-426 Moon Unit Smoke Sensor
    auto smokeSensorMoonUnit=std::make_shared <SmokeSensor>("Planet LV-426 Moon Unit",vendor,SensorType::Smoke);
    auto smokeSensorMoonUnitCallAction=std::make_shared <Text>("Fire Brigade","Fire Fire","112",AlarmLevel::High);
    smokeSensorMoonUnit->addAction(smokeSensorMoonUnitCallAction);

    //Planet LV-426 Moon Unit Motion Sensor
    auto motionSensorMoonUnit = std::make_shared <Motionsensor>(10,20,0,8,0,"Planet LV-426 Moon Unit",vendor,SensorType::Motion);
    auto motionSensorMoonUnitAction = std::make_shared <Alarm>(AlarmLevel::High);
    motionSensorMoonUnit->addAction(motionSensorMoonUnitAction);

    //Define Planet LV-426 Dweezil Collection
    auto planet_LV_426_Dweezil = std::make_shared <emergency_center>("Dweezil");

    //Planet LV-426 Dweezil Smoke and Motion Sensor
    auto smokeSensorDweezil=std::make_shared <SmokeSensor>("Planet LV-426 Dweezil",vendor,SensorType::Gas);
    auto smokeSensorDweezilCallAction=std::make_shared <Text>("Fire Brigade","Fire Fire","112",AlarmLevel::High);
    smokeSensorDweezil->addAction(smokeSensorDweezilCallAction);
    auto motionSensorDweezil = std::make_shared <Motionsensor>(10,20,0,8,0,"Planet LV-426 Dweezil",vendor,SensorType::Motion);
    auto motionSensorDweezilAction = std::make_shared <Alarm>(AlarmLevel::High);
    motionSensorDweezil->addAction(motionSensorDweezilAction);



    //Adding All Collections to Actual Emergency Center
    emergencyCenter->add_sensor(motionSensorTwix);

    planet_LV_426_Dweezil->add_sensor(smokeSensorDweezil);
    planet_LV_426_Dweezil->add_sensor(motionSensorDweezil);

    planet_LV_426_MoonUnit->add_sensor(smokeSensorMoonUnit);
    planet_LV_426_MoonUnit->add_sensor(motionSensorMoonUnit);

    planet_LV_426_atmosphere->add_sensor(gasSensorAtmosphere_LV_426);
    planet_LV_426_atmosphere->add_sensor(motionSensorAtmosphere_LV_426);

    planet_LV_426->add_sensor(planet_LV_426_atmosphere);
    planet_LV_426->add_sensor(planet_LV_426_MoonUnit);
    planet_LV_426->add_sensor(planet_LV_426_Dweezil);

    planet_X_AE_A_12_atmsophere->add_sensor(gasSensorAtmosphere_X_AE_A_12);
    planet_X_AE_A_12->add_sensor(planet_X_AE_A_12_atmsophere);
    planet_X_AE_A_12->add_sensor(smokeSensorRedstone);
    planet_X_AE_A_12->add_sensor(smokeSensorOrangestone);

    emergencyCenter->add_sensor(planet_X_AE_A_12);
    emergencyCenter->add_sensor(planet_LV_426);



    std::cout << "-----------ACTIVATE AND TEST ALL ATMOSPHERIC SENSOR------------"<<std::endl;
    emergencyCenter->activateCollectionbyName("Atmosphere");
    emergencyCenter->testCollectionbyName("Atmosphere");
    std::cout << "-----------ACTIVATE AND TEST ALL SENSORS ON X_AE_A_12----------"<<std::endl;
    emergencyCenter->activateCollectionbyName("X_AE_A_12");
    emergencyCenter->testCollectionbyName("X_AE_A_12");
    std::cout << "-----------DEACTIVATE  ALL SENSORS ON LV_426----------"<<std::endl;
    emergencyCenter->deactivateCollectionbyName("LV_426");
    std::cout << "-----------REACTIVATE  ALL SENSORS ON LV_426----------"<<std::endl;
    emergencyCenter->activateCollectionbyName("LV_426");
    std::cout << "-----------TEST WHOLE PLANET----------"<<std::endl;
    emergencyCenter->testCollectionbyName("LV_426");
    std::cout << "-----------TEST MOON UNIT----------"<<std::endl;
    emergencyCenter->testCollectionbyName("MoonUnit");
    std::cout << "-----------TEST DWEEZIL----------"<<std::endl;
    emergencyCenter->testCollectionbyName("Dweezil");
    std::cout << "-----------PRINT OVERVIEW OF ALL SENSOR ALBHABETHICALLY----------"<<std::endl;
    emergencyCenter->giveOverviewofAllSensor(OrderByLocation());
    return 0;
}
