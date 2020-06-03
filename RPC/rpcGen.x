
struct result
{
   Error_t Func_Status;
};

struct param
{
   DIO_Channels_t DIO_Channel; 
   BitStatus_t pinStatus;
};

program GOLDEN_BOX_PROG
 { 
    version GOLDEN_BOX_VERS
    {
       Error_t DIO_SetPinValue(param) = 1;
    } = 1;
 } = 0x20650609;

