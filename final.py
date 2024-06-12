import cv2
import serial
import dlib
import time
import numpy as np


arduino = serial.Serial(port='COM7', baudrate=9600)
time.sleep(2)
print('Connection established...')

cap = cv2.VideoCapture(0)

# define a face detector
face_detector = dlib.get_frontal_face_detector()

def wr(x):
    arduino.write(bytes(x, 'utf-8'))
    time.sleep(0.05)
    data = arduino.readline()
    return data

while True:
    success, img = cap.read()
    #img = cv2.flip(img,1)
    #img = cv2.resize(img, (1024,1024))
    #img = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)
    cv2.imshow("Webcam", img) # This will open an independent window
    bbox = face_detector(img)
    print("Number of Faces ==>",len(bbox))
    print(img.shape)
    for faces in bbox:
        x,y,width,height = faces.left(),faces.top(),faces.right() - faces.left(),faces.bottom()-faces.top()
        cv2.rectangle(img,(x,y),(x+width,y+height),(0,255,255),5)
        cx = int((int(faces.right()+faces.left()))//2)
        cy = int((int(faces.bottom()+faces.top()))//2)
        cv2.circle(img, (cx, cy), 2, (0,0,255),5)
        cv2.imshow("Webcam", img)
        #print(cx)
        #print(cy)
        ctr = (cx,cy)
        data = "X{0:d}Y{1:d}".format(cx, cy)
        print ("output = '" +data+ "'")
        arduino.write(bytes(data, 'utf-8'))
        qz = arduino.readline()
        print(qz)

        print(cy//cx)
        angle = np.arctan((cy//cx))
        print("ghj",angle)
    if cv2.waitKey(30) & 0xFF==ord('q'): # quit when 'q' is pressed
        cap.release()
        break
        
cv2.destroyAllWindows() 
cv2.waitKey(1) # normally unnecessary, but it fixes a bug on MacOS where the window doesn't close
