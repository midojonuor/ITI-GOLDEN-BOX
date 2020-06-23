
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
#include "Dio.h"

#ifdef _WIN32
#define SLEEP(seconds)      SleepEx(seconds * 1000, 1)
#else
#define SLEEP(seconds)      sleep(seconds)
#endif

#define PORT_NUMBER                     5000

static xmlrpc_value *digital_output_set(xmlrpc_env      *const envP,
                                        xmlrpc_value    *const paramArrayP,
                                        void            *const serverInfo,
                                        void            *const channelInfo) 
{
    xmlrpc_int32 channelNumber;
    //xmlrpc_int32 result;

    /* Parsing arguments */
    xmlrpc_decompose_value(envP, paramArrayP, "(i)", &channelNumber);

    /* check if any error occured while receiving parameters */
    if(envP->fault_occurred)
    {
        return NULL;
    }

    // printf("channel %d has been set\n", channelNumber);
    //DO_CH_SET(channelNumber);
    
   // result = 32;
    /* return the results */
    return xmlrpc_build_value(envP, "i", DO_CH_SET(channelNumber));
}

static xmlrpc_value *digital_output_reset(xmlrpc_env      *const envP,
                                        xmlrpc_value    *const paramArrayP,
                                        void            *const serverInfo,
                                        void            *const channelInfo) 
{
    xmlrpc_int32 channelNumber;
    //xmlrpc_int32 result;

    /* Parsing arguments */
    xmlrpc_decompose_value(envP, paramArrayP, "(i)", &channelNumber);

    /* check if any error occured while receiving parameters */
    if(envP->fault_occurred)
    {
        return NULL;
    }

    // printf("channel %d has been reset\n", channelNumber);
    //DO_CH_RESET(channelNumber);
    
    //result = 35;
    /* return the results */
    return xmlrpc_build_value(envP, "i", DO_CH_RESET(channelNumber));
}

static xmlrpc_value *digital_In_get(xmlrpc_env      *const envP,
                                        xmlrpc_value    *const paramArrayP,
                                        void            *const serverInfo,
                                        void            *const channelInfo) 
{
    xmlrpc_int32 channelNumber;
    xmlrpc_int32 result;

    /* Parsing arguments */
    xmlrpc_decompose_value(envP, paramArrayP, "(i)", &channelNumber);

    /* check if any error occured while receiving parameters */
    if(envP->fault_occurred)
    {
        return NULL;
    }

    printf("get channel %d status\n", channelNumber);
    // DIO_CH_GET(channelNumber);
    
    
    /* return the results */
    result = DI_CH_GET(channelNumber);
    return xmlrpc_build_value(envP, "i", result);
}

static xmlrpc_value *digital_Out_get(xmlrpc_env      *const envP,
                                        xmlrpc_value    *const paramArrayP,
                                        void            *const serverInfo,
                                        void            *const channelInfo) 
{
    xmlrpc_int32 channelNumber;
    //xmlrpc_int32 result;

    /* Parsing arguments */
    xmlrpc_decompose_value(envP, paramArrayP, "(i)", &channelNumber);

    /* check if any error occured while receiving parameters */
    if(envP->fault_occurred)
    {
        return NULL;
    }

  //  printf("get channel %d status\n", channelNumber);
    // DIO_CH_GET(channelNumber);
    
    
    /* return the results */
    return xmlrpc_build_value(envP, "i", DO_CH_GET(channelNumber));
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
