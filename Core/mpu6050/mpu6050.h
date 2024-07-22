//
// Created by Lenovo on 2024/1/24.
//

#ifndef MPU6050_TRY1_MPU6050_H
#define MPU6050_TRY1_MPU6050_H

#include "main.h"

#define SAMPLE_RATE_DRIVER    0x19 //采样分频存 采样频率=陀螺仪输出频率/(1+SMPRT_DIV)
#define CONFIG         0x1A  //低通滤波频率 例:0xo5->5Hz
#define GYRO_CONFIG    0x1B  //陀螺仪自检和配置陀螺仪量程,典型值:
#define ACCEL_CONFIG   0x1C  //加速度自检,配置计量范围,高通滤波

#define ACCEL_XOUT_H   0x3B  //存储最近的x,y,z轴加速度感应器测量值
#define ACCEL_XOUT_L   0x3C
#define ACCEL_YOUT_H   0x3D
#define ACCEL_YOUT_L   0x3E
#define ACCEL_ZOUT_H   0x3F
#define ACCEL_ZOUT_L   0x40

#define TEMP_OUT_H   0x41  // 存储的最近温度传感器的测量值 */
#define TEMP_OUT_L   0x42

#define GYRO_XOUT_H    0x43   //存储最近的x,y,z轴陀螺仪测量值
#define GYRO_XOUT_L    0x44
#define GYRO_YOUT_H    0x45
#define GYRO_YOUT_L    0x46
#define GYRO_ZOUT_H    0x47
#define GYRO_ZOUT_L    0x48

#define PWR_MGMT_1     0x6B   //电源管理,典型值:0x00(正常启用)
#define WHO_AM_I       0x75   //IIc地址寄存器(默认数值0x68,只读)
#define MPU6050_ADDR   0xD0   //MPU6050手册上的地址,可用search函数搜索

typedef struct {
    //角速度
    float Accel_X;
    float Accel_Y;
    float Accel_Z;
    //角度
    float Gyro_X;
    float Gyro_Y;
    float Gyro_Z;
    //温度
    float Temp;
}MPU6050DATATYPE;

extern MPU6050DATATYPE MPU6050_Data;
extern I2C_HandleTypeDef hi2c1;
extern I2C_HandleTypeDef hi2c2;
int8_t  Sensor_I2C1_Read(uint16_t DevAddr,uint16_t MemAddr,uint8_t *Data1,uint8_t DataLen);
int8_t Sensor_I2C1_Write(uint16_t DevAddr,uint16_t MemAddr,uint8_t *Data2,uint8_t DataLen);
int16_t Sensor_I2C1_Search(void);
int8_t MPU6050_Init(int16_t Addr);
void MPU6050_Read_Accel(void);
void MPU6050_Read_Gyro(void);
void MPU6050_Read_Temp(void);
#endif //MPU6050_TRY1_MPU6050_H
