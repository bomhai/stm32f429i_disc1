##### 이 프로젝트 touchgfx_00_start 는 TouchGFX 와 STM32CubeIDE 를 이용하여 LCD 를 처음 구동하기 위하여 작업되었습니다.
------------------------------------
###### 목차
>1. 프로젝트 생성
>2. 각 기능 설정 및 코드 생성
>3. 헤더파일 참조 폴더 설정
>4. TouchGFX 이용하여 LCD 이미지 설정
>5. 소스 코드 추가
>6. 컴파일 및 바이너리 다운로드
------------------------------------
##### 추가 코드
###### [main.c](Core/Src/main.c)
```c
#include "ili9341/ili9341.h"
#include "Common/lcd.h
```
```c
static LCD_DrvTypeDef* LcdDrv;
```
```c
LcdDrv = &ili9341_drv;
LcdDrv->Init();
LcdDrv->DisplayOff();
```

###### [TouchGFXHAL.cpp](TouchGFX/target/TouchGFXHAL.cpp)
```c
#include "touchgfx/hal/OSWrappers.hpp"
extern "C"{
    void    LCD_IO_WriteReg(uint8_t Reg);
}
```
```c
void TouchGFXHAL::taskEntry()
{
	enableLCDControllerInterrupt();
	enableInterrupts();

	OSWrappers::waitForVSync();
	backPorchExited();

	LCD_IO_WriteReg(0x29);
	for(;;)
	{
		OSWrappers::waitForVSync();
		backPorchExited();
	}
}
```

###### [TouchGFXHAL.hpp](TouchGFX/target/TouchGFXHAL.hpp)
```c
virtual void taskEntry();
```

###### [freertos.c](Core/Src/freertos.c)
```c
osThreadId touchGFXTaskHandle;
```
```c
void TouchGFX_Task(void const * argument);
```
```c
osThreadDef(touchTask, TouchGFX_Task, osPriorityNormal, 0, 4086);
touchGFXTaskHandle = osThreadCreate(osThread(touchTask), NULL);
```
```c
HAL_GPIO_TogglePin(GPIOG, GPIO_PIN_13);
osDelay(500);
```
------------------------------------
##### Link
Blog : [[STM32F429I-DISC1] TouchGFX + STM32CubeIDE 이용하여 LCD 구동하기](https://bomhai.com/27)

Youtube : 

[![[STM32F429I-DISC1] TouchGFX + STM32CubeIDE 이용하여 LCD 구동하기](http://img.youtube.com/vi/__wggrTcx_0/0.jpg)](https://youtu.be/__wggrTcx_0?t=0s)
