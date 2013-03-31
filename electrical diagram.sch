<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE eagle SYSTEM "eagle.dtd">
<eagle version="6.0">
<drawing>
<settings>
<setting alwaysvectorfont="no"/>
<setting verticaltext="up"/>
</settings>
<grid distance="0.1" unitdist="inch" unit="inch" style="lines" multiple="1" display="no" altdistance="0.01" altunitdist="inch" altunit="inch"/>
<layers>
<layer number="1" name="Top" color="4" fill="1" visible="no" active="no"/>
<layer number="16" name="Bottom" color="1" fill="1" visible="no" active="no"/>
<layer number="17" name="Pads" color="2" fill="1" visible="no" active="no"/>
<layer number="18" name="Vias" color="2" fill="1" visible="no" active="no"/>
<layer number="19" name="Unrouted" color="6" fill="1" visible="no" active="no"/>
<layer number="20" name="Dimension" color="15" fill="1" visible="no" active="no"/>
<layer number="21" name="tPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="22" name="bPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="23" name="tOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="24" name="bOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="25" name="tNames" color="7" fill="1" visible="no" active="no"/>
<layer number="26" name="bNames" color="7" fill="1" visible="no" active="no"/>
<layer number="27" name="tValues" color="7" fill="1" visible="no" active="no"/>
<layer number="28" name="bValues" color="7" fill="1" visible="no" active="no"/>
<layer number="29" name="tStop" color="7" fill="3" visible="no" active="no"/>
<layer number="30" name="bStop" color="7" fill="6" visible="no" active="no"/>
<layer number="31" name="tCream" color="7" fill="4" visible="no" active="no"/>
<layer number="32" name="bCream" color="7" fill="5" visible="no" active="no"/>
<layer number="33" name="tFinish" color="6" fill="3" visible="no" active="no"/>
<layer number="34" name="bFinish" color="6" fill="6" visible="no" active="no"/>
<layer number="35" name="tGlue" color="7" fill="4" visible="no" active="no"/>
<layer number="36" name="bGlue" color="7" fill="5" visible="no" active="no"/>
<layer number="37" name="tTest" color="7" fill="1" visible="no" active="no"/>
<layer number="38" name="bTest" color="7" fill="1" visible="no" active="no"/>
<layer number="39" name="tKeepout" color="4" fill="11" visible="no" active="no"/>
<layer number="40" name="bKeepout" color="1" fill="11" visible="no" active="no"/>
<layer number="41" name="tRestrict" color="4" fill="10" visible="no" active="no"/>
<layer number="42" name="bRestrict" color="1" fill="10" visible="no" active="no"/>
<layer number="43" name="vRestrict" color="2" fill="10" visible="no" active="no"/>
<layer number="44" name="Drills" color="7" fill="1" visible="no" active="no"/>
<layer number="45" name="Holes" color="7" fill="1" visible="no" active="no"/>
<layer number="46" name="Milling" color="3" fill="1" visible="no" active="no"/>
<layer number="47" name="Measures" color="7" fill="1" visible="no" active="no"/>
<layer number="48" name="Document" color="7" fill="1" visible="no" active="no"/>
<layer number="49" name="Reference" color="7" fill="1" visible="no" active="no"/>
<layer number="51" name="tDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="52" name="bDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="91" name="Nets" color="2" fill="1" visible="yes" active="yes"/>
<layer number="92" name="Busses" color="1" fill="1" visible="yes" active="yes"/>
<layer number="93" name="Pins" color="2" fill="1" visible="no" active="yes"/>
<layer number="94" name="Symbols" color="4" fill="1" visible="yes" active="yes"/>
<layer number="95" name="Names" color="7" fill="1" visible="yes" active="yes"/>
<layer number="96" name="Values" color="7" fill="1" visible="yes" active="yes"/>
<layer number="97" name="Info" color="7" fill="1" visible="yes" active="yes"/>
<layer number="98" name="Guide" color="6" fill="1" visible="yes" active="yes"/>
</layers>
<schematic xreflabel="%F%N/%S.%C%R" xrefpart="/%S.%C%R">
<libraries>
<library name="rov">
<packages>
<package name="POLOLU_MOTOR">
<pad name="VCC" x="-3.81" y="3.81" drill="0.8" shape="square"/>
<pad name="PWM" x="-11.43" y="1.27" drill="0.8" shape="square"/>
<pad name="M+" x="-3.81" y="0" drill="0.8" shape="square"/>
<pad name="A" x="-11.43" y="-2.54" drill="0.8" shape="square"/>
<pad name="B" x="-11.43" y="-6.35" drill="0.8" shape="square"/>
<pad name="M-" x="-3.81" y="-3.81" drill="0.8" shape="square"/>
<pad name="GND" x="-3.81" y="-7.62" drill="0.8" shape="square"/>
</package>
<package name="MOTOR">
<pad name="+" x="-7.62" y="0" drill="0.8" shape="square"/>
<pad name="-" x="7.62" y="0" drill="0.8" shape="square"/>
</package>
<package name="ROV_MCU">
<pad name="VCC" x="-7.62" y="10.16" drill="0.8" shape="square"/>
<pad name="GND" x="-7.62" y="7.62" drill="0.8" shape="square"/>
<pad name="TX1" x="-7.62" y="5.08" drill="0.8" shape="square"/>
<pad name="RX1" x="-7.62" y="2.54" drill="0.8" shape="square"/>
<pad name="PWM1" x="-7.62" y="-3.81" drill="0.8" shape="square"/>
<pad name="A1" x="-5.08" y="-3.81" drill="0.8" shape="square"/>
<pad name="B1" x="-2.54" y="-3.81" drill="0.8" shape="square"/>
<pad name="PWM2" x="1.27" y="-3.81" drill="0.8" shape="square"/>
<pad name="A2" x="3.81" y="-3.81" drill="0.8" shape="square"/>
<pad name="B2" x="6.35" y="-3.81" drill="0.8" shape="square"/>
<pad name="PWM3" x="10.16" y="-3.81" drill="0.8" shape="square"/>
<pad name="A3" x="12.7" y="-3.81" drill="0.8" shape="square"/>
<pad name="B3" x="15.24" y="-3.81" drill="0.8" shape="square"/>
<pad name="PWM4" x="19.05" y="-3.81" drill="0.8" shape="square"/>
<pad name="A4" x="21.59" y="-3.81" drill="0.8" shape="square"/>
<pad name="B4" x="24.13" y="-3.81" drill="0.8" shape="square"/>
<pad name="SERVO4" x="24.13" y="0" drill="0.8" shape="square"/>
<pad name="SERVO3" x="24.13" y="3.81" drill="0.8" shape="square"/>
<pad name="SERVO2" x="24.13" y="6.35" drill="0.8" shape="square"/>
<pad name="SERVO1" x="24.13" y="8.89" drill="0.8" shape="square"/>
<pad name="TX2" x="-7.62" y="0" drill="0.8" shape="square"/>
<pad name="RX2" x="-7.62" y="-1.27" drill="0.8" shape="square"/>
<pad name="DHT22" x="24.13" y="-1.905" drill="0.8" shape="square"/>
</package>
<package name="SERVO">
<pad name="VCC" x="-3.81" y="6.35" drill="0.8" shape="square"/>
<pad name="GND" x="-3.81" y="2.54" drill="0.8" shape="square"/>
<pad name="SIGNAL" x="-3.81" y="-1.27" drill="0.8" shape="square"/>
</package>
<package name="IMU">
<pad name="VCC" x="-10.16" y="7.62" drill="0.8" shape="square"/>
<pad name="GND" x="-10.16" y="-1.27" drill="0.8" shape="square"/>
<pad name="RX" x="11.43" y="-1.27" drill="0.8" shape="square"/>
<pad name="TX" x="11.43" y="7.62" drill="0.8" shape="square"/>
</package>
<package name="DHT22">
<pad name="VCC" x="-15.24" y="5.08" drill="0.8" shape="square"/>
<pad name="GND" x="-15.24" y="1.27" drill="0.8" shape="square"/>
<pad name="SIGNAL" x="-15.24" y="-1.27" drill="0.8" shape="square"/>
</package>
</packages>
<symbols>
<symbol name="POLOLU_MOTOR">
<description>Pololu Motor Driver</description>
<wire x1="-25.4" y1="0" x2="-25.4" y2="-17.78" width="0.254" layer="94"/>
<wire x1="-25.4" y1="-17.78" x2="-5.08" y2="-17.78" width="0.254" layer="94"/>
<wire x1="-5.08" y1="-17.78" x2="-5.08" y2="0" width="0.254" layer="94"/>
<wire x1="-5.08" y1="0" x2="-25.4" y2="0" width="0.254" layer="94"/>
<pin name="PWM" x="-30.48" y="-4.064" length="middle"/>
<pin name="A" x="-30.48" y="-9.398" length="middle"/>
<pin name="B" x="-30.48" y="-14.224" length="middle"/>
<pin name="VCC" x="0" y="-1.524" length="middle" rot="R180"/>
<pin name="M+" x="0" y="-6.604" length="middle" rot="R180"/>
<pin name="M-" x="0" y="-9.144" length="middle" rot="R180"/>
<pin name="GND" x="0" y="-14.224" length="middle" rot="R180"/>
<text x="-17.78" y="-10.16" size="1.27" layer="94">Pololu</text>
</symbol>
<symbol name="POLOLU_MOTOR@1">
<description>Pololu Motor Driver</description>
<wire x1="-25.4" y1="0" x2="-25.4" y2="-17.78" width="0.254" layer="94"/>
<wire x1="-25.4" y1="-17.78" x2="-5.08" y2="-17.78" width="0.254" layer="94"/>
<wire x1="-5.08" y1="-17.78" x2="-5.08" y2="0" width="0.254" layer="94"/>
<wire x1="-5.08" y1="0" x2="-25.4" y2="0" width="0.254" layer="94"/>
<pin name="PWM" x="-30.48" y="-4.064" length="middle"/>
<pin name="A" x="-30.48" y="-9.398" length="middle"/>
<pin name="B" x="-30.48" y="-14.224" length="middle"/>
<pin name="VCC" x="0" y="-1.524" length="middle" rot="R180"/>
<pin name="M+" x="0" y="-6.604" length="middle" rot="R180"/>
<pin name="M-" x="0" y="-9.144" length="middle" rot="R180"/>
<pin name="GND" x="0" y="-14.224" length="middle" rot="R180"/>
</symbol>
<symbol name="SEABOTIX">
<text x="-27.94" y="0" size="1.27" layer="94">Motor</text>
<circle x="-25.4" y="0" radius="9.1581" width="0.254" layer="94"/>
<pin name="+" x="-39.624" y="0" length="middle"/>
<pin name="-" x="-11.176" y="0" length="middle" rot="R180"/>
</symbol>
<symbol name="ROV_MCU">
<wire x1="-22.86" y1="30.48" x2="17.78" y2="30.48" width="0.254" layer="94"/>
<wire x1="17.78" y1="30.48" x2="17.78" y2="-20.32" width="0.254" layer="94"/>
<wire x1="17.78" y1="-20.32" x2="-22.86" y2="-20.32" width="0.254" layer="94"/>
<wire x1="-22.86" y1="-20.32" x2="-22.86" y2="30.48" width="0.254" layer="94"/>
<pin name="VCC" x="-27.94" y="27.94" length="middle"/>
<pin name="GND" x="-27.94" y="25.4" length="middle"/>
<pin name="PWM1" x="-20.32" y="-25.4" length="middle" rot="R90"/>
<pin name="A1" x="-17.78" y="-25.4" length="middle" rot="R90"/>
<pin name="B1" x="-15.24" y="-25.4" length="middle" rot="R90"/>
<pin name="PWM2" x="-10.16" y="-25.4" length="middle" rot="R90"/>
<pin name="A2" x="-7.62" y="-25.4" length="middle" rot="R90"/>
<pin name="B2" x="-5.08" y="-25.4" length="middle" rot="R90"/>
<pin name="PWM3" x="0" y="-25.4" length="middle" rot="R90"/>
<pin name="A3" x="2.54" y="-25.4" length="middle" rot="R90"/>
<pin name="B3" x="5.08" y="-25.4" length="middle" rot="R90"/>
<pin name="PWM4" x="10.16" y="-25.4" length="middle" rot="R90"/>
<pin name="A4" x="12.7" y="-25.4" length="middle" rot="R90"/>
<pin name="B4" x="15.24" y="-25.4" length="middle" rot="R90"/>
<pin name="SERVO1" x="22.86" y="25.4" length="middle" rot="R180"/>
<pin name="SERVO2" x="22.86" y="20.32" length="middle" rot="R180"/>
<pin name="SERVO3" x="22.86" y="15.24" length="middle" rot="R180"/>
<pin name="SERVO4" x="22.86" y="10.16" length="middle" rot="R180"/>
<pin name="TX1" x="-27.94" y="15.24" length="middle"/>
<pin name="RX1" x="-27.94" y="12.7" length="middle"/>
<pin name="TX2" x="-27.94" y="7.62" length="middle"/>
<pin name="RX2" x="-27.94" y="5.08" length="middle"/>
<text x="-10.16" y="-5.08" size="1.6764" layer="94">Atemga 2560</text>
<pin name="DHT22" x="22.86" y="-5.08" length="middle" rot="R180"/>
</symbol>
<symbol name="SERVO">
<circle x="-15.24" y="0" radius="10.16" width="0.254" layer="94"/>
<text x="-17.78" y="-7.62" size="1.27" layer="94">Servo</text>
<wire x1="-23.114" y1="-6.35" x2="-8.128" y2="7.366" width="0.254" layer="94"/>
<wire x1="-21.844" y1="7.366" x2="-7.366" y2="-6.35" width="0.254" layer="94"/>
<pin name="GND" x="-30.48" y="0" length="middle"/>
<pin name="VCC" x="-30.48" y="2.54" length="middle"/>
<pin name="SIGNAL" x="-30.48" y="-2.54" length="middle"/>
</symbol>
<symbol name="IMU">
<wire x1="-22.86" y1="15.24" x2="15.24" y2="15.24" width="0.254" layer="94"/>
<wire x1="15.24" y1="15.24" x2="15.24" y2="-10.16" width="0.254" layer="94"/>
<wire x1="15.24" y1="-10.16" x2="-22.86" y2="-10.16" width="0.254" layer="94"/>
<wire x1="-22.86" y1="-10.16" x2="-22.86" y2="15.24" width="0.254" layer="94"/>
<text x="-5.08" y="0" size="1.778" layer="94">IMU</text>
<pin name="TX" x="20.32" y="7.62" length="middle" rot="R180"/>
<pin name="RX" x="20.32" y="-2.54" length="middle" rot="R180"/>
<pin name="VCC" x="-27.94" y="7.62" length="middle"/>
<pin name="GND" x="-27.94" y="-2.54" length="middle"/>
</symbol>
<symbol name="DHT22">
<circle x="-22.86" y="-2.54" radius="8.032184375" width="0.254" layer="94"/>
<wire x1="-27.94" y1="-7.62" x2="-17.78" y2="-7.62" width="0.254" layer="94"/>
<wire x1="-17.78" y1="-7.62" x2="-17.78" y2="2.54" width="0.254" layer="94"/>
<wire x1="-17.78" y1="2.54" x2="-27.94" y2="2.54" width="0.254" layer="94"/>
<wire x1="-27.94" y1="2.54" x2="-27.94" y2="-7.62" width="0.254" layer="94"/>
<pin name="VCC" x="-33.02" y="0" length="middle"/>
<pin name="GND" x="-33.02" y="-2.54" length="middle"/>
<pin name="SIGNAL" x="-33.02" y="-5.08" length="middle"/>
<text x="-25.654" y="-9.398" size="1.27" layer="94">DHT22</text>
</symbol>
</symbols>
<devicesets>
<deviceset name="POLOLU_MOTOR">
<gates>
<gate name="G$1" symbol="POLOLU_MOTOR" x="12.7" y="22.86"/>
</gates>
<devices>
<device name="" package="POLOLU_MOTOR">
<connects>
<connect gate="G$1" pin="A" pad="A"/>
<connect gate="G$1" pin="B" pad="B"/>
<connect gate="G$1" pin="GND" pad="GND"/>
<connect gate="G$1" pin="M+" pad="M+"/>
<connect gate="G$1" pin="M-" pad="M-"/>
<connect gate="G$1" pin="PWM" pad="PWM"/>
<connect gate="G$1" pin="VCC" pad="VCC"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="MOTOR">
<gates>
<gate name="G$1" symbol="SEABOTIX" x="22.86" y="0"/>
</gates>
<devices>
<device name="" package="MOTOR">
<connects>
<connect gate="G$1" pin="+" pad="+"/>
<connect gate="G$1" pin="-" pad="-"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="ROV_MCU">
<gates>
<gate name="G$1" symbol="ROV_MCU" x="-5.08" y="0"/>
</gates>
<devices>
<device name="" package="ROV_MCU">
<connects>
<connect gate="G$1" pin="A1" pad="A1"/>
<connect gate="G$1" pin="A2" pad="A2"/>
<connect gate="G$1" pin="A3" pad="A3"/>
<connect gate="G$1" pin="A4" pad="A4"/>
<connect gate="G$1" pin="B1" pad="B1"/>
<connect gate="G$1" pin="B2" pad="B2"/>
<connect gate="G$1" pin="B3" pad="B3"/>
<connect gate="G$1" pin="B4" pad="B4"/>
<connect gate="G$1" pin="DHT22" pad="DHT22"/>
<connect gate="G$1" pin="GND" pad="GND"/>
<connect gate="G$1" pin="PWM1" pad="PWM1"/>
<connect gate="G$1" pin="PWM2" pad="PWM2"/>
<connect gate="G$1" pin="PWM3" pad="PWM3"/>
<connect gate="G$1" pin="PWM4" pad="PWM4"/>
<connect gate="G$1" pin="RX1" pad="RX1"/>
<connect gate="G$1" pin="RX2" pad="RX2"/>
<connect gate="G$1" pin="SERVO1" pad="SERVO1"/>
<connect gate="G$1" pin="SERVO2" pad="SERVO2"/>
<connect gate="G$1" pin="SERVO3" pad="SERVO3"/>
<connect gate="G$1" pin="SERVO4" pad="SERVO4"/>
<connect gate="G$1" pin="TX1" pad="TX1"/>
<connect gate="G$1" pin="TX2" pad="TX2"/>
<connect gate="G$1" pin="VCC" pad="VCC"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="SERVO">
<gates>
<gate name="G$1" symbol="SERVO" x="12.7" y="0"/>
</gates>
<devices>
<device name="" package="SERVO">
<connects>
<connect gate="G$1" pin="GND" pad="GND"/>
<connect gate="G$1" pin="SIGNAL" pad="SIGNAL"/>
<connect gate="G$1" pin="VCC" pad="VCC"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="IMU">
<gates>
<gate name="G$1" symbol="IMU" x="2.54" y="-5.08"/>
</gates>
<devices>
<device name="" package="IMU">
<connects>
<connect gate="G$1" pin="GND" pad="GND"/>
<connect gate="G$1" pin="RX" pad="RX"/>
<connect gate="G$1" pin="TX" pad="TX"/>
<connect gate="G$1" pin="VCC" pad="VCC"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="DHT22">
<gates>
<gate name="G$1" symbol="DHT22" x="12.7" y="5.08"/>
</gates>
<devices>
<device name="" package="DHT22">
<connects>
<connect gate="G$1" pin="GND" pad="GND"/>
<connect gate="G$1" pin="SIGNAL" pad="SIGNAL"/>
<connect gate="G$1" pin="VCC" pad="VCC"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
</libraries>
<attributes>
</attributes>
<variantdefs>
</variantdefs>
<classes>
<class number="0" name="default" width="0" drill="0">
</class>
</classes>
<parts>
<part name="U$2" library="rov" deviceset="POLOLU_MOTOR" device=""/>
<part name="U$3" library="rov" deviceset="POLOLU_MOTOR" device=""/>
<part name="U$4" library="rov" deviceset="POLOLU_MOTOR" device=""/>
<part name="U$5" library="rov" deviceset="POLOLU_MOTOR" device=""/>
<part name="U$6" library="rov" deviceset="MOTOR" device=""/>
<part name="U$7" library="rov" deviceset="MOTOR" device=""/>
<part name="U$8" library="rov" deviceset="MOTOR" device=""/>
<part name="U$9" library="rov" deviceset="MOTOR" device=""/>
<part name="U$14" library="rov" deviceset="ROV_MCU" device=""/>
<part name="U$10" library="rov" deviceset="SERVO" device=""/>
<part name="U$11" library="rov" deviceset="SERVO" device=""/>
<part name="U$12" library="rov" deviceset="SERVO" device=""/>
<part name="U$13" library="rov" deviceset="SERVO" device=""/>
<part name="U$15" library="rov" deviceset="IMU" device=""/>
<part name="U$16" library="rov" deviceset="DHT22" device=""/>
</parts>
<sheets>
<sheet>
<plain>
<text x="-12.7" y="-5.08" size="1.778" layer="91">Left Motor</text>
<text x="38.1" y="-5.08" size="1.778" layer="91">Right Motor</text>
<text x="93.98" y="-5.08" size="1.778" layer="91">Vertical Front Motor</text>
<text x="152.4" y="-5.08" size="1.778" layer="91">Vertical Back Motor</text>
<text x="-15.24" y="50.8" size="1.778" layer="91">Motor Driver 1</text>
<text x="35.56" y="50.8" size="1.778" layer="91">Motor Driver 2</text>
<text x="93.98" y="50.8" size="1.778" layer="91">Motor Driver 3</text>
<text x="152.4" y="50.8" size="1.778" layer="91">Motor Driver 4</text>
<text x="182.88" y="195.58" size="1.778" layer="91">Cam1 X-Axis</text>
<text x="182.88" y="167.64" size="1.778" layer="91">Cam1 Y-Axis</text>
<text x="182.88" y="139.7" size="1.778" layer="91">Cam2 X-Axis</text>
<text x="182.88" y="114.3" size="1.778" layer="91">Arm</text>
<text x="30.48" y="190.5" size="1.778" layer="91">To Onshore Control System</text>
</plain>
<instances>
<instance part="U$2" gate="G$1" x="7.62" y="48.26"/>
<instance part="U$3" gate="G$1" x="58.42" y="48.26"/>
<instance part="U$4" gate="G$1" x="116.84" y="48.26"/>
<instance part="U$5" gate="G$1" x="175.26" y="48.26"/>
<instance part="U$6" gate="G$1" x="17.78" y="7.62"/>
<instance part="U$7" gate="G$1" x="68.58" y="7.62"/>
<instance part="U$8" gate="G$1" x="129.54" y="7.62"/>
<instance part="U$9" gate="G$1" x="185.42" y="7.62"/>
<instance part="U$14" gate="G$1" x="83.82" y="121.92"/>
<instance part="U$10" gate="G$1" x="185.42" y="190.5"/>
<instance part="U$11" gate="G$1" x="185.42" y="162.56"/>
<instance part="U$12" gate="G$1" x="185.42" y="134.62"/>
<instance part="U$13" gate="G$1" x="185.42" y="109.22"/>
<instance part="U$15" gate="G$1" x="2.54" y="109.22"/>
<instance part="U$16" gate="G$1" x="193.04" y="81.28"/>
</instances>
<busses>
</busses>
<nets>
<net name="N$1" class="0">
<segment>
<wire x1="7.112" y1="46.736" x2="12.7" y2="46.736" width="0.1524" layer="91"/>
<wire x1="12.7" y1="46.736" x2="12.7" y2="27.94" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$2" class="0">
<segment>
<wire x1="58.166" y1="46.736" x2="60.96" y2="46.736" width="0.1524" layer="91"/>
<wire x1="60.96" y1="46.736" x2="60.96" y2="27.94" width="0.1524" layer="91"/>
<wire x1="60.96" y1="27.94" x2="-40.64" y2="27.94" width="0.1524" layer="91"/>
<wire x1="60.96" y1="27.94" x2="123.444" y2="27.94" width="0.1524" layer="91"/>
<wire x1="123.444" y1="27.94" x2="123.444" y2="46.736" width="0.1524" layer="91"/>
<pinref part="U$4" gate="G$1" pin="VCC"/>
<wire x1="116.84" y1="46.736" x2="123.444" y2="46.736" width="0.1524" layer="91"/>
<wire x1="175.006" y1="46.736" x2="180.34" y2="46.736" width="0.1524" layer="91"/>
<wire x1="180.34" y1="46.736" x2="180.34" y2="27.94" width="0.1524" layer="91"/>
<wire x1="180.34" y1="27.94" x2="139.7" y2="27.94" width="0.1524" layer="91"/>
<pinref part="U$10" gate="G$1" pin="VCC"/>
<wire x1="139.7" y1="27.94" x2="123.444" y2="27.94" width="0.1524" layer="91"/>
<wire x1="154.94" y1="193.04" x2="139.7" y2="193.04" width="0.1524" layer="91"/>
<wire x1="139.7" y1="193.04" x2="139.7" y2="165.1" width="0.1524" layer="91"/>
<pinref part="U$11" gate="G$1" pin="VCC"/>
<wire x1="154.94" y1="165.1" x2="139.7" y2="165.1" width="0.1524" layer="91"/>
<wire x1="139.7" y1="165.1" x2="139.7" y2="137.16" width="0.1524" layer="91"/>
<pinref part="U$12" gate="G$1" pin="VCC"/>
<wire x1="154.94" y1="137.16" x2="139.7" y2="137.16" width="0.1524" layer="91"/>
<wire x1="139.7" y1="137.16" x2="139.7" y2="111.76" width="0.1524" layer="91"/>
<wire x1="157.48" y1="111.76" x2="139.7" y2="111.76" width="0.1524" layer="91"/>
<wire x1="139.7" y1="111.76" x2="139.7" y2="81.28" width="0.1524" layer="91"/>
<wire x1="139.7" y1="81.28" x2="139.7" y2="27.94" width="0.1524" layer="91"/>
<wire x1="-40.64" y1="27.94" x2="-40.64" y2="91.44" width="0.1524" layer="91"/>
<wire x1="-40.64" y1="91.44" x2="35.56" y2="91.44" width="0.1524" layer="91"/>
<wire x1="35.56" y1="91.44" x2="35.56" y2="149.86" width="0.1524" layer="91"/>
<pinref part="U$14" gate="G$1" pin="VCC"/>
<wire x1="35.56" y1="149.86" x2="43.18" y2="149.86" width="0.1524" layer="91"/>
<pinref part="U$15" gate="G$1" pin="VCC"/>
<wire x1="43.18" y1="149.86" x2="55.88" y2="149.86" width="0.1524" layer="91"/>
<wire x1="-25.4" y1="116.84" x2="-40.64" y2="116.84" width="0.1524" layer="91"/>
<wire x1="-40.64" y1="116.84" x2="-40.64" y2="91.44" width="0.1524" layer="91"/>
<pinref part="U$16" gate="G$1" pin="VCC"/>
<wire x1="160.02" y1="81.28" x2="139.7" y2="81.28" width="0.1524" layer="91"/>
<wire x1="43.18" y1="149.86" x2="43.18" y2="185.42" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$3" class="0">
<segment>
<pinref part="U$2" gate="G$1" pin="M+"/>
<wire x1="7.62" y1="41.656" x2="15.24" y2="41.656" width="0.1524" layer="91"/>
<wire x1="15.24" y1="41.656" x2="15.24" y2="22.86" width="0.1524" layer="91"/>
<wire x1="15.24" y1="22.86" x2="-22.86" y2="22.86" width="0.1524" layer="91"/>
<wire x1="-22.86" y1="22.86" x2="-22.86" y2="7.62" width="0.1524" layer="91"/>
<wire x1="-22.86" y1="7.62" x2="-20.32" y2="7.62" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$4" class="0">
<segment>
<wire x1="7.366" y1="39.116" x2="17.78" y2="39.116" width="0.1524" layer="91"/>
<wire x1="17.78" y1="39.116" x2="17.78" y2="20.32" width="0.1524" layer="91"/>
<wire x1="17.78" y1="20.32" x2="10.16" y2="20.32" width="0.1524" layer="91"/>
<wire x1="10.16" y1="20.32" x2="10.16" y2="7.62" width="0.1524" layer="91"/>
<wire x1="10.16" y1="7.62" x2="5.08" y2="7.62" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$6" class="0">
<segment>
<wire x1="58.166" y1="41.656" x2="63.5" y2="41.656" width="0.1524" layer="91"/>
<wire x1="63.5" y1="41.656" x2="63.5" y2="22.86" width="0.1524" layer="91"/>
<wire x1="63.5" y1="22.86" x2="27.94" y2="22.86" width="0.1524" layer="91"/>
<wire x1="27.94" y1="22.86" x2="27.94" y2="7.62" width="0.1524" layer="91"/>
<wire x1="27.94" y1="7.62" x2="30.48" y2="7.62" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$7" class="0">
<segment>
<wire x1="58.166" y1="39.116" x2="66.04" y2="39.116" width="0.1524" layer="91"/>
<wire x1="66.04" y1="39.116" x2="66.04" y2="20.32" width="0.1524" layer="91"/>
<wire x1="66.04" y1="20.32" x2="60.96" y2="20.32" width="0.1524" layer="91"/>
<wire x1="60.96" y1="20.32" x2="60.96" y2="7.62" width="0.1524" layer="91"/>
<wire x1="60.96" y1="7.62" x2="55.88" y2="7.62" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$8" class="0">
<segment>
<wire x1="116.586" y1="41.656" x2="127" y2="41.656" width="0.1524" layer="91"/>
<wire x1="127" y1="41.656" x2="127" y2="22.86" width="0.1524" layer="91"/>
<wire x1="127" y1="22.86" x2="88.9" y2="22.86" width="0.1524" layer="91"/>
<wire x1="88.9" y1="22.86" x2="88.9" y2="7.62" width="0.1524" layer="91"/>
<wire x1="88.9" y1="7.62" x2="91.44" y2="7.62" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$9" class="0">
<segment>
<wire x1="116.586" y1="39.116" x2="129.54" y2="39.116" width="0.1524" layer="91"/>
<wire x1="129.54" y1="39.116" x2="129.54" y2="20.32" width="0.1524" layer="91"/>
<wire x1="129.54" y1="20.32" x2="119.38" y2="20.32" width="0.1524" layer="91"/>
<wire x1="119.38" y1="20.32" x2="119.38" y2="7.62" width="0.1524" layer="91"/>
<wire x1="119.38" y1="7.62" x2="116.84" y2="7.62" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$10" class="0">
<segment>
<wire x1="174.752" y1="41.656" x2="182.88" y2="41.656" width="0.1524" layer="91"/>
<wire x1="182.88" y1="41.656" x2="182.88" y2="22.86" width="0.1524" layer="91"/>
<wire x1="182.88" y1="22.86" x2="144.78" y2="22.86" width="0.1524" layer="91"/>
<wire x1="144.78" y1="22.86" x2="144.78" y2="7.62" width="0.1524" layer="91"/>
<wire x1="144.78" y1="7.62" x2="147.32" y2="7.62" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$11" class="0">
<segment>
<wire x1="175.006" y1="39.116" x2="185.42" y2="39.116" width="0.1524" layer="91"/>
<wire x1="185.42" y1="39.116" x2="185.42" y2="20.32" width="0.1524" layer="91"/>
<wire x1="185.42" y1="20.32" x2="175.26" y2="20.32" width="0.1524" layer="91"/>
<wire x1="175.26" y1="20.32" x2="175.26" y2="7.62" width="0.1524" layer="91"/>
<wire x1="175.26" y1="7.62" x2="172.72" y2="7.62" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$5" class="0">
<segment>
<wire x1="116.586" y1="34.036" x2="120.65" y2="34.036" width="0.1524" layer="91"/>
<wire x1="120.65" y1="34.036" x2="120.65" y2="25.4" width="0.1524" layer="91"/>
<wire x1="175.006" y1="34.036" x2="177.8" y2="34.036" width="0.1524" layer="91"/>
<wire x1="177.8" y1="34.036" x2="177.8" y2="25.4" width="0.1524" layer="91"/>
<wire x1="177.8" y1="25.4" x2="142.24" y2="25.4" width="0.1524" layer="91"/>
<wire x1="142.24" y1="25.4" x2="120.65" y2="25.4" width="0.1524" layer="91"/>
<wire x1="120.65" y1="25.4" x2="59.69" y2="25.4" width="0.1524" layer="91"/>
<wire x1="59.69" y1="25.4" x2="10.668" y2="25.4" width="0.1524" layer="91"/>
<wire x1="57.912" y1="34.036" x2="59.69" y2="34.036" width="0.1524" layer="91"/>
<wire x1="59.69" y1="34.036" x2="59.69" y2="25.4" width="0.1524" layer="91"/>
<wire x1="7.366" y1="34.036" x2="10.668" y2="34.036" width="0.1524" layer="91"/>
<wire x1="10.668" y1="34.036" x2="10.668" y2="25.4" width="0.1524" layer="91"/>
<pinref part="U$10" gate="G$1" pin="GND"/>
<wire x1="154.94" y1="190.5" x2="142.24" y2="190.5" width="0.1524" layer="91"/>
<wire x1="142.24" y1="190.5" x2="142.24" y2="162.56" width="0.1524" layer="91"/>
<wire x1="157.48" y1="162.56" x2="142.24" y2="162.56" width="0.1524" layer="91"/>
<wire x1="142.24" y1="162.56" x2="142.24" y2="134.62" width="0.1524" layer="91"/>
<pinref part="U$12" gate="G$1" pin="GND"/>
<wire x1="154.94" y1="134.62" x2="142.24" y2="134.62" width="0.1524" layer="91"/>
<wire x1="142.24" y1="134.62" x2="142.24" y2="109.22" width="0.1524" layer="91"/>
<pinref part="U$13" gate="G$1" pin="GND"/>
<wire x1="154.94" y1="109.22" x2="142.24" y2="109.22" width="0.1524" layer="91"/>
<wire x1="142.24" y1="109.22" x2="142.24" y2="78.74" width="0.1524" layer="91"/>
<pinref part="U$16" gate="G$1" pin="GND"/>
<wire x1="142.24" y1="78.74" x2="142.24" y2="25.4" width="0.1524" layer="91"/>
<wire x1="160.02" y1="78.74" x2="142.24" y2="78.74" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$12" class="0">
<segment>
<pinref part="U$14" gate="G$1" pin="SERVO1"/>
<wire x1="106.68" y1="147.32" x2="121.92" y2="147.32" width="0.1524" layer="91"/>
<wire x1="121.92" y1="147.32" x2="121.92" y2="187.96" width="0.1524" layer="91"/>
<wire x1="121.92" y1="187.96" x2="157.48" y2="187.96" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$13" class="0">
<segment>
<pinref part="U$11" gate="G$1" pin="SIGNAL"/>
<wire x1="154.94" y1="160.02" x2="124.46" y2="160.02" width="0.1524" layer="91"/>
<wire x1="124.46" y1="160.02" x2="124.46" y2="142.24" width="0.1524" layer="91"/>
<pinref part="U$14" gate="G$1" pin="SERVO2"/>
<wire x1="124.46" y1="142.24" x2="106.68" y2="142.24" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$14" class="0">
<segment>
<pinref part="U$14" gate="G$1" pin="SERVO3"/>
<wire x1="106.68" y1="137.16" x2="127" y2="137.16" width="0.1524" layer="91"/>
<wire x1="127" y1="137.16" x2="127" y2="132.08" width="0.1524" layer="91"/>
<pinref part="U$12" gate="G$1" pin="SIGNAL"/>
<wire x1="127" y1="132.08" x2="154.94" y2="132.08" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$15" class="0">
<segment>
<pinref part="U$14" gate="G$1" pin="SERVO4"/>
<wire x1="106.68" y1="132.08" x2="124.46" y2="132.08" width="0.1524" layer="91"/>
<wire x1="124.46" y1="132.08" x2="124.46" y2="106.68" width="0.1524" layer="91"/>
<pinref part="U$13" gate="G$1" pin="SIGNAL"/>
<wire x1="124.46" y1="106.68" x2="154.94" y2="106.68" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$18" class="0">
<segment>
<wire x1="-22.352" y1="34.036" x2="-25.4" y2="34.036" width="0.1524" layer="91"/>
<wire x1="-25.4" y1="34.036" x2="-25.4" y2="71.12" width="0.1524" layer="91"/>
<pinref part="U$14" gate="G$1" pin="B1"/>
<wire x1="-25.4" y1="71.12" x2="68.58" y2="71.12" width="0.1524" layer="91"/>
<wire x1="68.58" y1="71.12" x2="68.58" y2="96.52" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$19" class="0">
<segment>
<wire x1="-22.098" y1="38.862" x2="-27.94" y2="38.862" width="0.1524" layer="91"/>
<wire x1="-27.94" y1="38.862" x2="-27.94" y2="73.66" width="0.1524" layer="91"/>
<pinref part="U$14" gate="G$1" pin="A1"/>
<wire x1="-27.94" y1="73.66" x2="66.04" y2="73.66" width="0.1524" layer="91"/>
<wire x1="66.04" y1="73.66" x2="66.04" y2="96.52" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$20" class="0">
<segment>
<wire x1="-22.606" y1="44.196" x2="-30.48" y2="44.196" width="0.1524" layer="91"/>
<wire x1="-30.48" y1="44.196" x2="-30.48" y2="76.2" width="0.1524" layer="91"/>
<pinref part="U$14" gate="G$1" pin="PWM1"/>
<wire x1="-30.48" y1="76.2" x2="63.5" y2="76.2" width="0.1524" layer="91"/>
<wire x1="63.5" y1="76.2" x2="63.5" y2="96.52" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$21" class="0">
<segment>
<wire x1="28.448" y1="34.036" x2="25.4" y2="34.036" width="0.1524" layer="91"/>
<wire x1="25.4" y1="34.036" x2="25.4" y2="53.34" width="0.1524" layer="91"/>
<wire x1="25.4" y1="53.34" x2="78.74" y2="53.34" width="0.1524" layer="91"/>
<wire x1="78.74" y1="53.34" x2="78.74" y2="99.06" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$22" class="0">
<segment>
<wire x1="28.448" y1="38.862" x2="22.86" y2="38.862" width="0.1524" layer="91"/>
<wire x1="22.86" y1="38.862" x2="22.86" y2="55.88" width="0.1524" layer="91"/>
<wire x1="22.86" y1="55.88" x2="76.2" y2="55.88" width="0.1524" layer="91"/>
<wire x1="76.2" y1="55.88" x2="76.2" y2="99.06" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$23" class="0">
<segment>
<pinref part="U$3" gate="G$1" pin="PWM"/>
<wire x1="27.94" y1="44.196" x2="20.32" y2="44.196" width="0.1524" layer="91"/>
<wire x1="20.32" y1="44.196" x2="20.32" y2="58.42" width="0.1524" layer="91"/>
<pinref part="U$14" gate="G$1" pin="PWM2"/>
<wire x1="20.32" y1="58.42" x2="73.66" y2="58.42" width="0.1524" layer="91"/>
<wire x1="73.66" y1="58.42" x2="73.66" y2="96.52" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$24" class="0">
<segment>
<pinref part="U$4" gate="G$1" pin="PWM"/>
<wire x1="86.36" y1="44.196" x2="81.28" y2="44.196" width="0.1524" layer="91"/>
<wire x1="81.28" y1="44.196" x2="81.28" y2="93.98" width="0.1524" layer="91"/>
<pinref part="U$14" gate="G$1" pin="PWM3"/>
<wire x1="81.28" y1="93.98" x2="83.82" y2="93.98" width="0.1524" layer="91"/>
<wire x1="83.82" y1="93.98" x2="83.82" y2="96.52" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$25" class="0">
<segment>
<wire x1="86.868" y1="38.862" x2="83.82" y2="38.862" width="0.1524" layer="91"/>
<wire x1="83.82" y1="38.862" x2="83.82" y2="88.9" width="0.1524" layer="91"/>
<wire x1="83.82" y1="88.9" x2="86.36" y2="88.9" width="0.1524" layer="91"/>
<wire x1="86.36" y1="88.9" x2="86.36" y2="99.06" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$26" class="0">
<segment>
<wire x1="87.122" y1="34.036" x2="86.36" y2="34.036" width="0.1524" layer="91"/>
<wire x1="86.36" y1="34.036" x2="86.36" y2="83.82" width="0.1524" layer="91"/>
<wire x1="86.36" y1="83.82" x2="88.9" y2="83.82" width="0.1524" layer="91"/>
<wire x1="88.9" y1="83.82" x2="88.9" y2="99.06" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$27" class="0">
<segment>
<wire x1="145.796" y1="44.196" x2="129.54" y2="44.196" width="0.1524" layer="91"/>
<wire x1="129.54" y1="44.196" x2="129.54" y2="55.88" width="0.1524" layer="91"/>
<pinref part="U$14" gate="G$1" pin="PWM4"/>
<wire x1="129.54" y1="55.88" x2="93.98" y2="55.88" width="0.1524" layer="91"/>
<wire x1="93.98" y1="55.88" x2="93.98" y2="96.52" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$28" class="0">
<segment>
<wire x1="145.288" y1="38.862" x2="132.08" y2="38.862" width="0.1524" layer="91"/>
<wire x1="132.08" y1="38.862" x2="132.08" y2="58.42" width="0.1524" layer="91"/>
<wire x1="132.08" y1="58.42" x2="96.52" y2="58.42" width="0.1524" layer="91"/>
<wire x1="96.52" y1="58.42" x2="96.52" y2="99.06" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$29" class="0">
<segment>
<wire x1="145.288" y1="34.036" x2="134.62" y2="34.036" width="0.1524" layer="91"/>
<wire x1="134.62" y1="34.036" x2="134.62" y2="60.96" width="0.1524" layer="91"/>
<pinref part="U$14" gate="G$1" pin="B4"/>
<wire x1="134.62" y1="60.96" x2="99.06" y2="60.96" width="0.1524" layer="91"/>
<wire x1="99.06" y1="60.96" x2="99.06" y2="96.52" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$16" class="0">
<segment>
<wire x1="10.16" y1="25.4" x2="-35.56" y2="25.4" width="0.1524" layer="91"/>
<wire x1="-35.56" y1="25.4" x2="-35.56" y2="86.36" width="0.1524" layer="91"/>
<wire x1="-35.56" y1="86.36" x2="40.64" y2="86.36" width="0.1524" layer="91"/>
<wire x1="40.64" y1="86.36" x2="40.64" y2="147.32" width="0.1524" layer="91"/>
<pinref part="U$15" gate="G$1" pin="GND"/>
<wire x1="43.18" y1="147.32" x2="58.42" y2="147.32" width="0.1524" layer="91"/>
<wire x1="-25.4" y1="106.68" x2="-35.56" y2="106.68" width="0.1524" layer="91"/>
<wire x1="-35.56" y1="106.68" x2="-35.56" y2="86.36" width="0.1524" layer="91"/>
<wire x1="43.18" y1="147.32" x2="40.64" y2="147.32" width="0.1524" layer="91"/>
<wire x1="40.64" y1="147.32" x2="40.64" y2="185.42" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$17" class="0">
<segment>
<pinref part="U$15" gate="G$1" pin="TX"/>
<pinref part="U$14" gate="G$1" pin="RX2"/>
<wire x1="22.86" y1="116.84" x2="55.88" y2="116.84" width="0.1524" layer="91"/>
<wire x1="55.88" y1="116.84" x2="55.88" y2="127" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$30" class="0">
<segment>
<pinref part="U$15" gate="G$1" pin="RX"/>
<wire x1="22.86" y1="106.68" x2="50.8" y2="106.68" width="0.1524" layer="91"/>
<wire x1="50.8" y1="106.68" x2="50.8" y2="129.54" width="0.1524" layer="91"/>
<pinref part="U$14" gate="G$1" pin="TX2"/>
<wire x1="50.8" y1="129.54" x2="55.88" y2="129.54" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$31" class="0">
<segment>
<pinref part="U$14" gate="G$1" pin="DHT22"/>
<wire x1="106.68" y1="116.84" x2="119.38" y2="116.84" width="0.1524" layer="91"/>
<wire x1="119.38" y1="116.84" x2="119.38" y2="76.2" width="0.1524" layer="91"/>
<wire x1="119.38" y1="76.2" x2="162.56" y2="76.2" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$32" class="0">
<segment>
<pinref part="U$14" gate="G$1" pin="TX1"/>
<wire x1="55.88" y1="137.16" x2="48.26" y2="137.16" width="0.1524" layer="91"/>
<wire x1="48.26" y1="137.16" x2="48.26" y2="185.42" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$33" class="0">
<segment>
<pinref part="U$14" gate="G$1" pin="RX1"/>
<wire x1="55.88" y1="134.62" x2="45.72" y2="134.62" width="0.1524" layer="91"/>
<wire x1="45.72" y1="134.62" x2="45.72" y2="185.42" width="0.1524" layer="91"/>
</segment>
</net>
</nets>
</sheet>
</sheets>
</schematic>
</drawing>
</eagle>
