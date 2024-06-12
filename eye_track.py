import cv2
import serial,time
from playsound import playsound


face_cascade= cv2.CascadeClassifier(r'D:\College\PURR\Eye_tracking\haarcascade_frontalface_default.xml')

cap=cv2.VideoCapture(0)

#fourcc= cv2.VideoWriter_fourcc(*'XVID')
ArduinoSerial=serial.Serial('com7',31250, timeout=0.01)
#playsound(r"D:\Codes\Eye_tracking\Charge_up.mp3")
#out= cv2.VideoWriter('face detection4.avi',fourcc,20.0,(640,480))
#strings = ["0"]0

while cap.isOpened():
    ret, frame= cap.read()
    frame=cv2.flip(frame,1)  #mirror the image
    # frame=cv2.flip(frame,0)
    #print(frame.shape)
    gray = cv2.cvtColor(frame,cv2.COLOR_BGR2GRAY)
    faces= face_cascade.detectMultiScale(gray,1.1,6)
    #detect the face
    for x,y,w,h in faces:
        #sending coordinates to Arduino
        x_s='X{0:d}'.format((x+w//2))
        ArduinoSerial.write(x_s.encode('utf-8'))
        y_s = 'Y{0:d}'.format((y+h//2))
        ArduinoSerial.write(y_s.encode('utf-8'))
        print(x_s, y_s)
        
        #strings.append(string)
        #cv2.circle(frame,(x+w//2,y+h//2),2,(0,255,0),2)
        cv2.rectangle(frame,(x,y),(x+w,y+h),(0,0,255),3)
    #print(strings[-1])
    #ArduinoSerial.write(strings[-1].encode('utf-8'))
    #out.write(frame)
    cv2.imshow('img',frame)
    #cv2.imwrite('output_img.jpg',frame)
    '''for testing purpose
    read= str(ArduinoSerial.readline(ArduinoSerial.inWaiting()))
    time.sleep(0.05)
    print('data from arduino:'+read)
    '''
    # press q to Quit
    if cv2.waitKey(1)&0xFF== ord('q'):
        break
cap.release()
cv2.destroyAllWindows()
