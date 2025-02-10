# Compiler ve bayraklar
CC = gcc
CFLAGS = -I./inc \
         -I../Abstract_MotorDriver \
         -I../Abstract_MotorDriver/IBrakeAndDirection/inc \
         -I../Abstract_MotorDriver/IBrakeStatus/inc \
         -I../Abstract_MotorDriver/IDirectionStatus/inc \
         -I../Abstract_MotorDriver/IHALLA/inc \
         -I../Abstract_MotorDriver/IHALLB/inc \
         -I../Abstract_MotorDriver/IHALLC/inc \
         -I../Abstract_MotorDriver/IHALLWheelSpeed/inc \
         -I../Abstract_MotorDriver/IIndicatorBdrStatus/inc \
         -I../Abstract_MotorDriver/IIndicatorSpeedStatus/inc \
         -I../Abstract_MotorDriver/IMotorDriveError/inc \
         -I../Abstract_MotorDriver/IPwmStep/inc \
         -I../Abstract_MotorDriver/IRawSpeed/inc \
         -I../Abstract_MotorDriver/ISpeedStatus/inc \
		 \
         -I../Abstract_SmartGateDriver \
         -I../Abstract_SmartGateDriver/IDRV8353/inc \
		 \
		 -I../Abstract_CoreManager \
		 -I../Abstract_CoreManager/IExternalInterruptStatus/inc \
		 -I../Abstract_CoreManager/IGPIOStatus/inc \
		 -I../Abstract_CoreManager/ITimerInterruptStatus/inc \
		 \
		 -I../Abstract_VehComManager \
		 -I../Abstract_VehComManager/IBdr/inc \
		 -I../Abstract_VehComManager/IIndicator/inc \
		 -I../Abstract_VehComManager/ISpeed/inc \
		 -I../Abstract_VehComManager/IWheelSpeed/inc \
		 \
		 -I../BrakeAndDirectionManager/inc \
         -I../GateDriverController/inc \
         -I../HALLSensorConfiguration/inc \
         -I../InterruptHandlerManager/inc \
         -I../MotorDriverCommProxy/inc \
         -I../MotorDriverControlManager/inc \
         -I../MotorDriverDcmProxy/inc \
         -I../PWMConfiguration/inc \
         -I../SpeedControlManager/inc \
		 \
	     -Wall -Wextra -g

# Kaynak dosyalar ve çıktı dosyası
SRC = ./build/main.c \
	  ./src/ECUStateManager_SM.c \
	  ./src/ECUStateManager_toStringHelper.c \
	  ./src/ECUStateManager.c \
	  \
	  ../Abstract_MotorDriver/IBrakeAndDirection/src/IBrakeAndDirection.c \
	  ../Abstract_MotorDriver/IBrakeStatus/src/IBrakeStatus.c \
	  ../Abstract_MotorDriver/IDirectionStatus/src/IDirectionStatus.c \
	  ../Abstract_MotorDriver/IHALLA/src/IHALLA.c \
	  ../Abstract_MotorDriver/IHALLB/src/IHALLB.c \
      ../Abstract_MotorDriver/IHALLC/src/IHALLC.c \
      ../Abstract_MotorDriver/IHALLWheelSpeed/src/IHALLWheelSpeed.c \
      ../Abstract_MotorDriver/IIndicatorBdrStatus/src/IIndicatorBdrStatus.c \
      ../Abstract_MotorDriver/IIndicatorSpeedStatus/src/IIndicatorSpeedStatus.c \
      ../Abstract_MotorDriver/IMotorDriveError/src/IMotorDriveError.c \
      ../Abstract_MotorDriver/IPwmStep/src/IPwmStep.c \
      ../Abstract_MotorDriver/IRawSpeed/src/IRawSpeed.c \
      ../Abstract_MotorDriver/ISpeedStatus/src/ISpeedStatus.c \
	  \
	  ../Abstract_SmartGateDriver/IDRV8353/src/IDRV8353.c \
	  \
	  ../Abstract_CoreManager/IExternalInterruptStatus/src/IExternalInterruptStatus.c \
      ../Abstract_CoreManager/IGPIOStatus/src/IGPIOStatus.c \
	  ../Abstract_CoreManager/IGPIOStatus/src/IGPIOStatus_HAL_Impl.c \
      ../Abstract_CoreManager/ITimerInterruptStatus/src/ITimerInterruptStatus.c \
	  \
	  ../Abstract_VehComManager/IBdr/src/IBdr.c \
	  ../Abstract_VehComManager/IIndicator/src/IIndicator.c \
	  ../Abstract_VehComManager/ISpeed/src/ISpeed.c \
	  ../Abstract_VehComManager/IWheelSpeed/src/IWheelSpeed.c \
	  \
	  ..\BrakeAndDirectionManager\src\BrakeAndDirectionManager.c \
	  ..\BrakeAndDirectionManager\src\BrakeAndDirectionManager_ruInitialisation.c \
	  ..\BrakeAndDirectionManager\src\BrakeAndDirectionManager_ruRefresh.c \
	  \
	  ../GateDriverController/src/GateDriverController.c \
	  ../GateDriverController/src/GateDriverController_ruInitialisation.c \
	  ../GateDriverController/src/GateDriverController_ruRefresh.c \
	  \
	  ..\HALLSensorConfiguration\src\HALLSensorConfiguration.c \
	  ..\HALLSensorConfiguration\src\HALLSensorConfiguration_ruInitialisation.c \
	  ..\HALLSensorConfiguration\src\HALLSensorConfiguration_ruUpdateA.c \
	  ..\HALLSensorConfiguration\src\HALLSensorConfiguration_ruUpdateB.c \
	  ..\HALLSensorConfiguration\src\HALLSensorConfiguration_ruUpdateC.c \
	  \
	  ..\InterruptHandlerManager\src\InterruptHandlerManager.c \
	  ..\InterruptHandlerManager\src\InterruptHandlerMAnager_ruInitialisation.c \
	  ..\InterruptHandlerManager\src\InterruptHandlerManager_ruExternalTrigger.c \
	  ..\InterruptHandlerManager\src\InterruptHandlerManager_ruTimerTrigger.c \
	  \
	  ..\MotorDriverCommProxy\src\MotorDriverCommProxy.c \
	  ..\MotorDriverCommProxy\src\MotorDriverCommProxy_ruRefresh.c \
	  ..\MotorDriverCommProxy\src\MotorDriverCommProxy_ruUpdateIndicator.c \
	  ..\MotorDriverCommProxy\src\MotorDriverCommProxy_ruUpdateWheelSpeed.c \
	  \
	  ..\MotorDriverControlManager\src\MotorDriverControlManager.c \
	  ..\MotorDriverControlManager\src\MotorDriverControlManager_ruInitialisation.c \
	  ..\MotorDriverControlManager\src\MotorDriverControlManager_ruRefresh.c \
	  \
	  ..\MotorDriverDcmProxy\src\MotorDriverDcmProxy.c \
	  ..\MotorDriverDcmProxy\src\MotorDriverDcmProxy_ruCollect.c \
	  ..\MotorDriverDcmProxy\src\MotorDriverDcmProxy_ruRefresh.c \
	  \
	  ..\PWMConfiguration\src\PWMConfiguration.c \
	  ..\PWMConfiguration\src\PWMConfiguration_ruInitialisation.c \
	  ..\PWMConfiguration\src\PWMConfiguration_ruRefresh.c \
	  ..\PWMConfiguration\src\PWMConfiguration_ruUpdate.c \
	  \
	  ..\SpeedControlManager\src\SpeedControlManager.c \
	  ..\SpeedControlManager\src\SpeedControlManager_ruInitialisation.c \
	  ..\SpeedControlManager\src\SpeedControlManager_ruRefresh.c \
	  ..\SpeedControlManager\src\SpeedControlManager_ruBrakeUpdate.c \
	  ..\SpeedControlManager\src\SpeedControlManager_ruUpdate.c 
OUT = ./build/main.exe

# Varsayılan hedef
all: $(OUT)

# Çıktı dosyasını oluşturma
$(OUT): $(SRC)
	$(CC) $(CFLAGS) -o $(OUT) $(SRC)

# Temizlik
clean:
	if exist build\*.exe del /Q build\*.exe

