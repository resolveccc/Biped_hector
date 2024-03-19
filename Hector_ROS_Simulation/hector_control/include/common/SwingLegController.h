#ifndef SWINGLEGCONTROLLER_H
#define SWINGLEGCONTROLLER_H
#include "../../ConvexMPC/GaitGenerator.h"
#include "../../include/common/ControlFSMData.h"
#include "../../include/common/FootSwingTrajectory.h"
#include "../../include/common/cppTypes.h"
#include "../../include/common/LegController.h"


 /**
  * @note varibles with _w are in world frame
  * @note varibles with _b are in body frame
 */
class swingLegController {
    public:
        static constexpr int nLegs = 2;
    
        swingLegController() = default;
        swingLegController(ControlFSMData *data, Gait* gait, double dtSwing);
        ~swingLegController();

        //Setter method for data, gait, and dtSwing used at initialization only
        void initSwingLegController(ControlFSMData *data, Gait* gait, double dtSwing);

        

    private:
        Gait* gait;
        const ControlFSMData* data;
        StateEstimate seResult;
        double _dtSwing;
        FootSwingTrajectory<double> footSwingTrajectory[nLegs];
        Vec3<double> pFoot_w[nLegs];
        Vec3<double> vFoot_w[nLegs]; 
        Vec3<double> pFoot_b[nLegs];
        Vec3<double> vFoot_b[nLegs];                        
        Vec2<double> swingStates;
        Vec2<double> swingTimes;
        void updateFootPosition();

        // constants can be adjusted if needed
        const double _dt = 0.001;
        const double footHeight = 0.1;        

}; // class swingLegController

#endif // SWINGLEGCONTROLLER_H    