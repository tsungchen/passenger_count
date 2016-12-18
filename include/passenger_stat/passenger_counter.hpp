#ifndef _PASSENGER_COUNTER_HPP_
#define _PASSENGER_COUNTER_HPP_

#include "opencv2\core.hpp"
#include "passenger_stat_def.h"
#include "multi_target_tracker.hpp"
#include "target_detector.hpp"


class PASSEGER_EXPORTS PassengerCounter
{

public:

	int getPassengerNumber( ) const{ 
		return (m_innerCounter + m_candidateCounter);
	};
    
	static void stopProcess( PassengerCounter * pCounter );
	static void  runProcess( PassengerCounter * pCounter );

private:

	int m_innerCounter;
	int m_candidateCounter;
	int m_outerCounter;
	bool m_direction; //

	cv::Ptr<MultiTargetTracker> m_candidateTargets;
	cv::Ptr<TargetDetector> m_targetDetector;
};







#endif