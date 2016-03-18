#include <stdio.h>
#include <time.h>
#include <unistd.h>

#include "forteenSegmentDisplay.h"

int main(int argc, char *argv)
{
	time_t rawtime;
	struct tm *info;
	int old_second=-99;
	char szTime[10];

	forteenSegmentInit();
	do
	{
		time(&rawtime);
		info=localtime(&rawtime);
		if (info->tm_sec!=old_second)
		{
			old_second=info->tm_sec;
			switch (info->tm_sec)
			{
				case 57:
				case 58:
				case 59:
				case 0:
				case 1:
					sprintf(szTime,"  %2.2d",
						info->tm_sec);
					break;
				default:
					sprintf(szTime,"%2.2d%2.2d",
					info->tm_hour,info->tm_min);
					break;
			}
			displayColon(info->tm_sec % 2);
			if ( (info->tm_hour>=7) && (info->tm_hour<22))
			{
				setBrightness(BRIGHT);
			}
			else
			{
				setBrightness(DIM);
			}
			setDisplayString(szTime);
		}
		usleep(100000);
	}
	while(1);
	closeDisplay();
}

