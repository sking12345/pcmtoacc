#include "pcm_to_aac.h"

static struct pcm_acc *pcm_acc = NULL;

int pcm_to_acc_test()
{
    printf("%s\n", "pcm_to_acc_test is ok");
    return 1;
}

int pcm_to_acc_init(int samplerate, int chanel, int sample_bit)
{
	pcm_acc = (struct pcm_acc*)malloc(sizeof(struct pcm_acc));
	memset(pcm_acc,0,sizeof(struct pcm_acc));

	pcm_acc->m_PCMbitSize = sample_bit;
    pcm_acc->m_SampleRate = samplerate;
    pcm_acc->m_Channel    = chanel;
    pcm_acc->m_hEncoder = faacEncOpen(pcm_acc->m_SampleRate, pcm_acc->m_Channel,&pcm_acc->m_InputSample, &pcm_acc->m_MaxOutputBytes);
    if (!pcm_acc->m_hEncoder){
    	printf("%s\n", "faacEncOpen error");
        return -1;
    }
    pcm_acc->m_PCMBufSize = pcm_acc->m_InputSample * pcm_acc->m_PCMbitSize / 8;
    pcm_acc->m_PtrPCMBuf = (char*)malloc(pcm_acc->m_PCMBufSize);
    pcm_acc->m_PtrAACBuf = (char*)malloc(pcm_acc->m_MaxOutputBytes);
    pcm_acc->m_pConfiguration = faacEncGetCurrentConfiguration(pcm_acc->m_hEncoder);

    pcm_acc->m_pConfiguration->inputFormat  = FAAC_INPUT_16BIT;
   	pcm_acc->m_pConfiguration->outputFormat = 1;  //0--RAW  1--ADTS header 
    pcm_acc->m_pConfiguration->aacObjectType = LOW;
    pcm_acc->m_pConfiguration->allowMidside = 0;
    faacEncSetConfiguration(pcm_acc->m_hEncoder, pcm_acc->m_pConfiguration);   
    return 1;
}

int pcm_to_acc_encode(char* pcmbuf, int PcmSize, unsigned char* aacBuf)
{
	unsigned int inputSample = PcmSize / (pcm_acc->m_PCMbitSize / 8);
    return faacEncEncode(pcm_acc->m_hEncoder, (int*)pcmbuf, inputSample, aacBuf, pcm_acc->m_MaxOutputBytes);
}
void pcm_to_acc_end()
{
	if(pcm_acc->m_PtrPCMBuf!=NULL)
	{
		free(pcm_acc->m_PtrPCMBuf);
		pcm_acc->m_PtrPCMBuf = NULL;
	}

	if(pcm_acc->m_PtrAACBuf!=NULL)
	{
		free(pcm_acc->m_PtrAACBuf);
		pcm_acc->m_PtrAACBuf = NULL;
	}
    if (pcm_acc->m_hEncoder)
    {
        faacEncClose(pcm_acc->m_hEncoder);
        pcm_acc->m_hEncoder = 0;
    }
    free(pcm_acc);
    pcm_acc = NULL;
}








