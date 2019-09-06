


#include "Basic_Types.h"
#include "BLMGR.h"


#include "PWM.h"
#include "GPT.h"
void Cyclic30ms(void);
void Cyclic30ms(void)
{
	static u8 TimeoutCounter = 0;
	TimeoutCounter ++;
	if(TimeoutCounter == (u8)10)
	{
		BLMGR_BluetoothStateMachine();
		TimeoutCounter = (u8)0;
		
		
	}
}
int main(void)
{
	int Count= 0;
	int start = 0;
	int Count2 = 0;
 


GPT_Timer30msInit(Cyclic30ms);
	
	BLMGR_BluetoothInit();
	BLMGR_SetReceiver(ROLE_MAPP);
    
							
	PWM_Init();
	sei();
	PWM_SetSpeed(25);

	
	while(1)
	{
		Count2 = (Count2 +1) %20;
		BLMGR_SetBattLevel(Count2 / 4);
		
		_delay_ms(100);
		Count ++;
		if(start == 0)
		{
					if(Count > 5)
					{
						BLMGR_StartDevice();

						start = 1;
					}
					
		}

	    
		
		
	}
	
	
}
