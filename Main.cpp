#include "stdio.h"
#include "stdint.h"
#include "unistd.h"
#include "getopt.h"

#include "KEncoder.h"
#include "InputParameter.h"
#include "KErrors.h"

extern "C"
{
    #include "libavutil/imgutils.h"
    #include "libavformat/avformat.h"
    #include "libavutil/samplefmt.h"
}

const char *ENC = "enc";

struct option longopts[] = 
{
    // 选择功能， enc表示编码
    {"func", required_argument, NULL, FUNCTION},
    // 比特率
    {"br", required_argument, NULL, BITRATE},
    // 帧率
    {"fr", required_argument, NULL, FRAMERATE},
    // 帧数
    {"fc", required_argument, NULL, FRAMECOUNT},
    // 分辨率
    {"vr", required_argument, NULL, VIDEO_RESOLUTION},
};

int main(int argc, char **argv)
{
    int oc;
    char ec;
    char *func = NULL;
    InputParameter parameter;
    while((oc = getopt_long(argc, argv, "i:o:", longopts, NULL)) != -1)
    {
        switch(oc)
        {
            case FUNCTION:
                func = optarg;
                break;

            case INPUT_FILE:
                parameter.mInputFileName = optarg;
                break;

            case OUTPUT_FILE:
                parameter.mOutputFileName = optarg;
                break;

            case BITRATE:
                parameter.mBitRate = atoi(optarg);
                break;

            case FRAMERATE:
                parameter.mFrameRate = atoi(optarg);
                break;

            case FRAMECOUNT:
                parameter.mFrameCount = atoi(optarg);
                break;

            case VIDEO_RESOLUTION:
                char *resolution = optarg;
                int length = strlen(resolution);
                int i;
                for (i = 0; i < length; i++)
                {
                    if (resolution[i] == 'x')
                    {
                        int widthLength = i;
                        char width[widthLength + 1];
                        char height[length - widthLength];
                        strncpy(width, resolution, widthLength);
                        width[widthLength] = '\0';
                        printf("w: %s\n", width);
                        strncpy(height, resolution + widthLength + 1, length - widthLength - 1);
                        height[length - widthLength - 1] = '\0';
                        printf("h: %s\n", height);
                    }
                }
                
                break;
        }
    }

    if (!strcmp(ENC, func))
    {
        printf("启动编码器\n");
        KErrors res = NO_ERROR;
        KEncoder *encoder = new KEncoder();
        res = encoder->configure(&parameter);
        if (!res)
        {
            printf("配置编码器成功\n");
        } 
        else 
        {
            printf("配置编码器失败\n");
        }
    }
    av_register_all();
}