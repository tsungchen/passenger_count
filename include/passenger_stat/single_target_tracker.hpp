#ifndef _SINGLE_TARGET_TRACKER_HPP_
#define _SINGLE_TARGET_TRACKER_HPP_

#include "opencv2\core.hpp"
#include "passenger_stat\passenger_stat_def.h"

class PASSEGER_EXPORTS SingleTargetTracker
{

public:
	cv::Point PredictTarget( );
	void UpdateTarget(cv::Point newPos);


private:
	
	cv::Rect m_targetROI;
	cv::Mat  m_imageRef;    //

};






#endif