
/*
	2016.01.31
	Created by PHJ.
*/

#ifndef _PHS_TIME_LINE_H

#define _PHS_TIME_LINE_H

#include "PHsCommon.h"

#include <chrono>

namespace PHs
{
	/*
		TODO : Place your code here
	*/
	
	inline namespace PHsTime
	{
		class TimeLine
		{
		public:
			using Nano = std::chrono::duration <Long, std::nano>;
			using Time = std::chrono::time_point <std::chrono::system_clock, Nano>;

		private:
			Long nOrigin;

		public:
			TimeLine();
			TimeLine(TimeLine &&sNewTimeLine) = delete;
			TimeLine(const TimeLine &sNewTimeLine);
			~TimeLine() = default;

		public:
			TimeLine &operator=(TimeLine &&sNewTimeLine) = delete;
			TimeLine &operator=(const TimeLine &sNewTimeLine);

			Long timelineElapsed();
		};
	}
}

#endif