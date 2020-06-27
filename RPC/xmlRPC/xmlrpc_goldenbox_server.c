
/* Required by xmlrpc-c/server_abyss.h */
#define WIN32_LEN_AND_MEAN


#include"stdlib.h"
#include "stdio.h"


/* including liberaries for sockets */
#ifdef _WIN32
#include "windows.h"
#include "winsock2.h"

#else
#include "unistd.h"
#endif

/* xmlrpc libraries */
#include "xmlrpc-c/base.h"
#include "xmlrpc-c/server.h"
#include "xmlrpc-c/server_abyss.h"

/* information about this build environment */
#include "config.h"

/* include raspberry pi module */
#include "goldenbox_config.h"

#include "peripherals.h"

#ifdef _WIN32
#define SLEEP(seconds)      SleepEx(seconds * 1000, 1)
#else
#define SLEEP(seconds)      sleep(seconds)
#endif

#define PORT_NUMBER                     HIL_SERVER_PORT

#if RPI_HOST
uint8_t adc_channels_value[8] = {0};
#endif

static xmlrpc_value *digital_output_set(xmlrpc_env      *const envP,
                                        xmlrpc_value    *const paramArrayP,
                                        void            *const serverInfo,
                                        void            *const channelInfo) 
{
    xmlrpc_int32 channelNumber;
    xmlrpc_int32 result = 0;

    /* Parsing arguments */
    xmlrpc_decompose_value(envP, paramArrayP, "(i)", &channelNumber);

    /* check if any error occured while receiving parameters */
    if(envP->fault_occurred)
    {
        return NULL;
    }

#if DEBUG
    printf("channel %d has been set\n", channelNumber);
#endif

#if RPI_HOST
    result = DO_CH_SET(channelNumber);
#endif

    /* return the results */
    return xmlrpc_build_value(envP, "i", result);
}

static xmlrpc_value *digital_output_reset(xmlrpc_env      *const envP,
                                        xmlrpc_value    *const paramArrayP,
                                        void            *const serverInfo,
                                        void            *const channelInfo) 
{
    xmlrpc_int32 channelNumber;
    xmlrpc_int32 result = 0;

    /* Parsing arguments */
    xmlrpc_decompose_value(envP, paramArrayP, "(i)", &channelNumber);

    /* check if any error occured while receiving parameters */
    if(envP->fault_occurred)
    {
        return NULL;
    }

#if DEBUG
    printf("channel %d has been reset\n", channelNumber);
#endif

#if RPI_HOST
    result = DO_CH_RESET(channelNumber);
#endif
    
    /* return the results */
    return xmlrpc_build_value(envP, "i", result);
}

static xmlrpc_value *digital_In_get(xmlrpc_env      *const envP,
                                        xmlrpc_value    *const paramArrayP,
                                        void            *const serverInfo,
                                        void            *const channelInfo) 
{
    xmlrpc_int32 channelNumber;
    xmlrpc_int32 result = 0;

    /* Parsing arguments */
    xmlrpc_decompose_value(envP, paramArrayP, "(i)", &channelNumber);

    /* check if any error occured while receiving parameters */
    if(envP->fault_occurred)
    {
        return NULL;
    }

#if DEBUG
    printf("channel %d get status\n", channelNumber);
#endif

#if RPI_HOST
    /* return the results */
    result = DI_CH_GET(channelNumber);
#endif
    
    return xmlrpc_build_value(envP, "i", result);
}

static xmlrpc_value *digital_Out_get(xmlrpc_env      *const envP,
                                        xmlrpc_value    *const paramArrayP,
                                        void            *const serverInfo,
                                        void            *const channelInfo) 
{
    xmlrpc_int32 channelNumber;
    xmlrpc_int32 result = 0;

    /* Parsing arguments */
    xmlrpc_decompose_value(envP, paramArrayP, "(i)", &channelNumber);

    /* check if any error occured while receiving parameters */
    if(envP->fault_occurred)
    {
        return NULL;
    }

#if DEBUG
   printf("channel %d get status\n", channelNumber);
#endif

#if RPI_HOST
    result = DO_CH_GET(channelNumber);
#endif    
    
    /* return the results */
    return xmlrpc_build_value(envP, "i", result);
}


static xmlrpc_value *goldenbox_init(xmlrpc_env      *const envP,
                                        xmlrpc_value    *const paramArrayP,
                                        void            *const serverInfo,
                                        void            *const channelInfo) 
{
    uint32_t spi_speed  = 500000;

    xmlrpc_int32 pwm_freq = 0;
    xmlrpc_int32 errorState = 0;

    /* Parsing arguments */
    xmlrpc_decompose_value(envP, paramArrayP, "(i)", &pwm_freq);

    /* check if any error occured while receiving parameters */
    if(envP->fault_occurred)
    {
        return NULL;
    }

#if DEBUG
   printf("Golden box initialized with pwm frequency %d\n", pwm_freq);
#endif

#if RPI_HOST
    DIO_Init();
    SPI_Init(spi_speed, SPI_MODE_1);
    PWM_Init(pwm_freq);
#endif

    /* return the results */
    return xmlrpc_build_value(envP, "i", errorState);
}




static xmlrpc_value *pwm_write(xmlrpc_env      *const envP,
                                        xmlrpc_value    *const paramArrayP,
                                        void            *const serverInfo,
                                        void            *const channelInfo) 
{
    xmlrpc_int32 pwm_duty = 0;
    xmlrpc_int32 channel_num = 0;
    xmlrpc_int32 errorState = 0;

    /* Parsing arguments */
    xmlrpc_decompose_value(envP, paramArrayP, "(ii)", &channel_num, &pwm_duty);

    /* check if any error occured while receiving parameters */
    if(envP->fault_occurred)
    {
        return NULL;
    }

#if DEBUG
   printf("PWM channel %d writes duty cycle %d\n", channel_num, pwm_duty);
#endif

#if RPI_HOST
    PWM_Write(channel_num, pwm_duty);
#endif

    /* return the results */
    return xmlrpc_build_value(envP, "i", errorState);
}



static xmlrpc_value *adc_read_channel(xmlrpc_env      *const envP,
                                        xmlrpc_value    *const paramArrayP,
                                        void            *const serverInfo,
                                        void            *const channelInfo) 
{
    xmlrpc_int32 channel_num = 0;
    xmlrpc_int32 result = 0;

    uint8_t indx = 0;

    /* Parsing arguments */
    xmlrpc_decompose_value(envP, paramArrayP, "(i)", &channel_num);

    /* check if any error occured while receiving parameters */
    if(envP->fault_occurred)
    {
        return NULL;
    }

#if DEBUG
   printf("Assert on ADC channel number %d \n", channel_num);
#endif

#if RPI_HOST
    ADC_AllChannelsRead(adc_channels_value, 8);
    result = (xmlrpc_int32 )adc_channels_value[channel_num];

    for(indx = 0; indx < 8; ++indx)
    {
        printf("Channel %d = %d\n", indx, adc_channels_value[indx]);
    }
#endif

    /* return the results */
    return xmlrpc_build_value(envP, "i", result);
}



int
main(int const argc, const char **argv)
{

    struct xmlrpc_method_info3 const DigitalSetMethondInfo = {
        
        "DO_CH_SET",            /* Method name */
        &digital_output_set,     /* Method function */
    };

    struct xmlrpc_method_info3 const DigitalResetMethondInfo = {
        "DO_CH_RESET",
        &digital_output_reset
    };

    struct xmlrpc_method_info3 const DigitalInGetMethondInfo = {
        "DI_CH_GET",
        &digital_In_get
    };

    struct xmlrpc_method_info3 const DigitalOutGetMethondInfo = {
        "DO_CH_GET",
        &digital_Out_get
    };

    struct xmlrpc_method_info3 const GoldenboxInitMethodInfo = {
        "Goldenbox_Init",
        &goldenbox_init
    };
    
    struct xmlrpc_method_info3 const PWM_WriteMethodInfo = {
        "PWM_Write",
        &pwm_write
    };

    struct xmlrpc_method_info3 const ADC_ReadMethodInfo = {
        "ADC_Read",
        &adc_read_channel
    };

    xmlrpc_server_abyss_parms serverParam;
    xmlrpc_registry *registeryP;
    xmlrpc_env env;


    xmlrpc_env_init(&env);

    registeryP = xmlrpc_registry_new(&env);

    if(env.fault_occurred)
    {
        printf("Faild to regster new environment.\n%s\n", env.fault_string);
        exit(1);
    }
    
    xmlrpc_registry_add_method3(&env, registeryP, &DigitalOutGetMethondInfo);
    xmlrpc_registry_add_method3(&env, registeryP, &DigitalInGetMethondInfo);
    xmlrpc_registry_add_method3(&env, registeryP, &DigitalSetMethondInfo);
    xmlrpc_registry_add_method3(&env, registeryP, &DigitalResetMethondInfo);

    xmlrpc_registry_add_method3(&env, registeryP, &GoldenboxInitMethodInfo);
    xmlrpc_registry_add_method3(&env, registeryP, &PWM_WriteMethodInfo);
    xmlrpc_registry_add_method3(&env, registeryP, &ADC_ReadMethodInfo);
    
    if(env.fault_occurred)
    {
        printf("Faild to add environment\n%s\n", env.fault_string);
        exit(1);
    }


    serverParam.config_file_name    = NULL;        /* Select the modern normal API */
    serverParam.registryP           = registeryP;
    serverParam.port_number         = PORT_NUMBER;
    serverParam.log_file_name       = "/tmp/xmlrpc_log";
    
    DIO_Init();
    printf("Server up and listening.........\n");

    xmlrpc_server_abyss(&env, &serverParam, XMLRPC_APSIZE(log_file_name));

    if(env.fault_occurred)
    {
        printf("abyss server failed.\n %s\n", env.fault_string);
        exit(1);
    }

    return 0;

}
