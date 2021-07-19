# :raised_hands: 아두이노를 활용한 IoT 센서기술
2021.07.13 ~ 2021.07.23     
울산대학교에서 진행한 아두이노 활용 실습 파일 기록

## 실생활 적용 예제
#### 보행자 신호등
![ezgif com-gif-maker (1)](https://user-images.githubusercontent.com/70925962/125879967-2125e040-e310-462d-924c-79c1ec888a27.gif)
```
운전자 신호와 보행자 신호 동시 출력    
보행자가 버튼을 누르면 즉시보행자 신호는 초록색, 운전자 신호는 빨간색으로 변경    
```
## :file_folder: 파일별 기록    
#### Day01
```C언어 기초, C언어 사용 아두이노 LED 실습 진행```

#### Day02
```C언어 반복문, switch 개념+LED 학습```
> **3_PullDown** pulldown 구현    
> **4_Debounce** debounce 구현 > 버튼 클릭할때마다 LED toggle    
> **5_Debounce_3LED** 3개의 LED로 debounce 확인    
> **6_analogLight** 아날로그 사용 RGB 출력    
> **7_analogRGB** 6번 함수 구현     
> **8_analogBrightness** 아날로그 사용 RGB 밝기 변화 구현     
> **9_analogRandom** 랜덤 RGB 색상 출력     
> **10_analogRandomColor** random, switch 이용 색상 출력     

#### Day03
```Analog, 가변저항, 피에조 스피커, Arduino 함수, 배열, 이차원배열, 구조체, 클래스 개념, 인터럽트 ```
> **01_PWDtoLEDlight** 아날로그와 전압값에 따른 LED 밝기 조절     
> **02_6LEDlight map** 함수 이용 6개의 LED 레벨별 분류     
> **03_3LEDlight** 가변저항으로 N개의 LED 밝기 조절     
> **04_tone** tone 사용, 도~도 출력      
> **05_tone_pitchesHeader** "pitches.h" 파일 사용, 도,레,미,...도 출력      
> **06_tone_madeSong** 똑같아요 악보 출력     
> **07_tone_switch** 스위치를 사용해 도레미파 출력     
> **08_minmaxFunction** function 예제 - 최대, 최솟값 구하기     
> **09_arrMinMaxSum** 배열 예제 - 최대, 최소, 합 구하기      
> **10_interrupt** interrupt 사용 예제     
> **11_interrupt_delayTime** interrupt 실행시 delay 주기    

#### Day04
```인터럽트 적용, 온도 센서, 밝기 센서 ```
> **01_trafficLight** 보행자 신호등 만들기    
> **02_msTimer** 타이머 인터럽트 활용 예제     
> **03_sensorLight** 센서로 밝기 측정하기     
> **04_sensorLightChange** 주변 밝기에 따라 LED 조절        
> **05_sensorSound** 주변 밝기에 따라 소리 조절           

#### Day05
``` 기울임 센서, 소리 센서, 액추에이터 활용(모터, 서보모터, 스텝 모터, 조이스틱) ```
> **01_tiltSwitch** 기울임 센서 이용 지진 경보 알림          
> **02_soundSensor1** 소리 센서 사용 예제         
> **03_soundSensor2** 소리 센서 사용 예제 2(시간별 소음 측정)            
> **04_servoMotor** 서보모터 사용 예제        
> **05_servoControl** 가변저항으로 서보모터 조절      
> **06_stepMotor** 스텝모터 예제      
> **07_stepMotor2** 스텝모터 예제 2 (회전 횟수 입력받기)         
> **08_joyStick** 조이스틱 예제            
> **09_joyStickLED** 조이스틱과 스위치로 LED 조절           
> **10_joyStickServoControl** 조이스틱 x축 이동으로 서보모터 회전          
> **11_gameStopwatch** game 스탑워치 활용 예제            
