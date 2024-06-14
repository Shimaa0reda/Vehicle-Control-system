/*
 ============================================================================
 Name        : PROJECT_1.c
 Author      : SHIMAA REDA
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef unsigned char uint8;
/*if the value of #define 1 compile/run the code lines that are related to the “Engine
Temperature Controller and vice versa when its value is zero*/
#define WITH_ENGINE_TEMP_CONTROLLER 1
//define a structure containing all the vehicle specifications
struct characteristics
{
	char engine_state[4];
	char AC_state[4];
	char state[30];
	int vehicle_speed;
	float room_temp;
	char engine_temp_controller[4];
	float engine_temp;
}emp1;
// define a pointer to the object of the structure
struct characteristics*ptr=&emp1;

// fun to print the current specifications of the vehicle
void print()
{
	printf("engine is %s \n",ptr->engine_state);
	printf("AC is %s\n",ptr->AC_state);
	printf("vehicle speed = %d KM/H\n",ptr->vehicle_speed);
	printf("room temp = %f C\n",ptr->room_temp);
	//it is a condition to make these lines run or not depending on #define value
#if(WITH_ENGINE_TEMP_CONTROLLER)
	{
		printf("engine temperature controller is %s \n",ptr->engine_temp_controller);
		printf("engine temperature = %f C\n\n\n ",ptr->engine_temp);
	}
#endif
}

// fun to ask the user again what to do if he chose to turn off the system
char turn_off(char*a)
{//retake the choice of the user and return if to the main fun
	printf("a.turn on the vehicle engine\n");
	printf("b.turn off the vehicle engine\n");
	printf("c.quit the engine\n\n\n");
	fflush(stdout);
	scanf(" %c",&*a);
	return *a ;
}

//fun called when the user choose to turn on the system
char turn_on(char*a)
{
	char b;
	//Continuously reprint set sensor menu as long as the system is on
	while(1)
	{
		printf("Sensors set menu\n");
		printf("a.turn off the vehicle engine\n");
		printf("b.set the traffic light\n");
		printf("c.set the room temperature\n");
#if(WITH_ENGINE_TEMP_CONTROLLER)
		{
			printf("d.set the engine temperature\n\n\n");
		}
#endif
		fflush(stdout);
		scanf(" %c",&*a);
		// if the user chose to turn off the system ,call turn off fun
		if(*a=='a'||*a=='A')
		{
			*a=turn_off(&*a);
			return *a;
		}
		/*if the user chose to set the traffic light first turn
	the engine on and then take the color as input from the user*/
		else if(*a=='b'||*a=='B')
		{
			strcpy(ptr->engine_state,"on");
			printf("set the color of the traffic light\n");
			fflush(stdout);
			scanf(" %c",&b);

			while(b!='g'||b!='G'||b!='o'||b!='O'||b!='r'||b!='R')
			{
				printf("set the color of the traffic light\n");
				fflush(stdout);
				scanf(" %c",&b);
			}
			/*According to the color that the user will choose,
			the speed of the vehicle will be determined*/
			if(b=='g'||b=='G')
			{
				ptr->vehicle_speed=100;
			}
			else if(b=='o'||b=='O')
			{
				ptr->vehicle_speed=30;
			}
			else if(b=='r'||b=='R')
			{
				ptr->vehicle_speed=0;
			}

		}
		/* if the user chose to set the room temperature first turn
		the engine on and then take the temperature as input from the user*/
		else if(*a=='c'||*a=='C')
		{
			strcpy(ptr->engine_state,"on");
			printf("set the temperature of the room\n");
			fflush(stdout);
			scanf(" %f",&emp1.room_temp);
			/*According to the temperature that the user will enter,
		AC status and room temperature will be determined*/
			if((emp1.room_temp)<10)
			{
				strcpy(ptr->AC_state,"on");
				ptr->room_temp =20;
			}
			else if((ptr->room_temp)>30)
			{
				strcpy(ptr->AC_state,"on");
				ptr->room_temp =20;
			}
			else
			{
				strcpy(ptr->AC_state,"off");
			}
		}
		/* if the user chose to set the engine temperature first turn
	the engine on and then take the temperature as input from the user*/
		else if(*a=='d'||*a=='D')
		{//it is a condition to make these lines run or not depending on #define value
			if(WITH_ENGINE_TEMP_CONTROLLER)
			{
				strcpy(ptr->engine_state,"on");
				printf("set the temperature of the engine\n");
				fflush(stdout);
				scanf(" %f",&ptr->engine_temp);
				/*According to the temperature that the user will enter,
			engine temperature controller status and engine temperature  will be determined*/
				if((ptr->engine_temp) <100)
				{
					strcpy(ptr->engine_temp_controller,"on");
					ptr->engine_temp=125;
				}
				else if((ptr->engine_temp) >150)
				{
					strcpy(ptr->engine_temp_controller,"on");
					ptr->engine_temp=125;
				}
				else{
					strcpy(ptr->engine_temp_controller,"off");
				}
			}
		}
		else
		{
			printf("Sensors set menu\n");
			printf("a.turn off the vehicle engine\n");
			printf("b.set the traffic light\n");
			printf("c.set the room temperature\n");
#if(WITH_ENGINE_TEMP_CONTROLLER)
			{
				printf("d.set the engine temperature\n\n\n");
			}
#endif
			fflush(stdout);
			scanf(" %c",&*a);
			continue;
		}
		if(ptr->vehicle_speed==30)
		{
			strcpy(ptr->AC_state,"on");
			ptr->room_temp =ptr->room_temp *(5.0/4)+1;
#if(WITH_ENGINE_TEMP_CONTROLLER)
			{
				strcpy(ptr->engine_temp_controller,"on");
				ptr->engine_temp = ptr->engine_temp *(5.0/4)+1;
			}
#endif
		}
		print();
	}
}

int main()
{
	char(*turnoff)(char*)=turn_off;
	char(*turnon)(char*)=turn_on;
	uint8 flag =0;
	char choice;
	//initialize the values of the vehicle specifications
	strcpy(ptr->AC_state,"off");
	strcpy(ptr->engine_temp_controller,"off");
	strcpy(ptr->engine_state,"on");
	ptr->vehicle_speed=0;
	ptr->engine_temp=120;
	ptr->room_temp=20;
	strcpy(ptr->state,"aa");

	printf("a.turn on the vehicle engine\n");
	printf("b.turn off the vehicle engine\n");
	printf("c.quit the engine\n\n\n");
	fflush(stdout);
	scanf(" %c",&choice);
	//Continuously do these lines as long as the main fun compile
	while(1)
	{
		switch(choice)
		{
		case'a':
		case'A':
			flag=0;
			strcpy(ptr->state,"turn on the vehicle engine");
			printf("%s\n\n",ptr->state);
			strcpy(ptr->engine_state,"on");
			choice=turnon(&choice);
			break;

		case'b':
		case'B':
			flag=0;
			strcpy(ptr->engine_state,"off");
			strcpy(ptr->state,"turn off the vehicle engine");
			printf("%s\n\n",ptr->state);
			choice =turnoff(&choice);
			break;

		case'c':
		case'C':
			strcpy(ptr->state,"quit the system");
			printf("%s",ptr->state);
			//this variable =1 only when the user ask to quit the system
			flag=1;
			break;
		default:
			printf("a.turn on the vehicle engine\n");
			printf("b.turn off the vehicle engine\n");
			printf("c.quit the engine\n\n\n");
			fflush(stdout);
			scanf(" %c",&choice);
		}
		//Condition to test if the user wants to quit the system
		if(flag==1)
			break;
	}
	return 0;
}
