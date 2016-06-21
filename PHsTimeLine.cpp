
/*
	2016.01.31
	Created by PHJ.
*/

#ifndef _PHS_TIME_LINE_CPP

#define _PHS_TIME_LINE_CPP

#include "PHsTimeLine.h"

namespace PHs
{
	/*
		TODO : Place your code here
	*/
	
	inline namespace PHsTime
	{
		using namespace std;
		using namespace std::chrono;

		TimeLine::TimeLine() :
			nOrigin{system_clock::now().time_since_epoch().count()}
		{
			//Empty.
		}

		TimeLine::TimeLine(const TimeLine &sNewTimeLine) :
			nOrigin{sNewTimeLine.nOrigin}
		{
			//Empty.
		}

		TimeLine &TimeLine::operator=(const TimeLine &sNewTimeLine)
		{
			this->nOrigin = sNewTimeLine.nOrigin;

			return *this;
		}

		Long TimeLine::timelineElapsed()
		{
			Time sTime = system_clock::now();
			Long nElapsed = sTime.time_since_epoch().count() - this->nOrigin;
			this->nOrigin += nElapsed;

			return nElapsed;
		}
	}
}

#endif