#ifndef PCM_TO_AAC_H
#define PCM_TO_AAC_H

#include <faac.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct pcm_acc
{
    faacEncHandle   m_hEncoder ;
    faacEncConfigurationPtr m_pConfiguration;   //编码器参数 
    unsigned long   m_InputSample ;
    unsigned long   m_MaxOutputBytes;
    int             m_PCMbitSize;
    int             m_SampleRate;
    int             m_Channel;
    int m_PCMBufSize;
    char* m_PtrPCMBuf;
    char* m_PtrAACBuf;
}PCM_ACC;


/*
* 回调库测试
*/
int pcm_to_acc_test();
/*
* 初始话编码
* samplerate:采样率
*chanel: 通道
* sample_bit: 单样本位数
*/
int pcm_to_acc_init(int samplerate, int chanel, int sample_bit);
/*
*   编码数据
* pcmbuf: pcm 数据
*PcmSize： pcm 数据大小
*aacBuf: acc 数据
*/
int pcm_to_acc_encode(char* pcmbuf, int PcmSize, unsigned char* aacBuf);
/*
* 结束编码
*/
void pcm_to_acc_end();

#endif
