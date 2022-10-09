### FPGA_FND_STOPWATCH_STM32
STM32 CubeIDE와 Vivado 2020.1에서 C언어를 통해 스톱워치 기능을 구현한 FPGA와의 연동 코드

# 1. FSM (State Diagram)
![FPGA_STOPWATCH_FSM](https://user-images.githubusercontent.com/114629562/194760680-8e2d5df1-eb0b-4e60-8973-32b4a9eb583e.PNG)

# 2. 주요 동작
1) 초기 상태 : 스톱워치 정지
2) 스톱워치 정지 및 동작: 검은색 버튼(STOP/START BTN)을 통해서 스톱워치 동작(FPGA FND => min : sec, sec : msec) 및 일시 정지
3) 스톱워치 리셋: 노란색 버튼(RESET BTN)을  통해서 스톱워치 리셋 및 RESET LED ON + RESET BTN을 다시 누르면 스톱워치 정지로 복귀

# 3. STM32CubeIDE Pinout
![FPGA_STOPWATCH_pinout](https://user-images.githubusercontent.com/114629562/194761048-78c66680-f5bc-400a-b018-147d209bf865.PNG)

# 4. 동작 영상
https://user-images.githubusercontent.com/114629562/194761367-6a89c606-d8ca-4c22-8fbb-ab8f6095f173.mp4
