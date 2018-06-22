#机械手项目日志

##2018—6-20

优化了限位开关程序，不会发生机械臂撞击开关：
>具体是在Key_Limit.c中文件中加入了只允许触发单次。

##2018-6-21 修改了4个bug

解决的问题

1. 加上了打胶机开关
2. 加上了下降的动作
3. 每次运作完复位一次
4. 复位后的减速卡顿问题

##2018-6-22 修改按键

1. 加入了开始的按键保护，如果出现连按，下次机械臂直接进行。
    
        start_key_fla=0;
        ***
        //主程序开始时
        if (start_key_fal>0)
        {  
            main_fla=
        }
        *******
        //机械臂运行的最后一个复位任务中
        if (start_key_fal==1)
            start_key_fal=0;
        else start_key_fal=1;
        
        main_fla=0x0001;
        ***
        //开始按键中
        if(start_key_fal==0)main_fal=0x0001;
        start_key_fal++;
        ***
        //在复位按键中
        start_key_fal=0;   

2. 优化代码，提高了运行速度
       
    