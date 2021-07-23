# 아두이노를 활용한 IoT 센서기술
2021.07.13 ~ 2021.07.23     
울산대학교에서 진행한 아두이노 활용 실습 파일 기록
<br><br>


## 🖱️ 내가 만든 프로젝트 - 수용가능 인원 확인
![miniproject](https://user-images.githubusercontent.com/70925962/126786827-69981cc9-d717-458c-9181-aef64087d9a6.gif)

```
PIR 센서를 이용해 사람들이 들어올때 수를 파악하여 현재 수용가능한 인원을 LCD로 보여주고
인원초과시 LED와 소리로 경고를 주는 프로젝트
```
+ 사용한 센서: PIR, LCD, RGB LED 캐소드, 푸시버턴, 능동부저
+ IoT 프로젝트 수업에서 우수 참여자 3등 🥉 


## 🚶 실생활 적용 예제
#### 보행자 신호등
![ezgif com-gif-maker (1)](https://user-images.githubusercontent.com/70925962/125879967-2125e040-e310-462d-924c-79c1ec888a27.gif)
```
운전자 신호와 보행자 신호 동시 출력    
보행자가 버튼을 누르면 즉시보행자 신호는 초록색, 운전자 신호는 빨간색으로 변경    
```

#### 타이머 프로그램
![timecounter](https://user-images.githubusercontent.com/70925962/126265917-2d89d402-6e92-4762-b53a-17315f6057e7.gif)
```
조이스틱, CDS 센서로 시작을 판단하고 5초동안 스텝모터 회전 후
LED와 소리센서로 종료를 알리는 타이머 프로그램
```

#### 비밀번호 확인

```
키패드 모듈과 LED로 비밀번호 입력을 확인
틀릴 경우와 맞는 경우, 소리 센서가 다르게 동작
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

#### Day06
```키패드 모듈, LCD, tinkercad 사용법, 7-segment```        
https://www.tinkercad.com/

> **01_keypad** 키패드 모듈로 화면 출력, LED 깜박이기             
> **02_passwordKey** 비밀번호 확인           
> **03_LCD** lcd 출력하기 예제         
> **04_LCDprint** lcd 입력받아 출력하기           
> **05_LCDemoji** lcd 이모티콘 만들어 출력하기     
> **06_LCDtemp** lcd에 온도, 습도 출력하기      
> **07_volumnControl** 가변저항으로 볼륨크기 조절      
> **08_anode** anode 타입 제어       
> **09_cathode** cathod 타입 제어      

#### Day07
```7-segment catgod type, 74HC95 shift register, RTC, bluetooth, 앱 인벤터```

> **01_cathodType** cathod 타입 출력 확인     
> **02_multiply_two** 2의 배수만 표시하기      
> **03_numberChange** 가변저항으로 출력 조절     
> **04_LsbMsb** LSB, MSB 차이     
> **05_neonsign** 74HC95로 네온사인 만들기    
> **06_binarySign** 2진수로 LED 표시     
> **07_ds1302Time** RTC DS1302 모듈로 시간 출력    
> **08_bluetooth** bluetooth 연결      


#### Day08
```앱 인벤터와 블루투스 연동, X-SCADA, modeBus, ESP32cam, 구글 티처블 머신``` 
> **01_bluetoothLED** 앱인벤터와 bluetooth 연동해 LED 불 켜기     
> **02_modeBus1** modeBus 통신테스트       

#### Day09
```구글 티처블, 프로젝트 개발```
> **01_p5** 구글 티처블 사용 마스크 인식 프로그램     
> **02_miniProject** 나만의 프로젝트 진행 - 수용 가능 인원 확인