#ifndef K_ERRORS_H_

#define K_ERRORS_H_

enum KErrors
{
	NO_ERROR = 0,

	ERROR_BASE = 100,
	ERROR_NO_INPUT_PARAMETER,
	ERROR_CAN_NOT_OPEN_INPUT_FILE,
	ERROR_CAN_NOT_OPEN_OUTPUT_FILE,
	ERROR_FF_FIND_ENCODER,
	ERROR_FF_ALLOC_AVCODECCONTEXT,
	ERROR_FF_ALLOC_AVFRAME,
	ERROR_FF_ALLOC_IMAGE,
	ERROR_FF_ENCODE_VIDEO,
	ERROR_FF_OPEN_AVCODEC,
};

#endif