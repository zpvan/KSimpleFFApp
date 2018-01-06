#ifndef K_DEMUXER_H_

#define K_DEMUXER_H_

#include "KErrors.h"
#include "InputParameter.h"

class KDemuxer
{
public:
	KDemuxer();
	~KDemuxer();
	KErrors configure(InputParameter *pParameter);
	KErrors start();

private:
	char* mInputFileName;
	char* mVideoOutputFileName;
	char* mAudioOutputFileName;

	FILE *pFileIn;
    FILE *pVideoFileOut;
    FILE *pAudioFileOut;
};

#endif